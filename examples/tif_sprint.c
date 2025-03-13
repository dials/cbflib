/* tif_sprint.c
 
 -- variant of tif_print.c for printing to strings
 using snprintf
 
 H. J. Bernstein, 26 Dec 2010
 Revised for 4.0.6 version, 3 Nov 2016
 
 */

/**********************************************************************
 *                                                                    *
 * PORTIONS OF THIS CODE ARE DERIVED FROM CODE IN LIBTIFF AND ARE     *
 * SUBJECT TO THE FOLLOWING COPYRIGHT NOTICE                          *
 *                                                                    *
 **********************************************************************
 * Copyright (c) 1988-1997 Sam Leffler                                *
 * Copyright (c) 1991-1997 Silicon Graphics, Inc.                     *
 *                                                                    *
 * Permission to use, copy, modify, distribute, and sell this software*
 * and its documentation for any purpose is hereby granted without    *
 * fee, provided that (i) the above copyright notices and this        *
 * permission notice appear in all copies of the software and related *
 * documentation, and (ii) the names of Sam Leffler and Silicon       *
 * Graphics may not be used in any advertising or publicity relating  *
 * to the software without the specific, prior written permission of  *
 * Sam Leffler and Silicon Graphics.                                  *
 *                                                                    *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, *
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   *
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.   *
 *                                                                    *
 * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR    *
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY  *
 * KIND, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA   *
 * OR PROFITS, WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE,   *
 * AND ON ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION    *
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.                      *
 **********************************************************************/

#include <stdio.h>

#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <string.h>

#include <tiffio.h>

static size_t
_TIFFsnprintAsciiBounded(char * str, const size_t xstrlen, const char* cp, size_t max_chars);

static const char *photoNames[] = {
    "min-is-white",				/* PHOTOMETRIC_MINISWHITE */
    "min-is-black",				/* PHOTOMETRIC_MINISBLACK */
    "RGB color",				/* PHOTOMETRIC_RGB */
    "palette color (RGB from colormap)",	/* PHOTOMETRIC_PALETTE */
    "transparency mask",			/* PHOTOMETRIC_MASK */
    "separated",				/* PHOTOMETRIC_SEPARATED */
    "YCbCr",					/* PHOTOMETRIC_YCBCR */
    "7 (0x7)",
    "CIE L*a*b*",				/* PHOTOMETRIC_CIELAB */
    "ICC L*a*b*",				/* PHOTOMETRIC_ICCLAB */
    "ITU L*a*b*" 				/* PHOTOMETRIC_ITULAB */
};
#define	NPHOTONAMES	(sizeof (photoNames) / sizeof (photoNames[0]))

static const char *orientNames[] = {
    "0 (0x0)",
    "row 0 top, col 0 lhs",			/* ORIENTATION_TOPLEFT */
    "row 0 top, col 0 rhs",			/* ORIENTATION_TOPRIGHT */
    "row 0 bottom, col 0 rhs",			/* ORIENTATION_BOTRIGHT */
    "row 0 bottom, col 0 lhs",			/* ORIENTATION_BOTLEFT */
    "row 0 lhs, col 0 top",			/* ORIENTATION_LEFTTOP */
    "row 0 rhs, col 0 top",			/* ORIENTATION_RIGHTTOP */
    "row 0 rhs, col 0 bottom",			/* ORIENTATION_RIGHTBOT */
    "row 0 lhs, col 0 bottom",			/* ORIENTATION_LEFTBOT */
};
#define	NORIENTNAMES	(sizeof (orientNames) / sizeof (orientNames[0]))

/*
 * Return data size of the field datatype in bytes.  LibTIFF 4.4.0 introduced
 * TIFFFieldSetGetSize() for this.
 */
