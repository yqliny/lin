#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student{
    long num;
    float score;
    struct Student *next;
    struct Student *last;
};
struct Student*creatlist(void);
struct Student*destroylist(void);
struct Student*deletelist();
struct Student*insertlist();