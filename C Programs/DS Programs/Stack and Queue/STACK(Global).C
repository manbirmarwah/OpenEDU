/* Stack using array - Program to implement ADT stack using array (stack s declared globally) */

#include  <stdio.h>
#include  <conio.h>

#define  STACKSIZE  5

struct  stack
{
  int  top ;
  int  items[STACKSIZE] ; 
};
/* assuming that stack consists of integers */

struct  stack  s ;
/* Creating Stack */

/* Structure variable s is a global variable and need not be passed to any function. Any changes made to variable s by any of the functions in the program will be permanent and will be reflected in the entire program */

void  push(int  x)
{
  if(s.top==STACKSIZE-1)
  {
    printf("Stack Overflow. Cannot push \n") ;
    getch() ;
    exit(1) ; /* terminates program */
  }
  s.items[++(s.top)]=x ;
}

int  empty()
{
  if(s.top==-1)
    return  1 ;
  else
    return  0 ;
}

int  pop()
{
  if(empty())
  {
    printf("Stack Underflow. Cannot pop \n") ;
    getch() ;
    exit(1) ;
  }
  return (s.items[(s.top)--]) ;
}

int stacktop()
{
  if(empty())
  {
    printf("Stack Underflow. \n") ;
    getch() ;
    exit(1) ;
  }
  return (s.items[s.top]) ;
}

void  show()
{
  int  i ;
  printf("Stack from topmost element is as shown:\n") ;
  for(i=s.top ; i>=0 ; i--)
    printf("%d ", s.items[i]) ;
}

void  main()
{
  int  x , ch ;

  s.top=-1 ;

  clrscr() ;

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
      push(x) ;
      show() ;
      break ;

      case 2:
      x=pop() ;
      printf("Element popped is %d \n",x) ;
      show() ;
      break ;

      case 3:
      x=stacktop() ;
      printf("Topmost Element is %d \n",x) ;
      show() ;
      break ;

      case 4:
      break ;
   }
 }
 while(ch!=4) ;

 getch() ;
}


