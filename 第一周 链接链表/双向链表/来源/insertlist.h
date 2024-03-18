#include"destroylist.h"
struct Student*insertlist(void){
struct Student*head,*p1,*p2;
head=creatlist();
printf("请选择你要添加到第几个节结点");
    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
    p1=head;
    head=head->next;//定位到被添加的结点的地址
    }
    p2=(struct Student*)malloc(LEN);//要添加结点的空间
    p1->next=p2;//使前一个结点的指针域指向添加的结点
    p2->last=p1;
    p2->next=head;//使添加的结点指向本来的那一个结点
    head->last=p2;
}