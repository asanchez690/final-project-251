#include <stdio.h>
#include "Framework.h"
#include "stats.h"
#include "list.h"

int main(void)
{
    int input = 0;

    // Make sure the list starts empty
    init_list();

    do {
        printf("-----GradeBook-----\n");
        printf("What would you like to do?\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. List Students\n");
        printf("4. Show Statistics\n");
        printf("5. Save and Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &input) != 1) {
            // bad input, clear stdin
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* discard */
            }
            printf("Error: Invalid Input!\n\n");
            input = 0;
            continue;
        }

        switch (input) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                listStudents();
                break;
            case 4:
                stats_print(student_list, student_count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid Input!\n\n");
                break;
        }

    } while (input != 5);

    return 0;
}

