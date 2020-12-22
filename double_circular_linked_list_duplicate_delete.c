#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
  struct node *prev;
};
struct node *head=NULL;
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
void duplicate_removal()
{ struct node *t1=head;
  struct node *t2=head->next;
  do
  {
    do
    { if(t1->data==t2->data)
      { delete(t1->data);
      }
      else
      { continue;
      }
      t2=t2->next;
    }while(t2!=head);
    t1=t1->next;
  }while(t1!=head);
  display();
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  create(n);
  display();
  printf("\nduplicate items deleted list\n");
  duplicate_removal();
  return 0;
}
