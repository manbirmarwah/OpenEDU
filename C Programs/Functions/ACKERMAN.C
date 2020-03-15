/* Ackerman Problem - Refer program for Question 

There is a recursive function called the ackermans function which is popular with the lecturers of computer science and can be defined like this
If m and n are integers greater than or equal to zero then
ack(m,n)=n+1, if m=0
ack(m,n)=ack(m-1,1),if(n=0) and m>0
ack(m,n)=ack(m-1,ack(m,n-1)),otherwise
write a recursive function to implement the above mentioned algorithm. */

#include  <stdio.h>
#include  <conio.h>

int  ack(int  m , int  n)
{
  if(m==0)
	return  (n+1) ;
  else if(n==0 && m>0)
	return  ( ack(m-1,1) ) ;
  else
    return  ( ack(m-1, ack(m,n-1) ) );
}

void main()
{
  int  m , n ;

  clrscr() ;
  printf("Enter two numbers: ") ; 
  scanf("%d %d" , &m , &n) ;
  printf("Solution is %d" , ack(m,n) ) ;

  getch() ;
}

/*
Output:

Enter two numbers:  2 3
Solution is 9
*/
