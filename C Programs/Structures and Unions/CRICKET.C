/* Structure - Cricket 
Define a structure called cricket that will describe the following info
1)player name  2)team name  3)no of matches played   4)batting average
Declare an array player with 50 elements. Write a program to read information about all 50 players. Sort the information on their batting average and print the results */


#include  <stdio.h>
#include  <conio.h>

void main()
{
  struct cricket
  {  
    char  pname[20] ;		
    char  tname[20] ;  	
    int  np ;  	
    float  avg ;  
  };
  /* Some compilers do not allow float member in a structure. In that case make avg to be of data type int */
  struct  cricket player[50] , temp ;
  int  i , j ;

  clrscr();
 
  printf("Enter player name , team name , number of matches played and batting average for 50 players:\n") ;
  for(i=0 ; i<50 ; i++)
    scanf("%s %s %d %f" , player[i].pname , player[i].tname , &player[i].np , &player[i].avg) ;

  for(i=0 ; i<50-1 ; i++)
    for(j=0 ; j<50-1-i ; j++)
       if(player[j].avg < player[j+1].avg )
       {      
		  temp=player[j] ;	
           player[j]=player[j+1] ;
       	   player[j+1]=temp ;
       }

  printf("\nList in descending order of batting average is as shown:\n") ;
  for(i=0 ; i<50 ; i++)
    printf("%s %s %d %f \n", player[i].pname , player[i].tname , player[i].np , player[i].avg) ;

  getch();
}

/*
The following output is shown for 3 players only:

Enter player name , team name , number of matches played and batting average for 50 players:
Jack  Australia  202  67.5
Sachin  India  210  82.75
Tim  U.K.  205  76.25

List in descending order of batting average is as shown:
Sachin India 210 82.750000 
Tim U.K. 205 76.250000 
Jack Australia 202 67.500000 
*/

