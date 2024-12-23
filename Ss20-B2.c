#include <stdio.h>
#include <string.h>

typedef struct {
    int maSP;
    char tenSP[100];
    float giaNhap;
    float giaBan;
    int soLuong;
} SanPham;

SanPham danhSachSP[100];  
int soLuongSP = 0;         
float doanhThu = 0.0;     

void nhapSanPham() {
    int n;
    printf("Nhap so luong san pham can nhap: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int maSP;
        printf("Nhap ma san pham: ");
        scanf("%d", &maSP);

        int exists = 0;
        for (int j = 0; j < soLuongSP; j++) {
            if (danhSachSP[j].maSP == maSP) {
                exists = 1;
                printf("San pham da ton tai. Tong so luong hien tai: %d\n", danhSachSP[j].soLuong);
                printf("Nhap so luong moi: ");
                int them;
                scanf("%d", &them);
                danhSachSP[j].soLuong += them;
                doanhThu -= them * danhSachSP[j].giaNhap;
                break;
            }
        }

        if (!exists) {
            danhSachSP[soLuongSP].maSP = maSP;
            getchar();  

            printf("Nhap ten san pham: ");
            fgets(danhSachSP[soLuongSP].tenSP, 100, stdin);
            danhSachSP[soLuongSP].tenSP[strcspn(danhSachSP[soLuongSP].tenSP, "\n")] = '\0';  

            printf("Nhap gia nhap: ");
            scanf("%f", &danhSachSP[soLuongSP].giaNhap);

            printf("Nhap gia ban: ");
            scanf("%f", &danhSachSP[soLuongSP].giaBan);

            printf("Nhap so luong: ");
            scanf("%d", &danhSachSP[soLuongSP].soLuong);

            doanhThu -= danhSachSP[soLuongSP].soLuong * danhSachSP[soLuongSP].giaNhap;
            soLuongSP++;
        }
    }
}

void hienThiDanhSachSP() {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < soLuongSP; i++) {
        printf("Ma SP: %d\n", danhSachSP[i].maSP);
        printf("Ten SP: %s\n", danhSachSP[i].tenSP);
        printf("Gia nhap: %.2f\n", danhSachSP[i].giaNhap);
        printf("Gia ban: %.2f\n", danhSachSP[i].giaBan);
        printf("So luong: %d\n\n", danhSachSP[i].soLuong);
    }
}

void capNhatThongTinSP() {
    int maSP;
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%d", &maSP);

    for (int i = 0; i < soLuongSP; i++) {
        if (danhSachSP[i].maSP == maSP) {
            printf("Nhap thong tin moi cho san pham %s:\n", danhSachSP[i].tenSP);
            
            printf("Nhap gia nhap moi: ");
            scanf("%f", &danhSachSP[i].giaNhap);

            printf("Nhap gia ban moi: ");
            scanf("%f", &danhSachSP[i].giaBan);

            printf("Nhap so luong moi: ");
            scanf("%d", &danhSachSP[i].soLuong);

            printf("Cap nhat thong tin thanh cong!\n");
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

void sapXepTheoGia() {
    int luaChon;
    printf("1. Sap xep tang theo gia\n");
    printf("2. Sap xep giam theo gia\n");
    printf("Lua chon: ");
    scanf("%d", &luaChon);

    for (int i = 0; i < soLuongSP - 1; i++) {
        for (int j = i + 1; j < soLuongSP; j++) {
            if ((luaChon == 1 && danhSachSP[i].giaBan > danhSachSP[j].giaBan) || 
                (luaChon == 2 && danhSachSP[i].giaBan < danhSachSP[j].giaBan)) {
                SanPham temp = danhSachSP[i];
                danhSachSP[i] = danhSachSP[j];
                danhSachSP[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void timKiemSanPham() {
    char tenSP[100];
    printf("Nhap ten san pham can tim: ");
    getchar();  
    fgets(tenSP, 100, stdin);
    tenSP[strcspn(tenSP, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < soLuongSP; i++) {
        if (strstr(danhSachSP[i].tenSP, tenSP) != NULL) {
            printf("Ma SP: %d\n", danhSachSP[i].maSP);
            printf("Ten SP: %s\n", danhSachSP[i].tenSP);
            printf("Gia nhap: %.2f\n", danhSachSP[i].giaNhap);
            printf("Gia ban: %.2f\n", danhSachSP[i].giaBan);
            printf("So luong: %d\n\n", danhSachSP[i].soLuong);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay san pham co ten %s.\n", tenSP);
    }
}

void banSanPham() {
    int maSP, soLuongBan;
    printf("Nhap ma san pham can ban: ");
    scanf("%d", &maSP);

    for (int i = 0; i < soLuongSP; i++) {
        if (danhSachSP[i].maSP == maSP) {
            if (danhSachSP[i].soLuong == 0) {
                printf("San pham da het hang.\n");
                return;
            }

            printf("Nhap so luong san pham can ban: ");
            scanf("%d", &soLuongBan);

            if (soLuongBan > danhSachSP[i].soLuong) {
                printf("Khong con du so luong san pham.\n");
            } else {
                danhSachSP[i].soLuong -= soLuongBan;
                doanhThu += soLuongBan * danhSachSP[i].giaBan;
                printf("Ban thanh cong %d san pham %s.\n", soLuongBan, danhSachSP[i].tenSP);
                printf("Doanh thu hien tai: %.2f\n", doanhThu);
            }
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

void hienThiDoanhThu() {
    printf("Doanh thu hien tai: %.2f\n", doanhThu);
}

int main() {
    int luaChon;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap thong tin san pham.\n");
        printf("2. Hien thi danh sach san pham.\n");
        printf("3. Nhap san pham.\n");
        printf("4. Cap nhat thong tin san pham.\n");
        printf("5. Sap xep san pham theo gia.\n");
        printf("6. Tim kiem san pham.\n");
        printf("7. Ban san pham.\n");
        printf("8. Doanh thu hien tai.\n");
        printf("9. Thoat.\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapSanPham();
                break;
            case 2:
                hienThiDanhSachSP();
                break;
            case 3:
                nhapSanPham();
                break;
            case 4:
                capNhatThongTinSP();
                break;
            case 5:
                sapXepTheoGia();
                break;
            case 6:
                timKiemSanPham();
                break;
            case 7:
                banSanPham();
                break;
            case 8:
                hienThiDoanhThu();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 9);

    return 0;
}

