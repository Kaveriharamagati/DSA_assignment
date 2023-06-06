1.bubble sort using linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* link;
};
typedef struct node *N;
N head;
N insertend(N head,int b);
N createnode(int b);
N display(N head);
N sort(N head);
int main()
{

    int a,b;
    FILE *fptr;
    fptr=fopen("E:\\sort.txt","r");
    fscanf(fptr,"%d",&a);
    printf("%d ",a);
    for(int i=0;i<=a;i++)
    {
        fscanf(fptr,"%d",&b);
        head=insertend(head,b);
    }
    head=display(head);
    head=sort(head);
    fclose(fptr);
}
N insertend(N head,int b)
{
    N newnode=createnode(b);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
N createnode(int b)
{
    N newnode=(N)malloc(sizeof(struct node));
    newnode->data=b;
    newnode->link=NULL;
    return newnode;
}
N display(N head)
{
    N ptr=head;
    while(ptr->link!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    return head;
}
N sort(N head)
{

    int temp;
    N next=head;
    for(int i=0;i<4;i++)
    {


     while(next->link->link!=NULL)
     {
        if(next->data<next->link->data)
        {
            temp=next->data;
            next->data=next->link->data;
            next->link->data=temp;
        }
        next=next->link;
     }
     next=head;
    }
    printf("\n");

     head=display(head);

}

2.merge sort using linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* first, struct Node* second) {
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }

    struct Node* result = NULL;

    if (first->data <= second->data) {
        result = first;
        result->next = merge(first->next, second);
    } else {
        result = second;
        result->next = merge(first, second->next);
    }

    return result;
}

// Function to split the linked list into two halves
void split(struct Node* source, struct Node** firstHalf, struct Node** secondHalf) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *firstHalf = source;
    *secondHalf = slow->next;
    slow->next = NULL;
}

// Function to perform merge sort on the linked list
void mergeSort(struct Node** head) {
    struct Node* current = *head;
    struct Node* firstHalf;
    struct Node* secondHalf;

    if (current == NULL || current->next == NULL) {
        return;
    }

    split(current, &firstHalf, &secondHalf);

    mergeSort(&firstHalf);
    mergeSort(&secondHalf);

    *head = merge(firstHalf, secondHalf);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&head, data);
    }

    printf("Linked list before sorting:\n");
    printList(head);

    mergeSort(&head);

    printf("Linked list after sorting:\n");
    printList(head);

    return 0;
}