static int
_TIFFFieldDataSize(const TIFFField *fip)
{
	switch (TIFFFieldDataType(fip))
	{
		case TIFF_BYTE:
		case TIFF_SBYTE:
		case TIFF_ASCII:
		case TIFF_UNDEFINED:
		    return 1;
		case TIFF_SHORT:
		case TIFF_SSHORT:
		    return 2;
		case TIFF_LONG:
		case TIFF_SLONG:
		case TIFF_FLOAT:
		case TIFF_IFD:
		case TIFF_RATIONAL:
		case TIFF_SRATIONAL:
		    return 4;
		case TIFF_DOUBLE:
		case TIFF_LONG8:
		case TIFF_SLONG8:
		case TIFF_IFD8:
		    return 8;
		default:
		    return 0;
	}
}

static size_t
_TIFFSNPrintField(char * str, const size_t xstrlen, const TIFFField *fip,
                  uint32_t value_count, void *raw_data)
{
	uint32_t j;

    size_t chars_used = 0;
		
	chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  %s: ", TIFFFieldName(fip));

	for(j = 0; j < value_count; j++) {
		if(TIFFFieldDataType(fip) == TIFF_BYTE)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu8, ((uint8_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_UNDEFINED)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "0x%" PRIx8, ((uint8_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_SBYTE)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRId8, ((int8_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_SHORT)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16, ((uint16_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_SSHORT)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRId16, ((int16_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_LONG)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu32, ((uint32_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_SLONG)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRId32, ((int32_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_IFD)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "0x%" PRIx32, ((uint32_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_RATIONAL
			|| TIFFFieldDataType(fip) == TIFF_SRATIONAL) {
			if (_TIFFFieldDataSize(fip) == 8)
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%lf", ((double *)raw_data)[j]);
			else
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%f", ((float *) raw_data)[j]);
		} else if(TIFFFieldDataType(fip) == TIFF_FLOAT)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%f", ((float *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_LONG8)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu64, ((uint64_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_SLONG8)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRId64, ((int64_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_IFD8)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "0x%" PRIx64, ((uint64_t *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_DOUBLE)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%lf", ((double *) raw_data)[j]);
		else if(TIFFFieldDataType(fip) == TIFF_ASCII) {
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%s", (char *) raw_data);
			break;
		}
		else {
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "<unsupported data type in TIFFPrint>");
			break;
		}

		if(j < value_count - 1)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), ",");
	}

	chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\n");
    
    return chars_used;
}

static size_t
_TIFFPrettySNPrintField(TIFF* tif, char * str, const size_t xstrlen, ttag_t tag,
                        uint32_t value_count, void *raw_data)
{
    const TIFFField *fip;
    
    size_t chars_used = 0;

    fip = TIFFFieldWithTag(tif, tag);

	switch (tag)
	{
		case TIFFTAG_INKSET:
			if (value_count == 2 && TIFFFieldDataType(fip) == TIFF_SHORT) {
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Ink Set: ");
				switch (*((uint16_t *)raw_data)) {
				case INKSET_CMYK:
					chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "CMYK\n");
					break;
				default:
					chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
						*((uint16_t *)raw_data),
						*((uint16_t *)raw_data));
					break;
				}
				return chars_used;
			}
			return chars_used;

		case TIFFTAG_DOTRANGE:
			if (value_count == 2 && TIFFFieldDataType(fip) == TIFF_SHORT) {
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Dot Range: %" PRIu16 "-%" PRIu16 "\n",
					((uint16_t *)raw_data)[0], ((uint16_t *)raw_data)[1]);
				return chars_used;
			}
			return chars_used;

		case TIFFTAG_WHITEPOINT:
			if (value_count == 2 && TIFFFieldDataType(fip) == TIFF_RATIONAL) {
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  White Point: %g-%g\n",
					((float *)raw_data)[0], ((float *)raw_data)[1]);
				return chars_used;
			} 
			return chars_used;

		case TIFFTAG_XMLPACKET:
		{
			uint32_t i;

			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  XMLPacket (XMP Metadata):\n" );
			for(i = 0; i < value_count; i++)
                chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),"%c",(int)((char *)raw_data)[i]);
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\n" );
			return chars_used;
		}
		case TIFFTAG_RICHTIFFIPTC:
			/*
			 * XXX: for some weird reason RichTIFFIPTC tag
			 * defined as array of LONG values.
			 */
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),
			    "  RichTIFFIPTC Data: <present>, %" PRIu32 " bytes\n",
			    value_count * 4);
			return chars_used;

		case TIFFTAG_PHOTOSHOP:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Photoshop Data: <present>, %" PRIu32 " bytes\n",
			    value_count);
			return chars_used;

		case TIFFTAG_ICCPROFILE:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  ICC Profile: <present>, %" PRIu32 " bytes\n",
			    value_count);
			return chars_used;

		case TIFFTAG_STONITS:
			if (value_count == 1 && TIFFFieldDataType(fip) == TIFF_DOUBLE) {
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),
					"  Sample to Nits conversion factor: %.4e\n",
					*((double*)raw_data));
				return chars_used;
			}
			return chars_used;
	}

	return chars_used;
}

