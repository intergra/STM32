#include<stdio.h>
int main()
{
	float a, b, c,maxx;
	scanf_s("%f%f%f",&a,&b,&c);
	maxx = a;
	if (b > maxx)
		maxx = b;
	if (c > maxx)
		maxx = c;
	printf("%f",maxx);
	return 0;
}