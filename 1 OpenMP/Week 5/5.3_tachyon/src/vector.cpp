/*
    Copyright 2005-2009 Intel Corporation.  All Rights Reserved.

    The source code contained or described herein and all documents related
    to the source code ("Material") are owned by Intel Corporation or its
    suppliers or licensors.  Title to the Material remains with Intel
    Corporation or its suppliers and licensors.  The Material is protected
    by worldwide copyright laws and treaty provisions.  No part of the
    Material may be used, copied, reproduced, modified, published, uploaded,
    posted, transmitted, distributed, or disclosed in any way without
    Intel's prior express written permission.

    No license under any patent, copyright, trade secret or other
    intellectual property right is granted to or conferred upon you by
    disclosure or delivery of the Materials, either expressly, by
    implication, inducement, estoppel or otherwise.  Any license under such
    intellectual property rights must be express and approved by Intel in
    writing.
*/

/*
    The original source for this example is
    Copyright (c) 1994-2008 John E. Stone
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. The name of the author may not be used to endorse or promote products
       derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.
*/

/* 
 * vector.c - This file contains all of the vector arithmetic functions.
 *
 *  $Id: vector.cpp,v 1.2 2007-02-22 17:54:17 dpoulsen Exp $
 */

#include "machine.h"
#include "types.h"
#include "macros.h"

flt VDot(vector *a, vector *b) {
  return (a->x*b->x + a->y*b->y + a->z*b->z);
}

void VCross(vector * a, vector * b, vector * c) {
  c->x = (a->y * b->z) - (a->z * b->y);
  c->y = (a->z * b->x) - (a->x * b->z);
  c->z = (a->x * b->y) - (a->y * b->x);
}

flt VLength(vector * a) {
  return (flt) sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z));
}

void VNorm(vector * a) {
  flt len;

  len=sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z));
  if (len != 0.0) {
    a->x /= len;
    a->y /= len;
    a->z /= len;
  }
}

void VAdd(vector * a, vector * b, vector * c) {
  c->x = (a->x + b->x);
  c->y = (a->y + b->y);
  c->z = (a->z + b->z);
}
    
void VSub(vector * a, vector * b, vector * c) {
  c->x = (a->x - b->x);
  c->y = (a->y - b->y);
  c->z = (a->z - b->z);
}

void VAddS(flt a, vector * A, vector * B, vector * C) {
  C->x = (a * A->x) + B->x;
  C->y = (a * A->y) + B->y;
  C->z = (a * A->z) + B->z;
}

vector Raypnt(ray * a, flt t) {
  vector temp;

  temp.x=a->o.x + (a->d.x * t);
  temp.y=a->o.y + (a->d.y * t);
  temp.z=a->o.z + (a->d.z * t);

  return temp;
}

void VScale(vector * a, flt s) {
  a->x *= s;
  a->y *= s;
  a->z *= s;
}

void ColorAddS(color * a, color * b, flt s) {
  a->r += b->r * s;
  a->g += b->g * s;
  a->b += b->b * s;
}

void ColorAccum(color * a, color * b) {
  a->r += b->r;
  a->g += b->g;
  a->b += b->b;
}

void ColorScale(color * a, flt s) {
  a->r *= s;
  a->g *= s;
  a->b *= s;
}

