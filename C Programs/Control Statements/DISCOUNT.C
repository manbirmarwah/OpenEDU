/* Write a program which reads price of an article and the corresponding discount policy
If discount policy=1, discount=10%
If discount policy=2, discount=20%
If discount policy=3, discount=30%
For all other policies, discount=0
Print the final price of the article */

#include <stdio.h>
#include <conio.h>

void  main()
{
 float  p, d, fp ;
 int  policy ;
  
 clrscr() ;

 printf("Enter price of article and corresponding discount policy: ") ;
 scanf("%f %d", &p, &policy) ;

 switch(policy)
 {
	case 1: d=0.1*p ;
	        break ;
   case 2: d=0.2*p ;
	        break ;
   case 3: d=0.3*p ;
	        break ;
   default: d=0 ;
 }
 fp=p-d ;
 printf("Final price of the article is %f",fp) ;

 getch() ;
}

/*
Output 1:

Enter price of article and corresponding discount policy: 15 3
Final price of the article is 10.500000

Output 2:

Enter price of article and corresponding discount policy: 15 8
Final price of the article is 15.000000
*/







