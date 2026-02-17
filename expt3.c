3. A calculator needs to evaluate a postfix expression.
Develop and execute a program in C using a suitable data structure to evaluate a valid postfix expression. 
Assume the postfix expression is read as a single line consisting of non-negative single digit operands and binary arithmetic operators. 
The arithmetic operators are + (add), (subtract), (multiply) and / (divide).

PROGRAM:
    
#include <stdio.h>
#define SIZE 20
double eval (char exp[]){
    double op1 , op2 , stk[SIZE];
    char symb;
    int i,t;
    i = 0;
    t =-1;
    do{
        symb = exp[i];
        if(symb >= '0' && symb <= '9'){
            stk[++t] = symb -'0';
        }else{
            op2 = stk[t--];
            op1 = stk[t--];
            switch(symb){
                case'+' : stk[++t] = op1+op2;
                    break;
                case'-' : stk[++t] = op1-op2;
                    break;
                case'*' : stk[++t] = op1*op2;
                    break;
                case'/' : stk[++t] = op1/op2;
                    break;
            }
        }
    }while(exp[++i] != '\0');
    return(stk[t]);
}
int main(){
    char expr[SIZE];
    printf("Enter the expression: \n");
    scanf("%s",expr);
    printf("Result = %2f\n",eval(expr));
}

