
######################################################################
#  CMakeLists.txt - cmake build file for make to create CBFlib       #
#                                                                    #
# Version 0.9.6 06 November 2018                                     #
#                                                                    #
#                          Paul Ellis and                            #
#         Herbert J. Bernstein (yaya@bernstein-plus-sons.com)        #
#                                                                    #
# (C) Copyright 2006 - 2018 Herbert J. Bernstein                     #
#                                                                    #
######################################################################

######################################################################
#                                                                    #
# YOU MAY REDISTRIBUTE THE CBFLIB PACKAGE UNDER THE TERMS OF THE GPL #
#                                                                    #
# ALTERNATIVELY YOU MAY REDISTRIBUTE THE CBFLIB API UNDER THE TERMS  #
# OF THE LGPL                                                        #
#                                                                    #
######################################################################

########################### GPL NOTICES ##############################
#                                                                    #
# This program is free software; you can redistribute it and/or      #
# modify it under the terms of the GNU General Public License as     #
# published by the Free Software Foundation; either version 2 of     #
# (the License, or (at your option) any later version.               #
#                                                                    #
# This program is distributed in the hope that it will be useful,    #
# but WITHOUT ANY WARRANTY; without even the implied warranty of     #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      #
# GNU General Public License for more details.                       #
#                                                                    #
# You should have received a copy of the GNU General Public License  #
# along with this program; if not, write to the Free Software        #
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA           #
# 02111-1307  USA                                                    #
#                                                                    #
######################################################################

######################### LGPL NOTICES ###############################
#                                                                    #
# This library is free software; you can redistribute it and/or      #
# modify it under the terms of the GNU Lesser General Public         #
# License as published by the Free Software Foundation; either       #
# version 2.1 of the License, or (at your option) any later version. #
#                                                                    #
# This library is distributed in the hope that it will be useful,    #
# but WITHOUT ANY WARRANTY; without even the implied warranty of     #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  #
# Lesser General Public License for more details.                    #
#                                                                    #
# You should have received a copy of the GNU Lesser General Public   #
# License along with this library; if not, write to the Free         #
# Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,    #
# MA  02110-1301  USA                                                #
#                                                                    #
######################################################################

######################################################################
#                                                                    #
#                    Stanford University Notices                     #
#  for the CBFlib software package that incorporates SLAC software   #
#                 on which copyright is disclaimed                   #
#                                                                    #
# This software                                                      #
# -------------                                                      #
# The term "this software", as used in these Notices, refers to      #
# those portions of the software package CBFlib that were created by #
# employees of the Stanford Linear Accelerator Center, Stanford      #
# University.                                                        #
#                                                                    #
# Stanford disclaimer of copyright                                   #
# --------------------------------                                   #
# Stanford University, owner of the copyright, hereby disclaims its  #
# copyright and all other rights in this software.  Hence, anyone    #
# may freely use it for any purpose without restriction.             #
#                                                                    #
# Acknowledgement of sponsorship                                     #
# ------------------------------                                     #
# This software was produced by the Stanford Linear Accelerator      #
# Center, Stanford University, under Contract DE-AC03-76SFO0515 with #
# the Department of Energy.                                          #
#                                                                    #
# Government disclaimer of liability                                 #
# ----------------------------------                                 #
# Neither the United States nor the United States Department of      #
# Energy, nor any of their employees, makes any warranty, express or #
# implied, or assumes any legal liability or responsibility for the  #
# accuracy, completeness, or usefulness of any data, apparatus,      #
# product, or process disclosed, or represents that its use would    #
# not infringe privately owned rights.                               #
#                                                                    #
# Stanford disclaimer of liability                                   #
# --------------------------------                                   #
# Stanford University makes no representations or warranties,        #
# express or implied, nor assumes any liability for the use of this  #
# software.                                                          #
#                                                                    #
# Maintenance of notices                                             #
# ----------------------                                             #
# In the interest of clarity regarding the origin and status of this #
# software, this and all the preceding Stanford University notices   #
# are to remain affixed to any copy or derivative of this software   #
# made or distributed by the recipient and are to be affixed to any  #
# copy of software made or distributed by the recipient that         #
# contains a copy or derivative of this software.                    #
#                                                                    #
# Based on SLAC Software Notices, Set 4                              #
# OTT.002a, 2004 FEB 03                                              #
######################################################################



######################################################################
#                               NOTICE                               #
# Creative endeavors depend on the lively exchange of ideas. There   #
# are laws and customs which establish rights and responsibilities   #
# for authors and the users of what authors create.  This notice     #
# is not intended to prevent you from using the software and         #
# documents in this package, but to ensure that there are no         #
# misunderstandings about terms and conditions of such use.          #
#                                                                    #
# Please read the following notice carefully.  If you do not         #
# understand any portion of this notice, please seek appropriate     #
# professional legal advice before making use of the software and    #
# documents included in this software package.  In addition to       #
# whatever other steps you may be obliged to take to respect the     #
# intellectual property rights of the various parties involved, if   #
# you do make use of the software and documents in this package,     #
# please give credit where credit is due by citing this package,     #
# its authors and the URL or other source from which you obtained    #
# it, or equivalent primary references in the literature with the    #
# same authors.                                                      #
#                                                                    #
# Some of the software and documents included within this software   #
# package are the intellectual property of various parties, and      #
# placement in this package does not in any way imply that any       #
# such rights have in any way been waived or diminished.             #
#                                                                    #
# With respect to any software or documents for which a copyright    #
# exists, ALL RIGHTS ARE RESERVED TO THE OWNERS OF SUCH COPYRIGHT.   #
#                                                                    #
# Even though the authors of the various documents and software      #
# found here have made a good faith effort to ensure that the        #
# documents are correct and that the software performs according     #
# to its documentation, and we would greatly appreciate hearing of   #
# any problems you may encounter, the programs and documents any     #
# files created by the programs are provided **AS IS** without any   *
# warranty as to correctness, merchantability or fitness for any     #
# particular or general use.                                         #
#                                                                    #
# THE RESPONSIBILITY FOR ANY ADVERSE CONSEQUENCES FROM THE USE OF    #
# PROGRAMS OR DOCUMENTS OR ANY FILE OR FILES CREATED BY USE OF THE   #
# PROGRAMS OR DOCUMENTS LIES SOLELY WITH THE USERS OF THE PROGRAMS   #
# OR DOCUMENTS OR FILE OR FILES AND NOT WITH AUTHORS OF THE          #
# PROGRAMS OR DOCUMENTS.                                             #
######################################################################

######################################################################
#                                                                    #
#                           The IUCr Policy                          #
#      for the Protection and the Promotion of the STAR File and     #
#     CIF Standards for Exchanging and Archiving Electronic Data     #
#                                                                    #
# Overview                                                           #
#                                                                    #
# The Crystallographic Information File (CIF)[1] is a standard for   #
# information interchange promulgated by the International Union of  #
# Crystallography (IUCr). CIF (Hall, Allen & Brown, 1991) is the     #
# recommended method for submitting publications to Acta             #
# Crystallographica Section C and reports of crystal structure       #
# determinations to other sections of Acta Crystallographica         #
# and many other journals. The syntax of a CIF is a subset of the    #
# more general STAR File[2] format. The CIF and STAR File approaches #
# are used increasingly in the structural sciences for data exchange #
# and archiving, and are having a significant influence on these     #
# activities in other fields.                                        #
#                                                                    #
# Statement of intent                                                #
#                                                                    #
# The IUCr's interest in the STAR File is as a general data          #
# interchange standard for science, and its interest in the CIF,     #
# a conformant derivative of the STAR File, is as a concise data     #
# exchange and archival standard for crystallography and structural  #
# science.                                                           #
#                                                                    #
# Protection of the standards                                        #
#                                                                    #
# To protect the STAR File and the CIF as standards for              #
# interchanging and archiving electronic data, the IUCr, on behalf   #
# of the scientific community,                                       #
#                                                                    #
# # holds the copyrights on the standards themselves,                *
#                                                                    #
# # owns the associated trademarks and service marks, and            *
#                                                                    #
# # holds a patent on the STAR File.                                 *
#                                                                    #
# These intellectual property rights relate solely to the            #
# interchange formats, not to the data contained therein, nor to     #
# the software used in the generation, access or manipulation of     #
# the data.                                                          #
#                                                                    #
# Promotion of the standards                                         #
#                                                                    #
# The sole requirement that the IUCr, in its protective role,        #
# imposes on software purporting to process STAR File or CIF data    #
# is that the following conditions be met prior to sale or           #
# distribution.                                                      #
#                                                                    #
# # Software claiming to read files written to either the STAR       *
# File or the CIF standard must be able to extract the pertinent     #
# data from a file conformant to the STAR File syntax, or the CIF    #
# syntax, respectively.                                              #
#                                                                    #
# # Software claiming to write files in either the STAR File, or     *
# the CIF, standard must produce files that are conformant to the    #
# STAR File syntax, or the CIF syntax, respectively.                 #
#                                                                    #
# # Software claiming to read definitions from a specific data       *
# dictionary approved by the IUCr must be able to extract any        #
# pertinent definition which is conformant to the dictionary         #
# definition language (DDL)[3] associated with that dictionary.      #
#                                                                    #
# The IUCr, through its Committee on CIF Standards, will assist      #
# any developer to verify that software meets these conformance      #
# conditions.                                                        #
#                                                                    #
# Glossary of terms                                                  #
#                                                                    #
# [1] CIF:  is a data file conformant to the file syntax defined     #
# at http://www.iucr.org/iucr-top/cif/spec/index.html                #
#                                                                    #
# [2] STAR File:  is a data file conformant to the file syntax       #
# defined at http://www.iucr.org/iucr-top/cif/spec/star/index.html   #
#                                                                    #
# [3] DDL:  is a language used in a data dictionary to define data   #
# items in terms of "attributes". Dictionaries currently approved    #
# by the IUCr, and the DDL versions used to construct these          #
# dictionaries, are listed at                                        #
# http://www.iucr.org/iucr-top/cif/spec/ddl/index.html               #
#                                                                    #
# Last modified: 30 September 2000                                   #
#                                                                    #
# IUCr Policy Copyright (C) 2000 International Union of              #
# Crystallography                                                    #
######################################################################

