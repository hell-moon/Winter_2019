/* CS261- Assignment 1 - Q.2*/
/* Name: Xiao Kuang
 * Date: 1/15/2019
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomize(int max){
	return (rand() % max);
}


void swap(int** a, int** b){
	//store address pointed to by 'a' in temp variable
	int *temp = *a;
	//set a to point to address that 'b' points to
	*a = *b;
	*b = temp;
	;
}

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
	int *temp = *a; /* temp points to value pointed to by a, which is the address of x*/
	*a = *b;		/* value that a points to is adress that b points to, which is address of y*/
	*b = temp;		/* value that b points to is value of temp, which is value pointed to by a, which is address of x*/

    /*Decrement the value of integer variable c*/
	c--;

    /*Return c*/
	return c;
}

int main(){
	srand(time(NULL));

    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z;
    x = randomize(10);
    y = randomize(10);
    z = randomize(10);
    /*Print the values of x, y and z*/
    printf("Values of x, y, and z: %d %d %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returned = foo(&x, &y, z);
    /*Print the values of x, y and z*/
    printf("Values of x, y, and z are now: %d %d %d\n", x, y, z);
    
    //delete this
    //int returned2 = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("Value returned by foo: %d\n", returned);

    return 0;
}
    
    /*
     * COMMENT ANSWERS
     * a) Is the return value different than the value of integer z?
     * 		Yes, return value is 1 less than z; the value of z got decremented in foo
     * 		and since z is not passed as reference, it stays 1 greater than the returned
     * 		value in main().
     *
     * b) Are the values of integers x and y different before and after calling the function
     * 	  foo(..)?
     * 	  	Yes, the values of x and y are different, the swap function swapps the
     * 	  	two addresses each pointer points to, essentially having the label 'x' represent the
     * 	  	value and address of what belonged to 'y' and vice versa.
     */


