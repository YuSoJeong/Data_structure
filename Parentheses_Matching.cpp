#include<stdio.h>
#include<stdlib.h>
#include"stacksADT.h"

const char closMiss[]="Close parentheses missing at line";
const char openMiss[]="Open parentheses missing at line";
const char matchMiss[]="Match parentheses error at line";

char change(char token); //open 괄호를 종류에 따라 바꿔주는 함수를 정의하였다.

int main(void){

	STACK* stack;
	char token;
	char* dataPtr;
	char fileID[25];
	FILE* fpIn;
	int lineCount=1;
	
	stack=createStack();
	printf("Enter file ID for file to be parsed:");
	scanf("%s",fileID);

	fpIn=fopen(fileID,"r");

	if(!fpIn)
		printf("Error opening %s\n",fileID),exit(100);

	while((token=fgetc(fpIn))!=EOF){

		if(token=='\n')
			lineCount++;

		if(token=='('||token=='['||token=='{'){
			dataPtr=(char*)malloc(sizeof(char));
			*dataPtr=token;
			pushStack(stack,dataPtr);
		}//열기 괄호면 stack 에 쌓아준다.





		else{
			if(token==')'||token==']'||token=='}'){	

					if((emptyStack(stack))){
						printf("%s  %d\n",openMiss,lineCount);
						return 1;	}//stack이 비어있다면, 열기괄호수가 부족한 경우의 오류임
				
					else{
						char ime=*(char*)popStack(stack); //stack에 값이 있다면 일단 pop해준다. 값을 저장해논다.

						if(change(token)!=ime){//최근 stack에 저장된 괄호와 token의 괄호가 매칭되지 않는다면,,
							printf("%c and",ime);//stack의 최근 열기 괄호
							printf("%c are not match \n",token);//token의 닫기 괄호
							printf("%s  %d\n",matchMiss,lineCount);//괄호의 열고 닫기의 순서가 맞지 않으므로 오류이다.
							return 1;
						}
				}
			}	//나머지 문자중 닫기문자일 경우를 다룬다.	
		}
	}// 파일읽기완료

	if(!emptyStack(stack)){
		printf("%s %d ",closMiss,lineCount);
		return 1;
	
	}//stack의 데이터가 남아있다면 닫기괄호부족오류이다.	
	destroyStack(stack); //stack을 반납해준다.	
	printf("Parsing is OK:%d Line parsed.\n",lineCount);//오류가 발생하지 않았으므로 ok
	return 0;
}

char change(char token){
	if(token==')')
		return '(';
	else if(token==']')
		return '[';
	else
		return '{';
}//token의 닫기괄호와 매치되는 열기괄호를 내보내는 함수이다.