######################################################################
#  CMakeLists.txt for CBFlib                                         #
#                                                                    #
#  Assumed directory structure                                       #
#    CBFlib_SOURCE_DIR        CBFlib kit containing this file        #
#      doc                    Directory with documentation           #
#      examples               Directory with example programs        #
#      include                Directory with header files            #
#      m4                     Directory with m4 files                #
#      src                    Directory with source files            #
#                                                                    #
#    CBFlib_BINARY_DIR        CBFlib build directory                 #
#                               usually ${CBFlib_SOURCE_DIR}/build   #
#      external_packages      Directory for HDF5, libtiff, etc.      #
#        hdf5-1.8.11                                                 #
#        tiff-3.9.4-rev-6Feb11                                       #
#        regex-20090805                                              #
#        zlib-1.2.8                                                  #
#      data_files             Directory for test files               #
#      bin                    Directory for executable programs      #
#      include                Directory with build-created headers   #
#      src                    Directory with build-created source    #
#                                                                    #
######################################################################

# find_program()'s REQUIRED option was introduced in CMake 3.18.
cmake_minimum_required(VERSION 3.18)
project(CBFlib
  LANGUAGES C CXX
  VERSION 0.9.8)
set(VERSION_INFO "3:0:1")


# Set timestamps of extracted contents to the time of extraction.
# Resolved by explicitly setting DOWNLOAD_EXTRACT_TIMESTAMP in
# externalproject_add() or fetchcontent_declare(), but the option was
# only introduced in CMake 3.24.
cmake_policy(SET CMP0135 NEW)


# Output directories for static and shared libraries as well as
# binaries.  These appear to be required to on Windows and for running
# h5dump elsewhere.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

set(CBF_F90FLAGS_ENV $ENV{F90FLAGS})
set(CBF_USE_ULP $ENV{CBF_USE_ULP})
set(CBF_M4FLAGS_ENV $ENV{M4FLAGS})

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

option(CBF_ENABLE_FORTRAN "Enable Fortran 90" ON)
if(CBF_ENABLE_FORTRAN)
  include(CheckLanguage)
  check_language(Fortran)
  if(CMAKE_Fortran_COMPILER)
    enable_language(Fortran)
  else()
    message(FATAL_ERROR "Fortran 90 support requested, but no compiler found")
  endif()
endif()
enable_testing()

set (CBF_CMAKE_DEBUG "ON")

if (CBF_USE_ULP STREQUAL "YES")
  set(CMAKE_C_FLAGS "-Wall -g -fno-strict-aliasing -DCBF_USE_ULP")
else (CBF_USE_ULP STREQUAL "YES")
  set(CMAKE_C_FLAGS "-Wall -g -fno-strict-aliasing")
endif (CBF_USE_ULP STREQUAL "YES")

#
#  User setable parameters
#

if (CBF_M4FLAGS_ENV)
  set(CBF_M4FLAGS ${CBF_M4FLAGS_ENV})
else (CBF_M4FLAGS_ENV)
  set(CBF_M4FLAGS "-Dfcb_bytes_in_rec=4096")
endif (CBF_M4FLAGS_ENV)

if(CBF_ENABLE_FORTRAN)

if (CBF_F90FLAGS_ENV)
  set(CMAKE_Fortran_FLAGS_RELEASE "${CMAKE_Fortran_FLAGS_RELEASE} ${CBF_F90FLAGS_ENV}")
  set(CMAKE_Fortran_FLAGS_DEBUG   "${CMAKE_Fortran_FLAGS_DEBUG}   ${CBF_F90FLAGS_ENV}")
else (CBF_F90FLAGS_ENV)
  set(CMAKE_Fortran_FLAGS_RELEASE "${CMAKE_Fortran_FLAGS_RELEASE} -fno-range-check")
  set(CMAKE_Fortran_FLAGS_DEBUG   "${CMAKE_Fortran_FLAGS_DEBUG}   -fno-range-check")
endif (CBF_F90FLAGS_ENV)

endif()

# make sure that the default is a RELEASE
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE RELEASE CACHE STRING
      "Choose the type of build, options are: None Debug Release."
      FORCE)
endif (NOT CMAKE_BUILD_TYPE)


# Check for missing functions: regcomp(3) is in POSIX.1-2001,
# POSIX.1-2008.
include(CheckSymbolExists)
check_symbol_exists(regcomp "regex.h" HAVE_REGCOMP)


#
# Macros
#

#
#  CBF_DEBUG_MESSAGE if CBF_CMAKE_DEBUG issue str
#
macro(CBF_DEBUG_MESSAGE str)
  if(CBF_CMAKE_DEBUG)
    message(STATUS ${str})
  endif(CBF_CMAKE_DEBUG)
endmacro (CBF_DEBUG_MESSAGE)

#
# CBF_REQUIRE_DIRECTORY -- require directory dir
#
macro(CBF_REQUIRE_DIRECTORY dir)
  if (NOT EXISTS "${dir}")
    file(MAKE_DIRECTORY "${dir}")
    CBF_DEBUG_MESSAGE("Created directory ${dir}")
  endif (NOT EXISTS "${dir}")
endmacro(CBF_REQUIRE_DIRECTORY)

#
# Directories
#

#
# Directories on the kit side
#
set(CBF__SRC       "${CBFlib_SOURCE_DIR}/src" )
set(CBF__INCLUDE   "${CBFlib_SOURCE_DIR}/include" )
set(CBF__M4        "${CBFlib_SOURCE_DIR}/m4" )
set(CBF__DOC       "${CBFlib_SOURCE_DIR}/doc" )
set(CBF__EXAMPLES  "${CBFlib_SOURCE_DIR}/examples" )
set(CBF__EXTERNAL_PACKAGES 
                   "${CBFlib_SOURCE_DIR}/external_packages" )
set(CBF__DECTRIS_EXAMPLES
                   "${CBF__EXAMPLES}/dectris_cbf_template_test" )


#
# Directories on the build side
#
set(CBF__BLDSRC    "${CBFlib_BINARY_DIR}/src" )
set(CBF__BLDEXMP   "${CBFlib_BINARY_DIR}/src" )
set(CBF__BIN       "${CBFlib_BINARY_DIR}/bin" )
set(CBF__LIB       "${CBFlib_BINARY_DIR}/lib" )
set(CBF__BIN_INCLUDE "${CBFlib_BINARY_DIR}/include" )
set(CBF__SHARE     "${CBFlib_BINARY_DIR}/share" )
set(CBF__EXT_PKG   "${CBFlib_BINARY_DIR}/external_packages" )
set(CBF__DATA      "${CBFlib_BINARY_DIR}/data_files" )

CBF_REQUIRE_DIRECTORY(${CBF__BLDSRC})
CBF_REQUIRE_DIRECTORY(${CBF__BLDEXMP})
CBF_REQUIRE_DIRECTORY(${CBF__BIN})
CBF_REQUIRE_DIRECTORY(${CBF__LIB})
CBF_REQUIRE_DIRECTORY(${CBF__BIN_INCLUDE})
CBF_REQUIRE_DIRECTORY(${CBF__SHARE})
CBF_REQUIRE_DIRECTORY(${CBF__EXT_PKG})
CBF_REQUIRE_DIRECTORY(${CBF__DATA})


# Under the (Linux) libtool convention, the single-component SOVERSION
# is the difference between the current and age components of
# VERSION_INFO.
string(REPLACE ":" ";" _cra "${VERSION_INFO}")
list(GET _cra 0 _current)
list(GET _cra 2 _age)
math(EXPR SOVERSION "${_current} - ${_age}")


set(JCBF      "${CBFlib_SOURCE_DIR}/jcbf" CACHE STRING "")
set(JAVADIR   "${CBFlib_SOURCE_DIR}/java" CACHE STRING "")
set(BIN       "${CBFlib_BINARY_DIR}/bin" CACHE STRING "")
set(PYCBF     "${CBFlib_SOURCE_DIR}/pycbf" CACHE STRING "")
set(EXAMPLES  "${CBFlib_SOURCE_DIR}/examples" CACHE STRING "" )
set(DECTRIS_EXAMPLES "${EXAMPLES}/dectris_cbf_template_test" CACHE STRING "")
set(MINICBF_TEST "${CBFlib_SOURCE_DIR}/minicbf_test" CACHE STRING "")
set(GRAPHICS  "${CBFlib_SOURCE_DIR}/html_graphics" CACHE STRING "")

if(CBF_DONT_USE_LONG_LONG)
  set(CBF_NOLLFLAG "-DCBF_DONT_USE_LONG_LONG")
else(CBF_DONT_USE_LONG_LONG)
  set(CBF_NOLLFLAG "")
endif(CBF_DONT_USE_LONG_LONG)


#
# URLs from which to retrieve needed external package snapshots
#
include(FetchContent)
find_program(PATCH patch REQUIRED)

fetchcontent_declare(cqrlib
  URL "https://github.com/yayahjb/cqrlib/archive/refs/tags/CQRlib-1.1.4.tar.gz"
  URL_HASH MD5=629a349ed5e8bf6f2a69a2fb1da11c45
  PATCH_COMMAND "${PATCH}"
    -N -i "${CMAKE_CURRENT_SOURCE_DIR}/patches/cqrlib-1.1.4.patch" -p 1 -t)

fetchcontent_declare(hdf5
  URL "http://downloads.sf.net/cbflib/hdf5-1.14.4-2.tar.gz"
  URL_HASH MD5=1791c5f70660bf4ec2e05fc15526c181)

fetchcontent_declare(pcreposix
  URL "http://downloads.sf.net/cbflib/pcre-8.38.tar.gz"
  URL_HASH MD5=8a353fe1450216b6655dfcf3561716d9)

fetchcontent_declare(tiff
  URL "http://downloads.sf.net/cbflib/tiff-4.0.6_rev_3Nov16.tar.gz"
  URL_HASH MD5=594d1811ce715f7d5ec586bf5e0c4732)


