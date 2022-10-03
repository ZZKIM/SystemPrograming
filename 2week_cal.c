#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int sub(int, int);
int multiply(int, int);
int divide(int, int);

struct CalculatorNode {
    int a;
    int b;
    char name[20];
    int(*fptr)(int, int);
    struct CalculatorNode* next;

};
struct CalculatorNode* createNode(char name[], int a, int b)
{
    struct CalculatorNode* ptr;
    ptr = (struct CalculatorNode*)malloc(sizeof(struct CalculatorNode));
    ptr->a = a;
    ptr->b = b;
    strcpy(ptr->name, name);
    ptr->next = NULL;

    return ptr;
}
void cal(struct CalculatorNode* first) {

    while (first != NULL) {
        if (strcmp("add", first->name) == 0)
            first->fptr = add(first->a, first->b);
        else if(strcmp("sub", first->name) == 0)
            first->fptr = sub(first->a, first->b);
        else if (strcmp("multiply", first->name) == 0)
            first->fptr = multiply(first->a, first->b);
        else if (strcmp("divide", first->name) == 0)
            first->fptr = divide(first->a, first->b);

        first = first->next;
    }

}
void printData(struct CalculatorNode* first)
{
    while (first != NULL) {
        printf("%s %d %d \n", first->name, first->a, first->b);
        first = first->next;
    }
}
void printDataResult(struct CalculatorNode* first)
{
    while (first != NULL) {
        printf("%s %d %d %d \n", first->name, first->a, first->b, *(first->fptr));
        first = first->next;
    }
}
void insertData(struct CalculatorNode** first, char name[], int a, int b)
{
    struct CalculatorNode* tmp;
    tmp = createNode(name, a, b);

    tmp->next = *first;
    *first = tmp;

    //printData(*first);
}
int main(void) {

    struct CalculatorNode* top;
    struct CalculatorNode* tmp;

    top = createNode("add", 1, 2);
    tmp = createNode("sub", 10, 1);

    top->next = tmp;

    insertData(&top, "multiply", 5, 4);
    insertData(&top, "divide", 10, 5);

    printf("������� ������ ��� ��带 ����մϴ�. \n");

    printData(top);

    printf("������� ������ ��� ��带 ����� ����մϴ�. \n");
    cal(top);
    printDataResult(top);

    top->next = NULL;

    printf("���α׷��� �����մϴ�.");

    exit(0);

    return 0;
}
int add(int a, int b)
{
    int result;
    result = a + b;
    return result;
}
int sub(int a, int b)
{
    int result;
    result = a - b;
    return result;
}
int multiply(int a, int b)
{
    int result;
    result = a * b;
    return result;
}
int divide(int a, int b)
{
    int result;
    result = a / b;
    return result;
}