#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void insert_beg(int a)
{
    
    struct node *temp=(struct node *)malloc(sizeof(struct node ));
    temp->data=a;
    temp->link=head;
    head=temp;
   
}

void insert_end(int a)
{
      struct node *p,*temp;
       temp=(struct node *)malloc(sizeof(struct node ));
       temp->data=a;
       temp->link=NULL;
      p=head;
      if(p!=NULL){
      while (p->link!=NULL)
      {
         p=p->link;
      }
      p->link=temp;
      }
      else{
           head=temp;
      }
}

 void insert_after(int a,int b)
 {    
      int flag=0;
      struct node *p,*temp;
      p=head;
      while(p!=NULL)
      {
          if(p->data==a)
          {
           temp=(struct node*)malloc(sizeof(struct node));
           temp->data=b;
           temp->link=p->link;
           p->link=temp;
           flag=1;
           break;
          }
          p=p->link;
      }
       if(flag==0)
          printf("%d is not present in the linked list\n",a);
 }

void insert_before(int a,int b)
{
    struct node *p,*pre,*temp;
    int flag=0;
    p=head;
    pre=NULL;
    while(p!=NULL)
    {
        if(p->data==a)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=b;
            temp->link=pre->link;
            pre->link=temp;
            flag=1;
            break;
        }
        pre=p;
        p=p->link;
    }
     if(flag==0)
     printf("%d is not present in the linked list\n",a);
}

 void display()
{   
    struct node *p;
    if(head==NULL)
    {
        printf("Link list is empty.\n");
    }
    else
    {   p=head;
        printf("Linked list:  ");
        while(p->link!=NULL)
        {
            printf(" %d->",p->data);
            p=p->link;
        }
        printf(" %d",p->data);
    }
    printf("\n");
}

 void delete(int a)
 {
     struct node *p,*pre;
     p=head;
     pre=NULL;
    while(p!=NULL && p->data!=a)
    {   
        pre=p;
        p=p->link;
    }
    if(p==NULL)
    {
         printf("\n%d is not present in the linked list\n",a);
    }
    else if(p==head)
    {
        head=p->link;
    }
    else
    {
        pre->link=p->link;
    }
    
    free(p);
}

void sort()
{   
    int temp;
    struct node *pre,*post;
    pre=head;
    //post=pre->link;

    while(pre->link!=NULL)
    {   
        post=pre->link;
        while(post!=NULL)
        {
             if(post->data<pre->data)
             {
                 temp=pre->data;
                 pre->data=post->data;
                 post->data=temp;
             }
             post=post->link;
        }
        pre=pre->link;
    }              
}
void sort_de()
{
    struct node *pre,*post;
    int temp;
    pre=head;
   // post=pre->link;

    while(pre->link!=NULL)
    {   
        post=pre->link;
        while(post!=NULL)
        {
            if(pre->data<post->data)
            {
                temp=pre->data;
                pre->data=post->data;
                post->data=temp;
            }
            post=post->link;
        }
        pre=pre->link;
    }
}
void reverse()
{
    struct node *pre,*next,*temp;
    pre=NULL;
    temp=next=head;
  //  next=temp->link;
    while(next!=NULL)
    {    
        next=next->link;
        temp->link=pre;
        pre=temp;
        temp=next;
    }
    head=pre;
}
int main()
{
    //struct node *head=NULL;
    int choice,d,a,b;
    char ans;
     do{// printf("/n%p",head);
    printf("\n");
    printf("1.Insert a number at begining.\n");
    printf("2.Insert a number at end\n");
    printf("3.Insert after a number\n");
    printf("4.Insert before a number\n");
    printf("5.Sort in ascending order\n");
    printf("6.Sort in descending order\n");
    printf("7.Reverse the Linked list\n");
    printf("8.Display\n");
    printf("9.Delete\n");
    printf("10.Exit\n");
   // printf("5.Count the number of elements\n");
    printf("\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 1:printf("\nEnter a number you want to insert: ");
           scanf("%d",&d);
           insert_beg(d);
           break;
    case 2:printf("\nEnter a number you want to insert: ");
           scanf("%d",&d);
           insert_end(d);
           break;
    case 3:printf("\nEnter the number after which you want to enter a new number: ");
           scanf("%d",&a);
           printf("\nEnter a number you want to insert:");
           scanf("%d",&d);
           insert_after(a,d);
           break;
    case 4:printf("\nEnter the number before which you want to enter a new number: ");
           scanf("%d",&a);
           printf("\nEnter a number you want to insert:");
           scanf("%d",&d);
           insert_before(a,d);
           break;  
    case 5: sort();
            break;
    case 6: sort_de();
            break;
    case 7: reverse();
            break;       
    case 8:display();
           break;
    case 9: printf("\nEnter a number you want to delete: ");
            scanf("%d",&d);
            delete(d);
            break;
    case 10:exit(0);
           break;
    default:printf("\nInvalid input\n");
        break;
    }
     }
    while(1);

return 0;
}
