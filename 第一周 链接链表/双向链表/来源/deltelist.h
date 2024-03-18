#include"creatlist.h"
struct Student*deletelist(){
    struct Student*head;
    struct Student*p1,*p2;
    head=creatlist();
    printf("请选择你要删除第几个结点");
    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
    p1=head;
    head=head->next;//定位到被删的结点的地址
    }
p2=head->next;
p1->next=head->next;//让被删掉的那个结点之前的结点指向被删的下一个
p2->last=p1;
free(head);
}