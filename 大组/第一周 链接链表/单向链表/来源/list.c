#include"insertlist.h"
int main()
{
    printf("��ѡ����Ҫ���еĲ��� 1.�����б�\n2.�����б�\n3������\n4.ɾ�����\n");
    int a;
    scanf("%d",&a);
    while(a>4){
    switch(a){
        case 1:creatlist();
        case 2:destroylist();
        case 3:insertlist();
        case 4:deletelist();
        default:printf("��������������ѡ��");
    }
    }
    return 0;
};