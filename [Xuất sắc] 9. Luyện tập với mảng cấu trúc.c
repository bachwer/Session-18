#include <stdio.h>
#include <string.h>

struct information {
    int id;
    char name[50];
    float price;
};

struct information dish[100];

void dishPrint();
void dishAdd();
void dishChange();
void dishDelete();
void dishArrangeUp();
void dishArrangeDown();
void dishFindLS();
void dishFindBS();
void dishApUpName();


int main(void) {
    int dishnum = 0;
    int menu, menu2;
    char menu1;
    int pos;
    char character[50];

    strcpy(dish[0].name, "Pho ga"); dish[0].price = 35.00;
    strcpy(dish[1].name, "Pho bo"); dish[1].price = 32.99;
    strcpy(dish[2].name, "Pho ngan"); dish[2].price = 41.23;
    strcpy(dish[3].name, "Pho de"); dish[3].price = 31.00;
    strcpy(dish[4].name, "Pho vit"); dish[4].price = 32.12;
    int i = 0;
    while(dish[i].name[0] != '\0') {
        dish[i].id = i + 1;
        dishnum++;
        i++;
    }

    menu:
    do {
        printf("\n");
        printf("1.In gia tri cac phan tu co trong menu mon an theo dang\n");
        printf("2.Them mot phan tu vao vi tri chi dinh.\n");
        printf("3.Sua mot phan tu vao vi tri chi dinh.\n");
        printf("4.Xoa mot phan tu o vi tri chi dinh.\n");
        printf("5.Sap xep cac phan tu (Khi lua chon menu cha thi hien thi menu con).\n");
        printf("6.Tim kiem phan tu theo name nhap vao\n");
        printf("7.Thoat\n");
        printf("Enter your number: \n");
        scanf("%d", &menu);
        fflush(stdin);
        switch (menu) {
            case 1:
                dishPrint(dish);
                goto menu2;
                break;
            case 2:
                do{
                    printf("Nhap vi tri can them: ");
                    scanf("%d", &pos);
                    fflush(stdin);
                    if(pos > dishnum  || pos < 0){
                        printf("moi nhap lai: \n");
                    }
                }while(pos > dishnum  || pos < 0);
                pos--;
                dishAdd(dish, pos, dishnum);
                dishnum++;
                printf("\t---Sucssec----\n");
                goto menu2;
                break;
            case 3:
                do{
                    printf("Nhap vi tri can Sua: ");
                    scanf("%d", &pos);
                    fflush(stdin);
                    if(pos > dishnum  || pos < 0){
                        printf("moi nhap lai: \n");
                    }
                }while(pos > dishnum  || pos < 0);
                pos--;
                dishChange(dish, pos);
                printf("\t---Sucssec----\n");
                goto menu2;
                break;
            case 4:
                do{
                    printf("Nhap vi tri can Xoa: ");
                    scanf("%d", &pos);
                    fflush(stdin);
                    if(pos > dishnum  || pos < 0){
                        printf("moi nhap lai: \n");
                    }
                }while(pos > dishnum  || pos < 0);
                pos--;
                dishDelete(dish, pos, dishnum);
                printf("\t---Sucssec----\n");
                goto menu2;
                break;
            case 5:
                do {
                    printf("\n");
                    printf("a.Giam dan theo price\n");
                    printf("B.Giam dan theo price\n");
                    printf("Enter your choice: ");
                    scanf("%c", &menu1);
                    fflush(stdin);
                }while (menu1 != 'a' && menu1 != 'A' && menu1 != 'b' && menu1 != 'B');
                if(menu1 == 'a' || menu1 == 'A') {
                    dishArrangeUp(dish, dishnum);
                }else {
                    dishArrangeDown(dish, dishnum);
                }
                printf("\t---Sucssec----\n");
                goto menu2;
                break;
            case 6:
                do {
                    printf("a.Tim khiem tuyen tinh\n");
                    printf("B.Tim khiem nhi phan\n");
                    printf("Enter your choice: ");
                    scanf("%c", &menu1);
                    fflush(stdin);
                }while (menu1 != 'a' && menu1 != 'A' && menu1 != 'b' && menu1 != 'B');
            printf("Nhap ten can tim: ");
            fgets(character, sizeof(character), stdin);
            character[strlen(character)-1] = '\0';
            if(menu1 == 'a' || menu1 == 'A') {
                dishFindLS(dish, dishnum, character);
            }else {
                do {
                    printf("a.Xap xep lai va tim khiem(theo ten)\n");
                    printf(" B.Back to menu\n");
                    printf("Enter your choice: ");
                    scanf("%c", &menu1);
                }while (menu1 != 'a' && menu1 != 'A' && menu1 != 'b' && menu1 != 'B');
                if(menu1 == 'a' || menu1 == 'A') {
                    dishApUpName(dish, dishnum);
                    dishFindBS(dish, dishnum, character);
                }else {
                    goto menu;
                }
            }
                goto menu2;
                break;
                default:
                    printf("invalid\n");
                    menu2:
                    printf("\n");
                    menu1 = 0;
                    printf("1.Back to menu\n");
                    printf("2.Exit\n");
                    do{
                        scanf("%d", &menu2);
                    }while(menu1 > 2 || menu2 < 0);
                            if(menu2 == 1){
                                goto menu;
                            }else {
                                return 0;
                            }
                    break;
        }
    }while(menu !=  7);
}


