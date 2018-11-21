#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"QUEUE.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24


int main(void){

    int makeProc = 0;//������ �� ���üũ����
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;//�ֹ����� üũ����
    int sec; //�ð�üũ����
 
    Queue que;
 
    QueueInit(&que);//ť ���� & �ʱ�ȭ
    srand(time(NULL));//������ �������� �߻��� ���ؼ�
 
    for(sec=0; sec<3600; sec++)//�ѽð����Ƚù·��̼�����
    {
        if(sec % CUS_COME_TERM == 0)//15�ʿ��ѹ� �ֹ����� �������� �ֹ�����
        {
            switch(rand() % 3)
            {
                case CHE_BUR:
                    Enqueue(&que, CHE_TERM);
                    cheOrder += 1;
                    break;
 
                case BUL_BUR:
                    Enqueue(&que, BUL_TERM);
                    bulOrder += 1;
                    break;
 
                case DUB_BUR:
                    Enqueue(&que, DUB_TERM);
                    dubOrder += 1;
                    break;
            }//�ܹ��� �����ð��� ������ ���Ƿ� ���� �̵�
        }
 
        if(makeProc <= 0 && !QIsEmpty(&que))
            makeProc = Dequeue(&que);
 
        makeProc--;
    }//������ �տ� �ƹ��� ����, ���ǿ� ���� ������ ���
 


    printf("Simulation Report!! \n\n");
    printf("[Order Count]\n");
    printf("- Cheese Burger: %d \n", cheOrder);
    printf("- Bulgogi Burger: %d \n", bulOrder);
    printf("- Double Burger: %d \n\n", dubOrder);
    printf("�� Waiting room size: %d \n", QUE_LEN);

	getchar();
	return 0;

}

