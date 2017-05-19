#include<iostream>
#include<vector>
#include<string>
using namespace std;

class MyCalendar{
public:
  int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int leapdays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
  int year; int month; int day; bool leap;
  MyCalendar(){}
  MyCalendar(int y, int m, int d){ year = y; month = m; day = d; leap = isLeapyear(); }
  void input(int y, int m, int d){ year = y; month = m; day = d; leap = isLeapyear(); }
  string output(){
    string y = to_string(year); string m = to_string(month); string d = to_string(day);
    return string(4-y.size(), '0') + y + string(2-m.size(), '0') + m + string(2-d.size(), '0') + d;
  }
  bool isLeapyear(){// うるう年か
    if( year % 400 == 0 ) return true;
    if( year % 100 == 0 ) return false;
    if( year % 4 == 0 ) return true;
    return false;
  }
  void nextDay(int n = 1){// n日後
    while( n != 0 ){
      day++;
      if( !leap && day > days[ month-1 ] ){ day = 1; month++; }
      if( leap && day > leapdays[ month-1 ] ){ day = 1; month++; }
      if( month > 12 ){ month = 1; year++; }
      leap = isLeapyear();
      n--;
    }
  }
  // 0001/01/01 からの経過日数
  int elapsedDay(){ return 365 * year + (year / 4) - (year / 100) + (year / 400) + (306 * (month+1)) / 10 + day - 429; }
};

// 0001/01/01 からの経過日数
int elapsedDay(int y, int m, int d){
  return 365 * y + (y / 4) - (y / 100) + (y / 400) + (306 * (m+1)) / 10 + d - 429;
}
int main(){

  MyCalendar c(2016, 5, 30);
  cout << c.output() << endl;
  cout << c.isLeapyear() << endl;
  cout << c.elapsedDay() << endl;
  c.nextDay(10);
  cout << c.output() << endl;
  cout << c.isLeapyear() << endl;
  cout << c.elapsedDay() << endl;


  return 0;
}
