1. Write a C program to merge contents of two files containing USNs of students in a 
sorted order into the third file such that the third file contains Unique USNs. 
Program should also display common USNs in both the files.

program:


#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *f1,*f2,*f3;
    int num1 , num2 ;
    int has1 = 0, has2 = 0;
    f1 = fopen("file1.txt","r");
    f2 = fopen("file2.txt","r");
    f3 = fopen("file3.txt","w");
    if(f1==NULL|| f2==NULL|| f3 == NULL){
        printf("Error opening files ! \n");
        return 1;
    }
    if(fscanf(f1,"%d",&num1)==1)has1 = 1;
    if(fscanf(f2,"%d",&num2)==1)has2 = 1;
    printf("Common Roll Numbers:");
    while(has1 && has2){
        if(num1 < num2){
            fprintf(f3,"%d \n", num1);
            has1 = (fscanf(f1,"%d",&num1)==1);
        }
        else if(num2 < num1){
            fprintf(f3,"%d \n",num2);
            has2 = (fscanf(f2,"%d",&num2)==1);
        }
        else{
            fprintf(f3,"%d \n",num1);
            printf("%d ",num1);
            has1 = (fscanf(f1,"%d",&num1)==1);
            has2 = (fscanf(f2,"%d",&num2)==1);
        }
    }
    while(has1){
        fprintf(f3,"%d \n",num1);
        has1 = (fscanf(f1,"%d",&num1)==1);
    }
    while(has2){
        fprintf(f3,"%d \n",num2);
        has2 = (fscanf(f2,"%d",&num2)==1);
    }
    printf("\n merged file created as file3.txt \n");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
