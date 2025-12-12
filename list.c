#include <stdio.h>
#include "list.h"

/*
 * This file holds the real student list.
 * student_list stores the students.
 * student_count tracks how many have been added.
 */
Student student_list[MAX_STUDENTS];
int student_count = 0;

/*
 * Reset the list to empty.
 */
void init_list(void)
{
    student_count = 0;
}

/*
 * Add a new student to the list.
 * Returns 0 on success, -1 on failure (list full).
 */
int add_to_list(Student student)
{
    if (student_count >= MAX_STUDENTS) {
        return -1;
    }

    student_list[student_count] = student;
    student_count++;

    return 0;
}

/*
 * Remove a student with the given ID number.
 * Returns 0 on success, -1 if the ID was not found.
 */
int remove_from_list(int idNum)
{
    int index = -1;

    // Find the index of the student with the matching ID
    for (int i = 0; i < student_count; i++) {
        if (student_list[i].idNum == idNum) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return -1;
    }

    // Shift left to fill the gap
    for (int i = index; i < student_count - 1; i++) {
        student_list[i] = student_list[i + 1];
    }

    // One less student now
    student_count--;

    return 0;
}
