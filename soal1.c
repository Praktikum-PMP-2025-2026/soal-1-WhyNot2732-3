/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : R. Damar Prawiro Kusumo Sudradjat (13224109)
 *   Nama File           : soal1.c
 *   Deskripsi           : 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int gerbong;
    struct Node *next;
}Node;

int isEmpty(Node *head);

int main(){
    int N;
    char input[100];
    char* tok;
    int findId;
    int j, op;
    Node *head = NULL;
    Node *temp = NULL;
    Node *prev = NULL;
    fgets(input, 100, stdin);
    tok = strtok(input, " ");
    N = atoi(tok);

    for (int i = 0; i < N; i++)
    {
        tok = strtok(NULL, " ");
        op = atoi(tok);
        if (op == 1) // PUSH FRONT
        {
            Node *newNode = (Node*)malloc(sizeof(Node));
            tok = strtok(NULL, " ");
            newNode->gerbong = atoi(tok);
            if (isEmpty(head))
            {
                head = newNode;
                newNode->next = NULL;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }else if (op == 2){ // PUSH BACK
            Node *newNode = (Node*)malloc(sizeof(Node));
            tok = strtok(NULL, " ");
            newNode->gerbong = atoi(tok);
            if (isEmpty(head))
            {
                head = newNode;
            }else{
                temp = head;
                while (temp != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            newNode->next = NULL;
        } else if (op == 3){
            tok = strtok(NULL, " ");
            findId = atoi(tok);
            if (!isEmpty(head)){
                Node *temp1 = head;
                if ((temp1 != NULL) && (temp1->gerbong == findId)){
                    head = temp1->next;
                    free(temp1);
                } else{
                    while ((temp1 != NULL) && (temp1->gerbong != findId)){
                        prev = temp1;
                        temp1 = temp1->next;
                    }
                    if (temp1 != NULL){
                        prev->next = temp1->next;
                        free(temp1);
                    }
                }   
            }
        } else if (op == 4){
            tok = strtok(NULL, " ");
            findId = atoi(tok);
            j = 0;
            temp = head;
            while ((temp != NULL) && (temp->gerbong != findId)){
                temp = temp->next;
                j++;
            }
            if (temp == NULL){
                printf("NOT FOUND\n");
            } else{
                printf("FOUND %d\n", j);
            }
        }
    }
    
    printf("LIST ");
    if (isEmpty(head)){
        printf("EMPTY\n");
    } else{
        temp = head;
        while (temp != NULL){
            printf("%d", temp->gerbong);
            temp = temp->next;
            if (temp != NULL){
                printf(" ");
            }
        }
        printf("\n");
    }
    


    return 0;
}

int isEmpty(Node *head){
    return head == NULL;
}
