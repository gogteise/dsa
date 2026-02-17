#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct term {
    int coeff;
    int deg;
    struct term *next;
};

struct term* CreateList(struct term *head, int coeff[], int deg[], int n) {
    int i;
    struct term *newnode, *tempnode;

    // Create dummy head node
    head = (struct term*)malloc(sizeof(struct term));
    if (head == NULL) {
        printf("Error in allocating memory\n");
        return NULL;
    }
    head->coeff = 0;
    head->deg = 0;
    head->next = head;  // circular

    // Insert terms
    for (i = 0; i < n; i++) {
        newnode = (struct term*)malloc(sizeof(struct term));
        if (newnode == NULL) {
            printf("Error in allocating memory\n");
            return head;
        }
        newnode->coeff = coeff[i];
        newnode->deg = deg[i];
        newnode->next = head;

        // Find last node
        tempnode = head;
        while (tempnode->next != head) {
            tempnode = tempnode->next;
        }
        tempnode->next = newnode;
    }
    return head;
}

int EvalPoly(struct term *head, int x) {
    struct term *tempnode;
    int sum = 0;
    tempnode = head->next;
    while (tempnode != head) {
        sum += tempnode->coeff * (int)pow(x, tempnode->deg);
        tempnode = tempnode->next;
    }
    return sum;
}

int main() {
    struct term *head = NULL;
    int i, n, x, coeff[10], deg[10], sum;

    printf("Enter the number of terms of the polynomial: ");
    scanf("%d", &n);

    printf("Enter coeff and corresponding degree of the terms:\n");
    for (i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d%d", &coeff[i], &deg[i]);
    }

    head = CreateList(head, coeff, deg, n);

    printf("Enter the value of x: ");
    scanf("%d", &x);

    sum = EvalPoly(head, x);
    printf("The sum is: %d\n", sum);

    return 0;
}
