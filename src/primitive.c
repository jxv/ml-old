#include <math.h>
#include <stdlib.h>
#include "ml.h"

#define ML_DEFINE_PRIMITIVE_CTOR(A,T)\
inline T mlPrimitive##A(T x) {\
	return x;\
}

ML_DEFINE_PRIMITIVE_CTOR(b,bool)
ML_DEFINE_PRIMITIVE_CTOR(i,int)
ML_DEFINE_PRIMITIVE_CTOR(li,long int)
ML_DEFINE_PRIMITIVE_CTOR(f,float)
ML_DEFINE_PRIMITIVE_CTOR(d,double)
ML_DEFINE_PRIMITIVE_CTOR(ld,long double)

#define ML_DEFINE_PRIMITIVE_NUMBER(A,T,ABS)\
inline T mlAbs##A(T x) {\
	return ABS(x);\
}\
inline T mlSignum##A(T x) {\
	return -ABS(x);\
}\
inline T mlNegate##A(T x) {\
	return -x;\
}\
inline T mlAdd##A(T x, T y) {\
	return x + y;\
}\
inline T mlSub##A(T x, T y) {\
	return x - y;\
}\
inline T mlMul##A(T x, T y) {\
	return x * y;\
}\
inline T mlDiv##A(T x, T y) {\
	return x / y;\
}

ML_DEFINE_PRIMITIVE_NUMBER(i,int,abs)
ML_DEFINE_PRIMITIVE_NUMBER(li,long int,labs)
ML_DEFINE_PRIMITIVE_NUMBER(f,float,fabsf)
ML_DEFINE_PRIMITIVE_NUMBER(d,double,fabs)
ML_DEFINE_PRIMITIVE_NUMBER(ld,long double,fabsl)

#define ML_DEFINE_PRIMITIVE_COMPARE(A,T)\
inline bool mlLessThan##A(T x, T y) {\
	return x < y;\
}\
inline bool mlLessThanOrEqual##A(T x, T y) {\
	return x <= y;\
}\
inline bool mlGreaterThan##A(T x, T y) {\
	return x > y;\
}\
inline bool mlGreaterThanOrEqual##A(T x, T y) {\
	return x >= y;\
}\
inline bool mlEqual##A(T x, T y) {\
	return x == y;\
}

ML_DEFINE_PRIMITIVE_COMPARE(i,int)
ML_DEFINE_PRIMITIVE_COMPARE(li,long int)
ML_DEFINE_PRIMITIVE_COMPARE(f,float)
ML_DEFINE_PRIMITIVE_COMPARE(d,double)
ML_DEFINE_PRIMITIVE_COMPARE(ld,long double)

#define ML_DEFINE_PRIMITIVE_ORDER(A,T)\
inline T mlMin##A(T x, T y) {\
	return x < y ? x : y;\
}\
inline T mlMax##A(T x, T y) {\
	return x > y ? x : y;\
}\
inline T mlClamp##A(T low, T hi, T x) {\
	if (low >= x) return low;\
	if (hi <= x) return hi;\
	return x;\
}

#define ML_DEFINE_PRIMITIVE_ORDER_FN(A,T,MIN,MAX)\
inline T mlMin##A(T x, T y) {\
	return MIN(x,y);\
}\
inline T mlMax##A(T x, T y) {\
	return MAX(x,y);\
}\
inline T mlClamp##A(T low, T hi, T x) {\
	return MAX(low,MIN(hi,x));\
}

ML_DEFINE_PRIMITIVE_ORDER(i,int)
ML_DEFINE_PRIMITIVE_ORDER(li,long int)
ML_DEFINE_PRIMITIVE_ORDER_FN(f,float,fminf,fmaxf)
ML_DEFINE_PRIMITIVE_ORDER_FN(d,double,fmin,fmax)
ML_DEFINE_PRIMITIVE_ORDER_FN(ld,long double,fminl,fmaxl)

#define ML_DEFINE_PRIMITIVE_NEAR_ZERO(A,T,EPSILON)\
inline bool mlNearZero##A(T x) {\
	return mlAbs##A(x) < EPSILON;\
}

ML_DEFINE_PRIMITIVE_NEAR_ZERO(f,float,1e-6)
ML_DEFINE_PRIMITIVE_NEAR_ZERO(d,double,1e-6)
ML_DEFINE_PRIMITIVE_NEAR_ZERO(ld,long double,1e-6)