/*
 * Print the contents of the current directory
 * to the specified stdio file stream.
 */
size_t
cbf_TIFFSNPrintDirectory(TIFF* tif, char * str, const size_t xstrlen, long flags)
{
	char *sep;
	uint16_t i;
	long l, n;
    
	const char *inknames;
	const uint16_t *colormap[3], *sampleinfo, *transferfunction[3];
	const uint64_t *stripbytecounts, *stripoffsets, *subifd;
	double smaxsamplevalue, sminsamplevalue;
	float referenceblackwhite[6], xposition, xresolution,
		yposition, yresolution;
	uint32_t imagedepth, imagelength, imagewidth, rowsperstrip,
		subfiletype, tiledepth, tilelength, tilewidth;
	uint16_t bitspersample, compression, extrasamples, fillorder,
		halftonehints[2], maxsamplevalue, minsamplevalue,
		nsubifd, orientation, pagenumber[2], photometric,
		planarconfig, resolutionunit, sampleformat, samplesperpixel,
		threshholding, ycbcrpositioning, ycbcrsubsampling[2];

    size_t chars_used = 0;

	chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "TIFF Directory at offset 0x%" PRIx64 " (%" PRIu64 ")\n",
		TIFFCurrentDirOffset(tif),
		TIFFCurrentDirOffset(tif));
	if (!TIFFGetField(tif, TIFFTAG_EXTRASAMPLES, &extrasamples, &sampleinfo)) {
		extrasamples = 0;
		sampleinfo = NULL;
	}
	if (!TIFFGetField(tif, TIFFTAG_SAMPLESPERPIXEL, &samplesperpixel))
		samplesperpixel = 0;
	if (TIFFGetField(tif, TIFFTAG_SUBFILETYPE, &subfiletype)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Subfile Type:");
		sep = " ";
		if (subfiletype & FILETYPE_REDUCEDIMAGE) {
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%sreduced-resolution image", sep);
			sep = "/";
		}
		if (subfiletype & FILETYPE_PAGE) {
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%smulti-page document", sep);
			sep = "/";
		}
		if (subfiletype & FILETYPE_MASK)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%stransparency mask", sep);
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " (%" PRIu32 " = 0x%" PRIx32 ")\n",
		    subfiletype, subfiletype);
	}
	if (TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength)
	    && TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &imagewidth)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Image Width: %" PRIu32 " Image Length: %" PRIu32,
			imagewidth, imagelength);
		if (TIFFGetField(tif, TIFFTAG_IMAGEDEPTH, &imagedepth))
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " Image Depth: %" PRIu32,
			    imagedepth);
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\n");
	}
	if (TIFFGetField(tif, TIFFTAG_TILELENGTH, &tilelength)
	    && TIFFGetField(tif, TIFFTAG_TILEWIDTH, &tilewidth)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Tile Width: %" PRIu32 " Tile Length: %" PRIu32,
		    tilewidth, tilelength);
		if (TIFFGetField(tif, TIFFTAG_TILEDEPTH, &tiledepth))
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " Tile Depth: %" PRIu32,
			    tiledepth);
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\n");
	}
	if (TIFFGetField(tif, TIFFTAG_XRESOLUTION, &xresolution)
	    && TIFFGetField(tif, TIFFTAG_YRESOLUTION, &yresolution)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Resolution: %g, %g",
		    xresolution, yresolution);
		if (TIFFGetField(tif, TIFFTAG_RESOLUTIONUNIT, &resolutionunit)) {
			switch (resolutionunit) {
			case RESUNIT_NONE:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " (unitless)");
				break;
			case RESUNIT_INCH:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " pixels/inch");
				break;
			case RESUNIT_CENTIMETER:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " pixels/cm");
				break;
			default:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " (unit %" PRIu16 " = 0x%" PRIx16 ")",
				    resolutionunit,
				    resolutionunit);
				break;
			}
		}
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\n");
	}
	if (TIFFGetField(tif, TIFFTAG_XPOSITION, &xposition)
	    && TIFFGetField(tif, TIFFTAG_YPOSITION, &yposition))
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Position: %g, %g\n",
		    xposition, yposition);
	if (TIFFGetField(tif, TIFFTAG_BITSPERSAMPLE, &bitspersample))
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Bits/Sample: %" PRIu16 "\n", bitspersample);
	if (TIFFGetField(tif, TIFFTAG_SAMPLEFORMAT, &sampleformat)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Sample Format: ");
		switch (sampleformat) {
		case SAMPLEFORMAT_VOID:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "void\n");
			break;
		case SAMPLEFORMAT_INT:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "signed integer\n");
			break;
		case SAMPLEFORMAT_UINT:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "unsigned integer\n");
			break;
		case SAMPLEFORMAT_IEEEFP:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "IEEE floating point\n");
			break;
		case SAMPLEFORMAT_COMPLEXINT:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "complex signed integer\n");
			break;
		case SAMPLEFORMAT_COMPLEXIEEEFP:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "complex IEEE floating point\n");
			break;
		default:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
			    sampleformat, sampleformat);
			break;
		}
	}
	if (TIFFGetField(tif, TIFFTAG_COMPRESSION, &compression)) {
		const TIFFCodec* c = TIFFFindCODEC(compression);
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Compression Scheme: ");
		if (c)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%s\n", c->name);
		else
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
			    compression, compression);
	}
	if (TIFFGetField(tif, TIFFTAG_PHOTOMETRIC, &photometric)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Photometric Interpretation: ");
		if (photometric < NPHOTONAMES)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%s\n", photoNames[photometric]);
		else {
			switch (photometric) {
			case PHOTOMETRIC_LOGL:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "CIE Log2(L)\n");
				break;
			case PHOTOMETRIC_LOGLUV:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "CIE Log2(L) (u',v')\n");
				break;
			default:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
				    photometric, photometric);
				break;
			}
		}
	}
	if (extrasamples) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Extra Samples: %" PRIu16 "<", extrasamples);
		sep = "";
		for (i = 0; i < extrasamples; i++) {
			switch (sampleinfo[i]) {
			case EXTRASAMPLE_UNSPECIFIED:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%sunspecified", sep);
				break;
			case EXTRASAMPLE_ASSOCALPHA:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%sassoc-alpha", sep);
				break;
			case EXTRASAMPLE_UNASSALPHA:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%sunassoc-alpha", sep);
				break;
			default:
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%s%" PRIu16 " (0x%" PRIx16 ")", sep,
				    sampleinfo[i], sampleinfo[i]);
				break;
			}
			sep = ", ";
		}
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), ">\n");
	}
	if (TIFFGetField(tif, TIFFTAG_INKNAMES, &inknames) && samplesperpixel) {
		const char* cp;
		size_t inknameslen = strlen(inknames);
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Ink Names: ");
		i = samplesperpixel;
		sep = "";
		for (cp = inknames;
		     i > 0 && cp < inknames + inknameslen;
		     cp = strchr(cp,'\0')+1, i--) {
			size_t max_chars = 
				inknameslen - (cp - inknames);
            chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),sep);
            chars_used += _TIFFsnprintAsciiBounded(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), cp, max_chars);
			sep = ", ";
		}
        chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),"\n");
	}
	if (TIFFGetField(tif, TIFFTAG_THRESHHOLDING, &threshholding)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Thresholding: ");
		switch (threshholding) {
		case THRESHHOLD_BILEVEL:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "bilevel art scan\n");
			break;
		case THRESHHOLD_HALFTONE:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "halftone or dithered scan\n");
			break;
		case THRESHHOLD_ERRORDIFFUSE:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "error diffused\n");
			break;
		default:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
			    threshholding, threshholding);
			break;
		}
	}
	if (TIFFGetField(tif, TIFFTAG_FILLORDER, &fillorder)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  FillOrder: ");
		switch (fillorder) {
		case FILLORDER_MSB2LSB:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "msb-to-lsb\n");
			break;
		case FILLORDER_LSB2MSB:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "lsb-to-msb\n");
			break;
		default:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
			    fillorder, fillorder);
			break;
		}
	}
	if (TIFFGetField(tif, TIFFTAG_YCBCRSUBSAMPLING, &ycbcrsubsampling))
        {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  YCbCr Subsampling: %" PRIu16 ", %" PRIu16 "\n",
			ycbcrsubsampling[0], ycbcrsubsampling[1] );
	}
	if (TIFFGetField(tif, TIFFTAG_YCBCRPOSITIONING, &ycbcrpositioning)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  YCbCr Positioning: ");
		switch (ycbcrpositioning) {
		case YCBCRPOSITION_CENTERED:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "centered\n");
			break;
		case YCBCRPOSITION_COSITED:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "cosited\n");
			break;
		default:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
			    ycbcrpositioning, ycbcrpositioning);
			break;
		}
	}
	if (TIFFGetField(tif, TIFFTAG_HALFTONEHINTS, &halftonehints))
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Halftone Hints: light %" PRIu16 " dark %" PRIu16 "\n",
		    halftonehints[0], halftonehints[1]);
	if (TIFFGetField(tif, TIFFTAG_ORIENTATION, &orientation)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Orientation: ");
		if (orientation < NORIENTNAMES)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%s\n", orientNames[orientation]);
		else
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
			    orientation, orientation);
	}
	if (samplesperpixel)
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Samples/Pixel: %" PRIu16 "\n", samplesperpixel);
	if (TIFFGetField(tif, TIFFTAG_ROWSPERSTRIP, &rowsperstrip)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Rows/Strip: ");
		if (rowsperstrip == (uint32_t) -1)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "(infinite)\n");
		else
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu32 "\n", rowsperstrip);
	}
	if (TIFFGetField(tif, TIFFTAG_MINSAMPLEVALUE, &minsamplevalue))
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Min Sample Value: %" PRIu16 "\n", minsamplevalue);
	if (TIFFGetField(tif, TIFFTAG_MAXSAMPLEVALUE, &maxsamplevalue))
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Max Sample Value: %" PRIu16 "\n", maxsamplevalue);
	if (TIFFGetField(tif, TIFFTAG_SMINSAMPLEVALUE, &sminsamplevalue)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  SMin Sample Value: %g\n", sminsamplevalue);
	}
	if (TIFFGetField(tif, TIFFTAG_SMAXSAMPLEVALUE, &smaxsamplevalue)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  SMax Sample Value: %g\n", smaxsamplevalue);
	}
	if (TIFFGetField(tif, TIFFTAG_PLANARCONFIG, &planarconfig)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Planar Configuration: ");
		switch (planarconfig) {
		case PLANARCONFIG_CONTIG:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "single image plane\n");
			break;
		case PLANARCONFIG_SEPARATE:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "separate image planes\n");
			break;
		default:
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "%" PRIu16 " (0x%" PRIx16 ")\n",
			   planarconfig, planarconfig);
			break;
		}
	}
	if (TIFFGetField(tif, TIFFTAG_PAGENUMBER, &pagenumber))
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Page Number: %" PRIu16 "-%" PRIu16 "\n",
		    pagenumber[0], pagenumber[1]);
	if (TIFFGetField(tif, TIFFTAG_COLORMAP, &colormap)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Color Map: ");
		if (flags & TIFFPRINT_COLORMAP) {
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\n");
			n = 1L<<bitspersample;
			for (l = 0; l < n; l++)
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "   %5ld: %5" PRIu16 " %5" PRIu16 " %5" PRIu16 "\n",
				    l,
				    colormap[0][l],
				    colormap[1][l],
				    colormap[2][l]);
		} else
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "(present)\n");
	}
	if (TIFFGetField(tif, TIFFTAG_REFERENCEBLACKWHITE, &referenceblackwhite)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Reference Black/White:\n");
		for (i = 0; i < 3; i++)
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "    %2d: %5g %5g\n", i,
			referenceblackwhite[2*i+0],
			referenceblackwhite[2*i+1]);
	}
	if (TIFFGetField(tif, TIFFTAG_TRANSFERFUNCTION, &transferfunction)) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  Transfer Function: ");
		if (flags & TIFFPRINT_CURVES) {
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\n");
			n = 1L<<bitspersample;
			for (l = 0; l < n; l++) {
				chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "    %2ld: %5" PRIu16,
				    l, transferfunction[0][l]);
				for (i = 1;
				     i < samplesperpixel - extrasamples && i < 3;
				     i++)
					chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " %5" PRIu16,
					    transferfunction[i][l]);
                chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),"\n");

			}
		} else
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "(present)\n");
	}
	if (TIFFGetField(tif, TIFFTAG_SUBIFD, &nsubifd, &subifd) && subifd) {
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  SubIFD Offsets:");
		for (i = 0; i < nsubifd; i++)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), " %5" PRIu64,
				subifd[i]);
		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),"\n");
	}

	/*
	** Custom tag support.
	*/
	{
		int  i;
		short count;

		count = (short) TIFFGetTagListCount(tif);
		for(i = 0; i < count; i++) {
			uint32_t tag = TIFFGetTagListEntry(tif, i);
			const TIFFField *fip;
			uint32_t value_count;
			int mem_alloc = 0;
			void *raw_data;
			uint16_t dotrange[2]; /* must be kept in that scope and not moved in
						 the below TIFFTAG_DOTRANGE specific case */

			fip = TIFFFieldWithTag(tif, tag);
			if(fip == NULL)
				continue;

			if(TIFFFieldPassCount(fip)) {
				if (TIFFFieldReadCount(fip) == TIFF_VARIABLE2 ) {
					if(TIFFGetField(tif, tag, &value_count, &raw_data) != 1)
						continue;
				} else if (TIFFFieldReadCount(fip) == TIFF_VARIABLE ) {
					uint16_t small_value_count;
					if(TIFFGetField(tif, tag, &small_value_count, &raw_data) != 1)
						continue;
					value_count = small_value_count;
				} else {
					assert (TIFFFieldReadCount(fip) == TIFF_VARIABLE
						|| TIFFFieldReadCount(fip) == TIFF_VARIABLE2);
					continue;
				} 
			} else {
				if (TIFFFieldReadCount(fip) == TIFF_VARIABLE
				    || TIFFFieldReadCount(fip) == TIFF_VARIABLE2)
					value_count = 1;
				else if (TIFFFieldReadCount(fip) == TIFF_SPP)
					value_count = samplesperpixel;
				else
					value_count = TIFFFieldReadCount(fip);
				if (TIFFFieldTag(fip) == TIFFTAG_DOTRANGE
				    && strcmp(TIFFFieldName(fip),"DotRange") == 0) {
					/* TODO: This is an evil exception and should not have been
					   handled this way ... likely best if we move it into
					   the directory structure with an explicit field in 
					   libtiff 4.1 and assign it a FIELD_ value */
					raw_data = dotrange;
					TIFFGetField(tif, tag, dotrange+0, dotrange+1);
				} else if (TIFFFieldDataType(fip) == TIFF_ASCII
					   || TIFFFieldReadCount(fip) == TIFF_VARIABLE
					   || TIFFFieldReadCount(fip) == TIFF_VARIABLE2
					   || TIFFFieldReadCount(fip) == TIFF_SPP
					   || value_count > 1) {
					if(TIFFGetField(tif, tag, &raw_data) != 1)
						continue;
				} else {
					/*--: Rational2Double: For Rationals evaluate
					 * "set_field_type" to determine internal storage size. */
					raw_data = _TIFFmalloc(
					    _TIFFFieldDataSize(fip)
					    * value_count);
					mem_alloc = 1;
					if(TIFFGetField(tif, tag, raw_data) != 1) {
						_TIFFfree(raw_data);
						continue;
					}
				}
			}

			/*
			 * Catch the tags which needs to be specially handled
			 * and pretty print them. If tag not handled in
			 * _TIFFPrettyPrintField() fall down and print it as
			 * any other tag.
			 */
                if (raw_data != NULL) {
                    size_t c;
                    chars_used += c = _TIFFPrettySNPrintField(tif, str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), tag, value_count, raw_data);
                    if (!c)
                        chars_used += _TIFFSNPrintField(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), fip, value_count, raw_data);
                }
                if(mem_alloc)
                    _TIFFfree(raw_data);
                }
	}
        

        /* _TIFFFillStriles( tif ); */
        
	if ((flags & TIFFPRINT_STRIPS) &&
	    TIFFGetField(tif, TIFFTAG_STRIPOFFSETS, &stripoffsets) &&
	    TIFFGetField(tif, TIFFTAG_STRIPBYTECOUNTS, &stripbytecounts)) {
		uint32_t s;

		chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  %" PRIu32 " %s:\n",
		    TIFFNumberOfStrips(tif),
		    TIFFIsTiled(tif) ? "Tiles" : "Strips");
		for (s = 0; s < TIFFNumberOfStrips(tif); s++)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "    %3" PRIu32 ": [%8" PRIu64 ", %8" PRIu64 "]\n",
			    s,
			    stripoffsets[s],
			    stripbytecounts[s]);
	}
    return chars_used;
}

