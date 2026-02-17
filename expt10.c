10.Develop and execute a program in C using suitable data structures to perform 
Searching a data item in an ordered list of items in both directions and implement the following operations:
1. Create a doubly linked list by adding each node at the start.
2. Insert a new node at the end of the list.
3. Display the content of a list.Consider an integer number as a data item

PROGRAM:

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} NODE;

NODE *head = NULL;
NODE *last = NULL;

NODE* getnode();
void create();
void insert_last();
void display();

int main() {
    int option;

    do {
        printf("\n\nDoubly linked list\n");
        printf("Press 1-Createlist, 2-InsertAtlast, 3-Display, 4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                create();
                break;

            case 2:
                insert_last();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Terminating...\n");
                break;

            default:
                printf("\nInvalid option !!! Try again !! \n");
                break;
        }
    } while(option != 4);

    return 0;
}

NODE* getnode() {
    NODE *newnode = (NODE *)malloc(sizeof(NODE));

    if(newnode == NULL) {
        printf("Memory allocation unsuccessful\n");
        exit(0);
    }

    newnode->rlink = newnode->llink = NULL;
    printf("\nEnter the data for node: ");
    scanf("%d", &newnode->data);
    return newnode;
}
void create() {
    NODE *newnode = getnode();

    if(head == NULL) {
        head = newnode;
        last = head;
    } else {
        newnode->llink = NULL;
        newnode->rlink = head;
        head->llink = newnode;
        head = newnode;
    }
    printf("\nNode with value %d is inserted at front of the list\n", newnode->data);
}

void insert_last() {
    NODE *newnode = getnode();

    if(head == NULL) {
        head = newnode;
        last = head;
    } else {
        last->rlink = newnode;
        newnode->llink = last;
        newnode->rlink = NULL;
        last = newnode;
    }
    printf("\nNode with value %d is inserted at last of the list\n", newnode->data);
}

void display() {
    NODE *temp = head;

    if(head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nElements in doubly linked list are: \n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");

}

