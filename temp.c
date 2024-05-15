#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node* createnode(int);
void display(struct node*);
void append(struct node*);

struct node* reverseLL(struct node*);

int main()
{
    struct node *lhead = NULL;
    int n;
    printf("How many nodes you will created : ");
    scanf("%d",&n);

    head = createnode(n);
    lhead = reverseLL(head);
    display(lhead);
/*
    char choice;

    do{
        printf("Are you addon linked list : (y/n)\n");
        scanf(" %c",&choice);
        if(choice == 'Y' || choice == 'y'){
            struct node *t;
            printf("How many nodes you will created : ");
            scanf("%d",&n);
            t = createnode(n);
            append(t);
            display();
        }
    }while(choice == 'y' || choice == 'Y');
    */
    return 0;
}

struct node* createnode(int n)
{
    struct node *temp, *stemp,*lhead;
    int num,i;

    lhead = (struct node*)malloc(sizeof(struct node));

    if(lhead == NULL)
        printf("memory not allocated\n");
    else 
        {
            printf("Enter first node : ");
            scanf("%d",&num);
            lhead->data = num;
            lhead->next = NULL;
            temp = lhead;
        }

    for(i=2;i<=n;i++)
    {
        stemp = (struct node*)malloc(sizeof(struct node));

        if(stemp == NULL)
            printf("memory not allocated\n");

        else
        {
            printf("Enter node %d : ",i);
            scanf("%d",&num);

            stemp->data = num;
            stemp->next = NULL;

            temp->next = stemp;
            temp = temp->next;
        }
    }
    return lhead;
}
void append(struct node *newlist)
{
    if(head == NULL)
        head = newlist;
    else
    {
        struct node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newlist;
    }
}

struct node* reverseLL(struct node* rhead)
{
    struct node *prev = NULL;
    struct node *temp = rhead, *front = NULL;
    if(rhead == NULL){
        printf("there is no LL\n");
        return NULL;
    }
    else
        {
            while(temp != NULL)
            {
              front = temp->next;
              temp->next = prev;
              prev = temp;
              temp = front;
            }
        }
    return prev;
}


void display(struct node* lhead)
{
    if(lhead == NULL)
        printf("empty linked list\n");
    else
    {
        struct node *temp = lhead;
        printf("node are : ");
        while(temp)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}


