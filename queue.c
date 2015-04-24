#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
	int *pBase; //动态分配内存，保存首地址
	int front; //指向头结点
	int rear; //指向尾节点
} QUEUE;

void initQueue(QUEUE * pQueue);  //初始化
bool isEmpty(QUEUE * pQueue);  //是否为空
bool isFull(QUEUE * pQueue);  //是否满
bool inQueue(QUEUE * pQueue,int value);  //入队
bool outQueue(QUEUE * pQueue,int * pValue); //出队
void displayQueue(QUEUE * pQueue);  //遍历队列


int main(void){
	int value;
	QUEUE queue;
	
	initQueue(&queue);
	inQueue(&queue, 10);
	inQueue(&queue, 20);
	inQueue(&queue, 30);
	inQueue(&queue, 40);
	inQueue(&queue, 50);
	displayQueue(&queue);
	if(outQueue(&queue,&value)){
		printf("出队一次,元素:%d\n",value);
	}	
	displayQueue(&queue);
	if(outQueue(&queue,&value)){
		printf("出队一次,元素:%d\n",value);
	}
	displayQueue(&queue);

	return 0;
}

void initQueue(QUEUE * pQueue){
	pQueue->pBase=(int *)malloc(sizeof(int)*6);
	pQueue->front=0;
	pQueue->rear=0;
}

bool isFull(QUEUE * pQueue){
	if((pQueue->rear+1)%6==pQueue->front){
		return true; 
	}else{
		return false;
	}
}

bool isEmpty(QUEUE * pQueue){
	if(pQueue->front==pQueue->rear){
		return true;
	}else{
		return false;
	}
}

bool inQueue(QUEUE * pQueue,int value){
	if(isFull(pQueue)){
		printf("队列已满!\n");
		return false;
	}else{
		pQueue->pBase[pQueue->rear]=value;
		pQueue->rear=(pQueue->rear+1)%6;
		return true;
	}
}

bool outQueue(QUEUE * pQueue, int * pValue){
	if(isEmpty(pQueue)){
		printf("队列已为空!\n");
		return false;
	}else{
		*pValue=pQueue->pBase[pQueue->front];
		pQueue->front=(pQueue->front+1)%6;
		return true;
	}
}

void displayQueue(QUEUE * pQueue){
	int i=pQueue->front;
	printf("遍历队列:\n");
	while(i != pQueue->rear){
		printf("%d  ",pQueue->pBase[i]);
		i=(i+1)%6;
	}
	printf("\n");
}

//output
//遍历队列:
//10  20  30  40  50  

//出队一次,元素:10
//遍历队列:
//20  30  40  50  

//出队一次,元素:20
//遍历队列:
//30  40  50  


