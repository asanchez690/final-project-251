#include <stdio.h>
#include "FrameWork.h"
#include "stats.h"

int main(void)
{
//1 Add
//2 Delete
//3 List
//4 Show statistics
//5 Save & quit
//else invalid input
int input =0;

Student arr[MAX_STUDENTS];
int currentIndex =0;


do
{
  printf("-----GradeBook-----\n");
  printf("What would you like to do?\n");
  printf("1. Add Student\n");
  printf("2. Delete Student\n");
  printf("3. List Students\n");
  printf("4. Show Statistics\n");
  printf("5. Save and Exit\n");
  scanf("%d" ,&input);

  switch(input)
  {
    case 1:
      //function to add a student
      addStudent(arr, currentIndex);
      currentIndex++;
      printf("Works\n");
      break;
    case 2:
      //function to delete a student
      printf("Works\n");
      break;
    case 3:
      //function to list all students in gradebook
      listStudents(arr,currentIndex);
      break;
    case 4:
      stats_print(arr, currentIndex);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Error: Invalid Input!\n\n");
      break;
  }

} while (!(input==5));


  return 0;
}

