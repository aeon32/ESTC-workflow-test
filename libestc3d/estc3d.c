#include "estc3d.h"
#include <stdlib.h>
#include <stdio.h>



/**
 *  Initialization of vector. Fills all coords by zero
***/
void estc_vector3_ctor(ESTCVector3 *vector3)
{
	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		vector3->coords[i] = 0;
	};

};


/**
 *  Initialization of vector. Initialize vector by given values
***/
void estc_vector3_ctor3f(ESTCVector3 *vector3, ESTCFloat a1, ESTCFloat a2, ESTCFloat a3)
{
	vector3->coords[0] = a1;
	vector3->coords[1] = a2;
	vector3->coords[2] = a3;


};


/**
 *  Allocate memory for ESTCVector3, fills all coords by zero.
 *  Returns pointer to allocated struct.
***/
ESTCVector3 * estc_vector3_new()
{
	ESTCVector3 * res = (ESTCVector3 *) malloc(sizeof(ESTCVector3));
	if (res != NULL)
	{
		estc_vector3_ctor(res);

	};

	return res;

};


/**
 *  Free instance of ESTCVector3, previously allocated by estc_vector3_new
***/
void estc_vector3_free(ESTCVector3 * vector3 )
{
	free(vector3);

};





int estc_vector3_snprint(char * buff, size_t n, ESTCVector3 * vector3)
{

	char * pbuff = buff;
	char * buff_end = buff + n;

	*pbuff = '[';
	pbuff++;

	int total_width = 1;
    
	for (int i = 0; i< VECTOR_SIZE; i++)
	{
		const char * format = (i == VECTOR_SIZE - 1) ? "%.6e" : "%.6e, ";
		int need_chars = snprintf(pbuff, buff_end - pbuff, format, vector3->coords[i]);
		pbuff += need_chars;
		total_width += need_chars;
	};

	total_width +=1; //trailing ]
	if (total_width < n -1)
	{
       *(pbuff++) = ']';
       *pbuff = 0;
	};

	
	return total_width;

};



//should be enough for output vector3 value
#define DUMP_BUFF_SIZE (VECTOR_SIZE * 25 + 3)
/**
 *  Just print vector coords for debug purposes
**/
void estc_vector3_dump(ESTCVector3 *vector3)
{
	char buffer [DUMP_BUFF_SIZE];
	int size = estc_vector3_snprint(buffer, DUMP_BUFF_SIZE , vector3);

	printf("%s\n", buffer);

};


/**
 *  Vector summation
**/
void estc_vector3_add(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCVector3 * out)
{
	for (int i =0; i < VECTOR_SIZE; i++)
	{
		out->coords[i] = arg1->coords[i] + arg2->coords[i];

	};


};


/**
 *  Vector subtraction
**/
void estc_vector3_sub(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCVector3 * out)
{
	for (int i =0; i < VECTOR_SIZE; i++)
	{
		out->coords[i] = arg1->coords[i] - arg2->coords[i];

	};

};


/**
 *  Scalar product
**/
ESTCFloat estc_vector3_dot(ESTCVector3 * arg1, ESTCVector3 * arg2)
{
	ESTCFloat result;

	for (int i =0; i < VECTOR_SIZE; i++)
	{
		result +=  arg1->coords[i] * arg2->coords[i];

	};

	return result;

};


void estc_vector3_cross(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCVector3 * out)
{
	out->coords[0] = arg1->coords[1] * arg2->coords[2] - arg1->coords[2] * arg2->coords[1];
	out->coords[1] = arg1->coords[2] * arg2->coords[0] - arg1->coords[0] * arg2->coords[2];
	out->coords[2] = arg1->coords[0] * arg2->coords[1] - arg1->coords[1] * arg2->coords[0];
};


bool estc_vector3_cmp(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCFloat disp_threshold)
{
	ESTCFloat disp = 0;
	for (int i =0; i < VECTOR_SIZE ; i++)
	{
		disp +=  (arg1->coords[i] - arg2->coords[i])*(arg1->coords[i] - arg2->coords[i]);
	};

	return (disp / VECTOR_SIZE) <= disp_threshold;


};

