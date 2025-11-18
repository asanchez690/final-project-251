#include <stdio.h>

int main(void)
{
//1 Add
//2 List
//3 Sort
//4 Save and exit
//else invalid input
int input =0;


do
{
  printf("-----GradeBook-----\n");
  printf("What would you like to do?\n");
  printf("1. Add Student\n");
  printf("2. Delete Student\n");
  printf("3. List Students\n");
  printf("4. Save and Exit\n");
  scanf("%d" ,&input);

  switch(input)
  {
    case 1:
      //function to add a student
      printf("Works\n");
      break;
    case 2:
      //function to delete a student
      printf("Works\n");
      break;
      
    case 3:
      //function to list all students in gradebook
      printf("Works\n");
      break;
    case 4:
      //function to possibly return file with students
      printf("Works\n");
      break;
    default:
      printf("Error: Invalid Input!\n\n");
      break;
  }

} while (!(input==4));






  return 0;
}