#define ML_DEFINE_PRIMITIVE_RECIPORCAL(A,T)\
inline T mlRecip##A(T x) {\
	return mlDiv##A(1, x);\
}\
inline T mlRecipNoInf##A(T x) {\
	return mlNearZero##A(x) ? 0 : mlDiv##A(1, x);\
}

ML_DEFINE_PRIMITIVE_RECIPORCAL(f,float)
ML_DEFINE_PRIMITIVE_RECIPORCAL(d,double)
ML_DEFINE_PRIMITIVE_RECIPORCAL(ld,long double)

#define ML_DEFINE_PRIMITIVE_MODULUS(A,T)\
inline T mlMod##A(T x, T y) {\
	return x % y;\
}

#define ML_DEFINE_PRIMITIVE_MODULUS_FN(A,T,MOD)\
inline T mlMod##A(T x, T y) {\
	return MOD(x,y);\
}

ML_DEFINE_PRIMITIVE_MODULUS(i,int)
ML_DEFINE_PRIMITIVE_MODULUS(li,long int)
ML_DEFINE_PRIMITIVE_MODULUS_FN(f,float,fmodf)
ML_DEFINE_PRIMITIVE_MODULUS_FN(d,double,fmod)
ML_DEFINE_PRIMITIVE_MODULUS_FN(ld,long double,fmodl)

#define ML_DEFINE_PRIMITIVE_FLOATING_POINT(A,T,EXP,LOG,SQRT,POW,SIN,COS,TAN,ASIN,ACOS,ATAN,SINH,COSH,TANH,ASINH,ACOSH,ATANH)\
inline T mlPiDiv4##A() {\
	return 0.78539816339744830962;\
}\
inline T mlPiDiv2##A() {\
	return 1.57079632679489661923;\
}\
inline T mlPi##A() {\
	return 3.14159265358979323846;\
}\
inline T mlPiMul2##A() {\
	return 2 * 3.14159265358979323846;\
}\
inline T mlTau##A() {\
	return 2 * 3.14159265358979323846;\
}\
inline T mlEuler##A() {\
	return 2.7182818284590452354;\
}\
inline T mlPhi##A() {\
	return 1.618033988749895;\
}\
inline T mlExp##A(T x) {\
	return EXP(x);\
}\
inline T mlLog##A(T x) {\
	return LOG(x);\
}\
inline T mlSqrt##A(T x) {\
	return SQRT(x);\
}\
inline T mlPow##A(T x, T y) {\
	return POW(x,y);\
}\
inline T mlLogBase##A(T base, T x) {\
	return LOG(x) / LOG(base);\
}\
inline T mlSin##A(T x) {\
	return SIN(x);\
}\
inline T mlCos##A(T x) {\
	return COS(x);\
}\
inline T mlTan##A(T x) {\
	return TAN(x);\
}\
inline T mlArcSin##A(T x) {\
	return ASIN(x);\
}\
inline T mlArcCos##A(T x) {\
	return ACOS(x);\
}\
inline T mlArcTan##A(T x) {\
	return ATAN(x);\
}\
inline T mlSinH##A(T x) {\
	return SINH(x);\
}\
inline T mlCosH##A(T x) {\
	return COSH(x);\
}\
inline T mlTanH##A(T x) {\
	return TANH(x);\
}\
inline T mlArcSinH##A(T x) {\
	return ASINH(x);\
}\
inline T mlArcCosH##A(T x) {\
	return ACOSH(x);\
}\
inline T mlArcTanH##A(T x) {\
	return ATANH(x);\
}\
inline T mlSaturate##A(T x) {\
	return mlMax##A(mlMin##A(x,1),0);\
}

ML_DEFINE_PRIMITIVE_FLOATING_POINT(f,float,expf,logf,sqrtf,powf,sinf,cosf,tanf,asinf,acosf,atanf,sinhf,coshf,tanhf,asinhf,acoshf,atanhf)
ML_DEFINE_PRIMITIVE_FLOATING_POINT(d,double,exp,log,sqrt,pow,sin,cos,tan,asin,acos,atan,sinh,cosh,tanh,asinh,acosh,atanh)
ML_DEFINE_PRIMITIVE_FLOATING_POINT(ld,long double,expl,logl,sqrtl,powl,sinl,cosl,tanl,asinl,acosl,atanl,sinhl,coshl,tanhl,asinl,acoshl,atanhl)

#define ML_DEFINE_PRIMITIVE_REAL_FRACTION(A,T,ROUND,FLOOR,CEIL,TRUNCATE)\
inline T mlRound##A(T x) {\
	return ROUND(x);\
}\
inline T mlFloor##A(T x) {\
	return FLOOR(x);\
}\
inline T mlCeil##A(T x) {\
	return CEIL(x);\
}\
inline T mlTruncate##A(T x) {\
	return TRUNCATE(x);\
}

