#include <stdio.h>
#include <stdlib.h>

int c, *num;

int binarysearch(int start, int end) {    
    int s = start;
    int e = end;
    int middle;

    if (e < s)
      return -1;

    middle = (e + s)/2;

    if (c == num[middle])
      return middle;
    else if(c < num[middle])
      return binarysearch(s, middle-1);
    else      
      return binarysearch(middle+1, e);

}
int main() {    
    int n_num, n_queries, i, ans;
    
    scanf("%d %d", &n_num, &n_queries);
    num = (int*)malloc(n_num * sizeof(int));
    
    for(i = 0; i<n_num; i++)
        scanf("%d", &num[i]);
    
    for(i = 0; i<n_queries; i++) {
        scanf("%d", &c);        
        ans = binarysearch(0, n_num-1);
        printf("%d\n", ans);
    }

    return 0;
}
