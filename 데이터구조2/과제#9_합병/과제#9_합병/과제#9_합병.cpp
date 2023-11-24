#include <iostream>
#include <time.h>
#define MAX_SIZE 100000
int sorted[MAX_SIZE]; // 추가 공간이 필요

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	for (j = 0; j < 10; j++) { // 과정보이기
		printf("%d->", list[j]);
	}
	printf("\n");
}
void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;              // 리스트의 균등분할
		merge_sort(list, left, mid);     // 부분리스트 정렬
		merge_sort(list, mid + 1, right);//부분리스트 정렬
		merge(list, left, mid, right);    // 합병
	}
	
}


int main()
{
	int n = 10;
	int list[10];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100 + 1;
	}
	clock_t start = clock();		
	double result;
	merge_sort(list, 0, n-1);
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("수행시간: %lf\n", result);
}
