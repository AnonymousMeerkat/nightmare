/* Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Nightmare Project nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#ifndef _NME_VECMATH_H
#define _NME_VECMATH_H

#include "NVecTypes.h"
#include <math.h>

static NVec2i_t NVec2i(int x, int y);
static NVec2f_t NVec2i_2f(NVec2i_t o);
static NVec3i_t NVec2i_3i(NVec2i_t o);
static NVec3f_t NVec2i_3f(NVec2i_t o);
static NVec4i_t NVec2i_4i(NVec2i_t o);
static NVec4f_t NVec2i_4f(NVec2i_t o);
static NMat2i_t NMat2i(int m00, int m01, int m10, int m11);
static NMat2i_t NMat2i_identity();
static NMat2i_t NMat2i_rows(int x, int y);
static NMat2i_t NMat2i_cols(int x, int y);
static NMat2f_t NMat2i_2f(NMat2i_t o);
static NMat3i_t NMat2i_3i(NMat2i_t o);
static NMat3f_t NMat2i_3f(NMat2i_t o);
static NMat4i_t NMat2i_4i(NMat2i_t o);
static NMat4f_t NMat2i_4f(NMat2i_t o);
static NVec2i_t NVec2i_neg(NVec2i_t v1);
static NVec2i_t NVec2i_add(NVec2i_t v1, NVec2i_t v2);
static NVec2i_t NVec2i_adds(NVec2i_t v1, int s);
static NVec2i_t NVec2i_sub(NVec2i_t v1, NVec2i_t v2);
static NVec2i_t NVec2i_subs(NVec2i_t v1, int s);
static NVec2i_t NVec2i_mul(NVec2i_t v1, NVec2i_t v2);
static NVec2i_t NVec2i_muls(NVec2i_t v1, int s);
static NVec2i_t NVec2i_div(NVec2i_t v1, NVec2i_t v2);
static NVec2i_t NVec2i_divs(NVec2i_t v1, int s);
static int NVec2i_dot(NVec2i_t v1, NVec2i_t v2);
static float NVec2i_len(NVec2i_t v1);
static NVec2i_t NVec2i_norm(NVec2i_t v1);
static NVec2i_t NVec2i_proj(NVec2i_t v1, NVec2i_t v2);
static NMat2i_t NMat2i_add(NMat2i_t m1, NMat2i_t m2);
static NMat2i_t NMat2i_sub(NMat2i_t m1, NMat2i_t m2);
static NMat2i_t NMat2i_mul(NMat2i_t m1, NMat2i_t m2);
static NVec2f_t NVec2f(float x, float y);
static NVec2i_t NVec2f_2i(NVec2f_t o);
static NVec3i_t NVec2f_3i(NVec2f_t o);
static NVec3f_t NVec2f_3f(NVec2f_t o);
static NVec4i_t NVec2f_4i(NVec2f_t o);
static NVec4f_t NVec2f_4f(NVec2f_t o);
static NMat2f_t NMat2f(float m00, float m01, float m10, float m11);
static NMat2f_t NMat2f_identity();
static NMat2f_t NMat2f_rows(float x, float y);
static NMat2f_t NMat2f_cols(float x, float y);
static NMat2i_t NMat2f_2i(NMat2f_t o);
static NMat3i_t NMat2f_3i(NMat2f_t o);
static NMat3f_t NMat2f_3f(NMat2f_t o);
static NMat4i_t NMat2f_4i(NMat2f_t o);
static NMat4f_t NMat2f_4f(NMat2f_t o);
static NVec2f_t NVec2f_neg(NVec2f_t v1);
static NVec2f_t NVec2f_add(NVec2f_t v1, NVec2f_t v2);
static NVec2f_t NVec2f_adds(NVec2f_t v1, float s);
static NVec2f_t NVec2f_sub(NVec2f_t v1, NVec2f_t v2);
static NVec2f_t NVec2f_subs(NVec2f_t v1, float s);
static NVec2f_t NVec2f_mul(NVec2f_t v1, NVec2f_t v2);
static NVec2f_t NVec2f_muls(NVec2f_t v1, float s);
static NVec2f_t NVec2f_div(NVec2f_t v1, NVec2f_t v2);
static NVec2f_t NVec2f_divs(NVec2f_t v1, float s);
static float NVec2f_dot(NVec2f_t v1, NVec2f_t v2);
static float NVec2f_len(NVec2f_t v1);
static NVec2f_t NVec2f_norm(NVec2f_t v1);
static NVec2f_t NVec2f_proj(NVec2f_t v1, NVec2f_t v2);
static NMat2f_t NMat2f_add(NMat2f_t m1, NMat2f_t m2);
static NMat2f_t NMat2f_sub(NMat2f_t m1, NMat2f_t m2);
static NMat2f_t NMat2f_mul(NMat2f_t m1, NMat2f_t m2);
static NVec3i_t NVec3i(int x, int y, int z);
static NVec2i_t NVec3i_2i(NVec3i_t o);
static NVec2f_t NVec3i_2f(NVec3i_t o);
static NVec3f_t NVec3i_3f(NVec3i_t o);
static NVec4i_t NVec3i_4i(NVec3i_t o);
static NVec4f_t NVec3i_4f(NVec3i_t o);
static NMat3i_t NMat3i(int m00, int m01, int m02, int m10, int m11, int m12, int m20, int m21, int m22);
static NMat3i_t NMat3i_identity();
static NMat3i_t NMat3i_rows(int x, int y, int z);
static NMat3i_t NMat3i_cols(int x, int y, int z);
static NMat2i_t NMat3i_2i(NMat3i_t o);
static NMat2f_t NMat3i_2f(NMat3i_t o);
static NMat3f_t NMat3i_3f(NMat3i_t o);
static NMat4i_t NMat3i_4i(NMat3i_t o);
static NMat4f_t NMat3i_4f(NMat3i_t o);
static NVec3i_t NVec3i_neg(NVec3i_t v1);
static NVec3i_t NVec3i_add(NVec3i_t v1, NVec3i_t v2);
static NVec3i_t NVec3i_adds(NVec3i_t v1, int s);
static NVec3i_t NVec3i_sub(NVec3i_t v1, NVec3i_t v2);
static NVec3i_t NVec3i_subs(NVec3i_t v1, int s);
static NVec3i_t NVec3i_mul(NVec3i_t v1, NVec3i_t v2);
static NVec3i_t NVec3i_muls(NVec3i_t v1, int s);
static NVec3i_t NVec3i_div(NVec3i_t v1, NVec3i_t v2);
static NVec3i_t NVec3i_divs(NVec3i_t v1, int s);
static int NVec3i_dot(NVec3i_t v1, NVec3i_t v2);
static float NVec3i_len(NVec3i_t v1);
static NVec3i_t NVec3i_norm(NVec3i_t v1);
static NVec3i_t NVec3i_cross(NVec3i_t v1, NVec3i_t v2);
static NVec3i_t NVec3i_proj(NVec3i_t v1, NVec3i_t v2);
static NMat3i_t NMat3i_add(NMat3i_t m1, NMat3i_t m2);
static NMat3i_t NMat3i_sub(NMat3i_t m1, NMat3i_t m2);
static NMat3i_t NMat3i_mul(NMat3i_t m1, NMat3i_t m2);
static NMat3i_t NMat3i_scale_3i(NMat3i_t m1, NVec3i_t v1);
static NMat3i_t NMat3i_scale_3f(NMat3i_t m1, NVec3f_t v1);
static NMat3i_t NMat3i_scale_4i(NMat3i_t m1, NVec4i_t v1);
static NMat3i_t NMat3i_scale_4f(NMat3i_t m1, NVec4f_t v1);
static NMat3i_t NMat3i_rotation_3i(float radians, NVec3i_t v1);
static NMat3i_t NMat3i_rotation_3f(float radians, NVec3f_t v1);
static NMat3i_t NMat3i_rotation_4i(float radians, NVec4i_t v1);
static NMat3i_t NMat3i_rotation_4f(float radians, NVec4f_t v1);
static NMat3i_t NMat3i_rotate_3i(NMat3i_t m1, float radians, NVec3i_t v1);
static NMat3i_t NMat3i_rotate_3f(NMat3i_t m1, float radians, NVec3f_t v1);
static NMat3i_t NMat3i_rotate_4i(NMat3i_t m1, float radians, NVec4i_t v1);
static NMat3i_t NMat3i_rotate_4f(NMat3i_t m1, float radians, NVec4f_t v1);
static NVec3f_t NVec3f(float x, float y, float z);
static NVec2i_t NVec3f_2i(NVec3f_t o);
static NVec2f_t NVec3f_2f(NVec3f_t o);
static NVec3i_t NVec3f_3i(NVec3f_t o);
static NVec4i_t NVec3f_4i(NVec3f_t o);
static NVec4f_t NVec3f_4f(NVec3f_t o);
static NMat3f_t NMat3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
static NMat3f_t NMat3f_identity();
static NMat3f_t NMat3f_rows(float x, float y, float z);
static NMat3f_t NMat3f_cols(float x, float y, float z);
static NMat2i_t NMat3f_2i(NMat3f_t o);
static NMat2f_t NMat3f_2f(NMat3f_t o);
static NMat3i_t NMat3f_3i(NMat3f_t o);
static NMat4i_t NMat3f_4i(NMat3f_t o);
static NMat4f_t NMat3f_4f(NMat3f_t o);
static NVec3f_t NVec3f_neg(NVec3f_t v1);
static NVec3f_t NVec3f_add(NVec3f_t v1, NVec3f_t v2);
static NVec3f_t NVec3f_adds(NVec3f_t v1, float s);
static NVec3f_t NVec3f_sub(NVec3f_t v1, NVec3f_t v2);
static NVec3f_t NVec3f_subs(NVec3f_t v1, float s);
static NVec3f_t NVec3f_mul(NVec3f_t v1, NVec3f_t v2);
static NVec3f_t NVec3f_muls(NVec3f_t v1, float s);
static NVec3f_t NVec3f_div(NVec3f_t v1, NVec3f_t v2);
static NVec3f_t NVec3f_divs(NVec3f_t v1, float s);
static float NVec3f_dot(NVec3f_t v1, NVec3f_t v2);
static float NVec3f_len(NVec3f_t v1);
static NVec3f_t NVec3f_norm(NVec3f_t v1);
static NVec3f_t NVec3f_cross(NVec3f_t v1, NVec3f_t v2);
static NVec3f_t NVec3f_proj(NVec3f_t v1, NVec3f_t v2);
static NMat3f_t NMat3f_add(NMat3f_t m1, NMat3f_t m2);
static NMat3f_t NMat3f_sub(NMat3f_t m1, NMat3f_t m2);
static NMat3f_t NMat3f_mul(NMat3f_t m1, NMat3f_t m2);
static NMat3f_t NMat3f_scale_3i(NMat3f_t m1, NVec3i_t v1);
static NMat3f_t NMat3f_scale_3f(NMat3f_t m1, NVec3f_t v1);
static NMat3f_t NMat3f_scale_4i(NMat3f_t m1, NVec4i_t v1);
static NMat3f_t NMat3f_scale_4f(NMat3f_t m1, NVec4f_t v1);
static NMat3f_t NMat3f_rotation_3i(float radians, NVec3i_t v1);
static NMat3f_t NMat3f_rotation_3f(float radians, NVec3f_t v1);
static NMat3f_t NMat3f_rotation_4i(float radians, NVec4i_t v1);
static NMat3f_t NMat3f_rotation_4f(float radians, NVec4f_t v1);
static NMat3f_t NMat3f_rotate_3i(NMat3f_t m1, float radians, NVec3i_t v1);
static NMat3f_t NMat3f_rotate_3f(NMat3f_t m1, float radians, NVec3f_t v1);
static NMat3f_t NMat3f_rotate_4i(NMat3f_t m1, float radians, NVec4i_t v1);
static NMat3f_t NMat3f_rotate_4f(NMat3f_t m1, float radians, NVec4f_t v1);
static NVec4i_t NVec4i(int x, int y, int z, int w);
static NVec2i_t NVec4i_2i(NVec4i_t o);
static NVec2f_t NVec4i_2f(NVec4i_t o);
static NVec3i_t NVec4i_3i(NVec4i_t o);
static NVec3f_t NVec4i_3f(NVec4i_t o);
static NVec4f_t NVec4i_4f(NVec4i_t o);
static NMat4i_t NMat4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13, int m20, int m21, int m22, int m23, int m30, int m31, int m32, int m33);
static NMat4i_t NMat4i_identity();
static NMat4i_t NMat4i_rows(int x, int y, int z, int w);
static NMat4i_t NMat4i_cols(int x, int y, int z, int w);
static NMat2i_t NMat4i_2i(NMat4i_t o);
static NMat2f_t NMat4i_2f(NMat4i_t o);
static NMat3i_t NMat4i_3i(NMat4i_t o);
static NMat3f_t NMat4i_3f(NMat4i_t o);
static NMat4f_t NMat4i_4f(NMat4i_t o);
static NVec4i_t NVec4i_neg(NVec4i_t v1);
static NVec4i_t NVec4i_add(NVec4i_t v1, NVec4i_t v2);
static NVec4i_t NVec4i_adds(NVec4i_t v1, int s);
static NVec4i_t NVec4i_sub(NVec4i_t v1, NVec4i_t v2);
static NVec4i_t NVec4i_subs(NVec4i_t v1, int s);
static NVec4i_t NVec4i_mul(NVec4i_t v1, NVec4i_t v2);
static NVec4i_t NVec4i_muls(NVec4i_t v1, int s);
static NVec4i_t NVec4i_div(NVec4i_t v1, NVec4i_t v2);
static NVec4i_t NVec4i_divs(NVec4i_t v1, int s);
static int NVec4i_dot(NVec4i_t v1, NVec4i_t v2);
static float NVec4i_len(NVec4i_t v1);
static NVec4i_t NVec4i_norm(NVec4i_t v1);
static NVec4i_t NVec4i_cross(NVec4i_t v1, NVec4i_t v2);
static NVec4i_t NVec4i_proj(NVec4i_t v1, NVec4i_t v2);
static NMat4i_t NMat4i_add(NMat4i_t m1, NMat4i_t m2);
static NMat4i_t NMat4i_sub(NMat4i_t m1, NMat4i_t m2);
static NMat4i_t NMat4i_mul(NMat4i_t m1, NMat4i_t m2);
static NMat4i_t NMat4i_scale_3i(NMat4i_t m1, NVec3i_t v1);
static NMat4i_t NMat4i_scale_3f(NMat4i_t m1, NVec3f_t v1);
static NMat4i_t NMat4i_scale_4i(NMat4i_t m1, NVec4i_t v1);
static NMat4i_t NMat4i_scale_4f(NMat4i_t m1, NVec4f_t v1);
static NMat4i_t NMat4i_rotation_3i(float radians, NVec3i_t v1);
static NMat4i_t NMat4i_rotation_3f(float radians, NVec3f_t v1);
static NMat4i_t NMat4i_rotation_4i(float radians, NVec4i_t v1);
static NMat4i_t NMat4i_rotation_4f(float radians, NVec4f_t v1);
static NMat4i_t NMat4i_rotate_3i(NMat4i_t m1, float radians, NVec3i_t v1);
static NMat4i_t NMat4i_rotate_3f(NMat4i_t m1, float radians, NVec3f_t v1);
static NMat4i_t NMat4i_rotate_4i(NMat4i_t m1, float radians, NVec4i_t v1);
static NMat4i_t NMat4i_rotate_4f(NMat4i_t m1, float radians, NVec4f_t v1);
static NVec4f_t NVec4f(float x, float y, float z, float w);
static NVec2i_t NVec4f_2i(NVec4f_t o);
static NVec2f_t NVec4f_2f(NVec4f_t o);
static NVec3i_t NVec4f_3i(NVec4f_t o);
static NVec3f_t NVec4f_3f(NVec4f_t o);
static NVec4i_t NVec4f_4i(NVec4f_t o);
static NMat4f_t NMat4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
static NMat4f_t NMat4f_identity();
static NMat4f_t NMat4f_rows(float x, float y, float z, float w);
static NMat4f_t NMat4f_cols(float x, float y, float z, float w);
static NMat2i_t NMat4f_2i(NMat4f_t o);
static NMat2f_t NMat4f_2f(NMat4f_t o);
static NMat3i_t NMat4f_3i(NMat4f_t o);
static NMat3f_t NMat4f_3f(NMat4f_t o);
static NMat4i_t NMat4f_4i(NMat4f_t o);
static NVec4f_t NVec4f_neg(NVec4f_t v1);
static NVec4f_t NVec4f_add(NVec4f_t v1, NVec4f_t v2);
static NVec4f_t NVec4f_adds(NVec4f_t v1, float s);
static NVec4f_t NVec4f_sub(NVec4f_t v1, NVec4f_t v2);
static NVec4f_t NVec4f_subs(NVec4f_t v1, float s);
static NVec4f_t NVec4f_mul(NVec4f_t v1, NVec4f_t v2);
static NVec4f_t NVec4f_muls(NVec4f_t v1, float s);
static NVec4f_t NVec4f_div(NVec4f_t v1, NVec4f_t v2);
static NVec4f_t NVec4f_divs(NVec4f_t v1, float s);
static float NVec4f_dot(NVec4f_t v1, NVec4f_t v2);
static float NVec4f_len(NVec4f_t v1);
static NVec4f_t NVec4f_norm(NVec4f_t v1);
static NVec4f_t NVec4f_cross(NVec4f_t v1, NVec4f_t v2);
static NVec4f_t NVec4f_proj(NVec4f_t v1, NVec4f_t v2);
static NMat4f_t NMat4f_add(NMat4f_t m1, NMat4f_t m2);
static NMat4f_t NMat4f_sub(NMat4f_t m1, NMat4f_t m2);
static NMat4f_t NMat4f_mul(NMat4f_t m1, NMat4f_t m2);
static NMat4f_t NMat4f_scale_3i(NMat4f_t m1, NVec3i_t v1);
static NMat4f_t NMat4f_scale_3f(NMat4f_t m1, NVec3f_t v1);
static NMat4f_t NMat4f_scale_4i(NMat4f_t m1, NVec4i_t v1);
static NMat4f_t NMat4f_scale_4f(NMat4f_t m1, NVec4f_t v1);
static NMat4f_t NMat4f_rotation_3i(float radians, NVec3i_t v1);
static NMat4f_t NMat4f_rotation_3f(float radians, NVec3f_t v1);
static NMat4f_t NMat4f_rotation_4i(float radians, NVec4i_t v1);
static NMat4f_t NMat4f_rotation_4f(float radians, NVec4f_t v1);
static NMat4f_t NMat4f_rotate_3i(NMat4f_t m1, float radians, NVec3i_t v1);
static NMat4f_t NMat4f_rotate_3f(NMat4f_t m1, float radians, NVec3f_t v1);
static NMat4f_t NMat4f_rotate_4i(NMat4f_t m1, float radians, NVec4i_t v1);
static NMat4f_t NMat4f_rotate_4f(NMat4f_t m1, float radians, NVec4f_t v1);
static NMat4f_t NMat4f_translate_3i(NMat4f_t m1, NVec3i_t v1);
static NMat4f_t NMat4f_translate_3f(NMat4f_t m1, NVec3f_t v1);
static NMat4f_t NMat4f_perspective(float fov_rad, float aspect, float nearZ, float farZ);
static NMat4f_t NMat4f_frustum(float left, float right, float bottom, float top, float nearZ, float farZ);
static NMat4f_t NMat4f_ortho(float left, float right, float bottom, float top, float nearZ, float farZ);

static __inline__ NVec2i_t NVec2i(int x, int y) {
    NVec2i_t ret = {{x, y}};
    return ret;
}

static __inline__ NVec2f_t NVec2i_2f(NVec2i_t o) {
    NVec2f_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec3i_t NVec2i_3i(NVec2i_t o) {
    NVec3i_t ret = {{o.v[0], o.v[1], 0}};
    return ret;
}

static __inline__ NVec3f_t NVec2i_3f(NVec2i_t o) {
    NVec3f_t ret = {{o.v[0], o.v[1], 0}};
    return ret;
}

static __inline__ NVec4i_t NVec2i_4i(NVec2i_t o) {
    NVec4i_t ret = {{o.v[0], o.v[1], 0, 0}};
    return ret;
}

static __inline__ NVec4f_t NVec2i_4f(NVec2i_t o) {
    NVec4f_t ret = {{o.v[0], o.v[1], 0, 0}};
    return ret;
}

static __inline__ NMat2i_t NMat2i(int m00, int m01, int m10, int m11) {
    NMat2i_t ret = {{m00, m01, m10, m11}};
    return ret;
}

static __inline__ NMat2i_t NMat2i_identity() {
    NMat2i_t ret = {{1, 0, 0, 1}};
    return ret;
}

static __inline__ NMat2i_t NMat2i_rows(int x, int y) {
    NMat2i_t ret = {{x, x, y, y}};
    return ret;
}

static __inline__ NMat2i_t NMat2i_cols(int x, int y) {
    NMat2i_t ret = {{x, y, x, y}};
    return ret;
}

static __inline__ NMat2f_t NMat2i_2f(NMat2i_t o) {
    NMat2f_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat3i_t NMat2i_3i(NMat2i_t o) {
    NMat3i_t ret = {{o.m00, o.m01, 0, o.m10, o.m11, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat3f_t NMat2i_3f(NMat2i_t o) {
    NMat3f_t ret = {{o.m00, o.m01, 0, o.m10, o.m11, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat4i_t NMat2i_4i(NMat2i_t o) {
    NMat4i_t ret = {{o.m00, o.m01, 0, 0, o.m10, o.m11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat4f_t NMat2i_4f(NMat2i_t o) {
    NMat4f_t ret = {{o.m00, o.m01, 0, 0, o.m10, o.m11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_neg(NVec2i_t v1) {
    NVec2i_t ret = {{-v1.x, -v1.y}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_add(NVec2i_t v1, NVec2i_t v2) {
    NVec2i_t ret = {{v1.x + v2.x, v1.y + v2.y}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_adds(NVec2i_t v1, int s) {
    NVec2i_t ret = {{v1.x + s, v1.y + s}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_sub(NVec2i_t v1, NVec2i_t v2) {
    NVec2i_t ret = {{v1.x - v2.x, v1.y - v2.y}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_subs(NVec2i_t v1, int s) {
    NVec2i_t ret = {{v1.x - s, v1.y - s}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_mul(NVec2i_t v1, NVec2i_t v2) {
    NVec2i_t ret = {{v1.x * v2.x, v1.y * v2.y}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_muls(NVec2i_t v1, int s) {
    NVec2i_t ret = {{v1.x * s, v1.y * s}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_div(NVec2i_t v1, NVec2i_t v2) {
    NVec2i_t ret = {{v1.x / v2.x, v1.y / v2.y}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_divs(NVec2i_t v1, int s) {
    float f = 1. / s;
    NVec2i_t ret = {{v1.x * f, v1.y * f}};
    return ret;
}

static __inline__ int NVec2i_dot(NVec2i_t v1, NVec2i_t v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

static __inline__ float NVec2i_len(NVec2i_t v1) {
    return sqrt(v1.x * v1.x + v1.y * v1.y);
}

static __inline__ NVec2i_t NVec2i_norm(NVec2i_t v1) {
    float scale = 1.f / NVec2i_len(v1);
    NVec2i_t ret = {{v1.x * scale, v1.y * scale}};
    return ret;
}

static __inline__ NVec2i_t NVec2i_proj(NVec2i_t v1, NVec2i_t v2) {
    float scale = NVec2i_dot(v2, v1) / NVec2i_dot(v2, v2);
    NVec2i_t ret = NVec2i_muls(v2, scale);
    return ret;
}

static __inline__ NMat2i_t NMat2i_add(NMat2i_t m1, NMat2i_t m2) {
    NMat2i_t ret = (NMat2i_t) {{m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m10 + m2.m10, m1.m11 + m2.m11}};
    return ret;
}

static __inline__ NMat2i_t NMat2i_sub(NMat2i_t m1, NMat2i_t m2) {
    NMat2i_t ret = (NMat2i_t) {{m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m10 - m2.m10, m1.m11 - m2.m11}};
    return ret;
}

static __inline__ NMat2i_t NMat2i_mul(NMat2i_t m1, NMat2i_t m2) {
    NMat2i_t ret = (NMat2i_t) {{
        m1.m00 * m2.m00 + m1.m10 * m2.m01,
        m1.m01 * m2.m00 + m1.m11 * m2.m01,
        m1.m00 * m2.m10 + m1.m10 * m2.m11,
        m1.m01 * m2.m10 + m1.m11 * m2.m11
    }};
    return ret;
}

static __inline__ NVec2f_t NVec2f(float x, float y) {
    NVec2f_t ret = {{x, y}};
    return ret;
}

static __inline__ NVec2i_t NVec2f_2i(NVec2f_t o) {
    NVec2i_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec3i_t NVec2f_3i(NVec2f_t o) {
    NVec3i_t ret = {{o.v[0], o.v[1], 0}};
    return ret;
}

static __inline__ NVec3f_t NVec2f_3f(NVec2f_t o) {
    NVec3f_t ret = {{o.v[0], o.v[1], 0}};
    return ret;
}

static __inline__ NVec4i_t NVec2f_4i(NVec2f_t o) {
    NVec4i_t ret = {{o.v[0], o.v[1], 0, 0}};
    return ret;
}

static __inline__ NVec4f_t NVec2f_4f(NVec2f_t o) {
    NVec4f_t ret = {{o.v[0], o.v[1], 0, 0}};
    return ret;
}

static __inline__ NMat2f_t NMat2f(float m00, float m01, float m10, float m11) {
    NMat2f_t ret = {{m00, m01, m10, m11}};
    return ret;
}

static __inline__ NMat2f_t NMat2f_identity() {
    NMat2f_t ret = {{1, 0, 0, 1}};
    return ret;
}

static __inline__ NMat2f_t NMat2f_rows(float x, float y) {
    NMat2f_t ret = {{x, x, y, y}};
    return ret;
}

static __inline__ NMat2f_t NMat2f_cols(float x, float y) {
    NMat2f_t ret = {{x, y, x, y}};
    return ret;
}

static __inline__ NMat2i_t NMat2f_2i(NMat2f_t o) {
    NMat2i_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat3i_t NMat2f_3i(NMat2f_t o) {
    NMat3i_t ret = {{o.m00, o.m01, 0, o.m10, o.m11, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat3f_t NMat2f_3f(NMat2f_t o) {
    NMat3f_t ret = {{o.m00, o.m01, 0, o.m10, o.m11, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat4i_t NMat2f_4i(NMat2f_t o) {
    NMat4i_t ret = {{o.m00, o.m01, 0, 0, o.m10, o.m11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat4f_t NMat2f_4f(NMat2f_t o) {
    NMat4f_t ret = {{o.m00, o.m01, 0, 0, o.m10, o.m11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_neg(NVec2f_t v1) {
    NVec2f_t ret = {{-v1.x, -v1.y}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_add(NVec2f_t v1, NVec2f_t v2) {
    NVec2f_t ret = {{v1.x + v2.x, v1.y + v2.y}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_adds(NVec2f_t v1, float s) {
    NVec2f_t ret = {{v1.x + s, v1.y + s}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_sub(NVec2f_t v1, NVec2f_t v2) {
    NVec2f_t ret = {{v1.x - v2.x, v1.y - v2.y}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_subs(NVec2f_t v1, float s) {
    NVec2f_t ret = {{v1.x - s, v1.y - s}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_mul(NVec2f_t v1, NVec2f_t v2) {
    NVec2f_t ret = {{v1.x * v2.x, v1.y * v2.y}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_muls(NVec2f_t v1, float s) {
    NVec2f_t ret = {{v1.x * s, v1.y * s}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_div(NVec2f_t v1, NVec2f_t v2) {
    NVec2f_t ret = {{v1.x / v2.x, v1.y / v2.y}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_divs(NVec2f_t v1, float s) {
    float f = 1. / s;
    NVec2f_t ret = {{v1.x * f, v1.y * f}};
    return ret;
}

static __inline__ float NVec2f_dot(NVec2f_t v1, NVec2f_t v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

static __inline__ float NVec2f_len(NVec2f_t v1) {
    return sqrt(v1.x * v1.x + v1.y * v1.y);
}

static __inline__ NVec2f_t NVec2f_norm(NVec2f_t v1) {
    float scale = 1.f / NVec2f_len(v1);
    NVec2f_t ret = {{v1.x * scale, v1.y * scale}};
    return ret;
}

static __inline__ NVec2f_t NVec2f_proj(NVec2f_t v1, NVec2f_t v2) {
    float scale = NVec2f_dot(v2, v1) / NVec2f_dot(v2, v2);
    NVec2f_t ret = NVec2f_muls(v2, scale);
    return ret;
}

static __inline__ NMat2f_t NMat2f_add(NMat2f_t m1, NMat2f_t m2) {
    NMat2f_t ret = (NMat2f_t) {{m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m10 + m2.m10, m1.m11 + m2.m11}};
    return ret;
}

static __inline__ NMat2f_t NMat2f_sub(NMat2f_t m1, NMat2f_t m2) {
    NMat2f_t ret = (NMat2f_t) {{m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m10 - m2.m10, m1.m11 - m2.m11}};
    return ret;
}

static __inline__ NMat2f_t NMat2f_mul(NMat2f_t m1, NMat2f_t m2) {
    NMat2f_t ret = (NMat2f_t) {{
        m1.m00 * m2.m00 + m1.m10 * m2.m01,
        m1.m01 * m2.m00 + m1.m11 * m2.m01,
        m1.m00 * m2.m10 + m1.m10 * m2.m11,
        m1.m01 * m2.m10 + m1.m11 * m2.m11
    }};
    return ret;
}

static __inline__ NVec3i_t NVec3i(int x, int y, int z) {
    NVec3i_t ret = {{x, y, z}};
    return ret;
}

static __inline__ NVec2i_t NVec3i_2i(NVec3i_t o) {
    NVec2i_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec2f_t NVec3i_2f(NVec3i_t o) {
    NVec2f_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec3f_t NVec3i_3f(NVec3i_t o) {
    NVec3f_t ret = {{o.v[0], o.v[1], o.v[2]}};
    return ret;
}

static __inline__ NVec4i_t NVec3i_4i(NVec3i_t o) {
    NVec4i_t ret = {{o.v[0], o.v[1], o.v[2], 0}};
    return ret;
}

static __inline__ NVec4f_t NVec3i_4f(NVec3i_t o) {
    NVec4f_t ret = {{o.v[0], o.v[1], o.v[2], 0}};
    return ret;
}

static __inline__ NMat3i_t NMat3i(int m00, int m01, int m02, int m10, int m11, int m12, int m20, int m21, int m22) {
    NMat3i_t ret = {{m00, m01, m02, m10, m11, m12, m20, m21, m22}};
    return ret;
}

static __inline__ NMat3i_t NMat3i_identity() {
    NMat3i_t ret = {{1, 0, 0, 0, 1, 0, 0, 0, 1}};
    return ret;
}

static __inline__ NMat3i_t NMat3i_rows(int x, int y, int z) {
    NMat3i_t ret = {{x, x, x, y, y, y, z, z, z}};
    return ret;
}

static __inline__ NMat3i_t NMat3i_cols(int x, int y, int z) {
    NMat3i_t ret = {{x, y, z, x, y, z, x, y, z}};
    return ret;
}

static __inline__ NMat2i_t NMat3i_2i(NMat3i_t o) {
    NMat2i_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat2f_t NMat3i_2f(NMat3i_t o) {
    NMat2f_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat3f_t NMat3i_3f(NMat3i_t o) {
    NMat3f_t ret = {{o.m00, o.m01, o.m02, o.m10, o.m11, o.m12, o.m20, o.m21, o.m22}};
    return ret;
}

static __inline__ NMat4i_t NMat3i_4i(NMat3i_t o) {
    NMat4i_t ret = {{o.m00, o.m01, o.m02, 0, o.m10, o.m11, o.m12, 0, o.m20, o.m21, o.m22, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat4f_t NMat3i_4f(NMat3i_t o) {
    NMat4f_t ret = {{o.m00, o.m01, o.m02, 0, o.m10, o.m11, o.m12, 0, o.m20, o.m21, o.m22, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_neg(NVec3i_t v1) {
    NVec3i_t ret = {{-v1.x, -v1.y, -v1.z}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_add(NVec3i_t v1, NVec3i_t v2) {
    NVec3i_t ret = {{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_adds(NVec3i_t v1, int s) {
    NVec3i_t ret = {{v1.x + s, v1.y + s, v1.z + s}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_sub(NVec3i_t v1, NVec3i_t v2) {
    NVec3i_t ret = {{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_subs(NVec3i_t v1, int s) {
    NVec3i_t ret = {{v1.x - s, v1.y - s, v1.z - s}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_mul(NVec3i_t v1, NVec3i_t v2) {
    NVec3i_t ret = {{v1.x * v2.x, v1.y * v2.y, v1.z * v2.z}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_muls(NVec3i_t v1, int s) {
    NVec3i_t ret = {{v1.x * s, v1.y * s, v1.z * s}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_div(NVec3i_t v1, NVec3i_t v2) {
    NVec3i_t ret = {{v1.x / v2.x, v1.y / v2.y, v1.z / v2.z}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_divs(NVec3i_t v1, int s) {
    float f = 1. / s;
    NVec3i_t ret = {{v1.x * f, v1.y * f, v1.z * f}};
    return ret;
}

static __inline__ int NVec3i_dot(NVec3i_t v1, NVec3i_t v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

static __inline__ float NVec3i_len(NVec3i_t v1) {
    return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
}

static __inline__ NVec3i_t NVec3i_norm(NVec3i_t v1) {
    float scale = 1.f / NVec3i_len(v1);
    NVec3i_t ret = {{v1.x * scale, v1.y * scale, v1.z * scale}};
    return ret;
}

static __inline__ NVec3i_t NVec3i_cross(NVec3i_t v1, NVec3i_t v2) {
    return (NVec3i_t) {{
        v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]
    }};
}

static __inline__ NVec3i_t NVec3i_proj(NVec3i_t v1, NVec3i_t v2) {
    float scale = NVec3i_dot(v2, v1) / NVec3i_dot(v2, v2);
    NVec3i_t ret = NVec3i_muls(v2, scale);
    return ret;
}

static __inline__ NMat3i_t NMat3i_add(NMat3i_t m1, NMat3i_t m2) {
    NMat3i_t ret = (NMat3i_t) {{m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m02 + m2.m02, m1.m10 + m2.m10, m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m20 + m2.m20, m1.m21 + m2.m21, m1.m22 + m2.m22}};
    return ret;
}

static __inline__ NMat3i_t NMat3i_sub(NMat3i_t m1, NMat3i_t m2) {
    NMat3i_t ret = (NMat3i_t) {{m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m02 - m2.m02, m1.m10 - m2.m10, m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m20 - m2.m20, m1.m21 - m2.m21, m1.m22 - m2.m22}};
    return ret;
}

static __inline__ NMat3i_t NMat3i_mul(NMat3i_t m1, NMat3i_t m2) {
    NMat3i_t ret = (NMat3i_t) {{
        m1.m00 * m2.m00 + m1.m10 * m2.m01 + m1.m20 * m2.m02,
        m1.m01 * m2.m00 + m1.m11 * m2.m01 + m1.m21 * m2.m02,
        m1.m02 * m2.m00 + m1.m12 * m2.m01 + m1.m22 * m2.m02,
        m1.m00 * m2.m10 + m1.m10 * m2.m11 + m1.m20 * m2.m12,
        m1.m01 * m2.m10 + m1.m11 * m2.m11 + m1.m21 * m2.m12,
        m1.m02 * m2.m10 + m1.m12 * m2.m11 + m1.m22 * m2.m12,
        m1.m00 * m2.m20 + m1.m10 * m2.m21 + m1.m20 * m2.m22,
        m1.m01 * m2.m20 + m1.m11 * m2.m21 + m1.m21 * m2.m22,
        m1.m02 * m2.m20 + m1.m12 * m2.m21 + m1.m22 * m2.m22
    }};
    return ret;
}

static __inline__ NMat3i_t NMat3i_scale_3i(NMat3i_t m1, NVec3i_t v1) {
    return (NMat3i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_scale_3f(NMat3i_t m1, NVec3f_t v1) {
    return (NMat3i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_scale_4i(NMat3i_t m1, NVec4i_t v1) {
    return (NMat3i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_scale_4f(NMat3i_t m1, NVec4f_t v1) {
    return (NMat3i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_rotation_3i(float radians, NVec3i_t v1) {
    NVec3i_t v1_norm = NVec3i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_rotation_3f(float radians, NVec3f_t v1) {
    NVec3f_t v1_norm = NVec3f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_rotation_4i(float radians, NVec4i_t v1) {
    NVec4i_t v1_norm = NVec4i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_rotation_4f(float radians, NVec4f_t v1) {
    NVec4f_t v1_norm = NVec4f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3i_t NMat3i_rotate_3i(NMat3i_t m1, float radians, NVec3i_t v1) {
    return NMat3i_mul(m1, NMat3i_rotation_3i(radians, v1));
}

static __inline__ NMat3i_t NMat3i_rotate_3f(NMat3i_t m1, float radians, NVec3f_t v1) {
    return NMat3i_mul(m1, NMat3i_rotation_3f(radians, v1));
}

static __inline__ NMat3i_t NMat3i_rotate_4i(NMat3i_t m1, float radians, NVec4i_t v1) {
    return NMat3i_mul(m1, NMat3i_rotation_4i(radians, v1));
}

static __inline__ NMat3i_t NMat3i_rotate_4f(NMat3i_t m1, float radians, NVec4f_t v1) {
    return NMat3i_mul(m1, NMat3i_rotation_4f(radians, v1));
}

static __inline__ NVec3f_t NVec3f(float x, float y, float z) {
    NVec3f_t ret = {{x, y, z}};
    return ret;
}

static __inline__ NVec2i_t NVec3f_2i(NVec3f_t o) {
    NVec2i_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec2f_t NVec3f_2f(NVec3f_t o) {
    NVec2f_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec3i_t NVec3f_3i(NVec3f_t o) {
    NVec3i_t ret = {{o.v[0], o.v[1], o.v[2]}};
    return ret;
}

static __inline__ NVec4i_t NVec3f_4i(NVec3f_t o) {
    NVec4i_t ret = {{o.v[0], o.v[1], o.v[2], 0}};
    return ret;
}

static __inline__ NVec4f_t NVec3f_4f(NVec3f_t o) {
    NVec4f_t ret = {{o.v[0], o.v[1], o.v[2], 0}};
    return ret;
}

static __inline__ NMat3f_t NMat3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
    NMat3f_t ret = {{m00, m01, m02, m10, m11, m12, m20, m21, m22}};
    return ret;
}

static __inline__ NMat3f_t NMat3f_identity() {
    NMat3f_t ret = {{1, 0, 0, 0, 1, 0, 0, 0, 1}};
    return ret;
}

static __inline__ NMat3f_t NMat3f_rows(float x, float y, float z) {
    NMat3f_t ret = {{x, x, x, y, y, y, z, z, z}};
    return ret;
}

static __inline__ NMat3f_t NMat3f_cols(float x, float y, float z) {
    NMat3f_t ret = {{x, y, z, x, y, z, x, y, z}};
    return ret;
}

static __inline__ NMat2i_t NMat3f_2i(NMat3f_t o) {
    NMat2i_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat2f_t NMat3f_2f(NMat3f_t o) {
    NMat2f_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat3i_t NMat3f_3i(NMat3f_t o) {
    NMat3i_t ret = {{o.m00, o.m01, o.m02, o.m10, o.m11, o.m12, o.m20, o.m21, o.m22}};
    return ret;
}

static __inline__ NMat4i_t NMat3f_4i(NMat3f_t o) {
    NMat4i_t ret = {{o.m00, o.m01, o.m02, 0, o.m10, o.m11, o.m12, 0, o.m20, o.m21, o.m22, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NMat4f_t NMat3f_4f(NMat3f_t o) {
    NMat4f_t ret = {{o.m00, o.m01, o.m02, 0, o.m10, o.m11, o.m12, 0, o.m20, o.m21, o.m22, 0, 0, 0, 0, 0}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_neg(NVec3f_t v1) {
    NVec3f_t ret = {{-v1.x, -v1.y, -v1.z}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_add(NVec3f_t v1, NVec3f_t v2) {
    NVec3f_t ret = {{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_adds(NVec3f_t v1, float s) {
    NVec3f_t ret = {{v1.x + s, v1.y + s, v1.z + s}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_sub(NVec3f_t v1, NVec3f_t v2) {
    NVec3f_t ret = {{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_subs(NVec3f_t v1, float s) {
    NVec3f_t ret = {{v1.x - s, v1.y - s, v1.z - s}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_mul(NVec3f_t v1, NVec3f_t v2) {
    NVec3f_t ret = {{v1.x * v2.x, v1.y * v2.y, v1.z * v2.z}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_muls(NVec3f_t v1, float s) {
    NVec3f_t ret = {{v1.x * s, v1.y * s, v1.z * s}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_div(NVec3f_t v1, NVec3f_t v2) {
    NVec3f_t ret = {{v1.x / v2.x, v1.y / v2.y, v1.z / v2.z}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_divs(NVec3f_t v1, float s) {
    float f = 1. / s;
    NVec3f_t ret = {{v1.x * f, v1.y * f, v1.z * f}};
    return ret;
}

static __inline__ float NVec3f_dot(NVec3f_t v1, NVec3f_t v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

static __inline__ float NVec3f_len(NVec3f_t v1) {
    return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
}

static __inline__ NVec3f_t NVec3f_norm(NVec3f_t v1) {
    float scale = 1.f / NVec3f_len(v1);
    NVec3f_t ret = {{v1.x * scale, v1.y * scale, v1.z * scale}};
    return ret;
}

static __inline__ NVec3f_t NVec3f_cross(NVec3f_t v1, NVec3f_t v2) {
    return (NVec3f_t) {{
        v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]
    }};
}

static __inline__ NVec3f_t NVec3f_proj(NVec3f_t v1, NVec3f_t v2) {
    float scale = NVec3f_dot(v2, v1) / NVec3f_dot(v2, v2);
    NVec3f_t ret = NVec3f_muls(v2, scale);
    return ret;
}

static __inline__ NMat3f_t NMat3f_add(NMat3f_t m1, NMat3f_t m2) {
    NMat3f_t ret = (NMat3f_t) {{m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m02 + m2.m02, m1.m10 + m2.m10, m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m20 + m2.m20, m1.m21 + m2.m21, m1.m22 + m2.m22}};
    return ret;
}

static __inline__ NMat3f_t NMat3f_sub(NMat3f_t m1, NMat3f_t m2) {
    NMat3f_t ret = (NMat3f_t) {{m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m02 - m2.m02, m1.m10 - m2.m10, m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m20 - m2.m20, m1.m21 - m2.m21, m1.m22 - m2.m22}};
    return ret;
}

static __inline__ NMat3f_t NMat3f_mul(NMat3f_t m1, NMat3f_t m2) {
    NMat3f_t ret = (NMat3f_t) {{
        m1.m00 * m2.m00 + m1.m10 * m2.m01 + m1.m20 * m2.m02,
        m1.m01 * m2.m00 + m1.m11 * m2.m01 + m1.m21 * m2.m02,
        m1.m02 * m2.m00 + m1.m12 * m2.m01 + m1.m22 * m2.m02,
        m1.m00 * m2.m10 + m1.m10 * m2.m11 + m1.m20 * m2.m12,
        m1.m01 * m2.m10 + m1.m11 * m2.m11 + m1.m21 * m2.m12,
        m1.m02 * m2.m10 + m1.m12 * m2.m11 + m1.m22 * m2.m12,
        m1.m00 * m2.m20 + m1.m10 * m2.m21 + m1.m20 * m2.m22,
        m1.m01 * m2.m20 + m1.m11 * m2.m21 + m1.m21 * m2.m22,
        m1.m02 * m2.m20 + m1.m12 * m2.m21 + m1.m22 * m2.m22
    }};
    return ret;
}

static __inline__ NMat3f_t NMat3f_scale_3i(NMat3f_t m1, NVec3i_t v1) {
    return (NMat3f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_scale_3f(NMat3f_t m1, NVec3f_t v1) {
    return (NMat3f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_scale_4i(NMat3f_t m1, NVec4i_t v1) {
    return (NMat3f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_scale_4f(NMat3f_t m1, NVec4f_t v1) {
    return (NMat3f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_rotation_3i(float radians, NVec3i_t v1) {
    NVec3i_t v1_norm = NVec3i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_rotation_3f(float radians, NVec3f_t v1) {
    NVec3f_t v1_norm = NVec3f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_rotation_4i(float radians, NVec4i_t v1) {
    NVec4i_t v1_norm = NVec4i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_rotation_4f(float radians, NVec4f_t v1) {
    NVec4f_t v1_norm = NVec4f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat3f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]
    }};
}

static __inline__ NMat3f_t NMat3f_rotate_3i(NMat3f_t m1, float radians, NVec3i_t v1) {
    return NMat3f_mul(m1, NMat3f_rotation_3i(radians, v1));
}

static __inline__ NMat3f_t NMat3f_rotate_3f(NMat3f_t m1, float radians, NVec3f_t v1) {
    return NMat3f_mul(m1, NMat3f_rotation_3f(radians, v1));
}

static __inline__ NMat3f_t NMat3f_rotate_4i(NMat3f_t m1, float radians, NVec4i_t v1) {
    return NMat3f_mul(m1, NMat3f_rotation_4i(radians, v1));
}

static __inline__ NMat3f_t NMat3f_rotate_4f(NMat3f_t m1, float radians, NVec4f_t v1) {
    return NMat3f_mul(m1, NMat3f_rotation_4f(radians, v1));
}

static __inline__ NVec4i_t NVec4i(int x, int y, int z, int w) {
    NVec4i_t ret = {{x, y, z, w}};
    return ret;
}

static __inline__ NVec2i_t NVec4i_2i(NVec4i_t o) {
    NVec2i_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec2f_t NVec4i_2f(NVec4i_t o) {
    NVec2f_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec3i_t NVec4i_3i(NVec4i_t o) {
    NVec3i_t ret = {{o.v[0], o.v[1], o.v[2]}};
    return ret;
}

static __inline__ NVec3f_t NVec4i_3f(NVec4i_t o) {
    NVec3f_t ret = {{o.v[0], o.v[1], o.v[2]}};
    return ret;
}

static __inline__ NVec4f_t NVec4i_4f(NVec4i_t o) {
    NVec4f_t ret = {{o.v[0], o.v[1], o.v[2], o.v[3]}};
    return ret;
}

static __inline__ NMat4i_t NMat4i(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13, int m20, int m21, int m22, int m23, int m30, int m31, int m32, int m33) {
    NMat4i_t ret = {{m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33}};
    return ret;
}

static __inline__ NMat4i_t NMat4i_identity() {
    NMat4i_t ret = {{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
    return ret;
}

static __inline__ NMat4i_t NMat4i_rows(int x, int y, int z, int w) {
    NMat4i_t ret = {{x, x, x, x, y, y, y, y, z, z, z, z, w, w, w, w}};
    return ret;
}

static __inline__ NMat4i_t NMat4i_cols(int x, int y, int z, int w) {
    NMat4i_t ret = {{x, y, z, w, x, y, z, w, x, y, z, w, x, y, z, w}};
    return ret;
}

static __inline__ NMat2i_t NMat4i_2i(NMat4i_t o) {
    NMat2i_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat2f_t NMat4i_2f(NMat4i_t o) {
    NMat2f_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat3i_t NMat4i_3i(NMat4i_t o) {
    NMat3i_t ret = {{o.m00, o.m01, o.m02, o.m10, o.m11, o.m12, o.m20, o.m21, o.m22}};
    return ret;
}

static __inline__ NMat3f_t NMat4i_3f(NMat4i_t o) {
    NMat3f_t ret = {{o.m00, o.m01, o.m02, o.m10, o.m11, o.m12, o.m20, o.m21, o.m22}};
    return ret;
}

static __inline__ NMat4f_t NMat4i_4f(NMat4i_t o) {
    NMat4f_t ret = {{o.m00, o.m01, o.m02, o.m03, o.m10, o.m11, o.m12, o.m13, o.m20, o.m21, o.m22, o.m23, o.m30, o.m31, o.m32, o.m33}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_neg(NVec4i_t v1) {
    NVec4i_t ret = {{-v1.x, -v1.y, -v1.z, -v1.w}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_add(NVec4i_t v1, NVec4i_t v2) {
    NVec4i_t ret = {{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_adds(NVec4i_t v1, int s) {
    NVec4i_t ret = {{v1.x + s, v1.y + s, v1.z + s, v1.w + s}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_sub(NVec4i_t v1, NVec4i_t v2) {
    NVec4i_t ret = {{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_subs(NVec4i_t v1, int s) {
    NVec4i_t ret = {{v1.x - s, v1.y - s, v1.z - s, v1.w - s}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_mul(NVec4i_t v1, NVec4i_t v2) {
    NVec4i_t ret = {{v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_muls(NVec4i_t v1, int s) {
    NVec4i_t ret = {{v1.x * s, v1.y * s, v1.z * s, v1.w * s}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_div(NVec4i_t v1, NVec4i_t v2) {
    NVec4i_t ret = {{v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_divs(NVec4i_t v1, int s) {
    float f = 1. / s;
    NVec4i_t ret = {{v1.x * f, v1.y * f, v1.z * f, v1.w * f}};
    return ret;
}

static __inline__ int NVec4i_dot(NVec4i_t v1, NVec4i_t v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

static __inline__ float NVec4i_len(NVec4i_t v1) {
    return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w);
}

static __inline__ NVec4i_t NVec4i_norm(NVec4i_t v1) {
    float scale = 1.f / NVec4i_len(v1);
    NVec4i_t ret = {{v1.x * scale, v1.y * scale, v1.z * scale, v1.w * scale}};
    return ret;
}

static __inline__ NVec4i_t NVec4i_cross(NVec4i_t v1, NVec4i_t v2) {
    return (NVec4i_t) {{
        v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0],
        0
    }};
}

static __inline__ NVec4i_t NVec4i_proj(NVec4i_t v1, NVec4i_t v2) {
    float scale = NVec4i_dot(v2, v1) / NVec4i_dot(v2, v2);
    NVec4i_t ret = NVec4i_muls(v2, scale);
    return ret;
}

static __inline__ NMat4i_t NMat4i_add(NMat4i_t m1, NMat4i_t m2) {
    NMat4i_t ret = (NMat4i_t) {{m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m02 + m2.m02, m1.m03 + m2.m03, m1.m10 + m2.m10, m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m13 + m2.m13, m1.m20 + m2.m20, m1.m21 + m2.m21, m1.m22 + m2.m22, m1.m23 + m2.m23, m1.m30 + m2.m30, m1.m31 + m2.m31, m1.m32 + m2.m32, m1.m33 + m2.m33}};
    return ret;
}

static __inline__ NMat4i_t NMat4i_sub(NMat4i_t m1, NMat4i_t m2) {
    NMat4i_t ret = (NMat4i_t) {{m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m02 - m2.m02, m1.m03 - m2.m03, m1.m10 - m2.m10, m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m13 - m2.m13, m1.m20 - m2.m20, m1.m21 - m2.m21, m1.m22 - m2.m22, m1.m23 - m2.m23, m1.m30 - m2.m30, m1.m31 - m2.m31, m1.m32 - m2.m32, m1.m33 - m2.m33}};
    return ret;
}

static __inline__ NMat4i_t NMat4i_mul(NMat4i_t m1, NMat4i_t m2) {
    NMat4i_t ret = (NMat4i_t) {{
        m1.m00 * m2.m00 + m1.m10 * m2.m01 + m1.m20 * m2.m02 + m1.m30 * m2.m03,
        m1.m01 * m2.m00 + m1.m11 * m2.m01 + m1.m21 * m2.m02 + m1.m31 * m2.m03,
        m1.m02 * m2.m00 + m1.m12 * m2.m01 + m1.m22 * m2.m02 + m1.m32 * m2.m03,
        m1.m03 * m2.m00 + m1.m13 * m2.m01 + m1.m23 * m2.m02 + m1.m33 * m2.m03,
        m1.m00 * m2.m10 + m1.m10 * m2.m11 + m1.m20 * m2.m12 + m1.m30 * m2.m13,
        m1.m01 * m2.m10 + m1.m11 * m2.m11 + m1.m21 * m2.m12 + m1.m31 * m2.m13,
        m1.m02 * m2.m10 + m1.m12 * m2.m11 + m1.m22 * m2.m12 + m1.m32 * m2.m13,
        m1.m03 * m2.m10 + m1.m13 * m2.m11 + m1.m23 * m2.m12 + m1.m33 * m2.m13,
        m1.m00 * m2.m20 + m1.m10 * m2.m21 + m1.m20 * m2.m22 + m1.m30 * m2.m23,
        m1.m01 * m2.m20 + m1.m11 * m2.m21 + m1.m21 * m2.m22 + m1.m31 * m2.m23,
        m1.m02 * m2.m20 + m1.m12 * m2.m21 + m1.m22 * m2.m22 + m1.m32 * m2.m23,
        m1.m03 * m2.m20 + m1.m13 * m2.m21 + m1.m23 * m2.m22 + m1.m33 * m2.m23,
        m1.m00 * m2.m30 + m1.m10 * m2.m31 + m1.m20 * m2.m32 + m1.m30 * m2.m33,
        m1.m01 * m2.m30 + m1.m11 * m2.m31 + m1.m21 * m2.m32 + m1.m31 * m2.m33,
        m1.m02 * m2.m30 + m1.m12 * m2.m31 + m1.m22 * m2.m32 + m1.m32 * m2.m33,
        m1.m03 * m2.m30 + m1.m13 * m2.m31 + m1.m23 * m2.m32 + m1.m33 * m2.m33
    }};
    return ret;
}

static __inline__ NMat4i_t NMat4i_scale_3i(NMat4i_t m1, NVec3i_t v1) {
    return (NMat4i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4i_t NMat4i_scale_3f(NMat4i_t m1, NVec3f_t v1) {
    return (NMat4i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4i_t NMat4i_scale_4i(NMat4i_t m1, NVec4i_t v1) {
    return (NMat4i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4i_t NMat4i_scale_4f(NMat4i_t m1, NVec4f_t v1) {
    return (NMat4i_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4i_t NMat4i_rotation_3i(float radians, NVec3i_t v1) {
    NVec3i_t v1_norm = NVec3i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4i_t NMat4i_rotation_3f(float radians, NVec3f_t v1) {
    NVec3f_t v1_norm = NVec3f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4i_t NMat4i_rotation_4i(float radians, NVec4i_t v1) {
    NVec4i_t v1_norm = NVec4i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4i_t NMat4i_rotation_4f(float radians, NVec4f_t v1) {
    NVec4f_t v1_norm = NVec4f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4i_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4i_t NMat4i_rotate_3i(NMat4i_t m1, float radians, NVec3i_t v1) {
    return NMat4i_mul(m1, NMat4i_rotation_3i(radians, v1));
}

static __inline__ NMat4i_t NMat4i_rotate_3f(NMat4i_t m1, float radians, NVec3f_t v1) {
    return NMat4i_mul(m1, NMat4i_rotation_3f(radians, v1));
}

static __inline__ NMat4i_t NMat4i_rotate_4i(NMat4i_t m1, float radians, NVec4i_t v1) {
    return NMat4i_mul(m1, NMat4i_rotation_4i(radians, v1));
}

static __inline__ NMat4i_t NMat4i_rotate_4f(NMat4i_t m1, float radians, NVec4f_t v1) {
    return NMat4i_mul(m1, NMat4i_rotation_4f(radians, v1));
}

static __inline__ NVec4f_t NVec4f(float x, float y, float z, float w) {
    NVec4f_t ret = {{x, y, z, w}};
    return ret;
}

static __inline__ NVec2i_t NVec4f_2i(NVec4f_t o) {
    NVec2i_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec2f_t NVec4f_2f(NVec4f_t o) {
    NVec2f_t ret = {{o.v[0], o.v[1]}};
    return ret;
}

static __inline__ NVec3i_t NVec4f_3i(NVec4f_t o) {
    NVec3i_t ret = {{o.v[0], o.v[1], o.v[2]}};
    return ret;
}

static __inline__ NVec3f_t NVec4f_3f(NVec4f_t o) {
    NVec3f_t ret = {{o.v[0], o.v[1], o.v[2]}};
    return ret;
}

static __inline__ NVec4i_t NVec4f_4i(NVec4f_t o) {
    NVec4i_t ret = {{o.v[0], o.v[1], o.v[2], o.v[3]}};
    return ret;
}

static __inline__ NMat4f_t NMat4f(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) {
    NMat4f_t ret = {{m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33}};
    return ret;
}

static __inline__ NMat4f_t NMat4f_identity() {
    NMat4f_t ret = {{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
    return ret;
}

static __inline__ NMat4f_t NMat4f_rows(float x, float y, float z, float w) {
    NMat4f_t ret = {{x, x, x, x, y, y, y, y, z, z, z, z, w, w, w, w}};
    return ret;
}

static __inline__ NMat4f_t NMat4f_cols(float x, float y, float z, float w) {
    NMat4f_t ret = {{x, y, z, w, x, y, z, w, x, y, z, w, x, y, z, w}};
    return ret;
}

static __inline__ NMat2i_t NMat4f_2i(NMat4f_t o) {
    NMat2i_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat2f_t NMat4f_2f(NMat4f_t o) {
    NMat2f_t ret = {{o.m00, o.m01, o.m10, o.m11}};
    return ret;
}

static __inline__ NMat3i_t NMat4f_3i(NMat4f_t o) {
    NMat3i_t ret = {{o.m00, o.m01, o.m02, o.m10, o.m11, o.m12, o.m20, o.m21, o.m22}};
    return ret;
}

static __inline__ NMat3f_t NMat4f_3f(NMat4f_t o) {
    NMat3f_t ret = {{o.m00, o.m01, o.m02, o.m10, o.m11, o.m12, o.m20, o.m21, o.m22}};
    return ret;
}

static __inline__ NMat4i_t NMat4f_4i(NMat4f_t o) {
    NMat4i_t ret = {{o.m00, o.m01, o.m02, o.m03, o.m10, o.m11, o.m12, o.m13, o.m20, o.m21, o.m22, o.m23, o.m30, o.m31, o.m32, o.m33}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_neg(NVec4f_t v1) {
    NVec4f_t ret = {{-v1.x, -v1.y, -v1.z, -v1.w}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_add(NVec4f_t v1, NVec4f_t v2) {
    NVec4f_t ret = {{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_adds(NVec4f_t v1, float s) {
    NVec4f_t ret = {{v1.x + s, v1.y + s, v1.z + s, v1.w + s}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_sub(NVec4f_t v1, NVec4f_t v2) {
    NVec4f_t ret = {{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_subs(NVec4f_t v1, float s) {
    NVec4f_t ret = {{v1.x - s, v1.y - s, v1.z - s, v1.w - s}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_mul(NVec4f_t v1, NVec4f_t v2) {
    NVec4f_t ret = {{v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_muls(NVec4f_t v1, float s) {
    NVec4f_t ret = {{v1.x * s, v1.y * s, v1.z * s, v1.w * s}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_div(NVec4f_t v1, NVec4f_t v2) {
    NVec4f_t ret = {{v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_divs(NVec4f_t v1, float s) {
    float f = 1. / s;
    NVec4f_t ret = {{v1.x * f, v1.y * f, v1.z * f, v1.w * f}};
    return ret;
}

static __inline__ float NVec4f_dot(NVec4f_t v1, NVec4f_t v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

static __inline__ float NVec4f_len(NVec4f_t v1) {
    return sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w);
}

static __inline__ NVec4f_t NVec4f_norm(NVec4f_t v1) {
    float scale = 1.f / NVec4f_len(v1);
    NVec4f_t ret = {{v1.x * scale, v1.y * scale, v1.z * scale, v1.w * scale}};
    return ret;
}

static __inline__ NVec4f_t NVec4f_cross(NVec4f_t v1, NVec4f_t v2) {
    return (NVec4f_t) {{
        v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0],
        0
    }};
}

static __inline__ NVec4f_t NVec4f_proj(NVec4f_t v1, NVec4f_t v2) {
    float scale = NVec4f_dot(v2, v1) / NVec4f_dot(v2, v2);
    NVec4f_t ret = NVec4f_muls(v2, scale);
    return ret;
}

static __inline__ NMat4f_t NMat4f_add(NMat4f_t m1, NMat4f_t m2) {
    NMat4f_t ret = (NMat4f_t) {{m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m02 + m2.m02, m1.m03 + m2.m03, m1.m10 + m2.m10, m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m13 + m2.m13, m1.m20 + m2.m20, m1.m21 + m2.m21, m1.m22 + m2.m22, m1.m23 + m2.m23, m1.m30 + m2.m30, m1.m31 + m2.m31, m1.m32 + m2.m32, m1.m33 + m2.m33}};
    return ret;
}

static __inline__ NMat4f_t NMat4f_sub(NMat4f_t m1, NMat4f_t m2) {
    NMat4f_t ret = (NMat4f_t) {{m1.m00 - m2.m00, m1.m01 - m2.m01, m1.m02 - m2.m02, m1.m03 - m2.m03, m1.m10 - m2.m10, m1.m11 - m2.m11, m1.m12 - m2.m12, m1.m13 - m2.m13, m1.m20 - m2.m20, m1.m21 - m2.m21, m1.m22 - m2.m22, m1.m23 - m2.m23, m1.m30 - m2.m30, m1.m31 - m2.m31, m1.m32 - m2.m32, m1.m33 - m2.m33}};
    return ret;
}

static __inline__ NMat4f_t NMat4f_mul(NMat4f_t m1, NMat4f_t m2) {
    NMat4f_t ret = (NMat4f_t) {{
        m1.m00 * m2.m00 + m1.m10 * m2.m01 + m1.m20 * m2.m02 + m1.m30 * m2.m03,
        m1.m01 * m2.m00 + m1.m11 * m2.m01 + m1.m21 * m2.m02 + m1.m31 * m2.m03,
        m1.m02 * m2.m00 + m1.m12 * m2.m01 + m1.m22 * m2.m02 + m1.m32 * m2.m03,
        m1.m03 * m2.m00 + m1.m13 * m2.m01 + m1.m23 * m2.m02 + m1.m33 * m2.m03,
        m1.m00 * m2.m10 + m1.m10 * m2.m11 + m1.m20 * m2.m12 + m1.m30 * m2.m13,
        m1.m01 * m2.m10 + m1.m11 * m2.m11 + m1.m21 * m2.m12 + m1.m31 * m2.m13,
        m1.m02 * m2.m10 + m1.m12 * m2.m11 + m1.m22 * m2.m12 + m1.m32 * m2.m13,
        m1.m03 * m2.m10 + m1.m13 * m2.m11 + m1.m23 * m2.m12 + m1.m33 * m2.m13,
        m1.m00 * m2.m20 + m1.m10 * m2.m21 + m1.m20 * m2.m22 + m1.m30 * m2.m23,
        m1.m01 * m2.m20 + m1.m11 * m2.m21 + m1.m21 * m2.m22 + m1.m31 * m2.m23,
        m1.m02 * m2.m20 + m1.m12 * m2.m21 + m1.m22 * m2.m22 + m1.m32 * m2.m23,
        m1.m03 * m2.m20 + m1.m13 * m2.m21 + m1.m23 * m2.m22 + m1.m33 * m2.m23,
        m1.m00 * m2.m30 + m1.m10 * m2.m31 + m1.m20 * m2.m32 + m1.m30 * m2.m33,
        m1.m01 * m2.m30 + m1.m11 * m2.m31 + m1.m21 * m2.m32 + m1.m31 * m2.m33,
        m1.m02 * m2.m30 + m1.m12 * m2.m31 + m1.m22 * m2.m32 + m1.m32 * m2.m33,
        m1.m03 * m2.m30 + m1.m13 * m2.m31 + m1.m23 * m2.m32 + m1.m33 * m2.m33
    }};
    return ret;
}

static __inline__ NMat4f_t NMat4f_scale_3i(NMat4f_t m1, NVec3i_t v1) {
    return (NMat4f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4f_t NMat4f_scale_3f(NMat4f_t m1, NVec3f_t v1) {
    return (NMat4f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4f_t NMat4f_scale_4i(NMat4f_t m1, NVec4i_t v1) {
    return (NMat4f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4f_t NMat4f_scale_4f(NMat4f_t m1, NVec4f_t v1) {
    return (NMat4f_t) {{
        m1.m00 * v1.v[0], m1.m01 * v1.v[0], m1.m02 * v1.v[0], m1.m03 * v1.v[0], 
        m1.m10 * v1.v[1], m1.m11 * v1.v[1], m1.m12 * v1.v[1], m1.m13 * v1.v[1], 
        m1.m20 * v1.v[2], m1.m21 * v1.v[2], m1.m22 * v1.v[2], m1.m23 * v1.v[2], 
        m1.m30, m1.m31, m1.m32, m1.m33
    }};
}

static __inline__ NMat4f_t NMat4f_rotation_3i(float radians, NVec3i_t v1) {
    NVec3i_t v1_norm = NVec3i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4f_t NMat4f_rotation_3f(float radians, NVec3f_t v1) {
    NVec3f_t v1_norm = NVec3f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4f_t NMat4f_rotation_4i(float radians, NVec4i_t v1) {
    NVec4i_t v1_norm = NVec4i_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    int v01 = v1_norm.v[0] * v1_norm.v[1];
    int v02 = v1_norm.v[0] * v1_norm.v[2];
    int v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4f_t NMat4f_rotation_4f(float radians, NVec4f_t v1) {
    NVec4f_t v1_norm = NVec4f_norm(v1);
    float radcos = cosf(radians);
    float invradcos = 1.f / radcos;
    float radsin = sinf(radians);
    float v01 = v1_norm.v[0] * v1_norm.v[1];
    float v02 = v1_norm.v[0] * v1_norm.v[2];
    float v12 = v1_norm.v[1] * v1_norm.v[2];
    return (NMat4f_t) {{
        radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], invradcos * v01 + v1_norm.v[2] * radsin, invradcos * v02 - v1_norm.v[1] * radsin, 0.f,
        invradcos * v01 - v1_norm.v[2] * radsin, radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], invradcos * v12 + v1_norm.v[0] * radsin, 0.f,
        invradcos * v02 + v1_norm.v[1] * radsin, invradcos * v12 - v1_norm.v[0] * radsin, radcos + invradcos * v1_norm.v[2] * v1_norm.v[2], 0.f,
        0.f, 0.f, 0.f, 1.f
    }};
}

static __inline__ NMat4f_t NMat4f_rotate_3i(NMat4f_t m1, float radians, NVec3i_t v1) {
    return NMat4f_mul(m1, NMat4f_rotation_3i(radians, v1));
}

static __inline__ NMat4f_t NMat4f_rotate_3f(NMat4f_t m1, float radians, NVec3f_t v1) {
    return NMat4f_mul(m1, NMat4f_rotation_3f(radians, v1));
}

static __inline__ NMat4f_t NMat4f_rotate_4i(NMat4f_t m1, float radians, NVec4i_t v1) {
    return NMat4f_mul(m1, NMat4f_rotation_4i(radians, v1));
}

static __inline__ NMat4f_t NMat4f_rotate_4f(NMat4f_t m1, float radians, NVec4f_t v1) {
    return NMat4f_mul(m1, NMat4f_rotation_4f(radians, v1));
}

static __inline__ NMat4f_t NMat4f_translate_3i(NMat4f_t m1, NVec3i_t v1) {
    return (NMat4f_t) {{
        m1.m00, m1.m01, m1.m02, m1.m03,
        m1.m10, m1.m11, m1.m12, m1.m13,
        m1.m20, m1.m21, m1.m22, m1.m23,
        m1.m00 * v1.x + m1.m10 * v1.y + m1.m20 * v1.z + m1.m30,
        m1.m01 * v1.x + m1.m11 * v1.y + m1.m21 * v1.z + m1.m31,
        m1.m02 * v1.x + m1.m12 * v1.y + m1.m22 * v1.z + m1.m32,
        m1.m33
    }};
}

static __inline__ NMat4f_t NMat4f_translate_3f(NMat4f_t m1, NVec3f_t v1) {
    return (NMat4f_t) {{
        m1.m00, m1.m01, m1.m02, m1.m03,
        m1.m10, m1.m11, m1.m12, m1.m13,
        m1.m20, m1.m21, m1.m22, m1.m23,
        m1.m00 * v1.x + m1.m10 * v1.y + m1.m20 * v1.z + m1.m30,
        m1.m01 * v1.x + m1.m11 * v1.y + m1.m21 * v1.z + m1.m31,
        m1.m02 * v1.x + m1.m12 * v1.y + m1.m22 * v1.z + m1.m32,
        m1.m33
    }};
}

static __inline__ NMat4f_t NMat4f_perspective(float fov_rad, float aspect, float nearZ, float farZ) {
    float arctan = 1.f / tanf(fov_rad / 2.f);
    float invnf = 1.f / (nearZ - farZ);
    return (NMat4f_t) {{
        arctan / aspect, 0.f, 0.f, 0.f,
        0.f, arctan, 0.f, 0.f,
        0.f, 0.f, (farZ + nearZ) * invnf, -1.f,
        0.f, 0.f, (2.f * farZ * nearZ) * invnf, 0.f
    }};
}

static __inline__ NMat4f_t NMat4f_frustum(float left, float right, float bottom, float top, float nearZ, float farZ) {
    float invrl = 1.f / (right - left);
    float invtb = 1.f / (top - bottom);
    float invfn = 1.f / (farZ - nearZ);
    float _2n    = 2.f * nearZ;
    return (NMat4f_t) {{
        _2n * invrl, 0.f, 0.f, 0.f,
        0.f, _2n * invtb, 0.f, 0.f,
        (right + left) * invrl, (top + bottom) * invtb, -(farZ + nearZ) * invfn, -1.f,
        0.f, 0.f, (-_2n * farZ) * invfn, 0.f
    }};
}

static __inline__ NMat4f_t NMat4f_ortho(float left, float right, float bottom, float top, float nearZ, float farZ) {
    float invrl = 1.f / (right - left);
    float invtb = 1.f / (top - bottom);
    float invfn = 1.f / (farZ - nearZ);
    return (NMat4f_t) {{
        2.f * invrl, 0.f, 0.f, 0.f,
        0.f, 2.f * invtb, 0.f, 0.f,
        0.f, 0.f, -2.f * invfn, 0.f,
        -(right + left) * invrl, -(top + bottom) * invtb, -(farZ + nearZ) * invfn, 1.f
    }};
}

#endif
