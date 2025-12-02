

#include <stdio.h>
#include <string.h>
#include "Framework.h"
#include "list.h"

/*
 * Adds a new student to the gradebook.
 * Uses add_to_list from list.c to store the student.
 */
void addStudent(void)
{
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Maximum number of students reached\n");
        return;
    }

    Student s1;

    printf("Enter ID Number: ");
    scanf("%d", &s1.idNum);

    printf("Enter name of Student: ");
    scanf("%49s", s1.name);

    printf("Enter the Student's Overall Grade: ");
    scanf("%f", &s1.averageScore);

    if (add_to_list(s1) == 0) {
        printf("Student added successfully!\n");
    } else {
        printf("Error adding student!\n");
    }
}

/*
 * Lists all students.
 */
void listStudents(void)
{
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n=== STUDENT LIST (%d students) ===\n", student_count);

    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n",
               student_list[i].idNum,
               student_list[i].name,
               student_list[i].averageScore);
    }

    printf("=================================\n\n");
}

/*
 * Deletes a student by ID.
 * This function was added to complete the delete feature.
 *
 * It calls remove_from_list from list.c.
 * If the ID is found, it gets removed.
 */
void deleteStudent(void)
{
    if (student_count == 0) {
        printf("No students to delete.\n");
        return;
    }

    int id;
    printf("Enter ID of student to delete: ");
    scanf("%d", &id);

    int result = remove_from_list(id);

    if (result == 0) {
        printf("Student deleted successfully.\n");
    } else {
        printf("Student with that ID was not found.\n");
    }
}
