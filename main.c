/*Nama  : Belva Abthal Hidayat*/
/*Nim   : 241524035*/
/*Absen : 5*/
/*Kelas : 1B - D4*/

#include "mahasiswa.h"

int main() {
    node *L1 = NULL;
    node *L2 = NULL;

    ascendingNama(&L1, createNode(Mahasiswa("belva", 70)));
    ascendingNama(&L1, createNode(Mahasiswa("ihsan", 80)));
    ascendingNama(&L1, createNode(Mahasiswa("azzar", 90)));
    ascendingNama(&L1, createNode(Mahasiswa("lukman", 95)));
    ascendingNama(&L1, createNode(Mahasiswa("zein", 100)));

    printf("list L1:\n");
    printList(L1);

    descendingNilai(&L1);
    printf("\nlist L1 setelah sorting decending berdasarkan nilai:\n");
    printList(L1);

    printf("\njumlah elemen di L1: %d\n", countList(L1));
    
    copyListL1toL2(L1, &L2);
    descendingNilai(&L2);
    printf("\nlist L2 setelah melakukan copy dari L1 (hanya nilai > 70): \n");
    printList(L2);

    deleteDuplicateNama(&L2);
    printf("\nList L2 setelah menghapus duplikat  nama:\n");
    printList(L2);

    DeAlokasi(&L1);
    DeAlokasi(&L2);
}