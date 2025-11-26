#include "list.h"
#include <stdio.h>

Student student_list[MAX_STUDENTS];  // REAL list of students
int student_count = 0;

void init_list(void) 
{
    student_count = 0;  // reset the list
}

int get_student_count(void) 
{
    return student_count;
}

Student* get_student_list(void) 
{
    return student_list;
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
int remove_from_list(int id) 
{
    for (int i = 0; i < student_count; i++) 
    {
        if (student_list[i].idNum == id) {
            // Shift all elements after the removed one
            for (int j = i; j < student_count - 1; j++) {
                student_list[j] = student_list[j + 1];
            }
            student_count--;
            return 0;  // Success
        }
    }
    return -1;  // not found :/
}
