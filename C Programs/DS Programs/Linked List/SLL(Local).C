/* Singly Linked List (Basic Operations) - Program to create a linked list abstract data type and perform various operations on it (Variable first declared locally in main) */

#include  <stdio.h>
#include  <stdlib.h>
#define  NULL  0

/* Assume that the data portion of each node consists of ONLY an integer.*/
struct  node
{
  int  data ;
  struct  node  *next ;
} ;

/* This function is responsible for creating the Linked List right from the BEGINING. */
void  create(struct  node  **pfirst)
{
  int  i , n ;
  struct  node  *pnode , *p ;

  printf("Enter the number of nodes required:\n") ;
  scanf("%d",&n) ;

  printf("Enter the data value of each node:\n") ;
  for(i=1 ; i<=n ; i++)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;

    if(pnode==NULL)
    {
      printf("Memory overflow. Unable to create.\n") ;
      return ;
    }

    scanf("%d" , &pnode->data) ;

    /* New node will be the last node */
    pnode->next=NULL ;  

    if(*pfirst==NULL)
	 *pfirst=p=pnode ;
    else
    {
	 p->next=pnode ;
	 p=pnode ;  /* p keeps track of last node */
    }
  }
}


/* This function will insert a new node with value x after a node with value K in an already existing Linked List */
void  insertafter(struct  node  **pfirst , int  x , int  k)
{
  struct  node  *pnode , *p ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  /* searching the required node */
  p=*pfirst ;
  while(p!=NULL)
  {
	if(p->data==k)
	  break ;
    p=p->next ;
  }

  /* first condition becomes false when required data is found while second condition becomes false when required data is not found */
  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    pnode->data=x ;

    /* actual insertion */
    pnode->next=p->next ;
    p->next=pnode ;
  }
}

/* This function will insert a new node with value x before a node with value K in an already existing Linked List */
void  insertbefore(struct  node  **pfirst , int  x , int  k)
{
  struct  node  *pnode , *p , *follow ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  /* searching the required node */
  p=*pfirst ;
  follow=NULL ;
  while(p!=NULL)
  {
	if(p->data==k)
	  break ;
    follow=p ;
    p=p->next ;
  }

  if(p==NULL)
    printf("Required node not found.\n") ;
  else
  {
    pnode->data=x ;

    /* actual insertion */

    if(p==*pfirst)  /* inserting before the first node */
    {
      pnode->next=*pfirst ;     /* DONT INTERCHANGE */
      *pfirst=pnode ;
    }
    else /* inserting before any other node */
    {
      follow->next=pnode ;
      pnode->next=p ;
    }
  }
}

/* This function will delete a node with value k from the Linked List if such a node exists */
void  deletenode(struct  node  **pfirst , int  k)
{
  struct  node  *p , *follow ;

  /* searching the node to be deleted */
  p=*pfirst ;
  follow=NULL ;
  while(p!=NULL)
  {
    if(p->data==k)
	  break ;
    follow=p ;
    p=p->next ;
  }

  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    /* actual deletion */
    if(p==*pfirst)   /* first node to be deleted */
      *pfirst=(*pfirst)->next ;
    else	   /* deleting any other node */
      follow->next=p->next ;

    free(p) ;  /* Memory De-allocation */
  }
}

/* This function will search a node with value k in the Linked List */
void  search(struct  node  *first , int  k)
{
  struct  node  *p ;

  p=first ;
  while(p!=NULL)
  {
	if(p->data==k)
	  break ;
	   p=p->next ;
  }

  if(p==NULL)
     printf("Required node not found.\n") ;
  else
    printf("Required node is present at address %X \n",p) ;
}

/* This function go through all the nodes of Linked List exactly once and will display data value of each node */
void  traverse(struct  node  *first)
{
  struct  node  *p ;
  if(first==NULL)
    printf("Linked List Empty") ;
  else
  {
    printf("Linked List is as shown: \n") ;

    p=first ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }
    printf("\n") ;
  }
}

/* This function will count the number nodes in Linked List */
void  count(struct  node  *first)
{
  int  n=0 ;
  struct  node  *p ;

  p=first ;
  while(p!=NULL)
  {
    n++ ;
    p=p->next ;
  }

  printf("Number of nodes in Linked List is %d \n",n) ;
}

/* This function will reverse a given linked list without using additional memory allocation */
void  reverse(struct  node  **pfirst)
{
  struct  node  *p , *follow , *ahead ;

  p=*pfirst ;
  follow=ahead=NULL ;
  while(p!=NULL)
  {
    ahead=p->next ;
    p->next=follow ;
    follow=p ;
    p=ahead ;
  }
  *pfirst=follow ;
}

/* This function will make the Linked List empty. */
void  destroylist(struct  node  **pfirst)
{
  *pfirst=NULL ;
}

void main()
{
  int  x , k , ch ;
  struct  node *first=NULL;
  clrscr();
  do
  {
    printf("\n Menu: \n");
    printf("1:Create Linked List \n");
    printf("2:Insert After \n");
    printf("3:Insert Before \n");
    printf("4:Delete Node \n");
    printf("5:Search Node \n");
    printf("6:Traverse \n");
    printf("7:Count \n");
    printf("8:Reverse \n");
    printf("9:Destroy List \n");
    printf("10:Exit \n");

    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:
      create(&first);
      break;

      case 2:
      printf("Enter the data value of new node: ");
      scanf("%d",&x);
      printf("Enter the data value of that node after which the new node is to be inserted: ");
      scanf("%d",&k);
      insertafter(&first,x,k);
      break;

      case 3:
      printf("Enter the data value of new node: ");
      scanf("%d",&x);
      printf("Enter the data value of that node before which the new node is to be inserted: ");
      scanf("%d",&k);
      insertbefore(&first,x,k);
      break;

      case 4:
      printf("Enter the data value of the node to be deleted: ");
      scanf("%d",&k);
      deletenode(&first,k);
      break;

      case 5:
      printf("Enter the data value of the node to be searched: ");
      scanf("%d",&k);
      search(first,k);
      break;

      case 6:
      traverse(first);
      break;

      case 7:
      count(first);
      break;

      case 8:
      reverse(&first);
      break;

      case 9:
      destroylist(&first);
      break;

      case 10:
      break;
   }
  }
  while(ch!=10) ;
 
  getch();
}







