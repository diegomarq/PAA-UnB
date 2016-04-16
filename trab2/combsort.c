#include <stdio.h>
#include <string.h>

#define SIZE_S 100
#define SIZE_C 2

char data[SIZE_C][SIZE_S];
int size = 0;

void combsort(int size) {
    char swap[SIZE_S];
    float shrink_factor = 1.247330950103979;
    int gap = size, swapped = 1, i;

    while (gap > 1 || swapped) {
        if (gap > 1)
            gap = gap / shrink_factor;

        swapped = 0;
        i = 0;

        while (gap+i < size) {
            if (strcmp(data[i], data[i+gap]) > 0) {
                strcpy(swap, data[i]);
                strcpy(data[i], data[i+gap]);
                strcpy(data[i+gap], swap);
                swapped = 1;
            }
            ++i;
        }
    }
}

int main(void) {  
    int i;
    for(i =0; scanf("%[^\n]%*c", data[i]) != EOF; i++);  
    size = i;

    combsort(size);

    for(i = 0; i < size; i++) {
        printf("%s", data[i]);
        printf("\n");
    }
    return 0;

  
}
