#include <stdio.h>
#include "head.h"

int main(){
    List head;
    head.First = Nil;
    int jumlah;
    int i = 10;

    while(i > 0){
        addAwalNode(&head, i);
        i--;
    }

    jumlah = jumlahNodeList(&head);
    // delAwalNode(&head, &temp);
    printList(head);
    printf("Jumlah node : %d", jumlah);
    // printf("data %d telah dihapus", temp);
    return 0;
}