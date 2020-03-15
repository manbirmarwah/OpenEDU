/* 
An electric power distribution company charges its domestic consumer as follows:
Consumption Units				Rate of Charge
0-200							0.50 per unit
201-400						Rs. 100 plus Rs. 0.65 per unit excess of 200
401-600						Rs. 230 plus Rs. 0.85 per unit excess of 400
601-above					Rs. 390 plus Rs. 1.00 per unit excess of 600
Program should read the units consumed for a customer and calculate the total bill.
 */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  int  units ;
  float  amt ;

  clrscr() ;
  printf("Enter consumption units: ") ;
  scanf("%d" , &units) ;

  if(units>=0 && units<=200)
  {
    amt = units * 0.50 ;
    printf("The total billing amount is %f" , amt) ;
  }
  else  if(units>=201 && units<=400)
  {
    amt = 100 + (units-200) * 0.65 ;
    printf("The total billing amount is %f" , amt) ;
  }
  else  if(units>=401 && units<=600)
  {
    amt = 230 + (units-400) * 0.85 ;
    printf("The total billing amount is %f" , amt) ;
  }
   else
  {
    amt = 390 + (units-600) * 1.00 ;
    printf("The total billing amount is %f" , amt) ;
  }

  getch() ;
}

/*
Output 1:

Enter consumption units: 300
The total billing amount is 165.000000

Output 2:

Enter consumption units: 450
The total billing amount is 272.500000

Output 3:

Enter consumption units: 620
The total billing amount is 410.000000
*/

