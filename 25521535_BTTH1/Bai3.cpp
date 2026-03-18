#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

struct PhanSo {
    int tu;
    int mau;
    bool hople = true;

    // Khởi tạo phân số, mặc định là 0/1 nếu không truyền tham số
    PhanSo(int t = 0, int m = 1){
        tu = t;
        mau = m;
        
        // Nếu mẫu = 0 thì hople = false
        if(m == 0) {
            hople = false;
        } else {
            // Nếu mẫu khác 0 thì hople = true, gọi hàm rút gọn
            hople = true;
            RutGon();
        }
    }

    // Nhập vào 2 số nguyên a và b và trả về ước chung lớn nhất của 2 số (sử dụng thuật toán Euclid)    
    int gcd(int a,int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    // Nhập vào 2 số nguyên a và b và trả về bội chung nhỏ nhất của 2 số (sử dụng thuật toán Euclid)
    int BCNN(int a,int b) {
        return a * b / (gcd(a,b));
    }

    // Nhập dữ liệu tử số và mẫu số, gán giá trị cho biến 'tu' va 'mau', tự động kiểm tra tính hợp lệ (nếu không hợp lệ sẽ bắt nhập lại) và rút gọn phân số sau khi người dùng đã nhập một phân số hợp lệ
    void Nhap() {
        while (true) {
            cout << "Nhap tu va mau cua phan so (cach nhau bang dau cach): ";

            // Nếu nhập vào số nguyên và mẫu khác 0 thì break vòng lặp, còn lại thì bắt người dùng nhập lại
            if (cin >> tu >> mau) {
                if (mau != 0) {
                    break; 
                } else {
                    cout << "Loi: Mau so phai khac 0" << endl;
                }
            } else {
                cout << "Loi: Vui long chi nhap so nguyen" << endl;

                // Xóa sạch các ký tự lỗi hoặc thừa trong bộ đệm cho đến khi gặp phím Enter 
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            }
        }
        RutGon(); 
    }
    
    // Tối giản phân số và đảm bảo mẫu số luôn dương
    void RutGon() {
        int ucln = gcd(abs(tu),abs(mau)); // Tìm ước chung lớn nhất của tử và mẫu số
        tu /= ucln; // Chia tử cho ước chung lớn nhất
        mau /= ucln; // Chia mẫu cho ước chung lớn nhất

        // Đưa dấu trừ lên tử số nếu mẫu âm
        if(mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // Xuất phân số ra màn hình (ẩn mẫu số nếu mẫu bằng 1)
    void Xuat() {
        if(mau == 1) {
            cout << tu << "\n";
        }
        else {
            cout << tu << "/" << mau << "\n";
        }
    }
    
    // Quy đồng phân số hiện tại với một phân số khác và cập nhật giá trị sau khi quy đồng cho cả hai phân số (other: tham chiếu đến phân số thứ 2 cần quy đồng)
    void QuyDong(PhanSo &other) {
        int boi = BCNN(mau,other.mau); // Tìm mẫu số chung nhỏ nhất
        int hs1 = boi/mau; // Hệ số nhân của phân số thứ nhất
        int hs2 = boi/other.mau; // Hệ số nhân của phân số thứ hai
        tu *= hs1; // Nhân tử phân số thứ nhất cho hệ số nhân của nó
        other.tu *= hs2; // Nhân tử phân số thứ hai cho hệ số nhân của nó

        // Cập nhật cả hai mẫu số của hai phân số bằng với bội chung nhỏ nhất
        mau = boi;
        other.mau = boi;
    }

    // Nạp chồng toán tử cộng: Thực hiện quy đồng và trả về tổng của hai phân số
    PhanSo operator+(PhanSo other) {
        PhanSo self = *this; // Tạo một bản sao của phân số hiện tại để khi quy đồng không thay đổi phân số hiện tại
        self.QuyDong(other); // Quy đồng mẫu số giữa bản sao của phân số hiện tại và phân số cộng vào
        return PhanSo(self.tu + other.tu, self.mau); // Trả về kết quả sau khi cộng tử số
    }

    // Nạp chồng toán tử trừ: Thực hiện quy đồng và trả về hiệu của hai phân số
    PhanSo operator-(PhanSo other) {
        PhanSo self = *this; // Tạo một bản sao của phân số hiện tại để khi quy đồng không thay đổi phân số hiện tại
        self.QuyDong(other); // Quy đồng mẫu số giữa bản sao của phân số hiện tại và phân số trừ đi
        return PhanSo(self.tu - other.tu, self.mau); // Trả về kết quả sau khi trừ tử số
    }

    // Nạp chồng toán tử nhân: Nhân tử với tử và mẫu với mẫu để trả về tích của hai phân số
    PhanSo operator*(PhanSo other) {
        return PhanSo(tu * other.tu , mau * other.mau);
    }

    // Nạp chồng toán tử chia: Thực hiện nhân nghịch đảo. Kiểm tra lỗi nếu chia cho phân số bằng 0
    PhanSo operator/(PhanSo other) {
        // Nếu tử số của phân số chia bằng 0 (tức là giá trị bằng 0), đánh dấu kết quả không hợp lệ
        if(tu == 0 || other.tu == 0) {
            PhanSo error;
            error.hople = false;
            return error;
        }
        // Trả về kết quả nhân nghịch đảo: (a/b) / (c/d) = (a*d) / (b*c)
        return PhanSo(tu * other.mau , mau * other.tu);
    }

};

int main() {
    PhanSo ps1,ps2;
    ps1.Nhap();
    ps2.Nhap();
    PhanSo tong = ps1 + ps2;
    PhanSo hieu = ps1 - ps2;
    PhanSo tich = ps1 * ps2;
    PhanSo thuong = ps1/ps2;
    cout << "Tong 2 phan so la: ";
    tong.Xuat();
    cout << "Hieu 2 phan so la: ";
    hieu.Xuat();
    cout << "Tich 2 phan so la: ";
    tich.Xuat();
    if(thuong.hople)
    {   cout << "Thuong 2 phan so la: ";
        thuong.Xuat();
    
    } else {
        cout << "Loi: Khong the chia cho 0!!!" << "\n";
    }
    
}