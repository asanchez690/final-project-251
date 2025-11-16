
#ifndef FRAMEWORK_H
#define FRAMEWORK_H


#define MAX_STUDENTS 100 // max number of students allowed in gradebook
#define MAX_NAMELENGTH 50 //max numbe of characters allowed in name


typedef struct //sort of acts like an object in java, defining the structure of each student
{
  int idNum;
  char name[MAX_NAMELENGTH];
  float averageScore;
}Student;


//We have to implement a system that makes use of files in C
//So we need a method to initialize our file(create and or read from an existing one)
//Additionally we need another method to save our file so it updates the changes we made our program
//So something similar to files in java we have to learn to do


//implement these methods 
void addStudent();

void deleteStudent();

void listStudents();

void sortGradebook();



#endif


