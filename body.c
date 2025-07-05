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
    printf("Node berhasil ditambahkan");
    sleep(1);
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
    printf("Node berhasil ditambahkan");
    sleep(1);
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
            printf("Node berhasil ditambahkan");
            sleep(1);
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
        printf("Node berhasil dihapus");
        sleep(1);
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
        printf("Node berhasil dihapus");
        sleep(1);
        return;
    }

    P->next = tempList->next;
    tempList->next = Nil;
    printf("node %d dari list sudah dihapus....\n", tempList->info);
    sleep(1);
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
        sleep(1);
        return;
    }

    P->next = Nil;
    (*X) = tempList->info;
    free(tempList);
    printf("Node sudah dihapus di list\n");
    sleep(1);
}

void delList(List *L){
    // Deklarasi variabel lokal
    address P = (*L).First;

    // Begin
    if(P == Nil){
        printf("tidak ada list...");
        return;
    }

    while(P != Nil){
        (*L).First = P->next;
        free(P);
        P = (*L).First;        
    }

    (*L).First = Nil;
    printf("List berhasil dihapus...\n");
}

/* MODUL NON KONTROL */
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
    }
    printf("NULL\n");
}

int countNodeList(List L){
    // Deklarasi variabel lokal
    address P = (L).First;
    int jumlahNode = 0;

    // Begin
    while(P != Nil){
        P = P->next;
        jumlahNode++;
    }
    return jumlahNode;
}

void searchItem(List L, infotype X){
    // Deklarasi variabel lokal
    address P = (L).First;
    int i = -1;

    // Begin
    i = 0;
    while(P != Nil && P->info != X){
        P = P->next;
        i++;   
    }
    
    if(P == Nil){
        printf("tidak ada nilai %d di list\n", X);
        return;
    }
    printf("data %d ditemukan di index %d\n", P->info, i);
}

// MODUL INTERFACE 
void programLinkedList(){
    // Deklarasi variabel lokal
    List head;
    head.First = Nil;
    int jumlah;
    int choice;
    int info;
    int tempInfo;
    int infoNode;
    char subChoice;

    // Begin
    for(;;){
        choice = 0;
        system("cls");
        bannerTemplate();
        printList(head);
        printf("-----------------------------\n");
        printf("1. Tambah list\n");
        printf("2. Hapus list\n");
        printf("3. Search list\n");
        printf("4. Hitung list\n");
        printf("5. Keluar\n");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &choice);
        if(choice == 1){
            system("cls");
            bannerTemplate();
            choice = 0;
            printf("1. Tambah node di awal\n");
            printf("2. Tambah node di tengah\n");
            printf("3. Tambah node di akhir\n");
            printf("masukkan pilihan anda : ");
            scanf("%d", &choice);
            if(choice == 1){
                printf("Masukkan Info ke node yang akan ditambahkan : ");
                scanf("%d", &info);
                addAwalNode(&head, info);
            }else if(choice == 2){
                printf("Masukkan info ke node yang akan ditambahkan : ");
                scanf("%d", &info);
                printf("Masukkan node sebelah dari node yang akan ditambahkan : ");
                scanf("%d", &tempInfo);
                addTengahNode(&head, info, tempInfo);
            }else if(choice == 3){
                printf("Masukkan info ke node yang akan ditambahkan : ");
                scanf("%d", &info);
                addAkhirNode(&head, info);
            }else{
                printf("pilihan tidak valid.....");
            }
        }else if(choice == 2){
            system("cls"); 
            bannerTemplate();
            choice = 0;
            printf("1. Hapus node awal\n");
            printf("2. Hapus node tengah\n");
            printf("3. Hapus node akhir\n");
            printf("4. Hapus List\n");
            printf("Masukkan pilihan anda : ");
            scanf("%d", &choice);
            if(choice == 1){
                delAwalNode(&head, &infoNode);
                printf("data %d telah dihapus dari list...", infoNode);
                sleep(1);
            }else if(choice == 2){
                printf("Masukkan node yang akan dihapus : ");
                scanf("%d", &infoNode);
                delTengahNode(&head, infoNode);
            }else if(choice == 3){
                delAkhirNode(&head, &infoNode);
                printf("data %d telah dihapus dari list...", infoNode);
                sleep(1);
            }else if(choice == 4){
                delList(&head);
                sleep(1);
            }else{
                printf("pilihan tidak valid.....");
                sleep(2);
            }
        }else if(choice == 3){
            for(;;){
                printf("Masukkan node yang akan di cari di list : ");
                scanf("%d", &infoNode);
                searchItem(head, infoNode);
                printf("ingin mencari lagi ? (Y/N ) : ");
                while (getchar() != '\n');
                scanf("%c", &subChoice);
                if(subChoice == 'Y'){
                    system("cls");
                    bannerTemplate();
                }else if(subChoice == 'N'){
                    break;
                }
            }
        }else if(choice == 4){
            system("cls");
            bannerTemplate();
            jumlah = countNodeList(head);
            printf("Jumlah Node saat ini : %d \n", jumlah);
            sleep(1);
            system("pause");  
        }else if( choice == 5){
            printf("terimakasih sudah menggunakan program ini....");
            break;
        }
    }
}

void bannerTemplate(){
    printf("-----------------------------\n");
    printf("   LINKED LIST GENERATOR\n");
    printf("-----------------------------\n");
}