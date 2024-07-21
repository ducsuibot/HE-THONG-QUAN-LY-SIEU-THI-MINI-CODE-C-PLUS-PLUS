#include <iostream>
#include <fstream>
#include <string>
#define MAX_BILLS 100

using namespace std;

// ---------------------------------CODE CAC HAM QUAN LY HOA DON-------------------------------------//
struct HoaDon {
    int ma;
    int maKhachHang;
    int maSanPham;
    int soLuong;
    float tongGia;
    float giamGia;
    float giaCuoi;
};

HoaDon dsHoaDon[MAX_BILLS];
int soLuongHoaDon = 0;

// 1. Them hoa don
void themHoaDon() {
    if (soLuongHoaDon >= MAX_BILLS) {
        cout << "Khong the them hoa don moi. Danh sach da day." << endl;
        return;
    }
    HoaDon hd;
    cout << "Nhap ma hoa don: ";
    cin >> hd.ma;
    cout << "Nhap ma khach hang: ";
    cin >> hd.maKhachHang;
    cout << "Nhap ma san pham: ";
    cin >> hd.maSanPham;
    cout << "Nhap so luong san pham mua: ";
    cin >> hd.soLuong;

    for (int i = 0; i < soLuongSanPham; i++) {
        if (dsSanPham[i].ma == hd.maSanPham) {
            hd.tongGia = dsSanPham[i].gia * hd.soLuong;
        }
    }

    cout << "Nhap giam gia: ";
    cin >> hd.giamGia;
    hd.giaCuoi = hd.tongGia - hd.giamGia;
    dsHoaDon[soLuongHoaDon++] = hd;
    cout << "Them hoa don thanh cong!" << endl;
}

// 2. Sua hoa don
void suaHoaDon() {
    int ma, i;
    cout << "Nhap ma hoa don can sua: ";
    cin >> ma;
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            cout << "Nhap ma khach hang moi: ";
            cin >> dsHoaDon[i].maKhachHang;
            cout << "Nhap ma san pham moi: ";
            cin >> dsHoaDon[i].maSanPham;
            cout << "Nhap so luong san pham moi: ";
            cin >> dsHoaDon[i].soLuong;

            for (int j = 0; j < soLuongSanPham; j++) {
                if (dsSanPham[j].ma == dsHoaDon[i].maSanPham) {
                    dsHoaDon[i].tongGia = dsSanPham[j].gia * dsHoaDon[i].soLuong;
                }
            }

            cout << "Nhap giam gia moi: ";
            cin >> dsHoaDon[i].giamGia;
            dsHoaDon[i].giaCuoi = dsHoaDon[i].tongGia - dsHoaDon[i].giamGia;
            cout << "Sua thong tin hoa don thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay hoa don voi ma da cho." << endl;
}

// 3. Xoa hoa don
void xoaHoaDon() {
    int ma, i, j;
    cout << "Nhap ma hoa don can xoa: ";
    cin >> ma;
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            for (j = i; j < soLuongHoaDon - 1; j++) {
                dsHoaDon[j] = dsHoaDon[j + 1];
            }
            soLuongHoaDon--;
            cout << "Xoa hoa don thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay hoa don voi ma da cho." << endl;
}

// 4. Tim hoa don theo ma
void timHoaDon() {
    int ma, i;
    cout << "Nhap ma hoa don can tim: ";
    cin >> ma;
    for (i = 0; i < soLuongHoaDon; i++) {
        if (dsHoaDon[i].ma == ma) {
            cout << "Hoa don tim thay: Ma: " << dsHoaDon[i].ma << ", Ma khach hang: " << dsHoaDon[i].maKhachHang
                 << ", Ma san pham: " << dsHoaDon[i].maSanPham << ", So luong: " << dsHoaDon[i].soLuong
                 << ", Tong gia: " << dsHoaDon[i].tongGia << ", Giam gia: " << dsHoaDon[i].giamGia
                 << ", Gia cuoi: " << dsHoaDon[i].giaCuoi << endl;
            return;
        }
    }
    cout << "Khong tim thay hoa don voi ma da cho." << endl;
}
// 5. Luu hoa don vao FILE hoadon.txt
void luuHoaDonVaoTep() {
    FILE *f = fopen("hoadon.txt", "w");
    if (f == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fprintf(f, "So Luong Hoa Don: %d\n\n", soLuongHoaDon);
    for (int i = 0; i < soLuongHoaDon; i++) {
        
        //ma hoa don
			fprintf(f,"Ma hoa don: %d\n",dsHoaDon[i].ma);  
		// khach hang
			fprintf(f,"Ma khach hang: %d | ",dsHoaDon[i].maKhachHang); 
			for(int j=0;j<soLuongKhachHang;j++) 
				{ 
					if( dsHoaDon[i].maKhachHang==dsKhachHang[j].ma)//chay vong for de tim ma khach hang  
						{ 
								fprintf(f,"Ten khach hang: %s\n",dsKhachHang[j].ten); 
						}
				}   
		//san pham
			fprintf(f,"Ma San Pham: %d | ",dsHoaDon[i].maSanPham); 
			for(int j=0;j<soLuongHoaDon;j++) 
				{ 
					if( dsHoaDon[i].maSanPham==dsSanPham[j].ma)//chay vong for de tim ma san pham
						{ 
								fprintf(f,"Ten San Pham: %s\n",dsSanPham[j].ten); 
						}
				}    
		// so luong sp khach hang mua
			fprintf(f,"So Luong Sp Mua: %d\n",dsHoaDon[i].soLuong);
        
    }
    fclose(f);
    printf("Da luu danh sach nha cung cap vao tep hoadon.txt.\n");
}
 
// 6. Hien hoa don tu FILE hoadon.txt 
void docHoaDonTuTep() {
    FILE *f = fopen("hoadon.txt", "r");
    if (f == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }   
    char buffer[1000]; // Do dai toi da cua moi dong trong file
    // Doc va in ra so luong hoa don
    if (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }   
    // Doc va in ra tung hoa don
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }  
    fclose(f);
} 
//---------------------------------HAM TINH TONG DOANH THU----------------------------------------------//
void tinhTongDoanhThu() {
    float tongDoanhThu = 0;
    for (int i = 0; i < soLuongHoaDon; i++) {
        tongDoanhThu += dsHoaDon[i].giaCuoi;
    }
    cout << "Tong doanh thu: " << tongDoanhThu << endl;
}
