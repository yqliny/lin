#include"insertlist.h"
int main()
{
    printf("请选择你要进行的操作 1.创建列表\n2.销毁列表\n3插入结点\n4.删除结点\n");
    int a;
    scanf("%d",&a);
    while(a>4){
    switch(a){
        case 1:creatlist();
        case 2:destroylist();
        case 3:insertlist();
        case 4:deletelist();
        default:printf("输入有误，请重新选择");
    }
    }
    return 0;
};