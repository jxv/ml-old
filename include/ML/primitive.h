#ifndef ML_PRIMITIVE_H
#define ML_PRIMITIVE_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ML_DECLARE_PRIMITIVE_CTOR(A,T,S)\
T mlPrimitive##A(S x);

ML_DECLARE_PRIMITIVE_CTOR(b,bool,bool)
ML_DECLARE_PRIMITIVE_CTOR(i,int,int)
ML_DECLARE_PRIMITIVE_CTOR(li,long int,long int)
ML_DECLARE_PRIMITIVE_CTOR(f,float,float)
ML_DECLARE_PRIMITIVE_CTOR(d,double,double)
ML_DECLARE_PRIMITIVE_CTOR(ld,long double,long double)

#define ML_DECLARE_PRIMITIVE_NUMBER(A,T)\
T mlAbs##A(T x);\
T mlSignum##A(T x);\
T mlNegate##A(T x);\
T mlAdd##A(T x, T y);\
T mlSub##A(T x, T y);\
T mlMul##A(T x, T y);\
T mlDiv##A(T x, T y);

ML_DECLARE_PRIMITIVE_NUMBER(i,int)
ML_DECLARE_PRIMITIVE_NUMBER(li,long int)
ML_DECLARE_PRIMITIVE_NUMBER(f,float)
ML_DECLARE_PRIMITIVE_NUMBER(d,double)
ML_DECLARE_PRIMITIVE_NUMBER(ld,long double)

#define ML_DECLARE_PRIMITIVE_COMPARE(A,T)\
bool mlLessThan##A(T x, T y);\
bool mlLessThanOrEqual##A(T x, T y);\
bool mlGreaterThan##A(T x, T y);\
bool mlGreaterThanOrEqual##A(T x, T y);\
bool mlEqual##A(T x, T y);

ML_DECLARE_PRIMITIVE_COMPARE(i,int)
ML_DECLARE_PRIMITIVE_COMPARE(li,long int)
ML_DECLARE_PRIMITIVE_COMPARE(f,float)
ML_DECLARE_PRIMITIVE_COMPARE(d,double)
ML_DECLARE_PRIMITIVE_COMPARE(ld,long double)

#define ML_DECLARE_PRIMITIVE_ORDER(A,T)\
T mlMin##A(T x, T y);\
T mlMax##A(T x, T y);\
T mlClamp##A(T low, T hi, T x);

ML_DECLARE_PRIMITIVE_ORDER(i,int)
ML_DECLARE_PRIMITIVE_ORDER(li,long int)
ML_DECLARE_PRIMITIVE_ORDER(f,float)
ML_DECLARE_PRIMITIVE_ORDER(d,double)
ML_DECLARE_PRIMITIVE_ORDER(ld,long double)

#define ML_DECLARE_PRIMITIVE_NEAR_ZERO(A,T)\
bool mlNearZero##A(T x);

ML_DECLARE_PRIMITIVE_NEAR_ZERO(f,float)
ML_DECLARE_PRIMITIVE_NEAR_ZERO(d,double)
ML_DECLARE_PRIMITIVE_NEAR_ZERO(ld,long double)

#define ML_DECLARE_PRIMITIVE_RECIPORCAL(A,T)\
T mlRecip##A(T x);\
T mlRecipNoInf##A(T x);

ML_DECLARE_PRIMITIVE_RECIPORCAL(f,float)
ML_DECLARE_PRIMITIVE_RECIPORCAL(d,double)
ML_DECLARE_PRIMITIVE_RECIPORCAL(ld,long double)

#define ML_DECLARE_PRIMITIVE_MODULUS(A,T)\
T mlMod##A(T x, T y);

ML_DECLARE_PRIMITIVE_MODULUS(i,int)
ML_DECLARE_PRIMITIVE_MODULUS(li,long int)
ML_DECLARE_PRIMITIVE_MODULUS(f,float)
ML_DECLARE_PRIMITIVE_MODULUS(d,double)
ML_DECLARE_PRIMITIVE_MODULUS(ld,long double)

#define ML_DECLARE_PRIMITIVE_FLOATING_POINT(A,T)\
T mlPiDiv4##A();\
T mlPiDiv2##A();\
T mlPi##A();\
T mlPiMul2##A();\
T mlTau##A();\
T mlEuler##A();\
T mlPhi##A();\
T mlEpsilon##A();\
T mlExp##A(T x);\
T mlLog##A(T x);\
T mlSqrt##A(T x);\
T mlPow##A(T x, T y);\
T mlLogBase##A(T base, T x);\
T mlSin##A(T x);\
T mlCos##A(T x);\
T mlTan##A(T x);\
T mlArcSin##A(T x);\
T mlArcCos##A(T x);\
T mlArcTan##A(T x);\
T mlSinH##A(T x);\
T mlCosH##A(T x);\
T mlTanH##A(T x);\
T mlArcSinH##A(T x);\
T mlArcCosH##A(T x);\
T mlArcTanH##A(T x);\
T mlSaturate##A(T x);

ML_DECLARE_PRIMITIVE_FLOATING_POINT(f,float)
ML_DECLARE_PRIMITIVE_FLOATING_POINT(d,double)
ML_DECLARE_PRIMITIVE_FLOATING_POINT(ld,long double)

#define ML_DECLARE_PRIMITIVE_REAL_FRACTION(A,T)\
T mlRound##A(T x);\
T mlFloor##A(T x);\
T mlCeil##A(T x);\
T mlTruncate##A(T x);

ML_DECLARE_PRIMITIVE_REAL_FRACTION(f,float)
ML_DECLARE_PRIMITIVE_REAL_FRACTION(d,double)
ML_DECLARE_PRIMITIVE_REAL_FRACTION(ld,long double)

#define ML_DECLARE_PRIMITIVE_BETWEEN(A,T)\
bool mlBetweenInclusive##A(T low, T hi, T x);\
bool mlBetweenExclusive##A(T low, T hi, T x);

ML_DECLARE_PRIMITIVE_BETWEEN(f,float)
ML_DECLARE_PRIMITIVE_BETWEEN(d,double)
ML_DECLARE_PRIMITIVE_BETWEEN(ld,long double)

#define ML_DECLARE_PRIMITIVE_INTERPOLATE(A,T)\
T mlLerp##A(T x, T y, T s);\
T mlSmoothStep##A(T x, T y, T s);\
T mlSmootherStep##A(T x, T y, T s);\
T mlCosInterpolate##A(T x, T y, T s);\
T mlCubicInterpolate##A(T x, T y, T z, T w, T s);\
T mlNearestInterpolate##A(T x, T y, T s);\
T mlBiNearestInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy);\
T mlBilinearInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy);\
T mlBiCosInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy);\
T mlBiSmoothStepInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy);\
T mlBiSmootherstepInterpolate##A(T tl, T tr, T bl, T br, T sx, T sy);

ML_DECLARE_PRIMITIVE_INTERPOLATE(f,float)
ML_DECLARE_PRIMITIVE_INTERPOLATE(d,double)
ML_DECLARE_PRIMITIVE_INTERPOLATE(ld,long double)

#define ML_DECLARE_RAW_CAST(A,TA,B,TB)\
TB mlRawCast##A##To##B(TA x);

ML_DECLARE_RAW_CAST(f,float,i,int)
ML_DECLARE_RAW_CAST(i,int,f,float)
ML_DECLARE_RAW_CAST(d,double,li,long int)
ML_DECLARE_RAW_CAST(li,long int,d,double)

#ifdef __cplusplus
}
#endif

#endif
