#include <stdio.h>
#include <string.h>

struct information{
    int id;
    char name[50];
    int age;
    char phone[20];
};
struct information studen[50];
void arrStuden();
void arrStudenPrint();
int main(void){
    int pos;

    strcpy(studen[0].name, "Nguyen van A"); studen[0].age = 18; strcpy(studen[0].phone, "84+ 784 283 123");
    strcpy(studen[1].name, "Nguyen van B"); studen[1].age = 18; strcpy(studen[1].phone, "84+ 231 653 324");
    strcpy(studen[2].name, "Nguyen van C"); studen[2].age = 19; strcpy(studen[2].phone, "84+ 978 435 342");
    strcpy(studen[3].name, "Nguyen van D"); studen[3].age = 20; strcpy(studen[3].phone, "84+ 765 254 456");
    strcpy(studen[4].name, "Nguyen van E"); studen[4].age = 22; strcpy(studen[4].phone, "84+ 321 345 875");
    int i = 0;
    while(studen[i].name[0] != '\0') {
        studen[i].id = i + 1;
        i++;
    }

    do {
        printf("Enter the position element to change: ");
        scanf("%d", &pos);
    }while(pos < 1 || pos > i);
    fflush(stdin);
    arrStuden(studen, pos);
    arrStudenPrint(studen);

}

void arrStuden(struct information studen[], int pos){
    printf("Enter the Name to change: ");
    fgets(studen[pos].name, sizeof(studen[pos].name), stdin);
    studen[pos].name[strlen(studen[pos].name) - 1] = '\0';
    printf("Enter the age to change: ");
    scanf("%d", &studen[pos].age);
    fflush(stdin);
    printf("Enter the phone to change: ");
    fgets(studen[pos].phone, sizeof(studen[pos].phone), stdin);
    studen[pos].phone[strlen(studen[pos].phone) - 1] = '\0';
}

void arrStudenPrint(struct information studen[]){
    int i = 0;
    while(studen[i].name[0] != '\0') {
        printf("\n");
        printf("%d :", i + 1);
        printf("ID: %d\t", studen[i].id);
        printf("Name: %s\t", studen[i].name);
        printf("Age: %d\t", studen[i].age);
        printf("Phone %s \n", studen[i].phone);
        i++;
    }
}
