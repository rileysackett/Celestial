#include <iostream>
#include <unistd.h>
#include <cstdlib>
#pragma once

void sleep(int i) {usleep(i * 1000);}
void clear() {system("clear");}
int randomRange(int start, int end) {
    srand(time(0));
    return (rand() % end) + start;
}