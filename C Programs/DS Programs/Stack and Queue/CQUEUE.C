/* Circular Queue  - Program to implement circular queue using arrays and using technique of leaving one location empty   */

/* There are 2 drawbacks of this technique:
1) It is difficult to understand
2) If the QUEUESIZE = 5, then we can store a maximum of 4 elements  */

#include  <stdio.h>
#include  <conio.h>
#define  QUEUESIZE  5

struct  queue
{
  int  front , rear ;
  int  items[QUEUESIZE] ;
} ;

int  empty(struct  queue  *pq)
{
  if(pq->rear==pq->front)
    return  1 ;
  else
    return  0 ;
}

void  insert(struct  queue  *pq , int  x)
{
  if(pq->rear==QUEUESIZE-1)
	pq->rear=0 ;
  else
	(pq->rear)++ ;
	
  if(pq->rear==pq->front)
  {
    printf("Queue Overflow. Cannot insert \n") ;
    getch() ;
    exit(1) ;
  }

  pq->items[pq->rear]=x ;
}


int  removes(struct  queue  *pq)
{
  if(empty(pq))
  {
      printf("\nQueue Underflow. Cannot remove \n") ;
      getch() ;
      exit(1) ;
  }

  if(pq->front==QUEUESIZE-1)
    pq->front=0 ;
  else
    (pq->front)++ ;

  return(pq->items[pq->front]) ;
}


void  show(struct  queue  q)
{
  int  i ;
  printf("Queue from frontmost element is as shown:\n") ;

  if(q.front<q.rear)
    for(i=q.front+1 ; i<=q.rear ; i++)
	printf("%d ",q.items[i]) ;
	
  if(q.front>q.rear)
  {
    for(i=q.front+1 ; i<=QUEUESIZE-1 ; i++)
	printf("%d " , q.items[i]) ;
    for(i=0;i<=q.rear;i++)
	printf("%d " , q.items[i]) ;
  }
}

void main()
{
  int  x , ch ;

  struct  queue  q ;

  clrscr() ;

  q.rear=q.front=QUEUESIZE-1 ;

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



