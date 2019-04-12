#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
Date d1; // should default to 1/1/2000
Date d2(4,10,1992); // should init to 4/10/1992
// display dates to the screen
cout << "\nDate d1 is: ";
d1.Show();// print 1/1/2000
cout << "\nDate d2 is: ";
d2.Show();// print 4/10/1992 
d1.Input(); // Allow user to enter a date for d1
cout << "\nDate d1 is: ";
d1.Show();
d1.SetFormat('L'); // change format of d1 to "Long" format
cout << "\nDate d1 is: ";
d1.Show(); // print d1 -- should show now in long format,print Jan 1, 2000

d2.Set(11,11,2000);//set date
cout << "\nDate d2 is: ";
d2.Show();// print 11/11/2000

d2.Set(13,11,2000);//return false
cout << "\nDate d2 is: ";
d2.Show();//print 11,11,2000

//print Month, Day, Year
cout << "\nDate d2 Month is: "<<d2.GetMonth();  // print 11
cout << "\nDate d2 Day is: "<<d2.GetDay();  // print 11
cout << "\nDate d2 Year is: "<<d2.GetYear();  // print 2000

Date d3(10, 31, 1998);// Oct 31, 1998
Date d4(6, 29, 1950); // June 29, 1950
d3.Increment(); // d3 is now Nov 1, 1998
cout << "\nDate d3 is: ";
d3.Show(); // print 11/1/1998
d4.Increment(5); // d4 is now July 4, 1950
cout << "\nDate d4 is: ";
d4.Show();//  print 7/4/1950

cout << "\n d3 Compare d4 "<<d3.Compare(d4);// return 1 (since d4 comes first)
cout << "\n d4 Compare d3 "<<d4.Compare(d3);// return -1 (calling object is d4, comes first)





return 0;
} 
