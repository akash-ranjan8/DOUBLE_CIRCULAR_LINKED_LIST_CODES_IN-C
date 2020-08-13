#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
  struct node *prev;
}*head;
void create(int n)
{ int e,k,i;
  struct node *prev1,*new;
  printf("enter the data for 1st node\n");
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
int main()
{ int n;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  create(n);
  display();
  return 0;
}
