/* Binary Tree (NOT Binary Search Tree) operations - Create , Copy , Mirror , Traverse , node count and leaf count */

#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
#define  NULL  0		

/* Assume that the data portion of each node consists of an integer. */
struct  node
{
  int  data ;
  struct  node  *left , *right ;
} ;

int  ncount , lcount ;

/* This function is responsible for creating a BT with multiple nodes */
struct node * create()
{
  int  x ;
  struct  node  *pnode ;
  
  printf("Enter the data value of node.\n") ;
  printf("Enter -1 for no data or NULL.\n") ;
  scanf("%d",&x) ;

  if(x==-1)
    return NULL;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  pnode->data=x ;

  printf("Enter the left child of %d.\n",x) ;
  pnode->left=create() ;

  printf("Enter the right child of %d.\n",x) ;
  pnode->right=create() ;

  return pnode ;
}

/* This function will copy one binary tree into another */
struct node *  copy(struct node *root)
{
  struct node *pnode ;

  if(root==NULL)
    return NULL;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  pnode->data=root->data ;
  
  pnode->left=copy(root->left) ;
  pnode->right=copy(root->right) ;

  return pnode ;
}


/* This function will create a mirror image of original binary tree */
struct node *  mirror(struct node *root)
{
  struct node *pnode ;

  if(root==NULL)
    return NULL;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  pnode->data=root->data ;
  
  pnode->left=mirror(root->right) ;
  pnode->right=mirror(root->left) ;

  return pnode ;
}

/* Binary Tree Traversal methods */
void  preorder(struct  node  *root)
{
  if(root!=NULL)
  {
    /* Visit the root */
    printf("%d " , root->data) ;
    /* Traverse the left subtree in preorder */
    preorder(root->left) ;
    /* Traverse the right subtree in preorder */
    preorder(root->right) ;
  }
}

void  inorder(struct  node  *root)
{
  if(root!=NULL)
  {
    inorder(root->left) ;
    printf("%d ",root->data) ;
    inorder(root->right) ;
  }
}

void  postorder(struct  node  *root)
{
  if(root!=NULL)
  {
    postorder(root->left) ;
    postorder(root->right) ;
    printf("%d ",root->data) ;
  }
}

/* This function will count the total no. of nodes in the BT */
void  nodecount(struct  node  *root)
{
  if(root!=NULL)
  {
    nodecount(root->left) ;
    ++ncount ;
    nodecount(root->right) ;
  }
}

/* This function will count the total no. of leaf nodes in the BT. Moreover, it will also display data value of leaf nodes. */
void  leafnodecount(struct  node  *root)
{
  if(root!=NULL)
  {
    leafnodecount(root->left) ;
    if(root->left==NULL && root->right==NULL)
    {
      ++lcount ;
      printf("%d ",root->data) ;
    }
    leafnodecount(root->right) ;
  }
}


void main()
{
  struct node *root = NULL ;
  struct node *root1 = NULL ;
  struct node *root2 = NULL ;

  int  ch ;
 
  clrscr() ;

  do
  {
    printf("1.Create. \n") ;
    printf("2.Copy Tree. \n") ;
    printf("3.Mirror Tree. \n") ;
    printf("4.Preorder. \n") ;
    printf("5.Inorder. \n") ;
    printf("6.Postorder. \n") ;
    printf("7.Node Count. \n") ;
    printf("8.Leaf Count. \n") ;
    printf("9.Exit\n") ;

    printf("Enter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      root=create() ;
      break ;

      case 2:
      root1=copy(root) ;
      printf("Preorder traversal of copied tree is: \n") ;
      preorder(root1) ;
      printf("\n") ;
      printf("Inorder traversal of copied tree is: \n") ;
      inorder(root1) ;
      printf("\n") ;
      printf("Postorder traversal of copied tree is: \n") ;
      postorder(root1) ;
      printf("\n") ;
      break ;

      case 3:
      root2=mirror(root) ;
      printf("Preorder traversal of mirrored tree is: \n") ;
      preorder(root2) ;
      printf("\n") ;
      printf("Inorder traversal of mirrored tree is: \n") ;
      inorder(root2) ;
      printf("\n") ;
      printf("Postorder traversal of mirrored tree is: \n") ;
      postorder(root2) ;
      printf("\n") ;
      break ;

      case 4:
      preorder(root) ; 
      printf("\n") ;
      break ;

      case 5:
      inorder(root) ;
      printf("\n") ;
      break ;

      case 6:
      postorder(root) ;
      printf("\n") ;
      break ;

      case 7:
      ncount=0 ;
      nodecount(root) ;
      printf("No. of nodes present in the tree are %d \n",ncount) ;
      break ;

      case 8:
      lcount=0 ;
      leafnodecount(root) ;
      printf("No. of Leaf nodes present in the tree are %d \n",lcount) ;
      break ;

      case 9:
      break ;
    }
  }
  while(ch!=9) ;

  getch() ;
}









