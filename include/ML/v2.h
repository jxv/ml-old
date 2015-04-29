#ifndef ML_V2_H
#define ML_V2_H

#define ML_DECLARE_V2_CTOR(A,T)\
MLV2##A mlV2##A(T x, T y);\
MLV2##A mlV2Fill##A(T x);\
MLV2##A mlV2Zero##A();\
MLV2##A mlV2One##A();

ML_DECLARE_V2_CTOR(b,bool)
ML_DECLARE_V2_CTOR(i,int)
ML_DECLARE_V2_CTOR(li,long int)
ML_DECLARE_V2_CTOR(f,float)
ML_DECLARE_V2_CTOR(d,double)
ML_DECLARE_V2_CTOR(ld,long double)

#define ML_DECLARE_V2_NUMBER(A,T)\
MLV2##A mlAbsV2##A(MLV2##A x);\
MLV2##A mlSignumV2##A(MLV2##A x);\
MLV2##A mlNegateV2##A(MLV2##A x);\
MLV2##A mlAddV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlSubV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlMulV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlDivV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlAddV2##A##A(MLV2##A x, T y);\
MLV2##A mlSubV2##A##A(MLV2##A x, T y);\
MLV2##A mlMulV2##A##A(MLV2##A x, T y);\
MLV2##A mlDivV2##A##A(MLV2##A x, T y);

ML_DECLARE_V2_NUMBER(i,int)
ML_DECLARE_V2_NUMBER(li,long int)
ML_DECLARE_V2_NUMBER(f,float)
ML_DECLARE_V2_NUMBER(d,double)
ML_DECLARE_V2_NUMBER(ld,long double)

#define ML_DECLARE_V2_COMPARE(A)\
MLV2b mlLessThanV2##A(MLV2##A x, MLV2##A y);\
MLV2b mlLessThanOrEqualV2##A(MLV2##A x, MLV2##A y);\
MLV2b mlGreatherThanV2##A(MLV2##A x, MLV2##A y);\
MLV2b mlGreatherThanOrEqualV2##A(MLV2##A x, MLV2##A y);\
MLV2b mlEqualV2##A(MLV2##A x, MLV2##A y);

ML_DECLARE_V2_COMPARE(i)
ML_DECLARE_V2_COMPARE(f)
ML_DECLARE_V2_COMPARE(d)
ML_DECLARE_V2_COMPARE(ld)

#define ML_DECLARE_V2_ORDER(A)\
MLV2##A mlMinV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlMaxV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlClampV2##A(MLV2##A low, MLV2##A hi, MLV2##A x);

ML_DECLARE_V2_ORDER(f)
ML_DECLARE_V2_ORDER(d)
ML_DECLARE_V2_ORDER(ld)

#define ML_DECLARE_V2_NEAR_ZERO(A)\
bool mlNearZeroV2##A(MLV2##A x);

ML_DECLARE_V2_NEAR_ZERO(f)
ML_DECLARE_V2_NEAR_ZERO(d)
ML_DECLARE_V2_NEAR_ZERO(ld)

#define ML_DECLARE_V2_RECIPORCAL(A)\
MLV2##A mlRecipV2##A(MLV2##A x);\
MLV2##A mlRecipNoInfV2##A(MLV2##A x);

ML_DECLARE_V2_RECIPORCAL(f)
ML_DECLARE_V2_RECIPORCAL(d)
ML_DECLARE_V2_RECIPORCAL(ld)

#define ML_DECLARE_V2_MODULUS(A,T)\
MLV2##A mlModV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlModV2##A##A(MLV2##A x, T y);

ML_DECLARE_V2_MODULUS(f,float)
ML_DECLARE_V2_MODULUS(d,double)
ML_DECLARE_V2_MODULUS(ld,long double)

#define ML_DECLARE_V2_POWER(A,T)\
MLV2##A mlPowV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlPowV2##A##A(MLV2##A x, T y);

ML_DECLARE_V2_POWER(f,float)
ML_DECLARE_V2_POWER(d,double)
ML_DECLARE_V2_POWER(ld,long double)

#define ML_DECLARE_V2_REAL_FRACTION(A)\
MLV2##A mlRoundV2##A(MLV2##A x);\
MLV2##A mlFloorV2##A(MLV2##A x);\
MLV2##A mlCeilV2##A(MLV2##A x);\
MLV2##A mlTruncateV2##A(MLV2##A x);

ML_DECLARE_V2_REAL_FRACTION(f)
ML_DECLARE_V2_REAL_FRACTION(d)
ML_DECLARE_V2_REAL_FRACTION(ld)

#define ML_DECLARE_V2_VECTOR(A,T)\
T mlSqLenV2##A(MLV2##A x);\
T mlLenV2##A(MLV2##A x);\
T mlSqDistV2##A(MLV2##A x, MLV2##A y);\
T mlDistV2##A(MLV2##A x, MLV2##A y);\
T mlManhattanDistV2##A(MLV2##A x, MLV2##A y);\
T mlDotV2##A(MLV2##A x, MLV2##A y);\
MLV2##A mlNormalizeV2##A(MLV2##A x);\
MLV2##A mlReflectV2##A(MLV2##A x, MLV2##A y);

ML_DECLARE_V2_VECTOR(f,float)
ML_DECLARE_V2_VECTOR(d,double)
ML_DECLARE_V2_VECTOR(ld,long double)

int mlHashV2f(MLV2f v);
int mlMixHashV2f(MLV2f v);

#endif
