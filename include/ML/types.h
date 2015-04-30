#ifndef ML_TYPES_H
#define ML_TYPES_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ML_DECLARE_V2(A,T)	\
typedef struct {	\
	union {	\
		struct {	\
			T x;	\
			T y;	\
		};	\
		T val[2];	\
	};	\
} MLV2##A;

ML_DECLARE_V2(b,bool)
ML_DECLARE_V2(i,int)
ML_DECLARE_V2(li,long int)
ML_DECLARE_V2(f,float)
ML_DECLARE_V2(d,double)
ML_DECLARE_V2(ld,long double)

#define ML_DECLARE_V3(A,T)	\
typedef struct {	\
	union {	\
		struct {	\
			T x;	\
			T y;	\
			T z;	\
		};	\
		T val[3];	\
	};	\
} MLV3##A;

ML_DECLARE_V3(b,bool)
ML_DECLARE_V3(i,int)
ML_DECLARE_V3(li,long int)
ML_DECLARE_V3(f,float)
ML_DECLARE_V3(d,double)
ML_DECLARE_V3(ld,long double)

#define ML_DECLARE_V4(A,T)	\
typedef struct {	\
	union {	\
		struct {	\
			T x;	\
			T y;	\
			T z;	\
			T w;	\
		};	\
		T val[4];	\
	};	\
} MLV4##A;

ML_DECLARE_V4(b,bool)
ML_DECLARE_V4(i,int)
ML_DECLARE_V4(li,long int)
ML_DECLARE_V4(f,float)
ML_DECLARE_V4(d,double)
ML_DECLARE_V4(ld,long double)

#define ML_DECLARE_M2(A,T)	\
typedef struct {	\
	union {	\
		struct {	\
			MLV2##A x;	\
			MLV2##A y;	\
		};	\
		MLV2##A v[2];	\
		T val[4];	\
	};	\
} MLM2##A;

ML_DECLARE_M2(b,bool)
ML_DECLARE_M2(i,int)
ML_DECLARE_M2(li,long int)
ML_DECLARE_M2(f,float)
ML_DECLARE_M2(d,double)
ML_DECLARE_M2(ld,long double)

#define ML_DECLARE_M3(A,T)	\
typedef struct {	\
	union {	\
		struct {	\
			MLV3##A x;	\
			MLV3##A y;	\
			MLV3##A z;	\
		};	\
		MLV3##A v[3];	\
		T val[9];	\
	};	\
} MLM3##A;

ML_DECLARE_M3(b,bool)
ML_DECLARE_M3(i,int)
ML_DECLARE_M3(li,long int)
ML_DECLARE_M3(f,float)
ML_DECLARE_M3(d,double)
ML_DECLARE_M3(ld,long double)

#define ML_DECLARE_M4(A,T)	\
typedef struct {	\
	union {	\
		struct {	\
			MLV4##A x;	\
			MLV4##A y;	\
			MLV4##A z;	\
			MLV4##A w;	\
		};	\
		MLV4##A v[4];	\
		T val[16];	\
	};	\
} MLM4##A;

ML_DECLARE_M4(b,bool)
ML_DECLARE_M4(i,int)
ML_DECLARE_M4(li,long int)
ML_DECLARE_M4(f,float)
ML_DECLARE_M4(d,double)
ML_DECLARE_M4(ld,long double)

#ifdef __cplusplus
}
#endif

#endif
