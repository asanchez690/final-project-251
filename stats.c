#include <stdio.h>
#include "stats.h"
#include "Framework.h"

/*
 * Prints overall statistics for the gradebook.
 * Calls helper functions for average, highest, and lowest.
 */
void stats_print(const Student *students, int count)
{
    if (count <= 0) {
        printf("No students in gradebook\n");
        return;
    }

    double class_avg = stats_class_average(students, count);
    int max_index = stats_index_of_max_avg(students, count);
    int min_index = stats_index_of_min_avg(students, count);

    printf("Students: %d\n", count);
    printf("Class average: %.2f\n", class_avg);

    if (max_index >= 0) {
        const Student *s = &students[max_index];
        printf("Highest average: %.2f (ID %d, %s %s)\n",
               s->averageScore, s->idNum,
               s->firstName, s->lastName);
    }

    if (min_index >= 0) {
        const Student *s = &students[min_index];
        printf("Lowest average: %.2f (ID %d, %s %s)\n",
               s->averageScore, s->idNum,
               s->firstName, s->lastName);
    }
}

/*
 * Compute the class average grade.
 */
double stats_class_average(const Student *students, int count)
{
    if (count <= 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += students[i].averageScore;
    }

    return sum / count;
}

/*
 * Find index of student with highest average.
 * Returns -1 if the list is empty.
 */
int stats_index_of_max_avg(const Student *students, int count)
{
    if (count <= 0) {
        return -1;
    }

    int max_index = 0;

    for (int i = 1; i < count; i++) {
        if (students[i].averageScore > students[max_index].averageScore) {
            max_index = i;
        }
    }

    return max_index;
}

/*
 * Find index of student with lowest average.
 * Returns -1 if the list is empty.
 */
int stats_index_of_min_avg(const Student *students, int count)
{
    if (count <= 0) {
        return -1;
    }

    int min_index = 0;

    for (int i = 1; i < count; i++) {
        if (students[i].averageScore < students[min_index].averageScore) {
            min_index = i;
        }
    }

    return min_index;
}

