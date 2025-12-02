#include <stdio.h>
#include "list.h"

/*
 * This file holds the real student list.
 * student_list stores the students.
 * student_count tracks how many have been added.
 */
Student student_list[MAX_STUDENTS];
int student_count = 0;

/* Resets the list to empty */
void init_list(void)
{
    student_count = 0;
}

/* Adds one student to the list */
int add_to_list(Student student)
{
    if (student_count >= MAX_STUDENTS) {
        return -1;      // list full
    }

    student_list[student_count] = student;
    student_count++;
    return 0;           // success
}

/*
 * Removes a student with a given ID number.
 * This function was added to fix the delete feature.
 *
 * Steps:
 * 1. Find the student by ID
 * 2. If found, shift the remaining students left
 * 3. Decrease student_count
 */
int remove_from_list(int idNum)
{
    int index = -1;

    /* Look for the student with matching ID */
    for (int i = 0; i < student_count; i++) {
        if (student_list[i].idNum == idNum) {
            index = i;
            break;
        }
    }

    /* If not found, return error */
    if (index == -1) {
        return -1;
    }

    /* Shift left to fill the gap */
    for (int i = index; i < student_count - 1; i++) {
        student_list[i] = student_list[i + 1];
    }

    /* Reduce the count since one was removed */
    student_count--;

    return 0;   // success
}
