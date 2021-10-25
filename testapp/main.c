
#include <stdio.h>
#include <libestc3d/estc3d.h>

void printResult(ESTCVector3 * arg1, ESTCVector3 * arg2, ESTCVector3 * res, const char * fmt)
{
	const size_t BUFFSIZE = 50;
	char arg1Dump[BUFFSIZE];
	char arg2Dump[BUFFSIZE];
	char resDump[BUFFSIZE];

	estc_vector3_snprint(arg1Dump, BUFFSIZE, arg1);
	estc_vector3_snprint(arg2Dump, BUFFSIZE, arg2);
	estc_vector3_snprint(resDump, BUFFSIZE, res);

	printf(fmt, arg1Dump, arg2Dump, resDump);


};


void testSum()
{
	ESTCVector3 arg1;
	ESTCVector3 arg2;
	ESTCVector3 sum;
	

	estc_vector3_ctor3f(&arg1, 1, 2, 3);
	estc_vector3_ctor3f(&arg2, 5, 4, 6);
	estc_vector3_add(&arg1, &arg2, &sum);

    printResult(&arg1, &arg2, &sum, "%s + %s = %s\n");


};

void testSub()
{
	ESTCVector3 arg1;
	ESTCVector3 arg2;
	ESTCVector3 sub;
	
    estc_vector3_ctor3f(&arg1, 1, 2, 3);
	estc_vector3_ctor3f(&arg2, 11, 22, 33);
	estc_vector3_sub(&arg1, &arg2, &sub);

    printResult(&arg1, &arg2, &sub, "%s - %s = %s\n");

};


void testDot()
{
	const size_t BUFFSIZE = 50;
	ESTCVector3 arg1;
	ESTCVector3 arg2;
	
    estc_vector3_ctor3f(&arg1, 5, 3, 0);
	estc_vector3_ctor3f(&arg2, -33, 55, 0);  //orthogonal vectors
	ESTCFloat res = estc_vector3_dot(&arg1, &arg2);


	char arg1Dump[BUFFSIZE];
	char arg2Dump[BUFFSIZE];
	estc_vector3_snprint(arg1Dump, BUFFSIZE, &arg1);
	estc_vector3_snprint(arg2Dump, BUFFSIZE, &arg2);

    printf("%s * %s = %.3e\n", arg1Dump, arg2Dump, res);

};



void testCross()
{
	ESTCVector3 arg1;
	ESTCVector3 arg2;
	ESTCVector3 cross;
	
    estc_vector3_ctor3f(&arg1, 5, 0, 0);
	estc_vector3_ctor3f(&arg2, 0, 4, 0);
	estc_vector3_cross(&arg1, &arg2, &cross);

    printResult(&arg1, &arg2, &cross, "%s x %s = %s\n");

};

int main(int argc, char ** argv)
{

    testSum();
    testSub();
    testDot();
    testCross();
};