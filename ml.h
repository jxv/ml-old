#ifndef ML_H
#define ML_H

#include <stdbool.h>

#define DECL_POINT(B,TY)	\
	TY mlAbs##B(const TY x);	\
	TY mlSqrt##B(const TY x);	\
	bool mlNearZero##B(const TY x);	\
	TY mlClamp##B(const TY low, const TY hi, const TY x);

DECL_POINT(i,int)
DECL_POINT(f,float)
DECL_POINT(d,double)

#define DECL_V2(A,B,TY)	\
	typedef struct {	\
		union {	\
			struct {	\
				TY x;	\
				TY y;	\
			};	\
			TY v[2];	\
		};	\
	} ML_V2##A;	\
	\
	ML_V2##A mlV2##B(const TY x, const TY y);	\
	ML_V2##A mlV2##B##Point(const TY x);	\
	ML_V2##A mlAbsV2##B(const ML_V2##A x);	\
	ML_V2##A mlAddV2##B##V2##B(const ML_V2##A x, const ML_V2##A y);	\
	ML_V2##A mlSubV2##B##V2##B(const ML_V2##A x, const ML_V2##A y);	\
	ML_V2##A mlMulV2##B##V2##B(const ML_V2##A x, const ML_V2##A y);	\
	ML_V2##A mlDivV2##B##V2##B(const ML_V2##A x, const ML_V2##A y);	\
	ML_V2##A mlAddV2##B##B(const ML_V2##A x, const TY y);	\
	ML_V2##A mlSubV2##B##B(const ML_V2##A x, const TY y);	\
	ML_V2##A mlMulV2##B##B(const ML_V2##A x, const TY y);	\
	ML_V2##A mlDivV2##B##B(const ML_V2##A x, const TY y);	\
	TY mlSqLenV2##B(const ML_V2##A x);	\
	TY mlLenV2##B(const ML_V2##A x);	\
	ML_V2##A mlClampV2##B(const ML_V2##A low, const ML_V2##A hi, const ML_V2##A x);

DECL_V2(I,i,int)
DECL_V2(F,f,float)
DECL_V2(D,d,double)

#endif
