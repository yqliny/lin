#include"creatlist.h"
struct Student*deletelist(){
    struct Student*head;
    struct Student*p1;
    head=creatlist();
    printf("��ѡ����Ҫɾ���ڼ�����=���");
    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
    p1=head;
    head=head->next;//��λ����ɾ�Ľ��ĵ�ַ
    }
p1->next=head->next;//�ñ�ɾ�����Ǹ����֮ǰ�Ľ��ָ��ɾ����һ��
free(head);
}
