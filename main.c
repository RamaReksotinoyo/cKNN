#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include"cknn.h"


int main(void){

    struct Point_t arr[] = {
        {(int*)malloc(sizeof(int)), 2.0, 3.0, 0.0},
        {(int*)malloc(sizeof(int)), 2.0, 1.0, 0.0},
        {(int*)malloc(sizeof(int)), 5.0, 8.0, 0.0},
        {(int*)malloc(sizeof(int)), 6.0, 9.0, 0.0},
        {(int*)malloc(sizeof(int)), 7.0, 10.0, 0.0}
    };

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
    struct Point_t p = {(int*)malloc(sizeof(int)), 1.0, 2.0, 0.0};
    int result = classifier(arr, n, k, p);

    printf("The point (%g, %g) belongs to group %d\n", p.x, p.y, result);    

    return 0;
}