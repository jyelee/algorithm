#include <stdio.h>
#include <stdlib.h>

//1 2 3 4 5 6 7 8 9
//description: find consecutive subarray which sum is dest
//when sum greater than dest then remove small, ++small; when sum smaller than dest then ++big and add big
void subarray_sum(int dest_val) {
    int small = 1;
    int big = 2;
    int sum = small + big;
    int iter;
    while(small < (dest_val + 1) / 2) { //important
        if(sum < dest_val) {
            sum += ++big;
        } else if(sum > dest_val) {
            sum -= small;
            ++small;
        } else {
           for(iter = small; iter <= big; ++iter) {
               printf("%d ", iter);
           }
           printf("\n");
           sum -= small;
            ++small;
        }
    }
}


int main(int argc, char *argv[]) {
    int dest;
    while(scanf("%d", &dest) != EOF) {
        subarray_sum(dest);
    }
    return 0;
}
