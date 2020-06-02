/* Program to demonstrate Indexed sequential search*/

#include  <stdio.h>
#define  INTERVAL  5
/* If interval is 5 then every 5th element of original array will be represented in index table */

/* We assume that the original array x is sorted in ascending order */

struct  table
{
  int  kindex , pindex ;
} ;

int  iss(int  x[ ] , int  n , int  key , struct  table  index[ ] , int  indexsize) ;

void  main()
{
 /* Size of index table is 1/5th the size of original array since interval is 5 */
 struct  table  index[10] ;
 int  i , n , key , indexsize , p , q , x[50] ;

 clrscr() ;

 printf("Enter the no of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
   scanf("%d",&x[i]) ;

 /*Creating the index table. p keeps track of original array and q keeps track of index table*/
 q=0 ;
 for(p=INTERVAL-1 ; p<n ; p=p+INTERVAL)
 {
   index[q].kindex=x[p] ;
   index[q].pindex=p ;
   printf("%d %d \n",index[q].kindex,index[q].pindex) ;
   q++ ;
 }
 indexsize=q ;

 printf("Enter the element to be searched: ") ;
 scanf("%d",&key) ;

 i=iss(x,n,key,index,indexsize) ;

 if(i==-1)
     printf("%d not found.",key) ;
  else
     printf("%d found at position %d.",key,i) ;

 getch() ;
}

int  iss(int  x[ ] , int  n , int  key , struct  table  index[ ] , int  indexsize) 
{
 int  i , j , highlimit , lowlimit ;

 /* Searching the index table */
 i=0 ;
 while(i<indexsize)
	if(index[i].kindex<=key)
		i++ ;
	else
		break ;

 /* Deciding where searching should start in the original array*/
 if(i==0)
	lowlimit=0 ;
 else
	lowlimit=index[i-1].pindex ;
	

 /* Deciding where searching should end in the original array*/
 if(i==indexsize)
	highlimit=n-1 ;
 else
	highlimit=index[i].pindex-1 ;
	
 /* Searching the original array between lowlimit and highlimit */
 j=lowlimit ;
 while(j<=highlimit)
	if(x[j]!=key)   
		j++ ;
	else
	   break ;

 if(j>highlimit)
	return -1 ;
 else
	return j ;
}
