[![\[IUCr Home Page\]](../html_graphics/iucrhome.jpg)](http://www.iucr.org/iucr-top/welcome.html) [![\[CIF Home Page\]](../html_graphics/cifhome.jpg)](http://www.iucr.org/iucr-top/cif/home.html) [![\[CBF/imgCIF\]](../html_graphics/CBFbutton.jpg)](cbf_definition_rev.html) [![](../html_graphics/cbflibbutton.jpg)](CBFlib.html)

------------------------------------------------------------------------

\| [IUCr Home Page](http://www.iucr.org/iucr-top/welcome.html) \| [CIF Home Page](http://www.iucr.org/iucr-top/cif/home.html) \| [CBF/imgCIF](cbf_definition_rev.html) \| [CBFlib](CBFlib.html) \|  
\| [NOTICE](CBFlib_NOTICES.html) \| [GPL](gpl.txt) \| [LGPL](lgpl.txt) \| [imgCIF dictionary](cif_img_1.6.3.html) \|  
\| [Click Here to Make a Donation](http://arcib.dowling.edu/donation.shtml) \|

![](../html_graphics/cbflibbig.jpg)

## CBFlib ChangeLog

**An API for CBF/imgCIF  
Crystallographic Binary Files with ASCII Support**  
Version 0.9.3  
7 October 2013  

by  
Paul J. Ellis  
Stanford Synchrotron Radiation Laboratory  

and  
Herbert J. Bernstein  
Bernstein + Sons  

yayahjb **at** gmail **dot** com

© Copyright 2006, 2007, 2008, 2011, 2013 Herbert J. Bernstein

------------------------------------------------------------------------

**YOU MAY REDISTRIBUTE THE CBFLIB PACKAGE UNDER THE TERMS OF THE [GPL](gpl.txt).**

ALTERNATIVELY YOU MAY REDISTRIBUTE THE CBFLIB API UNDER THE TERMS OF THE [LGPL](lgpl.txt).

------------------------------------------------------------------------

### Before using this software, please read the [![NOTICE](../html_graphics/noticeButton.jpg)](CBFlib_NOTICES.html) for important disclaimers and the IUCr Policy on the Use of the Crystallographic Information File (CIF) and for other important information.

Work on imgCIF and CBFlib supported in part by the U. S. Department of Energy (DOE) under grants ER63601-1021466-0009501 and ER64212-1027708-0011962, by the U. S. National Science Foundation (NSF) under grants DBI-0610407, DBI-0315281 and EF-0312612, the U. S. National Institutes of Health (NIH) under grants 1R15GM078077 from NIGMS and 1R13RR023192 from NCRR and funding from the International Union for Crystallographyn (IUCr). The content is solely the responsibility of the authors and does not necessarily represent the official views of DOE, NSF, NIH, NIGMS, NCRR or IUCr. Recent work on integration among CBF, HDF5 and NeXus supported in part by Pandata ODI (EU 7th Framework Programme)

------------------------------------------------------------------------

## Version History

Version

Date

By

Description

  0.1

  Apr. 1998

  PJE

  This was the first CBFlib release. It supported binary CBF files using binary strings.

  [0.2](#0.2)

  Aug. 1998

  HJB

  This release added ascii imgCIF support using MIME-encoded binary sections, added the option of MIME headers for the binary strings was well. MIME code adapted from mpack 1.5. Added hooks needed for DDL1-style names without categories.

  [0.3](#0.3)

  Sep. 1998

  PJE

  This release cleaned up the changes made for version 0.2, allowing multi-threaded use of the code, and removing dependence on the mpack package.

  [0.4](#0.4)

  Nov. 1998

  HJB

  This release merged much of the message digest code into the general file reading and writing to reduce the number of passes. More consistency checking between the MIME header and the binary header was introduced. The size in the MIME header was adjusted to agree with the version 0.2 documentation.

  [0.5](#0.5)

  Dec. 1998

  PJE

  This release greatly increased the speed of processing by allowing for deferred digest evaluation.

  [0.6](#0.6)

  Jan. 1999

  HJB

  This release removed the redundant information (binary id, size, compression id) from a binary header when there is a MIME header, removed the unused repeat argument, and made the memory allocation for buffering and tables with many rows sensitive to the current memory allocation already used.

  [0.6.1](#0.6.1)

  Feb. 2001

  HP (per HJB)

  This release fixed a memory leak due to misallocation by size of cbf_handle instead of cbf_handle_struct

  [0.7](#0.7)

  Mar. 2001

  PJE

  This release added high-level instructions based on the imgCIF dictionary version 1.1.

  [0.7.1](#0.7.1)

  Mar. 2001

  PJE

  The high-level functions were revised to permit future expansion to files with multiple images.

  [0.7.2](#0.7.2)

  Apr. 2001

  HJB

  This release adjusted cbf_cimple.c to conform to cif_img.dic version 1.1.3

  [0.7.2.1](#0.7.2.1)

  May 2001

  PJE

  This release corrected an if nesting error in the prior mod to cbf_cimple.c.

  [0.7.3](#0.7.3)

  Oct. 2002

  PJE

  This release modified cbf_simple.c to reorder image data on read so that the indices are always increasing in memory (this behavior was undefined previously).

  [0.7.4](ChangeLog.html#0.7.4)

  Jan 2004

  HJB

  This release fixes a parse error for quoted strings, adds code to get and set character string types, and removes compiler warnings

  [0.7.5](ChangeLog.html#0.7.5)

  Apr 2006

  HJB

  This release cleans up some compiler warnings, corrects a parse error on quoted strings with a leading blank as adds the new routines for support of aliases, dictionaries and real arrays, higher level routines to get and set pixel sizes, do cell computations, and to set beam centers, improves support for conversion of images, picking up more data from headers.

  [0.7.6](ChangeLog.html#0.7.6)

  Jul 2006

  HJB

  This release reorganizes the kit into two pieces: CBFlib_0.7.6_Data_Files and CBFlib_0.7.6. An optional local copy of getopt is added. The 1.4 draft dictionary has been added. cif2cbf updated to support vcif2 validation. convert_image and cif2cbf updated to report text of error messages. convert_image updated to support tag and category aliases, default to adxv images. convert_image and img updated to support row-major images. Support added for binning. API Support added for validation, wide files and line folding. Logic changed for beam center reporting. Added new routines: cbf_validate, cbf_get_bin_sizes, cbf_set_bin_sizes, cbf_find_last_typed_child, cbf_compose_itemname, cbf_set_cbf_logfile, cbf_make_widefile, cbf_read_anyfile, cbf_read_widefile, cbf_write_local_file, cbf_write_widefile, cbf_column_number, cbf_blockitem_number, cbf_log, cbf_check_category_tags, cbf_set_beam_center

  [0.7.7](ChangeLog.html#0.7.7)

  February 2007

  HJB

  This release reflects changes for base 32K support developed by G. Darakev, and changes for support of reals, 3d arrays, byte_offset compression and J. P. Abrahams packed compression made in consultation with (in alphabetic order) E. Eikenberry, A. Hammerley, W. Kabsch, M. Kobas, J. Wright and others at PSI and ESRF in January 2007, as well accumulated changes fixing problems in release 0.7.6.

  [0.7.7.1](ChangeLog.html#0.7.7.1)

  February 2007

  HJB

  This release is a patch to 0.7.7 to change the treatment of the byteorder parameter from strcpy semantics to return of a pointer to a string constant. Our thanks to E. Eikenberry for pointing out the problem.

  [0.7.7.2](ChangeLog.html#0.7.7.2)

  February 2007

  HJB

  This release is a patch to 0.7.7.1 to add testing for JPA packed compression and to respect signs declared in the MIME header.

  [0.7.7.3](ChangeLog.html#0.7.7.3)

  April 2007

  HJB

  This release is a patch to 0.7.7.3 to add f90 support for reading of CBF byte-offset and packed compression, to fix problems with gcc 4.4.1 and to correct errors in multidimensional packed compression.

  [0.7.7.4](ChangeLog.html#0.7.7.4)

  May 2007

  HJB

  Corrects in handling SLS detector mincbfs and reorder dimensions versus arrays for some f90 compilers as per H. Powell.

  [0.7.7.5](ChangeLog.html#0.7.7.5)

  May 2007

  HJB

  Fix to cbf_get_image for bug reported by F. Remacle, fixes for windows builds as per J. Wright and F. Remacle.

  [0.7.7.6](ChangeLog.html#0.7.7.6)

  Jun 2007

  HJB

  Fix to CBF byte-offset compression writes, fix to Makefiles and m4 for f90 test programs to allow adjustable record length.

  [0.7.8](ChangeLog.html#0.7.8)

  Jul 2007

  HJB

  Release for full support of SLS data files with updated convert_minicbf, and support for gfortran from gcc 4.2.

  [0.7.8.1](ChangeLog.html#0.7.8.1)

  Jul 2007

  HJB

  Update to 0.7.8 release to fix memory leaks reported by N. Sauter and to update validation checks for recent changes.

  [0.7.8.2](ChangeLog.html#0.7.8.2)

  Dec 2007

  CN, HJB

  Update to 0.7.8.1 to add ADSC jiffie by Chris Nielsen, and to add ...\_fs and ...\_sf macros.

  [0.7.9](ChangeLog.html#0.7.9)

  Dec 2007

  CN, HJB

Identical to 0.7.8.2 except for a cleanup of deprecated examples, e.g. diffrn_frame_data

  [0.7.9.1](ChangeLog.html#0.7.9.1)

  Jan 2008

  CN, HJB

  Update to 0.7.8.2 to add inverse ADSC jiffie by Chris Nielsen, to clean up problems in handling maps for RasMol.

  [0.8.0](ChangeLog.html#0.8.0)

  Jul 2008

  GT, HJB

  Cleanup of 0.7.9.1 to start 0.8 series.

  [0.8.1](ChangeLog.html#0.8.1)

  Jul 2009

  EZ, CN, PC, GW, JH, HJB

   Release with EZ's 2008 DDLm support using JH's PyCifRW, also cbff f95 wrapper code, PC's java bindings.

  [0.9.1](ChangeLog.html#0.9.1)

  Aug 2010

  PC, EE, JLM, NS, EZ, HJB

   Release with EE's Dectris template software, also with vcif3, new arvai_test, sequence_match.

  [0.9.2](ChangeLog.html#0.9.2)

  Feb 2011

  PC, EE, JLM, NS, EZ, HJB

   New default release with updated pycbf, tiff support, removal of default use of PyCifRW to avoid Fedora license issue.

  [0.9.3](ChangeLog.html#0.9.3)

  Oct 2013

  JS, HJB

   New default release integrating CBF, HDF5 and NeXus.

------------------------------------------------------------------------

### <span id="0.9.3">Release 0.9.3</span>, John Lewis Muir, Jonathan Sloan, Graeme Winter, Herbert J. Bernstein, 7 October 2013

These are the cummulative mods from the 0.9.2 release in February 2011 to the 0.9.3 release in October 2013.

| Source File | Change |
|----|----|
| CBFlib.html, CBFlib.txt | Correction to description of byte-offset algorithm (JLM, 29 Mar 11) |
| cif_img_1.6.4_2Jul11.html, cif_img_1.6.4_2Jul11.dic | Corrections to support DLS Dectris header as per (GW, HJB, 2 Jul 11) |
| PyCifRW-3.3_6Dec09 | PyCifRW-3.3_6Dec09 removed because of license issues for Fedora (HJB, 6 Jul 11) |
| pycbf_wrap.c, cbf_tkfiledialog.py, cbfhandlewrappers.i, make_pycbf.py | Reverse setting of readable in pycbf write_file and write_widefile to ensure closure of the file immediately after a write. Fix errors in save_cbf in cbf_tkfiledialog.py (HJB, 30 Jul 11) |
| convert_minicbf.c, Makefiles | Update convert_minicbf.c and Makefiles to support both old and new test cases (HJB, 25 Oct 12) |
| convert_minicbf.c | Make convert_minicbf more fault tolerant with better warnings. (HJB, 29 Nov 12) |
| cbf_nibble_offset.c, cbf_nibble_offset.h, changtestcompression.c, cbf.h, cbf_read_mime.c, cbf_lex.c, cbf_simple.c, cbf_compress.c, cbf_copy.c, cif2cbf.c | Preliminary changes for cbf_nibble_offset. (HJB, 9 Dec 12) |
| cbf_hdf5.c, cbf_hdf5.h | Partial HDF5 support. (HJB, 28 Dec 12) Partial code for NeXus axis definitions. (HJB, 12 Jan 13) |
| cbf_hdf5_filter.c, bf_hdf5_filter.h, cbf.c, cbf.h, cbf_hdf5.c, cbf_hdf5.h, Makefiles | Addition of partially refactored code from J. Sloan (see below). Add all CBF compressions to Nexus with cbf_hdf5_filter (JS, HJB, 1 Jun 13) |
| cbf_hdf5.h, cbf_hdf5.c | New functions to interact with HDF5 at a realtively low level: cbf_H5Arequire_cmp, cbf_H5Arequire_string, cbf_H5Dcreate, cbf_H5Dfind, cbf_H5Drequire, cbf_H5Dinsert, cbf_H5Dset_extent, cbf_H5Dwrite, cbf_H5Dread, cbf_H5Drequire_scalar_F64LE, cbf_H5Drequire_string, cbf_H5Dfree, cbf_H5Fopen, cbf_H5Fclose, cbf_H5Gcreate, cbf_H5Grequire, cbf_H5Gfree, cbf_H5Ivalid, cbf_H5Screate, cbf_H5Sfree, cbf_H5Tcreate_string, cbf_H5Tfree |
| cbf_hdf5.h, cbf_hdf5.c | New functions to manage the lifetime of a 'cbf_h5handle' object, and access some commonly used components of a NeXus file in a safe way: cbf_create_h5handle, cbf_write_minicbf_h5file, cbf_write_cbf_h5file, cbf_free_h5handle, cbf_h5handle_require_file, cbf_h5handle_require_entry, cbf_h5handle_require_sample, cbf_h5handle_require_instrument, cbf_h5handle_require_detector, cbf_h5handle_require_monochromator |
| cbf_hdf5.h, cbf_hdf5.c | New functions to get some configration settings for a miniCBF file to allow it to be converted into a NeXus file: cbf_config_create, cbf_config_free, cbf_config_parse, cbf_config_strerror |
| cbf_ulp.h, cbf_ulp.c | New functions to compare IEEE-754 floating point numbers accurately: cbf_ULP32, cbf_ULP64 |
| minicbf2nexus.c, cbf2nexus.c | New utility programs for converting from CBF/miniCBF files to NeXus files. |
| testhdf5.c | New unit tests for the low-level 'cbf_H5\*' functions. |
| testulp.c | New unit tests and checks for applicability of the ulp comparison methods. |

------------------------------------------------------------------------

### <span id="0.9.2">Release 0.9.2</span>, Herbert J. Bernstein, 12 February 2011

Source File

Change

Makefile.m4, Makefiles

  Changes for libtiff and tiff2cbf. Create a separate setup.py for MINGW. Allow CBF_DONT_USE_LONG_LONG variable to control Makefiles. Disable default use of PyCifRW because of Fedora concerns about PyCifRW license issues. Force use of long long for SWIG. Update Makefiles to run changtestcompression. Update pycbf build.

cbf_template_t.c

  Don't use /tmp for dectris template code. Add EE's change for DLS signs

cbf_copy.c

  Fix cbf_copy.c to handle not using long long correctly

jcbf.i

  Move cbf.i to jcbf directory.

cbf_byte_offset.h, cbf_canonical.h, cbf_compress.h, cbf_packed.h, cbf_predictor.h, cbf_uncompressed.h, cbf.c, cbf_binary.c, cbf_byte_offset.c, cbf_canonical.c, cbf_compress.c, cbf_packed.c, cbf_predictor.c, cbf_uncompressed.c, cbff.c

  Implement P. Chang's fast byte-offset decompress, but with hooks to run on machines without long long support. Fix bad mask, fix sign extension for MINGW and other systems in which long long is not used. Fix error in mpint_shift logic causing erroneous sign Add changes in the compression infrastructure by P. Chang to make the compressed size available on decompression. Extend cbf_canonical to support long long and double. Correct cbf_packed for elsize 8 data.

cbfdetectorwrappers.i, cbfgenericwrappers.i, cbfgoniometerwrappers.i, cbfhandlewrappers.i, make_pycbf.py, pycbf.py, pycbf_test2.py, pycbf_wrap.c, cbf_simple.c

  Update pycbf for 0.9 release Add cbf_get_detector_axis_slow, cbf_get_detector_axis_fast, cbf_get_detector_axes, cbf_get_detector_axes_fs, cbf_get_detector_sf, and changes for pycbf wrapper

cbf2adscimg_sub.c

  Fix buffer overflow

cif_img_1.6.3_26Aug10.dic, cif_img_1.6.3_26Aug10.html Add variant category and tags and diffrn_scan_frame_monitor

------------------------------------------------------------------------

### <span id="0.9.1">Release 0.9.1</span>, P. Chang, E. Eikenberry, J. Lewis Muir, N. Sauter, E. Zlateva, Herbert J. Bernstein, 15 August 2010

Source File

Change

cbf_simple.c

  Fix nested axis handling.

cbf_template_t.c

  Add E.E.'s Dectris template software. Change to C-style comments.

Makefile.m4, Makefiles

  Add DMALLOC hooks.

arvai_test.c, seqmatchsub.c, seqmatchsub.h, sequence_match.c, cbf_copy.h, Makefile.m4, cbf_ascii.c, cbf_copy.c

  Add arvai_test and sequence_match examples. Transfer copy logic from cib2cbf into cbf_copy.c

cbf.h, cbf_ascii.h, cbf_file.h, cbf_write.h, cbff.h, cbf.c, cbf_ascii.c, cbf_file.c, cbf_lex.c, cbf_write.c

  As per request by J. Lewis Muir, direct all warning messages through cbf_log or new cbf_flog, so such messages can all be suppressed by setting the logfile to NULL

cbf_byte_offset.c, cbf_file.c

  Fix to byte-offset compression for 16 bit data with a delta that looks like a flag. Fix to setting/getting file position when there is no stream. Fix incorrect sign extension test as per N. Sauter.

convert_minicbf.c

  Allow for changes in miniheader and report unrecognized lines but continue. Also allow S/N instead of SN

Makefile.m4, Makefiles, Java.txt, testcbf.java, cbf.c

  As per P. Chang, decouple CBF_UNDEFINED error return from CBF_UNDEFINED node type by defining CBF_UNDEFNODE (rather than PC's CBF_UNDEFINEDNODE)

drel_prep.py, drel_yacc.py, cif2cbf.c, cbf.h, cbf.c, cbf_ascii.c, cbf_lex.c, cbf.stx.y, cbf_getopt.c, cbf_stx.c

  vcif 3 release.

cbf.h, cbf.c

  Add function cbf_set_column_name

------------------------------------------------------------------------

### <span id="0.8.1">Release 0.8.1</span>, E. Zlateva, C. Neilsen, P. Chang, G. Winter, J. Hester, Herbert J. Bernstein, 24 July 2009

Source File

Change

cbf.h, cbf_stx.h, cbf_tree.h, cbf.c, cbf.stx.y, cbf_lex.c, cbf_stx.c, Makefile.m4, Makefiles

  As per EZ, Add DDLm support, parsing of function definitions. Add auto download of J. Hester's PyCifRW and PLY

cbf_getopt.c

  Correct a memory leak and ensure correct handling of unspecified options when a '-' is given on the option string.

CBFlib.html, CBFlib.txt

  As per G. Winter correct documentation of byte-offset algorithm to refer to hex 80 not hex F0.

cbf_getopt.h, cbf_getopt.c, Makefile.m4, Makefiles, cif2cbf.c, convert_image.c, convert_minicbf.c, img2cif.c

  Introduce cbf_getopt.h, cbf_getopt.c, remove use of getopt

Java.txt, testcbf.c, testcbf.java, Makefile.m4, cbf.i

  P. Chang's java bindings

libtool directory

  Add a libtool build directory for future use of shared libraries.

cif2cbf.c

  Add test for construct_detector to cif2cbf. Fix getopt option string.

cif_tree.h

  Add DDLm bracket types for nodes

adscimg2cbf.c, adscimg2cbf_sub.c

  Apply mods to adscimg2cbf by C. Nielsen: Add new command line options: --beam_center_from_header, Figure out beam center from ADSC header information (default); --beam_center_mosflm, Beam center in ADSC header: MOSFLM coordinates; --beam_center_ulhc, Beam center in ADSC header: origin: upper left hand corner of image.(HKL mm); --beam_center_llhc, Beam center in ADSC header: origin: lower left hand corner of image.(adxv mm)

cbff.h, cbff.c

  Add src/cbff.c and include/cbff.h as start of full f95 wrapper for C code

------------------------------------------------------------------------

### <span id="0.8.0">Release 0.8.0</span>, G. Todorov, Herbert J. Bernstein, 21 July 2008

Source File

Change

adscimg2cbf_sub.c, adscimg2cbf_sub.c

  Patch to deal with gcc 4 optimization error in get_bo Replaced with call to cbf_get_local_integer_byte_order.

cbf.c, cbf.h, cbf_ascii.c, cbf_file.c, cbf_lex.c, cbf_write.c

  Clean up spacing; trim trailing blanks in text fields; validate DDLm types. Add MSG_DIGESTWARN. Update spacing. Fix includes for regex use. Fixes on achar and anchar and element. Added cbf_check_type_contents function that will verify ddlm types based on regular expressions. Fix handling for bracketed unquoted words and handle more DDLm tags. Fix scan of DDLm bracketed constructs with embedded quotes. Pick up item names in DDLm save frames. Fix cif2cbf handling of bracketed constructs in dictionaries. Updates to bracketed construct parse and output logic. Update write logic for bracketed constructs with folding. cbf_set_tag_category() code fixed. Change internal routine cbf_read_anyfile and add new user routine cbf_read_buffered_file to support pre-read of input files and memory-only files. Add new routines cbf_io_buffersize and cbf_reset_in_bits and change read logic to allow buffered reads.

------------------------------------------------------------------------

### <span id="0.7.9.1">Release 0.7.9.1</span>, Chris Nielsen, Herbert J. Bernstein, 24 January 2008

Source File

Change

cbf2adscimg.c cbf2adscimg_sub.c

  Last minutes fixes on release: Put missing byte swap in cbf2adscimg.c for when byte orders differ. Bypass problems with gcc optimization, and handle case then array header is there but invalid.

.symlinks .undosymlinks

  Update version to 0.7.9

Makefile.m4 Makefile, Makefile_AIX ...

  Update for CN's jiffies, and testing with MD5 signatures only

cbf2adscimg.c cbf2adscimg_sub.c

  New inverse jiffie by Chris Nielsen of ADSC to convert CBF files created by convert_image or adscimg2cbf to ADSC detector images. This version depends on the header extract planted by convert_image or adscimg2cbf.

cbf_byte_offset.c

  Fix handling of byte offset compression when the data does not compress.

cbf_codes.c

  Fix 32K encoding big-endian test as per Ladislav Michnovic .

cbf_packed.c

  Correct mishandling of 64 bit data.

cbf_uncompressed.c

  Remove redundant initialization of unsigned_char_data.

cbf_write.c.c

  Fix conflicting uses of variable column by introducing separate variable xcol.

README.html README

  Update to version 0.7.9 directory structure and programs.

cbf.c

  Fix local sensitivity of cbf_get_doublevalue and cbf_set_doublevalue so "." will be accepted and written as the decimal point in locales that use ",".

------------------------------------------------------------------------

### <span id="0.7.9">Release 0.7.9</span>, Chris Nielsen, Herbert J. Bernstein, 30 December 2007

Source File

Change

Makefiles and test data

  Change test cases to avoid deprecated features.

------------------------------------------------------------------------

### <span id="0.7.8.2">Release 0.7.8.2</span>, Chris Nielsen, Herbert J. Bernstein, 25 December 2007

Source File

Change

adscimg2cbf.c adscimg2cbf_sub.c

  New jiffie by Chris Nielsen of ADSC to convert ADSC detector images to CBF.

cbf.h cbf_byte_offset.h, cbf_compress.h, cbf_read_mime.h, cbf_simple.h

  Add \_fs and \_sf versions of cbf_get_arrayparameters_wdims, cbf_get_integerarrayparameters_wdims, cbf_get_realarrayparameters_wdims, cbf_set_integerarray_wdims, cbf_set_realarray_wdims, cbf_compress_byte_offset, cbf_compress, cbf_decompress, cbf_parse_mimeheader, cbf_get_pixel_size, cbf_set_pixel_size, cbf_get_image_size, cbf_get_image, cbf_get_real_image, cbf_get_3d_image_size, cbf_get_3d_image, cbf_get_real_3d_image, cbf_set_image, cbf_set_real_image, cbf_set_3d_image, cbf_set_real_3d_image, cbf_get_map_array_id, cbf_get_map_segment_size, cbf_get_map_segment, cbf_get_map_segment_mask, cbf_get_real_map_segment, cbf_get_real_map_segment_mask, cbf_set_map_segment, cbf_set_map_segment_mask, cbf_set_real_map_segment, cbf_set_real_map_segment_mask, cbf_get_3d_array_size, cbf_get_3d_array, cbf_set_3d_array, cbf_get_beam_center, cbf_set_beam_center, cbf_set_reference_beam_center, cbf_get_pixel_coordinates, cbf_get_pixel_normal, cbf_get_pixel_area, cbf_get_inferred_pixel_size

cbf_alloc.h

  Add prototype of cbf_free_text.

cbf_binary.h

  Add prototype of cbf_check_digest.

cbf_canonical.h

  Add definitions of cbf_compress_node and cbf_compress_data, and prototypes of cbf_make_compressdata, cbf_free_compressdata, cbf_initialise_compressdata, cbf_put_table, cbf_get_table, cbf_put_stopcode, cbf_insert_node, cbf_append_node, cbf_order_node, cbf_create_list, cbf_reduce_list, cbf_generate_codelengths, cbf_reverse_bitcodes, cbf_generate_canonicalcodes, cbf_compare_bitcodes, cbf_construct_tree, cbf_setup_decode, cbf_count_bits, cbf_get_code, cbf_put_code and cbf_count_values.

cbf_simple.h

  Add prototypes of cbf_get_detector_id and cbf_gregorian_julian.

cbf_string.c, cbf_string.h

  Add cbf_swab function for MS windows and other machines that do not provide swab.

cbf.c, cbf_binary.c, cbf_byte_offset.c, cbf_canonical.c, cbf_compress.c, cbf_lex.c, cbf_packed.c, cbf_predictor.c, cbf_read_mime.c, cbf_simple.c, cbf_uncompressed.c, cbf_write_binary.c

  Change dim1, dim2, dim3 to dimfast, dimmid, dimslow, ndim1, ndim2 to ndimslow, ndimfast. machines that do not provide swab.

cif2c.c

  Make declaration of xciftmp conditional to avoid compiler warnings.

convert_image.c

  Add code to check variations on pixel_size functions.

convert_minicbf.c

  Add second quick exit option (-Q). Improve error reporting. Update for most recent SLS miniheader.

getopt.c

  Fix some compiler warnings.

Makefile.m4

  add adscimg2cbf support

template_pilatus6m_2463x2527.cbf

  Update pilatus6m template for correct detector axis definitions, better comments and to list all categories used by SLS.

template_adscquantum315_3072x3072_rev.cbf

  New, corrected ADSC Quantum 315 template.

------------------------------------------------------------------------

### <span id="0.7.8.1">Release 0.7.8.1</span>, Chris Nielsen, Herbert J. Bernstein, 28 July 2007

Source File

Change

cbf.c

  Rework cbf_free_handle to ensure release of memory from root, not current position. Rework cbf_read_anyfile to ensure close of file stream on all exit cases. Fix save frame code in cbf_validate to restart counts on each save frame. Add name, idname and aliasname types from latest DDL2 dictionary.

cbf_alloc.c, cbf_alloc.h

  Add cbf_free_text to avoid type punning warnings from gcc 4. Add memory debug based on adding -DCBFLIB_MEM_DEBUG to CFLAGS.

cbf_simple.c

  Add code to ensure against memory leaks when working with a detector or positioner object.

cbf.stx.y, cbf_stx.c

  Add calls to cbf_undo_links and cbf_free_text to clean up memory leaks in parser. Add validation calls to mark end of save frames.

cbf_tree.c, cbf_tree.h

  Add cbf_undo_links to recover memory from links used to rotate among columns of a table. Rework cbf_free_node to avoid memory leaks.

cbf_uncompressed.c

  Add #define \_\_USE_XOPEN to avoid a warning on use of swab on some systems.

sauter_test.C Makefile.m4

  Add sauter_test to stress test for memory leaks. On make install, place cbf.h and cbf_simple.h into include directory.

------------------------------------------------------------------------

### <span id="0.7.8">Release 0.7.8</span>, Herbert J. Bernstein, 8 July 2007

Source File

Change

cbf_simple.c

  Update handling of both beam center and reference beam center to allow for units and new dictionary.

convert_minicbf.c

  Add code to handle data in \_array_data.header-contents. Clean up error handling, map all SLS tags. Add -Q option to convert old SLS comment format to new text field format.

Makefile, Makefile_AIX, Makefile_LINUX, Makefile_OSX

  As per ND add Makefile_LINUX_gcc42 and Makefile_OSX_gcc42 to handle gfortran 4.2 problems.

------------------------------------------------------------------------

### <span id="0.7.7.6">Release 0.7.7.6</span>, Herbert J. Bernstein, 30 June 2007

Source File

Change

cbf_codes.c

  Fix memory leaks in base32k encoding by G. Darakev.

cbf_byte_offset.c

  Fix in handling 32 bit offsets in the fast write code, which were incorrectly handled as 16 bit offsets.

Makefile, Makefile_AIX, Makefile_LINUX, Makefile_OSX

  Add M4FLAGS variable to control m4 expansion of f90 test programs with different record lengths. For g95, the record length must not be larger than the padding.

------------------------------------------------------------------------

### <span id="0.7.7.5">Release 0.7.7.5</span>, Herbert J. Bernstein, 9 May 2007

Source File

Change

cbf_codes.c

  Change from use of bzero to memset and remove include of strings.h

cbf_codes.c

  Change from use of bzero to memset and remove include of strings.h

cbf_simple.c

  Fix ordering of dimensions in cbf_get_3d_array_size and handling of non-zero binary ids to fix problems with cbf_get_image and cbf_get_image_size

cbf_uncompressed.c

  Add include of unistd.h for use of swab on more systems

Makefile

  Introduce $(TIME) variable for time command so it can be suppressed in windows

fcb_read_bits.m4

  Changes for g95 compatibility.

cif2c.c, cif2cbf.c, etc.

  Make use of mkstemp conditional on NOMKSTEMP. Make use of /tmp conditional on NOTMPDIR.

------------------------------------------------------------------------

### <span id="0.7.7.4">Release 0.7.7.4</span>, Herbert J. Bernstein, 6 May 2007

Source File

Change

cbf_simple.c

  Fix ordering of dimensions in cbf_set_3d_array.

cbf_uncompressed.c

  Add include of ctype.h to provide prototype for toupper.

convert_image.c

  Enable -p option for non-standard templates; correct handling of seconds in timestamps.

convert_minicbf.c

  Enable code for timestamp, exposure time, comment-style header.

fcb_packed.m4

  As per H. Powell, move declarations for dimensions before declarations of arrays.

fcb_read_image.m4

  As per H. Powell, move declarations for dimensions before declarations of arrays.

fcblib_defines.m4

  As per H. Powell, move declarations for dimensions before declarations of arrays.

------------------------------------------------------------------------

### <span id="0.7.7.3">Release 0.7.7.3</span>, Herbert J. Bernstein, 3 April 2007

Source File

Change

Makefile

  Add m4 directory to build f90 sources. Add .f90 routines to src and examples. Add libfcb.a to lib. Add tests for f90 routines to extra tests.

testflat.c

  Add support for 3D test.

testflatpacked.c

  Add support for 3D test.

cbf_binary.c

  Correct dim2,dim2 to be dim1,dim2 in check_digest.

cbf_packed.c

  Correct JPA pointer logic for 3D case. Work around compiler problems with handling of sign bits

fcb_exit_binary.m4

  New m4 macro file to build fcb_exit_binary.f90 a routine to skip from the end of a binary to the end of the text field.

fcb_next_binary.m4

  New m4 macro file to build fcb_next_binary.f90 a routine to skip to the start of the next binary.

fcb_open_cifin.m4

  New m4 macro file to build fcb_open_cifin.f90 a routine to open a cbf file.

fcb_packed.m4

  New m4 macro file to build fcb_packed.f90 a routine to uncompress JPA packed binaries.

fcb_read_bits.m4

  New m4 macro file to build fcb_read_bits.f90 a routine to read an arbitrary number of bits as an integer.

fcb_read_image.m4

  New m4 macro file to build fcb_read_image.f90 a set of routines to read a byte offset or packed image

fcb_read_xds_i2.m4

  New m4 macro file to build fcb_read_xds_i2.f90 a routine to read a single xds I2 image.

fcblib_define.m4

  New m4 macro file of common definitions for all f90 code

test_fcb_read_image.m4

  New m4 macro file of build test_fcb_read_image.f90 a test program for the f90 routines.

test_xds_binary.m4

  New m4 macro file of build test_xds_binary.f90 a test program for the f90 routines.

fcb_atol_wcnt.f90

  f90 code to convert a string to an integer.

fcb_ci_strncmparr.f90

  f90 code to do a case-insensitive string comparison

fcb_nblen.f90

  f90 code to do test the non-blank length of a string

fcb_read_byte.f90

  f90 code to read a byte

fcb_read_line.f90

  f90 code to read a line

fcb_skip_whitespace.f90

  f90 code to skip MIME whitespace

------------------------------------------------------------------------

### <span id="0.7.7.2">Release 0.7.7.2</span>, Herbert J. Bernstein, 27 February 2007

Source File

Change

Makefile

  Add testflatpacked build to extra test dependencies.

testflat.c

  Add more test cases.

testflatpacked.c

  Add version of testflat for packed compression.

cbf_binary.c

  Add recovery of sign from mime header.

cbf_byte_offset.c

  Change limit logic to simple mask and remove overflow report.

cbf_packed.c

  Change limit logic to simple mask and remove overflow report.

cbf_uncompressed.c

  Change limit logic to simple mask and remove overflow report.

------------------------------------------------------------------------

### <span id="0.7.7.1">Release 0.7.7.1</span>, Herbert J. Bernstein, 25 February 2007

Source File

Change

Makefile

  Add testflat build to extra test dependencies.

CBFlib.html

  Add descriptions of cbf_get_integerarrayparameters_wdims, cbf_get_realarrayparameters_wdims, cbf_set_integerarray_wdims, cbf_set_realarray_wdims

cif2cbf.c

  Change to use of byteorder as a pointer to a constant string, rather than as a local copy of a string.

testflat.c

  Add report of byteorder, dim1, dim2, dim2, padding.

cbf.h,  
cbf_binary.h,  
cbf_byte_offset.h,  
cbf_canonical.h,  
cbf_compress.h,  
cbf_packed.h,  
cbf_predictor.h,  
cbf_read_mime.h,  
cbf_uncompressed.h

  Change prototypes for all functions that return byteorder from char \* byteorder to const char \*\* byteorder. Change prototypes of all functions that set byteorder from char \* byteorder to const char \* byteorder

cbf.c,  
cbf_binary.c,  
cbf_byte_offset.c,  
cbf_canonical.c,  
cbf_compress.c,  
cbf_lex.c,  
cbf_packed.c,  
cbf_predictor.c,  
cbf_read_mime.c,  
cbf_uncompressed.c,  
cbf_write_binary.c

  Change signatures for all functions that return byteorder from char \* byteorder to const char \*\* byteorder. Change prototypes of all functions that set byteorder from char \* byteorder to const char \* byteorder, and make the matching changes in all calls.

------------------------------------------------------------------------

### <span id="0.7.7">Release 0.7.7</span>, Herbert J. Bernstein, 19 February 2007

Source File

Change

cif2cbf.c

  Add support for byte offset, packed version 2 and flat compression, and binary section padding. Add support for base-32K encoding. Allow command line compression to override compression_type in the file and to set compression_type_flag.

convert_image.c

  Add support for new -R and -F flags, for use of reference beam center and flat packed compression respectively.

cbf.h

  Add constants CBF_PACKED_V2 for packed version 2 compression, CBF_UNCORRELATED_SECTIONS for uncorrelated sections in packed compression, CBF_FLAT_IMAGE for original CBFlib packed compression, PAD_1K, PAD_2K and PAD_4K for trailing pad on binary sections, ENC_BASE32K for base 32K encoding. Fix bad code in DEBUG mode for failnez macros. Add prototypes for cbf_get_arrayparameters_wdims, cbf_get_integerarrayparameters_wdims, cbf_get_realarrayparameters_wdims, cbf_set_integerarray_wdims, cbf_set_realarray_wdims, cbf_mpint_load_acc, cbf_mpint_store_acc, cbf_mpint_clear_acc, cbf_mpint_increment_acc, cbf_mpint_decrement_acc, cbf_mpint_negate_acc, cbf_mpint_add_acc, cbf_mpint_rightshift_acc, cbf_mpint_leftshift_acc.

cbf_binary.h

  Update prototypes for cbf_get_bintext, cbf_set_bintext, cbf_set_binary, cbf_binary_parameters, cbf_get_binary to carry byteorder, dimensions and padding.

cbf_byte_offset.h

  Update prototypes for cbf_compress_byte_offset, cbf_decompress_byte_offset to carry byteorder, dimensions and padding.

cbf_canonical.h

  Update prototypes for cbf_compress_canonical, cbf_decompress_canonical to carry byteorder, dimensions and padding.

cbf_codes.h

  Add prototypes for base 32K encoding: cbf_tobase32k, cbf_encode32k_bit_op, cbf_isBigEndian, cbf_endianFix, cbf_frombase32k, cbf_decode32k_bit_op.

cbf_compress.h

   Update prototypes for cbf_compress, cbf_decompress to carry byteorder, dimensions and padding.

cbf_packed.h

  Update prototypes for cbf_compress_packed, cbf_decompress_packed to carry byteorder, dimensions and padding.

cbf_predictor.h

  Update prototypes for cbf_compress_predictor, cbf_decompress_predictor to carry byteorder, dimensions and padding.

cbf_read_mime.h

  Update prototype for cbf_parse_mimeheader to carry byteorder, dimensions and padding.

cbf_simple.h

  Add prototypes for cbf_get_3d_array_size, cbf_get_3d_array, cbf_get_3d_image_size, cbf_get_3d_image, cbf_get_map_array_id, cbf_get_map_segment_mask, cbf_get_map_segment_size, cbf_get_map_segment, cbf_get_real_3d_image, cbf_get_real_map_segment, cbf_get_real_map_segment_mask, cbf_set_3d_array, cbf_set_3d_image, cbf_set_map_segment, cbf_set_map_segment_mask, cbf_set_real_3d_image, cbf_set_real_map_segment, cbf_set_real_map_segment_mask.

cbf_uncompressed.h

  Update prototypes for cbf_compress_none, cbf_decompress_none to carry byteorder, dimensions and padding.

Makefile

  Update version and tests to work against data files in CBFlib_0.7.7_Data_Files.

cbf.c

   Remove compiler warnings on signedness and type punned pointers. Fix bug in detection of local real format. Add base32K support. Fix inverted test in value range checking. Add new routines cbf_get_arrayparameters_wdims, cbf_get_integerarrayparameters_wdims, cbf_get_realarrayparameters_wdims, cbf_set_integerarray_wdims, cbf_set_realarray_wdims, cbf_mpint_load_acc, cbf_mpint_store_acc, cbf_mpint_clear_acc, cbf_mpint_increment_acc, cbf_mpint_decrement_acc, cbf_mpint_negate_acc, cbf_mpint_add_acc, cbf_mpint_rightshift_acc, cbf_mpint_leftshift_acc.

cbf.stx.y

  Temporarily change to use of YYSTYPE argument type to remove an error when compiling under on MS Windows. A better solution is needed./

cbf_binary.c

  Update cbf_get_bintext, cbf_set_bintext, cbf_set_binary, cbf_binary_parameters, cbf_get_binary to carry byteorder, dimensions and padding.

cbf_byte_offset.c

  Implement byte_offset compression and decompression as designed by A. Hammersley and modified by W. Kabsch.

cbf_canonical.c

  Fix warnings from gcc 4 on punned pointers. Update cbf_compress_canonical, cbf_decompress_canonical to carry byteorder, dimensions and padding.

cbf_codes.c

  Add support forr base 32K encoding: cbf_tobase32k, cbf_encode32k_bit_op, cbf_isBigEndian, cbf_endianFix, cbf_frombase32k, cbf_decode32k_bit_op.

cbf_compress.c

   Update cbf_compress, cbf_decompress carry byteorder, dimensions and padding.

cbf_file.c

  Fix warnings from gcc 4 on punned pointers.

cbf_lex.c

  Add support for byteorder, dimensions and padding and base 32K encoding.

cbf_packed.c

  Update cbf_compress_packed, cbf_decompress_packed to carry byteorder, dimensions and padding. Add support for J. P. Abrahams packed compression, versions 1 and 2, while preserving support for original CBFlib flat packed compression. Add support for 64 bit elements.

cbf_predictor.c

  Update cbf_compress_predictor, cbf_decompress_predictor to carry byteorder, dimensions and padding.

cbf_simple.c

  Change logic of most image handling routines to work as special cases of 3d routines. Add new routines cbf_get_detector_id, cbf_get_real_map_segment, cbf_get_real_map_segment_mask, cbf_set_map_segment, cbf_set_map_segment_mask, cbf_set_real_map_segment, cbf_set_real_map_segment_mask, cbf_get_3d_array_size, cbf_get_3d_array, cbf_set_3d_array, cbf_get_axis_reference_setting, cbf_set_axis_reference_setting, cbf_construct_reference_detector, cbf_require_reference_detector, cbf_set_reference_beam_center.

cbf_read_mime.c

  Update cbf_parse_mimeheader to read MIME headers for new compression types and flags and byteorder, dimensions and padding. Add support for base 32K encoding.

cbf_tree.c

  Fix warnings from gcc 4 on punned pointers.

cbf_uncompressed.c

  Fix handling of 64-bit reads and writes.

cbf_write_binary.c

  Add code to write out base-32K encoded sections, to write byte order, dimensions and padding. Add code to write out MIME headers for packed compressions or packed version 2 compression with flags for uncorrelated sections and for flat packed images.

------------------------------------------------------------------------

### <span id="0.7.6">Release 0.7.6</span>, Herbert J. Bernstein, 15 July 2006

Source File

Change

cbf.h

  Add include of stdio.h; change CBF_LINELENGTH into CBF_LINELENGTH_10 and CBF_LINELENGTH_11; add new symbols CBF_CASE_INSENSITIVE, CBF_CASE_SENSITIVE, CBF_LOGERROR, CBF_LOGWARNING, CBF_LOGWOLINE, CBF_LOGWOCOLUMN, CBF_LOGSTARTLOC, CBF_LOGCURRENTLOC; add information on input file and log file to cbf handle struct; and prototypes for cbf_read_widefile, cbf_write_local_file, cbf_write_widefile, cbf_column_number, cbf_blockitem_number, cbf_warning, cbf_error, cbf_log, cbf_increment_column, cbf_reset_column, cbf_reset_refcounts, cbf_validate; added valuerow argument to cbf_set_hashedvalue and caseinsensitive to cbf_find_hashedvalue.

cbf.c

  In cbf_make_handle, added include of cbf_ascii.h, initialized handle-\>logfile, handle-\>warnings, handle-\>errors, handle-\>startline, handle-\>startcolumn; added new routine cbf_set_logfile; in cbf_free_handle removed gcc4 warning; broke up cbf_read_file into cbf_read_anyfile, cbf_read_file, added two more entries to parse array, one for the cbf handle and one to carry an auxillary node, such as a parent category; in cbf_write_file, reset reference counts; added new routine cbf_write_local_file to allow writing of a local portion of a cbf instead of the whole thing; added new routines cbf_column_number and cbf_blockitem_number; added new routine cbf_log to report parse errors with line numbers; fixed cbf_require_category when dealing with null datablocks; fixed cbf_require_column to preserve current row number; fixed inverted logic in cbf_require_dictionary; rewrote cbf_set_hashed_value to deal with insertions correctly; revised cbf_find_hashedvalue to survive commong errors; revised cbf_convert_dictionary_definition to recover category information properly and top deal with more complex loop-singleton interactions; added new routines cbf_increment_column, cbf_reset_column, cbf_reset_refcounts; updated cbf_convert_dictionary to align database with changes in cbf_convert_dictionary_definition and to distribute unspecified items from parents to children; fixed cbf_find_local_tag for DDL1 names and categories; updated cbf_find_category_root and cbf_require_category_root to allow for DDL1 categories drawn from dictionaries; changed cbf_find_tag_root and cbf_set_tag_root to use cbf_find_hashedvalue and cbf_set_hashedvalue; added routines cbf_check_category_tags, cbf_validate.

cbf.stx.y

  To facilitate validation, changed save frame logic to append partial save frame to the base cif from the beginning instead of waiting for the end of the save frame; added cbf_validate calls at all levels and provided detailed parse form common errors with reports via cbf_log

cbf_ascii.h

  Add prototype for cbf_foldtextline.

cbf_ascii.c

  Added new routine cbf_foldtextline; in cbf_write_ascii changed logic to no longer backslash-quote individual embedded semicolons in text fields and to use full line-folding spec;

cbf_canonical.c

  fixed gcc4 warning.

cbf_cantext.c

  fixed gcc4 warnings.

cbf_file.h

  Add columnlimit to strcut; add prototype for cbf_make_widefile.

cbf_file.c

  In cbf_make_file added intialization of line length; added new routine cbf_make_widefile; in cbf_read_character do not increment column number at EOF; in cbf_read_line report lines over the limit

cbf_lex.c

  Added lexical validation for line length, illegal characters, long data block names, long save frame names, failure to provide whitespace after loop\_, unterminated quoted strings.

cbf_packed.c

  Fix gcc4 warnings

cbf_read_mime.c

  Pick up corrections to parse of types from work by GD for X-BASE32K.

cbf_simple.h

  Add prototypes for cbf_get_bin_sizes, cbf_set_bin_sizes

cbf_simple.c

  Changed cbf_read_template to use cbf_read_widefile; added new routines cbf_get_bin_sizes and cbf_set_bin_sizes; changed cbf_set_gain, cbf_set_overload, cbf_set_integration_time, cbf_set_datestamp, cbf_set_axis_setting to force in intervening categories and columns; in cbf_free_positioner, cbf_free_detector, fixed gcc4 warnings; revised cbf_set_beam_center to adjust the displacement rather than the offset.

cbf_tree.h

  Add symbol for CBF_VALUE as a node type to use for validation; add prototype for cbf_find_last_typed_child.

cbf_tree.c

  In cbf_free_node fixed gcc4 warning; added new routine cbf_find_last_typed_child; changed cbf_make_child to use cbf_find_last_typed_child instead of cbf_fid_last_child to avoid confusion between categories and save frames when the same name is used for both; changed cbf_compute_hashcode to return values between 0 and 255.

cbf_write.d

  Add prototype for cbf_compose_itemname.

cbf_write.c

  In cbf_set_value fold text fields that contain the text field terminator; add new routine cbf_compose_itemname, int cbf_write_itemname catch names that are too long;

cif2cbf.c

  Add "-v dictionary" command line argument and suppress output to /dev/null and "-w" to process a wide file; add hooks (based on symbol GNUGETOPT) to use a local copy of getopt; add text for error exits; add code to load layered dictionaries.

convert_image.c

  Add text for error exits; add logic for binning; alias support with command line arguments "-c category_alias=category_root" and "-t tag_alias=tag_root", change from \_diffrn_detector.sample_detector_distance to \_diffrn_measurement.sample_detector_distance; change to support row-major images to agree with adxv; remove most advisory messages to stdout.

img.h

  Added rowmajor to struct; redefined img_pixel to be conditional on rowmajor; added img_pixelptr to get the pointers to the image.

img.c

  Added recognition of ADSC QUANTUM315; added row major support

img2cif.c

  Changed to use to new img.h macros

makecbf.c

  Changed to use to new img.h macros

------------------------------------------------------------------------

### <span id="0.7.5">Release 0.7.5</span>, Herbert J. Bernstein, 15 April 2006

Source File

Change

cbf.c

  Revised header for open source licenses; added support for aliases, dictionaries and real arrays; added convenience routines to do searches with default creation of what is being searched for; added reference count and dictionary link for cbf handles; added cbf_new_saveframe, cbf_force_new_saveframe, cbf_set_saveframename, cbf_reset_saveframe, cbf_remove_saveframe, cbf_rewind_saveframe, cbf_rewind_blockitem, cbf_next_saveframe, cbf_next_blockitem, cbf_select_saveframe, cbf_select_blockitem, cbf_find_saveframe, cbf_require_row, cbf_require_nextrow, cbf_count_saveframes, cbf_count_blockitems, cbf_saveframe_name, cbf_require_value, cbf_require_integervalue, cbf_require_doublevalue, cbf_get_realarrayparameters, cbf_get_realarray, cbf_set_realarray, cbf_require_datablock, cbf_require_category, cbf_require_column, cbf_require_column_value, cbf_require_column_integervalue, cbf_require_column_doublevalue, cbf_get_local_integer_byte_order, cbf_get_local_real_byte_order, cbf_get_local_real_format, cbf_get_dictionary, cbf_set_dictionary, cbf_require_dictionary, cbf_set_hashedvalue, cbf_find_hashedvalue, cbf_convert_dictionary_definition, cbf_convert_dictionary, cbf_find_tag, cbf_find_local_tag, cbf_srch_tag, cbf_find_category_root, cbf_require_category_root, cbf_set_category_root, cbf_find_tag_root, cbf_require_tag_root, cbf_set_tag_root, cbf_find_tag_category, cbf_set_tag_category.

cbf.h

  Revised header for open source licenses; added definitions of CBF_API_VERSION and CBF_DIC_VERSION; changed the debug versions of cbf_failnez and cbf_onfailnez to stringfy the argument; added dictionary and reference count to cbf_handle definition; added prototypes for cbf_new_saveframe, cbf_force_new_saveframe, cbf_set_saveframename, cbf_remove_saveframe, cbf_rewind_saveframe, cbf_rewind_blockitem, cbf_next_saveframe, cbf_next_blockitem, cbf_saveframe_name, cbf_select_saveframe, cbf_select_blockitem, cbf_find_saveframe, cbf_require_row, cbf_require_nextrow, cbf_count_saveframes, cbf_count_blockitems, cbf_require_value, cbf_require_integervalue, cbf_require_doublevalue, cbf_get_realarrayparameters, cbf_get_realarray, cbf_set_realarray, cbf_require_datablock, cbf_require_category, cbf_require_column, cbf_require_column_value, cbf_require_column_integervalue, cbf_require_column_doublevalue, cbf_get_local_integer_byte_order, cbf_get_local_real_byte_order, cbf_get_local_real_format, cbf_get_dictionary, cbf_set_dictionary, cbf_require_dictionary, cbf_set_hashedvalue, cbf_find_hashedvalue, cbf_convert_dictionary_definition, cbf_convert_dictionary, cbf_find_tag, cbf_find_local_tag, cbf_srch_tag, cbf_find_category_root, cbf_require_category_root, cbf_set_category_root, cbf_find_tag_root, cbf_require_tag_root, cbf_set_tag_root, cbf_find_tag_category, cbf_set_tag_category,

cbf_alloc.c

  Revised header for open source licenses.

cbf_alloc.h

  Revised header for open source licenses.

cbf_ascii.c

  Revised header for open source licenses.

cbf_ascii.h

  Revised header for open source licenses.

cbf_binary.c

  Revised header for open source licenses; added support of real arrays.

cbf_binary.h

  Revised header for open source licenses; added support of real arrays.

cbf_byte_offset.c

  Revised header for open source licenses; changed signature for support of real arrays; no actual changes to the code.

cbf_byte_offset.h

  Revised header for open source licenses; changed signature for support of real arrays; no actual changes to the code.

cbf_canonical.c

  Revised header for open source licenses; changed signatures for support of real arrays; no actual changes to the code.

cbf_canonical.h

  Revised header for open source licenses; changed signatures for support of real arrays; no actual changes to the code.

cbf_codes.c

  Revised header for open source licenses.

cbf_codes.h

  Revised header for open source licenses.

cbf_compress.c

  Revised header for open source licenses; added support of real arrays.

cbf_compress.h

  Revised header for open source licenses; added support of real arrays.

cbf_context.c

  Revised header for open source licenses.

cbf_context.h

  Revised header for open source licenses.

cbf_file.c

  Revised header for open source licenses; added support of real arrays, making extensive changes to the handling of integers to get past 32 bit limits.

cbf_file.h

  Revised header for open source licenses..

cbf_lex.c

  Revised header for open source licenses; added save frame support; required whitespace before a comment; changed WORD to CBFWORD; corrected quoted string parse to allow for a blank immediately after the opening quote mark.

cbf_lex.h

  Revised header for open source licenses.

cbf_packed.c

  Revised header for open source licenses; changed signatures for support of real arrays; no actual changes to the code.

cbf_packed.h

  Revised header for open source licenses; changed signatures for support of real arrays; no actual changes to the code.

cbf_predictor.c

  Revised header for open source licenses; changed signatures for support of real arrays; no actual changes to the code.

cbf_predictor.h

  Revised header for open source licenses; changed signatures for support of real arrays; no actual changes to the code.

cbf_read_binary.c

  Revised header for open source licenses.

cbf_read_binary.h

  Revised header for open source licenses.

cbf_read_mime.c

  Revised header for open source licenses; added support for real arrays.

cbf_read_mime.h

  Revised header for open source licenses; added support for real arrays.

cbf_simple.c

  Revised header for open source licenses; increased precision of all numbers to 15 digits; added support for cells and orientation matrices; built in support for diffrn_frame_data as an alternative to diffrn_data_frame; added new routines cbf_require_diffrn_id, cbf_get_pixel_size, cbf_set_pixel_size, cbf_get_real_image, cbf_set_real_image, int cbf_require_detector, cbf_set_beam_center, cbf_get_inferred_pixel_size, cbf_get_unit_cell, cbf_set_unit_cell, cbf_get_reciprocal_cell, cbf_set_reciprocal_cell, cbf_compute_cell_volume, cbf_compute_reciprocal_cell, cbf_get_orientation_matrix, cbf_set_orientation_matrix; added braces to deal with compiler warnings on dangling else.

cbf_simple.h

  Revised header for open source licenses; added prototypes for cbf_require_diffrn_id, cbf_get_array_id, cbf_get_pixel_size, cbf_set_pixel_size, cbf_get_real_image, cbf_set_real_image, cbf_require_detector, cbf_set_beam_center, cbf_get_inferred_pixel_size, cbf_get_unit_cell, cbf_set_unit_cell, cbf_get_reciprocal_cell, cbf_set_reciprocal_cell, cbf_compute_cell_volume, cbf_compute_reciprocal_cell, cbf_get_orientation_matrix, cbf_set_orientation_matrix.

cbf_string.c

  Revised header for open source licenses.

cbf_string.h

  Revised header for open source licenses.

cbf_stx.c

  Rebuilt from new cbf.stx.y.

cbf_stx.h

  Changed WORD to CBFWORD; added SAVE and SAVEEND.

cbf.stx.y

  Revised header for open source licenses; Revised grammar to support save frames and to be more comprehensible; changed name from cbf.stx

cbf_tree.c

  Revised header for open source licenses; added code to support save frames, allowing typed searches for children; added new routines cbf_find_typed_child, cbf_count_typed_children, cbf_compute_hashcode.

cbf_tree.c

  Revised header for open source licenses; added definition of CBF_SAVEFRAME as node type; added prototypes for cbf_find_typed_child, cbf_count_typed_children, cbf_compute_hashcode.

cbf.uncompressed.c

  Revised header for open source licenses; Added support for real arrays, and to remove 32 bit limits.

cbf.uncompressed.h

  Revised header for open source licenses; Added support for real arrays.

cbf.write.c

  Revised header for open source licenses; added support for save frames and aliases; changed logic for single row categories to present item-by-item, instead of as a loop except for vectors and matrices, present matrices row by row; carried cbf handle through nest of calls.

cbf.write.h

  Revised header for open source licenses; adjusted prototype of cbf_write_node to carry the cbf handle as the first argument.

cbf.write_binary.c

  Revised header for open source licenses; added support for real arrays.

cbf.write_binary.h

  Revised header for open source licenses.

Makefile

  Revised header for open source licenses; defined C++; added symbol RANLIB for use on systems that require a ranlib pass after creating a library with ar; added build and tests of testcell and cif2c; added ADSC test case to tests of convert_image; updated list of contents of tar;changed cbf.stx to cbf.stx.y.

connvert_image.c

  Revised header for open source licenses; added command line arguments for detector name, detector distance, rotation and reflection of the image; added usage report on errors; added code for axis transforms; added code to report image header fields; cleaned up PHI reporting; recovered pixel size and beam center from header; commented out most debug code.

cif2cbf.c

  Revised header for open source licenses; renamed BUFSIZ as C2CBUFSIZ to remove a compiler warning; process save frames.

img2cif.c

  Revised header for open source licenses; renamed BUFSIZ as I2CBUFSIZ to remove a compiler warning.

testcell.C

  New program to test cell functions.

cif2c.c

  New program to test cell functions.

------------------------------------------------------------------------

### <span id="0.7.4">Release 0.7.4</span>, Herbert J. Bernstein, 12 January 2004

Source File

Change

cbf.c

  added cbf_set_typeofvalue, cbf_get_typeofvalue; added braces for nested if-else to remove a compiler warning.

cbf_ascii.c

  added braces to remove a compiler warnings.

cbf_binary.c

  added braces to remove a compiler warnings.

cbf_canonical.c

  added braces to remove a compiler warnings.

cbf_compress.c

  added braces to remove a compiler warnings.

cbf_file.c

  simplied dynamic array logic and went to straight doubling; added braces to remove a compiler warnings.

cbf_lex.c

  changed parse of quoted strings to allow for embedded quote marks; removed unused variables; fixed mismatch of formats; added braces to remove a compiler warnings.

cbf_packed.c

  added braces to remove a compiler warnings; intialized variables.

cbf_simple.c

  typed default typed variable; removed unused variables; added braces to remove a compiler warnings; intialized variables.

cbf_uncompressed.c

  added braces to remove a compiler warnings.

cbf_write.c

  added internal functions cbf_get_value_type and cbf_set_value_type for typeofvalue functions; updated magic number and set magic number to match dictionary, not CBFlib version; initialized variable.

cbf.h

  added new external typeofvalue function prototypes; added notices.

cbf_write.h

  added new value_type function prototypes.

cif2cbf.c

  added code to transfer typeofvalue from input to output to fix handling of nulls; increased buffer to 8192 and called it BUFSIZ; changed from tmpnam to mkstemp to remove warning; unlinked temporary file; added braces to remove compiler warnings.

img2cif.c

  added code to transfer typeofvalue from input to output to fix handling of nulls; increased buffer to 8192 and called it BUFSIZ; changed from tmpnam to mkstemp to remove warning; unlinked temporary file; removed unused variables.

------------------------------------------------------------------------

### <span id="0.7.3">Release 0.7.3</span>, Paul J. Ellis, 2 October 2002

Source File

Change

cbf_simple.c

  modified cbf_get_image to reorder the image data on read so that the indices are always increasing in memory (this behavior was undefined previously).

Note: Early versions of Release 0.7.3 carried the version number 0.7.2.3. Other than the change in number on 7 Nov 2002, there is no difference between these versions.

------------------------------------------------------------------------

### <span id="0.7.2.1">Release 0.7.2.1</span>, Paul J. Ellis, 7 May 2001

Source File

Change

cbf_simple.c

  corrected nesting in if statements introduced for the prior mod.

------------------------------------------------------------------------

### <span id="0.7.2">Release 0.7.2</span>, Herbert J. Bernstein, 22 April 2001

Source File

Change

cbf_simple.c

  changed \_diffrn_measurement_axis.id (now deprecated) to \_diffrn_measurement_axis.measurement_id and \_diffrn_detector_axis.id (now deprecated) to \_diffrn_detector_axis.detector_id, but allowed old forms as aliases.

------------------------------------------------------------------------

### <span id="0.7.1">Release 0.7.1</span>, Paul J. Ellis, 30 March 2001

Source File

Change

cbf_simple.c

  add reserved argument to various routines; in cbf_update_pixel use index2 instead of index1; add new routine cbf_get_pixel_normal; in cbf_get_pixel_area, shift by (-0.5,-0.5)  

------------------------------------------------------------------------

### <span id="0.7.1">Release 0.7.1</span>, Paul J. Ellis, 13 March 2001

Source File

Change

cbf.c

  remove unused declaration of little.

cbf.h

  add definitions of CBF_UNDEFINED and CBF_NOTIMPLEMENTED.

cbf_binary.c

  cast type argument to (char) in cbf_copy-string call.

cbf_compress.c

  remove unused declaration of compression_file.

cbf_simple.c

  add this new routine for higher level calls.

cbf_simple.h

  add this new header for higher level calls.

cbf_uncompressed.c

  remove unused declaration of bit.

------------------------------------------------------------------------

### <span id="0.6.1">Release 0.6.1</span>, H. Powell (per Herbert J. Bernstein), 23 February 2001

Source File

Change

cbf.c

  fix memory leak as corrected by H. Powell  

------------------------------------------------------------------------

### <span id="0.6">Release 0.6</span>, Herbert J. Bernstein, 13 January 1999

Source File

Change

cbf.c

  remove argument repeat from cbf_set_integerarray  

cbf.h

  remove argument repeat from cbf_set_integerarray  

cbf_binary.h

  carry compression id in text as argument to cbf_get/set_bintext, remove repeat as argument to cbf_set_binary  

cbf_binary.c

  carry compression id in text, rather than header, as an argument to cbf_get/set_bintext, remove repeat as argument to cbf_set_binary  

cbf_byte_offset.h

  remove argument repeat from cbf_compress_byte_offset  

cbf_byte_offset.c

  remove argument repeat from cbf_compress_byte_offset  

cbf_canonical.

  remove argument repeat from cbf_compress_canonical  

cbf_canonical.c

  remove argument repeat from cbf_compress_canonical  

cbf_compress.h

  remove argument repeat from cbf_compress, change argument compression from pointer to value in cbf_decompress_parameters  

cbf_compress.c

  remove argument repeat from cbf_compress, use compression as an input argument in cbf_decompress_parameters, do not write compression id  

cbf_file.c

  tune buffer size allocations to current size  

cbf_lex.c

  carry compression in text, not header, suppress binary header when there is a MIME header  

cbf_packed.h

  remove argument repeat from cbf_compress_packed  

cbf_packed.c

  remove argument repeat from cbf_compress_packed  

cbf_predictor.h

  remove argument repeat from cbf_compress_predictor  

cbf_predictor.c

  remove argument repeat from cbf_compress_predictor  

cbf_read_binary.h

  make pointer to compression an argument to cbf_parse_binaryheader  

cbf_read_binary.c

  carry compression in text, not header, suppress binary header when there is a MIME header  

cbf_read_mime.h

  add prototype for cbf_nblen  

cbf_read_mime.c

  carry compression in text, not header, suppress binary header when there is a MIME header, allow trailing blanks on header lines, test for early terminations, allow arbitrary spacing on element type, add cbf_nblen  

cbf_stx.c

  rebuilt from cbf.stx with bison 1.25  

cbf_tree.c

  tune allocation of memory for extra children to current use levels  

cbf_uncompressed.h

  remove argument repeat from cbf_compress_none  

cbf_uncompressed.c

  remove argument repeat from cbf_compress_none  

cbf_write.c

  update version numbers in file headers  

cbf_write_binary.c

  carry compression in text, not header, suppress binary header when there is a MIME header, quote X-Binary-Element-Type  

------------------------------------------------------------------------

### <span id="0.5">Release 0.5</span>, Paul J. Ellis, 5 December 1998

Source File

Change

cbf.c

  Add option for immediate digest evaluation (MSG_DIGESTNOW) or deferred digest evaluation (MSG_DIGEST); adjust layout of error messages; remove unused repeat.  

cbf.stx

  Add new argument for cbf_set_columnrow.  

cbf_ascii.c

  Add buffer flush.  

cbf_binary.c

  Add call to cbf_codes.h; convert to use of cbf_get/set_bintext; digests saved in the text for deferred evaluation.  

cbf_byte_offset.c

  Add storedbits argument on compression; remove repeat on decompression.  

cbf_canonical.c

  Stylistic cleanup; add storedbits argument on compression; remove repeat on decompression.  

cbf_codes.c

  Add routines cbf_is_base64digest, cbf_md5digest_to64, flush buffers when done, general cleanup  

cbf_compress.c

  Add argument bits to cbf_compress and each actual compression routine, add bits and remove repeat on decompression.  

cbf_file.c

  Reorganize digest logic; remove nblen argument from cbf_read_line.  

cbf_lex.c

  Argument type and stylisic cleanup; allow for deferred digest evaluation, adjust binary size to agree with MIME size.  

cbf_packed.c

  Stylistic cleanup; add storedbits argument on compression; remove repeat on decompression.  

cbf_predictor.c

  Add storedbits argument on compression; remove repeat on decompression.  

cbf_read_mime.c

  Add binary element type logic; cleanup header scan; allow for deferred digest evaluation.  

cbf_tree.c

  Add argument free to cbf_set_columnrow. If free is true, free the old value, otherwise a user responsibility.  

cbf_uncompressed.c

  Add storedbits argument on compression; remove repeat on decompression.  

cbf_write.c

  Add buffer flush.  

cbf_write_binary.c

  Reorganize digest calculation, adjust binary size by 8, add X-Binary-E;ement-Type.  

global.h

  Change definition of UINT4 from unsigned long int to unsigned int.  

md5.c

  Mask 32 bits for longer words.  

------------------------------------------------------------------------

### <span id="0.4" width="18%">Release 0.4</span>, Herbert J. Bernstein, 15 November 1998

Source File

Change

cbf_stx.c

  rebuilt from cbf.stx with bison 1.25  

cbf_binary.c

  add digest, elsize, elsign to text  

cbf_canonical.c

  remove write of compression id  

cbf_codes.h

  add argument \*digest to cbf_fromqp, cbf_frombase64, cbf_frombasex  

cbf_codes.c

  add mpack notice, add cbf_md5context_to64, add digest to cbf_from...  

cbf_compress.h

  add argument \*digest to cbf_compress  

cbf_compress.c

  add digest to cbf_compress  

cbf_file.h

  add nscolumn, digest_buffer, digest_bpoint, context to cbf_file struct, add argument \*nblen to cbf_read_line  

cbf_file.c

  add file-\>nscolumn, file-\>digest_buffer, file-\>digest_bpoint, update digest when writing  

cbf_lex.c

  add notices, compute digests on intial read  

cbf_packed.c

  do not write compression id  

cbf_read_mime.h

  add prototype for cbf_skip_whitespace, add argument \*compression to cbf_parse_mimeheader  

cbf_read_mime.c

  add notices, remove redundant digest calculation, adjust handling of compression id, add cbf_skip_whitespace, have cbf_parse_mimeheader return compression id, add checks for garbled files, allow more general headers  

cbf_uncompressed.c

  make uncompressed section free of headers  

cbf_write.c

  update version in headers  

cbf_write_binary.c

  carry digest, elsize, elsign in text rather than header  

------------------------------------------------------------------------

### <span id="0.3" width="18%">Release 0.3.1.1</span>, Paul J. Ellis, 21 September 1998

Source File

Change

cbf.h

  remove globals, add tolen CBF_TOKEN_MIME_BIN, change MIME_NOHEADERS to PLAIN_HEADERS, add HDR_DEFAULT, add arguments ciforcbf, headers, encoding to cbf_write_file, add argument headers to cbf_read_file, restore const in several places, merge int cbf_get_integerarrayparams into cbf_get_integerarrayparameters  

cbf.c

   add notices, add argument headers to cbf_read_file to replace use of globals in release 0.2, add arguments ciforcbf, headers, encoding to cbf_write_file to replace use of globals in release 0.2, restore some uses of const, remove integerarrayparams and merge arguments into cbf_get_integerparameters, replace cbf_binary_params with cbf_binary_parameters with extended argument list  

cbf.stx

  add notices, remove gcc use of malloc, define alloca(x) as NULL, and set large inital depth, adopts mods from cbf.stx.y in release 0.2  

cbf_alloc.c

  add notices  

cbf_ascii.c

  change use of range of token values to explicit symbolic tokens  

cbf_binary.h

  merge cbf_binary_params into cbf_binary_parameters, remove cbf_write_binary  

cbf_binary.c

  add cbf_read_mime.h, and CBF_TOKEN_MIME_BIN token, use cbf_set/get_fileposition, merge cbf_binary_params into cbf_binary_parameters, restore some uses of const, use cbf_decompress_parameters with extended argument list, use cbf_mime_temp, move cbf_write_binary to its own file.  

cbf_canonical.h

  add argument binsize to cbf_compress_canonical, add argument repeat to cbf_decompress_canonical  

cbf_canonical.c

  add notices, remove binbitcount, handle binsize as an argument  

cbf_codes.h

  new header  

cbf_codes.c

  revise notices, major cleanup.  

cbf_compress.c

  add notices, add compressedsize argument, add repeat to decompression calls  

cbf_context.c

  add notices  

cbf_compress.h

  add argument compressedsize to cbf_compress, repeat to cbf_decompress  

cbf_file.h

  map "text..." to "buffer..." in cbf_file, remove CBFbytedir, change cbf_set_textsize to cbf_set_buffersize, add cbf_reset_buffer, add cbf_get_buffer, change cbf_get/put_text to cbf_get/put_block, add cbf_get/set_position

cbf_file.c  

  add notices, change file-\>text to file-\>buffer, file-\>text_size to file-\>buffer_size, file-\>text_used to file-\>buffer_used, file-\>read_headers, file-\>write_headers, file-\>write_encoding, remove file-\>fpos, file-\>fend, add cbf_get/set_fileposition  

cbf_lex.c

  read by buffers, move MIME processing later in the flow  

cbf_packed.h  

  add compressedsize argument to cbf-compress-packed, repeat to cbf_decompress_packed, remove ..none, ..byte_off, ..predict  

cbf_packed.c

  add notices, add bitcount argument to cbf_pack_chunk  

cbf_predictor.h

  new header  

cbf_predictor.c

  New routine  

cbf_read_binary.h

  new header  

cbf_read_binary.c

  New routine  

cbf_read_mime.h

  new header  

cbf_string.h

  new header  

cbf_string.c

  New routine, replacing string.c  

cbf_stx.c

  Rebuild of cbf.stx with bison A2.6  

cbf_tree.h

  remove CBF_INDEX, cbf_init_index, cbf_add_index, cleanup, add const  

cbf_tree.c

  add notices, general cleanup, restore const, remove cbf_init_index, cbf_add_index  

cbf_uncompressed.h

  new header  

cbf_uncompressed.c

  New routine  

cbf_write.c

  add notices, change tests for "?" and ".", change range test on tokens to explicit list  

cbf_write_binary.h

  new header  

cbf_write_binary.c

  New routine  

global.h

  new routine with part of md5.h  

md5c.c

  use global.h  

md5.h

  move portion of this header to global.h, from whence it came  

------------------------------------------------------------------------

### <span id="0.2" width="18%">Release 0.2</span>, Herbert J. Bernstein, 27 August 1998

Source File

Change

cbf.h

  Define CBF and CIF, add cbf_force_new_datablock, cbf_force_new_category, remove some uses of const, add, cbf_get_integerarrayparams, add globals CBForCIF, CIFCRterm, CIFNLterm, CBFbinsize, CBFmime, CBFdigest, CBFencoding, CBFelsize, CBFbytedir  

cbf.c

  Define CBF and CIF, add cbf_force_new_datablock, cbf_force_new_category, remove some uses of const, add, cbf_get_integerarrayparams, add globals CBForCIF, CIFCRterm, CIFNLterm, CBFbinsize, CBFmime, CBFdigest, CBFencoding, CBFelsize, CBFbytedir  

cbf.stx

  Add malloc.h when using gcc  

cbf.stx.y

  Version of cbf.stx with changes to allow DDL1  

cbf_ascii.c

  Use symbols for tokens  

cbf_binary.h

  Add cbf_binary_params  

cbf_binary.c

  Add digest logic, change file position tracking  

cbf_canonical.c

  Make writing repeat consistent; track binbitcount add cbf_binary_params, use cbf_decompress_params; allow MIME header  

cbf_codes.c

  New routine adapted from mpack  

cbf_compress.h

  Add cbf_decompress_params  

cbf_compress.c

  Add hooks for CBF_NONE, CBF_BYTE_OFFSET, CBF_PREDICTOR, add cbf_decompress_params  

cbf_context.h

  Remove const from cbf_copy_string  

cbf_context.c

  Remove const from cbf_copy_string  

cbf_decode.c

  New routine adapted from mpack  

cbf_file.h

  Add files to record file position  

cbf_file.c

  Track file position; allow writing CIFs and CBFs  

cbf_lex.c

  Add mime processing; add DDL1 support; process "."  

cbf_mime.c

  New routine  

cbf_packed.h

  Add cbf_compress_none, cbf_decompress_none, cbf_compress_byte_off, cbf_decompress_byte_off, cbf_compress_predict, cbf_decompress_predict  

cbf_packed.c

  Add cbf_compress_none, cbf_decompress_none, dummy cbf_compress_byte_off, dummy cbf_decompress_byte_off, dummy cbf_compress_predict, dummy cbf_decompress_predict; ensure consistent writing of repeat  

cbf_part.h

  New header adapted from mpack  

cbf_part.c

  New routine adapted from pack  

cbf_stx.c

  rebuilt with correct bison parser from cbf.stx.y  

cbf_tree.c

  added cbf_make_new_node, cbf_find_last_child, cbf_name_new_node, cbf_add_new_child, cbf_make_new_child, cbf_init_index, cbf_add_index; report CBF_ARGUMENT for cbf_make_child for type CBF_LINK; removed some uses of const  

cbf_write.c

  Added symbols for parse tokens; recognize "."; adjusted file header line to conform to documentation; removed some uses of const  

cif2cbf.c

  New program  

common.h

  New header from mpack  

img2cif.c

  New program  

makecbf.c

  Add local_exit and change cbf_failnez to facilitate debugging, add \_array_intensities.binary_id, \_array_data.binary.id  

md5.h

  New header from mpack  

md5c.c

  New routine from mpack  

string.c

  New routine from mpack  

uudecode.c

  New routine from mpack  

------------------------------------------------------------------------

### Release 0.1, Paul J. Ellis, 17 April 1998

This was the first CBFlib release. It supported binary CBF files using binary strings.

------------------------------------------------------------------------

------------------------------------------------------------------------

Updated 13 February 2011.

yaya **at** bernstein-plus-sons **dot** com
