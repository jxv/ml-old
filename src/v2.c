#include "ml.h"

#define ML_DEFINE_V2_CTOR(A,T)\
inline MLV2##A mlV2##A(T x, T y) {\
	return (MLV2##A) {\
		.x = x,\
		.y = y,\
	};\
}\
inline MLV2##A mlV2Fill##A(T x) {\
	return mlV2##A(x,x);\
}\
inline MLV2##A mlV2Zero##A() {\
	return mlV2##A(0,0);\
}\
inline MLV2##A mlV2One##A() {\
	return mlV2##A(1,1);\
}

ML_DEFINE_V2_CTOR(b,bool)
ML_DEFINE_V2_CTOR(i,int)
ML_DEFINE_V2_CTOR(li,long int)
ML_DEFINE_V2_CTOR(f,float)
ML_DEFINE_V2_CTOR(d,double)
ML_DEFINE_V2_CTOR(ld,long double)

#define ML_DEFINE_V2_NUMBER(A,T)\
inline MLV2##A mlAbsV2##A(MLV2##A x) {\
	return mlV2##A(mlAbs##A(x.x), mlAbs##A(x.y));\
}\
inline MLV2##A mlSignumV2##A(MLV2##A x) {\
	return mlV2##A(mlSignum##A(x.x), mlSignum##A(x.y));\
}\
inline MLV2##A mlNegateV2##A(MLV2##A x) {\
	return mlV2##A(mlNegate##A(x.x), mlNegate##A(x.y));\
}\
inline MLV2##A mlAddV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlAdd##A(x.x, y.x), mlAdd##A(x.y, y.y));\
}\
inline MLV2##A mlSubV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlSub##A(x.x, y.x), mlSub##A(x.y, y.y));\
}\
inline MLV2##A mlMulV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlMul##A(x.x, y.x), mlMul##A(x.y, y.y));\
}\
inline MLV2##A mlDivV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlDiv##A(x.x, y.x), mlDiv##A(x.y, y.y));\
}\
inline MLV2##A mlAddV2##A##A(MLV2##A x, T y) {\
	return mlV2##A(mlAdd##A(x.x, y), mlAdd##A(x.y, y));\
}\
inline MLV2##A mlSubV2##A##A(MLV2##A x, T y) {\
	return mlV2##A(mlSub##A(x.x, y), mlSub##A(x.y, y));\
}\
inline MLV2##A mlMulV2##A##A(MLV2##A x, T y) {\
	return mlV2##A(mlMul##A(x.x, y), mlMul##A(x.y, y));\
}\
inline MLV2##A mlDivV2##A##A(MLV2##A x, T y) {\
	return mlV2##A(mlDiv##A(x.x, y), mlDiv##A(x.y, y));\
}

ML_DEFINE_V2_NUMBER(i,int)
ML_DEFINE_V2_NUMBER(li,long int)
ML_DEFINE_V2_NUMBER(f,float)
ML_DEFINE_V2_NUMBER(d,double)
ML_DEFINE_V2_NUMBER(ld,long double)

#define ML_DEFINE_V2_COMPARE(A)\
inline MLV2b mlLessThanV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2b(mlLessThan##A(x.x, y.x), mlLessThan##A(x.y, y.y));\
}\
inline MLV2b mlLessThanOrEqualV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2b(mlLessThanOrEqual##A(x.x, y.x), mlLessThanOrEqual##A(x.y, y.y));\
}\
inline MLV2b mlGreatherThanV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2b(mlGreaterThan##A(x.x, y.x), mlGreaterThan##A(x.y, y.y));\
}\
inline MLV2b mlGreatherThanOrEqualV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2b(mlGreaterThanOrEqual##A(x.x, y.x), mlGreaterThanOrEqual##A(x.y, y.y));\
}\
inline MLV2b mlEqualV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2b(mlEqual##A(x.x, y.x), mlEqual##A(x.y, y.y));\
}

ML_DEFINE_V2_COMPARE(i)
ML_DEFINE_V2_COMPARE(f)
ML_DEFINE_V2_COMPARE(d)
ML_DEFINE_V2_COMPARE(ld)

#define ML_DEFINE_V2_ORDER(A)\
inline MLV2##A mlMinV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlMin##A(x.x, y.x), mlMin##A(x.y, y.y));\
}\
inline MLV2##A mlMaxV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlMax##A(x.x, y.x), mlMax##A(x.y, y.y));\
}\
inline MLV2##A mlClampV2##A(MLV2##A low, MLV2##A hi, MLV2##A x) {\
	return mlV2##A(mlClamp##A(low.x, hi.x, x.x), mlClamp##A(low.y, hi.y, x.y));\
}

ML_DEFINE_V2_ORDER(f)
ML_DEFINE_V2_ORDER(d)
ML_DEFINE_V2_ORDER(ld)

#define ML_DEFINE_V2_NEAR_ZERO(A)\
inline bool mlNearZeroV2##A(MLV2##A x) {\
	return mlNearZero##A(x.x) && mlNearZero##A(x.y);\
}

ML_DEFINE_V2_NEAR_ZERO(f)
ML_DEFINE_V2_NEAR_ZERO(d)
ML_DEFINE_V2_NEAR_ZERO(ld)

#define ML_DEFINE_V2_RECIPORCAL(A)\
inline MLV2##A mlRecipV2##A(MLV2##A x) {\
	return mlV2##A(mlRecip##A(x.x), mlRecip##A(x.y));\
}\
inline MLV2##A mlRecipNoInfV2##A(MLV2##A x) {\
	return mlV2##A(mlRecipNoInf##A(x.x), mlRecipNoInf##A(x.y));\
}

