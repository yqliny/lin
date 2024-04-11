#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ������ջ�ڵ�ṹ��
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// ������ջ�ṹ��
typedef struct {
    StackNode* top;
} LinkedStack;

// ��ʼ����ջ
void initStack(LinkedStack* stack) {
    stack->top = NULL;
}

// �ж���ջ�Ƿ�Ϊ��
bool isEmpty(LinkedStack* stack) {
    return stack->top == NULL;
}

// ��ջ����
void push(LinkedStack* stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// ��ջ����
int pop(LinkedStack* stack) {
    if (isEmpty(stack)) {
        printf("ջ�ѿգ��޷���ջ\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// ��ȡջ��Ԫ��
int peek(LinkedStack* stack) {
    if (isEmpty(stack)) {
        printf("ջ�ѿգ��޷���ȡջ��Ԫ��\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// �ж��Ƿ�Ϊ�����
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// ��ȡ��������ȼ�
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// ִ������
int executeOperation(int operand1, int operand2, char op) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("��������Ϊ0\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            printf("��Ч�������\n");
            exit(EXIT_FAILURE);
    }
}

// ������ʽ��ֵ
int evaluateExpression(char* expression) {
    LinkedStack operandStack;
    LinkedStack operatorStack;
    initStack(&operandStack);
    initStack(&operatorStack);

    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == ' ') {
            i++;
            continue;
        }
        if (isdigit(expression[i])) {
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&operandStack, operand);
        } else if (isOperator(expression[i])) {
            while (!isEmpty(&operatorStack) && precedence(peek(&operatorStack)) >= precedence(expression[i])) {
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                char op = pop(&operatorStack);
                int result = executeOperation(operand1, operand2, op);
                push(&operandStack, result);
            }
            push(&operatorStack, expression[i]);
            i++;
        } else if (expression[i] == '(') {
            push(&operatorStack, expression[i]);
            i++;
        } else if (expression[i] == ')') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != '(') {
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                char op = pop(&operatorStack);
                int result = executeOperation(operand1, operand2, op);
                push(&operandStack, result);
            }
            if (!isEmpty(&operatorStack) && peek(&operatorStack) == '(') {
                pop(&operatorStack); // ����������
            }
            i++;
        } else {
            printf("��Ч���ַ���%c\n", expression[i]);
            exit(EXIT_FAILURE);
        }
    }

    while (!isEmpty(&operatorStack)) {
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);
        char op = pop(&operatorStack);
        int result = executeOperation(operand1, operand2, op);
        push(&operandStack, result);
    }

    int finalResult = pop(&operandStack);
    if (!isEmpty(&operandStack)) {
        printf("���ʽ��ʽ����\n");
        exit(EXIT_FAILURE);
    }

    return finalResult;
}

int main() {
    char expression[100];
    printf("����������������ʽ�������ţ���\n");
    scanf("%s", expression);
    int result = evaluateExpression(expression);
    printf("������Ϊ��%d\n", result);
    return 0;
}
