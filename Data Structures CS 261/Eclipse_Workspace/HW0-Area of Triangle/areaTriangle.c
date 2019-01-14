/*
 * areaTriangle.c
 *
 *  Created on: Jan 12, 2019
 *      Author: Xiao Kuang
 */

#include <stdio.h>
#include <math.h>

//formula for area of triangle
//A = sqrt ( s(s-a)(s-b)(s-c)),
//where s = (a+b+c)/2




void areaTriangle(double a, double b, double c){
	double s = ((a + b + c)/2);

	printf("%f ",sqrt(s*(s-a)*(s-b)*(s-c)));
}

int main() {

	areaTriangle(3,4,5);
	areaTriangle(5,5,6);
	areaTriangle(5,5,8);
	areaTriangle(13,4,15);

	return 0;

}


