#include "list.h"
#include <stdio.h>

Student student_list[MAX_STUDENTS];  // REAL list of students
int student_count = 0;

void init_list(void) 
{
    student_count = 0;  // reset the list
}

int add_to_list(Student student) 
{
    if (student_count >= MAX_STUDENTS) 
    {
        return -1;  // List full
    }
    student_list[student_count] = student;
    student_count++;
    return 0;  // Success
}

