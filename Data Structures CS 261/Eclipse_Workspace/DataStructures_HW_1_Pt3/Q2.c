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
	//swap(&a, &b);
	int *temp = a;
	a = b;
	b = temp;

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
     * 	  	No, the values of x and y are the same before and after the call to foo(..).
     * 	  	I believe that when x and y are passed as parameters and their addresses are swapped
     * 	  	inside of foo, the values of a and b, which point to x and y, respectively, are actually
     * 	  	swapped and the addresses of x and y stay the same, and when values of x and y are printed
     * 	  	after foo(..) is called, they are identical to before the function was called.
     */