size_t
_TIFFsnprintAscii(char * str, const size_t xstrlen, const char* cp)
{
	return _TIFFsnprintAsciiBounded( str, xstrlen, cp, strlen(cp));
}

static size_t
_TIFFsnprintAsciiBounded(char * str, const size_t xstrlen, const char* cp, size_t max_chars)
{
    size_t chars_used=0;
	for (; max_chars > 0 && *cp != '\0'; cp++, max_chars--) {
		const char* tp;

		if (isprint((int)*cp)) {
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0),"%c",*cp);
			continue;
		}
		for (tp = "\tt\bb\rr\nn\vv"; *tp; tp++)
			if (*tp++ == *cp)
				break;
		if (*tp)
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\\%c", *tp);
		else
			chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\\%03o", *cp & 0xff);
	}
    return chars_used;
}

size_t
_TIFFsnprintAsciiTag(char * str, const size_t xstrlen, const char* name, const char* value)
{
    size_t chars_used=0;
	chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "  %s: \"", name);
	chars_used += _TIFFsnprintAscii(str+chars_used, xstrlen, value);
	chars_used += snprintf(str+chars_used, ((xstrlen>chars_used)?xstrlen-chars_used:0), "\"\n");
    return chars_used;
}

/* vim: set ts=8 sts=8 sw=8 noet: */
/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 8
 * fill-column: 78
 * End:
 */
