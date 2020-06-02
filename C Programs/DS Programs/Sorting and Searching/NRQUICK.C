/* Program to demonstrate non recursive quick sort */

#include  <stdio.h>
#include  <conio.h>
#define  STACKSIZE  50

struct  bounds
{
  int  lb , ub ;
} ;

struct  stack
{
  int  top ;
  struct  bounds  items[STACKSIZE] ;
} ;

void  quick(int  x[ ] , int  n) ;
int  partition(int  x[ ] , int  lb , int  ub) ;
void  show(int  x[ ] , int  lb , int  ub) ;

void  push(struct  stack  *ps , struct  bounds  x) ;
struct  bounds  pop(struct  stack  *ps) ;
int  empty(struct  stack  *ps) ;

void  main()
{
 int  i , n , x[20] ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 quick(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0 ; i<n ; i++)
    printf("%d ",x[i]) ;

 getch() ;
}

void  quick(int  x[ ] , int  n)
{
  int  temp , j ;
  struct  bounds  b ;

  /*Initializing the stack to be empty*/
  struct  stack  s ;
  s.top=-1 ;

  b.lb=0 ;
  b.ub=n-1 ;
  push(&s,b) ;

  /*Repeat as long as there are any unsorted sub-arrays*/
  while(!empty(&s))
  {
    b=pop(&s) ;
    while(b.ub>b.lb)
    {
      j=partition(x,b.lb,b.ub) ;
      if(j-b.lb>b.ub-j)
      {    /* stack the lower sub-array */
	   temp=b.ub;
	   b.ub=j-1;
	   push(&s,b);

	   /* Process the upper sub-array */
	   b.lb=j+1;
	   b.ub=temp;
      }
      else
      {
	   /* stack the upper sub-array */
	   temp=b.lb;
	   b.lb=j+1;
	   push(&s,b);

	   /* Process the lower sub-array */
	   b.ub=j-1;
	   b.lb=temp;
      }
    }
  }
}

int  partition(int  x[ ] , int  lb , int  ub)
{
  int  a , down , up , temp ;

  a=x[lb] ;
  up=ub ;
  down=lb ;

  while(down<up)
  {
    while(x[down]<=a&&down<ub)
	   down++ ;
	
    while(x[up]>a)
	   up-- ;
	
    if(down<up)
    {
	    temp=x[down];
	    x[down]=x[up];
	    x[up]=temp;
    }
  }

  x[lb]=x[up] ;
  x[up]=a ;

  show(x,lb, ub) ;

  return up ;
}

void  show(int  x[ ] , int  lb , int  ub)
{
  int  i ;
  for(i=lb ; i<=ub ; i++)
    printf("%d " , x[i]) ;
  printf("\n\n") ;
}

void  push(struct  stack  *ps , struct  bounds  x)
{
  if(ps->top==STACKSIZE-1)
  {
    printf("Stack Overflow. Cannot push. \n") ;
    getch() ;
    exit(1) ;
  }
  ps->items[++(ps->top)]=x ;
}

struct  bounds  pop(struct  stack  *ps)
{
  if(empty(ps))
  {
      printf("Stack Underflow. Cannot pop. \n") ;
      getch() ;
      exit(1) ;
  }
  return(ps->items[(ps->top)--]) ;
}

int  empty(struct  stack  *ps)
{
  if(ps->top==-1)
    return  1 ;
  else
    return  0 ;
}


/* The method show() is optional. It is written to show output of each pass. It may not be written in theory exam. It is required only in practical exams */




