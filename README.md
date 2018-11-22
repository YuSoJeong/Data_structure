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
      
      (token=getchar())!='\n' 사용자로 부터 infix formula 를 받아오고 엔터 입력 전까지 한 문자씩 읽어온다
      
      token이 열기 괄호면 스택에 넣고, token이 닫기 괄호면 스택에서 최근 top 이 열기 괄호일 때 까지 pop하고 문자 배열에 추가 해준다.
      
      token이 연산자 라면 우선순위를 따져서 문자 배열에 추가해주고, 숫자라면 바로 문자 배열에 출력 해준다.
      
      즉 스택에는 열기 괄호와 연산자만 쌓였다가 postfix 로 바꿔줄 때 token 에 따라 순서를 맞춰주는 것이다.
      
      입력을 문자 당 받아온후 스택에 아직 데이터가 남아있다면 스택의 위에서 부터 차례대로 출력해준다.
      
 
 # 결과
      
      ex) Enter an infix formula :(1+(2*3))
          The postfix formula id : 123*+

# Parentheses_Matching.cpp

  # 코드 설명
  
      C 언어에서 사용되는 3 가지 괄호인 (),[],{} 모두를 고려한 매칭 문제를 스택 ADT C 언어 구현코드를 이용하여 해결한 코드이다.
     
  
  # 구체적인 설명
  
      file에 다양한 괄호 배치 경우를 저장해 놓고 파일을 불러와서 소스코드를 돌려보았다.
      
      stack을 하나 생성해서 세가지의 매칭 괄호에 대해 작동하게 구현하였다.  파일에서 token 단위로 읽어왔다.
      
      읽어온 글자가 열기 괄호일 때 일단 괄호에 상관없이 stack에 쌓아준다.
      
      열기 괄호 외의 문자를 다룰 때 괄호 가 아닌 문자들에 대해서는 어느 루프도 실행하지 않는다.
      
      닫기 괄호를 읽어 왔을 경우, stack이 비어 있다면 그것은 열기 괄호 수가 부족한 것이므로
      
      Open parentheses 오류와 오류의 line번호를 띄워주고 실행을 종료한다. 
     
      Stack에 데이터 값이 아직 남아 있을 때 stack의 가장 최근의 데이터와 현재 읽어온 닫기 괄호가 매칭된다면, 
      
      오류없이 진행되지만 만약 매칭되지 않는다면 괄호 매칭 순서의 문제가 발생한 것이므로 오류를 띄워주고 실행을 종료한다.
      
      파일을 읽어올 동안 오류가 발생하지 않았을 때 stack 안의 데이터가 남아있는지 확인하고 남아있으면 
      
      닫기 괄호의 수가 부족한 것이므로 Close parentheses 오류를 발생시킨다. 

      
  
  # 결과
     
       >  Noerrors.txt 
       {{
       [[
       ((
       ))
       ]]
       }}
       
       Parsing id OK : 6 Line parsed
       
      >  Closeerrors.txt 
      {{{
      [[[[
      ]]]]
      }}
      
       Close parentheses missing at line 4
       
       
       >  Openerrors.txt 
       [[{}
       ]]
       ]
      
      Open parentheses missing at line 3
       
      
       Matcherrors.txt 
       {{[[
       ]]
       ))
       
       Match parentheses error at line 3
       
    
  # HamburgerSim.cpp

  # 코드 설명
      
     배열 기반 원형 큐를 헤더파일로 미리 저장해 놓았다.
     
     queue simulation를 활용하여 주문한 음식이 포장되어 나오기를 기다리는 고객을 위한 대기실을 구현하였다.
     
     [운영 조건]
     
      운영 시간은 1시간

      고객의 첫 주문 이후 15초당 다음 1명씩 주문

      고객은 총 3가지 햄버거 중 무작위로 1개만 주문가능

      햄버거 조리 시간(치즈버거 12초, 불고기버거 15초, 더블버거 24초)

      한 번에 하나의 햄버거만 조리가능

      조리가 끝나기 전까지 다음 주문을 받지 않음

      주문 처리가 된 고객은 대기실에서 나옴


  # 구체적인 설명
  
      #include"QUEUE.h"  원형 스택 헤더를 include 해줘야 한다.

      #define CUS_COME_TERM 15     15 마다 주문 받으므로 미리 정의
      
      #define CHE_BUR 0 #define BUL_BUR 1 #define DUB_BUR 2 버거 종류를 정수로 저장

      #define CHE_TERM 12 #define BUL_TERM 15 #define DUB_TERM 24 조리 시간을 정수로 저장
      
      무작위 램덤 버거 주문 발생을 위해서 srand(), rand()%3 을 이용
      
      햄버거 조리시간을 가지고 고객이 대기실로 이동, 버거 종류마다 주문 개수를 증가
      
      

  # 결과
      
      Simulation Report!!
      
      [Order Count]
      - Cheese Burger : 74
      - Bulgogi Burger: 88
      - Doubel Burger: 78
      
      ※ Waiting room size : 100
  
      랜덤 난수를 이용했으므로 매번 주문 개수가 다를 것 이다.
  
      1시간 동안 버거를 요리하는 상황에서 대기실 크기에 따라 
      얼마나 안정적으로 수용할 수 있는지 확률적으로 알수 있다.
     
      
