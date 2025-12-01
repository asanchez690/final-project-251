#ifndef LIST_H
#define LIST_H
#include "FrameWork.h"

// The list where the students belong to
extern Student student_list[MAX_STUDENTS];
extern int student_count;

//functions we'll be using
void init_list(void);
int get_student_list(void);

int add_to_list(Student student);
int remove_from_list(int id);

#endif
