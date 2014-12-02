/* Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>
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

#ifndef _NME_VECTYPES_H
#define _NME_VECTYPES_H

union _NVec2i_t {
    struct {
        int x;
        int y;
    };
    struct {
        int r;
        int g;
    };
    struct {
        int s;
        int t;
    };
    int v[2];
};
typedef union _NVec2i_t NVec2i_t;

extern NVec2i_t NVec2i0;

union _NMat2i_t {
    struct {
        int m00;
        int m01;
        int m10;
        int m11;
    };
    int m[4];
    int m2[2][2];
};
typedef union _NMat2i_t NMat2i_t;

union _NVec2f_t {
    struct {
        float x;
        float y;
    };
    struct {
        float r;
        float g;
    };
    struct {
        float s;
        float t;
    };
    float v[2];
};
typedef union _NVec2f_t NVec2f_t;

extern NVec2f_t NVec2f0;

union _NMat2f_t {
    struct {
        float m00;
        float m01;
        float m10;
        float m11;
    };
    float m[4];
    float m2[2][2];
};
typedef union _NMat2f_t NMat2f_t;

union _NVec3i_t {
    struct {
        int x;
        int y;
        int z;
    };
    struct {
        int r;
        int g;
        int b;
    };
    struct {
        int s;
        int t;
        int p;
    };
    int v[3];
};
typedef union _NVec3i_t NVec3i_t;

extern NVec3i_t NVec3i0;

union _NMat3i_t {
    struct {
        int m00;
        int m01;
        int m02;
        int m10;
        int m11;
        int m12;
        int m20;
        int m21;
        int m22;
    };
    int m[9];
    int m3[3][3];
};
typedef union _NMat3i_t NMat3i_t;

union _NVec3f_t {
    struct {
        float x;
        float y;
        float z;
    };
    struct {
        float r;
        float g;
        float b;
    };
    struct {
        float s;
        float t;
        float p;
    };
    float v[3];
};
typedef union _NVec3f_t NVec3f_t;

extern NVec3f_t NVec3f0;

union _NMat3f_t {
    struct {
        float m00;
        float m01;
        float m02;
        float m10;
        float m11;
        float m12;
        float m20;
        float m21;
        float m22;
    };
    float m[9];
    float m3[3][3];
};
typedef union _NMat3f_t NMat3f_t;

union _NVec4i_t {
    struct {
        int x;
        int y;
        int z;
        int w;
    };
    struct {
        int r;
        int g;
        int b;
        int a;
    };
    struct {
        int s;
        int t;
        int p;
        int q;
    };
    int v[4];
};
typedef union _NVec4i_t NVec4i_t;

extern NVec4i_t NVec4i0;

union _NMat4i_t {
    struct {
        int m00;
        int m01;
        int m02;
        int m03;
        int m10;
        int m11;
        int m12;
        int m13;
        int m20;
        int m21;
        int m22;
        int m23;
        int m30;
        int m31;
        int m32;
        int m33;
    };
    int m[16];
    int m4[4][4];
};
typedef union _NMat4i_t NMat4i_t;

union _NVec4f_t {
    struct {
        float x;
        float y;
        float z;
        float w;
    };
    struct {
        float r;
        float g;
        float b;
        float a;
    };
    struct {
        float s;
        float t;
        float p;
        float q;
    };
    float v[4];
};
typedef union _NVec4f_t NVec4f_t;

extern NVec4f_t NVec4f0;

union _NMat4f_t {
    struct {
        float m00;
        float m01;
        float m02;
        float m03;
        float m10;
        float m11;
        float m12;
        float m13;
        float m20;
        float m21;
        float m22;
        float m23;
        float m30;
        float m31;
        float m32;
        float m33;
    };
    float m[16];
    float m4[4][4];
};
typedef union _NMat4f_t NMat4f_t;

#endif
