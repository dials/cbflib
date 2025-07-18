/* lib/fgetln.c - bsd-games implementation of fgetln.
 *
 * Copyright (c) 1997, 1998, 1999, 2000, 2004 Joseph Samuel Myers.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
_cbf_fgetln(FILE *stream, size_t *len)
{
  static char *buf = NULL;
  static size_t buflen = 0;
  char *res;
  char *nbuf;
  if (buf == NULL) {
    buf = (char *)malloc(buflen = 1024);
    if (buf == NULL) {
      return NULL;
    }
  }
  buf[buflen - 1] = 1;
  res = fgets(buf, buflen, stream);
  if (res == NULL)
    return NULL;
  while (buf[buflen - 1] == 0 && buf[buflen - 2] != '\n') { /* long line */
    nbuf = realloc(buf, buflen * 2);
    if (nbuf == NULL)
      return NULL;
    buf = nbuf;
    buflen *= 2;
    buf[buflen - 1] = 1;
    res = fgets(buf + buflen/2 - 1, buflen/2 + 1, stream);
    if (res == NULL)
      return NULL;
  }
  *len = strlen(buf);
  return buf;
}
