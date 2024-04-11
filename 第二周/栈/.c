#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链栈节点结构体
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// 定义链栈结构体
typedef struct {
    StackNode* top;
} LinkedStack;

// 初始化链栈
void initStack(LinkedStack* stack) {
    stack->top = NULL;
}

// 判断链栈是否为空
bool isEmpty(LinkedStack* stack) {
    return stack->top == NULL;
}

// 入栈操作
void push(LinkedStack* stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈操作
int pop(LinkedStack* stack) {
    if (isEmpty(stack)) {
        printf("栈已空，无法出栈\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// 获取栈顶元素
int peek(LinkedStack* stack) {
    if (isEmpty(stack)) {
        printf("栈已空，无法获取栈顶元素\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// 判断是否为运算符
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 获取运算符优先级
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

// 执行运算
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
                printf("除数不能为0\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            printf("无效的运算符\n");
            exit(EXIT_FAILURE);
    }
}

// 计算表达式的值
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
                pop(&operatorStack); // 弹出左括号
            }
            i++;
        } else {
            printf("无效的字符：%c\n", expression[i]);
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
        printf("表达式格式错误\n");
        exit(EXIT_FAILURE);
    }

    return finalResult;
}

int main() {
    char expression[100];
    printf("请输入四则运算表达式（带括号）：\n");
    scanf("%s", expression);
    int result = evaluateExpression(expression);
    printf("计算结果为：%d\n", result);
    return 0;
}