#
# libm
set(libm "$<$<NOT:$<C_COMPILER_ID:MSVC>>:m>")


#
# CQRlib
set(CBF_WITH_CQRLIB ON CACHE BOOL
  "Link against internally built CQRlib library")
mark_as_advanced(CBF_WITH_CQRLIB)

if(CBF_WITH_CQRLIB)
  fetchcontent_makeavailable(cqrlib)
else()
  find_library(cqrlib_library CQRlib)
  find_path(cqrlib_include_dir cqrlib.h)

  add_library(CQR UNKNOWN IMPORTED)
  set_target_properties(CQR PROPERTIES
    IMPORTED_LOCATION "${cqrlib_library}"
    INTERFACE_INCLUDE_DIRECTORIES "${cqrlib_include_dir}"
    INTERFACE_LINK_LIBRARIES "${libm}")
endif()


#
# HDF5
#
# See hdf5's root CMakeLists.txt and config/cmake/HDFLibMacros.cmake.
# Set _h5dump_executable to the path to h5dump and _hdf5_target to the
# real (unaliased) HDF5 target.
set(CBF_WITH_HDF5 ON CACHE BOOL
  "Link against internally built HDF5 library")
mark_as_advanced(CBF_WITH_HDF5)

set(HDF5REGISTER "--register" "manual" CACHE INTERNAL
  "Flags to register HDF5 plugins")
mark_as_advanced(HDF5REGISTER)

