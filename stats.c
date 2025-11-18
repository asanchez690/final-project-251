//
//  main.c
//  Final Project
//
//  Created by Anthony Rodriguez on 11/17/25.
//

#include <stdio.h>
#include "stats.h"
#include "model.h"

/*
 * This function prints all statistics for the gradebook
 * It expects an array of Student and the total count
 */
void stats_print(const Student *students, int count) {
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
        printf("Highest average: %.2f (ID %d, %s)\n",
               s->average, s->id, s->name);
    }

    if (min_index >= 0) {
        const Student *s = &students[min_index];
        printf("Lowest average: %.2f (ID %d, %s)\n",
               s->average, s->id, s->name);
    }
}

/*
 * Compute the class average of student averages
 */
double stats_class_average(const Student *students, int count) {
    if (count <= 0) {
        return 0.0;
    }

    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += students[i].average;
    }

    return total / count;
}

/*
 * Return index of student with highest average
 */
int stats_index_of_max_avg(const Student *students, int count) {
    if (count <= 0) {
        return -1;
    }

    int max_index = 0;

    for (int i = 1; i < count; i++) {
        if (students[i].average > students[max_index].average) {
            max_index = i;
        }
    }

    return max_index;
}

/*
 * Return index of student with lowest average
 */
int stats_index_of_min_avg(const Student *students, int count) {
    if (count <= 0) {
        return -1;
    }

    int min_index = 0;

    for (int i = 1; i < count; i++) {
        if (students[i].average < students[min_index].average) {
            min_index = i;
        }
    }

    return min_index;
}

