#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_PRODUCTS 100 

// ---------------------------------CODE CAC HAM QUAN LY SAN PHAM-------------------------------------// 
struct SanPham {
    int ma;
    char ten[50];
    float gia;
    int soLuong;
};

SanPham dsSanPham[MAX_PRODUCTS];
int soLuongSanPham = 0;

// 1. Them san pham
void themSanPham() {
    if (soLuongSanPham >= MAX_PRODUCTS) {
        cout << "Khong the them san pham moi. Danh sach da day." << endl;
        return;
    }
    SanPham sp;
    cout << "Nhap ma san pham: ";
    cin >> sp.ma;
    cout << "Nhap ten san pham: ";
    cin.ignore();
    cin.getline(sp.ten, 50);
    cout << "Nhap gia san pham: ";
    cin >> sp.gia;
    cout << "Nhap so luong san pham: ";
    cin >> sp.soLuong;
    dsSanPham[soLuongSanPham++] = sp;
    cout << "Them san pham thanh cong!" << endl;
}

// 2. Sua san pham
void suaSanPham() {
    int ma;
    cout << "Nhap ma san pham can sua: ";
    cin >> ma;
    for (int i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            cout << "Nhap ten san pham moi: ";
            cin.ignore();
            cin.getline(dsSanPham[i].ten, 50);
            cout << "Nhap gia san pham moi: ";
            cin >> dsSanPham[i].gia;
            cout << "Nhap so luong san pham moi: ";
            cin >> dsSanPham[i].soLuong;
            cout << "Sua thong tin san pham thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham voi ma da cho." << endl;
}

// 3. Xoa san pham
void xoaSanPham() {
    int ma;
    cout << "Nhap ma san pham can xoa: ";
    cin >> ma;
    for (int i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            for (int j = i; j < soLuongSanPham - 1; j++) {
                dsSanPham[j] = dsSanPham[j + 1];
            }
            soLuongSanPham--;
            cout << "Xoa san pham thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham voi ma da cho." << endl;
}

// 4. Tim san pham theo ma
void timSanPham() {
    int ma;
    cout << "Nhap ma san pham can tim: ";
    cin >> ma;
    for (int i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == ma) {
            cout << "San pham tim thay: Ma: " << dsSanPham[i].ma
                 << ", Ten: " << dsSanPham[i].ten
                 << ", Gia: " << dsSanPham[i].gia
                 << ", So luong: " << dsSanPham[i].soLuong << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham voi ma da cho." << endl;
}

// 5. Tim san pham theo ten
void timSanPhamTheoTen() {
    char ten[50];
    cout << "Nhap ten san pham can tim: ";
    cin.ignore();
    cin.getline(ten, 50);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(dsSanPham[i].ten, ten) == 0) {
            cout << "San pham tim thay: Ma: " << dsSanPham[i].ma
                 << ", Ten: " << dsSanPham[i].ten
                 << ", Gia: " << dsSanPham[i].gia
                 << ", So luong: " << dsSanPham[i].soLuong << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham voi ten da cho." << endl;
}

// 6. Sap xep san pham theo gia
void sapXepSanPhamTheoGia() {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if (dsSanPham[i].gia > dsSanPham[j].gia) {
                SanPham temp = dsSanPham[i];
                dsSanPham[i] = dsSanPham[j];
                dsSanPham[j] = temp;
            }
        }
    }
    cout << "Da sap xep san pham theo gia tang dan." << endl;
}

// 7. Sap xep san pham theo ten
void sapXepSanPhamTheoTen() {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if (strcmp(dsSanPham[i].ten, dsSanPham[j].ten) > 0) {
                SanPham temp = dsSanPham[i];
                dsSanPham[i] = dsSanPham[j];
                dsSanPham[j] = temp;
            }
        }
    }
    cout << "Da sap xep san pham theo ten tang dan." << endl;
}

// 8. Luu san pham vao FILE sanpham.txt
void luuSanPhamVaoTep() {
    FILE *f = fopen("sanpham.txt", "w");
    if (f == NULL) {
        cout << "Khong the mo tep de ghi." << endl;
        return;
    }
    fprintf(f, "\nSO LUONG SAN PHAM:%d\n\n", soLuongSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        fprintf(f, "Ma san pham: %d\nTen san pham: %s\nGia san pham: %.0f\nSo luong: %d\n\n\n", dsSanPham[i].ma, dsSanPham[i].ten, dsSanPham[i].gia, dsSanPham[i].soLuong);
    }
    fclose(f);
    cout << "Da luu danh sach san pham vao tep sanpham.txt." << endl;
}  

// 9. Hien san pham tu FILE sanpham.txt ra man hinh
void docSanPhamTuTep() {
    FILE *f = fopen("sanpham.txt", "r");
    if (f == NULL) {
        cout << "Khong the mo tep de doc." << endl;
        return;
    } 
    char buffer[1000]; // Do dai toi da cua moi dong trong file    
    // Doc va in ra so luong san pham
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        cout << buffer;
    }    
    // Doc va in ra tung san pham
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        cout << buffer;
    }
    
    fclose(f);
}

