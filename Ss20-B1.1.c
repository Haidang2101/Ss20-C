#include <stdio.h>
#include <string.h>

typedef struct {
    int maSach;
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char theLoai[50];
} Sach;

Sach sachList[100]; 
int soLuongSach = 0;

void nhapSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);

    for (int i = 0; i < soLuongSach; i++) {
        printf("Nhap ma sach %d: ", i + 1);
        scanf("%d", &sachList[i].maSach);
        getchar();  

        printf("Nhap ten sach %d: ", i + 1);
        fgets(sachList[i].tenSach, 100, stdin);
        sachList[i].tenSach[strcspn(sachList[i].tenSach, "\n")] = '\0';  

        printf("Nhap tac gia %d: ", i + 1);
        fgets(sachList[i].tacGia, 100, stdin);
        sachList[i].tacGia[strcspn(sachList[i].tacGia, "\n")] = '\0';  

        printf("Nhap gia tien %d: ", i + 1);
        scanf("%f", &sachList[i].giaTien);
        getchar();  

        printf("Nhap the loai %d: ", i + 1);
        fgets(sachList[i].theLoai, 50, stdin);
        sachList[i].theLoai[strcspn(sachList[i].theLoai, "\n")] = '\0';  
    }
}

void hienThiSach() {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("Ma sach: %d\n", sachList[i].maSach);
        printf("Ten sach: %s\n", sachList[i].tenSach);
        printf("Tac gia: %s\n", sachList[i].tacGia);
        printf("Gia tien: %.2f\n", sachList[i].giaTien);
        printf("The loai: %s\n\n", sachList[i].theLoai);
    }
}

void themSachVaoViTri() {
    int viTri;
    printf("Nhap vi tri can them sach: ");
    scanf("%d", &viTri);

    if (viTri < 0 || viTri > soLuongSach) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    printf("Nhap thong tin sach can them:\n");
    printf("Nhap ma sach: ");
    scanf("%d", &sachList[viTri].maSach);
    getchar();  

    printf("Nhap ten sach: ");
    fgets(sachList[viTri].tenSach, 100, stdin);
    sachList[viTri].tenSach[strcspn(sachList[viTri].tenSach, "\n")] = '\0';  

    printf("Nhap tac gia: ");
    fgets(sachList[viTri].tacGia, 100, stdin);
    sachList[viTri].tacGia[strcspn(sachList[viTri].tacGia, "\n")] = '\0';  

    printf("Nhap gia tien: ");
    scanf("%f", &sachList[viTri].giaTien);
    getchar();  

    printf("Nhap the loai: ");
    fgets(sachList[viTri].theLoai, 50, stdin);
    sachList[viTri].theLoai[strcspn(sachList[viTri].theLoai, "\n")] = '\0';  

    soLuongSach++;
}

void xoaSach() {
    int maSach;
    printf("Nhap ma sach can xoa: ");
    scanf("%d", &maSach);

    for (int i = 0; i < soLuongSach; i++) {
        if (sachList[i].maSach == maSach) {
            for (int j = i; j < soLuongSach - 1; j++) {
                sachList[j] = sachList[j + 1];
            }
            soLuongSach--;
            printf("Xoa sach ma %d thanh cong.\n", maSach);
            return;
        }
    }
    printf("Khong tim thay sach voi ma sach %d.\n", maSach);
}

void capNhatSach() {
    int maSach;
    printf("Nhap ma sach can cap nhat: ");
    scanf("%d", &maSach);

    for (int i = 0; i < soLuongSach; i++) {
        if (sachList[i].maSach == maSach) {
            printf("Nhap thong tin sach moi:\n");

            printf("Nhap ten sach: ");
            getchar();  
            fgets(sachList[i].tenSach, 100, stdin);
            sachList[i].tenSach[strcspn(sachList[i].tenSach, "\n")] = '\0';

            printf("Nhap tac gia: ");
            fgets(sachList[i].tacGia, 100, stdin);
            sachList[i].tacGia[strcspn(sachList[i].tacGia, "\n")] = '\0';

            printf("Nhap gia tien: ");
            scanf("%f", &sachList[i].giaTien);
            getchar();  

            printf("Nhap the loai: ");
            fgets(sachList[i].theLoai, 50, stdin);
            sachList[i].theLoai[strcspn(sachList[i].theLoai, "\n")] = '\0';

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma sach %d.\n", maSach);
}

void sapXepSach() {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if (sachList[i].giaTien > sachList[j].giaTien) {
                Sach temp = sachList[i];
                sachList[i] = sachList[j];
                sachList[j] = temp;
            }
        }
    }
    printf("Sap xep sach theo gia thanh cong.\n");
}

void timKiemSach() {
    char tenSach[100];
    printf("Nhap ten sach can tim: ");
    getchar();  
    fgets(tenSach, 100, stdin);
    tenSach[strcspn(tenSach, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(sachList[i].tenSach, tenSach) != NULL) {
            printf("Ma sach: %d\n", sachList[i].maSach);
            printf("Ten sach: %s\n", sachList[i].tenSach);
            printf("Tac gia: %s\n", sachList[i].tacGia);
            printf("Gia tien: %.2f\n", sachList[i].giaTien);
            printf("The loai: %s\n\n", sachList[i].theLoai);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach co ten %s.\n", tenSach);
    }
}

int main() {
    int luaChon;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang dan).\n");
        printf("7. Tim kiem sach theo ten.\n");
        printf("8. Thoat.\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapSach();
                break;
            case 2:
                hienThiSach();
                break;
            case 3:
                themSachVaoViTri();
                break;
            case 4:
                xoaSach();
                break;
            case 5:
                capNhatSach();
                break;
            case 6:
                sapXepSach();
                break;
            case 7:
                timKiemSach();
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Khong hop le.\n");
        }
    } while (luaChon != 8);

    return 0;
}

