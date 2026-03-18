#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Date {
    int Day, Month, Year;

    // Khởi tạo ngày tháng năm, mặc định ngày/tháng/năm là 1/1/1 nếu không truyền tham số
    Date(int d = 1, int m = 1, int y = 1) : Day(d), Month(m), Year(y) {}

    // Phân loại tháng: trả về 0 (tháng 2), 1 (tháng có 30 ngày), hoặc -1 (tháng có 31 ngày)
    int MonthType() {
        if (Month == 2) return 0; 
        if (Month == 4 || Month == 6 || Month == 9 || Month == 11) return 1; 
        return -1; 
    }

    // Hàm kiểm tra năm nhuận, nếu có thì trả về true, ngược lại là false
    bool checkLeapYear() 
    { 
        // Nếu chia hết cho 400 thì là năm nhuận
        if (Year % 400 == 0) 
            return true; 
        // Nếu chia hết cho 4 nhưng không chia hết cho 100 thì là năm nhuận
        if (Year % 4 == 0 && Year % 100 != 0) 
            return true;
        return false; 
    } 

    // Kiểm tra xem ngày tháng năm hiện tại có tồn tại trong thực tế hay không
    bool ValidDate() {
        // Kiểm tra các giới hạn cơ bản của ngày, tháng, năm
        if(Day <= 0 || Month <= 0 || Year <= 0 || Month > 12) return false;
        
        int maxDay;
        int type = MonthType();
        
        // Xác định số ngày tối đa trong tháng dựa trên loại tháng và năm nhuận
        if(type == 1) {
            maxDay = 30;
        }
        else if(type == -1) {
            maxDay = 31;
        }
        else maxDay = (checkLeapYear() ? 29 : 28);
        
        // Ngày hợp lệ nếu không vượt quá số ngày tối đa của tháng đó
        return Day <= maxDay;
    } 

    // Nhập dữ liệu ngày tháng năm, tự động bắt lỗi nhập chữ hoặc ngày không hợp lệ
    void NhapDate() {
        while(true){
            cout << "Nhap lan luot ngay thang nam (cach nhau boi dau cach): ";
            // Kiểm tra kiểu dữ liệu đầu vào có phải là số nguyên không
            if(cin >> Day >> Month >> Year) {
                if(ValidDate()) {
                    break; // Nếu dữ liệu hợp lệ thì thoát vòng lặp
                }
                else {
                    cout << "Ngay/Thang/Nam khong hop le!!!" << "\n";
                }
            } else {
                cout << "Vui long nhap so nguyen duong" << "\n";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa sạch các ký tự lỗi hoặc thừa trong bộ đệm
            }
        }
    }

    // Tính toán và cập nhật giá trị của ngày tiếp theo
    void NextDay() {
        Day += 1;
        // Nếu cộng 1 ngày mà ngày không hợp lệ (vượt quá số ngày trong tháng)
        if(!ValidDate()) {
            Day = 1;      // Reset về ngày 1 của tháng mới
            Month += 1;   // Tăng tháng lên 1
            
            // Nếu tăng tháng mà tháng không hợp lệ (vượt quá tháng 12)
            if(!ValidDate()) {
                Month = 1; // Reset về tháng 1 của năm mới
                Year += 1; // Tăng năm lên 1
            }
        }
    }

    // In thông tin ngày tháng năm ra màn hình theo định dạng Day/Month/Year
    void InDate() {
        cout << "Date: " << Day << "/" << Month << "/" << Year << "\n";
    }
};

int main() {
    Date a;
    a.NhapDate();
    a.NextDay();
    cout << "Ngay tiep theo la: ";
    a.InDate();
    return 0;
}