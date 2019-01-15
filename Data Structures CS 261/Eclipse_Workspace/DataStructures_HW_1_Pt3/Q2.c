/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomize(int max){
	return (rand() % max);
}


void swap(int* a, int* b){
	//store address pointed to by 'a' in temp variable
	int* temp = a;
	//set a to point to address that 'b' points to
	a = b;
	b = temp;
}

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
	swap(a, b);

    /*Decrement the value of integer variable c*/
	c--;
    
    /*Return c*/
	return c;
}

int main(){
	srand(time(NULL));

    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z = 0;
    x = randomize(10);
    y = randomize(10);
    z = randomize(10);
    /*Print the values of x, y and z*/
    printf("Values of x, y, and z: %d %d %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returned = foo(&x, &y, z);
    /*Print the values of x, y and z*/
    printf("Values of x, y, and z are now: %d %d %d\n", x, y, z);
    
    /*Print the value returned by foo*/
    printf("Value returned by foo: %d\n", returned);

    return 0;
}
    
    


