/* Program to demonstrate  radix sort */

/* Some textbooks and some teachers call radix sort as bucket sort i.e. they consider radix sort and bucket sort same. However, in some textbooks bucket sort is considered to be that sorting technique in which the numbers to be sorted must be of ONLY ONE DIGIT while radix sort can sort numbers with MULTIPLE DIGITS.  Personally, I follow the practice in which they are considered different. You may follow what your college techers tell you.*/

#include  <stdio.h>
#include  <conio.h>

void  radixsort(int  x[ ] , int  n) ;
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

 radixsort(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0 ; i<n ; i++)
    printf("%d ",x[i]) ;

 getch() ;
}

void  radixsort(int  x[ ] , int  n)
{
  int  i , j , k , d , max , divisor , digit , passes ;
  int  bucket[10][20] , count[10] ;
  /* We assume there will be a maximum of 20 elements in each bucket. Count[i] will store the number of elements in bucket[i]  For example, if bucket[2] has 5 elements then count[2] = 5 */

  /* Finding the largest number in the array */
  max=x[0] ;
  for(i=1 ; i<n ; i++)
     if(x[i]>max)
       max=x[i] ;

  /* Finding the number of digits in largest number which will be equal to the total number of passes */
  passes=0 ;
  while(max>0)
  {
	max=max/10 ;
	passes++ ;
  }

  /* Starting radix sort */
  divisor = 1 ;
  for(digit=1 ; digit<=passes ; digit++)
  {
    for(i=0 ; i<10 ; i++)
      count[i]=0 ;

    /* Copying elements from the array into the buckets */
    for(i=0 ; i<n ; i++)
    {
	 d=(x[i]/divisor)%10 ;
      bucket[ d ][ count[d] ]= x[i] ;
      count[ d ]++ ;
    }

    /* Copying elements from the buckets into the array */
    k=0 ;
    for(i=0 ; i<10 ; i++)
      for(j=0 ; j<count[i] ; j++)
	x[k++] = bucket[i][j] ;

    divisor = divisor * 10 ;
  }
}
