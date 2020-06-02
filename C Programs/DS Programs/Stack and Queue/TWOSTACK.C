/* Two Stacks in one array - Program for keeping two stacks within a single linear array so that neither stack overflows until all of the memory is used and an entire stack is never shifted to a different location within an array */

#include  <stdio.h>
#include  <conio.h>
#define  SIZE  5

struct  stack
{
  int  top1 , top2 ;
  int  items[SIZE] ;
} ;

int  empty1(struct  stack  *ps)
{
  if(ps->top1==-1)
    return  1 ;
  else
    return  0 ;
}

int  empty2(struct  stack  *ps)
{
  if(ps->top2==SIZE)
    return  1 ;
  else
    return  0 ;
}

void  push1(struct  stack  *ps , int  x)
{
  if(ps->top1==ps->top2-1)
  {
    printf("Stack 1 Overflow. Cannot push \n") ;
    getch() ;
    exit(1) ;
  }
  ps->items[++(ps->top1)]=x ;
}

void  push2(struct  stack  *ps , int  x)
{
  if(ps->top2==ps->top1+1)
  {
    printf("Stack 2 Overflow. Cannot push \n") ;
    getch() ;
    exit(1) ;
  }
  ps->items[--(ps->top2)]=x ;
}

int  pop1(struct  stack  *ps)
{
  if(empty1(ps))
  {
      printf("Stack 1 Underflow. Cannot pop \n") ;
      getch() ;
      exit(1) ;
  }
  return (ps->items[(ps->top1)--]) ;
}

int  pop2(struct  stack  *ps)
{
  if(empty2(ps))
  {
      printf("Stack 2 Underflow. Cannot pop \n") ;
      getch() ;
      exit(1) ;
  }
  return (ps->items[(ps->top2)++]) ;
}

void  show1(struct  stack  s)
{
  int  i ;
  printf("Stack 1 from top to bottom is as shown:\n") ;
  for(i=s.top1 ; i>=0 ; i--)
    printf("%d " , s.items[i]) ;
}

void  show2(struct  stack  s)
{
  int  i ;
  printf("Stack 2 from top to bottom is as shown:\n") ;
  for(i=s.top2 ; i<=SIZE-1 ; i++)
    printf("%d ", s.items[i]) ;
}

void  main()
{
  int  x , i , ch ;

  struct  stack  s ;
  s.top1=-1 ;
  s.top2=SIZE ;

  clrscr() ;

  do
  {
      printf("\n\nMenu: \n") ;
      printf("1:push1 \n") ;
      printf("2:pop1 \n") ;
      printf("3:push2 \n") ;
      printf("4:pop2 \n") ;
      printf("5:exit \n") ;
      printf("Enter your choice: ") ;
      scanf("%d",&ch) ;
      switch(ch)
      {
	    case 1:
		printf("Enter element to be pushed on stack 1: ") ;
		scanf("%d",&x) ;
		push1(&s,x) ;
		show1(s) ;
		break ;
	
	    case 2:
		x=pop1(&s) ;
		printf("Element popped from stack 1 is: %d \n",x) ;
		show1(s) ;
		break ;
	
	    case 3:
		printf("Enter element to be pushed on stack 2: ") ;
		scanf("%d",&x) ;
		push2(&s,x) ;
		show2(s) ;
		break ;
	
	    case 4:
		x=pop2(&s) ;
		printf("Element popped from stack 2 is: %d \n",x) ;
		show2(s) ;
		break ;

	    case 5:	
	    break ;
      }
    }
    while(ch!=5) ;

    getch();
}


