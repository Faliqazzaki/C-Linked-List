#ifndef HEAD_H
#define HEAD_h

#define Nil NULL

/*
INFORMASI JENIS MODUL
MODUL KONSTRUKTOR : sebuah jenis modul untuk menyusun atau membangun sebuah node 
MODUL KONTROL : sebuah jenis modul yang bertujuan untuk mengendalikan linked list
MODUL NON KONTROL : Sebuah jenis modul yang berfungsi untuk hal lain yang tidak berpengaruh terhadap pengendalian linked list
MODUL INTERFACE : Sebuah jenis modul yang berfungsi untuk menampilkan interface dari program linked list
*/

// DEKLARASI TIPE DATA
typedef int infotype; 
typedef struct NODE* address;

// NODE LINKED LIST
typedef struct NODE{
    infotype info;
    address next;
}NODE;

// POINTER LIST
typedef struct {
    address First;
}List;

/* MODUL KONSTRUKTOR */
// IS : NODE program tidak ada atau belum dialokasikan
// FS : NODE baru sudah dibuat dan dialokasikan dengan nilai X
address alokasi(infotype X);


/* MODUL KONTROL */
// IS : List bisa kosong atau berisi beberapa node
// FS : Sebuah node baru dengan nilai X ditambahkan di awal list
void addAwalNode(List *L, infotype X);

// IS : List bisa kosong atau berisi beberapa node
// FS : Sebuah node baru dengan nilai X ditambahkan di akhir list
void addAkhirNode(List *L, infotype X);

// IS : List berisi satu atau lebih node
// FS : Node baru dengan nilai Y ditambahkan setelah node dengan nilai X
void addTengahNode(List *L, infotype X, infotype Y);

// IS : List minimal memiliki satu node
// FS : Node pertama dihapus dari list dan nilainya disimpan dalam X
void delAwalNode(List *L, infotype *X);

// IS : List minimal memiliki dua node, dan terdapat node dengan nilai Y
// FS : Node setelah node dengan nilai X dihapus dan nilainya disimpan dalam Y
void delTengahNode(List *L, infotype X);

// IS : List minimal memiliki satu node
// FS : Node terakhir dihapus dari list dan nilainya disimpan dalam X
void delAkhirNode(List *L, infotype *X);

// IS : List ada
// FS : Seluruh node di list sudah dihapus
void delList(List *L);


/* MODUL NON KONTROL */
// IS : List dalam kondisi apapun (kosong atau tidak)
// FS : Seluruh elemen list ditampilkan ke layar
void printList(List L);

// IS : List bisa ada atau tidak ada
// FS : Mengembalika nilai dari jumlah node di list 
int countNodeList(List L);

// IS : User tidak bisa mencari sebuah item di list
// FS : User dapat mencari item di list
void searchItem(List L, infotype X);


/* MODUL INTERFACE */
// IS : User tidak bisa membuat list
// FS : User bisa membuat list
void programLinkedList();

// IS : Tidak ada banner template untuk menampilkan linked list
// FS : Terdapat sebuah banner bertuliskan linked list dengan desain sedemikian rupa
void bannerTemplate();


#endif