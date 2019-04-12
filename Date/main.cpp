#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
Date d1; // should default to 1/1/2000
Date d2(4,10,1992); // should init to 4/10/1992
// display dates to the screen
cout << "\nDate d1 is: ";
d1.Show();// 顯示1/1/2000
cout << "\nDate d2 is: ";
d2.Show();// 顯示4/10/1992 
d1.Input(); // Allow user to enter a date for d1
cout << "\nDate d1 is: ";
d1.Show();
d1.SetFormat('L'); // change format of d1 to "Long" format
cout << "\nDate d1 is: ";
d1.Show(); // print d1 -- should show now in long format,顯示 Jan 1, 2000

d2.Set(11,11,2000);//根據參數設定日期
cout << "\nDate d2 is: ";
d2.Show();// 顯示11/11/2000

d2.Set(13,11,2000);//根據參數設定日期,因為格式錯誤所以回傳false
cout << "\nDate d2 is: ";
d2.Show();//格式錯誤所以維持之前的 顯示11,11,2000

//顯示月、日、年，回傳數值不用回傳英文
cout << "\nDate d2 Month is: "<<d2.GetMonth();  // 顯示11
cout << "\nDate d2 Day is: "<<d2.GetDay();  // 顯示11
cout << "\nDate d2 Year is: "<<d2.GetYear();  // 顯示2000

Date d3(10, 31, 1998);// Oct 31, 1998
Date d4(6, 29, 1950); // June 29, 1950
d3.Increment(); // d3 is now Nov 1, 1998
cout << "\nDate d3 is: ";
d3.Show(); // 顯示11/1/1998
d4.Increment(5); // d4 is now July 4, 1950
cout << "\nDate d4 is: ";
d4.Show();//  顯示7/4/1950

cout << "\n d3 Compare d4 "<<d3.Compare(d4);// return 1 (since d4 comes first)
cout << "\n d4 Compare d3 "<<d4.Compare(d3);// return -1 (calling object is d4, comes first)





return 0;
} 
