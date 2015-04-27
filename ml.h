#ifndef ML_H
#define ML_H

#include <stdbool.h>

#define DECL_POINT(A,TY)	\
	TY mlAbs##A(const TY x);	\
	TY mlSqrt##A(const TY x);	\
	TY mlRecip##A(const TY x);	\
	bool mlNearZero##A(const TY x);	\
	TY mlClamp##A(const TY low, const TY hi, const TY x);

DECL_POINT(i,int)
DECL_POINT(f,float)
DECL_POINT(d,double)

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
	MLV2##A mlV2##A(const TY x, const TY y);	\
	MLV2##A mlV2##A##Point(const TY x);	\
	MLV2##A mlV2##A##Zero();	\
	MLV2##A mlV2##A##One();	\
	MLV2##A mlAbsV2##A(const MLV2##A x);	\
	MLV2##A mlAddV2##A(const MLV2##A x, const MLV2##A y);	\
	MLV2##A mlSubV2##A(const MLV2##A x, const MLV2##A y);	\
	MLV2##A mlMulV2##A(const MLV2##A x, const MLV2##A y);	\
	MLV2##A mlDivV2##A(const MLV2##A x, const MLV2##A y);	\
	MLV2##A mlAddV2##A##A(const MLV2##A x, const TY y);	\
	MLV2##A mlSubV2##A##A(const MLV2##A x, const TY y);	\
	MLV2##A mlMulV2##A##A(const MLV2##A x, const TY y);	\
	MLV2##A mlDivV2##A##A(const MLV2##A x, const TY y);	\
	TY mlSqLenV2##A(const MLV2##A x);	\
	TY mlLenV2##A(const MLV2##A x);	\
	TY mlDotV2##A(const MLV2##A x, const MLV2##A y);	\
	MLV2##A mlNormalizeV2##A(const MLV2##A x);	\
	MLV2##A mlClampV2##A(const MLV2##A low, const MLV2##A hi, const MLV2##A x);	\
	bool mlNearZeroV2##A(const MLV2##A x);

DECL_V2(i,int)
DECL_V2(f,float)
DECL_V2(d,double)

#endif
