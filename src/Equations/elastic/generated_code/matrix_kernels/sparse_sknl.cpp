// Copyright (c) 2015, Intel Corporation
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of its contributors
//       may be used to endorse or promote products derived from this software
//       without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// @file
// This file is part of SeisSol.
// 
// @author Alexander Breuer (breuer AT mytum.de, http://www5.in.tum.de/wiki/index.php/Dipl.-Math._Alexander_Breuer)
// @author Alexander Heinecke (alexander.heinecke AT mytum.de, http://www5.in.tum.de/wiki/index.php/Alexander_Heinecke,_M.Sc.,_M.Sc._with_honors)
// 
// @date 2015-05-09 22:17:48.671254
// 
// @section LICENSE
// Copyright (c) 2012-2015, SeisSol Group
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from this
//    software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// 
// @section DESCRIPTION
// Remark: This file was generated.
#ifndef SPARSESKNLCPP
#define SPARSESKNLCPP

#if defined( __SSE3__) || defined(__MIC__)
#include <immintrin.h>
#endif

#include <cstddef>
#ifndef NDEBUG
extern long long libxsmm_num_total_flops;
#endif

void ssparse_starMatrix_m1_n9_k9_ldA16_ldBna2_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
for (unsigned int i = 0; i < 1; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif

}

void ssparse_starMatrix_m4_n9_k9_ldA16_ldBna3_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 4; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif

}

void ssparse_starMatrix_m1_n9_k9_ldA16_ldBna3_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
for (unsigned int i = 0; i < 1; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif

}

void ssparse_starMatrix_m10_n9_k9_ldA16_ldBna4_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 10; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif

}

void ssparse_starMatrix_m4_n9_k9_ldA16_ldBna4_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 4; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif

}

void ssparse_starMatrix_m1_n9_k9_ldA16_ldBna4_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
for (unsigned int i = 0; i < 1; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif

}

void ssparse_starMatrix_m20_n9_k9_ldA32_ldBna5_ldC32_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 20; i += 1)
{
C[(i)+(0)] += A[(i)+(192)] * values[0];
C[(i)+(0)] += A[(i)+(224)] * values[1];
C[(i)+(0)] += A[(i)+(256)] * values[2];
C[(i)+(32)] += A[(i)+(192)] * values[3];
C[(i)+(32)] += A[(i)+(224)] * values[4];
C[(i)+(32)] += A[(i)+(256)] * values[5];
C[(i)+(64)] += A[(i)+(192)] * values[6];
C[(i)+(64)] += A[(i)+(224)] * values[7];
C[(i)+(64)] += A[(i)+(256)] * values[8];
C[(i)+(96)] += A[(i)+(192)] * values[9];
C[(i)+(96)] += A[(i)+(224)] * values[10];
C[(i)+(128)] += A[(i)+(224)] * values[11];
C[(i)+(128)] += A[(i)+(256)] * values[12];
C[(i)+(160)] += A[(i)+(192)] * values[13];
C[(i)+(160)] += A[(i)+(256)] * values[14];
C[(i)+(192)] += A[(i)+(0)] * values[15];
C[(i)+(192)] += A[(i)+(96)] * values[16];
C[(i)+(192)] += A[(i)+(160)] * values[17];
C[(i)+(224)] += A[(i)+(32)] * values[18];
C[(i)+(224)] += A[(i)+(96)] * values[19];
C[(i)+(224)] += A[(i)+(128)] * values[20];
C[(i)+(256)] += A[(i)+(64)] * values[21];
C[(i)+(256)] += A[(i)+(128)] * values[22];
C[(i)+(256)] += A[(i)+(160)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif

}

void ssparse_starMatrix_m10_n9_k9_ldA16_ldBna5_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 10; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif

}

void ssparse_starMatrix_m4_n9_k9_ldA16_ldBna5_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 4; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif

}

void ssparse_starMatrix_m1_n9_k9_ldA16_ldBna5_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
for (unsigned int i = 0; i < 1; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif

}

void ssparse_starMatrix_m35_n9_k9_ldA48_ldBna6_ldC48_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 35; i += 1)
{
C[(i)+(0)] += A[(i)+(288)] * values[0];
C[(i)+(0)] += A[(i)+(336)] * values[1];
C[(i)+(0)] += A[(i)+(384)] * values[2];
C[(i)+(48)] += A[(i)+(288)] * values[3];
C[(i)+(48)] += A[(i)+(336)] * values[4];
C[(i)+(48)] += A[(i)+(384)] * values[5];
C[(i)+(96)] += A[(i)+(288)] * values[6];
C[(i)+(96)] += A[(i)+(336)] * values[7];
C[(i)+(96)] += A[(i)+(384)] * values[8];
C[(i)+(144)] += A[(i)+(288)] * values[9];
C[(i)+(144)] += A[(i)+(336)] * values[10];
C[(i)+(192)] += A[(i)+(336)] * values[11];
C[(i)+(192)] += A[(i)+(384)] * values[12];
C[(i)+(240)] += A[(i)+(288)] * values[13];
C[(i)+(240)] += A[(i)+(384)] * values[14];
C[(i)+(288)] += A[(i)+(0)] * values[15];
C[(i)+(288)] += A[(i)+(144)] * values[16];
C[(i)+(288)] += A[(i)+(240)] * values[17];
C[(i)+(336)] += A[(i)+(48)] * values[18];
C[(i)+(336)] += A[(i)+(144)] * values[19];
C[(i)+(336)] += A[(i)+(192)] * values[20];
C[(i)+(384)] += A[(i)+(96)] * values[21];
C[(i)+(384)] += A[(i)+(192)] * values[22];
C[(i)+(384)] += A[(i)+(240)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 1680;
#endif

}

void ssparse_starMatrix_m20_n9_k9_ldA32_ldBna6_ldC32_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 20; i += 1)
{
C[(i)+(0)] += A[(i)+(192)] * values[0];
C[(i)+(0)] += A[(i)+(224)] * values[1];
C[(i)+(0)] += A[(i)+(256)] * values[2];
C[(i)+(32)] += A[(i)+(192)] * values[3];
C[(i)+(32)] += A[(i)+(224)] * values[4];
C[(i)+(32)] += A[(i)+(256)] * values[5];
C[(i)+(64)] += A[(i)+(192)] * values[6];
C[(i)+(64)] += A[(i)+(224)] * values[7];
C[(i)+(64)] += A[(i)+(256)] * values[8];
C[(i)+(96)] += A[(i)+(192)] * values[9];
C[(i)+(96)] += A[(i)+(224)] * values[10];
C[(i)+(128)] += A[(i)+(224)] * values[11];
C[(i)+(128)] += A[(i)+(256)] * values[12];
C[(i)+(160)] += A[(i)+(192)] * values[13];
C[(i)+(160)] += A[(i)+(256)] * values[14];
C[(i)+(192)] += A[(i)+(0)] * values[15];
C[(i)+(192)] += A[(i)+(96)] * values[16];
C[(i)+(192)] += A[(i)+(160)] * values[17];
C[(i)+(224)] += A[(i)+(32)] * values[18];
C[(i)+(224)] += A[(i)+(96)] * values[19];
C[(i)+(224)] += A[(i)+(128)] * values[20];
C[(i)+(256)] += A[(i)+(64)] * values[21];
C[(i)+(256)] += A[(i)+(128)] * values[22];
C[(i)+(256)] += A[(i)+(160)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif

}

void ssparse_starMatrix_m10_n9_k9_ldA16_ldBna6_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 10; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif

}

void ssparse_starMatrix_m4_n9_k9_ldA16_ldBna6_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 4; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif

}

void ssparse_starMatrix_m1_n9_k9_ldA16_ldBna6_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
for (unsigned int i = 0; i < 1; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif

}

void ssparse_starMatrix_m56_n9_k9_ldA64_ldBna7_ldC64_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 56; i += 1)
{
C[(i)+(0)] += A[(i)+(384)] * values[0];
C[(i)+(0)] += A[(i)+(448)] * values[1];
C[(i)+(0)] += A[(i)+(512)] * values[2];
C[(i)+(64)] += A[(i)+(384)] * values[3];
C[(i)+(64)] += A[(i)+(448)] * values[4];
C[(i)+(64)] += A[(i)+(512)] * values[5];
C[(i)+(128)] += A[(i)+(384)] * values[6];
C[(i)+(128)] += A[(i)+(448)] * values[7];
C[(i)+(128)] += A[(i)+(512)] * values[8];
C[(i)+(192)] += A[(i)+(384)] * values[9];
C[(i)+(192)] += A[(i)+(448)] * values[10];
C[(i)+(256)] += A[(i)+(448)] * values[11];
C[(i)+(256)] += A[(i)+(512)] * values[12];
C[(i)+(320)] += A[(i)+(384)] * values[13];
C[(i)+(320)] += A[(i)+(512)] * values[14];
C[(i)+(384)] += A[(i)+(0)] * values[15];
C[(i)+(384)] += A[(i)+(192)] * values[16];
C[(i)+(384)] += A[(i)+(320)] * values[17];
C[(i)+(448)] += A[(i)+(64)] * values[18];
C[(i)+(448)] += A[(i)+(192)] * values[19];
C[(i)+(448)] += A[(i)+(256)] * values[20];
C[(i)+(512)] += A[(i)+(128)] * values[21];
C[(i)+(512)] += A[(i)+(256)] * values[22];
C[(i)+(512)] += A[(i)+(320)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 2688;
#endif

}

void ssparse_starMatrix_m35_n9_k9_ldA48_ldBna7_ldC48_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 35; i += 1)
{
C[(i)+(0)] += A[(i)+(288)] * values[0];
C[(i)+(0)] += A[(i)+(336)] * values[1];
C[(i)+(0)] += A[(i)+(384)] * values[2];
C[(i)+(48)] += A[(i)+(288)] * values[3];
C[(i)+(48)] += A[(i)+(336)] * values[4];
C[(i)+(48)] += A[(i)+(384)] * values[5];
C[(i)+(96)] += A[(i)+(288)] * values[6];
C[(i)+(96)] += A[(i)+(336)] * values[7];
C[(i)+(96)] += A[(i)+(384)] * values[8];
C[(i)+(144)] += A[(i)+(288)] * values[9];
C[(i)+(144)] += A[(i)+(336)] * values[10];
C[(i)+(192)] += A[(i)+(336)] * values[11];
C[(i)+(192)] += A[(i)+(384)] * values[12];
C[(i)+(240)] += A[(i)+(288)] * values[13];
C[(i)+(240)] += A[(i)+(384)] * values[14];
C[(i)+(288)] += A[(i)+(0)] * values[15];
C[(i)+(288)] += A[(i)+(144)] * values[16];
C[(i)+(288)] += A[(i)+(240)] * values[17];
C[(i)+(336)] += A[(i)+(48)] * values[18];
C[(i)+(336)] += A[(i)+(144)] * values[19];
C[(i)+(336)] += A[(i)+(192)] * values[20];
C[(i)+(384)] += A[(i)+(96)] * values[21];
C[(i)+(384)] += A[(i)+(192)] * values[22];
C[(i)+(384)] += A[(i)+(240)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 1680;
#endif

}

void ssparse_starMatrix_m20_n9_k9_ldA32_ldBna7_ldC32_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 20; i += 1)
{
C[(i)+(0)] += A[(i)+(192)] * values[0];
C[(i)+(0)] += A[(i)+(224)] * values[1];
C[(i)+(0)] += A[(i)+(256)] * values[2];
C[(i)+(32)] += A[(i)+(192)] * values[3];
C[(i)+(32)] += A[(i)+(224)] * values[4];
C[(i)+(32)] += A[(i)+(256)] * values[5];
C[(i)+(64)] += A[(i)+(192)] * values[6];
C[(i)+(64)] += A[(i)+(224)] * values[7];
C[(i)+(64)] += A[(i)+(256)] * values[8];
C[(i)+(96)] += A[(i)+(192)] * values[9];
C[(i)+(96)] += A[(i)+(224)] * values[10];
C[(i)+(128)] += A[(i)+(224)] * values[11];
C[(i)+(128)] += A[(i)+(256)] * values[12];
C[(i)+(160)] += A[(i)+(192)] * values[13];
C[(i)+(160)] += A[(i)+(256)] * values[14];
C[(i)+(192)] += A[(i)+(0)] * values[15];
C[(i)+(192)] += A[(i)+(96)] * values[16];
C[(i)+(192)] += A[(i)+(160)] * values[17];
C[(i)+(224)] += A[(i)+(32)] * values[18];
C[(i)+(224)] += A[(i)+(96)] * values[19];
C[(i)+(224)] += A[(i)+(128)] * values[20];
C[(i)+(256)] += A[(i)+(64)] * values[21];
C[(i)+(256)] += A[(i)+(128)] * values[22];
C[(i)+(256)] += A[(i)+(160)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif

}

void ssparse_starMatrix_m10_n9_k9_ldA16_ldBna7_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 10; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif

}

void ssparse_starMatrix_m4_n9_k9_ldA16_ldBna7_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 4; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif

}

void ssparse_starMatrix_m1_n9_k9_ldA16_ldBna7_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
for (unsigned int i = 0; i < 1; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif

}

