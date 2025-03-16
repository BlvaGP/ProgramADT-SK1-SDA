/*Nama  : Belva Abthal Hidayat*/
/*Nim   : 241524035*/
/*Absen : 5*/
/*Kelas : 1B - D4*/
#include "mahasiswa.h"

/*MODUL MODIFIKASI dari linear linked list*/
struct Node* createNode(mahasiswa info) {
    struct Node *n = (node*)malloc(sizeof(node));
    n->info = info;
    n->next = Nil;
    return n; 
}

void printList(node *head) {
    node *m = head;

    while (m != Nil) 
    {
        printf("[%s, %d] ", getNama(m->info), getNilai(m->info));
        m = next(m);
    }
    printf("\n");
}

void deleteDuplicateNama(node **head) {
    if (*head == Nil) {
        printf("Deletion tidak mungkin di lakukan lagi.");  //penyesuaian kode 
        return;                                             //dari pseudocode ADT Linked List, untuk memenuhi note quiz
    }

    node *curr = *head;
    node *prev, *temp;

    while (curr != Nil) 
    {
        prev = curr;
        temp = next(curr);

        while (temp != Nil)
        {
            if (strcmp(getNama(curr->info), getNama(temp->info)) == 0) {
                next(prev) = next(temp);
                free(getNama(temp->info));
                free(temp);
                temp = next(prev);
            } else {
                prev = temp;
                temp = next(prev);
            }
        }
        curr = next(curr);
    }
}

void DeAlokasi(node **head) { 
    node *temp;
    while (*head != Nil) 
    {
        temp = *head;
        *head = next(*head);
        free(temp);
    }
}

/*MODUL BARU*/
mahasiswa Mahasiswa(char* nama, int nilai) {
    mahasiswa m;
    m.nama = setNama(nama);
    m.nilai = setNilai(nilai);
    return m;
}

char* getNama(mahasiswa msh) {
    return msh.nama;
}

int getNilai(mahasiswa msh) {
    return msh.nilai;
}

char* setNama(char *nama) {
    char *newNama = strdup(nama);  
    if (newNama == NULL) {
        printf("Gagal mengalokasikan memori untuk nama.\n");
        return NULL;
    }
    return newNama;
}

int setNilai(int nilai) {
    return nilai;  
}

bool validList(char *nama, int nilai, node *head) {
    node *m = head;

    while (m != Nil)
    {
        if (strcmp(nama, m->info.nama) == 0 && nilai == m->info.nilai) {
            return true;
        }
        m = m->next;
    }
    return false;
}

void ascendingNama(node **head, node *info) {
    if (validList(getNama(info->info), getNilai(info->info), *head)) {
        printf("data [%s, %d] sudah ada, dan tidak akan ditambahkan.", getNama(info->info), getNilai(info->info));
        free(getNama(info->info));
        free(info);
        return;
    }

    if (*head == Nil || strcmp(getNama(info->info), getNama((*head)->info)) < 0) {
        next(info) = *head;
        *head = info;
        return;
    }

    node *temp = *head;
    while (next(temp) != Nil && strcmp(temp->next->info.nama, getNama(info->info)) < 0) {
        temp = next(temp);
    }

    next(info) = next(temp);
    next(temp) = info;
}

void descendingNilai(node **head) {
    if (*head == Nil || next(*head) == Nil)return;

    node *i, *j;
    char *tempNama;
    int tempNilai;

    for (i = *head ; next(i) != Nil ; i = next(i)) {
        for (j = *head ; next(j) != Nil ; j = next(j)) {
            if (getNilai(i->info) < getNilai(j->info)) {
                tempNama = i->info.nama;
                tempNilai = i->info.nilai;

                i->info.nama = j->info.nama;
                i->info.nilai = j->info.nilai;

                j->info.nama = tempNama;
                j->info.nilai = tempNilai;
            }
        }
    }
}

int countList(node *head) {
    node *m = head;
    int count = 0;
    while (m != Nil) 
    {
        count++;
        m = next(m);
    }
    return count;
}

void copyListL1toL2(node *L1, node **L2) {
    node *m = L1;
    while (m != Nil)
    {
        if (getNilai(m->info) > 70 && !validList(getNama(m->info), getNilai(m->info), *L2)) {
            node *newMhs = createNode(m->info);  
            if (newMhs != Nil) {
                ascendingNama(L2, newMhs); 
            }
        }
        m = next(m);
    }
}