#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue{
	int front;
	int rear;
	Data queArr[QUE_LEN];//대기실 공간

}CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

int NextPosIdx(int pos){
	if(pos==QUE_LEN-1)
		return 0;
	else
		return pos+1;
}// 큐의 연산에서 F,R 이 이동해야할 위치를 알려주는 함수

void QueueInit(Queue* pq){

	pq->front=0;
	pq->rear=0;

}

int QIsEmpty(Queue* pq){
	if(pq->front==pq->rear)
		return 1;
	else
		return 0;
}

void Enqueue(Queue* pq, Data data){
	if(NextPosIdx(pq->rear)==pq->front){
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear=NextPosIdx(pq->rear);
	pq->queArr[pq->rear]=data;
}

Data Dequeue(Queue* pq){
	if(QIsEmpty(pq)){

		printf("Queue Memory Error!");
		exit(-1);
 }
	pq->front=NextPosIdx(pq->front);
	return pq->queArr[pq->front]; 
}



