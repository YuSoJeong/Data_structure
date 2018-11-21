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

    int makeProc = 0;//조리대 앞 대기체크변수
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;//주문개수 체크변수
    int sec; //시간체크변수
 
    Queue que;
 
    QueueInit(&que);//큐 생성 & 초기화
    srand(time(NULL));//무작위 랜덤난수 발생을 위해서
 
    for(sec=0; sec<3600; sec++)//한시간동안시뮤레이션진행
    {
        if(sec % CUS_COME_TERM == 0)//15초에한번 주문받음 무작위로 주문받음
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
            }//햄버거 조리시간을 가지고 대기실로 고객이 이동
        }
 
        if(makeProc <= 0 && !QIsEmpty(&que))
            makeProc = Dequeue(&que);
 
        makeProc--;
    }//조리대 앞에 아무도 없고, 대기실에 고객이 존재할 경우
 


    printf("Simulation Report!! \n\n");
    printf("[Order Count]\n");
    printf("- Cheese Burger: %d \n", cheOrder);
    printf("- Bulgogi Burger: %d \n", bulOrder);
    printf("- Double Burger: %d \n\n", dubOrder);
    printf("※ Waiting room size: %d \n", QUE_LEN);

	getchar();
	return 0;

}

