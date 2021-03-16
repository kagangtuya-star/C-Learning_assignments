#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float a,b,c,p,s;
	
	cin >> a >> b >> c;
	p = (a+b+c)/2;
	s = sqrt(p*(p-a)*(p-b)*(p-c));
	cout <<	 "the area of triangle is " << s << endl;
	
	return 0;
 } 
