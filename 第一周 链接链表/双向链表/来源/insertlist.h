#include"destroylist.h"
struct Student*insertlist(void){
struct Student*head,*p1,*p2;
head=creatlist();
printf("��ѡ����Ҫ��ӵ��ڼ����ڽ��");
    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
    p1=head;
    head=head->next;//��λ������ӵĽ��ĵ�ַ
    }
    p2=(struct Student*)malloc(LEN);//Ҫ��ӽ��Ŀռ�
    p1->next=p2;//ʹǰһ������ָ����ָ����ӵĽ��
    p2->last=p1;
    p2->next=head;//ʹ��ӵĽ��ָ��������һ�����
    head->last=p2;
}