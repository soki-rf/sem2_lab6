#include <iostream>
#include <string>
#include <stdexcept>


class MyException: public std::out_of_range {
private:
    int day, month, year;
public:
    MyException(const std::string&msg, int d, int m, int y) : out_of_range(msg), day(d), month(m), year(y) {}
    void print(){
        std::cerr<< "Wrong date: " << day << "." << month << "." << year << std::endl;
    }
};

class Date{
private:
    int day, month, year;
    bool isOK(){
        if (year < 1) return false;
        if ((month < 1) || (month > 12)) return false;
        if (day < 1) return false;
        int mxDay = 31;
        switch(month){
            case 4: case 6: case 9: case 11:
                mxDay = 30;
                break;
            case 2:
                if((year % 4 == 0) && (year % 100 != 0)){
                    mxDay = 29;
                    break;
                } else{
                    mxDay = 28;
                    break;
                }
        }
        return day <= mxDay;
    }
public:
    Date(int d, int m, int y): day(d), month(m), year(y) {
        if (!isOK()){
            throw MyException("Wrong date", day, month, year);
        }
    }
    void print()
    {
        std::cout << "Date: " << day << "." << month << "." << year << std::endl;
    }
};



int main(){
    try{
        Date t1(20, 2, 2020);
        Date t2(31, 4, 2024);
    }
    catch(MyException& ex){
        std::cerr << "Error " << ex.what() << std::endl;
        ex.print();
    }
    return 0;
}
