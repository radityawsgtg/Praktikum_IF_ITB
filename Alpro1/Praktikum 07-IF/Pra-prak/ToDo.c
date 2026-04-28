#include<stdio.h>
#include"ToDo.h"


void createList(ToDoList *T, int capacity){
    T->tasksList = (Task *)malloc(capacity * sizeof(Task));
    T->capacity = capacity;
    T->nEff = 0;
}
/* I.S. T sembarang, capacity > 0 */
/* F.S. Terbentuk to-do list T kosong dengan kapasitas capacity */

void dealocateList(ToDoList *T){
    free(T->tasksList);
    T->capacity =0;
    T->nEff = 0;
}
/* I.S. T terdefinisi */
/* F.S. tasksList T dikembalikan ke sistem, T.capacity=0, T.nEff=0 */

int getNumOfTasks(ToDoList T){
    return T.nEff;
}
/* Mengembalikan banyaknya task efektif dalam to-do list */
/* Mengembalikan 0 jika list kosong */

int getNumOfCompletedTasks(ToDoList T){
    int count =0;
    if (T.nEff == 0)
    {
        return 0;
    }
    
    for (int i = 0; i < T.nEff; i++)
    {
        if (T.tasksList[i].status == true)
        {
            count++;
        }
        
    }
    return count;
    
}
/* Mengembalikan banyaknya task yang sudah selesai dalam to-do list */
/* Mengembalikan 0 jika list kosong */

boolean isEmpty(ToDoList T){
    if (T.nEff == 0)
    {
        return true;
    }
    return false;
    
}
/* Mengirimkan true jika list T kosong, false jika tidak */

boolean isFull(ToDoList T){
    if (T.nEff >= T.capacity)
    {
        return true;
    }
    return false;
    
}
/* Mengirimkan true jika list T penuh, false jika tidak */

void addNewTask(ToDoList *T, char *taskName){
    if (!isFull(*T))
    {
        T->tasksList[T->nEff].name = (char *)malloc((strlen(taskName) + 1) * sizeof(char)); /*ini ga paham kenapa harus gini*/
        strcpy(T->tasksList[T->nEff].name, taskName);
        T->tasksList[T->nEff].status =  false;
        T->nEff++;
    }
    
}
/* Proses: Menambahkan task baru dengan nama salinan dari taskName pada akhir list */
/* I.S. List T tidak penuh, taskName terdefinisi */
/* F.S. Task baru dengan status belum selesai ditambahkan sebagai elemen terakhir T */

void removeTask(ToDoList *T, int idx) {
    if (!isEmpty(*T)) {
        free(T->tasksList[idx].name);
        for (int i = idx; i < T->nEff - 1; i++) {
            T->tasksList[i] = T->tasksList[i + 1];
        }
        T->nEff--;
    }
}
/* Proses: Menghapus task pada indeks idx, elemen setelahnya digeser ke kiri */
/* I.S. List T tidak kosong, 0 <= idx <= T.nEff-1 */
/* F.S. Task pada indeks idx terhapus, T.nEff berkurang satu */

void markTaskAsCompleted(ToDoList *T, int idx){
    if (!isEmpty(*T))
    {
        T->tasksList[idx].status = true;
    }
    
}
/* Proses: Mengubah status task pada indeks idx menjadi sudah selesai */
/* I.S. List T tidak kosong, 0 <= idx <= T.nEff-1 */
/* F.S. T.tasksList[idx].status = true */

int getProgress(ToDoList T){
    if (T.nEff > 0)
    {
        return (getNumOfCompletedTasks(T) * 100 )/T.nEff;
    }
    
}
/* Mengembalikan persentase task yang sudah selesai dari keseluruhan task */
/* Persentase dalam bentuk integer, angka di belakang koma di-truncate */
/* Prekondisi: T.nEff > 0 */

void expandList(ToDoList *T, int num){
    T->capacity += num;
    T->tasksList = (Task *)realloc(T->tasksList, T->capacity * sizeof(Task));
}
/* Proses: Menambahkan capacity T sebanyak num */
/* I.S. T sudah terdefinisi, num > 0 */
/* F.S. Ukuran capacity bertambah sebanyak num */

void shrinkList(ToDoList *T, int num){
    T->capacity -= num;
    T->tasksList = (Task *)realloc(T->tasksList, T->capacity * sizeof(Task));
}
/* Proses: Mengurangi capacity T sebanyak num */
/* I.S. T sudah terdefinisi, capacity > num, nEff < capacity - num */
/* F.S. Ukuran capacity berkurang sebanyak num */
