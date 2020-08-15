#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
  struct node *prev;
}*head;
void create(int n)
{ int e,k,i;
  struct node *new,*prev1;
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
void delete(int k)
{ struct node *ptr=head;
  while(ptr->data!=k)
  { ptr=ptr->next;
  }
  struct node *t1,*t2;
  t1=ptr->next;
  t2=ptr->prev;
  t1->prev=t2;
  t2->next=t1;
  free(ptr);
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  create(n);
  display();
  printf("\nenter the element to be deleted\n");
  scanf("%d",&e);
  delete(e);
  printf("\n");
  display();
  return 0;
}
