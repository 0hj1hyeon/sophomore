#include <iostream>
#include <time.h>   
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do
            low++;
        while (low <= right && list[low] < pivot);
        do
            high--;
        while (high >= left && list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], temp);
        for (int i = 0; i < 10; i++)
            printf("%d->", list[i]);
        printf("\n");
        for (int i = 0; i < 10; i++) {
            if (list[i] == list[low])
                printf("%d번째는 low ",i+1);
            if (list[i] == list[high])
                printf("%d번째는 high ",i+1);
        }
        printf("\n");
    } while (low < high);

    SWAP(list[left], list[high], temp);
    return high;
}


void quick_sort(int list[], int left, int right)
{
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}


#define MAX_SIZE 10

int main(void)
{
    int i;
    int n = MAX_SIZE;
    int list[10];

    srand(time(NULL));
    for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
        list[i] = rand() % 100;
    clock_t start = clock();
    double result;
    quick_sort(list, 0, n - 1); // 퀵정렬 호출 
    for (i = 0; i < 10; i++)
        printf("%d ", list[i]);
    printf("\n");
    clock_t end = clock();
    result = (double)(end - start) / CLOCKS_PER_SEC;
    printf("수행시간: %lf\n", result);
    return 0;
}


