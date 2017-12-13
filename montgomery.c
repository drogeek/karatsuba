#include <stdio.h>
#include <stdlib.h>
#include "extendedEuclid.h"

typedef unsigned int uint;

#define DEFAULT_PW_R 5

uint REDC(const uint t,const uint r,const uint n,const int neg_inv_n)
{
	printf("t=%u\n",t);
	printf("invn=%d", (neg_inv_n*n)%r);
	uint res;
	uint m = ((t%r)*neg_inv_n)%r;
	res = (t+m*n)<<r;
	if (res >= n)
		return res-n;
	else
		return res;
}
uint repr_Montgomery(uint x,uint R, uint N)
{
	//x<<=powerOfTwo;
	x=x*R;
	return x%N; // is that expensive?
}

int main(int argc, char** argv)
{
	ExtEucRes extEucRes;
	/*
	uint powerOfTwo=DEFAULT_PW_R;
	do
	//we wanta power of 2 that is coprime with n
	//note that this is useless if n is odd
	while(extEucRes.r-1)
	{
		extEucRes=extendedEuclid(1<<powerOfTwo,n);
		powerOfTwo++;
	}
	*/
	
	uint N=17,R=10;
	uint a=repr_Montgomery(7,R,N);
	printf("a=%u\n",a);
	uint b=repr_Montgomery(15,R,N);
	printf("b=%u\n",b);
	extEucRes=extendedEuclid(R,N);
	printf("%u %d %d\n", extEucRes.r, extEucRes.u, extEucRes.v);
	printf("%u\n",REDC(a*b,R,N,extEucRes.v));

  return EXIT_SUCCESS;
}