void dishPrint(struct information dish[]){
    int i = 0;
    while(dish[i].name[0] != '\0') {
        printf("%d Dish - ", i + 1);
        printf("ID: %d\t", dish[i].id);
        printf("Name: %s\t", dish[i].name);
        printf("Price: %.2f $\n", dish[i].price);
        i++;
    }
}

void dishAdd(struct information dish[], int pos, int dishnum) {
    for(int i = dishnum; i >= pos ; i--) {
        dish[i + 1].id = dish[i].id;
        strcpy(dish[i + 1].name, dish[i].name);
        dish[i + 1].price = dish[i].price;
    }
    dish[pos].id = dishnum + 1;
    fflush(stdin);
    printf("Nhap ten mon moi: ");
    fgets(dish[pos].name, sizeof(dish[pos].name), stdin);
    dish[pos].name[strlen(dish[pos].name) - 1] = '\0';
    fflush(stdin);
    printf("nhap gia tien: ");
    scanf("%f", &dish[pos].price);
}

void dishChange(struct information dish[], int pos) {
    fflush(stdin);
    printf("Nhap ten mon moi: ");
    fgets(dish[pos].name, sizeof(dish[pos].name), stdin);
    dish[pos].name[strlen(dish[pos].name) - 1] = '\0';
    fflush(stdin);
    printf("nhap gia tien: ");
    scanf("%f", &dish[pos].price);

}

void dishDelete(struct information dish[], int pos, int dishnum) {
    for(int i = pos ; i < dishnum + 1; i++) {
        dish[i].id = dish[i + 1].id;
        strcpy(dish[i].name, dish[i + 1].name);
        dish[i].price = dish[i + 1].price;
    }
}

void dishArrangeUp(struct information dish[], int dishnum) {
    for (int i = 1; i < dishnum; i++) {
        int key = dish[i].price;
        char key1[50];
        strcpy(key1, dish[i].name);
        int key2 = dish[i].id;
        int j = i - 1;
        while (j >= 0 && dish[j].price > key) {
            dish[j + 1].price = dish[j].price;
            strcpy(dish[j + 1].name, dish[j].name);
            dish[j + 1].id = dish[j].id;
            j--;
        }
        dish[j + 1].price = key;
        strcpy(dish[j + 1].name, key1);
        dish[j + 1].id = key2;

    }
}

void dishArrangeDown(struct information dish[], int dishnum) {
    for (int i = 1; i < dishnum; i++) {
        int key = dish[i].price;
        char key1[50];
        strcpy(key1, dish[i].name);
        int key2 = dish[i].id;
        int j = i - 1;
        while (j >= 0 && dish[j].price < key) {
            dish[j + 1].price = dish[j].price;
            strcpy(dish[j + 1].name, dish[j].name);
            dish[j + 1].id = dish[j].id;
            j--;
        }
        dish[j + 1].price = key;
        strcpy(dish[j + 1].name, key1);
        dish[j + 1].id = key2;

    }
}

void dishFindLS(struct information dish[], int dishnum, char character[]) {
    int check = 0;
    for(int i = 0; i < dishnum; i++) {
        if(strcmp(dish[i].name, character) == 0) {
            printf("da tim thay tai vi tri: %d", i + 1);
            check = 1;
        }
    }
    if(!check) {
        printf("khong tim thay phan tu nao");
    }
}

void dishFindBS(struct information dish[], int dishnum, char character[]) {
    int right = dishnum;
    int left = 0;
    int check = 0;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(strcmp(dish[mid].name, character) == 0) {
            printf("da tim thay tai vi tri: %d", mid + 1);
            check = 1;
        }else if(strcmp(dish[mid].name, character) < 0){
            left = mid + 1;
        }else (strcmp(dish[mid].name, character) > 0); {
            right = mid - 1;
        }

    }
    if(!check) {
        printf("khong tim thay phan tu nao");
    }
}

void dishApUpName(struct information dish[], int dishnum) {
    for (int i = 1; i < dishnum; i++) {
        int key = dish[i].price;
        char key1[50];
        strcpy(key1, dish[i].name);
        int key2 = dish[i].id;
        int j = i - 1;
        while (j >= 0 && strcmp(dish[j].name, key1) > 0) {
            dish[j + 1].price = dish[j].price;
            strcpy(dish[j + 1].name, dish[j].name);
            dish[j + 1].id = dish[j].id;
            j--;
        }
        dish[j + 1].price = key;
        strcpy(dish[j + 1].name, key1);
        dish[j + 1].id = key2;

    }
}
