
#ifndef LIST_H
#define LIST_H

#include "Framework.h"

/*
 * These variables store the actual student list.
 * student_list is the array.
 * student_count tracks how many students are in the list.
 */
extern Student student_list[MAX_STUDENTS];
extern int student_count;

/*
 * Functions for managing the list.
 * init_list resets everything.
 * add_to_list adds a new student.
 * remove_from_list removes a student by ID.
 */
void init_list(void);
int add_to_list(Student student);
int remove_from_list(int idNum);

#endif
