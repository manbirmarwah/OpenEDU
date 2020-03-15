/* 
Four Expeiments are performed, each experiment consisting of six results. The result for each expeiment follows. Write a program to compute and display the average of the test results for each experiment.
1st experiment results		23.2  31.5  16.9  28.0  26.3  28.2
2nd experiment results	34.8  45.2  20.8  39.4  33.4  36.8
3rd experiment results		19.4  50.6  45.1  20.8  50.6  13.4
4th experiment results		36.9  42.7  20.8  10.2  16.8  42.7
*/

#include  <stdio.h>
#include  <conio.h>

void main()
{
  float  x[4][6] = {23.2 , 31.5 , 16.9 , 28.0 , 26.3 , 28.2 , 34.8 , 45.2 , 20.8 , 39.4 , 33.4 , 36.8 , 19.4 , 50.6 , 45.1 , 20.8 , 50.6 , 13.4 , 36.9 , 42.7 , 20.8 ,  
                           10.2 , 16.8 , 42.7} ;
  float  sum ;
  int r , c ;

  clrscr() ;

  for(r=0 ; r<4 ; r++)
  {
    sum = 0 ;
    for(c=0 ; c<6 ; c++)
        sum = sum + x[r][c];
    printf("Test results average for experiment number %d is %f \n" , r+1 , sum/6 );
  }

  getch();
}

/*
Output:

Test results average for experiment number 1 is 25.683332 
Test results average for experiment number 2 is 35.066669 
Test results average for experiment number 3 is 33.316666 
Test results average for experiment number 4 is 28.350000 
*/

