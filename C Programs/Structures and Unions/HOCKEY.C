/* Structure - Program on hockey players
Define a structure called "hockey"containing following elements:
1)player name  2)Country name  3)no of matches played   4)no of goals scored
Write a program to read records of n players and to prepare the following lists
1) List prepared according to player's name
2) List prepared according to country's name
3) List prepared according to no. of matches played
4) List prepared according to no. of goals scored */

#include  <stdio.h>
#include  <conio.h>
#include  <string.h>

void main()
{
  struct  hockey
  {
  	char  pname[20] ;
	char  cname[20] ;
  	int  np ;
  	int  ng ;
  } ;
  struct    hockey    player[50] , temp ;
  int  i , j , n ;

  clrscr();

  printf("Enter the number of players: ") ;
  scanf("%d" , &n)  ;

  printf("Enter player name , country name , number of matches played and no of goals scored  for all players:\n\n")  ;
  for(i=0 ; i<n ; i++)
     scanf("%s %s %d %d" , player[i].pname , player[i].cname , &player[i].np , &player[i].ng) ;

  /* List according to number of goals scored */
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ;j++)
       if(player[j].ng<player[j+1].ng)
       {      
		   	temp=player[j];
       		player[j]=player[j+1];
       		player[j+1]=temp;
       }

  printf("\nList in descending order of number of goals scored is as shown:\n") ;
  for(i=0 ; i<n ; i++)
  	printf("%s  %s  %d  %d \n" , player[i].pname , player[i].cname , player[i].np , player[i].ng) ;

  /* List according to number of matches played */
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ;j++)
       if(player[j].np<player[j+1].np)
       {      
		   	temp=player[j];
       		player[j]=player[j+1];
       		player[j+1]=temp;
       }

  printf("\nList in descending order of number of matches played is as shown:\n") ;
  for(i=0 ; i<n ; i++)
  	printf("%s  %s  %d  %d \n" , player[i].pname , player[i].cname , player[i].np , player[i].ng) ;

  /* List according to country name */
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ;j++)
       if( strcmp(player[j].cname , player[j+1].cname) > 0 )
       {      
		   	temp=player[j];
       		player[j]=player[j+1];
       		player[j+1]=temp;
       }

  printf("\nList in alphabetical order of country name is as shown:\n") ;
  for(i=0 ; i<n ; i++)
  	printf("%s  %s  %d  %d \n" , player[i].pname , player[i].cname , player[i].np , player[i].ng) ;
  
  /* List according to player name */
  for(i=0 ; i<n-1 ; i++)
    for(j=0 ; j<n-1-i ;j++)
       if( strcmp(player[j].pname , player[j+1].pname) > 0 )
       {      
		   	temp=player[j];
       		player[j]=player[j+1];
       		player[j+1]=temp;
       }

  printf("\nList in alphabetical order of player name is as shown:\n") ;
  for(i=0 ; i<n ; i++)
  	printf("%s  %s  %d  %d \n" , player[i].pname , player[i].cname , player[i].np , player[i].ng) ;

  getch() ;
}

/* In this program I have used strcmp() to compare two strings. strcmp() is case sensitive. A better option is to use strcmpi() which is not case sensitive. However, some compilers do not support strcmpi() */

/*
Output:

Enter the number of players: 3
Enter player name , country name , number of matches played and no of goals scored  for all players:

Jack  USA  24  28
Tim  India  16  35
Sandy  Brazil  10  42

List in descending order of number of goals scored is as shown:
Sandy  Brazil  10  42 
Tim  India  16  35 
Jack  USA  24  28 

List in descending order of number of matches played is as shown:
Jack  USA  24  28 
Tim  India  16  35 
Sandy  Brazil  10  42 

List in alphabetical order of country name is as shown:
Sandy  Brazil  10  42 
Tim  India  16  35 
Jack  USA  24  28 

List in alphabetical order of player name is as shown:
Jack  USA  24  28 
Sandy  Brazil  10  42 
Tim  India  16  35 

*/




