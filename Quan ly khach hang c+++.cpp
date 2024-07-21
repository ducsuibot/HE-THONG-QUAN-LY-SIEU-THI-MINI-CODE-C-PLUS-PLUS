#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_CUSTOMERS 100 

using namespace std;

// ---------------------------------CODE CAC HAM QUAN LY KHACH HANG-------------------------------------//

typedef struct {
    int ma;
    char ten[50];
    char diaChi[100];
    char soDienThoai[15];
} KhachHang;

KhachHang dsKhachHang[MAX_CUSTOMERS];
int soLuongKhachHang = 0;

// 1. Them khach hang
void themKhachHang() {
    if (soLuongKhachHang >= MAX_CUSTOMERS) {
        cout << "Khong the them khach hang moi. Danh sach da day.\n";
        return;
    }
    KhachHang kh;
    cout << "Nhap ma khach hang: ";
    cin >> kh.ma;
    cin.ignore();
    cout << "Nhap ten khach hang: ";
    cin.getline(kh.ten, 50);
    cout << "Nhap dia chi khach hang: ";
    cin.getline(kh.diaChi, 100);
    cout << "Nhap so dien thoai khach hang: ";
    cin.getline(kh.soDienThoai, 15);
    dsKhachHang[soLuongKhachHang++] = kh;
    cout << "Them khach hang thanh cong!\n";
}

// 2. Sua khach hang
void suaKhachHang() {
    int ma, i;
    cout << "Nhap ma khach hang can sua: ";
    cin >> ma;
    cin.ignore();
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            cout << "Nhap ten khach hang moi: ";
            cin.getline(dsKhachHang[i].ten, 50);
            cout << "Nhap dia chi khach hang moi: ";
            cin.getline(dsKhachHang[i].diaChi, 100);
            cout << "Nhap so dien thoai khach hang moi: ";
            cin.getline(dsKhachHang[i].soDienThoai, 15);
            cout << "Sua thong tin khach hang thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ma da cho.\n";
}

// 3. Xoa khach hang
void xoaKhachHang() {
    int ma, i, j;
    cout << "Nhap ma khach hang can xoa: ";
    cin >> ma;
    cin.ignore();
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            for (j = i; j < soLuongKhachHang - 1; j++) {
                dsKhachHang[j] = dsKhachHang[j + 1];
            }
            soLuongKhachHang--;
            cout << "Xoa khach hang thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ma da cho.\n";
}

// 4. Tim khach hang theo ma
void timKhachHang() {
    int ma, i;
    cout << "Nhap ma khach hang can tim: ";
    cin >> ma;
    cin.ignore();
    for (i = 0; i < soLuongKhachHang; i++) {
        if (dsKhachHang[i].ma == ma) {
            cout << "Khach hang tim thay: Ma: " << dsKhachHang[i].ma 
                 << ", Ten: " << dsKhachHang[i].ten 
                 << ", Dia chi: " << dsKhachHang[i].diaChi 
                 << ", So dien thoai: " << dsKhachHang[i].soDienThoai << "\n";
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ma da cho.\n";
}

// 5. Luu thong tin khach hang vao FILE khachhang.txt
void luuKhachHangVaoTep() {
    FILE *f = fopen("khachhang.txt", "w");
    if (f == NULL) {
        cout << "Khong the mo tep de ghi.\n";
        return;
    }
    fprintf(f, "\nSO LUONG KHACH HANG: %d\n", soLuongKhachHang);
    for (int i = 0; i < soLuongKhachHang; i++) {
        fprintf(f, "Ma khach hang: %d\nTen khach hang: %s\nDia chi khach hang: %s\nSDT khach hang: %s\n", 
                dsKhachHang[i].ma, dsKhachHang[i].ten, dsKhachHang[i].diaChi, dsKhachHang[i].soDienThoai);
    }
    fclose(f);
    cout << "Da luu danh sach khach hang vao tep khachhang.txt.\n";
}

// 6. Hien thong tin khach hang tu FILE khachhang.txt
void docKhachHangTuTep() {
    FILE *f = fopen("khachhang.txt", "r");
    if (f == NULL) {
        cout << "Khong the mo tep de doc.\n";
        return;
    }
    char buffer[1000]; // Do dai toi da cua moi dong trong file
    // Doc va in ra so luong Khach hang
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        cout << buffer;
    }
    // Doc va in ra tung khach hang
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        cout << buffer;
    }
    fclose(f);
}
