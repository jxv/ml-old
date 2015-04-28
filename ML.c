#include <stdlib.h>
#include <math.h>
#include "ML.h"

#define DEF_RAWCAST(A,TYA,B,TYB)	\
TYB mlRawCast##A##B(TYA x) {	\
	union {	\
		TYA a;	\
		TYB b;	\
	} v;	\
	v.a = x;	\
	return v.b;	\
}

DEF_RAWCAST(f,float,i,int)
DEF_RAWCAST(i,int,f,float)

#define DEF_PRIM(A,TY,ABS,SQRT,ROUND,FLOOR,CEIL,MOD,POW,SIN,COS,EPSILON)	\
inline	\
TY mlPiDiv4##A() {	\
	return M_PI_4;	\
}	\
\
inline	\
TY mlPiDiv2##A() {	\
	return M_PI_2;	\
}	\
\
inline	\
TY mlPi##A() {	\
	return M_PI;	\
}	\
\
inline	\
TY mlPiMul2##A() {	\
	return mlTau##A();	\
}	\
\
inline	\
TY mlTau##A() {	\
	return M_2_PI;	\
}	\
\
\
inline	\
TY mlAbs##A(TY x) {	\
	return ABS(x);	\
}	\
\
inline	\
TY mlSqrt##A(TY x) {	\
	return SQRT(x);	\
}	\
\
inline	\
TY mlRecip##A(TY x) {	\
	return mlNearZero##A(x) ? 0 : (1 / x);	\
}	\
\
inline	\
TY mlNegate##A(TY x) {	\
	return -x;	\
}	\
\
inline	\
TY mlRound##A(TY x) {	\
	return ROUND(x);	\
}	\
\
inline	\
TY mlFloor##A(TY x) {	\
	return FLOOR(x);	\
}	\
\
inline	\
TY mlCeil##A(TY x) {	\
	return CEIL(x);	\
}	\
\
inline	\
TY mlMod##A(TY x, TY y) {	\
	return MOD(x,y);	\
}	\
\
inline	\
TY mlPow##A(TY x, TY y) {	\
	return POW(x,y);	\
}	\
\
inline	\
bool mlNearZero##A(TY x) {	\
	return mlAbs##A(x) <= EPSILON;	\
}	\
\
\
inline	\
TY mlMin##A(TY x, TY y) {	\
	return x < y ? x : y;	\
}	\
\
inline	\
TY mlMax##A(TY x, TY y) {	\
	return x > y ? x : y;	\
}	\
\
inline	\
TY mlClamp##A(TY low, TY hi, TY val) {	\
	if (low >= val)	return low;	\
	if (hi <= val)	return hi;	\
	return val;	\
}	\
\
inline	\
TY mlSaturate##A(TY x) {	\
	return mlMin##A(mlMax##A(x, 0), 1);	\
}	\
\
inline	\
bool mlInRangeIn##A(TY low, TY hi, TY x) {	\
	return low <= x && hi >= x;	\
}	\
\
inline	\
bool mlInRangeEx##A(TY low, TY hi, TY x) {	\
	return low < x && hi > x;	\
}	\
\
\
inline	\
TY mlLerp##A(TY x, TY y, TY s) {	\
	return s * x + (1 - s) * y;	\
}	\
\
inline	\
TY mlSmoothStep##A(TY x, TY y, TY s) {	\
	return mlLerp##A(x, y, (3 - 2 * s) * s * s);	\
}	\
\
inline	\
TY mlSmootherStep##A(TY x, TY y, TY s) {	\
	return mlLerp##A(x, y, (10 + (s * 6 - 15) * s) * s * s * s);	\
}	\
\
inline	\
TY mlCosInterp##A(TY x, TY y, TY s) {	\
	TY mu2 = (1 - COS(s * mlPi##A())) / 2;	\
	return mu2 * x + (1 - mu2) * y;	\
}	\
\
inline	\
TY mlCubicInterp##A(TY x, TY y, TY z, TY w, TY s) {	\
	TY s2 = s * s;	\
	TY s3 = s * s * s;	\
	TY a = w - z - y + x;	\
	TY b = x - y - a;	\
	TY c = z - x;	\
	TY d = y;	\
	return s3 * a + s2 * b + s * c + d;	\
}	\
\
inline	\
TY mlNearestInterp##A(TY x, TY y, TY s) {	\
	return mlNearZero##A(ROUND(s)) ? x : y;	\
}	\
\
\
inline	\
TY mlBiNearestInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy) {	\
	TY sx_ = ROUND(sx);	\
	TY sy_ = ROUND(sy);	\
	if (sx_ != 0 && sy_ == 0) return br;	\
	if (sx_ == 0 && sy_ != 0) return tl;	\
	if (sx_ == 0 && sy_ == 0) return bl;	\
	if (sx_ != 0 && sy_ != 0) return tr;	\
	return 0;	\
}	\
\
inline	\
TY mlBilinearInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy) {	\
	TY lf = mlLerp##A(tl, bl, sy);	\
	TY rt = mlLerp##A(tr, br, sy);	\
	return mlLerp##A(rt, lf, sx);	\
}	\
\
inline	\
TY mlBiCosInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy) {	\
	TY lf = mlCosInterp##A(tl, bl, sy);	\
	TY rt = mlCosInterp##A(tr, br, sy);	\
	return mlCosInterp##A(rt, lf, sx);	\
}	\
\
inline	\
TY mlBiSmoothStepInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy) {	\
	TY lf = mlSmoothStep##A(tl, bl, sy);	\
	TY rt = mlSmoothStep##A(tr, br, sy);	\
	return mlSmoothStep##A(rt, lf, sx);	\
}	\
\
inline	\
TY mlBiSmootherStepInterp##A(TY tl, TY tr, TY bl, TY br, TY sx, TY sy) {	\
	TY lf = mlSmootherStep##A(tl, bl, sy);	\
	TY rt = mlSmootherStep##A(tr, br, sy);	\
	return mlSmootherStep##A(rt, lf, sx);	\
}

