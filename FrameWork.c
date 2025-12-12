
#include <stdio.h>
#include <string.h>
#include "Framework.h"
#include "list.h"

/*
 * Internal helper to sort students by last name, then first name.
 */
static void sortStudentsByName(void)
{
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {

            Student *a = &student_list[j];
            Student *b = &student_list[j + 1];

            int cmp = strcmp(a->lastName, b->lastName);
            if (cmp > 0 ||
               (cmp == 0 && strcmp(a->firstName, b->firstName) > 0)) {
                Student tmp = *a;
                *a = *b;
                *b = tmp;
            }
        }
    }
}

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

    printf("Enter first name of Student: ");
    scanf("%49s", s1.firstName);

    printf("Enter last name of Student: ");
    scanf("%49s", s1.lastName);

    printf("Enter the Student's Overall Grade: ");
    scanf("%f", &s1.averageScore);

    int rc = add_to_list(s1);

    if (rc == 0) {
        printf("\nStudent added successfully!\n");
    } else {
        printf("\nError adding student!\n");
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

    // keep the list organized
    sortStudentsByName();

    printf("\n=== STUDENT LIST (%d students) ===\n\n", student_count);

    // header row
    printf("%-6s %-15s %-15s %-7s\n",
           "ID", "Last", "First", "Grade");
    printf("===========================================\n");

    // each student
    for (int i = 0; i < student_count; i++) {
        printf("%-6d %-15s %-15s %-7.2f\n",
               student_list[i].idNum,
               student_list[i].lastName,
               student_list[i].firstName,
               student_list[i].averageScore);
    }

    printf("===========================================\n\n");
}

/*
 * Deletes a student by ID.
 * Uses remove_from_list from list.c.
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

void sortGradebook(void)
{
    sortStudentsByName();
}
