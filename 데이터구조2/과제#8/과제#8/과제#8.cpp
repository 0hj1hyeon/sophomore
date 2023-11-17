#include <iostream>
#include <time.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))

void print_step(int a) {
	printf("STEP%d: ",a);
}
void printing(int list[], int n) {
	int j;
	for (j = 0; j < n; j++) { // 과정보이기
		printf("%d->", list[j]);
	}
	printf("\n");
}

void selection_sort(int list[], int n)  //선택 정렬
{
	int i, j, least, temp;
	int a = 1;
	
	clock_t start = clock();
	double result;

	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 			// 최솟값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
		print_step(a++);
		printing(list, n);
	}
	clock_t end = clock();
	result = (double)(end - start)/CLOCKS_PER_SEC;
	printf("수행시간: %lf\n", result);
}


void insertion_sort(int list[], int n) // 삽입정렬
{
	int i, j, key;
	int a = 1;

	double result;
	clock_t start = clock();
	for (i = 1; i < n; i++) {
	
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
		list[j + 1] = key;
		print_step(a++);
		printing(list, n);

	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("수행시간: %lf\n", result);
}


void bubble_sort(int list[], int n)
{
	int i, j, temp;
	int a = 1;

	double result;
	clock_t start = clock();
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) 	// 앞뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				print_step(a++);
				printing(list, n);
			}
		
	}

	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("수행시간: %lf\n", result);
}

// gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last
void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
//
void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	int a = 1;
	
	double result;
	clock_t start = clock();
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)		// 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
		print_step(a++);
		printing(list, n);
	}
	clock_t end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC;
	printf("수행시간: %lf\n", result);
}

#define MAX_SIZE 5000

int main()
{
	int n = 10;
	int list1[10];
	int list2[10];
	int list3[10];
	int list4[10];
	int n1 = MAX_SIZE;
	int list11[MAX_SIZE];
	int list22[MAX_SIZE];
	int list33[MAX_SIZE];
	int list44[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		list1[i] = rand() % 100 + 1;
		list2[i] = list1[i];
		list3[i] = list1[i];
		list4[i] = list1[i];
	}
	for (int i = 0; i < n1; i++) {
		list11[i] = rand() % 1000000 + 1;
		list22[i] = list11[i];
		list33[i] = list11[i];
		list44[i] = list11[i];
	}
	printf("선택정렬\n");
	selection_sort(list1, n);
	printf("삽입정렬\n");
	insertion_sort(list2, n);
	printf("버블정렬\n");
	bubble_sort(list3, n);
	printf("셀정렬\n");
	shell_sort(list4, n);

	/*printf("선택정렬\n");
	selection_sort(list11, n1);
	printf("삽입정렬\n");
	insertion_sort(list22, n1);
	printf("버블정렬\n");
	bubble_sort(list33, n1);
	printf("셀정렬\n");
	shell_sort(list44, n1); 8*/
}	




