#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *prev;
  struct node *next;
}*head;
void create(int n)
{ struct node *prev1,*new;
  int i,e,k;
  printf("enter the first node data\n");
  scanf("%d",&e);
  head=(struct node*)malloc(sizeof(struct node));
  head->data=e;
  head->next=NULL;
  head->prev=NULL;
  prev1=head;
  for(i=2;i<=n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=k;
    new->next=NULL;
    new->prev=NULL;
    prev1->next=new;
    new->prev=prev1;
    prev1=new;
  }
  prev1->next=head;
  head->prev=prev1;
}
void display()
{ struct node *ptr=head;
  do
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }while(ptr!=head);
}
void insert_at_beginning(int k)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=k;
  new->next=NULL;
  new->prev=NULL;
  struct node *ptr=head;
  while(ptr->next!=head)
  { ptr=ptr->next;
  }
  new->next=head;
  head->prev=new;
  ptr->next=new;
  head=new;
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  create(n);
  display();
  printf("\nenter the element to be inserted\n");
  scanf("%d",&e);
  insert_at_beginning(e);
  display();
  return 0;
}
