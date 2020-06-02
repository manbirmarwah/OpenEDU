/* Program to demonstrate hashing using modulo division and linear probing */

#include  <stdio.h>
#include  <conio.h>
#define  size  10

/* The hashtable size is normally 5 times the size of original array. However, in this program I have  taken the size of hashtable same as original array */
int  ht[size] ;

void  store(int  x[ ] , int  n) ;
int  modulodivision(int  key) ;
int  linearprobe(int  address) ;
void  hashsearch() ;

void main()
{
 int  i , n , x[10] ;
 char  ch ;

 clrscr() ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 store(x,n) ;

 printf("Hashtable is as shown:\n") ;
 for(i=0 ; i<size ; i++)
    printf("%d " , ht[i]) ;
 printf("\n") ;

 do
 {
   hashsearch() ;

   printf("Do you want to search another element ? ") ;
   flushall() ;
   scanf("%c",&ch) ;
 }
 while(ch=='y'||ch=='Y') ;

 getch() ;
}

void  store(int  x[ ] , int  n)
{
  int  i , key , address ;

  /* Initializing hash table to empty */
  for(i=0 ; i<size ; i++)
    ht[i]=-1 ;

  /* Copying elements from original array to hashtable */
  for(i=0 ; i<n ; i++)
  {
    key=x[i] ;
    address=modulodivision(key) ;
    if(ht[address]!=-1)
      address=linearprobe(address) ;
    ht[address]=key ;
  }
}

/* Hash Function */
int  modulodivision(int  key)
{
  int  address ;
  address=key%size+1 ;
  if(address==size)
    return  0 ;
  else
    return  address ;
}

/* Collision Resolution */
int  linearprobe(int  address)
{
  while(ht[address]!=-1)
  {
    address++ ;
    if(address==size)
      address=0 ;
  }
  return  address ;
}

/* Searching in hashtable */
void  hashsearch()
{
 int  key , address ;

 printf("Enter the element to be searched: ") ;
 scanf("%d",&key) ;

 address=modulodivision(key) ;

 while(ht[address]!=key && ht[address]!=-1)
 {
   address++ ;
   if(address==size)
     address=0 ;
 }

 if(ht[address]==-1)
   printf("%d not found \n",key) ;
 else
   printf("%d found at position %d \n",key,address) ;
}

