/* Program to demonstrate heap sort */

#include  <stdio.h>
#include  <conio.h>

void  heapsort(int  x[ ] , int  n) ;
void  heapup(int  heap[ ] , int  newnode) ;
void  heapdown(int  heap[ ] , int  root , int last) ;
void  show(int  x[ ] , int  n) ;

void  main()
{
 int  i , n , x[20] ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 heapsort(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;

 getch() ;
}


void  heapsort(int  x[ ] , int  n)
{
  int  i , temp ;

  /* Heap Creation or Heapify */
  for(i=1 ; i<n ; i++)
  {
    heapup(x,i) ;
    show(x,n) ;
  }
  printf("\n----------------------\n") ;
  /* Actual sorting */
  for(i=n-1 ; i>0 ; i--)
  {
    /* Swapping */
    temp=x[0] ;
    x[0]=x[i] ;
    x[i]=temp ;

    show(x,n) ;

    /* Applying rectification */
    heapdown(x,0,i-1) ;
    show(x,n) ;
  }
}

void  heapup(int  heap[ ] , int  newnode)
{
   int  parent , temp ;
   if(newnode>0)
   {
     parent=(newnode-1)/2 ;
     if(heap[newnode]>heap[parent])
     {
       temp=heap[parent] ;
       heap[parent]=heap[newnode] ;
       heap[newnode]=temp ;

       heapup(heap,parent) ;
     }
   }
}

void  heapdown(int  heap[ ] , int  root , int  last)
{
  int  leftchild , rightchild , largerchild , temp ;

  leftchild=2*root+1 ;
  rightchild=2*root+2 ;

  /* Checking whether leftchild exists */
  if(leftchild<=last) 
  { 
	/*Checking whether right child exists */
    if(rightchild<=last)
      if(heap[leftchild]>heap[rightchild])
	      largerchild=leftchild ;
      else
	      largerchild=rightchild;
    else
      largerchild=leftchild;

    if(heap[root]<heap[largerchild])
    {
      temp=heap[root] ;
      heap[root]=heap[largerchild] ;
      heap[largerchild]=temp ;

      heapdown(heap,largerchild,last) ;
    }
  }
}

void  show(int  x[ ] , int  n)
{
  int  i ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  printf("\n\n") ;
}

/* The method show() is optional. It is written to show output of each pass. It may not be written in theory exam. It is required only in practical exams */
