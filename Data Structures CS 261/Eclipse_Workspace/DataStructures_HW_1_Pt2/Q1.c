/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

int randomize(int max){
	return (rand() % max);
}

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* list = (struct student*) malloc(10*sizeof(struct student));
	/*Return the pointer*/
	return list;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/

	//array a, values 1-10
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	//randomize that array using Fisher-Yates shuffle algorithm
	for(int i = 9; i > 1; i--){
		int j = randomize(i);

		//swap a[j] and a[i]
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	//assign each student in list an ID and score
	for(int i = 0; i < 10; i++){				//starting at 0th index and going to index 9 of list array
		students[i].id = a[i];					//set the id of a student to a entry in the number array a
		students[i].score = randomize(100);	//set the score of each student to a random integer between 0 and 100
	}



}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	printf("ID SCORE\n");
	for(int i = 0; i < 10; i++){
		printf("%d %d\n" , students[i].id, students[i].score);
		//printf("%d\n", students[i].score);
	}
}

void summary(struct student* students){
     /*
      * Compute and print the minimum, maximum and average scores of the ten students
	  */
	int min, max, avg = 0;

	min = students[0].score;
	max = students[0].score;

	for(int i = 0; i < 10; i ++){
		if(students[i].score < min){
			min = students[i].score;
		}
		if(students[i].score > max){
			max = students[i].score;
		}
		avg = avg + students[i].score;
	}
	avg = avg / 10;

	printf("Summary of scores: \n");
	printf("Minimum %d\n", min);
	printf("Maximum %d\n", max);
	printf("Average %d\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	//check that students is not NULL
	if(stud != NULL){
		free(stud);
	}

}

int main(){
	//seed for random generator
	srand(time(NULL));

    struct student* stud = NULL;
    
    /*Call allocate*/
    stud = allocate();
    
    /*Call generate*/
    generate(stud);
    
    /*Call output*/
    output(stud);

    /*Call summary*/
    summary(stud);

    /*Call deallocate*/
    deallocate(stud);

    return 0;
}

