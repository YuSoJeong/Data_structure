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
	
	printf("���� �Ʒ� �� ����ϴ� ù��° ���:");	
	int value=*(int*)stackBottom(stack);
	printf("%d \n",value);

	printf("���� �Ʒ� �� ����ϴ� �ι�° ���:");
	int value2=*(int*)stackBottom2(stack);
	printf("%d \n",value2);

	return 0;
}

