#ifndef ESTC3D_H
#define ESTC3D_H

#include <stddef.h>
#include <stdbool.h>


#define ESTCFloat float
#define VECTOR_SIZE 3


/**
 *  Representation of 3D vector 
**/
typedef struct 
{
	ESTCFloat coords[VECTOR_SIZE];

} ESTCVector3;


#ifdef __cplusplus
 extern "C" {
#endif

/**
 *  Initialization of vector. Fills all coords by zero
***/
void estc_vector3_ctor(ESTCVector3 *vector3);


/**
 *  Initialization of vector. Initialize vector by given values
***/
void estc_vector3_ctor3f(ESTCVector3 *vector3, ESTCFloat a1, ESTCFloat a2, ESTCFloat a3);


/**
 *  Allocate memory for ESTCVector3, fills all coords by zero.
 *  Returns pointer to allocated struct.
***/
ESTCVector3 * estc_vector3_new();


/**
 *  Free instance of ESTCVector3, previously allocated by estc_vector3_new
***/
void estc_vector3_free(ESTCVector3 * vector3 );

/**
 *  Just print vector coords for debug purposes
**/
void estc_vector3_dump(ESTCVector3 *vector3);

/**
 *  Composes a string that contains printable value of vector3.
 *  buff - pointer to a buffer where the resulting C-string is stored. buff  should have a size of at least n characters
 *  n - maximum number of bytes to be used in the buffer. The generated string has a length of at most n-1, leaving space for the additional terminating null character
 *  Returns the number of characters that would have been written if n had been sufficiently large, not counting the terminating null character.
**/
int estc_vector3_snprint(char * buff, size_t n, ESTCVector3 * vector3);


/**
 *  Vector summation
**/
void estc_vector3_add(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCVector3 * out);


/**
 *  Vector subtraction
**/
void estc_vector3_sub(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCVector3 * out);



/**
 *  Scalar product
**/
ESTCFloat estc_vector3_dot(ESTCVector3 * arg1, ESTCVector3 * arg2);



/**
 *  Scalar product
**/
void estc_vector3_cross(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCVector3 * out);

/**
 *  Check if vectors are equal
 *  disp threshold = threshold of RMSE^2. Must be positive.
**/
bool estc_vector3_cmp(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCFloat disp_threshold);


#ifdef __cplusplus
}
#endif


#endif  /* ESTC3D_H */
