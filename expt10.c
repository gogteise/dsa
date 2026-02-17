#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *llink;
    struct node *rlink;
} NODE;

/* Global Declarations */
NODE *head = NULL;
NODE *last = NULL;

/* Function Declarations */
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

/* Function to create a new node */
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

/* Insert node at the front */
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

/* Insert node at the end */
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

/* Display the list */
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