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

	while((token=getchar())!='\n'){ //한 문장이 끝날 때 까지 한 문자씩 받아온다.
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
			}//열기 괄호가 아니라 연산자면 postfix에 붙여짐
		}//열기 괄호면 그냥 pop됨
		else if(isOperator(token)){//token이 연산자라면
			dataPtr=(char*)stackTop(stack);
			while(!emptyStack(stack)&&priority(token)<=priority(*dataPtr)){
				dataPtr=(char*)popStack(stack);
				temp[0]=*dataPtr;
				strcat(postfix,temp);
				dataPtr=(char*)stackTop(stack);
			}//기존 연산자의 우선순위가 더 높으면 pop해서 postfix뒤에 덧붙임
		dataPtr=(char*)malloc(sizeof(char));
		*dataPtr=token;
		pushStack(stack,dataPtr);//들어오는 연산자의 우선순위가 더 높으면 push함
		}
		else{
			temp[0]=token;
			strcat(postfix,temp);
		}//숫자면 바로 postfix에 붙여짐

	}
	while(!emptyStack(stack)){
		dataPtr=(char*)popStack(stack);
		temp[0]=*dataPtr;
		strcat(postfix,temp);
	}//stack 에 데이터가 남아있으면 받아와서 postfix에 넣어준다.
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

}//우선순위는 교재와 같다
bool isOperator(char token){
	if(token=='*'||token=='/'||token=='+'||token=='-')
		return true;

	return false;
}//연산자인지 확인한다.



