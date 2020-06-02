/* Program to solve towers of hanoi problem */

#include  <stdio.h>
#include  <conio.h>

void  towers(int  n , char  frompeg , char  topeg , char  auxpeg)
{
  if(n==1)    /* only one disk is present */
  {
    printf("Move disk 1 from %c to %c \n" , frompeg , topeg) ;
    return ;
  }

  /* move top n-1 disks from a to b using c as auxillary */
  towers(n-1, frompeg , auxpeg , topeg) ;

  /* move remaining disk from a to c */
  printf("Move disk %d from %c to %c \n" , n , frompeg , topeg);

  /* move n-1 disks from b to c using a as auxillary */
  towers(n-1 , auxpeg , topeg , frompeg) ;
}

void  main()
{
  int  n ;

  clrscr() ;

  printf("Enter number of disks: ") ;
  scanf("%d",&n) ;
  printf("Solution for %d disks is as shown: \n",n) ;
  towers(n,'A','C','B') ;

  getch() ;
}

