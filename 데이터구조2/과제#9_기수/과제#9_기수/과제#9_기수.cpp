#include <iostream>


// 6장의 큐 소스를 여기에...
#define BUCKETS 10
#define DIGITS 4

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void init(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType q) {
	return ((q.rear + 1) % MAX_QUEUE_SIZE == q.front);
}

int is_empty(QueueType q) {
	return (q.rear == q.front);
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(*q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d|", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(*q)) {
		printf("Queue is full.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(*q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
void print_bucket(QueueType* q) {
	int f = q->front ;
	while (f != (q->rear + 1) % MAX_QUEUE_SIZE) {
		if (q->data[f] != -858993460) {
			printf("%d ", q->data[f]);
		}
		f = (f + 1) % MAX_QUEUE_SIZE;
	}
	printf("\n");
}

void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for (b = 0; b < BUCKETS; b++) init(&queues[b]);	// 큐들의 초기화

    
	for (i = 0; i < n; i++) {				// 데이터들을 자리수에 따라 큐에 입력
		enqueue(&queues[(list[i] / factor) % 10], list[i]);
	}

	

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)				// 데이터들을 자리수에 따라 큐에 입력
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		for (int i = 0; i < n; i++) {				// 데이터들을 자리수에 따라 큐에 입력
			printf("%d번째 큐: ", i);
			print_bucket(&queues[i]);
		}

		for (b = i = 0; b < BUCKETS; b++)			// 버켓에서 꺼내어 list로 합친다.
			while (!is_empty(queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;				// 그 다음 자리수로 간다.
	}

}



#define  SIZE 10

int main()
{
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100;

	radix_sort(list, SIZE); // 기수정렬 호출 
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;

}

