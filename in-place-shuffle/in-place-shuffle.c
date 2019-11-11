#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t getRandom(size_t floor, size_t ceiling)
{
    return ((rand() / (1.0 + RAND_MAX)) * (ceiling - floor + 1)) + floor;
}

void shuffle(int* array, size_t size)
{
    // shuffle the input in place
    

}