void ssparse_starMatrix_m84_n9_k9_ldA96_ldBna8_ldC96_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 84; i += 1)
{
C[(i)+(0)] += A[(i)+(576)] * values[0];
C[(i)+(0)] += A[(i)+(672)] * values[1];
C[(i)+(0)] += A[(i)+(768)] * values[2];
C[(i)+(96)] += A[(i)+(576)] * values[3];
C[(i)+(96)] += A[(i)+(672)] * values[4];
C[(i)+(96)] += A[(i)+(768)] * values[5];
C[(i)+(192)] += A[(i)+(576)] * values[6];
C[(i)+(192)] += A[(i)+(672)] * values[7];
C[(i)+(192)] += A[(i)+(768)] * values[8];
C[(i)+(288)] += A[(i)+(576)] * values[9];
C[(i)+(288)] += A[(i)+(672)] * values[10];
C[(i)+(384)] += A[(i)+(672)] * values[11];
C[(i)+(384)] += A[(i)+(768)] * values[12];
C[(i)+(480)] += A[(i)+(576)] * values[13];
C[(i)+(480)] += A[(i)+(768)] * values[14];
C[(i)+(576)] += A[(i)+(0)] * values[15];
C[(i)+(576)] += A[(i)+(288)] * values[16];
C[(i)+(576)] += A[(i)+(480)] * values[17];
C[(i)+(672)] += A[(i)+(96)] * values[18];
C[(i)+(672)] += A[(i)+(288)] * values[19];
C[(i)+(672)] += A[(i)+(384)] * values[20];
C[(i)+(768)] += A[(i)+(192)] * values[21];
C[(i)+(768)] += A[(i)+(384)] * values[22];
C[(i)+(768)] += A[(i)+(480)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 4032;
#endif

}

void ssparse_starMatrix_m56_n9_k9_ldA64_ldBna8_ldC64_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 56; i += 1)
{
C[(i)+(0)] += A[(i)+(384)] * values[0];
C[(i)+(0)] += A[(i)+(448)] * values[1];
C[(i)+(0)] += A[(i)+(512)] * values[2];
C[(i)+(64)] += A[(i)+(384)] * values[3];
C[(i)+(64)] += A[(i)+(448)] * values[4];
C[(i)+(64)] += A[(i)+(512)] * values[5];
C[(i)+(128)] += A[(i)+(384)] * values[6];
C[(i)+(128)] += A[(i)+(448)] * values[7];
C[(i)+(128)] += A[(i)+(512)] * values[8];
C[(i)+(192)] += A[(i)+(384)] * values[9];
C[(i)+(192)] += A[(i)+(448)] * values[10];
C[(i)+(256)] += A[(i)+(448)] * values[11];
C[(i)+(256)] += A[(i)+(512)] * values[12];
C[(i)+(320)] += A[(i)+(384)] * values[13];
C[(i)+(320)] += A[(i)+(512)] * values[14];
C[(i)+(384)] += A[(i)+(0)] * values[15];
C[(i)+(384)] += A[(i)+(192)] * values[16];
C[(i)+(384)] += A[(i)+(320)] * values[17];
C[(i)+(448)] += A[(i)+(64)] * values[18];
C[(i)+(448)] += A[(i)+(192)] * values[19];
C[(i)+(448)] += A[(i)+(256)] * values[20];
C[(i)+(512)] += A[(i)+(128)] * values[21];
C[(i)+(512)] += A[(i)+(256)] * values[22];
C[(i)+(512)] += A[(i)+(320)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 2688;
#endif

}

void ssparse_starMatrix_m35_n9_k9_ldA48_ldBna8_ldC48_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 35; i += 1)
{
C[(i)+(0)] += A[(i)+(288)] * values[0];
C[(i)+(0)] += A[(i)+(336)] * values[1];
C[(i)+(0)] += A[(i)+(384)] * values[2];
C[(i)+(48)] += A[(i)+(288)] * values[3];
C[(i)+(48)] += A[(i)+(336)] * values[4];
C[(i)+(48)] += A[(i)+(384)] * values[5];
C[(i)+(96)] += A[(i)+(288)] * values[6];
C[(i)+(96)] += A[(i)+(336)] * values[7];
C[(i)+(96)] += A[(i)+(384)] * values[8];
C[(i)+(144)] += A[(i)+(288)] * values[9];
C[(i)+(144)] += A[(i)+(336)] * values[10];
C[(i)+(192)] += A[(i)+(336)] * values[11];
C[(i)+(192)] += A[(i)+(384)] * values[12];
C[(i)+(240)] += A[(i)+(288)] * values[13];
C[(i)+(240)] += A[(i)+(384)] * values[14];
C[(i)+(288)] += A[(i)+(0)] * values[15];
C[(i)+(288)] += A[(i)+(144)] * values[16];
C[(i)+(288)] += A[(i)+(240)] * values[17];
C[(i)+(336)] += A[(i)+(48)] * values[18];
C[(i)+(336)] += A[(i)+(144)] * values[19];
C[(i)+(336)] += A[(i)+(192)] * values[20];
C[(i)+(384)] += A[(i)+(96)] * values[21];
C[(i)+(384)] += A[(i)+(192)] * values[22];
C[(i)+(384)] += A[(i)+(240)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 1680;
#endif

}

void ssparse_starMatrix_m20_n9_k9_ldA32_ldBna8_ldC32_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 20; i += 1)
{
C[(i)+(0)] += A[(i)+(192)] * values[0];
C[(i)+(0)] += A[(i)+(224)] * values[1];
C[(i)+(0)] += A[(i)+(256)] * values[2];
C[(i)+(32)] += A[(i)+(192)] * values[3];
C[(i)+(32)] += A[(i)+(224)] * values[4];
C[(i)+(32)] += A[(i)+(256)] * values[5];
C[(i)+(64)] += A[(i)+(192)] * values[6];
C[(i)+(64)] += A[(i)+(224)] * values[7];
C[(i)+(64)] += A[(i)+(256)] * values[8];
C[(i)+(96)] += A[(i)+(192)] * values[9];
C[(i)+(96)] += A[(i)+(224)] * values[10];
C[(i)+(128)] += A[(i)+(224)] * values[11];
C[(i)+(128)] += A[(i)+(256)] * values[12];
C[(i)+(160)] += A[(i)+(192)] * values[13];
C[(i)+(160)] += A[(i)+(256)] * values[14];
C[(i)+(192)] += A[(i)+(0)] * values[15];
C[(i)+(192)] += A[(i)+(96)] * values[16];
C[(i)+(192)] += A[(i)+(160)] * values[17];
C[(i)+(224)] += A[(i)+(32)] * values[18];
C[(i)+(224)] += A[(i)+(96)] * values[19];
C[(i)+(224)] += A[(i)+(128)] * values[20];
C[(i)+(256)] += A[(i)+(64)] * values[21];
C[(i)+(256)] += A[(i)+(128)] * values[22];
C[(i)+(256)] += A[(i)+(160)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif

}

void ssparse_starMatrix_m10_n9_k9_ldA16_ldBna8_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 10; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif

}

void ssparse_starMatrix_m4_n9_k9_ldA16_ldBna8_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 4; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif

}

void ssparse_starMatrix_m1_n9_k9_ldA16_ldBna8_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
for (unsigned int i = 0; i < 1; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif

}

void ssparse_starMatrix_m4_n9_k9_ldA16_ldBna2_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 4; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif

}

