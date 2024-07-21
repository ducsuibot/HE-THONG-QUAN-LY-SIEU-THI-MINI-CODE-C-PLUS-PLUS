void menuChinh() {
    int luaChon;
    do {
        cout << "\n============= MENU =============\n";
        cout << "1. Quan ly san pham\n";
        cout << "2. Quan ly khach hang\n";
        cout << "3. Quan ly nhan vien\n";
        cout << "4. Quan ly nha cung cap\n";
        cout << "5. Quan ly hoa don\n";
        cout << "6. Tinh tong doanh thu\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1:
                cout << "\n============= QUAN LY SAN PHAM =============\n";
                cout << "1. Them san pham\n";
                cout << "2. Sua san pham\n";
                cout << "3. Xoa san pham\n";
                cout << "4. Tim san pham\n";
                cout << "5. Tim san pham theo ten\n";
                cout << "6. Sap xep san pham theo gia\n";
                cout << "7. Sap xep san pham theo ten\n";
                cout << "8. Luu danh sach san pham vao tep\n";
                cout << "9. Hien thi danh sach san pham tu tep\n";
                cout << "Lua chon cua ban: ";
                cin >> luaChon;
                switch (luaChon) {
                    case 1:
                        themSanPham();
                        break;
                    case 2:
                        suaSanPham();
                        break;
                    case 3:
                        xoaSanPham();
                        break;
                    case 4:
                        timSanPham();
                        break;
                    case 5:
                        timSanPhamTheoTen();
                        break;
                    case 6:
                        sapXepSanPhamTheoGia();
                        break;
                    case 7:
                        sapXepSanPhamTheoTen();
                        break;
                    case 8:
                        luuSanPhamVaoTep();
                        break;
                    case 9:
                        docSanPhamTuTep();
                        break;
                    default:
                        cout << "Lua chon khong hop le!\n";
                        break;
                }
                break;
            case 2:
                cout << "\n============= QUAN LY KHACH HANG =============\n";
                cout << "1. Them khach hang\n";
                cout << "2. Sua khach hang\n";
                cout << "3. Xoa khach hang\n";
                cout << "4. Tim khach hang\n";
                cout << "5. Luu danh sach khach hang vao tep\n";
                cout << "6. Hien danh sach khach hang tu tep\n";
                cout << "Lua chon cua ban: ";
                cin >> luaChon;
                switch (luaChon) {
                    case 1:
                        themKhachHang();
                        break;
                    case 2:
                        suaKhachHang();
                        break;
                    case 3:
                        xoaKhachHang();
                        break;
                    case 4:
                        timKhachHang();
                        break;
                    case 5:
                        luuKhachHangVaoTep();
                        break;
                    case 6:
                        docKhachHangTuTep();
                        break;
                    default:
                        cout << "Lua chon khong hop le!\n";
                        break;
                }
                break;
            case 3:
                cout << "\n============= QUAN LY NHAN VIEN =============\n";
                cout << "1. Them nhan vien\n";
                cout << "2. Sua nhan vien\n";
                cout << "3. Xoa nhan vien\n";
                cout << "4. Tim nhan vien\n";
                cout << "5. Luu danh sach nhan vien vao tep\n";
                cout << "6. Hien danh sach nhan vien tu tep\n";
                cout << "0. Quay lai\n";
                cout << "Lua chon cua ban: ";
                cin >> luaChon;
                switch (luaChon) {
                    case 1:
                        themNhanVien();
                        break;
                    case 2:
                        suaNhanVien();
                        break;
                    case 3:
                        xoaNhanVien();
                        break;
                    case 4:
                        timNhanVien();
                        break;
                    case 5:
                        luuNhanVienVaoTep();
                        break;
                    case 6:
                        docNhanVienTuTep();
                        break;
                    case 0:
                        return;
                    default:
                        cout << "Lua chon khong hop le!\n";
                        break;
                }
                break;
            case 4:
                cout << "\n============= QUAN LY NHA CUNG CAP =============\n";
                cout << "1. Them nha cung cap\n";
                cout << "2. Sua nha cung cap\n";
                cout << "3. Xoa nha cung cap\n";
                cout << "4. Tim nha cung cap\n";
                cout << "5. Luu danh sach nha cung cap vao tep\n";
                cout << "6. Hien danh sach nha cung cap tu tep\n";
                cout << "Lua chon cua ban: ";
                cin >> luaChon;
                switch (luaChon) {
                    case 1:
                        themNhaCungCap();
                        break;
                    case 2:
                        suaNhaCungCap();
                        break;
                    case 3:
                        xoaNhaCungCap();
                        break;
                    case 4:
                        timNhaCungCap();
                        break;
                    case 5:
                        luuNhaCungCapVaoTep();
                        break;
                    case 6:
                        docNhaCungCapTuTep();
                        break;
                    default:
                        cout << "Lua chon khong hop le!\n";
                        break;
                }
                break;
            case 5:
                cout << "\n============= QUAN LY HOA DON =============\n";
                cout << "1. Them hoa don\n";
                cout << "2. Sua hoa don\n";
                cout << "3. Xoa hoa don\n";
                cout << "4. Tim hoa don\n";
                cout << "5. Luu danh sach hoa don vao tep\n";
                cout << "6. Hien danh sach hoa don tu tep\n";
                cout << "0. Quay lai\n";
                cout << "Lua chon cua ban: ";
                cin >> luaChon;
                switch (luaChon) {
                    case 1:
                        themHoaDon();
                        break;
                    case 2:
                        suaHoaDon();
                        break;
                    case 3:
                        xoaHoaDon();
                        break;
                    case 4:
                        timHoaDon();
                        break;
                    case 5:
                        luuHoaDonVaoTep();
                        break;
                    case 6:
                        docHoaDonTuTep();
                        break;
                    case 0:
                        return;
                    default:
                        cout << "Lua chon khong hop le!\n";
                        break;
                }
                break;
            case 6:
                cout << "\n============= TINH TONG DOANH THU =============\n";
                tinhTongDoanhThu();
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (luaChon != 0);
}
