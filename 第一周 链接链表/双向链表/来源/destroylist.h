#include"deltelist.h"
struct Student*destroylist(void){
    struct Student*head;
    head=creatlist();
    struct Student*p1;
    p1=head;
    while(head->next!=NULL){
        head=head->next;
        free(p1);
        p1=head;
    }
    free(head);

}