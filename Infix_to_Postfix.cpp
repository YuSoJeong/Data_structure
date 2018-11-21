#include<stdio.h>
#include<string.h>
#include"stacksADT.h"

int priority(char token);
bool isOperator(char token);

int main(void){
	char postfix[80]={0};
	char temp[2]={0};
	char token;
	char* dataPtr;
	STACK* stack;

	stack=createStack();
	printf("Enter an infix formula:");

	while((token=getchar())!='\n'){ //�� ������ ���� �� ���� �� ���ھ� �޾ƿ´�.
		if(token=='('){
			dataPtr=(char*)malloc(sizeof(char));
			*dataPtr=token;
			pushStack(stack,dataPtr);
		
		}
		else if (token==')'){
			dataPtr=(char*)popStack(stack);
			while(*dataPtr!='('){
				temp[0]=*dataPtr;
				strcat(postfix,temp);
				dataPtr=(char*)popStack(stack);
			}//���� ��ȣ�� �ƴ϶� �����ڸ� postfix�� �ٿ���
		}//���� ��ȣ�� �׳� pop��
		else if(isOperator(token)){//token�� �����ڶ��
			dataPtr=(char*)stackTop(stack);
			while(!emptyStack(stack)&&priority(token)<=priority(*dataPtr)){
				dataPtr=(char*)popStack(stack);
				temp[0]=*dataPtr;
				strcat(postfix,temp);
				dataPtr=(char*)stackTop(stack);
			}//���� �������� �켱������ �� ������ pop�ؼ� postfix�ڿ� ������
		dataPtr=(char*)malloc(sizeof(char));
		*dataPtr=token;
		pushStack(stack,dataPtr);//������ �������� �켱������ �� ������ push��
		}
		else{
			temp[0]=token;
			strcat(postfix,temp);
		}//���ڸ� �ٷ� postfix�� �ٿ���

	}
	while(!emptyStack(stack)){
		dataPtr=(char*)popStack(stack);
		temp[0]=*dataPtr;
		strcat(postfix,temp);
	}//stack �� �����Ͱ� ���������� �޾ƿͼ� postfix�� �־��ش�.
	printf("The postfix fomular is :");
	puts(postfix);
	destroyStack(stack);
	return 0;

}
int priority(char token){
	if(token=='*'||token=='/')
		return 2;
	if(token=='+'||token=='-')
		return 1;
	return 0;

}//�켱������ ����� ����
bool isOperator(char token){
	if(token=='*'||token=='/'||token=='+'||token=='-')
		return true;

	return false;
}//���������� Ȯ���Ѵ�.



