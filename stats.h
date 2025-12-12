#ifndef stats_h
#define stats_h

#include "Framework.h"

// Print statistics for the gradebook
void stats_print(const Student *students, int count);

// Compute the class average
double stats_class_average(const Student *students, int count);

// Find index of student with highest average
int stats_index_of_max_avg(const Student *students, int count);

// Find index of student with lowest average
int stats_index_of_min_avg(const Student *students, int count);

#endif
