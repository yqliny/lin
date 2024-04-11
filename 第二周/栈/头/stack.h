#ifndef STACK_H
#define STACK_H

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
void initStack(LinkedStack* stack);

// 判断链栈是否为空
bool isEmpty(LinkedStack* stack);

// 入栈操作
void push(LinkedStack* stack, int data);

// 出栈操作
int pop(LinkedStack* stack);

// 获取栈顶元素
int peek(LinkedStack* stack);

#endif /* STACK_H */