ML_DEFINE_PRIMITIVE_REAL_FRACTION(f,float,roundf,floorf,ceilf,truncf)
ML_DEFINE_PRIMITIVE_REAL_FRACTION(d,double,round,floor,ceil,trunc)
ML_DEFINE_PRIMITIVE_REAL_FRACTION(ld,long double,roundl,floorl,ceill,truncl)

#define ML_DEFINE_PRIMITIVE_BETWEEN(A,T)\
inline bool mlBetweenInclusive##A(T low, T hi, T x) {\
	return low <= x && hi >= x;\
}\
inline bool mlBetweenExclusive##A(T low, T hi, T x) {\
	return low < x && hi > x;\
}

ML_DEFINE_PRIMITIVE_BETWEEN(f,float)
ML_DEFINE_PRIMITIVE_BETWEEN(d,double)
ML_DEFINE_PRIMITIVE_BETWEEN(ld,long double)

#define ML_DEFINE_PRIMITIVE_INTERPOLATE(A,T)\
inline T mlLerp##A(T x, T y, T s) {\
	return s * x + (1 - s) * y;\
}\
inline T mlSmoothStep##A(T x, T y, T s) {\
	return mlLerp##A(x, y, (3 - 2 * s) * s * s);\
}\
inline T mlSmootherStep##A(T x, T y, T s) {\
	return mlLerp##A(x, y, (10 + (s * 6 - 15) * s) * s * s * s);\
}\
inline T mlCosInterpolate##A(T x, T y, T s) {\
	T mu2 = (1 - mlCos##A(s * mlPi##A())) / 2;\
	return mu2 * x + (1 - mu2) * y;\
}\
inline T mlCubicInterpolate##A(T x, T y, T z, T w, T s) {\
	T s2 = s * s;\
	T s3 = s * s * s;\
	T a = w - z - y + x;\
	T b = x - y - a;\
	T c = z - x;\
	T d = y;\
	return s3 * a + s2 * b + s * c + d;\
}\
inline T mlNearestInterpolate##A(T x, T y, T s) {\
	return mlNearZero##A(mlRound##A(s)) ? x : y;\
}\
inline T mlBiNearestInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy) {\
	T sx_ = mlRound##A(sx);\
	T sy_ = mlRound##A(sy);\
	if (sx_ != 0 && sy_ == 0) return br;\
	if (sx_ == 0 && sy_ != 0) return tl;\
	if (sx_ == 0 && sy_ == 0) return bl;\
	if (sx_ != 0 && sy_ != 0) return tr;\
	return 0;\
}\
inline T mlBilinearInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy) {\
	T lf = mlLerp##A(tl, bl, sy);\
	T rt = mlLerp##A(tr, br, sy);\
	return mlLerp##A(rt, lf, sx);\
}\
inline T mlBiCosInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy) {\
	T lf = mlCosInterpolate##A(tl, bl, sy);\
	T rt = mlCosInterpolate##A(tr, br, sy);\
	return mlCosInterpolate##A(rt, lf, sx);\
}\
inline T mlBiSmoothStepInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy) {\
	T lf = mlSmoothStep##A(tl, bl, sy);\
	T rt = mlSmoothStep##A(tr, br, sy);\
	return mlSmoothStep##A(rt, lf, sx);\
}\
inline T mlBiSmootherstepInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy) {\
	T lf = mlSmootherStep##A(tl, bl, sy);\
	T rt = mlSmootherStep##A(tr, br, sy);\
	return mlSmootherStep##A(rt, lf, sx);\
}

ML_DEFINE_PRIMITIVE_INTERPOLATE(f,float)
ML_DEFINE_PRIMITIVE_INTERPOLATE(d,double)
ML_DEFINE_PRIMITIVE_INTERPOLATE(ld,long double)

#define ML_DEFINE_RAW_CAST(A,TA,B,TB)\
inline TB mlRawCast##A##To##B(TA x) {\
	union {\
		TA a;\
		TB b;\
	} v;\
	v.a = x;\
	return v.b;\
}

ML_DEFINE_RAW_CAST(f,float,i,int)
ML_DEFINE_RAW_CAST(i,int,f,float)
ML_DEFINE_RAW_CAST(d,double,li,long int)
ML_DEFINE_RAW_CAST(li,long int,d,double)

