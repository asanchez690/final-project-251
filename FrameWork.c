
#include <stdio.h>
#include "FrameWork.h"
#include "list.h"
#include <string.h>


void addStudent(void)
{

  if(student_count > MAX_STUDENTS)  // this will lead to problems later down the line, especially if the user decides to delete
  {                                 //Have to find another way of finding empty spaces within array, Maybe another array that indicates available spots?
    printf("Error: Maximum Number of Students have been added");
  }
  else
  {

    Student s1; //student instance created

    printf("Enter ID Number: ");
    scanf("%d", &s1.idNum);

    printf("Enter name of Student: "); 
    scanf("%49s", s1.name); // setting the name of the student

    printf("Enter the Students Overall Grade: ");
    scanf("%f", &s1.averageScore);
    
    //Now utilizes list functions to add students
    if(add_to_list(s1) == 0) 
    {
        printf("Student added successfully!\n");
    } else {
        printf("Error adding student!\n");
    }
  
  }
}

void listStudents(void)
{
  if(student_count == 0) 
  {
    printf("No students to display.\n");
    return;
  }
    
  printf("\n=== STUDENT LIST (%d students) ===\n", student_count);
  for(int index = 0; index < student_count; index++)
  {
    printf("ID: %d, Name: %s, Grade: %.2f\n", 
                       student_list[index].idNum, 
                       student_list[index].name, 
                       student_list[index].averageScore);
  }
  printf("===================\n\n");
  
}
