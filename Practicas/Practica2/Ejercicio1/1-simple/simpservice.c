#include <stdio.h>
#include "simp.h"

int* add_1_svc(operands *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("Got request: adding %d, %d\n",
	       argp->x, argp->y);

	result = argp->x + argp->y;

	return (&result);
}



int* sub_1_svc(operands *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("Got request: subtracting %d, %d\n",
	       argp->x, argp->y);

	result = argp->x - argp->y;

	return (&result);
}
