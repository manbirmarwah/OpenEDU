/* Structure - Computer - Program to declare structure for COMPUTER configuration having CPU-type, SDRAM-size, clock-speed, HDD-size, CDROM-type, CDROM-speed, mouse-type, keyboard-type, SVGA-monitor-make. Read information for 50 computers and list computers having HDD size greater than 250 GB. */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  struct computer
  {
    char  cputype[20] , cdtype[20] , mousetype[20] , kbtype[20] , monmake[20] ;
    int  sdsize , clockspeed , hddsize , cdspeed ;
  } ;
  struct computer c[50] ;
  int  i , j , n ;

  clrscr();

  printf("Enter details for all 50 computers: \n") ;
  printf("Enter cpu type, cdrom type, mouse type, keyboard type, monitor make, sdram size, clock speed, hdd size, cdrom speed: \n") ;
  for(i=0 ; i<3 ; i++)
    scanf("%s %s %s %s %s %d %d %d %d" , c[i].cputype , c[i].cdtype , c[i].mousetype , c[i].kbtype , c[i].monmake , &c[i].sdsize ,   
    &c[i].clockspeed , &c[i].hddsize , &c[i].cdspeed ) ;	
  printf("\nComputers with HDD size greater than 250 GB are as shown:\n"); 
  for(i=0 ; i<3 ; i++)
    if(c[i].hddsize>250)
      printf("%s %s %s %s %s %d %d %d %d \n" , c[i].cputype, c[i].cdtype , c[i].mousetype, c[i].kbtype, c[i].monmake, c[i].sdsize, 
      c[i].clockspeed , c[i].hddsize , c[i].cdspeed) ;

  getch();	
}

/*
Output:
Enter details for all 50 computers: 
Enter cpu type, cdrom type, mouse type, keyboard type, monitor make, sdram size, clock speed, hdd size, cdrom speed: 
asw  qtw  uyr  ndf  iur  2  120  100  320
gta  wer  nhy  aqw  dre  4  600 500 400
fra  ytr  wqe  loi  bgt  1  210 250 340

Computers with HDD size greater than 250 GB are as shown:
gta wer nhy aqw dre 4 600 500 400 
*/

 
