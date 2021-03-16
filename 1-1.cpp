#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float a,b,c,p,s;
	
	scanf("%f %f %f", &a, &b, &c);
	p = (a+b+c)/2;
	s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("the area of triangle is %.2f", s);
	
	return 0;
 } 
