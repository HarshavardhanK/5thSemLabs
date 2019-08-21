
#ifndef TIME_FUNCTIONS_H
#define TIME_FUNCTIONS_H

#include <time.h>

double time_taken(void (*function) ()) {

    clock_t timer;
    timer = clock();

    function();

    timer = clock() - timer;

    return ((double) timer) / CLOCKS_PER_SEC;
}



#endif