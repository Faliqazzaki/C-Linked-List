#include "head.h"
#include "malloc.h"
#include <stdio.h>
#include <unistd.h>

/* MODUL KONSTRUKTOR */
address alokasi(infotype X){
    // Deklarasi variabel lokal
    address P;

    //Begin
    P = (address)malloc(sizeof(NODE));
    if(P != Nil){
        P->info = X;
        P->next = Nil;
        return P;
    }
    printf("alokasi gagal!!!");
    return Nil;
}

/* MODUL KONTROL */
void addAwalNode(List *L, infotype X){
    // Deklarasi variabel lokal
    address tempList = (*L).First;

    // Begin
    address temp = alokasi(X); // alokasi memori
    if(temp == Nil){ 
        printf("alokasi gagal!!!"); // memberikan pesan error handling
        return;
    }

    temp->next = tempList; 
    (*L).First = temp;
}

void addAkhirNode(List *L, infotype X){
    // Deklarasi variabel lokal 
    address tempList = (*L).First;
    address temp = Nil;
    
    // Begin
    temp = alokasi(X);
    if(temp == Nil){
        printf("alokasi gagal!!!");
        return;
    }

    if(tempList == Nil){
        (*L).First = temp;
    }else{
        while(tempList->next != Nil){
            tempList = tempList->next;
        }
        tempList->next = temp;     
    }
}

void addTengahNode(List *L, infotype X, infotype Y){
    // Deklarasi variabel lokal
    address tempList = (*L).First;
    address P = Nil;
    
    // Begin
    P = alokasi(X);
    if(P == Nil){
        printf("alokasi gagal!!"); // memberikan pesan error handling
        return;
    }
    
    if(tempList == Nil){
        printf("tidak ada list....");
        return;
    }

   while(tempList != Nil){
        if(tempList->info == Y){
            P->next = tempList->next;
            tempList->next = P;
            return;
        }
        tempList = tempList->next;
   }

    printf("tidak ada node yang sesuai....\n");
    free(P);
}

void delAwalNode(List *L, infotype *X){
    // Deklarasi variabel lokal
    address tempList = (*L).First;

    // Begin
    if(tempList != Nil){
        (*X) = tempList->info;
        (*L).First = (*L).First->next;
        free(tempList);
    }else{
        printf("tidak ada list...\n");
    }
}

void delTengahNode(List *L, infotype X){
    // Deklarasi variabel lokal 
    address tempList = (*L).First;
    address P = Nil;

    // Begin
    while(tempList != Nil && tempList->info != X){
        P = tempList;
        tempList = tempList->next;
    }

    if(tempList == Nil){
        printf("tidak %d ada di list...\n", X);
        return;
    }

    if(P == Nil){
        (*L).First = (*L).First->next;
        free(tempList);
        return;
    }

    P->next = tempList->next;
    tempList->next = Nil;
    printf("node %d dari list sudah dihapus....\n", tempList->info);
    free(tempList);

}

void delAkhirNode(List *L, infotype *X){
    // Deklarasi variabel lokal
    address tempList = (*L).First;
    address P = Nil;

    // Begin
    if(tempList == Nil){
        printf("tidak ada list......\n");
        return;
    } 

    while(tempList->next != Nil){
        P = tempList;
        tempList = tempList->next;
    }

    if(P == Nil){
        (*L).First = Nil;
        (*X) = tempList->info;
        free(tempList);
        printf("Node sudah dihapus di list\n");
        return;
    }

    P->next = Nil;
    (*X) = tempList->info;
    free(tempList);
    printf("Node sudah dihapus di list\n");
}

void printList(List L){
    // Deklarasi variabel lokal
    address P = (L).First;

    // Begin
    if(P == Nil){
        printf("tidak ada list.....\n");
        return;
    }

    printf("LIST : ");
    while(P != Nil){
        printf("%d -> ", P->info);
        P = P->next;
        sleep(1);
    }
    printf("NULL\n");
    sleep(1);
    printf("Print Berhasil...\n");
    sleep(1);
}

int jumlahNodeList(List *L){
    // Deklarasi variabel lokal
    address P = (*L).First;
    int jumlahNode = 0;

    // Begin
    if(P == Nil){
        return jumlahNode;
    } 

    while(P != Nil){
        P = P->next;
        jumlahNode++;
    }
    return jumlahNode;
}