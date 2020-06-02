/* Queue using array - Program to implement ADT queue using array (Queue q declared globally)*/

#include  <stdio.h>
#include  <conio.h>

#define  QUEUESIZE  5

struct  queue
{
  int  front , rear ;
  int  items[QUEUESIZE] ; 
} ;
/* assuming queue contains integers */

struct  queue  q ;
/* Creating Queue */

/* Structure variable q is a global variable and need not be passed to any function. Any changes made to variable q by any of the functions in the program will be permanent and will be reflected in the entire program */

void  insert(int  x)
{
  if(q.rear==QUEUESIZE-1)
  {
    printf("Queue Overflow. Cannot insert \n") ;
    getch() ;
    exit(1) ;   /* terminates program */
  }
  q.items[++(q.rear)]=x ;
}

int  removes()
{
  if(empty())
  {
      printf("Queue Underflow. Cannot remove \n") ;
      getch() ;
      exit(1) ;
  }
  return (q.items[(q.front)++]) ;
}

int  empty()
{
  if(q.rear<q.front)
    return  1 ;
  else
    return  0 ;
}

void  show()
{
  int  i ;
  printf("Queue from frontmost element is as shown:\n") ;
  for(i=q.front ; i<=q.rear ; i++)
    printf("%d " , q.items[i]) ;
}

void  main()
{
  int  x , ch ;

  clrscr() ;

  q.rear=-1 ;
  q.front=0 ;

  do
  {
    printf("\n\n Menu: \n") ;
    printf("1:Insert \n") ;
    printf("2:Remove \n") ;
    printf("3:exit \n") ;
    printf("Enter your choice: ") ;
    scanf("%d",&ch) ;
    switch(ch)
    {
      case 1:
      printf("Enter element to be inserted: ") ;
      scanf("%d",&x) ;
      insert(x) ;
      show() ;
      break ;

      case 2:
      x=removes() ;
      printf("Element removed is: %d \n",x) ;
      show() ;
      break ;

      case 3:
      break ;
    }
  }
  while(ch!=3) ;

  getch() ;
}


