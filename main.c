#include <stdio.h>
#include "Framework.h"
#include "stats.h"
#include "list.h"

int main(void)
{
    int input = 0;

    /*
     * Initialize the list so student_count starts at zero.
     * This lets add, list, delete, and stats work properly.
     */
    init_list();

    do {
        printf("-----GradeBook-----\n");
        printf("What would you like to do?\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. List Students\n");
        printf("4. Show Statistics\n");
        printf("5. Save and Exit\n");
        scanf("%d", &input);

        switch (input) {
            case 1:
                addStudent();
                break;
            case 2:
                /* Now calls deleteStudent which uses remove_from_list */
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
        }

    } while (input != 5);

    return 0;
}
