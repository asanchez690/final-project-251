
#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#define MAX_STUDENTS   100
#define MAX_NAMELENGTH 50

// Definition of a Student in the gradebook
typedef struct {
    int  idNum;
    char firstName[MAX_NAMELENGTH];
    char lastName[MAX_NAMELENGTH];
    float averageScore;
} Student;

// Gradebook function prototypes
void addStudent(void);
void listStudents(void);
void deleteStudent(void);
void sortGradebook(void);

#endif

