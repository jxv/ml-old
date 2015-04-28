#ifndef ML_H
#define ML_H

#include <stdbool.h>

#define DECL_PRIM(A,TY)	\
TY mlPiDiv4##A();	\
TY mlPiDiv2##A();	\
TY mlPi##A();	\
TY mlPiMul2##A();	\
TY mlTau##A();	\
\
TY mlAbs##A(TY x);	\
TY mlSqrt##A(TY x);	\
TY mlRecip##A(TY x);	\
TY mlNegate##A(TY x);	\
TY mlRound##A(TY x);	\
TY mlFloor##A(TY x);	\
TY mlCeil##A(TY x);	\
TY mlMod##A(TY x, TY y);	\
bool mlNearZero##A(TY x);	\
\
TY mlMin##A(TY x, TY y);	\
TY mlMax##A(TY x, TY y);	\
TY mlClamp##A(TY low, TY hi, TY x);	\
TY mlSaturate##A(TY x);	\
bool mlInRangeIn##A(TY low, TY hi, TY x);	\
bool mlInRangeEx##A(TY low, TY hi, TY x);	\
\
TY mlLerp##A(TY x, TY y, TY s);	\
TY mlSmoothStep##A(TY x, TY y, TY s);	\
TY mlSmootherStep##A(TY x, TY y, TY s);	\
TY mlCosInterp##A(TY x, TY y, TY s);	\
TY mlCubicInterp##A(TY x, TY y, TY z, TY w, TY s);	\
TY mlNearestInterp##A(TY x, TY y, TY s);	\
\
TY mlBiNearestInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy);	\
TY mlBilinearInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy);	\
TY mlBiCosInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy);	\
TY mlBiSmoothStepInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy);	\
TY mlBiSmootherstepInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy);

DECL_PRIM(i,int)
DECL_PRIM(f,float)
DECL_PRIM(d,double)

#define DECL_V2(A,TY)	\
typedef struct {	\
	union {	\
		struct {	\
			TY x;	\
			TY y;	\
		};	\
		TY v[2];	\
	};	\
} MLV2##A;	\
\
MLV2##A mlV2##A(TY x, TY y);	\
MLV2##A mlV2##A##Fill(TY x);	\
MLV2##A mlV2##A##Zero();	\
MLV2##A mlV2##A##One();	\
\
MLV2##A mlAbsV2##A(MLV2##A x);	\
MLV2##A mlNegateV2##A(MLV2##A x);	\
MLV2##A mlRoundV2##A(MLV2##A x);	\
MLV2##A mlFloorV2##A(MLV2##A x);	\
MLV2##A mlCeilV2##A(MLV2##A x);	\
MLV2##A mlModV2##A(MLV2##A x);	\
\
MLV2##A mlAddV2##A(MLV2##A x, MLV2##A y);	\
MLV2##A mlSubV2##A(MLV2##A x, MLV2##A y);	\
MLV2##A mlMulV2##A(MLV2##A x, MLV2##A y);	\
MLV2##A mlDivV2##A(MLV2##A x, MLV2##A y);	\
\
MLV2##A mlAddV2##A##A(MLV2##A x, TY y);	\
MLV2##A mlSubV2##A##A(MLV2##A x, TY y);	\
MLV2##A mlMulV2##A##A(MLV2##A x, TY y);	\
MLV2##A mlDivV2##A##A(MLV2##A x, TY y);	\
\
MLV2##A mlClampV2##A(MLV2##A low, MLV2##A hi, MLV2##A x);	\
\
TY mlSqLenV2##A(MLV2##A x);	\
TY mlLenV2##A(MLV2##A x);	\
TY mlDotV2##A(MLV2##A x, MLV2##A y);	\
MLV2##A mlNormalizeV2##A(MLV2##A x);	\
\
bool mlNearZeroV2##A(MLV2##A x);

DECL_V2(i,int)
DECL_V2(f,float)
DECL_V2(d,double)

#endif