void ssparse_fP113DivM_m4_n9_k4_ldAna2_ldB16_ldC16_beta0_pfsigonly(const float* values, const float* B, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma nounroll_and_jam
for (unsigned int i = 0; i < 9; i++)
{
  #pragma simd
  for (unsigned int m = 0; m < 4; m++) {
    C[(i*16)+m] = 0.0;
  }
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b0 = _mm_broadcast_ss(&B[(i*16)+0]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b0 = _mm_load_ss(&B[(i*16)+0]);
b0 = _mm_shuffle_ps(b0, b0, 0x00);
#endif
__m128 c0_0 = _mm_load_ss(&C[(i*16)+0]);
__m128 a0_0 = _mm_load_ss(&values[0]);
c0_0 = _mm_add_ss(c0_0, _mm_mul_ss(a0_0, b0));
_mm_store_ss(&C[(i*16)+0], c0_0);
__m128 c0_1 = _mm_load_ss(&C[(i*16)+3]);
__m128 a0_1 = _mm_load_ss(&values[1]);
c0_1 = _mm_add_ss(c0_1, _mm_mul_ss(a0_1, b0));
_mm_store_ss(&C[(i*16)+3], c0_1);
#else
C[(i*16)+0] += values[0] * B[(i*16)+0];
C[(i*16)+3] += values[1] * B[(i*16)+0];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b1 = _mm_broadcast_ss(&B[(i*16)+1]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b1 = _mm_load_ss(&B[(i*16)+1]);
b1 = _mm_shuffle_ps(b1, b1, 0x00);
#endif
__m128 c1_0 = _mm_load_ss(&C[(i*16)+1]);
__m128 a1_0 = _mm_load_ss(&values[2]);
c1_0 = _mm_add_ss(c1_0, _mm_mul_ss(a1_0, b1));
_mm_store_ss(&C[(i*16)+1], c1_0);
#else
C[(i*16)+1] += values[2] * B[(i*16)+1];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b2 = _mm_broadcast_ss(&B[(i*16)+2]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b2 = _mm_load_ss(&B[(i*16)+2]);
b2 = _mm_shuffle_ps(b2, b2, 0x00);
#endif
__m128 c2_0 = _mm_load_ss(&C[(i*16)+2]);
__m128 a2_0 = _mm_load_ss(&values[3]);
c2_0 = _mm_add_ss(c2_0, _mm_mul_ss(a2_0, b2));
_mm_store_ss(&C[(i*16)+2], c2_0);
#else
C[(i*16)+2] += values[3] * B[(i*16)+2];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b3 = _mm_broadcast_ss(&B[(i*16)+3]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b3 = _mm_load_ss(&B[(i*16)+3]);
b3 = _mm_shuffle_ps(b3, b3, 0x00);
#endif
__m128 c3_0 = _mm_load_ss(&C[(i*16)+0]);
__m128 a3_0 = _mm_load_ss(&values[4]);
c3_0 = _mm_add_ss(c3_0, _mm_mul_ss(a3_0, b3));
_mm_store_ss(&C[(i*16)+0], c3_0);
__m128 c3_1 = _mm_load_ss(&C[(i*16)+3]);
__m128 a3_1 = _mm_load_ss(&values[5]);
c3_1 = _mm_add_ss(c3_1, _mm_mul_ss(a3_1, b3));
_mm_store_ss(&C[(i*16)+3], c3_1);
#else
C[(i*16)+0] += values[4] * B[(i*16)+3];
C[(i*16)+3] += values[5] * B[(i*16)+3];
#endif

}

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 108;
#endif

}

void ssparse_starMatrix_m10_n9_k9_ldA16_ldBna3_ldC16_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 10; i += 1)
{
C[(i)+(0)] += A[(i)+(96)] * values[0];
C[(i)+(0)] += A[(i)+(112)] * values[1];
C[(i)+(0)] += A[(i)+(128)] * values[2];
C[(i)+(16)] += A[(i)+(96)] * values[3];
C[(i)+(16)] += A[(i)+(112)] * values[4];
C[(i)+(16)] += A[(i)+(128)] * values[5];
C[(i)+(32)] += A[(i)+(96)] * values[6];
C[(i)+(32)] += A[(i)+(112)] * values[7];
C[(i)+(32)] += A[(i)+(128)] * values[8];
C[(i)+(48)] += A[(i)+(96)] * values[9];
C[(i)+(48)] += A[(i)+(112)] * values[10];
C[(i)+(64)] += A[(i)+(112)] * values[11];
C[(i)+(64)] += A[(i)+(128)] * values[12];
C[(i)+(80)] += A[(i)+(96)] * values[13];
C[(i)+(80)] += A[(i)+(128)] * values[14];
C[(i)+(96)] += A[(i)+(0)] * values[15];
C[(i)+(96)] += A[(i)+(48)] * values[16];
C[(i)+(96)] += A[(i)+(80)] * values[17];
C[(i)+(112)] += A[(i)+(16)] * values[18];
C[(i)+(112)] += A[(i)+(48)] * values[19];
C[(i)+(112)] += A[(i)+(64)] * values[20];
C[(i)+(128)] += A[(i)+(32)] * values[21];
C[(i)+(128)] += A[(i)+(64)] * values[22];
C[(i)+(128)] += A[(i)+(80)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif

}

void ssparse_fP113DivM_m10_n9_k10_ldAna3_ldB16_ldC16_beta0_pfsigonly(const float* values, const float* B, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma nounroll_and_jam
for (unsigned int i = 0; i < 9; i++)
{
  #pragma simd
  for (unsigned int m = 0; m < 10; m++) {
    C[(i*16)+m] = 0.0;
  }
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b0 = _mm_broadcast_ss(&B[(i*16)+0]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b0 = _mm_load_ss(&B[(i*16)+0]);
b0 = _mm_shuffle_ps(b0, b0, 0x00);
#endif
__m128 c0_0 = _mm_load_ss(&C[(i*16)+0]);
__m128 a0_0 = _mm_load_ss(&values[0]);
c0_0 = _mm_add_ss(c0_0, _mm_mul_ss(a0_0, b0));
_mm_store_ss(&C[(i*16)+0], c0_0);
__m128 c0_1 = _mm_load_ss(&C[(i*16)+3]);
__m128 a0_1 = _mm_load_ss(&values[1]);
c0_1 = _mm_add_ss(c0_1, _mm_mul_ss(a0_1, b0));
_mm_store_ss(&C[(i*16)+3], c0_1);
__m128 c0_2 = _mm_load_ss(&C[(i*16)+9]);
__m128 a0_2 = _mm_load_ss(&values[2]);
c0_2 = _mm_add_ss(c0_2, _mm_mul_ss(a0_2, b0));
_mm_store_ss(&C[(i*16)+9], c0_2);
#else
C[(i*16)+0] += values[0] * B[(i*16)+0];
C[(i*16)+3] += values[1] * B[(i*16)+0];
C[(i*16)+9] += values[2] * B[(i*16)+0];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b1 = _mm_broadcast_ss(&B[(i*16)+1]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b1 = _mm_load_ss(&B[(i*16)+1]);
b1 = _mm_shuffle_ps(b1, b1, 0x00);
#endif
__m128 c1_0 = _mm_load_ss(&C[(i*16)+1]);
__m128 a1_0 = _mm_load_ss(&values[3]);
c1_0 = _mm_add_ss(c1_0, _mm_mul_ss(a1_0, b1));
_mm_store_ss(&C[(i*16)+1], c1_0);
__m128 c1_1 = _mm_load_ss(&C[(i*16)+7]);
__m128 a1_1 = _mm_load_ss(&values[4]);
c1_1 = _mm_add_ss(c1_1, _mm_mul_ss(a1_1, b1));
_mm_store_ss(&C[(i*16)+7], c1_1);
#else
C[(i*16)+1] += values[3] * B[(i*16)+1];
C[(i*16)+7] += values[4] * B[(i*16)+1];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b2 = _mm_broadcast_ss(&B[(i*16)+2]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b2 = _mm_load_ss(&B[(i*16)+2]);
b2 = _mm_shuffle_ps(b2, b2, 0x00);
#endif
__m128 c2_0 = _mm_load_ss(&C[(i*16)+2]);
__m128 a2_0 = _mm_load_ss(&values[5]);
c2_0 = _mm_add_ss(c2_0, _mm_mul_ss(a2_0, b2));
_mm_store_ss(&C[(i*16)+2], c2_0);
__m128 c2_1 = _mm_load_ss(&C[(i*16)+8]);
__m128 a2_1 = _mm_load_ss(&values[6]);
c2_1 = _mm_add_ss(c2_1, _mm_mul_ss(a2_1, b2));
_mm_store_ss(&C[(i*16)+8], c2_1);
#else
C[(i*16)+2] += values[5] * B[(i*16)+2];
C[(i*16)+8] += values[6] * B[(i*16)+2];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b3 = _mm_broadcast_ss(&B[(i*16)+3]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b3 = _mm_load_ss(&B[(i*16)+3]);
b3 = _mm_shuffle_ps(b3, b3, 0x00);
#endif
__m128 c3_0 = _mm_load_ss(&C[(i*16)+0]);
__m128 a3_0 = _mm_load_ss(&values[7]);
c3_0 = _mm_add_ss(c3_0, _mm_mul_ss(a3_0, b3));
_mm_store_ss(&C[(i*16)+0], c3_0);
__m128 c3_1 = _mm_load_ss(&C[(i*16)+3]);
__m128 a3_1 = _mm_load_ss(&values[8]);
c3_1 = _mm_add_ss(c3_1, _mm_mul_ss(a3_1, b3));
_mm_store_ss(&C[(i*16)+3], c3_1);
__m128 c3_2 = _mm_load_ss(&C[(i*16)+9]);
__m128 a3_2 = _mm_load_ss(&values[9]);
c3_2 = _mm_add_ss(c3_2, _mm_mul_ss(a3_2, b3));
_mm_store_ss(&C[(i*16)+9], c3_2);
#else
C[(i*16)+0] += values[7] * B[(i*16)+3];
C[(i*16)+3] += values[8] * B[(i*16)+3];
C[(i*16)+9] += values[9] * B[(i*16)+3];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b4 = _mm_broadcast_ss(&B[(i*16)+4]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b4 = _mm_load_ss(&B[(i*16)+4]);
b4 = _mm_shuffle_ps(b4, b4, 0x00);
#endif
__m128 c4_0 = _mm_load_ss(&C[(i*16)+4]);
__m128 a4_0 = _mm_load_ss(&values[10]);
c4_0 = _mm_add_ss(c4_0, _mm_mul_ss(a4_0, b4));
_mm_store_ss(&C[(i*16)+4], c4_0);
#else
C[(i*16)+4] += values[10] * B[(i*16)+4];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b5 = _mm_broadcast_ss(&B[(i*16)+5]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b5 = _mm_load_ss(&B[(i*16)+5]);
b5 = _mm_shuffle_ps(b5, b5, 0x00);
#endif
__m128 c5_0 = _mm_load_ss(&C[(i*16)+5]);
__m128 a5_0 = _mm_load_ss(&values[11]);
c5_0 = _mm_add_ss(c5_0, _mm_mul_ss(a5_0, b5));
_mm_store_ss(&C[(i*16)+5], c5_0);
#else
C[(i*16)+5] += values[11] * B[(i*16)+5];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b6 = _mm_broadcast_ss(&B[(i*16)+6]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b6 = _mm_load_ss(&B[(i*16)+6]);
b6 = _mm_shuffle_ps(b6, b6, 0x00);
#endif
__m128 c6_0 = _mm_load_ss(&C[(i*16)+6]);
__m128 a6_0 = _mm_load_ss(&values[12]);
c6_0 = _mm_add_ss(c6_0, _mm_mul_ss(a6_0, b6));
_mm_store_ss(&C[(i*16)+6], c6_0);
#else
C[(i*16)+6] += values[12] * B[(i*16)+6];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b7 = _mm_broadcast_ss(&B[(i*16)+7]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b7 = _mm_load_ss(&B[(i*16)+7]);
b7 = _mm_shuffle_ps(b7, b7, 0x00);
#endif
__m128 c7_0 = _mm_load_ss(&C[(i*16)+1]);
__m128 a7_0 = _mm_load_ss(&values[13]);
c7_0 = _mm_add_ss(c7_0, _mm_mul_ss(a7_0, b7));
_mm_store_ss(&C[(i*16)+1], c7_0);
__m128 c7_1 = _mm_load_ss(&C[(i*16)+7]);
__m128 a7_1 = _mm_load_ss(&values[14]);
c7_1 = _mm_add_ss(c7_1, _mm_mul_ss(a7_1, b7));
_mm_store_ss(&C[(i*16)+7], c7_1);
#else
C[(i*16)+1] += values[13] * B[(i*16)+7];
C[(i*16)+7] += values[14] * B[(i*16)+7];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b8 = _mm_broadcast_ss(&B[(i*16)+8]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b8 = _mm_load_ss(&B[(i*16)+8]);
b8 = _mm_shuffle_ps(b8, b8, 0x00);
#endif
__m128 c8_0 = _mm_load_ss(&C[(i*16)+2]);
__m128 a8_0 = _mm_load_ss(&values[15]);
c8_0 = _mm_add_ss(c8_0, _mm_mul_ss(a8_0, b8));
_mm_store_ss(&C[(i*16)+2], c8_0);
__m128 c8_1 = _mm_load_ss(&C[(i*16)+8]);
__m128 a8_1 = _mm_load_ss(&values[16]);
c8_1 = _mm_add_ss(c8_1, _mm_mul_ss(a8_1, b8));
_mm_store_ss(&C[(i*16)+8], c8_1);
#else
C[(i*16)+2] += values[15] * B[(i*16)+8];
C[(i*16)+8] += values[16] * B[(i*16)+8];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b9 = _mm_broadcast_ss(&B[(i*16)+9]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b9 = _mm_load_ss(&B[(i*16)+9]);
b9 = _mm_shuffle_ps(b9, b9, 0x00);
#endif
__m128 c9_0 = _mm_load_ss(&C[(i*16)+0]);
__m128 a9_0 = _mm_load_ss(&values[17]);
c9_0 = _mm_add_ss(c9_0, _mm_mul_ss(a9_0, b9));
_mm_store_ss(&C[(i*16)+0], c9_0);
__m128 c9_1 = _mm_load_ss(&C[(i*16)+3]);
__m128 a9_1 = _mm_load_ss(&values[18]);
c9_1 = _mm_add_ss(c9_1, _mm_mul_ss(a9_1, b9));
_mm_store_ss(&C[(i*16)+3], c9_1);
__m128 c9_2 = _mm_load_ss(&C[(i*16)+9]);
__m128 a9_2 = _mm_load_ss(&values[19]);
c9_2 = _mm_add_ss(c9_2, _mm_mul_ss(a9_2, b9));
_mm_store_ss(&C[(i*16)+9], c9_2);
#else
C[(i*16)+0] += values[17] * B[(i*16)+9];
C[(i*16)+3] += values[18] * B[(i*16)+9];
C[(i*16)+9] += values[19] * B[(i*16)+9];
#endif

}

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 360;
#endif

}

void ssparse_starMatrix_m20_n9_k9_ldA32_ldBna4_ldC32_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 20; i += 1)
{
C[(i)+(0)] += A[(i)+(192)] * values[0];
C[(i)+(0)] += A[(i)+(224)] * values[1];
C[(i)+(0)] += A[(i)+(256)] * values[2];
C[(i)+(32)] += A[(i)+(192)] * values[3];
C[(i)+(32)] += A[(i)+(224)] * values[4];
C[(i)+(32)] += A[(i)+(256)] * values[5];
C[(i)+(64)] += A[(i)+(192)] * values[6];
C[(i)+(64)] += A[(i)+(224)] * values[7];
C[(i)+(64)] += A[(i)+(256)] * values[8];
C[(i)+(96)] += A[(i)+(192)] * values[9];
C[(i)+(96)] += A[(i)+(224)] * values[10];
C[(i)+(128)] += A[(i)+(224)] * values[11];
C[(i)+(128)] += A[(i)+(256)] * values[12];
C[(i)+(160)] += A[(i)+(192)] * values[13];
C[(i)+(160)] += A[(i)+(256)] * values[14];
C[(i)+(192)] += A[(i)+(0)] * values[15];
C[(i)+(192)] += A[(i)+(96)] * values[16];
C[(i)+(192)] += A[(i)+(160)] * values[17];
C[(i)+(224)] += A[(i)+(32)] * values[18];
C[(i)+(224)] += A[(i)+(96)] * values[19];
C[(i)+(224)] += A[(i)+(128)] * values[20];
C[(i)+(256)] += A[(i)+(64)] * values[21];
C[(i)+(256)] += A[(i)+(128)] * values[22];
C[(i)+(256)] += A[(i)+(160)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif

}

void ssparse_starMatrix_m35_n9_k9_ldA48_ldBna5_ldC48_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 35; i += 1)
{
C[(i)+(0)] += A[(i)+(288)] * values[0];
C[(i)+(0)] += A[(i)+(336)] * values[1];
C[(i)+(0)] += A[(i)+(384)] * values[2];
C[(i)+(48)] += A[(i)+(288)] * values[3];
C[(i)+(48)] += A[(i)+(336)] * values[4];
C[(i)+(48)] += A[(i)+(384)] * values[5];
C[(i)+(96)] += A[(i)+(288)] * values[6];
C[(i)+(96)] += A[(i)+(336)] * values[7];
C[(i)+(96)] += A[(i)+(384)] * values[8];
C[(i)+(144)] += A[(i)+(288)] * values[9];
C[(i)+(144)] += A[(i)+(336)] * values[10];
C[(i)+(192)] += A[(i)+(336)] * values[11];
C[(i)+(192)] += A[(i)+(384)] * values[12];
C[(i)+(240)] += A[(i)+(288)] * values[13];
C[(i)+(240)] += A[(i)+(384)] * values[14];
C[(i)+(288)] += A[(i)+(0)] * values[15];
C[(i)+(288)] += A[(i)+(144)] * values[16];
C[(i)+(288)] += A[(i)+(240)] * values[17];
C[(i)+(336)] += A[(i)+(48)] * values[18];
C[(i)+(336)] += A[(i)+(144)] * values[19];
C[(i)+(336)] += A[(i)+(192)] * values[20];
C[(i)+(384)] += A[(i)+(96)] * values[21];
C[(i)+(384)] += A[(i)+(192)] * values[22];
C[(i)+(384)] += A[(i)+(240)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 1680;
#endif

}

void ssparse_starMatrix_m56_n9_k9_ldA64_ldBna6_ldC64_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 56; i += 1)
{
C[(i)+(0)] += A[(i)+(384)] * values[0];
C[(i)+(0)] += A[(i)+(448)] * values[1];
C[(i)+(0)] += A[(i)+(512)] * values[2];
C[(i)+(64)] += A[(i)+(384)] * values[3];
C[(i)+(64)] += A[(i)+(448)] * values[4];
C[(i)+(64)] += A[(i)+(512)] * values[5];
C[(i)+(128)] += A[(i)+(384)] * values[6];
C[(i)+(128)] += A[(i)+(448)] * values[7];
C[(i)+(128)] += A[(i)+(512)] * values[8];
C[(i)+(192)] += A[(i)+(384)] * values[9];
C[(i)+(192)] += A[(i)+(448)] * values[10];
C[(i)+(256)] += A[(i)+(448)] * values[11];
C[(i)+(256)] += A[(i)+(512)] * values[12];
C[(i)+(320)] += A[(i)+(384)] * values[13];
C[(i)+(320)] += A[(i)+(512)] * values[14];
C[(i)+(384)] += A[(i)+(0)] * values[15];
C[(i)+(384)] += A[(i)+(192)] * values[16];
C[(i)+(384)] += A[(i)+(320)] * values[17];
C[(i)+(448)] += A[(i)+(64)] * values[18];
C[(i)+(448)] += A[(i)+(192)] * values[19];
C[(i)+(448)] += A[(i)+(256)] * values[20];
C[(i)+(512)] += A[(i)+(128)] * values[21];
C[(i)+(512)] += A[(i)+(256)] * values[22];
C[(i)+(512)] += A[(i)+(320)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 2688;
#endif

}

void ssparse_fP113DivM_m56_n9_k56_ldAna6_ldB64_ldC64_beta0_pfsigonly(const float* values, const float* B, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma nounroll_and_jam
for (unsigned int i = 0; i < 9; i++)
{
  #pragma simd
  for (unsigned int m = 0; m < 56; m++) {
    C[(i*64)+m] = 0.0;
  }
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b0 = _mm_broadcast_ss(&B[(i*64)+0]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b0 = _mm_load_ss(&B[(i*64)+0]);
b0 = _mm_shuffle_ps(b0, b0, 0x00);
#endif
__m128 c0_0 = _mm_load_ss(&C[(i*64)+0]);
__m128 a0_0 = _mm_load_ss(&values[0]);
c0_0 = _mm_add_ss(c0_0, _mm_mul_ss(a0_0, b0));
_mm_store_ss(&C[(i*64)+0], c0_0);
__m128 c0_1 = _mm_load_ss(&C[(i*64)+3]);
__m128 a0_1 = _mm_load_ss(&values[1]);
c0_1 = _mm_add_ss(c0_1, _mm_mul_ss(a0_1, b0));
_mm_store_ss(&C[(i*64)+3], c0_1);
__m128 c0_2 = _mm_load_ss(&C[(i*64)+9]);
__m128 a0_2 = _mm_load_ss(&values[2]);
c0_2 = _mm_add_ss(c0_2, _mm_mul_ss(a0_2, b0));
_mm_store_ss(&C[(i*64)+9], c0_2);
__m128 c0_3 = _mm_load_ss(&C[(i*64)+19]);
__m128 a0_3 = _mm_load_ss(&values[3]);
c0_3 = _mm_add_ss(c0_3, _mm_mul_ss(a0_3, b0));
_mm_store_ss(&C[(i*64)+19], c0_3);
__m128 c0_4 = _mm_load_ss(&C[(i*64)+34]);
__m128 a0_4 = _mm_load_ss(&values[4]);
c0_4 = _mm_add_ss(c0_4, _mm_mul_ss(a0_4, b0));
_mm_store_ss(&C[(i*64)+34], c0_4);
__m128 c0_5 = _mm_load_ss(&C[(i*64)+55]);
__m128 a0_5 = _mm_load_ss(&values[5]);
c0_5 = _mm_add_ss(c0_5, _mm_mul_ss(a0_5, b0));
_mm_store_ss(&C[(i*64)+55], c0_5);
#else
C[(i*64)+0] += values[0] * B[(i*64)+0];
C[(i*64)+3] += values[1] * B[(i*64)+0];
C[(i*64)+9] += values[2] * B[(i*64)+0];
C[(i*64)+19] += values[3] * B[(i*64)+0];
C[(i*64)+34] += values[4] * B[(i*64)+0];
C[(i*64)+55] += values[5] * B[(i*64)+0];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b1 = _mm_broadcast_ss(&B[(i*64)+1]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b1 = _mm_load_ss(&B[(i*64)+1]);
b1 = _mm_shuffle_ps(b1, b1, 0x00);
#endif
__m128 c1_0 = _mm_load_ss(&C[(i*64)+1]);
__m128 a1_0 = _mm_load_ss(&values[6]);
c1_0 = _mm_add_ss(c1_0, _mm_mul_ss(a1_0, b1));
_mm_store_ss(&C[(i*64)+1], c1_0);
__m128 c1_1 = _mm_load_ss(&C[(i*64)+7]);
__m128 a1_1 = _mm_load_ss(&values[7]);
c1_1 = _mm_add_ss(c1_1, _mm_mul_ss(a1_1, b1));
_mm_store_ss(&C[(i*64)+7], c1_1);
__m128 c1_2 = _mm_load_ss(&C[(i*64)+17]);
__m128 a1_2 = _mm_load_ss(&values[8]);
c1_2 = _mm_add_ss(c1_2, _mm_mul_ss(a1_2, b1));
_mm_store_ss(&C[(i*64)+17], c1_2);
__m128 c1_3 = _mm_load_ss(&C[(i*64)+32]);
__m128 a1_3 = _mm_load_ss(&values[9]);
c1_3 = _mm_add_ss(c1_3, _mm_mul_ss(a1_3, b1));
_mm_store_ss(&C[(i*64)+32], c1_3);
__m128 c1_4 = _mm_load_ss(&C[(i*64)+53]);
__m128 a1_4 = _mm_load_ss(&values[10]);
c1_4 = _mm_add_ss(c1_4, _mm_mul_ss(a1_4, b1));
_mm_store_ss(&C[(i*64)+53], c1_4);
#else
C[(i*64)+1] += values[6] * B[(i*64)+1];
C[(i*64)+7] += values[7] * B[(i*64)+1];
C[(i*64)+17] += values[8] * B[(i*64)+1];
C[(i*64)+32] += values[9] * B[(i*64)+1];
C[(i*64)+53] += values[10] * B[(i*64)+1];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b2 = _mm_broadcast_ss(&B[(i*64)+2]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b2 = _mm_load_ss(&B[(i*64)+2]);
b2 = _mm_shuffle_ps(b2, b2, 0x00);
#endif
__m128 c2_0 = _mm_load_ss(&C[(i*64)+2]);
__m128 a2_0 = _mm_load_ss(&values[11]);
c2_0 = _mm_add_ss(c2_0, _mm_mul_ss(a2_0, b2));
_mm_store_ss(&C[(i*64)+2], c2_0);
__m128 c2_1 = _mm_load_ss(&C[(i*64)+8]);
__m128 a2_1 = _mm_load_ss(&values[12]);
c2_1 = _mm_add_ss(c2_1, _mm_mul_ss(a2_1, b2));
_mm_store_ss(&C[(i*64)+8], c2_1);
__m128 c2_2 = _mm_load_ss(&C[(i*64)+18]);
__m128 a2_2 = _mm_load_ss(&values[13]);
c2_2 = _mm_add_ss(c2_2, _mm_mul_ss(a2_2, b2));
_mm_store_ss(&C[(i*64)+18], c2_2);
__m128 c2_3 = _mm_load_ss(&C[(i*64)+33]);
__m128 a2_3 = _mm_load_ss(&values[14]);
c2_3 = _mm_add_ss(c2_3, _mm_mul_ss(a2_3, b2));
_mm_store_ss(&C[(i*64)+33], c2_3);
__m128 c2_4 = _mm_load_ss(&C[(i*64)+54]);
__m128 a2_4 = _mm_load_ss(&values[15]);
c2_4 = _mm_add_ss(c2_4, _mm_mul_ss(a2_4, b2));
_mm_store_ss(&C[(i*64)+54], c2_4);
#else
C[(i*64)+2] += values[11] * B[(i*64)+2];
C[(i*64)+8] += values[12] * B[(i*64)+2];
C[(i*64)+18] += values[13] * B[(i*64)+2];
C[(i*64)+33] += values[14] * B[(i*64)+2];
C[(i*64)+54] += values[15] * B[(i*64)+2];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b3 = _mm_broadcast_ss(&B[(i*64)+3]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b3 = _mm_load_ss(&B[(i*64)+3]);
b3 = _mm_shuffle_ps(b3, b3, 0x00);
#endif
__m128 c3_0 = _mm_load_ss(&C[(i*64)+0]);
__m128 a3_0 = _mm_load_ss(&values[16]);
c3_0 = _mm_add_ss(c3_0, _mm_mul_ss(a3_0, b3));
_mm_store_ss(&C[(i*64)+0], c3_0);
__m128 c3_1 = _mm_load_ss(&C[(i*64)+3]);
__m128 a3_1 = _mm_load_ss(&values[17]);
c3_1 = _mm_add_ss(c3_1, _mm_mul_ss(a3_1, b3));
_mm_store_ss(&C[(i*64)+3], c3_1);
__m128 c3_2 = _mm_load_ss(&C[(i*64)+9]);
__m128 a3_2 = _mm_load_ss(&values[18]);
c3_2 = _mm_add_ss(c3_2, _mm_mul_ss(a3_2, b3));
_mm_store_ss(&C[(i*64)+9], c3_2);
__m128 c3_3 = _mm_load_ss(&C[(i*64)+19]);
__m128 a3_3 = _mm_load_ss(&values[19]);
c3_3 = _mm_add_ss(c3_3, _mm_mul_ss(a3_3, b3));
_mm_store_ss(&C[(i*64)+19], c3_3);
__m128 c3_4 = _mm_load_ss(&C[(i*64)+34]);
__m128 a3_4 = _mm_load_ss(&values[20]);
c3_4 = _mm_add_ss(c3_4, _mm_mul_ss(a3_4, b3));
_mm_store_ss(&C[(i*64)+34], c3_4);
__m128 c3_5 = _mm_load_ss(&C[(i*64)+55]);
__m128 a3_5 = _mm_load_ss(&values[21]);
c3_5 = _mm_add_ss(c3_5, _mm_mul_ss(a3_5, b3));
_mm_store_ss(&C[(i*64)+55], c3_5);
#else
C[(i*64)+0] += values[16] * B[(i*64)+3];
C[(i*64)+3] += values[17] * B[(i*64)+3];
C[(i*64)+9] += values[18] * B[(i*64)+3];
C[(i*64)+19] += values[19] * B[(i*64)+3];
C[(i*64)+34] += values[20] * B[(i*64)+3];
C[(i*64)+55] += values[21] * B[(i*64)+3];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b4 = _mm_broadcast_ss(&B[(i*64)+4]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b4 = _mm_load_ss(&B[(i*64)+4]);
b4 = _mm_shuffle_ps(b4, b4, 0x00);
#endif
__m128 c4_0 = _mm_load_ss(&C[(i*64)+4]);
__m128 a4_0 = _mm_load_ss(&values[22]);
c4_0 = _mm_add_ss(c4_0, _mm_mul_ss(a4_0, b4));
_mm_store_ss(&C[(i*64)+4], c4_0);
__m128 c4_1 = _mm_load_ss(&C[(i*64)+14]);
__m128 a4_1 = _mm_load_ss(&values[23]);
c4_1 = _mm_add_ss(c4_1, _mm_mul_ss(a4_1, b4));
_mm_store_ss(&C[(i*64)+14], c4_1);
__m128 c4_2 = _mm_load_ss(&C[(i*64)+29]);
__m128 a4_2 = _mm_load_ss(&values[24]);
c4_2 = _mm_add_ss(c4_2, _mm_mul_ss(a4_2, b4));
_mm_store_ss(&C[(i*64)+29], c4_2);
__m128 c4_3 = _mm_load_ss(&C[(i*64)+50]);
__m128 a4_3 = _mm_load_ss(&values[25]);
c4_3 = _mm_add_ss(c4_3, _mm_mul_ss(a4_3, b4));
_mm_store_ss(&C[(i*64)+50], c4_3);
#else
C[(i*64)+4] += values[22] * B[(i*64)+4];
C[(i*64)+14] += values[23] * B[(i*64)+4];
C[(i*64)+29] += values[24] * B[(i*64)+4];
C[(i*64)+50] += values[25] * B[(i*64)+4];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b5 = _mm_broadcast_ss(&B[(i*64)+5]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b5 = _mm_load_ss(&B[(i*64)+5]);
b5 = _mm_shuffle_ps(b5, b5, 0x00);
#endif
__m128 c5_0 = _mm_load_ss(&C[(i*64)+5]);
__m128 a5_0 = _mm_load_ss(&values[26]);
c5_0 = _mm_add_ss(c5_0, _mm_mul_ss(a5_0, b5));
_mm_store_ss(&C[(i*64)+5], c5_0);
__m128 c5_1 = _mm_load_ss(&C[(i*64)+15]);
__m128 a5_1 = _mm_load_ss(&values[27]);
c5_1 = _mm_add_ss(c5_1, _mm_mul_ss(a5_1, b5));
_mm_store_ss(&C[(i*64)+15], c5_1);
__m128 c5_2 = _mm_load_ss(&C[(i*64)+30]);
__m128 a5_2 = _mm_load_ss(&values[28]);
c5_2 = _mm_add_ss(c5_2, _mm_mul_ss(a5_2, b5));
_mm_store_ss(&C[(i*64)+30], c5_2);
__m128 c5_3 = _mm_load_ss(&C[(i*64)+51]);
__m128 a5_3 = _mm_load_ss(&values[29]);
c5_3 = _mm_add_ss(c5_3, _mm_mul_ss(a5_3, b5));
_mm_store_ss(&C[(i*64)+51], c5_3);
#else
C[(i*64)+5] += values[26] * B[(i*64)+5];
C[(i*64)+15] += values[27] * B[(i*64)+5];
C[(i*64)+30] += values[28] * B[(i*64)+5];
C[(i*64)+51] += values[29] * B[(i*64)+5];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b6 = _mm_broadcast_ss(&B[(i*64)+6]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b6 = _mm_load_ss(&B[(i*64)+6]);
b6 = _mm_shuffle_ps(b6, b6, 0x00);
#endif
__m128 c6_0 = _mm_load_ss(&C[(i*64)+6]);
__m128 a6_0 = _mm_load_ss(&values[30]);
c6_0 = _mm_add_ss(c6_0, _mm_mul_ss(a6_0, b6));
_mm_store_ss(&C[(i*64)+6], c6_0);
__m128 c6_1 = _mm_load_ss(&C[(i*64)+16]);
__m128 a6_1 = _mm_load_ss(&values[31]);
c6_1 = _mm_add_ss(c6_1, _mm_mul_ss(a6_1, b6));
_mm_store_ss(&C[(i*64)+16], c6_1);
__m128 c6_2 = _mm_load_ss(&C[(i*64)+31]);
__m128 a6_2 = _mm_load_ss(&values[32]);
c6_2 = _mm_add_ss(c6_2, _mm_mul_ss(a6_2, b6));
_mm_store_ss(&C[(i*64)+31], c6_2);
__m128 c6_3 = _mm_load_ss(&C[(i*64)+52]);
__m128 a6_3 = _mm_load_ss(&values[33]);
c6_3 = _mm_add_ss(c6_3, _mm_mul_ss(a6_3, b6));
_mm_store_ss(&C[(i*64)+52], c6_3);
#else
C[(i*64)+6] += values[30] * B[(i*64)+6];
C[(i*64)+16] += values[31] * B[(i*64)+6];
C[(i*64)+31] += values[32] * B[(i*64)+6];
C[(i*64)+52] += values[33] * B[(i*64)+6];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b7 = _mm_broadcast_ss(&B[(i*64)+7]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b7 = _mm_load_ss(&B[(i*64)+7]);
b7 = _mm_shuffle_ps(b7, b7, 0x00);
#endif
__m128 c7_0 = _mm_load_ss(&C[(i*64)+1]);
__m128 a7_0 = _mm_load_ss(&values[34]);
c7_0 = _mm_add_ss(c7_0, _mm_mul_ss(a7_0, b7));
_mm_store_ss(&C[(i*64)+1], c7_0);
__m128 c7_1 = _mm_load_ss(&C[(i*64)+7]);
__m128 a7_1 = _mm_load_ss(&values[35]);
c7_1 = _mm_add_ss(c7_1, _mm_mul_ss(a7_1, b7));
_mm_store_ss(&C[(i*64)+7], c7_1);
__m128 c7_2 = _mm_load_ss(&C[(i*64)+17]);
__m128 a7_2 = _mm_load_ss(&values[36]);
c7_2 = _mm_add_ss(c7_2, _mm_mul_ss(a7_2, b7));
_mm_store_ss(&C[(i*64)+17], c7_2);
__m128 c7_3 = _mm_load_ss(&C[(i*64)+32]);
__m128 a7_3 = _mm_load_ss(&values[37]);
c7_3 = _mm_add_ss(c7_3, _mm_mul_ss(a7_3, b7));
_mm_store_ss(&C[(i*64)+32], c7_3);
__m128 c7_4 = _mm_load_ss(&C[(i*64)+53]);
__m128 a7_4 = _mm_load_ss(&values[38]);
c7_4 = _mm_add_ss(c7_4, _mm_mul_ss(a7_4, b7));
_mm_store_ss(&C[(i*64)+53], c7_4);
#else
C[(i*64)+1] += values[34] * B[(i*64)+7];
C[(i*64)+7] += values[35] * B[(i*64)+7];
C[(i*64)+17] += values[36] * B[(i*64)+7];
C[(i*64)+32] += values[37] * B[(i*64)+7];
C[(i*64)+53] += values[38] * B[(i*64)+7];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b8 = _mm_broadcast_ss(&B[(i*64)+8]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b8 = _mm_load_ss(&B[(i*64)+8]);
b8 = _mm_shuffle_ps(b8, b8, 0x00);
#endif
__m128 c8_0 = _mm_load_ss(&C[(i*64)+2]);
__m128 a8_0 = _mm_load_ss(&values[39]);
c8_0 = _mm_add_ss(c8_0, _mm_mul_ss(a8_0, b8));
_mm_store_ss(&C[(i*64)+2], c8_0);
__m128 c8_1 = _mm_load_ss(&C[(i*64)+8]);
__m128 a8_1 = _mm_load_ss(&values[40]);
c8_1 = _mm_add_ss(c8_1, _mm_mul_ss(a8_1, b8));
_mm_store_ss(&C[(i*64)+8], c8_1);
__m128 c8_2 = _mm_load_ss(&C[(i*64)+18]);
__m128 a8_2 = _mm_load_ss(&values[41]);
c8_2 = _mm_add_ss(c8_2, _mm_mul_ss(a8_2, b8));
_mm_store_ss(&C[(i*64)+18], c8_2);
__m128 c8_3 = _mm_load_ss(&C[(i*64)+33]);
__m128 a8_3 = _mm_load_ss(&values[42]);
c8_3 = _mm_add_ss(c8_3, _mm_mul_ss(a8_3, b8));
_mm_store_ss(&C[(i*64)+33], c8_3);
__m128 c8_4 = _mm_load_ss(&C[(i*64)+54]);
__m128 a8_4 = _mm_load_ss(&values[43]);
c8_4 = _mm_add_ss(c8_4, _mm_mul_ss(a8_4, b8));
_mm_store_ss(&C[(i*64)+54], c8_4);
#else
C[(i*64)+2] += values[39] * B[(i*64)+8];
C[(i*64)+8] += values[40] * B[(i*64)+8];
C[(i*64)+18] += values[41] * B[(i*64)+8];
C[(i*64)+33] += values[42] * B[(i*64)+8];
C[(i*64)+54] += values[43] * B[(i*64)+8];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b9 = _mm_broadcast_ss(&B[(i*64)+9]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b9 = _mm_load_ss(&B[(i*64)+9]);
b9 = _mm_shuffle_ps(b9, b9, 0x00);
#endif
__m128 c9_0 = _mm_load_ss(&C[(i*64)+0]);
__m128 a9_0 = _mm_load_ss(&values[44]);
c9_0 = _mm_add_ss(c9_0, _mm_mul_ss(a9_0, b9));
_mm_store_ss(&C[(i*64)+0], c9_0);
__m128 c9_1 = _mm_load_ss(&C[(i*64)+3]);
__m128 a9_1 = _mm_load_ss(&values[45]);
c9_1 = _mm_add_ss(c9_1, _mm_mul_ss(a9_1, b9));
_mm_store_ss(&C[(i*64)+3], c9_1);
__m128 c9_2 = _mm_load_ss(&C[(i*64)+9]);
__m128 a9_2 = _mm_load_ss(&values[46]);
c9_2 = _mm_add_ss(c9_2, _mm_mul_ss(a9_2, b9));
_mm_store_ss(&C[(i*64)+9], c9_2);
__m128 c9_3 = _mm_load_ss(&C[(i*64)+19]);
__m128 a9_3 = _mm_load_ss(&values[47]);
c9_3 = _mm_add_ss(c9_3, _mm_mul_ss(a9_3, b9));
_mm_store_ss(&C[(i*64)+19], c9_3);
__m128 c9_4 = _mm_load_ss(&C[(i*64)+34]);
__m128 a9_4 = _mm_load_ss(&values[48]);
c9_4 = _mm_add_ss(c9_4, _mm_mul_ss(a9_4, b9));
_mm_store_ss(&C[(i*64)+34], c9_4);
__m128 c9_5 = _mm_load_ss(&C[(i*64)+55]);
__m128 a9_5 = _mm_load_ss(&values[49]);
c9_5 = _mm_add_ss(c9_5, _mm_mul_ss(a9_5, b9));
_mm_store_ss(&C[(i*64)+55], c9_5);
#else
C[(i*64)+0] += values[44] * B[(i*64)+9];
C[(i*64)+3] += values[45] * B[(i*64)+9];
C[(i*64)+9] += values[46] * B[(i*64)+9];
C[(i*64)+19] += values[47] * B[(i*64)+9];
C[(i*64)+34] += values[48] * B[(i*64)+9];
C[(i*64)+55] += values[49] * B[(i*64)+9];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b10 = _mm_broadcast_ss(&B[(i*64)+10]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b10 = _mm_load_ss(&B[(i*64)+10]);
b10 = _mm_shuffle_ps(b10, b10, 0x00);
#endif
__m128 c10_0 = _mm_load_ss(&C[(i*64)+10]);
__m128 a10_0 = _mm_load_ss(&values[50]);
c10_0 = _mm_add_ss(c10_0, _mm_mul_ss(a10_0, b10));
_mm_store_ss(&C[(i*64)+10], c10_0);
__m128 c10_1 = _mm_load_ss(&C[(i*64)+25]);
__m128 a10_1 = _mm_load_ss(&values[51]);
c10_1 = _mm_add_ss(c10_1, _mm_mul_ss(a10_1, b10));
_mm_store_ss(&C[(i*64)+25], c10_1);
__m128 c10_2 = _mm_load_ss(&C[(i*64)+46]);
__m128 a10_2 = _mm_load_ss(&values[52]);
c10_2 = _mm_add_ss(c10_2, _mm_mul_ss(a10_2, b10));
_mm_store_ss(&C[(i*64)+46], c10_2);
#else
C[(i*64)+10] += values[50] * B[(i*64)+10];
C[(i*64)+25] += values[51] * B[(i*64)+10];
C[(i*64)+46] += values[52] * B[(i*64)+10];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b11 = _mm_broadcast_ss(&B[(i*64)+11]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b11 = _mm_load_ss(&B[(i*64)+11]);
b11 = _mm_shuffle_ps(b11, b11, 0x00);
#endif
__m128 c11_0 = _mm_load_ss(&C[(i*64)+11]);
__m128 a11_0 = _mm_load_ss(&values[53]);
c11_0 = _mm_add_ss(c11_0, _mm_mul_ss(a11_0, b11));
_mm_store_ss(&C[(i*64)+11], c11_0);
__m128 c11_1 = _mm_load_ss(&C[(i*64)+26]);
__m128 a11_1 = _mm_load_ss(&values[54]);
c11_1 = _mm_add_ss(c11_1, _mm_mul_ss(a11_1, b11));
_mm_store_ss(&C[(i*64)+26], c11_1);
__m128 c11_2 = _mm_load_ss(&C[(i*64)+47]);
__m128 a11_2 = _mm_load_ss(&values[55]);
c11_2 = _mm_add_ss(c11_2, _mm_mul_ss(a11_2, b11));
_mm_store_ss(&C[(i*64)+47], c11_2);
#else
C[(i*64)+11] += values[53] * B[(i*64)+11];
C[(i*64)+26] += values[54] * B[(i*64)+11];
C[(i*64)+47] += values[55] * B[(i*64)+11];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b12 = _mm_broadcast_ss(&B[(i*64)+12]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b12 = _mm_load_ss(&B[(i*64)+12]);
b12 = _mm_shuffle_ps(b12, b12, 0x00);
#endif
__m128 c12_0 = _mm_load_ss(&C[(i*64)+12]);
__m128 a12_0 = _mm_load_ss(&values[56]);
c12_0 = _mm_add_ss(c12_0, _mm_mul_ss(a12_0, b12));
_mm_store_ss(&C[(i*64)+12], c12_0);
__m128 c12_1 = _mm_load_ss(&C[(i*64)+27]);
__m128 a12_1 = _mm_load_ss(&values[57]);
c12_1 = _mm_add_ss(c12_1, _mm_mul_ss(a12_1, b12));
_mm_store_ss(&C[(i*64)+27], c12_1);
__m128 c12_2 = _mm_load_ss(&C[(i*64)+48]);
__m128 a12_2 = _mm_load_ss(&values[58]);
c12_2 = _mm_add_ss(c12_2, _mm_mul_ss(a12_2, b12));
_mm_store_ss(&C[(i*64)+48], c12_2);
#else
C[(i*64)+12] += values[56] * B[(i*64)+12];
C[(i*64)+27] += values[57] * B[(i*64)+12];
C[(i*64)+48] += values[58] * B[(i*64)+12];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b13 = _mm_broadcast_ss(&B[(i*64)+13]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b13 = _mm_load_ss(&B[(i*64)+13]);
b13 = _mm_shuffle_ps(b13, b13, 0x00);
#endif
__m128 c13_0 = _mm_load_ss(&C[(i*64)+13]);
__m128 a13_0 = _mm_load_ss(&values[59]);
c13_0 = _mm_add_ss(c13_0, _mm_mul_ss(a13_0, b13));
_mm_store_ss(&C[(i*64)+13], c13_0);
__m128 c13_1 = _mm_load_ss(&C[(i*64)+28]);
__m128 a13_1 = _mm_load_ss(&values[60]);
c13_1 = _mm_add_ss(c13_1, _mm_mul_ss(a13_1, b13));
_mm_store_ss(&C[(i*64)+28], c13_1);
__m128 c13_2 = _mm_load_ss(&C[(i*64)+49]);
__m128 a13_2 = _mm_load_ss(&values[61]);
c13_2 = _mm_add_ss(c13_2, _mm_mul_ss(a13_2, b13));
_mm_store_ss(&C[(i*64)+49], c13_2);
#else
C[(i*64)+13] += values[59] * B[(i*64)+13];
C[(i*64)+28] += values[60] * B[(i*64)+13];
C[(i*64)+49] += values[61] * B[(i*64)+13];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b14 = _mm_broadcast_ss(&B[(i*64)+14]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b14 = _mm_load_ss(&B[(i*64)+14]);
b14 = _mm_shuffle_ps(b14, b14, 0x00);
#endif
__m128 c14_0 = _mm_load_ss(&C[(i*64)+4]);
__m128 a14_0 = _mm_load_ss(&values[62]);
c14_0 = _mm_add_ss(c14_0, _mm_mul_ss(a14_0, b14));
_mm_store_ss(&C[(i*64)+4], c14_0);
__m128 c14_1 = _mm_load_ss(&C[(i*64)+14]);
__m128 a14_1 = _mm_load_ss(&values[63]);
c14_1 = _mm_add_ss(c14_1, _mm_mul_ss(a14_1, b14));
_mm_store_ss(&C[(i*64)+14], c14_1);
__m128 c14_2 = _mm_load_ss(&C[(i*64)+29]);
__m128 a14_2 = _mm_load_ss(&values[64]);
c14_2 = _mm_add_ss(c14_2, _mm_mul_ss(a14_2, b14));
_mm_store_ss(&C[(i*64)+29], c14_2);
__m128 c14_3 = _mm_load_ss(&C[(i*64)+50]);
__m128 a14_3 = _mm_load_ss(&values[65]);
c14_3 = _mm_add_ss(c14_3, _mm_mul_ss(a14_3, b14));
_mm_store_ss(&C[(i*64)+50], c14_3);
#else
C[(i*64)+4] += values[62] * B[(i*64)+14];
C[(i*64)+14] += values[63] * B[(i*64)+14];
C[(i*64)+29] += values[64] * B[(i*64)+14];
C[(i*64)+50] += values[65] * B[(i*64)+14];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b15 = _mm_broadcast_ss(&B[(i*64)+15]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b15 = _mm_load_ss(&B[(i*64)+15]);
b15 = _mm_shuffle_ps(b15, b15, 0x00);
#endif
__m128 c15_0 = _mm_load_ss(&C[(i*64)+5]);
__m128 a15_0 = _mm_load_ss(&values[66]);
c15_0 = _mm_add_ss(c15_0, _mm_mul_ss(a15_0, b15));
_mm_store_ss(&C[(i*64)+5], c15_0);
__m128 c15_1 = _mm_load_ss(&C[(i*64)+15]);
__m128 a15_1 = _mm_load_ss(&values[67]);
c15_1 = _mm_add_ss(c15_1, _mm_mul_ss(a15_1, b15));
_mm_store_ss(&C[(i*64)+15], c15_1);
__m128 c15_2 = _mm_load_ss(&C[(i*64)+30]);
__m128 a15_2 = _mm_load_ss(&values[68]);
c15_2 = _mm_add_ss(c15_2, _mm_mul_ss(a15_2, b15));
_mm_store_ss(&C[(i*64)+30], c15_2);
__m128 c15_3 = _mm_load_ss(&C[(i*64)+51]);
__m128 a15_3 = _mm_load_ss(&values[69]);
c15_3 = _mm_add_ss(c15_3, _mm_mul_ss(a15_3, b15));
_mm_store_ss(&C[(i*64)+51], c15_3);
#else
C[(i*64)+5] += values[66] * B[(i*64)+15];
C[(i*64)+15] += values[67] * B[(i*64)+15];
C[(i*64)+30] += values[68] * B[(i*64)+15];
C[(i*64)+51] += values[69] * B[(i*64)+15];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b16 = _mm_broadcast_ss(&B[(i*64)+16]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b16 = _mm_load_ss(&B[(i*64)+16]);
b16 = _mm_shuffle_ps(b16, b16, 0x00);
#endif
__m128 c16_0 = _mm_load_ss(&C[(i*64)+6]);
__m128 a16_0 = _mm_load_ss(&values[70]);
c16_0 = _mm_add_ss(c16_0, _mm_mul_ss(a16_0, b16));
_mm_store_ss(&C[(i*64)+6], c16_0);
__m128 c16_1 = _mm_load_ss(&C[(i*64)+16]);
__m128 a16_1 = _mm_load_ss(&values[71]);
c16_1 = _mm_add_ss(c16_1, _mm_mul_ss(a16_1, b16));
_mm_store_ss(&C[(i*64)+16], c16_1);
__m128 c16_2 = _mm_load_ss(&C[(i*64)+31]);
__m128 a16_2 = _mm_load_ss(&values[72]);
c16_2 = _mm_add_ss(c16_2, _mm_mul_ss(a16_2, b16));
_mm_store_ss(&C[(i*64)+31], c16_2);
__m128 c16_3 = _mm_load_ss(&C[(i*64)+52]);
__m128 a16_3 = _mm_load_ss(&values[73]);
c16_3 = _mm_add_ss(c16_3, _mm_mul_ss(a16_3, b16));
_mm_store_ss(&C[(i*64)+52], c16_3);
#else
C[(i*64)+6] += values[70] * B[(i*64)+16];
C[(i*64)+16] += values[71] * B[(i*64)+16];
C[(i*64)+31] += values[72] * B[(i*64)+16];
C[(i*64)+52] += values[73] * B[(i*64)+16];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b17 = _mm_broadcast_ss(&B[(i*64)+17]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b17 = _mm_load_ss(&B[(i*64)+17]);
b17 = _mm_shuffle_ps(b17, b17, 0x00);
#endif
__m128 c17_0 = _mm_load_ss(&C[(i*64)+1]);
__m128 a17_0 = _mm_load_ss(&values[74]);
c17_0 = _mm_add_ss(c17_0, _mm_mul_ss(a17_0, b17));
_mm_store_ss(&C[(i*64)+1], c17_0);
__m128 c17_1 = _mm_load_ss(&C[(i*64)+7]);
__m128 a17_1 = _mm_load_ss(&values[75]);
c17_1 = _mm_add_ss(c17_1, _mm_mul_ss(a17_1, b17));
_mm_store_ss(&C[(i*64)+7], c17_1);
__m128 c17_2 = _mm_load_ss(&C[(i*64)+17]);
__m128 a17_2 = _mm_load_ss(&values[76]);
c17_2 = _mm_add_ss(c17_2, _mm_mul_ss(a17_2, b17));
_mm_store_ss(&C[(i*64)+17], c17_2);
__m128 c17_3 = _mm_load_ss(&C[(i*64)+32]);
__m128 a17_3 = _mm_load_ss(&values[77]);
c17_3 = _mm_add_ss(c17_3, _mm_mul_ss(a17_3, b17));
_mm_store_ss(&C[(i*64)+32], c17_3);
__m128 c17_4 = _mm_load_ss(&C[(i*64)+53]);
__m128 a17_4 = _mm_load_ss(&values[78]);
c17_4 = _mm_add_ss(c17_4, _mm_mul_ss(a17_4, b17));
_mm_store_ss(&C[(i*64)+53], c17_4);
#else
C[(i*64)+1] += values[74] * B[(i*64)+17];
C[(i*64)+7] += values[75] * B[(i*64)+17];
C[(i*64)+17] += values[76] * B[(i*64)+17];
C[(i*64)+32] += values[77] * B[(i*64)+17];
C[(i*64)+53] += values[78] * B[(i*64)+17];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b18 = _mm_broadcast_ss(&B[(i*64)+18]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b18 = _mm_load_ss(&B[(i*64)+18]);
b18 = _mm_shuffle_ps(b18, b18, 0x00);
#endif
__m128 c18_0 = _mm_load_ss(&C[(i*64)+2]);
__m128 a18_0 = _mm_load_ss(&values[79]);
c18_0 = _mm_add_ss(c18_0, _mm_mul_ss(a18_0, b18));
_mm_store_ss(&C[(i*64)+2], c18_0);
__m128 c18_1 = _mm_load_ss(&C[(i*64)+8]);
__m128 a18_1 = _mm_load_ss(&values[80]);
c18_1 = _mm_add_ss(c18_1, _mm_mul_ss(a18_1, b18));
_mm_store_ss(&C[(i*64)+8], c18_1);
__m128 c18_2 = _mm_load_ss(&C[(i*64)+18]);
__m128 a18_2 = _mm_load_ss(&values[81]);
c18_2 = _mm_add_ss(c18_2, _mm_mul_ss(a18_2, b18));
_mm_store_ss(&C[(i*64)+18], c18_2);
__m128 c18_3 = _mm_load_ss(&C[(i*64)+33]);
__m128 a18_3 = _mm_load_ss(&values[82]);
c18_3 = _mm_add_ss(c18_3, _mm_mul_ss(a18_3, b18));
_mm_store_ss(&C[(i*64)+33], c18_3);
__m128 c18_4 = _mm_load_ss(&C[(i*64)+54]);
__m128 a18_4 = _mm_load_ss(&values[83]);
c18_4 = _mm_add_ss(c18_4, _mm_mul_ss(a18_4, b18));
_mm_store_ss(&C[(i*64)+54], c18_4);
#else
C[(i*64)+2] += values[79] * B[(i*64)+18];
C[(i*64)+8] += values[80] * B[(i*64)+18];
C[(i*64)+18] += values[81] * B[(i*64)+18];
C[(i*64)+33] += values[82] * B[(i*64)+18];
C[(i*64)+54] += values[83] * B[(i*64)+18];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b19 = _mm_broadcast_ss(&B[(i*64)+19]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b19 = _mm_load_ss(&B[(i*64)+19]);
b19 = _mm_shuffle_ps(b19, b19, 0x00);
#endif
__m128 c19_0 = _mm_load_ss(&C[(i*64)+0]);
__m128 a19_0 = _mm_load_ss(&values[84]);
c19_0 = _mm_add_ss(c19_0, _mm_mul_ss(a19_0, b19));
_mm_store_ss(&C[(i*64)+0], c19_0);
__m128 c19_1 = _mm_load_ss(&C[(i*64)+3]);
__m128 a19_1 = _mm_load_ss(&values[85]);
c19_1 = _mm_add_ss(c19_1, _mm_mul_ss(a19_1, b19));
_mm_store_ss(&C[(i*64)+3], c19_1);
__m128 c19_2 = _mm_load_ss(&C[(i*64)+9]);
__m128 a19_2 = _mm_load_ss(&values[86]);
c19_2 = _mm_add_ss(c19_2, _mm_mul_ss(a19_2, b19));
_mm_store_ss(&C[(i*64)+9], c19_2);
__m128 c19_3 = _mm_load_ss(&C[(i*64)+19]);
__m128 a19_3 = _mm_load_ss(&values[87]);
c19_3 = _mm_add_ss(c19_3, _mm_mul_ss(a19_3, b19));
_mm_store_ss(&C[(i*64)+19], c19_3);
__m128 c19_4 = _mm_load_ss(&C[(i*64)+34]);
__m128 a19_4 = _mm_load_ss(&values[88]);
c19_4 = _mm_add_ss(c19_4, _mm_mul_ss(a19_4, b19));
_mm_store_ss(&C[(i*64)+34], c19_4);
__m128 c19_5 = _mm_load_ss(&C[(i*64)+55]);
__m128 a19_5 = _mm_load_ss(&values[89]);
c19_5 = _mm_add_ss(c19_5, _mm_mul_ss(a19_5, b19));
_mm_store_ss(&C[(i*64)+55], c19_5);
#else
C[(i*64)+0] += values[84] * B[(i*64)+19];
C[(i*64)+3] += values[85] * B[(i*64)+19];
C[(i*64)+9] += values[86] * B[(i*64)+19];
C[(i*64)+19] += values[87] * B[(i*64)+19];
C[(i*64)+34] += values[88] * B[(i*64)+19];
C[(i*64)+55] += values[89] * B[(i*64)+19];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b20 = _mm_broadcast_ss(&B[(i*64)+20]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b20 = _mm_load_ss(&B[(i*64)+20]);
b20 = _mm_shuffle_ps(b20, b20, 0x00);
#endif
__m128 c20_0 = _mm_load_ss(&C[(i*64)+20]);
__m128 a20_0 = _mm_load_ss(&values[90]);
c20_0 = _mm_add_ss(c20_0, _mm_mul_ss(a20_0, b20));
_mm_store_ss(&C[(i*64)+20], c20_0);
__m128 c20_1 = _mm_load_ss(&C[(i*64)+41]);
__m128 a20_1 = _mm_load_ss(&values[91]);
c20_1 = _mm_add_ss(c20_1, _mm_mul_ss(a20_1, b20));
_mm_store_ss(&C[(i*64)+41], c20_1);
#else
C[(i*64)+20] += values[90] * B[(i*64)+20];
C[(i*64)+41] += values[91] * B[(i*64)+20];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b21 = _mm_broadcast_ss(&B[(i*64)+21]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b21 = _mm_load_ss(&B[(i*64)+21]);
b21 = _mm_shuffle_ps(b21, b21, 0x00);
#endif
__m128 c21_0 = _mm_load_ss(&C[(i*64)+21]);
__m128 a21_0 = _mm_load_ss(&values[92]);
c21_0 = _mm_add_ss(c21_0, _mm_mul_ss(a21_0, b21));
_mm_store_ss(&C[(i*64)+21], c21_0);
__m128 c21_1 = _mm_load_ss(&C[(i*64)+42]);
__m128 a21_1 = _mm_load_ss(&values[93]);
c21_1 = _mm_add_ss(c21_1, _mm_mul_ss(a21_1, b21));
_mm_store_ss(&C[(i*64)+42], c21_1);
#else
C[(i*64)+21] += values[92] * B[(i*64)+21];
C[(i*64)+42] += values[93] * B[(i*64)+21];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b22 = _mm_broadcast_ss(&B[(i*64)+22]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b22 = _mm_load_ss(&B[(i*64)+22]);
b22 = _mm_shuffle_ps(b22, b22, 0x00);
#endif
__m128 c22_0 = _mm_load_ss(&C[(i*64)+22]);
__m128 a22_0 = _mm_load_ss(&values[94]);
c22_0 = _mm_add_ss(c22_0, _mm_mul_ss(a22_0, b22));
_mm_store_ss(&C[(i*64)+22], c22_0);
__m128 c22_1 = _mm_load_ss(&C[(i*64)+43]);
__m128 a22_1 = _mm_load_ss(&values[95]);
c22_1 = _mm_add_ss(c22_1, _mm_mul_ss(a22_1, b22));
_mm_store_ss(&C[(i*64)+43], c22_1);
#else
C[(i*64)+22] += values[94] * B[(i*64)+22];
C[(i*64)+43] += values[95] * B[(i*64)+22];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b23 = _mm_broadcast_ss(&B[(i*64)+23]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b23 = _mm_load_ss(&B[(i*64)+23]);
b23 = _mm_shuffle_ps(b23, b23, 0x00);
#endif
__m128 c23_0 = _mm_load_ss(&C[(i*64)+23]);
__m128 a23_0 = _mm_load_ss(&values[96]);
c23_0 = _mm_add_ss(c23_0, _mm_mul_ss(a23_0, b23));
_mm_store_ss(&C[(i*64)+23], c23_0);
__m128 c23_1 = _mm_load_ss(&C[(i*64)+44]);
__m128 a23_1 = _mm_load_ss(&values[97]);
c23_1 = _mm_add_ss(c23_1, _mm_mul_ss(a23_1, b23));
_mm_store_ss(&C[(i*64)+44], c23_1);
#else
C[(i*64)+23] += values[96] * B[(i*64)+23];
C[(i*64)+44] += values[97] * B[(i*64)+23];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b24 = _mm_broadcast_ss(&B[(i*64)+24]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b24 = _mm_load_ss(&B[(i*64)+24]);
b24 = _mm_shuffle_ps(b24, b24, 0x00);
#endif
__m128 c24_0 = _mm_load_ss(&C[(i*64)+24]);
__m128 a24_0 = _mm_load_ss(&values[98]);
c24_0 = _mm_add_ss(c24_0, _mm_mul_ss(a24_0, b24));
_mm_store_ss(&C[(i*64)+24], c24_0);
__m128 c24_1 = _mm_load_ss(&C[(i*64)+45]);
__m128 a24_1 = _mm_load_ss(&values[99]);
c24_1 = _mm_add_ss(c24_1, _mm_mul_ss(a24_1, b24));
_mm_store_ss(&C[(i*64)+45], c24_1);
#else
C[(i*64)+24] += values[98] * B[(i*64)+24];
C[(i*64)+45] += values[99] * B[(i*64)+24];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b25 = _mm_broadcast_ss(&B[(i*64)+25]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b25 = _mm_load_ss(&B[(i*64)+25]);
b25 = _mm_shuffle_ps(b25, b25, 0x00);
#endif
__m128 c25_0 = _mm_load_ss(&C[(i*64)+10]);
__m128 a25_0 = _mm_load_ss(&values[100]);
c25_0 = _mm_add_ss(c25_0, _mm_mul_ss(a25_0, b25));
_mm_store_ss(&C[(i*64)+10], c25_0);
__m128 c25_1 = _mm_load_ss(&C[(i*64)+25]);
__m128 a25_1 = _mm_load_ss(&values[101]);
c25_1 = _mm_add_ss(c25_1, _mm_mul_ss(a25_1, b25));
_mm_store_ss(&C[(i*64)+25], c25_1);
__m128 c25_2 = _mm_load_ss(&C[(i*64)+46]);
__m128 a25_2 = _mm_load_ss(&values[102]);
c25_2 = _mm_add_ss(c25_2, _mm_mul_ss(a25_2, b25));
_mm_store_ss(&C[(i*64)+46], c25_2);
#else
C[(i*64)+10] += values[100] * B[(i*64)+25];
C[(i*64)+25] += values[101] * B[(i*64)+25];
C[(i*64)+46] += values[102] * B[(i*64)+25];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b26 = _mm_broadcast_ss(&B[(i*64)+26]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b26 = _mm_load_ss(&B[(i*64)+26]);
b26 = _mm_shuffle_ps(b26, b26, 0x00);
#endif
__m128 c26_0 = _mm_load_ss(&C[(i*64)+11]);
__m128 a26_0 = _mm_load_ss(&values[103]);
c26_0 = _mm_add_ss(c26_0, _mm_mul_ss(a26_0, b26));
_mm_store_ss(&C[(i*64)+11], c26_0);
__m128 c26_1 = _mm_load_ss(&C[(i*64)+26]);
__m128 a26_1 = _mm_load_ss(&values[104]);
c26_1 = _mm_add_ss(c26_1, _mm_mul_ss(a26_1, b26));
_mm_store_ss(&C[(i*64)+26], c26_1);
__m128 c26_2 = _mm_load_ss(&C[(i*64)+47]);
__m128 a26_2 = _mm_load_ss(&values[105]);
c26_2 = _mm_add_ss(c26_2, _mm_mul_ss(a26_2, b26));
_mm_store_ss(&C[(i*64)+47], c26_2);
#else
C[(i*64)+11] += values[103] * B[(i*64)+26];
C[(i*64)+26] += values[104] * B[(i*64)+26];
C[(i*64)+47] += values[105] * B[(i*64)+26];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b27 = _mm_broadcast_ss(&B[(i*64)+27]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b27 = _mm_load_ss(&B[(i*64)+27]);
b27 = _mm_shuffle_ps(b27, b27, 0x00);
#endif
__m128 c27_0 = _mm_load_ss(&C[(i*64)+12]);
__m128 a27_0 = _mm_load_ss(&values[106]);
c27_0 = _mm_add_ss(c27_0, _mm_mul_ss(a27_0, b27));
_mm_store_ss(&C[(i*64)+12], c27_0);
__m128 c27_1 = _mm_load_ss(&C[(i*64)+27]);
__m128 a27_1 = _mm_load_ss(&values[107]);
c27_1 = _mm_add_ss(c27_1, _mm_mul_ss(a27_1, b27));
_mm_store_ss(&C[(i*64)+27], c27_1);
__m128 c27_2 = _mm_load_ss(&C[(i*64)+48]);
__m128 a27_2 = _mm_load_ss(&values[108]);
c27_2 = _mm_add_ss(c27_2, _mm_mul_ss(a27_2, b27));
_mm_store_ss(&C[(i*64)+48], c27_2);
#else
C[(i*64)+12] += values[106] * B[(i*64)+27];
C[(i*64)+27] += values[107] * B[(i*64)+27];
C[(i*64)+48] += values[108] * B[(i*64)+27];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b28 = _mm_broadcast_ss(&B[(i*64)+28]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b28 = _mm_load_ss(&B[(i*64)+28]);
b28 = _mm_shuffle_ps(b28, b28, 0x00);
#endif
__m128 c28_0 = _mm_load_ss(&C[(i*64)+13]);
__m128 a28_0 = _mm_load_ss(&values[109]);
c28_0 = _mm_add_ss(c28_0, _mm_mul_ss(a28_0, b28));
_mm_store_ss(&C[(i*64)+13], c28_0);
__m128 c28_1 = _mm_load_ss(&C[(i*64)+28]);
__m128 a28_1 = _mm_load_ss(&values[110]);
c28_1 = _mm_add_ss(c28_1, _mm_mul_ss(a28_1, b28));
_mm_store_ss(&C[(i*64)+28], c28_1);
__m128 c28_2 = _mm_load_ss(&C[(i*64)+49]);
__m128 a28_2 = _mm_load_ss(&values[111]);
c28_2 = _mm_add_ss(c28_2, _mm_mul_ss(a28_2, b28));
_mm_store_ss(&C[(i*64)+49], c28_2);
#else
C[(i*64)+13] += values[109] * B[(i*64)+28];
C[(i*64)+28] += values[110] * B[(i*64)+28];
C[(i*64)+49] += values[111] * B[(i*64)+28];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b29 = _mm_broadcast_ss(&B[(i*64)+29]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b29 = _mm_load_ss(&B[(i*64)+29]);
b29 = _mm_shuffle_ps(b29, b29, 0x00);
#endif
__m128 c29_0 = _mm_load_ss(&C[(i*64)+4]);
__m128 a29_0 = _mm_load_ss(&values[112]);
c29_0 = _mm_add_ss(c29_0, _mm_mul_ss(a29_0, b29));
_mm_store_ss(&C[(i*64)+4], c29_0);
__m128 c29_1 = _mm_load_ss(&C[(i*64)+14]);
__m128 a29_1 = _mm_load_ss(&values[113]);
c29_1 = _mm_add_ss(c29_1, _mm_mul_ss(a29_1, b29));
_mm_store_ss(&C[(i*64)+14], c29_1);
__m128 c29_2 = _mm_load_ss(&C[(i*64)+29]);
__m128 a29_2 = _mm_load_ss(&values[114]);
c29_2 = _mm_add_ss(c29_2, _mm_mul_ss(a29_2, b29));
_mm_store_ss(&C[(i*64)+29], c29_2);
__m128 c29_3 = _mm_load_ss(&C[(i*64)+50]);
__m128 a29_3 = _mm_load_ss(&values[115]);
c29_3 = _mm_add_ss(c29_3, _mm_mul_ss(a29_3, b29));
_mm_store_ss(&C[(i*64)+50], c29_3);
#else
C[(i*64)+4] += values[112] * B[(i*64)+29];
C[(i*64)+14] += values[113] * B[(i*64)+29];
C[(i*64)+29] += values[114] * B[(i*64)+29];
C[(i*64)+50] += values[115] * B[(i*64)+29];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b30 = _mm_broadcast_ss(&B[(i*64)+30]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b30 = _mm_load_ss(&B[(i*64)+30]);
b30 = _mm_shuffle_ps(b30, b30, 0x00);
#endif
__m128 c30_0 = _mm_load_ss(&C[(i*64)+5]);
__m128 a30_0 = _mm_load_ss(&values[116]);
c30_0 = _mm_add_ss(c30_0, _mm_mul_ss(a30_0, b30));
_mm_store_ss(&C[(i*64)+5], c30_0);
__m128 c30_1 = _mm_load_ss(&C[(i*64)+15]);
__m128 a30_1 = _mm_load_ss(&values[117]);
c30_1 = _mm_add_ss(c30_1, _mm_mul_ss(a30_1, b30));
_mm_store_ss(&C[(i*64)+15], c30_1);
__m128 c30_2 = _mm_load_ss(&C[(i*64)+30]);
__m128 a30_2 = _mm_load_ss(&values[118]);
c30_2 = _mm_add_ss(c30_2, _mm_mul_ss(a30_2, b30));
_mm_store_ss(&C[(i*64)+30], c30_2);
__m128 c30_3 = _mm_load_ss(&C[(i*64)+51]);
__m128 a30_3 = _mm_load_ss(&values[119]);
c30_3 = _mm_add_ss(c30_3, _mm_mul_ss(a30_3, b30));
_mm_store_ss(&C[(i*64)+51], c30_3);
#else
C[(i*64)+5] += values[116] * B[(i*64)+30];
C[(i*64)+15] += values[117] * B[(i*64)+30];
C[(i*64)+30] += values[118] * B[(i*64)+30];
C[(i*64)+51] += values[119] * B[(i*64)+30];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b31 = _mm_broadcast_ss(&B[(i*64)+31]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b31 = _mm_load_ss(&B[(i*64)+31]);
b31 = _mm_shuffle_ps(b31, b31, 0x00);
#endif
__m128 c31_0 = _mm_load_ss(&C[(i*64)+6]);
__m128 a31_0 = _mm_load_ss(&values[120]);
c31_0 = _mm_add_ss(c31_0, _mm_mul_ss(a31_0, b31));
_mm_store_ss(&C[(i*64)+6], c31_0);
__m128 c31_1 = _mm_load_ss(&C[(i*64)+16]);
__m128 a31_1 = _mm_load_ss(&values[121]);
c31_1 = _mm_add_ss(c31_1, _mm_mul_ss(a31_1, b31));
_mm_store_ss(&C[(i*64)+16], c31_1);
__m128 c31_2 = _mm_load_ss(&C[(i*64)+31]);
__m128 a31_2 = _mm_load_ss(&values[122]);
c31_2 = _mm_add_ss(c31_2, _mm_mul_ss(a31_2, b31));
_mm_store_ss(&C[(i*64)+31], c31_2);
__m128 c31_3 = _mm_load_ss(&C[(i*64)+52]);
__m128 a31_3 = _mm_load_ss(&values[123]);
c31_3 = _mm_add_ss(c31_3, _mm_mul_ss(a31_3, b31));
_mm_store_ss(&C[(i*64)+52], c31_3);
#else
C[(i*64)+6] += values[120] * B[(i*64)+31];
C[(i*64)+16] += values[121] * B[(i*64)+31];
C[(i*64)+31] += values[122] * B[(i*64)+31];
C[(i*64)+52] += values[123] * B[(i*64)+31];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b32 = _mm_broadcast_ss(&B[(i*64)+32]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b32 = _mm_load_ss(&B[(i*64)+32]);
b32 = _mm_shuffle_ps(b32, b32, 0x00);
#endif
__m128 c32_0 = _mm_load_ss(&C[(i*64)+1]);
__m128 a32_0 = _mm_load_ss(&values[124]);
c32_0 = _mm_add_ss(c32_0, _mm_mul_ss(a32_0, b32));
_mm_store_ss(&C[(i*64)+1], c32_0);
__m128 c32_1 = _mm_load_ss(&C[(i*64)+7]);
__m128 a32_1 = _mm_load_ss(&values[125]);
c32_1 = _mm_add_ss(c32_1, _mm_mul_ss(a32_1, b32));
_mm_store_ss(&C[(i*64)+7], c32_1);
__m128 c32_2 = _mm_load_ss(&C[(i*64)+17]);
__m128 a32_2 = _mm_load_ss(&values[126]);
c32_2 = _mm_add_ss(c32_2, _mm_mul_ss(a32_2, b32));
_mm_store_ss(&C[(i*64)+17], c32_2);
__m128 c32_3 = _mm_load_ss(&C[(i*64)+32]);
__m128 a32_3 = _mm_load_ss(&values[127]);
c32_3 = _mm_add_ss(c32_3, _mm_mul_ss(a32_3, b32));
_mm_store_ss(&C[(i*64)+32], c32_3);
__m128 c32_4 = _mm_load_ss(&C[(i*64)+53]);
__m128 a32_4 = _mm_load_ss(&values[128]);
c32_4 = _mm_add_ss(c32_4, _mm_mul_ss(a32_4, b32));
_mm_store_ss(&C[(i*64)+53], c32_4);
#else
C[(i*64)+1] += values[124] * B[(i*64)+32];
C[(i*64)+7] += values[125] * B[(i*64)+32];
C[(i*64)+17] += values[126] * B[(i*64)+32];
C[(i*64)+32] += values[127] * B[(i*64)+32];
C[(i*64)+53] += values[128] * B[(i*64)+32];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b33 = _mm_broadcast_ss(&B[(i*64)+33]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b33 = _mm_load_ss(&B[(i*64)+33]);
b33 = _mm_shuffle_ps(b33, b33, 0x00);
#endif
__m128 c33_0 = _mm_load_ss(&C[(i*64)+2]);
__m128 a33_0 = _mm_load_ss(&values[129]);
c33_0 = _mm_add_ss(c33_0, _mm_mul_ss(a33_0, b33));
_mm_store_ss(&C[(i*64)+2], c33_0);
__m128 c33_1 = _mm_load_ss(&C[(i*64)+8]);
__m128 a33_1 = _mm_load_ss(&values[130]);
c33_1 = _mm_add_ss(c33_1, _mm_mul_ss(a33_1, b33));
_mm_store_ss(&C[(i*64)+8], c33_1);
__m128 c33_2 = _mm_load_ss(&C[(i*64)+18]);
__m128 a33_2 = _mm_load_ss(&values[131]);
c33_2 = _mm_add_ss(c33_2, _mm_mul_ss(a33_2, b33));
_mm_store_ss(&C[(i*64)+18], c33_2);
__m128 c33_3 = _mm_load_ss(&C[(i*64)+33]);
__m128 a33_3 = _mm_load_ss(&values[132]);
c33_3 = _mm_add_ss(c33_3, _mm_mul_ss(a33_3, b33));
_mm_store_ss(&C[(i*64)+33], c33_3);
__m128 c33_4 = _mm_load_ss(&C[(i*64)+54]);
__m128 a33_4 = _mm_load_ss(&values[133]);
c33_4 = _mm_add_ss(c33_4, _mm_mul_ss(a33_4, b33));
_mm_store_ss(&C[(i*64)+54], c33_4);
#else
C[(i*64)+2] += values[129] * B[(i*64)+33];
C[(i*64)+8] += values[130] * B[(i*64)+33];
C[(i*64)+18] += values[131] * B[(i*64)+33];
C[(i*64)+33] += values[132] * B[(i*64)+33];
C[(i*64)+54] += values[133] * B[(i*64)+33];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b34 = _mm_broadcast_ss(&B[(i*64)+34]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b34 = _mm_load_ss(&B[(i*64)+34]);
b34 = _mm_shuffle_ps(b34, b34, 0x00);
#endif
__m128 c34_0 = _mm_load_ss(&C[(i*64)+0]);
__m128 a34_0 = _mm_load_ss(&values[134]);
c34_0 = _mm_add_ss(c34_0, _mm_mul_ss(a34_0, b34));
_mm_store_ss(&C[(i*64)+0], c34_0);
__m128 c34_1 = _mm_load_ss(&C[(i*64)+3]);
__m128 a34_1 = _mm_load_ss(&values[135]);
c34_1 = _mm_add_ss(c34_1, _mm_mul_ss(a34_1, b34));
_mm_store_ss(&C[(i*64)+3], c34_1);
__m128 c34_2 = _mm_load_ss(&C[(i*64)+9]);
__m128 a34_2 = _mm_load_ss(&values[136]);
c34_2 = _mm_add_ss(c34_2, _mm_mul_ss(a34_2, b34));
_mm_store_ss(&C[(i*64)+9], c34_2);
__m128 c34_3 = _mm_load_ss(&C[(i*64)+19]);
__m128 a34_3 = _mm_load_ss(&values[137]);
c34_3 = _mm_add_ss(c34_3, _mm_mul_ss(a34_3, b34));
_mm_store_ss(&C[(i*64)+19], c34_3);
__m128 c34_4 = _mm_load_ss(&C[(i*64)+34]);
__m128 a34_4 = _mm_load_ss(&values[138]);
c34_4 = _mm_add_ss(c34_4, _mm_mul_ss(a34_4, b34));
_mm_store_ss(&C[(i*64)+34], c34_4);
__m128 c34_5 = _mm_load_ss(&C[(i*64)+55]);
__m128 a34_5 = _mm_load_ss(&values[139]);
c34_5 = _mm_add_ss(c34_5, _mm_mul_ss(a34_5, b34));
_mm_store_ss(&C[(i*64)+55], c34_5);
#else
C[(i*64)+0] += values[134] * B[(i*64)+34];
C[(i*64)+3] += values[135] * B[(i*64)+34];
C[(i*64)+9] += values[136] * B[(i*64)+34];
C[(i*64)+19] += values[137] * B[(i*64)+34];
C[(i*64)+34] += values[138] * B[(i*64)+34];
C[(i*64)+55] += values[139] * B[(i*64)+34];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b35 = _mm_broadcast_ss(&B[(i*64)+35]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b35 = _mm_load_ss(&B[(i*64)+35]);
b35 = _mm_shuffle_ps(b35, b35, 0x00);
#endif
__m128 c35_0 = _mm_load_ss(&C[(i*64)+35]);
__m128 a35_0 = _mm_load_ss(&values[140]);
c35_0 = _mm_add_ss(c35_0, _mm_mul_ss(a35_0, b35));
_mm_store_ss(&C[(i*64)+35], c35_0);
#else
C[(i*64)+35] += values[140] * B[(i*64)+35];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b36 = _mm_broadcast_ss(&B[(i*64)+36]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b36 = _mm_load_ss(&B[(i*64)+36]);
b36 = _mm_shuffle_ps(b36, b36, 0x00);
#endif
__m128 c36_0 = _mm_load_ss(&C[(i*64)+36]);
__m128 a36_0 = _mm_load_ss(&values[141]);
c36_0 = _mm_add_ss(c36_0, _mm_mul_ss(a36_0, b36));
_mm_store_ss(&C[(i*64)+36], c36_0);
#else
C[(i*64)+36] += values[141] * B[(i*64)+36];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b37 = _mm_broadcast_ss(&B[(i*64)+37]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b37 = _mm_load_ss(&B[(i*64)+37]);
b37 = _mm_shuffle_ps(b37, b37, 0x00);
#endif
__m128 c37_0 = _mm_load_ss(&C[(i*64)+37]);
__m128 a37_0 = _mm_load_ss(&values[142]);
c37_0 = _mm_add_ss(c37_0, _mm_mul_ss(a37_0, b37));
_mm_store_ss(&C[(i*64)+37], c37_0);
#else
C[(i*64)+37] += values[142] * B[(i*64)+37];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b38 = _mm_broadcast_ss(&B[(i*64)+38]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b38 = _mm_load_ss(&B[(i*64)+38]);
b38 = _mm_shuffle_ps(b38, b38, 0x00);
#endif
__m128 c38_0 = _mm_load_ss(&C[(i*64)+38]);
__m128 a38_0 = _mm_load_ss(&values[143]);
c38_0 = _mm_add_ss(c38_0, _mm_mul_ss(a38_0, b38));
_mm_store_ss(&C[(i*64)+38], c38_0);
#else
C[(i*64)+38] += values[143] * B[(i*64)+38];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b39 = _mm_broadcast_ss(&B[(i*64)+39]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b39 = _mm_load_ss(&B[(i*64)+39]);
b39 = _mm_shuffle_ps(b39, b39, 0x00);
#endif
__m128 c39_0 = _mm_load_ss(&C[(i*64)+39]);
__m128 a39_0 = _mm_load_ss(&values[144]);
c39_0 = _mm_add_ss(c39_0, _mm_mul_ss(a39_0, b39));
_mm_store_ss(&C[(i*64)+39], c39_0);
#else
C[(i*64)+39] += values[144] * B[(i*64)+39];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b40 = _mm_broadcast_ss(&B[(i*64)+40]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b40 = _mm_load_ss(&B[(i*64)+40]);
b40 = _mm_shuffle_ps(b40, b40, 0x00);
#endif
__m128 c40_0 = _mm_load_ss(&C[(i*64)+40]);
__m128 a40_0 = _mm_load_ss(&values[145]);
c40_0 = _mm_add_ss(c40_0, _mm_mul_ss(a40_0, b40));
_mm_store_ss(&C[(i*64)+40], c40_0);
#else
C[(i*64)+40] += values[145] * B[(i*64)+40];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b41 = _mm_broadcast_ss(&B[(i*64)+41]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b41 = _mm_load_ss(&B[(i*64)+41]);
b41 = _mm_shuffle_ps(b41, b41, 0x00);
#endif
__m128 c41_0 = _mm_load_ss(&C[(i*64)+20]);
__m128 a41_0 = _mm_load_ss(&values[146]);
c41_0 = _mm_add_ss(c41_0, _mm_mul_ss(a41_0, b41));
_mm_store_ss(&C[(i*64)+20], c41_0);
__m128 c41_1 = _mm_load_ss(&C[(i*64)+41]);
__m128 a41_1 = _mm_load_ss(&values[147]);
c41_1 = _mm_add_ss(c41_1, _mm_mul_ss(a41_1, b41));
_mm_store_ss(&C[(i*64)+41], c41_1);
#else
C[(i*64)+20] += values[146] * B[(i*64)+41];
C[(i*64)+41] += values[147] * B[(i*64)+41];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b42 = _mm_broadcast_ss(&B[(i*64)+42]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b42 = _mm_load_ss(&B[(i*64)+42]);
b42 = _mm_shuffle_ps(b42, b42, 0x00);
#endif
__m128 c42_0 = _mm_load_ss(&C[(i*64)+21]);
__m128 a42_0 = _mm_load_ss(&values[148]);
c42_0 = _mm_add_ss(c42_0, _mm_mul_ss(a42_0, b42));
_mm_store_ss(&C[(i*64)+21], c42_0);
__m128 c42_1 = _mm_load_ss(&C[(i*64)+42]);
__m128 a42_1 = _mm_load_ss(&values[149]);
c42_1 = _mm_add_ss(c42_1, _mm_mul_ss(a42_1, b42));
_mm_store_ss(&C[(i*64)+42], c42_1);
#else
C[(i*64)+21] += values[148] * B[(i*64)+42];
C[(i*64)+42] += values[149] * B[(i*64)+42];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b43 = _mm_broadcast_ss(&B[(i*64)+43]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b43 = _mm_load_ss(&B[(i*64)+43]);
b43 = _mm_shuffle_ps(b43, b43, 0x00);
#endif
__m128 c43_0 = _mm_load_ss(&C[(i*64)+22]);
__m128 a43_0 = _mm_load_ss(&values[150]);
c43_0 = _mm_add_ss(c43_0, _mm_mul_ss(a43_0, b43));
_mm_store_ss(&C[(i*64)+22], c43_0);
__m128 c43_1 = _mm_load_ss(&C[(i*64)+43]);
__m128 a43_1 = _mm_load_ss(&values[151]);
c43_1 = _mm_add_ss(c43_1, _mm_mul_ss(a43_1, b43));
_mm_store_ss(&C[(i*64)+43], c43_1);
#else
C[(i*64)+22] += values[150] * B[(i*64)+43];
C[(i*64)+43] += values[151] * B[(i*64)+43];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b44 = _mm_broadcast_ss(&B[(i*64)+44]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b44 = _mm_load_ss(&B[(i*64)+44]);
b44 = _mm_shuffle_ps(b44, b44, 0x00);
#endif
__m128 c44_0 = _mm_load_ss(&C[(i*64)+23]);
__m128 a44_0 = _mm_load_ss(&values[152]);
c44_0 = _mm_add_ss(c44_0, _mm_mul_ss(a44_0, b44));
_mm_store_ss(&C[(i*64)+23], c44_0);
__m128 c44_1 = _mm_load_ss(&C[(i*64)+44]);
__m128 a44_1 = _mm_load_ss(&values[153]);
c44_1 = _mm_add_ss(c44_1, _mm_mul_ss(a44_1, b44));
_mm_store_ss(&C[(i*64)+44], c44_1);
#else
C[(i*64)+23] += values[152] * B[(i*64)+44];
C[(i*64)+44] += values[153] * B[(i*64)+44];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b45 = _mm_broadcast_ss(&B[(i*64)+45]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b45 = _mm_load_ss(&B[(i*64)+45]);
b45 = _mm_shuffle_ps(b45, b45, 0x00);
#endif
__m128 c45_0 = _mm_load_ss(&C[(i*64)+24]);
__m128 a45_0 = _mm_load_ss(&values[154]);
c45_0 = _mm_add_ss(c45_0, _mm_mul_ss(a45_0, b45));
_mm_store_ss(&C[(i*64)+24], c45_0);
__m128 c45_1 = _mm_load_ss(&C[(i*64)+45]);
__m128 a45_1 = _mm_load_ss(&values[155]);
c45_1 = _mm_add_ss(c45_1, _mm_mul_ss(a45_1, b45));
_mm_store_ss(&C[(i*64)+45], c45_1);
#else
C[(i*64)+24] += values[154] * B[(i*64)+45];
C[(i*64)+45] += values[155] * B[(i*64)+45];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b46 = _mm_broadcast_ss(&B[(i*64)+46]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b46 = _mm_load_ss(&B[(i*64)+46]);
b46 = _mm_shuffle_ps(b46, b46, 0x00);
#endif
__m128 c46_0 = _mm_load_ss(&C[(i*64)+10]);
__m128 a46_0 = _mm_load_ss(&values[156]);
c46_0 = _mm_add_ss(c46_0, _mm_mul_ss(a46_0, b46));
_mm_store_ss(&C[(i*64)+10], c46_0);
__m128 c46_1 = _mm_load_ss(&C[(i*64)+25]);
__m128 a46_1 = _mm_load_ss(&values[157]);
c46_1 = _mm_add_ss(c46_1, _mm_mul_ss(a46_1, b46));
_mm_store_ss(&C[(i*64)+25], c46_1);
__m128 c46_2 = _mm_load_ss(&C[(i*64)+46]);
__m128 a46_2 = _mm_load_ss(&values[158]);
c46_2 = _mm_add_ss(c46_2, _mm_mul_ss(a46_2, b46));
_mm_store_ss(&C[(i*64)+46], c46_2);
#else
C[(i*64)+10] += values[156] * B[(i*64)+46];
C[(i*64)+25] += values[157] * B[(i*64)+46];
C[(i*64)+46] += values[158] * B[(i*64)+46];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b47 = _mm_broadcast_ss(&B[(i*64)+47]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b47 = _mm_load_ss(&B[(i*64)+47]);
b47 = _mm_shuffle_ps(b47, b47, 0x00);
#endif
__m128 c47_0 = _mm_load_ss(&C[(i*64)+11]);
__m128 a47_0 = _mm_load_ss(&values[159]);
c47_0 = _mm_add_ss(c47_0, _mm_mul_ss(a47_0, b47));
_mm_store_ss(&C[(i*64)+11], c47_0);
__m128 c47_1 = _mm_load_ss(&C[(i*64)+26]);
__m128 a47_1 = _mm_load_ss(&values[160]);
c47_1 = _mm_add_ss(c47_1, _mm_mul_ss(a47_1, b47));
_mm_store_ss(&C[(i*64)+26], c47_1);
__m128 c47_2 = _mm_load_ss(&C[(i*64)+47]);
__m128 a47_2 = _mm_load_ss(&values[161]);
c47_2 = _mm_add_ss(c47_2, _mm_mul_ss(a47_2, b47));
_mm_store_ss(&C[(i*64)+47], c47_2);
#else
C[(i*64)+11] += values[159] * B[(i*64)+47];
C[(i*64)+26] += values[160] * B[(i*64)+47];
C[(i*64)+47] += values[161] * B[(i*64)+47];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b48 = _mm_broadcast_ss(&B[(i*64)+48]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b48 = _mm_load_ss(&B[(i*64)+48]);
b48 = _mm_shuffle_ps(b48, b48, 0x00);
#endif
__m128 c48_0 = _mm_load_ss(&C[(i*64)+12]);
__m128 a48_0 = _mm_load_ss(&values[162]);
c48_0 = _mm_add_ss(c48_0, _mm_mul_ss(a48_0, b48));
_mm_store_ss(&C[(i*64)+12], c48_0);
__m128 c48_1 = _mm_load_ss(&C[(i*64)+27]);
__m128 a48_1 = _mm_load_ss(&values[163]);
c48_1 = _mm_add_ss(c48_1, _mm_mul_ss(a48_1, b48));
_mm_store_ss(&C[(i*64)+27], c48_1);
__m128 c48_2 = _mm_load_ss(&C[(i*64)+48]);
__m128 a48_2 = _mm_load_ss(&values[164]);
c48_2 = _mm_add_ss(c48_2, _mm_mul_ss(a48_2, b48));
_mm_store_ss(&C[(i*64)+48], c48_2);
#else
C[(i*64)+12] += values[162] * B[(i*64)+48];
C[(i*64)+27] += values[163] * B[(i*64)+48];
C[(i*64)+48] += values[164] * B[(i*64)+48];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b49 = _mm_broadcast_ss(&B[(i*64)+49]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b49 = _mm_load_ss(&B[(i*64)+49]);
b49 = _mm_shuffle_ps(b49, b49, 0x00);
#endif
__m128 c49_0 = _mm_load_ss(&C[(i*64)+13]);
__m128 a49_0 = _mm_load_ss(&values[165]);
c49_0 = _mm_add_ss(c49_0, _mm_mul_ss(a49_0, b49));
_mm_store_ss(&C[(i*64)+13], c49_0);
__m128 c49_1 = _mm_load_ss(&C[(i*64)+28]);
__m128 a49_1 = _mm_load_ss(&values[166]);
c49_1 = _mm_add_ss(c49_1, _mm_mul_ss(a49_1, b49));
_mm_store_ss(&C[(i*64)+28], c49_1);
__m128 c49_2 = _mm_load_ss(&C[(i*64)+49]);
__m128 a49_2 = _mm_load_ss(&values[167]);
c49_2 = _mm_add_ss(c49_2, _mm_mul_ss(a49_2, b49));
_mm_store_ss(&C[(i*64)+49], c49_2);
#else
C[(i*64)+13] += values[165] * B[(i*64)+49];
C[(i*64)+28] += values[166] * B[(i*64)+49];
C[(i*64)+49] += values[167] * B[(i*64)+49];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b50 = _mm_broadcast_ss(&B[(i*64)+50]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b50 = _mm_load_ss(&B[(i*64)+50]);
b50 = _mm_shuffle_ps(b50, b50, 0x00);
#endif
__m128 c50_0 = _mm_load_ss(&C[(i*64)+4]);
__m128 a50_0 = _mm_load_ss(&values[168]);
c50_0 = _mm_add_ss(c50_0, _mm_mul_ss(a50_0, b50));
_mm_store_ss(&C[(i*64)+4], c50_0);
__m128 c50_1 = _mm_load_ss(&C[(i*64)+14]);
__m128 a50_1 = _mm_load_ss(&values[169]);
c50_1 = _mm_add_ss(c50_1, _mm_mul_ss(a50_1, b50));
_mm_store_ss(&C[(i*64)+14], c50_1);
__m128 c50_2 = _mm_load_ss(&C[(i*64)+29]);
__m128 a50_2 = _mm_load_ss(&values[170]);
c50_2 = _mm_add_ss(c50_2, _mm_mul_ss(a50_2, b50));
_mm_store_ss(&C[(i*64)+29], c50_2);
__m128 c50_3 = _mm_load_ss(&C[(i*64)+50]);
__m128 a50_3 = _mm_load_ss(&values[171]);
c50_3 = _mm_add_ss(c50_3, _mm_mul_ss(a50_3, b50));
_mm_store_ss(&C[(i*64)+50], c50_3);
#else
C[(i*64)+4] += values[168] * B[(i*64)+50];
C[(i*64)+14] += values[169] * B[(i*64)+50];
C[(i*64)+29] += values[170] * B[(i*64)+50];
C[(i*64)+50] += values[171] * B[(i*64)+50];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b51 = _mm_broadcast_ss(&B[(i*64)+51]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b51 = _mm_load_ss(&B[(i*64)+51]);
b51 = _mm_shuffle_ps(b51, b51, 0x00);
#endif
__m128 c51_0 = _mm_load_ss(&C[(i*64)+5]);
__m128 a51_0 = _mm_load_ss(&values[172]);
c51_0 = _mm_add_ss(c51_0, _mm_mul_ss(a51_0, b51));
_mm_store_ss(&C[(i*64)+5], c51_0);
__m128 c51_1 = _mm_load_ss(&C[(i*64)+15]);
__m128 a51_1 = _mm_load_ss(&values[173]);
c51_1 = _mm_add_ss(c51_1, _mm_mul_ss(a51_1, b51));
_mm_store_ss(&C[(i*64)+15], c51_1);
__m128 c51_2 = _mm_load_ss(&C[(i*64)+30]);
__m128 a51_2 = _mm_load_ss(&values[174]);
c51_2 = _mm_add_ss(c51_2, _mm_mul_ss(a51_2, b51));
_mm_store_ss(&C[(i*64)+30], c51_2);
__m128 c51_3 = _mm_load_ss(&C[(i*64)+51]);
__m128 a51_3 = _mm_load_ss(&values[175]);
c51_3 = _mm_add_ss(c51_3, _mm_mul_ss(a51_3, b51));
_mm_store_ss(&C[(i*64)+51], c51_3);
#else
C[(i*64)+5] += values[172] * B[(i*64)+51];
C[(i*64)+15] += values[173] * B[(i*64)+51];
C[(i*64)+30] += values[174] * B[(i*64)+51];
C[(i*64)+51] += values[175] * B[(i*64)+51];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b52 = _mm_broadcast_ss(&B[(i*64)+52]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b52 = _mm_load_ss(&B[(i*64)+52]);
b52 = _mm_shuffle_ps(b52, b52, 0x00);
#endif
__m128 c52_0 = _mm_load_ss(&C[(i*64)+6]);
__m128 a52_0 = _mm_load_ss(&values[176]);
c52_0 = _mm_add_ss(c52_0, _mm_mul_ss(a52_0, b52));
_mm_store_ss(&C[(i*64)+6], c52_0);
__m128 c52_1 = _mm_load_ss(&C[(i*64)+16]);
__m128 a52_1 = _mm_load_ss(&values[177]);
c52_1 = _mm_add_ss(c52_1, _mm_mul_ss(a52_1, b52));
_mm_store_ss(&C[(i*64)+16], c52_1);
__m128 c52_2 = _mm_load_ss(&C[(i*64)+31]);
__m128 a52_2 = _mm_load_ss(&values[178]);
c52_2 = _mm_add_ss(c52_2, _mm_mul_ss(a52_2, b52));
_mm_store_ss(&C[(i*64)+31], c52_2);
__m128 c52_3 = _mm_load_ss(&C[(i*64)+52]);
__m128 a52_3 = _mm_load_ss(&values[179]);
c52_3 = _mm_add_ss(c52_3, _mm_mul_ss(a52_3, b52));
_mm_store_ss(&C[(i*64)+52], c52_3);
#else
C[(i*64)+6] += values[176] * B[(i*64)+52];
C[(i*64)+16] += values[177] * B[(i*64)+52];
C[(i*64)+31] += values[178] * B[(i*64)+52];
C[(i*64)+52] += values[179] * B[(i*64)+52];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b53 = _mm_broadcast_ss(&B[(i*64)+53]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b53 = _mm_load_ss(&B[(i*64)+53]);
b53 = _mm_shuffle_ps(b53, b53, 0x00);
#endif
__m128 c53_0 = _mm_load_ss(&C[(i*64)+1]);
__m128 a53_0 = _mm_load_ss(&values[180]);
c53_0 = _mm_add_ss(c53_0, _mm_mul_ss(a53_0, b53));
_mm_store_ss(&C[(i*64)+1], c53_0);
__m128 c53_1 = _mm_load_ss(&C[(i*64)+7]);
__m128 a53_1 = _mm_load_ss(&values[181]);
c53_1 = _mm_add_ss(c53_1, _mm_mul_ss(a53_1, b53));
_mm_store_ss(&C[(i*64)+7], c53_1);
__m128 c53_2 = _mm_load_ss(&C[(i*64)+17]);
__m128 a53_2 = _mm_load_ss(&values[182]);
c53_2 = _mm_add_ss(c53_2, _mm_mul_ss(a53_2, b53));
_mm_store_ss(&C[(i*64)+17], c53_2);
__m128 c53_3 = _mm_load_ss(&C[(i*64)+32]);
__m128 a53_3 = _mm_load_ss(&values[183]);
c53_3 = _mm_add_ss(c53_3, _mm_mul_ss(a53_3, b53));
_mm_store_ss(&C[(i*64)+32], c53_3);
__m128 c53_4 = _mm_load_ss(&C[(i*64)+53]);
__m128 a53_4 = _mm_load_ss(&values[184]);
c53_4 = _mm_add_ss(c53_4, _mm_mul_ss(a53_4, b53));
_mm_store_ss(&C[(i*64)+53], c53_4);
#else
C[(i*64)+1] += values[180] * B[(i*64)+53];
C[(i*64)+7] += values[181] * B[(i*64)+53];
C[(i*64)+17] += values[182] * B[(i*64)+53];
C[(i*64)+32] += values[183] * B[(i*64)+53];
C[(i*64)+53] += values[184] * B[(i*64)+53];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b54 = _mm_broadcast_ss(&B[(i*64)+54]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b54 = _mm_load_ss(&B[(i*64)+54]);
b54 = _mm_shuffle_ps(b54, b54, 0x00);
#endif
__m128 c54_0 = _mm_load_ss(&C[(i*64)+2]);
__m128 a54_0 = _mm_load_ss(&values[185]);
c54_0 = _mm_add_ss(c54_0, _mm_mul_ss(a54_0, b54));
_mm_store_ss(&C[(i*64)+2], c54_0);
__m128 c54_1 = _mm_load_ss(&C[(i*64)+8]);
__m128 a54_1 = _mm_load_ss(&values[186]);
c54_1 = _mm_add_ss(c54_1, _mm_mul_ss(a54_1, b54));
_mm_store_ss(&C[(i*64)+8], c54_1);
__m128 c54_2 = _mm_load_ss(&C[(i*64)+18]);
__m128 a54_2 = _mm_load_ss(&values[187]);
c54_2 = _mm_add_ss(c54_2, _mm_mul_ss(a54_2, b54));
_mm_store_ss(&C[(i*64)+18], c54_2);
__m128 c54_3 = _mm_load_ss(&C[(i*64)+33]);
__m128 a54_3 = _mm_load_ss(&values[188]);
c54_3 = _mm_add_ss(c54_3, _mm_mul_ss(a54_3, b54));
_mm_store_ss(&C[(i*64)+33], c54_3);
__m128 c54_4 = _mm_load_ss(&C[(i*64)+54]);
__m128 a54_4 = _mm_load_ss(&values[189]);
c54_4 = _mm_add_ss(c54_4, _mm_mul_ss(a54_4, b54));
_mm_store_ss(&C[(i*64)+54], c54_4);
#else
C[(i*64)+2] += values[185] * B[(i*64)+54];
C[(i*64)+8] += values[186] * B[(i*64)+54];
C[(i*64)+18] += values[187] * B[(i*64)+54];
C[(i*64)+33] += values[188] * B[(i*64)+54];
C[(i*64)+54] += values[189] * B[(i*64)+54];
#endif
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
__m128 b55 = _mm_broadcast_ss(&B[(i*64)+55]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
__m128 b55 = _mm_load_ss(&B[(i*64)+55]);
b55 = _mm_shuffle_ps(b55, b55, 0x00);
#endif
__m128 c55_0 = _mm_load_ss(&C[(i*64)+0]);
__m128 a55_0 = _mm_load_ss(&values[190]);
c55_0 = _mm_add_ss(c55_0, _mm_mul_ss(a55_0, b55));
_mm_store_ss(&C[(i*64)+0], c55_0);
__m128 c55_1 = _mm_load_ss(&C[(i*64)+3]);
__m128 a55_1 = _mm_load_ss(&values[191]);
c55_1 = _mm_add_ss(c55_1, _mm_mul_ss(a55_1, b55));
_mm_store_ss(&C[(i*64)+3], c55_1);
__m128 c55_2 = _mm_load_ss(&C[(i*64)+9]);
__m128 a55_2 = _mm_load_ss(&values[192]);
c55_2 = _mm_add_ss(c55_2, _mm_mul_ss(a55_2, b55));
_mm_store_ss(&C[(i*64)+9], c55_2);
__m128 c55_3 = _mm_load_ss(&C[(i*64)+19]);
__m128 a55_3 = _mm_load_ss(&values[193]);
c55_3 = _mm_add_ss(c55_3, _mm_mul_ss(a55_3, b55));
_mm_store_ss(&C[(i*64)+19], c55_3);
__m128 c55_4 = _mm_load_ss(&C[(i*64)+34]);
__m128 a55_4 = _mm_load_ss(&values[194]);
c55_4 = _mm_add_ss(c55_4, _mm_mul_ss(a55_4, b55));
_mm_store_ss(&C[(i*64)+34], c55_4);
__m128 c55_5 = _mm_load_ss(&C[(i*64)+55]);
__m128 a55_5 = _mm_load_ss(&values[195]);
c55_5 = _mm_add_ss(c55_5, _mm_mul_ss(a55_5, b55));
_mm_store_ss(&C[(i*64)+55], c55_5);
#else
C[(i*64)+0] += values[190] * B[(i*64)+55];
C[(i*64)+3] += values[191] * B[(i*64)+55];
C[(i*64)+9] += values[192] * B[(i*64)+55];
C[(i*64)+19] += values[193] * B[(i*64)+55];
C[(i*64)+34] += values[194] * B[(i*64)+55];
C[(i*64)+55] += values[195] * B[(i*64)+55];
#endif

}

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 3528;
#endif

}

void ssparse_starMatrix_m84_n9_k9_ldA96_ldBna7_ldC96_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 84; i += 1)
{
C[(i)+(0)] += A[(i)+(576)] * values[0];
C[(i)+(0)] += A[(i)+(672)] * values[1];
C[(i)+(0)] += A[(i)+(768)] * values[2];
C[(i)+(96)] += A[(i)+(576)] * values[3];
C[(i)+(96)] += A[(i)+(672)] * values[4];
C[(i)+(96)] += A[(i)+(768)] * values[5];
C[(i)+(192)] += A[(i)+(576)] * values[6];
C[(i)+(192)] += A[(i)+(672)] * values[7];
C[(i)+(192)] += A[(i)+(768)] * values[8];
C[(i)+(288)] += A[(i)+(576)] * values[9];
C[(i)+(288)] += A[(i)+(672)] * values[10];
C[(i)+(384)] += A[(i)+(672)] * values[11];
C[(i)+(384)] += A[(i)+(768)] * values[12];
C[(i)+(480)] += A[(i)+(576)] * values[13];
C[(i)+(480)] += A[(i)+(768)] * values[14];
C[(i)+(576)] += A[(i)+(0)] * values[15];
C[(i)+(576)] += A[(i)+(288)] * values[16];
C[(i)+(576)] += A[(i)+(480)] * values[17];
C[(i)+(672)] += A[(i)+(96)] * values[18];
C[(i)+(672)] += A[(i)+(288)] * values[19];
C[(i)+(672)] += A[(i)+(384)] * values[20];
C[(i)+(768)] += A[(i)+(192)] * values[21];
C[(i)+(768)] += A[(i)+(384)] * values[22];
C[(i)+(768)] += A[(i)+(480)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 4032;
#endif

}

void ssparse_starMatrix_m120_n9_k9_ldA128_ldBna8_ldC128_beta1_pfsigonly(const float* A, const float* values, float* C, const float* A_prefetch = NULL, const float* B_prefetch = NULL, const float* C_prefetch = NULL)
{
#pragma simd vectorlength(32)
#pragma vector aligned
for (unsigned int i = 0; i < 120; i += 1)
{
C[(i)+(0)] += A[(i)+(768)] * values[0];
C[(i)+(0)] += A[(i)+(896)] * values[1];
C[(i)+(0)] += A[(i)+(1024)] * values[2];
C[(i)+(128)] += A[(i)+(768)] * values[3];
C[(i)+(128)] += A[(i)+(896)] * values[4];
C[(i)+(128)] += A[(i)+(1024)] * values[5];
C[(i)+(256)] += A[(i)+(768)] * values[6];
C[(i)+(256)] += A[(i)+(896)] * values[7];
C[(i)+(256)] += A[(i)+(1024)] * values[8];
C[(i)+(384)] += A[(i)+(768)] * values[9];
C[(i)+(384)] += A[(i)+(896)] * values[10];
C[(i)+(512)] += A[(i)+(896)] * values[11];
C[(i)+(512)] += A[(i)+(1024)] * values[12];
C[(i)+(640)] += A[(i)+(768)] * values[13];
C[(i)+(640)] += A[(i)+(1024)] * values[14];
C[(i)+(768)] += A[(i)+(0)] * values[15];
C[(i)+(768)] += A[(i)+(384)] * values[16];
C[(i)+(768)] += A[(i)+(640)] * values[17];
C[(i)+(896)] += A[(i)+(128)] * values[18];
C[(i)+(896)] += A[(i)+(384)] * values[19];
C[(i)+(896)] += A[(i)+(512)] * values[20];
C[(i)+(1024)] += A[(i)+(256)] * values[21];
C[(i)+(1024)] += A[(i)+(512)] * values[22];
C[(i)+(1024)] += A[(i)+(640)] * values[23];
}
#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 5760;
#endif

}

#endif