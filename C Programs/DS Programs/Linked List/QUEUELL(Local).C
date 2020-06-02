/* Queue using Linked List - Program to create a queue ADT using linked list. ADT should support the following operations
1)  Createqueue
2)  Insert into the queue
3)  Delete from the queue
4)  destroyqueue
*/

/* queue q declared locally */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

struct  node
{
  int  data ;
  struct  node  *next ;
} ;

struct  queue
{
 struct  node  *front , *rear ;
} ;

/* This function initializes the queue to empty by making both front and rear as NULL */
void  createqueue(struct  queue  *pq)
{
  pq->front=pq->rear=NULL ;
}

int  empty(struct  queue  *pq)
{
  if(pq->front==NULL)
    return  1 ;
  else
    return  0 ;
}

void  insert(struct  queue  *pq , int  x)
{
  struct  node  *pnode ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to insert.\n") ;
    exit(1) ;
  }

  pnode->data=x ;
  pnode->next=NULL ;   /* New node is always last node */
  if(empty(pq))
      pq->front=pq->rear=pnode ;
  else
  {
      pq->rear->next=pnode ;
      pq->rear=pnode ;
  }
}

int  removes(struct  queue  *pq)
{
  int  x ;
  struct  node  *p ;

  if(empty(pq))
  {
    printf("Queue Underflow. Unable to remove.\n") ;
    getch() ;
    exit(1) ;
  }

  p=pq->front ;
  x=pq->front->data ;
  pq->front=pq->front->next ;
  if(pq->front==NULL)       /* Queue contained only one node */
       pq->rear=NULL ;
  free(p) ;
  return x ;
}

void  show(struct  queue  q)
{
  struct  node  *p ;

  if(empty(&q))
    printf("Queue empty. No data to display \n") ;
  else
  {
    printf("Queue from front to rear is as shown: \n") ;
    p=q.front ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }

    printf("\n") ;
  }
}

void  destroyqueue(struct  queue  *pq)
{
  pq->front=pq->rear=NULL ;
}

void  main()
{
  int  x , ch ;

  struct  queue  q ;
  createqueue(&q) ;

  clrscr() ;

  do
  {
    printf("\n\n  Menu: \n") ;
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
      printf("Element removed is: %d\n",x) ;
      show(q) ;
      break ;

      case 3:
      break ;
    }
  }
  while(ch!=3) ;

  destroyqueue(&q) ;

  getch() ;
}








