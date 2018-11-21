#include<stdio.h>
#include<stdlib.h>
#include"stacksADT.h"

const char closMiss[]="Close parentheses missing at line";
const char openMiss[]="Open parentheses missing at line";
const char matchMiss[]="Match parentheses error at line";

char change(char token); //open ��ȣ�� ������ ���� �ٲ��ִ� �Լ��� �����Ͽ���.

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
		}//���� ��ȣ�� stack �� �׾��ش�.





		else{
			if(token==')'||token==']'||token=='}'){	

					if((emptyStack(stack))){
						printf("%s  %d\n",openMiss,lineCount);
						return 1;	}//stack�� ����ִٸ�, �����ȣ���� ������ ����� ������
				
					else{
						char ime=*(char*)popStack(stack); //stack�� ���� �ִٸ� �ϴ� pop���ش�. ���� �����س��.

						if(change(token)!=ime){//�ֱ� stack�� ����� ��ȣ�� token�� ��ȣ�� ��Ī���� �ʴ´ٸ�,,
							printf("%c and",ime);//stack�� �ֱ� ���� ��ȣ
							printf("%c are not match \n",token);//token�� �ݱ� ��ȣ
							printf("%s  %d\n",matchMiss,lineCount);//��ȣ�� ���� �ݱ��� ������ ���� �����Ƿ� �����̴�.
							return 1;
						}
				}
			}	//������ ������ �ݱ⹮���� ��츦 �ٷ��.	
		}
	}// �����б�Ϸ�

	if(!emptyStack(stack)){
		printf("%s %d ",closMiss,lineCount);
		return 1;
	
	}//stack�� �����Ͱ� �����ִٸ� �ݱ��ȣ���������̴�.	
	destroyStack(stack); //stack�� �ݳ����ش�.	
	printf("Parsing is OK:%d Line parsed.\n",lineCount);//������ �߻����� �ʾ����Ƿ� ok
	return 0;
}

char change(char token){
	if(token==')')
		return '(';
	else if(token==']')
		return '[';
	else
		return '{';
}//token�� �ݱ��ȣ�� ��ġ�Ǵ� �����ȣ�� �������� �Լ��̴�.