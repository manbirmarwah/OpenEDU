/* Stack using Linked List - Program to create a stack ADT using linked list. ADT should  support the following operations
1)  Createstack
2)  pushstack
3)  popstack
4)  destroystack
*/

/* stack s declared locally */
#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>	
#define  NULL  0

struct  node
{
  int  data ;
  struct  node  *next ;
};

struct  stack
{
 struct  node  *top ;
} ;

/* This fn. initializes the stack to be empty by making top as NULL */
void  createstack(struct  stack  *ps)
{
  ps->top=NULL ;
}

void  pushstack(struct  stack  *ps , int  x)
{
  struct  node  *pnode ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to push.\n") ;
    exit(1) ;
  }

  pnode->data=x ;

  pnode->next=ps->top ;
  ps->top=pnode ;
}

int  empty(struct  stack  *ps)
{
  if(ps->top==NULL)
    return 1 ;
  else
    return 0 ;
}

int  popstack(struct  stack  *ps)
{
  int  x ;
  struct  node  *p ;

  if(empty(ps))
  {
    printf("Stack Underflow. Unable to pop.\n") ;
    getch() ;
    exit(1) ;
  }

  x=ps->top->data ;
  p=ps->top ;
  ps->top=ps->top->next ;
  free(p) ;
  return  x ;
}

/* The  statements  
  p=ps->top;
  ps->top=ps->top->next;
  free(p);
  SHOULD NOT BE WRITTEN for function stacktop() */

void  show(struct  stack  s)
{
  struct  node  *p ;

  if(empty(&s))
    printf("Stack empty. No data to display.\n") ;
  else
  {
    printf("Stack from topmost element is as shown:\n") ;
    p=s.top ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }
    printf("\n") ;
  }
}

void  destroystack(struct  stack  *ps)
{
 ps->top=NULL ;
}

void main()
{
 int  x , ch ;

 struct  stack  s ;
 createstack(&s) ;

 clrscr() ;
 do
 {
   printf("\n\n  Menu: \n") ;
   printf("1:push \n") ;
   printf("2:pop \n") ;
   printf("3:exit \n") ;
   printf("Enter your choice: ") ;
   scanf("%d",&ch) ;

   switch(ch)
   {
    case 1:
    printf("Enter element to be pushed: ") ;
    scanf("%d",&x) ;
    pushstack(&s,x) ;
    show(s) ;
    break ;

    case 2:
    x=popstack(&s) ;
    printf("Element popped is: %d \n",x) ;
    show(s) ;
    break ;

    case 3:
    break ;
   }
 }
 while(ch!=3) ;

 destroystack(&s) ;

 getch() ;
}

/*
The operation destroystack need not be given if not asked to do so. Morover even empty operation was not asked. But giving it is necessary for pop and show. 
*/







