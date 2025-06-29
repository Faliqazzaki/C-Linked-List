#include "head.h"
#include "malloc.h"

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

    
}