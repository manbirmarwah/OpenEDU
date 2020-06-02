/* Stack using array - Program to implement a ADT stack using array (stack s declared locally inside main) */

#include  <stdio.h>
#include  <conio.h>

#define  STACKSIZE  5

struct  stack
{
  int  top ;
  int  items[STACKSIZE] ;
} ;
/* assuming that stack consists of integers */

void  push(struct  stack  *ps , int  x)
{
  if(ps->top==STACKSIZE-1)
  {
    printf("Stack Overflow. Cannot push \n") ;
    getch() ;
    exit(1) ; /* terminates program */
  }
  ps->items[++(ps->top)]=x ;
}

int  empty(struct  stack  *ps)
{
  if(ps->top==-1)
    return  1 ;
  else
    return  0 ;
}

int  pop(struct  stack  *ps)
{
  if(empty(ps))
  {
    printf("Stack Underflow. Cannot pop \n") ;
    getch() ;
    exit(1) ;
  }
  return (ps->items[(ps->top)--]) ;
}

int  stacktop(struct  stack  s)
{
  if(empty(&s))
  {
    printf("Stack Underflow. \n") ;
    getch() ;
    exit(1) ;
  }
  return (s.items[s.top]) ;
}

void  show(struct  stack  s)
{
  int i ;
  printf("Stack from topmost element is as shown:\n") ;
  for(i=s.top ; i>=0 ; i--)
    printf("%d ", s.items[i]) ;
}

void main()
{
  int  x ,ch ;
  struct  stack  s ; /* creating Stack */

  clrscr() ;

  s.top=-1 ;

  do
  {
    printf("\n\n  Menu: \n") ;
    printf("1:push \n") ;
    printf("2:pop \n") ;
    printf("3:stacktop \n") ;
    printf("4:exit \n") ;
    printf("Enter your choice: ") ;
    scanf("%d",&ch) ;
    switch(ch)
    {
      case 1:
      printf("Enter element to be pushed: ") ;
      scanf("%d",&x) ;
      push(&s,x) ;
      show(s) ;
      break ;

      case 2:
      x=pop(&s) ;
      printf("Element popped is %d \n",x) ;
      show(s) ;
      break ;

      case 3:
      x=stacktop(s) ;
      printf("Topmost Element is %d \n",x) ;
      show(s) ;
      break ;

      case 4:
      break ;
    }
  }
  while(ch!=4) ;

  getch() ;
}



