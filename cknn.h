#include<stdbool.h>
#include<stdlib.h>


float euclidean(int x1, int x2, int y1, int y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

float manhattan(int x1, int x2, int y1, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

struct Point_t
{
    int* label;     
    double x, y;    
    double distance; 
};

bool comparison(struct Point_t *a, struct Point_t *b)
{
    return (a->distance < b->distance);
}

void bubble_sort(struct Point_t *arr, int n, bool (*cmp)(struct Point_t *, struct Point_t *)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(&arr[j], &arr[j + 1])) {
                struct Point_t temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int classifier(struct Point_t arr[], int n, int k, struct Point_t p)
{
    // Fill distances of all points from p
    for (int i = 0; i < n; i++){
        arr[i].distance = manhattan(arr[i].x, p.x, arr[i].y, p.y);      
    }

    bubble_sort(arr, n, comparison);
 
    int freq1 = 0;     
    int freq2 = 0;     
    for (int i = 0; i < k; i++)
    {
        if (*(arr[i].label) == 0)
            freq1++;
        else if (*(arr[i].label) == 1)
            freq2++;
    }
 
    return (freq1 > freq2 ? 0 : 1);
}