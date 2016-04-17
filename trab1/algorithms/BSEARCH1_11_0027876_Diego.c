// Diego Marques de Azevedo 11/0027876

#include <stdio.h>
#include <stdlib.h>

int *num;

int binarySearch(int size, int key) {
    int flag = 0;
    int start = 0;
    int end = size-1;
    int middle, ans;

    while(start <= end) {
        middle = start + (end - start)/2;

        if(key < num[middle])
            end = middle-1;
        else if(key > num[middle])
            start = middle+1;
        else {
            ans = middle;
            flag = 1;
            end = middle-1;
        }
    }
    if(flag == 1) {
        return ans;
    } else {
        return -1;
    }

}
int main() {
    int n_num, n_queries, key, i, flag, ans;

    scanf("%d %d", &n_num, &n_queries);
    num = (int*)malloc(n_num * sizeof(int));

    for(i = 0; i<n_num; i++)
        scanf("%d", &num[i]);

    for(i = 0; i<n_queries; i++) {
        scanf("%d", &key);
        ans = binarySearch(n_num, key);
        printf("%d\n", ans);
    }

    return 0;
}
