
#include <stdio.h>
#include "FrameWork.h"
#include <string.h>


void addStudent(Student arr[], int *currentIndex )
{

if(*currentIndex>MAX_STUDENTS) // this will lead to problems later down the line, especially if the user decides to delete
{//Have to find another way of finding empty spaces within array, Maybe another array that indicates available spots?
printf("Error: Maximum Number of Students have been added");
}



else
{


Student s1; //student instance created


printf("Enter ID Number: ");
scanf("%d", &s1.idNum);

printf("Enter name of Student: "); 
scanf("%s", s1.name); // setting the name of the student

printf("Enter the Students Overall Grade: ");
scanf("%f", &s1.averageScore);
//Maybe implement an if statement that validates that the index is valid
arr[*currentIndex] = (s1);  // this adds the student to the correct place in 

}
}

void listStudents(Student arr[], int count)
{
  for(int index =0; index<count; index++)
  {
    printf("%s %d %.2f\n",arr[index].name,arr[index].idNum,arr[index].averageScore);
  }
}