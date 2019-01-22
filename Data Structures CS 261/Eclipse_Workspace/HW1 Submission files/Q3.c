/* CS261- Assignment 1 - Q.3*/
/* Name: Xiao Kuang
 * Date: 1/20/2019
 * Solution description: scanf is used to read in user-input until newline character is read
 * and stored in userInput array. UserInput array is then filtered and characters' ascii codes
 * are analyzed and the only characters kept are upper and lower case letters, underscores, and spaces.
 * The filtered array is called filteredInput.  All letters are converted to lowercase, spaces
 * converted to underscores.  Adjacent underscores are removed, as well as underscores at index 0
 * and at end of array.  Then array is ready to be passed to camelCase which capitalizes letters
 * coming after underscores, then removing the underscores.
 *
 * Verification of input is done by a flag variable, passe to camelCase().  It is checked if
 * a letter is directly following an underscore.  If so, that means that there is indeed an underscore
 * separating two words and the input is valid, and passed is set to 1.
 *
 * If passed, then the correct array will print, if not, then an error message will print.
 */

#include <stdio.h>
#include <stdlib.h>

int passed = 0;

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

	while(s[i] != '\n') {   //loop through array starting at i = 0 until reaching the end of string character
		i++;				//because starting at 0 and stopping at the eos character, returning i will give length of string
	}

	return i;
}


void camelCase(char* word){
	//check each index in word[] for underscore
	//if found, capitalize next index
	for(int i = 0; i < stringLength(word); i++) {
		if(word[i] == 95) {
			passed = 1;
			word[i+1] = toUpperCase(word[i+1]);
		}
	}

	//now, remove the underscores
	//check each index in word[] for underscore
	//if found, shift every index after it, one index to the left
	for(int i = 1; i < stringLength(word); i++) {
		if(word[i] == 95) {
			for(int j = i; j < stringLength(word); j++){
				word[j] = word[j+1];
			}
		}
	}
	
}

void printWord (char* word) {
	int i = 0;
	while(word[i] != '\n'){
		printf("%c", word[i]);
		i++;
	}
}




int main(){
	int MAX_SIZE = 50;
	int i = 0;
	//declare variable for array of characters, with max size:
	char userInput[MAX_SIZE];
	char filteredInput[MAX_SIZE];

	/*Read the string from the keyboard*/

	//printf("Please enter a string you want to convert into camel case, to stop, press 'ENTER'");

	while(i < MAX_SIZE - 1) {
		//keep trying to scanf into input[i] until pass, and then increment i and go to next element

		scanf("%c", &userInput[i]);				//read-in user input
		if(userInput[i] == '\n'){
			break;
		}
		i++;
	}
	
	//filter the input, get rid of all characters except space, uppercase, lowercase, and underscore
	i = 0;								//used to loop thru userInput array
	int j = 0;							//used to loop thru filteredInput array
	while(userInput[i] != '\n'){

		if(((userInput[i] <= 31 || (userInput[i] >=33 && userInput[i] <= 64)
					|| (userInput[i] >= 91 && userInput[i] <= 94)
					|| userInput[i] == 96 || userInput[i] == 127) ) &&
				(((userInput[i+1] >= 65) && (userInput[i+1] <=90)) || ((userInput[i+1] >= 97) && (userInput[i+1] <=122)))){
			filteredInput[j] = 32;
			j++;
			i++;
		}
		else if(userInput[i] <= 31 || (userInput[i] >=33 && userInput[i] <= 64)
			|| (userInput[i] >= 91 && userInput[i] <= 94)
			|| userInput[i] == 96 || userInput[i] == 127){
			//don't save these characters
			i++;
		}
		else {
			filteredInput[j] = userInput[i];
			i++;
			j++;
		}
	}
	
	filteredInput[j] = '\n';

	//make sure the first element of the word is a letter
	//if index 0 of array is a space or character, then delete it and move everything over to left

	//convert all spaces to underscores
	for(int i = 0; i < j; i++){
		if(filteredInput[i] == 32){
			filteredInput[i] = 95;
		}
	}

	//if adjacent underscores, remove them
	//check each index of array if underscore
	//if it is, check index+1 for underscore
	//if it is, replace first underscore and shift everything left
	for(int i = 0; i < stringLength(filteredInput); i++) {
		if(filteredInput[i] == 95 && filteredInput[i+1] == 95) {
			for(int j = i; j < stringLength(filteredInput); j++){
				filteredInput[j] = filteredInput[j+1];
			}
		}
	}

	//convert all letters to lowercase
	for(int i = 0; i < j; i++){
		if(filteredInput[i] >= 65 && filteredInput[i] <=90){
			filteredInput[i] = (filteredInput[i] + 32);				//add 32 to get ascii lowercase
		}
	}

	//make sure index 0 of array is a letter
	i = 0;

	while(filteredInput[0] == 95){
		for(int i = 0; i < stringLength(filteredInput); i++){
			filteredInput[i] = filteredInput[i+1];
		}
	}

	while(filteredInput[stringLength(filteredInput) -1] == 95) {
		for(int i = stringLength(filteredInput)-1; i < stringLength(filteredInput); i++){
			filteredInput[stringLength(filteredInput)-1] = filteredInput[stringLength(filteredInput)];
		}

	}

	//int len = stringLength(filteredInput);


	//printf("\n%d", len);

	camelCase(filteredInput);
	/*Print the new string*/
	if(passed == 1){
		printWord(filteredInput);
	}
	else {
		printf("Invalid input string.");
	}
	
	return 0;
}

