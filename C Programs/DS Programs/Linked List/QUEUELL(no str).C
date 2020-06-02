/* Queue using Linked List - Program to create a queue ADT using linked list. ADT should support the following operations
1)  Createqueue
2)  Insert into the queue
3)  Delete from the queue
4)  destroyqueue */

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>	
#define  NULL  0
struct  node
{
  int  data ;
  struct  node  *next ;
} ;

struct  node  *front , *rear ;

/* This function initializes the queue to be empty by making both front and rear as NULL */
void createqueue()
{
  front=rear=NULL ;
}

int  empty()
{
  if(front==NULL)
    return  1 ;
  else
    return  0 ;
}

void  insert(int  x)
{
  struct  node  *pnode ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to insert.\n") ;
    exit(1) ;
  }

  pnode->data=x ;  
  pnode->next=NULL;   /* New node is always last node */

  if(empty())
      front=rear=pnode  ;
  else
  {
      rear->next=pnode ;
      rear=pnode ;
  }
}

int  removes()
{
  int  x ;
  struct  node  *p ;

  if(empty())
  {
    printf("Queue Underflow. Unable to remove.\n") ;
    getch() ;
    exit(1) ;
  }

  p=front ;
  x=front->data ;
  front=front->next ;
  if(front==NULL)   /* Queue contained only one node */
       rear=NULL ;
  free(p) ;
  return  x ;
}

void  show()
{
  struct  node  *p ;

  if(empty())
    printf("Queue empty. No data to display \n") ;
  else
  {
    printf("Queue from front to rear is as shown: \n") ;

    p=front ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }

    printf("\n") ;
  }
}

void  destroyqueue()
{
 front=rear=NULL ;
}

void  main()
{
  int  x , ch ;

  createqueue() ;

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
     insert(x) ;
     show() ;
     break ;

     case 2:
     x=removes() ;
     printf("Element removed is: %d\n",x) ;
     show() ;
     break ;

     case 3:
     break ;
   }
 }
 while(ch!=3) ;

 destroyqueue() ;

 getch() ;
}








