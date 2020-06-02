/*Program to perform depth first traversal on a graph */

#include  <stdio.h>

int  v , adj[10][10] , visited[10] ; 
/* Assuming maximum 9 vertices. */

void  dfs(int  k) ;

void  main()
{
 int  i , j ;

 clrscr() ;

 /* Creating graph of v vertices */
 printf("Enter the number of vertices in the graph: ") ;
 scanf("%d",&v) ;

 for(i=1 ; i<=v ; i++)
   for(j=1 ; j<=v ; j++)
   {
     printf("Is vertex %d adjacent to vertex %d ? ",j,i) ;
     printf("Enter 1 if yes and 0 if no. ") ;
     scanf("%d",&adj[i][j]) ;
    }

 /* Making all the vertices as unvisited */
 for(i=1 ; i<=v ; i++)
   visited[i]=0 ;

 printf("Depth first Search of the graph is as shown:\n") ; 
 for(i=1 ; i<=v ; i++)
   if(visited[i]==0)
     dfs(i) ;
     /* Initiating dfs from vertex i if it is not visited */

 getch() ; 
}

void  dfs(int  k)
{
  int j ;

  visited[k]=1 ;     /* Visiting vertex k */

  printf("%d ",k) ;

  for(j=1; j<=v ; j++)
    if(adj[k][j] == 1)
      if(visited[j] ==0)
	    dfs(j);      /* Initiating dfs from vertex j */
}

/* The first if checks whether vertex j is adjacent to vertex k. The second if checks whether j is visited or not */
