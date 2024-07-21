#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_EMPLOYEES 100

using namespace std;

// ---------------------------------CODE CAC HAM QUAN LY NHAN VIEN------------------------------------//

typedef struct {
    int ma;
    char ten[50];
    float luong;
    char chucVu[50];
    char soDienThoai[15];
} NhanVien;

NhanVien dsNhanVien[MAX_EMPLOYEES];
int soLuongNhanVien = 0;

// 1. Them nhan vien
void themNhanVien() {
    if (soLuongNhanVien >= MAX_EMPLOYEES) {
        cout << "Khong the them nhan vien moi. Danh sach da day.\n";
        return;
    }
    NhanVien nv;
    cout << "Nhap ma nhan vien: ";
    cin >> nv.ma;
    cin.ignore();
    cout << "Nhap ten nhan vien: ";
    cin.getline(nv.ten, 50);
    cout << "Nhap luong nhan vien: ";
    cin >> nv.luong;
    cin.ignore();
    cout << "Nhap chuc vu nhan vien: ";
    cin.getline(nv.chucVu, 50);
    cout << "Nhap so dien thoai nhan vien: ";
    cin.getline(nv.soDienThoai, 15);
    dsNhanVien[soLuongNhanVien++] = nv;
    cout << "Them nhan vien thanh cong!\n";
}

// 2. Sua nhan vien
void suaNhanVien() {
    int ma, i;
    cout << "Nhap ma nhan vien can sua: ";
    cin >> ma;
    cin.ignore();
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            cout << "Nhap ten nhan vien moi: ";
            cin.getline(dsNhanVien[i].ten, 50);
            cout << "Nhap luong nhan vien moi: ";
            cin >> dsNhanVien[i].luong;
            cin.ignore();
            cout << "Nhap chuc vu nhan vien moi: ";
            cin.getline(dsNhanVien[i].chucVu, 50);
            cout << "Nhap so dien thoai nhan vien moi: ";
            cin.getline(dsNhanVien[i].soDienThoai, 15);
            cout << "Sua thong tin nhan vien thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien voi ma da cho.\n";
}

// 3. Xoa nhan vien
void xoaNhanVien() {
    int ma, i, j;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> ma;
    cin.ignore();
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            for (j = i; j < soLuongNhanVien - 1; j++) {
                dsNhanVien[j] = dsNhanVien[j + 1];
            }
            soLuongNhanVien--;
            cout << "Xoa nhan vien thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien voi ma da cho.\n";
}

// 4. Tim nhan vien
void timNhanVien() {
    int ma, i;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> ma;
    cin.ignore();
    for (i = 0; i < soLuongNhanVien; i++) {
        if (dsNhanVien[i].ma == ma) {
            cout << "Nhan vien tim thay: Ma: " << dsNhanVien[i].ma 
                 << ", Ten: " << dsNhanVien[i].ten 
                 << ", Luong: " << dsNhanVien[i].luong 
                 << ", Chuc vu: " << dsNhanVien[i].chucVu 
                 << ", So dien thoai: " << dsNhanVien[i].soDienThoai << "\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien voi ma da cho.\n";
}

// 5. Luu danh sach nhan vien vao FILE nhanvien.txt
void luuNhanVienVaoTep() {
    FILE *f = fopen("nhanvien.txt", "w");
    if (f == NULL) {
        cout << "Khong the mo tep de ghi.\n";
        return;
    }
    fprintf(f, "SO LUONG NHAN VIEN: %d\n", soLuongNhanVien);
    for (int i = 0; i < soLuongNhanVien; i++) {
        fprintf(f, "Ma nhan vien: %d\nTen nhan vien: %s\nLuong: %f\nChuc vu: %s\nSDT nhan vien: %s\n", 
                dsNhanVien[i].ma, dsNhanVien[i].ten, dsNhanVien[i].luong, dsNhanVien[i].chucVu, dsNhanVien[i].soDienThoai);
    }
    fclose(f);
    cout << "Da luu danh sach nhan vien vao tep nhanvien.txt.\n";
}

// 6. Hien danh sach nhan vien tu FILE nhanvien.txt
void docNhanVienTuTep() {
    FILE *f = fopen("nhanvien.txt", "r");
    if (f == NULL) {
        cout << "Khong the mo tep de doc.\n";
        return;
    }
    char buffer[1000]; // Do dai toi da cua moi dong trong file
    // Doc va in ra so luong Nhan vien
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        cout << buffer;
    }
    // Doc va in ra tung nhan vien
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        cout << buffer;
    }
    fclose(f);
}