ML_DEFINE_V2_RECIPORCAL(f)
ML_DEFINE_V2_RECIPORCAL(d)
ML_DEFINE_V2_RECIPORCAL(ld)

#define ML_DEFINE_V2_MODULUS(A,T)\
inline MLV2##A mlModV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlMod##A(x.x, y.x), mlMod##A(x.y, y.y));\
}\
inline MLV2##A mlModV2##A##A(MLV2##A x, T y) {\
	return mlV2##A(mlMod##A(x.x, y), mlMod##A(x.y, y));\
}

ML_DEFINE_V2_MODULUS(f,float)
ML_DEFINE_V2_MODULUS(d,double)
ML_DEFINE_V2_MODULUS(ld,long double)

#define ML_DEFINE_V2_POWER(A,T)\
inline MLV2##A mlPowV2##A(MLV2##A x, MLV2##A y) {\
	return mlV2##A(mlPow##A(x.x, y.x), mlPow##A(x.y, y.y));\
}\
inline MLV2##A mlPowV2##A##A(MLV2##A x, T y) {\
	return mlV2##A(mlPow##A(x.x, y), mlPow##A(x.y, y));\
}

ML_DEFINE_V2_POWER(f,float)
ML_DEFINE_V2_POWER(d,double)
ML_DEFINE_V2_POWER(ld,long double)

#define ML_DEFINE_V2_REAL_FRACTION(A)\
inline MLV2##A mlRoundV2##A(MLV2##A x) {\
	return mlV2##A(mlRound##A(x.x), mlRound##A(x.y));\
}\
inline MLV2##A mlFloorV2##A(MLV2##A x) {\
	return mlV2##A(mlFloor##A(x.x), mlFloor##A(x.y));\
}\
inline MLV2##A mlCeilV2##A(MLV2##A x) {\
	return mlV2##A(mlCeil##A(x.x), mlCeil##A(x.y));\
}\
inline MLV2##A mlTruncateV2##A(MLV2##A x) {\
	return mlV2##A(mlTruncate##A(x.x), mlTruncate##A(x.y));\
}

ML_DEFINE_V2_REAL_FRACTION(f)
ML_DEFINE_V2_REAL_FRACTION(d)
ML_DEFINE_V2_REAL_FRACTION(ld)

#define ML_DEFINE_V2_VECTOR(A,T)\
inline T mlSqLenV2##A(MLV2##A x) {\
	return mlMul##A(x.x, x.x) + mlMul##A(x.y, x.y);\
}\
inline T mlLenV2##A(MLV2##A x) {\
	return mlSqrt##A(mlSqLenV2##A(x));\
}\
inline T mlSqDistV2##A(MLV2##A x, MLV2##A y) {\
	const T dx = mlSub##A(x.x, y.x);\
	const T dy = mlSub##A(x.y, y.y);\
	return mlAdd##A(mlMul##A(dx, dx), mlMul##A(dy, dy));\
}\
inline T mlDistV2##A(MLV2##A x, MLV2##A y) {\
	return mlSqrt##A(mlSqDistV2##A(x, y));\
}\
inline T mlManhattanDistV2##A(MLV2##A x, MLV2##A y) {\
	return mlAdd##A(mlAbs##A(mlSub##A(x.x, y.x)), mlAbs##A(mlSub##A(x.y, y.y)));\
}\
inline T mlDotV2##A(MLV2##A x, MLV2##A y) {\
	return mlAdd##A(mlMul##A(x.x, y.x), mlMul##A(x.y, y.y));\
}\
inline MLV2##A mlNormalizeV2##A(MLV2##A x) {\
	T len = mlLenV2##A(x);\
	if (mlGreaterThan##A(len, mlEpsilon##A())) {\
		return mlDivV2##A##A(x, len);\
	}\
	return x;\
}\
inline MLV2##A mlReflectV2##A(MLV2##A x, MLV2##A y) {\
	return mlSubV2##A(x, mlMulV2##A##A(y, mlMul##A(mlDotV2##A(x, y), mlPrimitive##A(2))));\
}

ML_DEFINE_V2_VECTOR(f,float)
ML_DEFINE_V2_VECTOR(d,double)
ML_DEFINE_V2_VECTOR(ld,long double)

int mlHashV2f(MLV2f x) {
  return mlAbsi(mlRawCastfToi(x.x) ^ mlRawCastfToi(x.y));
}

int mlMixHashV2f(MLV2f v) {
	int raw_vx = mlAbsi(mlRawCastfToi(v.x));
	int raw_vy = mlAbsi(mlRawCastfToi(v.y));

	int h1 = raw_vx << 1;
	int h2 = raw_vy << 3;
	int h3 = raw_vx >> 8;
	
	int h4 = raw_vy << 7;
	int h5 = raw_vx >> 12;
	int h6 = raw_vy >> 15;

	int h7 = raw_vx << 2;
	int h8 = raw_vy << 6;
	int h9 = raw_vx >> 2;
	
	int h10 = raw_vy << 9;
	int h11 = raw_vx >> 21;
	int h12 = raw_vy >> 13;
	
	int res1 = h1 ^ h2 ^ h3;
	int res2 = h4 ^ h5 ^ h6;
	int res3 = h7 ^ h8 ^ h9;
	int res4 = h10 ^ h11 ^ h12;
	
	return (res1 * 10252247) ^ (res2 * 70209673) ^ (res3 * 104711) ^ (res4 * 63589);
}

