//
//  stats.h
//  Final Project
//
//  Created by Anthony Rodriguez on 11/17/25.
//

#ifndef stats_h
#define stats_h

#include "model.h"
void stats_print(const Student *students, int count);
double stats_class_average(const Student*students,int count);
int stats_index_of_max_avg(const Student*students,int count);
int stats_index_of_min_avg(const Student*students,int count);


#endif /* stats_h */
