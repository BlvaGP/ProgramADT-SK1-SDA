/*Nama  : Belva Abthal Hidayat*/
/*Nim   : 241524035*/
/*Absen : 5*/
/*Kelas : 1B - D4*/

#ifndef MAHASISWA_H
#define MAHASISWA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define next(P) (P)->next
#define Nil NULL

typedef struct mhs
{
    char *nama;
    int nilai;
} mahasiswa;

typedef struct Node{
    mahasiswa info;
    struct Node *next;
} node;

/*MODUL MODIFIKASI dari linear linked list*/
struct Node* createNode(mahasiswa info);
void printList(node *head);
void deleteDuplicateNama(node **head);
void DeAlokasi(node **head);

/*MODUL BARU*/
mahasiswa Mahasiswa(char* nama, int nilai);
char* getNama(mahasiswa mhs);
int getNilai(mahasiswa mhs);
char* setNama(char *nama);
int setNilai(int nilai);
bool validList(char *nama, int nilai, node *head);
void ascendingNama(node **head, node *info);
void descendingNilai(node **head);
int countList(node *head);
void copyListL1toL2(node *L1, node **L2);

#endif