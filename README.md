# Data_structure

자료구조( STACK , QUEUE )의 ADT 를 C 프로그래밍의 연결리스크 또는 배열로 구현하여 응용한 예제

# stackBottom.cpp

# 코드설명

      STACK ADT의 연결리스트 기반의 기본적인 구현내용이 헤더파일에 정의되어있어 include 로 포함하고 ,
      
      추가적으로 BOTTOM 값(스택의 맨 아래 값)을 반환하는 void* stackBottom(STACK* stack) 함수를 정의하여 추가하였다.
      
      stackBottom.c에서는 STACK 을 위한 META DATE 를 생성하여 임의의 int 형 포인터에 1 부터 9까지의 값을 넣어놓고, 
      
      그 값을 가르키는 노드와 다음 노드를 지정하는 링크를 포함한 스택을 META DATA 가 가르키는 top 부분에 연결시켜준다.
 
      
# 구체적인 설명

      >c file
      #include"stacksADT.h" 를 적어주어야 STACK ADT의 연결리스트 기반의 기본적인 구현함수를 사용할 수 있다.
      
      
      STACK* stack; stack=createStack(); 스택을 가르키는 META DATA 를 생성하였다.
      
      for((*i)=0;(*i)<9;(*i)++){

        pushStack(stack,i); 

       }
       여기서 i는 int 형의 포인터 이므로 *으로 값에 접근하여 META 에 스택을 연결시켜준다.
       스택에 1부터 9까지를 차곡차곡 쌓는 느낌이다.
       
       >header file
       
       stackBottom 함수는 입력받은 스택의 크기를 사용해서 크기만큼 link 를 타고 따라가 마지막 단의 데이터를 출력시켜준다.
       
       
 # 결과
  
    printf("%d",*(int*)stackBottom(stack));   스택은 LIFO 방식이지만 이 정의된 함수를 사용하면 FIFO 방식으로 출력시킬수 있다.
    
    destroyStack(stack);  메모리의 효율성을 위하여 스택을 지워주고, META 를 지워준다.

# Infix_to_Postfix.cpp

 # 코드 설명
      
    사용자가 Infix formula 를 입력하면 Postfix formula 로 변환시켜 주는 코드이다.
 
 # 구체적인 설명
      
      
 
 # 결과
      
      ex) Enter an infix formula :(1+(2*3))
          The postfix formula id : 123*+
