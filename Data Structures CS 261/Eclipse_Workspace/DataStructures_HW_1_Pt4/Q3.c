/* CS261- Assignment 1 - Q.3*/
/* Name: 
 * Date: 
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
	return (ch - 32);

}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          
	return (ch + 32);
}

int stringLength(char s[]) {
   /*Return the length of the string*/
	int i = 0;

	while(s[i] != '\0') {   //loop through array starting at i = 0 until reaching the end of string character
		i++;				//because starting at 0 and stopping at the eos character, returning i will give length of string
	}

	return i;
}


void camelCase(char* word){
	/*Convert to camelCase*/
	
	
}

void printWord (char* word) {
	int i = 0;
	while(word[i] != '\n'){
		printf("%c", word[i]);
		i++;
	}

//	for(int i = 0; i < MAX_SIZE; i ++) {
//		if(userInput[i] == '\n'){
//			return ;
//		}
//			printf("%c", userInput[i]);
//	}

}
int main(){
	int MAX_SIZE = 50;
	int i = 0;

	//declare variable for array of characters, with max size:
	char userInput[MAX_SIZE];

	/*Read the string from the keyboard*/

	while(i < MAX_SIZE - 1) {
		scanf("%c", &userInput[i]);
		if(userInput[i] == '\n')
			break;
		i++;
	}
	
	printWord(userInput);
	
	
	/*Print the new string*/
	
	
	return 0;
}

