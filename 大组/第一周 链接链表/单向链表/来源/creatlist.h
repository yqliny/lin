#include"tou.h"
int n=0;
struct Student*creatlist(void)
{
    struct Student*head;
    struct Student*p1,*p2;//定义同类型的指针
    n=0;
    p1=p2=(struct Student*)malloc(LEN);//开辟一个新空间
    scanf("%ld,%f",&p1->num,&p1->score);
    head=NULL;
    while(p1->num!=0){//直到输完数据位置，当输入num=0时结束运行
        n=n+1;
        if(n==1)head=p1;
        else p2->next=p1;//使p2所指向的结点的指针域指向p1的位置
        p2=p1;//使p2移动到p1的位置
        p1=(struct Student*)malloc(LEN);//p1再移动到下一结点
        scanf("%ld,%f",&p1->num,&p1->score);
    }
    p2->next=NULL;
    return(head);
}