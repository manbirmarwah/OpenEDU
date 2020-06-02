/* Circular Queue using arrays - Program to implement circular queue using array and counter method */

#include  <stdio.h>
#include  <conio.h>
#define  QUEUESIZE  5

struct  queue
{
  int  front , rear ;
  int  items[QUEUESIZE] ;
  int  count ;
} ;

void  insert(struct  queue  *pq , int  x)
{
  if(pq->count==QUEUESIZE)
  {
    printf("Queue Overflow. Cannot insert \n") ;
    getch() ;
    exit(1) ;
  }

  ++(pq->count) ;

  if(pq->rear==QUEUESIZE-1)
    pq->rear=0 ;
  else
    ++(pq->rear) ;

  pq->items[pq->rear]=x ;
}

int  empty(struct  queue  *pq)
{
  if(pq->count==0)
    return  1 ;
  else
    return  0 ;
}

int  removes(struct  queue  *pq)
{
  int  t ;

  if(empty(pq))
  {
    printf("Queue Underflow. Cannot remove \n") ;
    getch() ;
    exit(1) ;
  }

  t=pq->items[pq->front] ;

  --(pq->count) ;

  if(pq->front==QUEUESIZE-1)
    pq->front=0 ;
  else
    ++(pq->front) ;

  return  t ;
}

void  show(struct  queue  q)
{
  int  i ;
  printf("Queue from frontmost element is as shown: \n") ;

  if(q.count!=0)
  {
    if(q.front<=q.rear)
      for(i=q.front ; i<=q.rear ; i++)
	   printf("%d " , q.items[i]) ;

    if(q.front>q.rear)
    {
      for(i=q.front ; i<=QUEUESIZE-1 ; i++)
	   printf("%d ",q.items[i]) ;
      for(i=0; i<=q.rear; i++)
	   printf("%d ",q.items[i]) ;
    }
  }
}

void  main()
{
  int  x , ch ;
  struct  queue  q ;

  clrscr() ;

  q.rear=-1 ;
  q.front=0 ;
  q.count=0 ;

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
      insert(&q,x) ;
      show(q) ;
      break ;

      case 2:
      x=removes(&q) ;
      printf("Element removed is: %d \n",x) ;
      show(q) ;
      break ;

      case 3:
      break ;
    }
  }
  while(ch!=3) ;

  getch() ;
}


