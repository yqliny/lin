#include"tou.h"
int n=0;
struct Student*creatlist(void)
{
    struct Student*head;
    struct Student*p1,*p2;//����ͬ���͵�ָ��
    n=0;
    p1=p2=(struct Student*)malloc(LEN);//����һ���¿ռ�
    scanf("%ld,%f",&p1->num,&p1->score);
    head=NULL;
    while(p1->num!=0){//ֱ����������λ�ã�������num=0ʱ��������
        n=n+1;
        if(n==1)head=p1;
        else p2->next=p1;//ʹp2��ָ��Ľ���ָ����ָ��p1��λ��
        p2=p1;//ʹp2�ƶ���p1��λ��
        p1=(struct Student*)malloc(LEN);//p1���ƶ�����һ���
        scanf("%ld,%f",&p1->num,&p1->score);
    }
    p2->next=NULL;
    return(head);
}