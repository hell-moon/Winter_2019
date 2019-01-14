/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){	//takes a pointer-to-integer as parameter
  
     /*Print the value and address of the integer pointed to by iptr*/
	printf("Value pointed to by iptr: %d\n", *iptr);
	printf("Address of integer pointed to by iptr: %p\n", iptr);
          
     /*Increment the value of the integer pointed to by iptr by 5*/
	*iptr = *iptr + 5;

     /*Print the address of iptr itself*/
	printf("Address of iptr: %p\n", &iptr);

    /*Dummy variable, ignore the warning*/
   int c=5;  
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
	printf("Value pointed to by jptr: %d\n", *jptr);
	printf("Address of integer pointed to by jptr: %p\n", jptr);
               
     /*Decrement the address by 1 pointed to by jptr using jptr */
	jptr--;

	//printf("Address pointed to by jptr: %p\n", jptr);
    //  ^^above line (37) was used to check and make sure address pointed to by jptr was decremented

     /*Print the address of jptr itself*/
	printf("Address of jptr: %p\n", &jptr);
}


int main(){
    
    /*Declare an integer x and initialize it randomly to a value in [0,10] */
	srand(time(NULL));
	int x;
	x = rand() % 10;

    /*Print the value and address of x*/
    printf("The value of x: %d\n", x );

    printf("The address of x: %p\n",&x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*Print the value of x*/
    printf("The value of x (should be +5 from earlier): %d\n", x);
    /*
     * COMMENT ANSWER:
     * The value of x is different than before because fooA() changes the value pointed to by iptr,
     * essentially, x was passed as reference.
     */
    
    /*Call fooB() with the address of x*/
    fooB(&x);
    
    /*Print the value and address of x*/
    printf("The value of x: %d\n", x );
    printf("The address of x: %p\n",&x);
    /*
     * COMMENT ANSWER:
     * The value and address of x is the same as before fooB() was called because changing the address of
     *
     */
    
    return 0;
}


