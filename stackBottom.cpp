#include<stdio.h>
#include"stacksADT.h"

int main(void){

	STACK* stack;
	stack=createStack();
	int i=10;
	int j=11;
	int k=13;

		pushStack(stack,&i);
		pushStack(stack,&k);
		pushStack(stack,&j);
	
	printf("스택 아랫 값 출력하는 첫번째 방법:");	
	int value=*(int*)stackBottom(stack);
	printf("%d \n",value);

	printf("스택 아랫 값 출력하는 두번째 방법:");
	int value2=*(int*)stackBottom2(stack);
	printf("%d \n",value2);

	return 0;
}

