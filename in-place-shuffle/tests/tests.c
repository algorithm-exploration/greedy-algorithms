void printArray(const char* title, const int* array, size_t size)
{
    size_t i;
    printf("%s: [", title);
    for (i = 0; i < size; i++) {
        printf(i > 0 ? ", %d" : "%d", array[i]);
    }
    printf("]\n");
}

#define countof(a) (sizeof(a)/sizeof((a)[0]))

int main(int argc, char** argv)
{
    const int initial[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int shuffled[countof(initial)];
    memcpy(shuffled, initial, sizeof(initial));
    shuffle(shuffled, countof(shuffled));
    printArray("initial array", initial, countof(initial));
    printArray("shuffled array", shuffled, countof(shuffled));
    return 0;
}