if(CBF_WITH_HDF5)
  set(BUILD_TESTING OFF CACHE INTERNAL
    "Build HDF5 unit testing")
  set(HDF5_EXTERNALLY_CONFIGURED ON CACHE INTERNAL
    "HDF5 configured externally")
  fetchcontent_makeavailable(hdf5)

  set(_h5dump_executable
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/h5dump${CMAKE_EXECUTABLE_SUFFIX}")
  if(BUILD_SHARED_LIBS)
    set(_hdf5_target hdf5-shared)
  else()
    set(_hdf5_target hdf5-static)
  endif()
else()
  if(NOT BUILD_SHARED_LIBS)
    # HDF5_USE_STATIC_LIBRARIES does not seem to do what it is
    # supposed to, see
    # https://gitlab.kitware.com/cmake/cmake/-/issues/24613.
    set(HDF5_USE_STATIC_LIBRARIES TRUE)
  endif()
  find_package(HDF5 REQUIRED)
  find_program(_h5dump_executable h5dump REQUIRED)
  set(_hdf5_target hdf5::hdf5)
endif()


# The h5dump target already exists with CMake 3.30 and HDF 1.14.4 on
# Windows.
if(NOT TARGET h5dump)
  add_executable(h5dump IMPORTED)
  set_target_properties(h5dump PROPERTIES
    IMPORTED_LOCATION "${_h5dump_executable}")
endif()


# CBFlib must be compiled with H5_USE_110_API.  With MSVC, also need
# H5_BUILT_AS_DYNAMIC_LIB if HDF5 is a dynamic library.
add_library(hdf5 ALIAS ${_hdf5_target})
target_compile_definitions(${_hdf5_target}
  INTERFACE H5_USE_110_API)
if(BUILD_SHARED_LIBS)
  target_compile_definitions(${_hdf5_target}
    INTERFACE H5_BUILT_AS_DYNAMIC_LIB)
endif()


#
# PCRE
#
# Linking against an external PCRE1 library (no longer maintained)
# with a libc that has the regex functions will define regcomp(3),
# regerror(3), regexec(3), and regfree(3) twice: do not set
# CBF_WITH_PCRE if libc has the regexec functions.  PCRE2 does it
# differently: it defines the regex functions prefixed with pcre2_ and
# maps them onto the unprefixed names with preprocessor directives.
set(CBF_WITH_PCRE OFF CACHE BOOL
  "Link against internally built Perl-compatible regular expressions library")
mark_as_advanced(CBF_WITH_PCRE)

if(CBF_WITH_PCRE)
  # Do not try to link pcretest against readline, because the PCRE
  # build system does not catch the libtinfo dependency (for tputs and
  # friends).  Note that PCRE-8.38 is not using GNUInstallDirs; later
  # versions may.
  #
  # PCRE 8.38 reads the DEBUG_LOCATION property of the pcregrep and
  # pcretest targets--disable both targets.
  set(PCRE_BUILD_PCREGREP OFF CACHE INTERNAL "Bulid pcregrep")
  set(PCRE_BUILD_TESTS OFF CACHE INTERNAL "Build the tests")
  fetchcontent_makeavailable(pcreposix)


  # Always use the pcreposix.h from ${pcreposix_SOURCE_DIR} rather
  # than a system-supplied header.
  target_include_directories(pcreposix BEFORE PUBLIC "${pcreposix_SOURCE_DIR}")

elseif(HAVE_REGCOMP)
  add_library(pcreposix INTERFACE IMPORTED)
  target_compile_definitions(pcreposix
    INTERFACE CBF_REGEXLIB_REGEX)

else()
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(pcreposix REQUIRED IMPORTED_TARGET libpcreposix)
  add_library(pcreposix ALIAS PkgConfig::pcreposix)
endif()


#
# TIFF
#
# LibTIFF to support tiff2cbf.  Disable tests if building in-tree; the
# tiff-tests cache variable was introduced in LibTIFF 4.5.0.
set(CBF_WITH_LIBTIFF ON CACHE BOOL
  "Link against internally built LibTIFF library")
mark_as_advanced(CBF_WITH_LIBTIFF)

if(CBF_WITH_LIBTIFF)
  # The first LibTIFF at https://gitlab.com/libtiff/libtiff with
  # native CMake support seems to be 4.0.5.  The first version that
  # builds on current MSYS2 is 4.0.9.
  #
  # 4.0.3-rev-29Sep13 appears to have CMakeLists.txt patched in but
  # fails on MSYS2: multiple definition of ua_wcsicmp.
  set(tiff-contrib OFF CACHE INTERNAL "Build TIFF contrib")
  set(tiff-docs OFF CACHE INTERNAL "Build TIFF documentation")
  set(tiff-tests OFF CACHE INTERNAL "Build TIFF tests")
  set(tiff-tools OFF CACHE INTERNAL "Build TIFF tools")
  fetchcontent_makeavailable(tiff)
else()
  # find_package(TIFF) appears to miss the dependencies (Lerc, jbig,
  # etc) for a static LibTIFF.  pkg_check_modules(... IMPORTED_TARGET
  # libtiff-4) on the other hand always seems to create a
  # shared-library target; see
  # https://gitlab.kitware.com/cmake/cmake/-/issues/21714.
  #
  # Use pkg-config, with the intent of eventually switching to
  # cmake_pkg_config(), because e.g. Debian does not ship CMake config
  # files in their dev packages.
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(tiff REQUIRED IMPORTED_TARGET libtiff-4)
  add_library(tiff ALIAS PkgConfig::tiff)
endif()


#
# Data Directories
#
# Verify the checksums.  The --binary option appears to be required
# for patching the test data on MSYS2.
fetchcontent_declare(data_input
  URL "http://downloads.sf.net/cbflib/CBFlib_${PROJECT_VERSION}_Data_Files_Input.tar.gz"
  URL_HASH MD5=f98ae4214b3e57acb42437ea4b685c4d)

fetchcontent_declare(data_output
  URL "http://downloads.sf.net/cbflib/CBFlib_${PROJECT_VERSION}_Data_Files_Output.tar.gz"
  URL_HASH MD5=edde13b20baf16bb9ab91cfc647ba4d6
  PATCH_COMMAND "${PATCH}"
    -N -i "${CMAKE_CURRENT_SOURCE_DIR}/patches/cbflib-data-output-${PROJECT_VERSION}.patch" -p 1 -t --binary)


#
# INPUT/OUTPUT TEST DATA
#
# If CBF_DATA_INPUT and/or CBF_DATA_OUTPUT are set externally, the
# test data in the corresponding directories are assumed to be
# patched.
set(CBF_DATA_INPUT "" CACHE FILEPATH
  "Path to input test data directory")
mark_as_advanced(CBF_DATA_INPUT)

if(NOT CBF_DATA_INPUT)
  fetchcontent_makeavailable(data_input)
  set(CBF_DATA_INPUT "${data_input_SOURCE_DIR}")
endif()

set(CBF_DATA_OUTPUT "" CACHE FILEPATH
  "Path to reference output test data directory")
mark_as_advanced(CBF_DATA_OUTPUT)

if(NOT CBF_DATA_OUTPUT)
  fetchcontent_makeavailable(data_output)
  set(CBF_DATA_OUTPUT "${data_output_SOURCE_DIR}")
endif()


#
# Source files
#
set(
	CBF_C_SOURCES
    ${CBF__SRC}/cbf.c
    ${CBF__SRC}/cbf_alloc.c
    ${CBF__SRC}/cbf_ascii.c
    ${CBF__SRC}/cbf_binary.c
    ${CBF__SRC}/cbf_byte_offset.c
    ${CBF__SRC}/cbf_canonical.c
    ${CBF__SRC}/cbf_codes.c
    ${CBF__SRC}/cbf_compress.c
    ${CBF__SRC}/cbf_context.c
    ${CBF__SRC}/cbf_copy.c
    ${CBF__SRC}/cbf_file.c
    ${CBF__SRC}/cbf_getopt.c
    ${CBF__SRC}/cbf_hdf5.c
    ${CBF__SRC}/cbf_hdf5_filter.c
    ${CBF__SRC}/cbf_lex.c
    ${CBF__SRC}/cbf_minicbf_header.c
    ${CBF__SRC}/cbf_nibble_offset.c
    ${CBF__SRC}/cbf_packed.c
    ${CBF__SRC}/cbf_predictor.c
    ${CBF__SRC}/cbf_read_binary.c
    ${CBF__SRC}/cbf_read_mime.c
    ${CBF__SRC}/cbf_simple.c
    ${CBF__SRC}/cbf_string.c
    ${CBF__SRC}/cbf_stx.c
    ${CBF__SRC}/cbf_tree.c
    ${CBF__SRC}/cbf_uncompressed.c
    ${CBF__SRC}/cbf_ulp.c
    ${CBF__SRC}/cbf_write.c
    ${CBF__SRC}/cbf_write_binary.c
    ${CBF__SRC}/cbf_ws.c
	${CBF__SRC}/md5c.c
    ${CBF__SRC}/img.c
)

if(CBF_ENABLE_FORTRAN)

set(
	CBF_F90_BUILT_SOURCES 
			${CBF__BLDSRC}/fcb_exit_binary.f90
			${CBF__BLDSRC}/fcb_next_binary.f90
			${CBF__BLDSRC}/fcb_open_cifin.f90
			${CBF__BLDSRC}/fcb_packed.f90
			${CBF__BLDSRC}/fcb_read_bits.f90
			${CBF__BLDSRC}/fcb_read_image.f90
	${CBF__BLDSRC}/fcb_read_xds_i2.f90
)
            
set(
	CBF_F90_SOURCES
	${CBF__SRC}/fcb_atol_wcnt.f90
			${CBF__SRC}/fcb_ci_strncmparr.f90
			${CBF__SRC}/fcb_nblen_array.f90
			${CBF__SRC}/fcb_read_byte.f90
			${CBF__SRC}/fcb_read_line.f90
	${CBF__SRC}/fcb_skip_whitespace.f90
)

endif()

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# the RPATH to be used when installing, but only if it's not a system directory
LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
IF("${isSystemDir}" STREQUAL "-1")
   SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" )
ENDIF("${isSystemDir}" STREQUAL "-1")

			
#
# Header files
#
set(
	CBF_HEADERS
	${CBF__INCLUDE}/cbf.h			
    ${CBF__INCLUDE}/cbf_alloc.h
    ${CBF__INCLUDE}/cbf_ascii.h
    ${CBF__INCLUDE}/cbf_binary.h		
    ${CBF__INCLUDE}/cbf_byte_offset.h
    ${CBF__INCLUDE}/cbf_canonical.h
    ${CBF__INCLUDE}/cbf_codes.h
    ${CBF__INCLUDE}/cbf_compress.h		
    ${CBF__INCLUDE}/cbf_context.h		
    ${CBF__INCLUDE}/cbf_copy.h			
    ${CBF__INCLUDE}/cbf_file.h			
    ${CBF__INCLUDE}/cbf_getopt.h		
    ${CBF__INCLUDE}/cbf_hdf5.h			
    ${CBF__INCLUDE}/cbf_hdf5_filter.h
    ${CBF__INCLUDE}/cbf_lex.h			
    ${CBF__INCLUDE}/cbf_minicbf_header.h
    ${CBF__INCLUDE}/cbf_nibble_offset.h
    ${CBF__INCLUDE}/cbf_packed.h		
    ${CBF__INCLUDE}/cbf_predictor.h
    ${CBF__INCLUDE}/cbf_read_binary.h
    ${CBF__INCLUDE}/cbf_read_mime.h		
    ${CBF__INCLUDE}/cbf_simple.h		
    ${CBF__INCLUDE}/cbf_string.h		
    ${CBF__INCLUDE}/cbf_stx.h
    ${CBF__INCLUDE}/cbf_tree.h
    ${CBF__INCLUDE}/cbf_uncompressed.h
    ${CBF__INCLUDE}/cbf_ulp.h
    ${CBF__INCLUDE}/cbf_write.h
    ${CBF__INCLUDE}/cbf_write_binary.h
    ${CBF__INCLUDE}/cbf_ws.h
    ${CBF__INCLUDE}/global.h
    ${CBF__INCLUDE}/cbff.h			
	${CBF__INCLUDE}/md5.h
    ${CBF__INCLUDE}/img.h
)


if(CBF_ENABLE_FORTRAN)

#
# m4 FCB library macro files
#
set(
	CBF_M4_FCB_DEFINES
	${CBF__M4}/fcblib_defines.m4
)

set(
	CBF_M4_FCB_FILES 
			${CBF__M4}/fcb_exit_binary.m4
			${CBF__M4}/fcb_next_binary.m4
			${CBF__M4}/fcb_open_cifin.m4
			${CBF__M4}/fcb_packed.m4
			${CBF__M4}/fcb_read_bits.m4
			${CBF__M4}/fcb_read_image.m4
	${CBF__M4}/fcb_read_xds_i2.m4
)
#
# m4 F90 examples macro files
#
set(
	CBF_M4_F90_EXAMPLES
            ${CBF__M4}/test_fcb_read_image.m4
	${CBF__M4}/test_xds_binary.m4
)

endif()


#
# Documentation files
#
set(
	CBF_DOCUMENTS
	${CBF__DOC}/CBFlib.html
			${CBF__DOC}/CBFlib.txt
			${CBF__DOC}/CBFlib_NOTICES.html
			${CBF__DOC}/CBFlib_NOTICES.txt
            ${CBF__DOC}/ChangeLog
			${CBF__DOC}/ChangeLog.html
			${CBF__DOC}/MANIFEST
			${CBF__DOC}/gpl.txt $(DOC)/lgpl.txt
	CACHE STRING ""
)

#
# HTML Graphics files
#
set(
	JPEGS
	${GRAPHICS}/CBFbackground.jpg
			${GRAPHICS}/CBFbig.jpg
			${GRAPHICS}/CBFbutton.jpg
			${GRAPHICS}/cbflibbackground.jpg
            ${GRAPHICS}/cbflibbig.jpg
			${GRAPHICS}/cbflibbutton.jpg
			${GRAPHICS}/cifhome.jpg
            ${GRAPHICS}/iucrhome.jpg
			${GRAPHICS}/noticeButton.jpg
	CACHE STRING ""
)

# Set up the necessary includes

include_directories(BEFORE SYSTEM
  ${CBFlib_SOURCE_DIR}/include)


#
# Build the static and shared CBF libraries
#
# Note that HDF5 is a PUBLIC dependency of CBFlib, because cbf_hdf5.h
# includes hdf5.h.
add_library(cbf ${CBF_C_SOURCES})
set_target_properties(cbf PROPERTIES OUTPUT_NAME "cbf")
set_target_properties(cbf PROPERTIES LINKER_LANGUAGE C)
set_target_properties(cbf PROPERTIES SOVERSION "${SOVERSION}")
target_link_libraries(cbf
  PUBLIC hdf5
  PRIVATE pcreposix
  PRIVATE ${libm})


#
# Build the static and shared IMG libraries
#
add_library(img "${CBF__SRC}/img.c")
set_target_properties(img PROPERTIES OUTPUT_NAME "img")
set_target_properties(img PROPERTIES LINKER_LANGUAGE C)


if(CBF_ENABLE_FORTRAN)

#
# Build the f90 library sources
#
find_program(M4 m4)
foreach(f90src IN LISTS CBF_F90_BUILT_SOURCES)
  get_filename_component(filename "${f90src}" NAME_WE )
  set(f90bldsrc "${CBF__BLDSRC}/${filename}.f90")
  set(f90srcm4 "${CBF__M4}/${filename}.m4")
	add_custom_command(
		OUTPUT "${f90bldsrc}"
    WORKING_DIRECTORY "${CBF__M4}"
    COMMAND ${M4} -P "${CBF_M4FLAGS}" "${f90srcm4}" > "${f90bldsrc}"
    DEPENDS ${CBF_M4_FCB_DEFINES} ${f90srcm4}
		COMMENT "Generating ${f90bldsrc}"
	)
endforeach(f90src)


#
# Build the fcb libraries
#
add_library(fcb ${CBF_F90_BUILT_SOURCES};${CBF_F90_SOURCES})
set_target_properties(fcb PROPERTIES OUTPUT_NAME "fcb")
set_target_properties(fcb PROPERTIES LINKER_LANGUAGE C)
endif()


#
#  C and C++ examples
#
add_executable(tiff2cbf
  "${CBF__EXAMPLES}/tif_sprint.c"
  "${CBF__EXAMPLES}/tiff2cbf.c")
target_link_libraries(tiff2cbf
  cbf
  tiff)

add_executable(cbf2nexus
  "${CBF__EXAMPLES}/cbf2nexus.c")
target_link_libraries(cbf2nexus
  cbf)

add_executable(nexus2cbf
  "${CBF__EXAMPLES}/nexus2cbf.c")
target_link_libraries(nexus2cbf
  cbf
  hdf5)

add_executable(minicbf2nexus
  "${CBF__EXAMPLES}/minicbf2nexus.c")
target_link_libraries(minicbf2nexus
  cbf)

add_executable(adscimg2cbf
  "${CBF__EXAMPLES}/adscimg2cbf.c"
  "${CBF__EXAMPLES}/adscimg2cbf_sub.c")
target_link_libraries(adscimg2cbf
  cbf
  "${libm}")

add_executable(cbf2adscimg
  "${CBF__EXAMPLES}/cbf2adscimg.c"
  "${CBF__EXAMPLES}/cbf2adscimg_sub.c")
target_link_libraries(cbf2adscimg
  cbf
  "${libm}")

add_executable(convert_image
  "${CBF__EXAMPLES}/convert_image.c")
target_link_libraries(convert_image
  cbf)

add_executable(convert_minicbf
  "${CBF__EXAMPLES}/convert_minicbf.c")
target_link_libraries(convert_minicbf
  cbf)

add_executable(makecbf
  "${CBF__EXAMPLES}/makecbf.c")
target_link_libraries(makecbf
  cbf)

add_executable(cbf_tail
  "${CBF__EXAMPLES}/cbf_tail.c")
target_link_libraries(cbf_tail
  cbf)

add_executable(changtestcompression
  "${CBF__EXAMPLES}/changtestcompression.c")
target_link_libraries(changtestcompression
  cbf)

add_executable(img2cif
  "${CBF__EXAMPLES}/img2cif.c")
target_link_libraries(img2cif
  cbf)

add_executable(cif2cbf
  "${CBF__EXAMPLES}/cif2cbf.c")
target_link_libraries(cif2cbf
  cbf
  CQR
  "${libm}")

add_executable(cbf_template_t
  "${CBF__DECTRIS_EXAMPLES}/cbf_template_t.c")
target_link_libraries(cbf_template_t
  cbf)

add_executable(testcell
  "${CBF__EXAMPLES}/testcell.C")
target_link_libraries(testcell
  cbf)

add_executable(sauter_test
  "${CBF__EXAMPLES}/sauter_test.C")
target_link_libraries(sauter_test
  cbf)

add_executable(sequence_match
  "${CBF__EXAMPLES}/sequence_match.c")
target_link_libraries(sequence_match
  cbf)

add_executable(testulp
  "${CBF__EXAMPLES}/testulp.c")
target_link_libraries(testulp
  cbf)

add_executable(testhdf5
  "${CBF__EXAMPLES}/testhdf5.c")
target_link_libraries(testhdf5
  cbf)

add_executable(testtree
  "${CBF__EXAMPLES}/testtree.c")
target_link_libraries(testtree
  cbf)

add_executable(testalloc
  "${CBF__EXAMPLES}/testalloc.c")
target_link_libraries(testalloc
  cbf)

add_executable(testflat
  "${CBF__EXAMPLES}/testflat.c")
target_link_libraries(testflat
  cbf)

add_executable(testflatpacked
  "${CBF__EXAMPLES}/testflatpacked.c")
target_link_libraries(testflatpacked
  cbf)

add_executable(testreals
  "${CBF__EXAMPLES}/testreals.c")
target_link_libraries(testreals
  cbf)


#
#  F90 examples
#
if(CBF_ENABLE_FORTRAN)
  add_custom_command(OUTPUT "${CBF__BLDEXMP}/test_fcb_read_image.f90"
    WORKING_DIRECTORY "${CBF__M4}"
    COMMAND ${M4} -P "${CBF_M4FLAGS}" "${CBF__M4}/test_fcb_read_image.m4" > "${CBF__BLDEXMP}/test_fcb_read_image.f90"
    DEPENDS ${CBF_M4_FCB_DEFINES} "${CBF__M4}/test_fcb_read_image.m4"
    COMMENT "Generating ${test_fcb_read_image.f90}")
  add_custom_command(OUTPUT "${CBF__BLDEXMP}/test_xds_binary.f90"
    WORKING_DIRECTORY "${CBF__M4}"
    COMMAND ${M4} -P "${CBF_M4FLAGS}" "${CBF__M4}/test_xds_binary.m4" > "${CBF__BLDEXMP}/test_xds_binary.f90"
    DEPENDS ${CBF_M4_FCB_DEFINES} "${CBF__M4}/test_xds_binary.m4"
    COMMENT "Generating ${test_xds_binary.f90}")

  add_executable(test_fcb_read_image
    "${CBF__BLDEXMP}/test_fcb_read_image.f90")
  target_link_libraries(test_fcb_read_image
    fcb
    hdf5)

  add_executable(test_xds_binary
    "${CBF__BLDEXMP}/test_xds_binary.f90")
  target_link_libraries(test_xds_binary
    fcb
    hdf5)
endif()


#
# install
#
install (TARGETS makecbf DESTINATION bin)
install (TARGETS img2cif DESTINATION bin)
install (TARGETS cif2cbf DESTINATION bin)
install (TARGETS adscimg2cbf DESTINATION bin)
install (TARGETS cbf2adscimg DESTINATION bin)
install (TARGETS changtestcompression DESTINATION bin)
install (TARGETS convert_image DESTINATION bin)
install (TARGETS convert_minicbf DESTINATION bin)
install (TARGETS minicbf2nexus DESTINATION bin)
install (TARGETS cbf2nexus DESTINATION bin)
install (TARGETS nexus2cbf DESTINATION bin)
install (TARGETS cbf_template_t DESTINATION bin)
install (TARGETS testcell DESTINATION bin)
install (TARGETS sauter_test DESTINATION bin)
install (TARGETS sequence_match DESTINATION bin)
install (TARGETS tiff2cbf DESTINATION bin)
install(TARGETS cbf DESTINATION lib)

if(CBF_ENABLE_FORTRAN)
  install(TARGETS fcb DESTINATION lib)
endif()

install(TARGETS img DESTINATION lib)
install (DIRECTORY ${CBF__INCLUDE}/ DESTINATION include/cbflib FILES_MATCHING PATTERN "*.h")
install (DIRECTORY ${CBF__BIN_INCLUDE}/* DESTINATION include/cbflib FILES_MATCHING PATTERN "*.h")

# message(STATUS "CMAKE_INSTALL_PREFIX/lib ${CMAKE_INSTALL_PREFIX}/lib")

# path to the valgrind executable
set(VALGRIND_COMMAND "")
find_program(VALGRIND valgrind)
if (VALGRIND)
	CBF_DEBUG_MESSAGE("valgrind found at ${VALGRIND}")
	set(VALGRIND_COMMAND ${VALGRIND} --error-exitcode=3 --leak-check=full)
else ()
	CBF_DEBUG_MESSAGE("valgrind could not be not found")
endif ()

#
# tests  -- to be extended
#

# Set up a wrapper to call 'h5dump' and redirect its output to a file.
file(GENERATE
  OUTPUT "h5dump-$<CONFIG>.cmake"
  INPUT "h5dump.cmake")


# core tests

add_test(makecbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/makecbf "${CBF_DATA_INPUT}/example.mar2300" ${CBF__DATA}/makecbf.cbf)

# $(BIN)/img2cif -c flatpacked -m headers -d digest -e base64 example.mar2300 img2cif_packed.cif
add_test(img2cif_packed.cif ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/img2cif -c flatpacked -m headers -d digest -e base64 "${CBF_DATA_INPUT}/example.mar2300" ${CBF__DATA}/img2cif_packed.cif)

# $(BIN)/img2cif -c canonical -m headers -d digest -e base64 example.mar2300 img2cif_canonical.cif
add_test(img2cif_canonical.cif ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/img2cif -c canonical -m headers -d digest -e base64 "${CBF_DATA_INPUT}/example.mar2300" ${CBF__DATA}/img2cif_canonical.cif)

# $(BIN)/img2cif -c flatpacked -m headers -d digest -e none example.mar2300 img2cif_packed.cbf
add_test(img2cif_packed.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/img2cif -c flatpacked -m headers -d digest -e none "${CBF_DATA_INPUT}/example.mar2300" ${CBF__DATA}/img2cif_packed.cbf)

# $(BIN)/img2cif -c canonical -m headers -d digest -e none example.mar2300 img2cif_canonical.cbf
add_test(img2cif_canonical.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/img2cif -c canonical -m headers -d digest -e none "${CBF_DATA_INPUT}/example.mar2300" ${CBF__DATA}/img2cif_canonical.cbf)

# $(BIN)/cif2cbf -e none -c flatpacked img2cif_canonical.cif cif2cbf_packed.cbf
add_test(cif2cbf_packed.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -e none -c flatpacked ${CBF__DATA}/img2cif_canonical.cif ${CBF__DATA}/cif2cbf_packed.cbf)
set_property(TEST cif2cbf_packed.cbf APPEND PROPERTY DEPENDS img2cif_canonical.cif)

# $(BIN)/cif2cbf -e none -c canonical img2cif_packed.cif cif2cbf_canonical.cbf
add_test(cif2cbf_canonical.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -e none -c canonical ${CBF__DATA}/img2cif_packed.cif ${CBF__DATA}/cif2cbf_canonical.cbf)
set_property(TEST cif2cbf_canonical.cbf APPEND PROPERTY DEPENDS img2cif_packed.cif)

# -cmp cif2cbf_packed.cbf makecbf.cbf
add_test(cmp-cif2cbf_packed.cbf-makecbf.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/cif2cbf_packed.cbf ${CBF__DATA}/makecbf.cbf)
set_property(TEST cmp-cif2cbf_packed.cbf-makecbf.cbf APPEND PROPERTY DEPENDS cif2cbf_packed.cbf)
set_property(TEST cmp-cif2cbf_packed.cbf-makecbf.cbf APPEND PROPERTY DEPENDS makecbf)

# -cmp cif2cbf_packed.cbf img2cif_packed.cbf
add_test(cmp-cif2cbf_packed.cbf-img2cif_packed.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/cif2cbf_packed.cbf ${CBF__DATA}/img2cif_packed.cbf)
set_property(TEST cmp-cif2cbf_packed.cbf-img2cif_packed.cbf APPEND PROPERTY DEPENDS cif2cbf_packed.cbf)
set_property(TEST cmp-cif2cbf_packed.cbf-img2cif_packed.cbf APPEND PROPERTY DEPENDS img2cif_packed.cbf)

# -cmp cif2cbf_canonical.cbf img2cif_canonical.cbf
add_test(cmp-cif2cbf_canonical.cbf-img2cif_canonical.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/cif2cbf_canonical.cbf ${CBF__DATA}/img2cif_canonical.cbf)
set_property(TEST cmp-cif2cbf_canonical.cbf-img2cif_canonical.cbf APPEND PROPERTY DEPENDS cif2cbf_canonical.cbf)
set_property(TEST cmp-cif2cbf_canonical.cbf-img2cif_canonical.cbf APPEND PROPERTY DEPENDS img2cif_canonical.cbf)

# $(BIN)/cif2cbf -e hex -c none makecbf.cbf cif2cbf_ehcn.cif
add_test(cif2cbf_ehcn.cif ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -e hex -c none ${CBF__DATA}/makecbf.cbf ${CBF__DATA}/cif2cbf_ehcn.cif)
set_property(TEST cif2cbf_ehcn.cif APPEND PROPERTY DEPENDS makecbf)

# $(BIN)/cif2cbf -e none -c flatpacked cif2cbf_ehcn.cif cif2cbf_encp.cbf
add_test(cif2cbf_encp.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -e none -c flatpacked ${CBF__DATA}/cif2cbf_ehcn.cif ${CBF__DATA}/cif2cbf_encp.cbf)
set_property(TEST cif2cbf_encp.cbf APPEND PROPERTY DEPENDS cif2cbf_ehcn.cif)

#-cmp makecbf.cbf cif2cbf_encp.cbf
add_test(cmp-makecbf.cbf-cif2cbf_encp.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/makecbf.cbf ${CBF__DATA}/cif2cbf_encp.cbf)
set_property(TEST cmp-makecbf.cbf-cif2cbf_encp.cbf APPEND PROPERTY DEPENDS makecbf)
set_property(TEST cmp-makecbf.cbf-cif2cbf_encp.cbf APPEND PROPERTY DEPENDS cif2cbf_encp.cbf)

# $(BIN)/cif2cbf -i 9ins.cif -o 9ins.cbf
add_test(9ins.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -i "${CBF_DATA_INPUT}/9ins.cif" -o ${CBF__DATA}/9ins.cbf)

# -cmp 9ins.cif 9ins.cbf
add_test(cmp-9ins.cif-9ins.cbf ${CMAKE_COMMAND} -E compare_files "${CBF_DATA_INPUT}/9ins.cif" ${CBF__DATA}/9ins.cbf)
set_property(TEST cmp-9ins.cif-9ins.cbf APPEND PROPERTY DEPENDS 9ins.cbf)

# $(BIN)/convert_image -F example.mar2300 converted_flat.cbf
add_test(
	converted_flat.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/convert_image
	-F -p ${CBFlib_SOURCE_DIR}/templates/template_mar345_2300x2300.cbf
	"${CBF_DATA_INPUT}/example.mar2300"
	${CBF__DATA}/converted_flat.cbf
)

# -cmp converted_flat_orig.cbf converted_flat.cbf
add_test(cmp-converted_flat_orig.cbf-converted_flat.cbf ${CMAKE_COMMAND} -E compare_files "${CBF_DATA_OUTPUT}/converted_flat_orig.cbf" ${CBF__DATA}/converted_flat.cbf)
set_property(TEST cmp-converted_flat_orig.cbf-converted_flat.cbf APPEND PROPERTY DEPENDS converted_flat.cbf)

# $(BIN)/convert_image example.mar2300 converted.cbf
add_test(converted.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/convert_image -p ${CBFlib_SOURCE_DIR}/templates/template_mar345_2300x2300.cbf "${CBF_DATA_INPUT}/example.mar2300" ${CBF__DATA}/converted.cbf)

# -cmp converted_orig.cbf converted.cbf
add_test(cmp-converted_orig.cbf-converted.cbf ${CMAKE_COMMAND} -E compare_files "${CBF_DATA_OUTPUT}/converted_orig.cbf" ${CBF__DATA}/converted.cbf)
set_property(TEST cmp-converted_orig.cbf-converted.cbf APPEND PROPERTY DEPENDS converted.cbf)

# copy a file into another directory so that test input data is not modified
add_test(mb_LP_1_001.img ${CMAKE_COMMAND} -E copy "${CBF_DATA_INPUT}/mb_LP_1_001.img" ${CBF__DATA}/mb_LP_1_001.img)

# $(BIN)/convert_image -F -d adscquantum315 mb_LP_1_001.img adscconverted_flat.cbf
add_test(
	adscconverted_flat.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/convert_image
	-F -p ${CBFlib_SOURCE_DIR}/templates/template_adscquantum315_3072x3072.cbf
	-d adscquantum315
	${CBF__DATA}/mb_LP_1_001.img
	${CBF__DATA}/adscconverted_flat.cbf
)
set_property(TEST adscconverted_flat.cbf APPEND PROPERTY DEPENDS mb_LP_1_001.img)

# -cmp adscconverted_flat_orig.cbf adscconverted_flat.cbf
add_test(cmp-adscconverted_flat_orig.cbf-adscconverted_flat.cbf ${CMAKE_COMMAND} -E compare_files "${CBF_DATA_OUTPUT}/adscconverted_flat_orig.cbf" ${CBF__DATA}/adscconverted_flat.cbf)
set_property(TEST cmp-adscconverted_flat_orig.cbf-adscconverted_flat.cbf APPEND PROPERTY DEPENDS adscconverted_flat.cbf)

# $(BIN)/convert_image -d adscquantum315 mb_LP_1_001.img adscconverted.cbf
add_test(
	adscconverted.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/convert_image
	-p ${CBFlib_SOURCE_DIR}/templates/template_adscquantum315_3072x3072.cbf
	-d adscquantum315
	${CBF__DATA}/mb_LP_1_001.img
	${CBF__DATA}/adscconverted.cbf
)
set_property(TEST adscconverted.cbf APPEND PROPERTY DEPENDS mb_LP_1_001.img)

# -cmp adscconverted_orig.cbf adscconverted.cbf
add_test(cmp-adscconverted_orig.cbf-adscconverted.cbf ${CMAKE_COMMAND} -E compare_files "${CBF_DATA_OUTPUT}/adscconverted_orig.cbf" ${CBF__DATA}/adscconverted.cbf)
set_property(TEST cmp-adscconverted_orig.cbf-adscconverted.cbf APPEND PROPERTY DEPENDS adscconverted.cbf)

# $(BIN)/adscimg2cbf --no_pad --cbf_packed,flat mb_LP_1_001.img
add_test(mb_LP_1_001.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/adscimg2cbf --no_pad --cbf_packed,flat ${CBF__DATA}/mb_LP_1_001.img)
set_property(TEST mb_LP_1_001.cbf APPEND PROPERTY DEPENDS mb_LP_1_001.img)

# -cmp mb_LP_1_001_orig.cbf mb_LP_1_001.cbf
add_test(cmp-mb_LP_1_001_orig.cbf-mb_LP_1_001.cbf ${CMAKE_COMMAND} -E compare_files "${CBF_DATA_OUTPUT}/mb_LP_1_001_orig.cbf" ${CBF__DATA}/mb_LP_1_001.cbf)
set_property(TEST cmp-mb_LP_1_001_orig.cbf-mb_LP_1_001.cbf APPEND PROPERTY DEPENDS mb_LP_1_001.cbf)

# cp mb_LP_1_001.cbf nmb_LP_1_001.cbf
add_test(nmb_LP_1_001.cbf ${CMAKE_COMMAND} -E copy ${CBF__DATA}/mb_LP_1_001.cbf ${CBF__DATA}/nmb_LP_1_001.cbf)
set_property(TEST nmb_LP_1_001.cbf APPEND PROPERTY DEPENDS mb_LP_1_001.cbf)

# $(BIN)/cbf2adscimg nmb_LP_1_001.cbf
add_test(nmb_LP_1_001.img ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cbf2adscimg ${CBF__DATA}/nmb_LP_1_001.cbf)
set_property(TEST nmb_LP_1_001.img APPEND PROPERTY DEPENDS nmb_LP_1_001.cbf)

# -cmp mb_LP_1_001.img nmb_LP_1_001.img
add_test(cmp-mb_LP_1_001.img-nmb_LP_1_001.img ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/mb_LP_1_001.img ${CBF__DATA}/nmb_LP_1_001.img)
set_property(TEST cmp-mb_LP_1_001.img-nmb_LP_1_001.img APPEND PROPERTY DEPENDS mb_LP_1_001.img)
set_property(TEST cmp-mb_LP_1_001.img-nmb_LP_1_001.img APPEND PROPERTY DEPENDS nmb_LP_1_001.img)

# $(BIN)/convert_minicbf -d pilatus6m -v 1 insulin_pilatus6m.cbf insulin_pilatus6mconverted.cbf
add_test(
	insulin_pilatus6mconverted.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/convert_minicbf
	-p ${CBFlib_SOURCE_DIR}/templates/template_pilatus6m_2463x2527.cbf
	-d pilatus6m -v 1
	"${CBF_DATA_INPUT}/insulin_pilatus6m.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted.cbf
)

# -cmp insulin_pilatus6mconverted_rev_orig.cbf insulin_pilatus6mconverted.cbf
add_test(
	cmp-insulin_pilatus6mconverted_rev_orig.cbf-insulin_pilatus6mconverted.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_rev_orig.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted.cbf
)
set_property(TEST cmp-insulin_pilatus6mconverted_rev_orig.cbf-insulin_pilatus6mconverted.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf)

# $(BIN)/convert_minicbf -d pilatus6m insulin_pilatus6m.cbf insulin_pilatus6mconverted_v2.cbf
add_test(
	insulin_pilatus6mconverted_v2.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/convert_minicbf
	-p ${CBFlib_SOURCE_DIR}/templates/template_pilatus6m_2463x2527.cbf
	-d pilatus6m
	"${CBF_DATA_INPUT}/insulin_pilatus6m.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted_v2.cbf
)

# -cmp insulin_pilatus6mconverted_v2_orig.cbf insulin_pilatus6mconverted_v2.cbf
add_test(
	cmp-insulin_pilatus6mconverted_v2_orig.cbf-insulin_pilatus6mconverted_v2.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_v2_orig.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted_v2.cbf
)
set_property(TEST cmp-insulin_pilatus6mconverted_v2_orig.cbf-insulin_pilatus6mconverted_v2.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_v2.cbf)

# cif2cbf basic round-trip to hdf5 tests

# $(BIN)/cif2cbf -5 w -O $(HDF5REGISTER) -i insulin_pilatus6mconverted.cbf -o insulin_pilatus6mconverted.cbf.h5
add_test(
	insulin_pilatus6mconverted.cbf.h5
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 w -O
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted.cbf
	-o ${CBF__DATA}/insulin_pilatus6mconverted.cbf.h5
)
set_property(TEST insulin_pilatus6mconverted.cbf.h5 APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf)

# $(BIN)/cif2cbf -5 rn $(HDF5REGISTER) -en -cp -i insulin_pilatus6mconverted.cbf.h5 -o insulin_pilatus6mconverted.cbf.h5.cbf
add_test(
	insulin_pilatus6mconverted.cbf.h5.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 rn -en -cp
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted.cbf.h5
	-o ${CBF__DATA}/insulin_pilatus6mconverted.cbf.h5.cbf
)
set_property(TEST insulin_pilatus6mconverted.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf.h5)

# -cmp insulin_pilatus6mconverted.cbf.h5.cbf insulin_pilatus6mconverted_orig.cbf.h5.cbf
add_test(
	cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted.cbf.h5.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_orig.cbf.h5.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted.cbf.h5.cbf
)
set_property(TEST cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf.h5.cbf)

# $(BIN)/h5dump insulin_pilatus6mconverted_orig.cbf.h5 | $(ALLBUTONE) > insulin_pilatus6mconverted_orig.cbf.h5.dump
add_test(NAME insulin_pilatus6mconverted_orig.cbf.h5.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_orig.cbf.h5"
    "-Doutput-file=${CBF__DATA}/insulin_pilatus6mconverted_orig.cbf.h5.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
# $(BIN)/h5dump insulin_pilatus6mconverted.cbf.h5 | $(ALLBUTONE)  > insulin_pilatus6mconverted.cbf.h5.dump
add_test(NAME insulin_pilatus6mconverted.cbf.h5.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF__DATA}/insulin_pilatus6mconverted.cbf.h5"
    "-Doutput-file=${CBF__DATA}/insulin_pilatus6mconverted.cbf.h5.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
set_property(TEST insulin_pilatus6mconverted.cbf.h5.dump APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf.h5)
# $(DIFF) insulin_pilatus6mconverted_orig.cbf.h5.dump insulin_pilatus6mconverted.cbf.h5.dump
add_test(
	cmp-insulin_pilatus6mconverted_orig.cbf.h5.dump-insulin_pilatus6mconverted.cbf.h5.dump
	${CMAKE_COMMAND} -E compare_files
	${CBF__DATA}/insulin_pilatus6mconverted_orig.cbf.h5.dump
	${CBF__DATA}/insulin_pilatus6mconverted.cbf.h5.dump
)
set_property(TEST cmp-insulin_pilatus6mconverted_orig.cbf.h5.dump-insulin_pilatus6mconverted.cbf.h5.dump APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_orig.cbf.h5.dump)
set_property(TEST cmp-insulin_pilatus6mconverted_orig.cbf.h5.dump-insulin_pilatus6mconverted.cbf.h5.dump APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf.h5.dump)

# cif2cbf round-trip tests

# convert to hdf5 with '-en -cI' options, then back to cbf with '-en -cp' options to check the file against a reference file

# $(BIN)/cif2cbf -5 w $(HDF5REGISTER) -en -cI -i insulin_pilatus6mconverted.cbf -o insulin_pilatus6mconverted_encI.cbf.h5
add_test(
	insulin_pilatus6mconverted_encI.cbf.h5
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 w -en -cI
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted.cbf
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encI.cbf.h5
)
set_property(TEST insulin_pilatus6mconverted_encI.cbf.h5 APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf)
# $(BIN)/cif2cbf -5 rn $(HDF5REGISTER) -en -cp -i insulin_pilatus6mconverted_encI.cbf.h5 -o insulin_pilatus6mconverted_encI.cbf.h5.cbf
add_test(
	insulin_pilatus6mconverted_encI.cbf.h5.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 rn -en -cp
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted_encI.cbf.h5
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encI.cbf.h5.cbf
)
set_property(TEST insulin_pilatus6mconverted_encI.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encI.cbf.h5)
# -cmp insulin_pilatus6mconverted_encI.cbf.h5.cbf insulin_pilatus6mconverted_orig.cbf.h5.cbf
add_test(
	cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encI.cbf.h5.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_orig.cbf.h5.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted_encI.cbf.h5.cbf
)
set_property(TEST cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encI.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encI.cbf.h5.cbf)

# convert to hdf5 with '-en -cp' options, then back to cbf with '-en -cp' options to check the file against a reference file

# $(BIN)/cif2cbf -5 w $(HDF5REGISTER) -en -cp -i insulin_pilatus6mconverted.cbf -o insulin_pilatus6mconverted_encp.cbf.h5
add_test(
	insulin_pilatus6mconverted_encp.cbf.h5
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 w -en -cp
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted.cbf
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encp.cbf.h5
)
set_property(TEST insulin_pilatus6mconverted_encp.cbf.h5 APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf)
# $(BIN)/cif2cbf -5 rn $(HDF5REGISTER) -en -cp -i insulin_pilatus6mconverted_encp.cbf.h5 -o insulin_pilatus6mconverted_encp.cbf.h5.cbf
add_test(
	insulin_pilatus6mconverted_encp.cbf.h5.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 rn -en -cp
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted_encp.cbf.h5
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encp.cbf.h5.cbf
)
set_property(TEST insulin_pilatus6mconverted_encp.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encp.cbf.h5)
# -cmp insulin_pilatus6mconverted_encp.cbf.h5.cbf insulin_pilatus6mconverted_orig.cbf.h5.cbf
add_test(
	cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encp.cbf.h5.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_orig.cbf.h5.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted_encp.cbf.h5.cbf
)
set_property(TEST cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encp.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encp.cbf.h5.cbf)

# convert to hdf5 with '-en -cb' options, then back to cbf with '-en -cp' options to check the file against a reference file

# $(BIN)/cif2cbf -5 w $(HDF5REGISTER) -en -cb -i insulin_pilatus6mconverted.cbf -o insulin_pilatus6mconverted_encb.cbf.h5
add_test(
	insulin_pilatus6mconverted_encb.cbf.h5
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 w -en -cb
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted.cbf
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encb.cbf.h5
)
set_property(TEST insulin_pilatus6mconverted_encb.cbf.h5 APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf)
# $(BIN)/cif2cbf -5 rn $(HDF5REGISTER) -en -cp -i insulin_pilatus6mconverted_encb.cbf.h5 -o insulin_pilatus6mconverted_encb.cbf.h5.cbf
add_test(
	insulin_pilatus6mconverted_encb.cbf.h5.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 rn -en -cp
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted_encb.cbf.h5
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encb.cbf.h5.cbf
)
set_property(TEST insulin_pilatus6mconverted_encb.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encb.cbf.h5)
# -cmp insulin_pilatus6mconverted_encb.cbf.h5.cbf insulin_pilatus6mconverted_orig.cbf.h5.cbf
add_test(
	cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encb.cbf.h5.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_orig.cbf.h5.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted_encb.cbf.h5.cbf
)
set_property(TEST cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encb.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encb.cbf.h5.cbf)

# convert to hdf5 with '-en -cc' options, then back to cbf with '-en -cp' options to check the file against a reference file

# $(BIN)/cif2cbf -5 w $(HDF5REGISTER) -en -cc -i insulin_pilatus6mconverted.cbf -o insulin_pilatus6mconverted_encc.cbf.h5
add_test(
	insulin_pilatus6mconverted_encc.cbf.h5
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 w -en -cc
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted.cbf
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encc.cbf.h5
)
set_property(TEST insulin_pilatus6mconverted_encc.cbf.h5 APPEND PROPERTY DEPENDS insulin_pilatus6mconverted.cbf)
# $(BIN)/cif2cbf -5 rn $(HDF5REGISTER) -en -cp -i insulin_pilatus6mconverted_encc.cbf.h5 -o insulin_pilatus6mconverted_encc.cbf.h5.cbf
add_test(
	insulin_pilatus6mconverted_encc.cbf.h5.cbf
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cif2cbf -5 rn -en -cp
	${HDF5REGISTER}
	-i ${CBF__DATA}/insulin_pilatus6mconverted_encc.cbf.h5
	-o ${CBF__DATA}/insulin_pilatus6mconverted_encc.cbf.h5.cbf
)
set_property(TEST insulin_pilatus6mconverted_encc.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encc.cbf.h5)
# -cmp insulin_pilatus6mconverted_encc.cbf.h5.cbf insulin_pilatus6mconverted_orig.cbf.h5.cbf
add_test(
	cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encc.cbf.h5.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/insulin_pilatus6mconverted_orig.cbf.h5.cbf"
	${CBF__DATA}/insulin_pilatus6mconverted_encc.cbf.h5.cbf
)
set_property(TEST cmp-insulin_pilatus6mconverted_orig.cbf.h5.cbf-insulin_pilatus6mconverted_encc.cbf.h5.cbf APPEND PROPERTY DEPENDS insulin_pilatus6mconverted_encc.cbf.h5.cbf)

# conversion tests for tiff2cbf

# $(BIN)/tiff2cbf XRD1621.tif XRD1621.cbf
add_test(XRD1621.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tiff2cbf -cn "${CBF_DATA_INPUT}/XRD1621.tif" ${CBF__DATA}/XRD1621.cbf)

# $(DIFF) XRD1621_orig.cbf XRD1621.cbf
add_test(
	cmp-XRD1621_orig.cbf-XRD1621.cbf
	${CMAKE_COMMAND} -E compare_files
	"${CBF_DATA_OUTPUT}/XRD1621_orig.cbf"
	${CBF__DATA}/XRD1621.cbf
)
set_property(TEST cmp-XRD1621_orig.cbf-XRD1621.cbf APPEND PROPERTY DEPENDS XRD1621.cbf)
# $(BIN)/cif2cbf -I 4 -C 100. -L 0. -e n -c b -i XRD1621.cbf -o XRD1621_I4encbC100.cbf
# $(DIFF) XRD1621_I4encbC100_orig.cbf XRD1621_I4encbC100.cbf

# unit tests

add_test(testalloc ${VALGRIND_COMMAND} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testalloc)


#
# testhdf5
add_test(NAME testhdf5
  COMMAND testhdf5)
set_tests_properties(testhdf5 PROPERTIES
  FIXTURES_SETUP testhdf5)

add_test(NAME testhdf5-cleanup
  COMMAND ${CMAKE_COMMAND} -E rm "testfile.h5")
set_tests_properties(testhdf5-cleanup PROPERTIES
  FIXTURES_CLEANUP testhdf5)

add_test(testtree ${VALGRIND_COMMAND} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testtree)
add_test(testulp ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testulp)

add_test(testflatin.cbf ${CMAKE_COMMAND} -E copy "${CBF_DATA_INPUT}/testflatin.cbf" ${CBF__DATA}/testflatin.cbf)
add_test(NAME testflat COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testflat WORKING_DIRECTORY ${CBF__DATA})
set_property(TEST testflat APPEND PROPERTY DEPENDS testflatin.cbf)
add_test(cmp-testflatin.cbf-testflatout.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/testflatin.cbf ${CBF__DATA}/testflatout.cbf)
set_property(TEST cmp-testflatin.cbf-testflatout.cbf APPEND PROPERTY DEPENDS testflat)

add_test(testflatpackedin.cbf ${CMAKE_COMMAND} -E copy "${CBF_DATA_INPUT}/testflatpackedin.cbf" ${CBF__DATA}/testflatpackedin.cbf)
add_test(NAME testflatpacked COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testflatpacked WORKING_DIRECTORY ${CBF__DATA})
set_property(TEST testflatpacked APPEND PROPERTY DEPENDS testflatpackedin.cbf)
add_test(cmp-testflatpackedin.cbf-testflatpackedout.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/testflatpackedin.cbf ${CBF__DATA}/testflatpackedout.cbf)
set_property(TEST cmp-testflatpackedin.cbf-testflatpackedout.cbf APPEND PROPERTY DEPENDS testflatpacked)

add_test(testrealin.cbf ${CMAKE_COMMAND} -E copy "${CBF_DATA_INPUT}/testrealin.cbf" ${CBF__DATA}/testrealin.cbf)
add_test(NAME testreals COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testreals WORKING_DIRECTORY ${CBF__DATA})
set_property(TEST testreals APPEND PROPERTY DEPENDS testrealin.cbf)
add_test(cmp-testrealin.cbf-testrealout.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/testrealin.cbf ${CBF__DATA}/testrealout.cbf)
set_property(TEST cmp-testrealin.cbf-testrealout.cbf APPEND PROPERTY DEPENDS testreals)

# $(BIN)/sauter_test
add_test(NAME sauter_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sauter_test WORKING_DIRECTORY ${CBF__DATA})
set_property(TEST sauter_test APPEND PROPERTY DEPENDS adscconverted_flat.cbf)
# $(BIN)/changtestcompression
add_test(changtestcompression ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/changtestcompression)

# set up a test script for 'testcell':
configure_file(${CBF__EXAMPLES}/testcell.cmake ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testcell.cmake)
# $(BIN)/testcell < testcell.dat > testcell.prt
add_test(testcell ${CMAKE_COMMAND} -P ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/testcell.cmake)
# -cmp testcell_orig.prt testcell.prt
add_test(cmp-testcell_orig.prt-testcell.prt ${CMAKE_COMMAND} -E compare_files "${CBF_DATA_OUTPUT}/testcell_orig.prt" ${CBF__DATA}/testcell.prt)
set_property(TEST cmp-testcell_orig.prt-testcell.prt APPEND PROPERTY DEPENDS testcell)

# basic minicbf2nexus tests
  
# generate a hfd5 file from minicbf data
add_test(
	minicbf.h5
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/minicbf2nexus
	-c zlib
	-C ${CBFlib_SOURCE_DIR}/minicbf_test/config
	${HDF5REGISTER}
	-o ${CBF__DATA}/minicbf.h5
	"${CBF_DATA_INPUT}/X4_lots_M1S4_1_0001.cbf"
	"${CBF_DATA_INPUT}/X4_lots_M1S4_1_0002.cbf"
	"${CBF_DATA_INPUT}/X4_lots_M1S4_1_0003.cbf"
	"${CBF_DATA_INPUT}/X4_lots_M1S4_1_0004.cbf"
	"${CBF_DATA_INPUT}/X4_lots_M1S4_1_0005.cbf"
)
  
# dump the content of generated and reference hdf5 files & use 'cbf_tail' to strip off some file names
add_test(NAME minicbf_original.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF_DATA_OUTPUT}/minicbf_original.h5"
    "-Doutput-file=${CBF__DATA}/minicbf_original.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
add_test(NAME minicbf.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF__DATA}/minicbf.h5"
    "-Doutput-file=${CBF__DATA}/minicbf.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
set_property(TEST minicbf.dump APPEND PROPERTY DEPENDS minicbf.h5)

# compare dumped hdf5 file content
add_test(cmp-minicbf_original.dump-minicbf.dump ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/minicbf_original.dump ${CBF__DATA}/minicbf.dump)
set_property(TEST cmp-minicbf_original.dump-minicbf.dump APPEND PROPERTY DEPENDS minicbf_original.dump)
set_property(TEST cmp-minicbf_original.dump-minicbf.dump APPEND PROPERTY DEPENDS minicbf.dump)

# round-trip cbf2nexus & nexus2cbf tests using i19 data

# generate the data
add_test(i19-1.h5 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cbf2nexus -c zlib --list -o ${CBF__DATA}/i19-1.h5 "${CBF_DATA_INPUT}/1191_00005.cbf")

add_test(i19-1.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/nexus2cbf -o ${CBF__DATA}/i19-1.cbf ${CBF__DATA}/i19-1.h5)
set_property(TEST i19-1.cbf APPEND PROPERTY DEPENDS i19-1.h5)

add_test(i19-2.h5 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cbf2nexus -c zlib --list -o ${CBF__DATA}/i19-2.h5 ${CBF__DATA}/i19-1.cbf)
set_property(TEST i19-2.h5 APPEND PROPERTY DEPENDS i19-1.cbf)

add_test(i19-2.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/nexus2cbf -o ${CBF__DATA}/i19-2.cbf ${CBF__DATA}/i19-2.h5)
set_property(TEST i19-2.cbf APPEND PROPERTY DEPENDS i19-2.h5)

# compare the cbf files from i19 data
add_test(cmp-i19-1.cbf-i19-2.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/i19-1.cbf ${CBF__DATA}/i19-2.cbf)
set_property(TEST cmp-i19-1.cbf-i19-2.cbf APPEND PROPERTY DEPENDS i19-1.cbf)
set_property(TEST cmp-i19-1.cbf-i19-2.cbf APPEND PROPERTY DEPENDS i19-2.cbf)

# dump the content of generated hdf5 files & use 'cbf_tail' to strip off some file names
add_test(NAME i19-1.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF__DATA}/i19-1.h5"
    "-Doutput-file=${CBF__DATA}/i19-1.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
set_property(TEST i19-1.dump APPEND PROPERTY DEPENDS i19-1.h5)
add_test(NAME i19-2.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF__DATA}/i19-2.h5"
    "-Doutput-file=${CBF__DATA}/i19-2.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
set_property(TEST i19-2.dump APPEND PROPERTY DEPENDS i19-2.h5)

# compare dumped hdf5 file content
add_test(cmp-i19-1.dump-i19-2.dump ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/i19-1.dump ${CBF__DATA}/i19-2.dump)
set_property(TEST cmp-i19-1.dump-i19-2.dump APPEND PROPERTY DEPENDS i19-1.dump)
set_property(TEST cmp-i19-1.dump-i19-2.dump APPEND PROPERTY DEPENDS i19-2.dump)

# round-trip cbf2nexus & nexus2cbf tests using i03 data

# generate the data
add_test(i03-1.h5 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cbf2nexus -c zlib --list -o ${CBF__DATA}/i03-1.h5 "${CBF_DATA_INPUT}/thaumatin_die_M1S5_1_0005_2.cbf")

add_test(i03-1.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/nexus2cbf -o ${CBF__DATA}/i03-1.cbf ${CBF__DATA}/i03-1.h5)
set_property(TEST i03-1.cbf APPEND PROPERTY DEPENDS i03-1.h5)

add_test(i03-2.h5 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cbf2nexus -c zlib --list -o ${CBF__DATA}/i03-2.h5 ${CBF__DATA}/i03-1.cbf)
set_property(TEST i03-2.h5 APPEND PROPERTY DEPENDS i03-1.cbf)

add_test(i03-2.cbf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/nexus2cbf -o ${CBF__DATA}/i03-2.cbf ${CBF__DATA}/i03-2.h5)
set_property(TEST i03-2.cbf APPEND PROPERTY DEPENDS i03-2.h5)

# compare the cbf files from i03 data
add_test(cmp-i03-1.cbf-i03-2.cbf ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/i03-1.cbf ${CBF__DATA}/i03-2.cbf)
set_property(TEST cmp-i03-1.cbf-i03-2.cbf APPEND PROPERTY DEPENDS i03-1.cbf)
set_property(TEST cmp-i03-1.cbf-i03-2.cbf APPEND PROPERTY DEPENDS i03-2.cbf)

# dump the content of generated hdf5 files & use 'cbf_tail' to strip off some file names
add_test(NAME i03-1.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF__DATA}/i03-1.h5"
    "-Doutput-file=${CBF__DATA}/i03-1.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
set_property(TEST i03-1.dump APPEND PROPERTY DEPENDS i03-1.h5)
add_test(NAME i03-2.dump
  COMMAND ${CMAKE_COMMAND}
    "-Dinput-file=${CBF__DATA}/i03-2.h5"
    "-Doutput-file=${CBF__DATA}/i03-2.dump"
    -P "${PROJECT_BINARY_DIR}/h5dump-$<CONFIG>.cmake")
set_property(TEST i03-2.dump APPEND PROPERTY DEPENDS i03-2.h5)

# compare dumped hdf5 file content
add_test(cmp-i03-1.dump-i03-2.dump ${CMAKE_COMMAND} -E compare_files ${CBF__DATA}/i03-1.dump ${CBF__DATA}/i03-2.dump)
set_property(TEST cmp-i03-1.dump-i03-2.dump APPEND PROPERTY DEPENDS i03-1.dump)
set_property(TEST cmp-i03-1.dump-i03-2.dump APPEND PROPERTY DEPENDS i03-2.dump)

