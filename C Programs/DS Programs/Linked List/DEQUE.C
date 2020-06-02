/* Deque using Linked list - Program to implement ADT deque using doubly linked list */

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#define  NULL  0

/* Assume that the data portion of each node consists of an integer. */
struct  node
{
  int  data ;
  struct  node  *next , *prev ;
} ;

struct  node  *left , *right ;

/* This function initializes the deque to empty by making both left and right as NULL */
void createdeque()
{
  left=right=NULL ;
}

void  insertleft(int  x)
{
  struct  node  *pnode ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("\nMemory overflow. Unable to create.") ;
    exit(1) ;

  }
  pnode->data=x ;

  if(left==NULL)
  {
      pnode->prev=pnode->next=NULL ;
      left=right=pnode ;
  }
  else
  {
      pnode->prev=NULL ;
      pnode->next=left ;
      left->prev=pnode ;
      left=pnode ;
  }
}

void  insertright(int  x)
{
  struct  node  *pnode ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("\nMemory overflow. Unable to create.") ;
    exit(1) ;
  }

  pnode->data=x ;

  if(right==NULL)
  {
      pnode->prev=pnode->next=NULL ;
      left=right=pnode ;
  }
  else
  {
      pnode->next=NULL ;
      pnode->prev=right ;
      right->next=pnode ;
      right=pnode ;
  }
}

int removeleft()
{
  int  x ;
  struct  node  *p ;

  if(left==NULL)
  {
    printf("Deque underflow. Cannot remove") ;
    getch() ;
    exit(1) ;
  }

  x=left->data ;
  p=left ;
  left=left->next ;
  if(left==NULL)
      right=NULL ;
  else
      left->prev=NULL ;
  free(p) ;
  return x ;
}

int removeright()
{
  int  x ;
  struct  node  *p ;

  if(right==NULL)
  {
    printf("Deque underflow. Cannot remove") ;
    getch() ;
    exit(1) ;
  }

  x=right->data ;
  p=right ;
  right=right->prev ;
  if(right==NULL)
      left=NULL ;
  else
      right->next=NULL ;
  free(p) ;
  return x ;
}


void show()
{
  struct  node  *p ;

  if(left==NULL)
    printf("Deque empty. No data to display. \n") ;
  else
  {
    printf("Deque from left to right is as shown: \n") ;
    p=left ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }
    printf("\n") ;
  }
}

void destroydeque()
{
  left=right=NULL ;
}

void  main()
{
  int  x , ch ;

 createdeque() ;

 clrscr() ;

 do
 {
  printf("\n\n  Menu: \n") ;
  printf("1:Insert Left.\n") ;
  printf("2:Remove Left.\n") ;
  printf("3:Insert Right.\n") ;
  printf("4:Remove Right.\n") ;
  printf("5:exit \n") ;
  printf("Enter your choice: ") ;
  scanf("%d",&ch) ;
  switch(ch)
  {
    case 1:
    printf("Enter element to be inserted at left: ") ;
    scanf("%d",&x) ;
    insertleft(x) ;
    show() ;
    break ;

    case 2:
    x=removeleft() ;
    printf("Element removed from left is: %d \n",x) ;
    show() ;
    break ;
  
    case 3:
    printf("Enter element to be inserted at right: ") ;
    scanf("%d",&x) ;
    insertright(x) ;
    show() ;
    break ;

    case 4:
    x=removeright() ;
    printf("Element removed from right is: %d \n",x) ;
    show() ;
    break ;
  }
 }
 while(ch!=5) ;

 destroydeque() ;

 getch() ;
}



