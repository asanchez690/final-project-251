#include <stdio.h>
#include "stats.h"
#include "FrameWork.h"

/*
 * Print all statistics for the gradebook.
 * Uses helper functions to compute average, highest, and lowest.
 */
void stats_print(const Student *students, int count) {

    /* No students means nothing to show */
    if (count <= 0) {
        printf("No students in gradebook\n");
        return;
    }

    /* Get the class average and the positions of highest and lowest */
    double class_avg = stats_class_average(students, count);
    int max_index = stats_index_of_max_avg(students, count);
    int min_index = stats_index_of_min_avg(students, count);

    /* Print basic class info */
    printf("Students: %d\n", count);
    printf("Class average: %.2f\n", class_avg);

    /* Print highest scoring student if index is valid */
    if (max_index >= 0) {
        const Student *s = &students[max_index];
        printf("Highest average: %.2f (ID %d, %s)\n",
               s->averageScore, s->idNum, s->name);
    }

    /* Print lowest scoring student if index is valid */
    if (min_index >= 0) {
        const Student *s = &students[min_index];
        printf("Lowest average: %.2f (ID %d, %s)\n",
               s->averageScore, s->idNum, s->name);
    }
}

/*
 * Computes the class average by looping through all students
 * and adding their averageScore values.
 */
double stats_class_average(const Student *students, int count) {

    /* Return zero if no students exist */
    if (count <= 0) {
        return 0.0;
    }

    double total = 0.0;

    /* Add every student's average score */
    for (int i = 0; i < count; i++) {
        total += students[i].averageScore;
    }

    /* Final average */
    return total / count;
}

/*
 * Finds the index of the student with the highest averageScore.
 */
int stats_index_of_max_avg(const Student *students, int count) {

    /* No valid index if count is zero */
    if (count <= 0) {
        return -1;
    }

    int max_index = 0;

    /* Check each student and update max_index when needed */
    for (int i = 1; i < count; i++) {
        if (students[i].averageScore > students[max_index].averageScore) {
            max_index = i;
        }
    }

    return max_index;
}

/*
 * Finds the index of the student with the lowest averageScore.
 */
int stats_index_of_min_avg(const Student *students, int count) {

    /* No valid index if no students */
    if (count <= 0) {
        return -1;
    }

    int min_index = 0;

    /* Check for any lower scores */
    for (int i = 1; i < count; i++) {
        if (students[i].averageScore < students[min_index].averageScore) {
            min_index = i;
        }
    }

    return min_index;
}

