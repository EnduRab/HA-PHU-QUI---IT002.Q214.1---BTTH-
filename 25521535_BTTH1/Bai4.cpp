#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

//4 6 9 11

int LinearSearch(const vector<int> &a, int x) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == x) {
            return 1;
        }
    }
    return -1;
}

struct Date {
    int Day,Month,Year;

    Date(int d = 1, int m = 1, int y = 1) : Day(d), Month(m), Year(y) {
        ValidDate();
    }

    int MonthType() {
        vector<int> Thang30 = {4,6,9,11};
        if(Month == 2) {
            return 0;
        }
        else {
            return LinearSearch(Thang30,Month);
        }
    }

    bool checkLeapYear() 
    { 
        if (Year % 400 == 0) 
            return true; 
        if (Year % 4 == 0 && Year % 100 != 0) 
            return true;
        return false; 
    } 

    bool ValidDate() {
        if(Day <= 0 || Month <= 0 || Year <= 0 || Month > 12) return false;
        int maxDay;
        int type = MonthType();
        if(type == 1) {
            maxDay = 30;
        }
        else if(type == -1) {
            maxDay = 31;
        }
        else maxDay = (checkLeapYear() ? 29 : 28);
        return Day <= maxDay;
    } 

    void NhapDate() {
        while(true){
            cout << "Nhap lan luot ngay thang nam (cach nhau boi dau cach): ";
            if(cin >> Day >> Month >> Year) {
                if(ValidDate()) {
                    break;
                }
                else {
                    cout << "Ngay/Thang/Nam khong hop le!!!" << "\n";
                }
            } else {
                cout << "Vui long nhap so nguyen duong" << "\n";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa sạch các ký tự lỗi hoặc thừa trong bộ đệm cho đến khi gặp phím Enter
            }
        }
    }

    void NextDay() {
        Day += 1;
        if(!ValidDate()) {
            Day = 1;
            Month += 1;
            if(!ValidDate()) {
                Month = 1;
                Year += 1;
        }
        }
    }

    void InDate() {
        cout << "Date: " << Day << "/" << Month << "/" << Year << "\n";
    }
};



int main() {
    Date a;
    a.NhapDate();
    a.NextDay();
    a.InDate();
}