#define DEF_MOD_FN(A,TY)	\
static inline	\
TY local_mlMod##A(TY x, TY y) {	\
	return x % y;	\
}

// DEF_MOD_FN(i,int)

// DEF_PRIM(i,int,abs,sqrtl,/*round*/,/*floor*/,/*ceil*/,local_mlModi,powl,sin,cos,0)
DEF_PRIM(f,float,fabsf,sqrtf,roundf,floorf,ceilf,fmodf,powf,sinf,cosf,1e-6)
DEF_PRIM(d,double,fabs,sqrt,round,floor,ceil,fmod,pow,sin,cos,1e-6)

#define DEF_V2(A,TY)	\
inline	\
MLV2##A mlV2##A(TY x, TY y) {	\
	return (MLV2##A) { .x = x, .y = y };	\
}	\
\
inline	\
MLV2##A mlV2##A##Fill(TY x) {	\
	return (MLV2##A) { .x = x, .y = x };	\
}	\
\
inline	\
MLV2##A mlV2##A##Zero() {	\
	return mlV2##A(0,0);	\
}	\
\
inline	\
MLV2##A mlV2##A##One() {	\
	return mlV2##A(1,1);	\
}	\
\
inline	\
MLV2##A mlAbsV2##A(MLV2##A x) {	\
	return mlV2##A(mlAbs##A(x.x), mlAbs##A(x.y));	\
}	\
\
inline	\
MLV2##A mlAddV2##A(MLV2##A x, MLV2##A y) {	\
	return mlV2##A(x.x + y.x, x.y + y.y);	\
}	\
\
inline	\
MLV2##A mlSubV2##A(MLV2##A x, MLV2##A y) {	\
	return mlV2##A(x.x - y.x, x.y - y.y);	\
}	\
\
inline	\
MLV2##A mlMulV2##A(MLV2##A x, MLV2##A y) {	\
	return mlV2##A(x.x * y.x, x.y * y.y);	\
}	\
\
inline	\
MLV2##A mlDivV2##A(MLV2##A x, MLV2##A y) {	\
	return mlV2##A(x.x / y.x, x.y / y.y);	\
}	\
\
inline	\
MLV2##A mlPowV2##A(MLV2##A x, MLV2##A y) {	\
	return mlV2##A(mlPow##A(x.x, y.x), mlPow##A(x.y, y.y));	\
}	\
\
\
inline	\
MLV2##A mlAddV2##A##A(MLV2##A x, TY y) {	\
	return mlV2##A(x.x + y, x.y + y);	\
}	\
\
inline	\
MLV2##A mlSubV2##A##A(MLV2##A x, TY y) {	\
	return mlV2##A(x.x - y, x.y - y);	\
}	\
\
inline	\
MLV2##A mlMulV2##A##A(MLV2##A x, TY y) {	\
	return mlV2##A(x.x * y, x.y * y);	\
}	\
\
inline	\
MLV2##A mlDivV2##A##A(MLV2##A x, TY y) {	\
	return mlV2##A(x.x / y, x.y / y);	\
}	\
\
\
inline	\
MLV2##A mlClampV2##A(MLV2##A low, MLV2##A hi, MLV2##A x) {	\
	return mlV2##A(mlClamp##A(low.x, hi.x, x.x), mlClamp##A(low.y, hi.y, x.y));	\
}	\
\
inline	\
bool mlNearZeroV2##A(MLV2##A x)	{	\
	return mlNearZero##A(x.x) && mlNearZero##A(x.y);	\
}	\
\
inline	\
bool mlEqualV2##A(MLV2##A x, MLV2##A y) {	\
	return x.x == y.x && x.y == y.y;	\
}	\
\
\
inline	\
TY mlSqLenV2##A(MLV2##A x) {	\
	return x.x * x.x + x.y * x.y;	\
}	\
\
inline	\
TY mlLenV2##A(MLV2##A x) {	\
	return mlSqrt##A(mlSqLenV2##A(x));	\
}	\
\
inline	\
TY mlSqDistV2##A(MLV2##A x, MLV2##A y) {	\
	const TY dx = x.x - y.x;	\
	const TY dy = x.y - y.y;	\
	return dx * dx + dy * dy;	\
}	\
\
inline	\
TY mlDistV2##A(MLV2##A x, MLV2##A y) {	\
	return mlSqrt##A(mlSqDistV2##A(x, y));	\
}	\
\
inline	\
TY mlManhattanDistV2##A(MLV2##A x, MLV2##A y) {	\
	return mlAbs##A(x.x - y.x) + mlAbs##A(x.y - y.y);	\
}	\
\
inline	\
TY mlDotV2##A(MLV2##A x, MLV2##A y) {	\
	return x.x * y.x + x.y * y.y;	\
}	\
\
inline	\
MLV2##A mlNormalizeV2##A(MLV2##A x) {	\
	return mlDivV2##A##A(x, mlLenV2##A(x));	\
}	\
\
inline	\
MLV2##A mlReflectV2##A(MLV2##A x, MLV2##A y) {	\
	return mlSubV2##A(x, mlMulV2##A##A(y, mlDotV2##A(x, y) * 2));	\
}

// DEF_V2(i,int)
DEF_V2(f,float)
DEF_V2(d,double)
