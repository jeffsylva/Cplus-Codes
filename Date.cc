#include <string>
#include <iostream>
#include <sstream>
using namespace std;
  int MonthDaySt[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
class Date
{
   int day, month, year;

public:
   Date();

   // d is the day (1-31)
   // m is the month (1-12)
   // y is the year (>1)
   Date(int d, int m, int y);

   // returns the number of days from the date of the object to date d
   int operator - (Date d);
   // returns a date days ahead of the date of the object
   Date operator + (int d);
   int numOfLeapYears(int c);
   Date(int d);
   string monthCase(int mon);

   // returns a string representation of the date of the object
   std::string toString();
   int numDaysInMonthLeap(int d);
   int numDaysInMonth(int da);
   
   int MonthDayStart(int month);
   bool leapYear(int bear);
   int daysTo1_1_1800();
private:
   // returns the number of days from 1 Jan 1800 to the date;


   // constructs a date representing d days after Jan 1, 1800
 
};

Date::Date()
{
   day=1;  month=1; year = 2016;
}

Date::Date(int d, int m, int y)
{
   day=d; month=m; year=y;

}


Date Date::operator+(int d)
{
   return Date(daysTo1_1_1800() + d);

}

int Date::operator-(Date d)
{
   return daysTo1_1_1800() - d.daysTo1_1_1800();
}

bool Date::leapYear(int bear)
{
   if (bear%4==0 || bear%400 == 0 && bear%100 != 0) return true;
  else return false;
}

// What day each month starts on (counting from 0)

/*int Date::MonthDayStart(int monti)
{
   if (leapYear(year) && monti >= 2) return MonthDaySt[monti]+1;
   return MonthDaySt[monti];

}
*/

// incorrect implementation! Does not take into account leap years and
// months with 30/31 days

int Date::daysTo1_1_1800()
{

   int objectholder, dateholder, result;
   objectholder= 365* 1800 + (1800/4) - (1800/100) + (1800/400) + 1 + ((153 * 1 +8)/5);
   dateholder= 365 * year + (year/4) - (year/100)+ (year/400) + day + ((153* month + 8)/5);
   result=dateholder-objectholder;
   return result+1;
   /*int store = (1800 *365) + numOfLeapYears(1800);
   cout << numOfLeapYears(1800) << endl;
   int clone;
   clone = (((year) * 365)+ numOfLeapYears(year) + (MonthDayStart(month-1)) + (day-1));
   return clone-store;
   */
   //return (year-1800) * 365 + (month-1)*30 + day-1;
}

// incorrect implementation. See daysTo1_1_1800()

Date::Date(int d)
{
   
   int holder=1800;
   while (d>365)
   {
      if (leapYear(holder) && holder!=1800)
	 d-=366;
      else
	 d-=365;
      holder +=1;
   }
   year = holder;
   // cout << "d = :" << d << endl;
   if (leapYear(holder))
   {
      if(d <= 31)
      {
	 month = 1;
      }
      else if(d<= 60)
      {
	 month = 2;
      }
      else if ( d <= 91)
      {
	 month = 3;
      }
      else if ( d <= 121)
      {
	 month = 4;
      }
      else if(d <= 152)
      {
	 month = 5;
      }
      else if (d <= 182 )
      {
	 month = 6;
      }
      else if(d <= 213)
      {
	 month = 7;
      }
      else if(d <= 244)
      {
	 month = 8;
      }
      else if(d <= 274)
      {
	 month = 9;
      }

      else if(d <= 305)
      {
	 month = 10;
      }
      else if(d <= 335)
      {
	 month = 11;
      }
      else 
      {
	 month = 12;
      }

   }
      
   else
   {
      if(d <= 31)
      {
	 month == 1;
      }
      else if(d<= 59)
      {
	 month == 2;
      }
      else if (d <= 90)
      {
	 month == 3;
      }
      else if (d <= 120)
      {
	 month == 4;
      }
      else if(d <= 151)
      {
	 month = 5;
      }
      else if (d <= 181 )
      {
	 month = 6;
      }
      else if(d <= 212)
      {
	 month = 7;
      }
      else if(d <= 243)
      {
	 month = 8;
      }
      else if(d <= 273)
      {
	 month = 9;
      }

      else if(d <= 304)
      {
	 month = 10;
      }
      else if(d <= 334)
      {
	 month = 11;
      }
      else
      {
	 month = 12;
      }
   }

   if (month==1)
   {
	 day=d;
   }

   else
      {
	 if(leapYear(year))
	 {
	   day= d - numDaysInMonthLeap(month-1);
	 }
	 else 
	 day= d - numDaysInMonth(month-1);
      }
}


int Date::numDaysInMonthLeap(int da)
{
   switch(da)
   {
	 case 1: return 31;break;
	 case 2: return 60; break;
	 case 3: return 91; break;
	 case 4: return 121; break;
	 case 5: return 152; break;
	 case 6: return 182; break;
	 case 7: return 213; break;
	 case 8: return 244; break;
	 case 9: return 274; break;
	 case 10: return 305; break;
	 case 11: return 335; break;
	 case 12: return 366; break;
      }

}

int Date::numDaysInMonth(int dar)
{
   switch(dar)
   {
   case 1: return 31;break;
   case 2: return 59; break;
   case 3: return 90; break;
   case 4: return 120; break;
   case 5: return 151; break;
   case 6: return 181; break;
   case 7: return 212; break;
   case 8: return 243; break;
   case 9: return 273; break;
   case 10: return 304; break;
   case 11: return 334; break;
      case 12: return 365; break;
   }
}

int Date::numOfLeapYears(int code)
{
   int store1, store2;
   store1=((1800)/4 - (1800)/100 + (1800)/400);
   store2=((code-1)/4 - (code-1)/100 + (code-1)/400);
   return store2-store1;
}

string Date :: monthCase(int mon)
{
   string ban="";
   switch(mon)
   {
      case 1 : ban = "JAN"; break;
      case 2 : ban = "FEB"; break;
      case 3 : ban = "MAR"; break;
      case 4 : ban = "APR"; break;
      case 5 : ban = "MAY"; break;
      case 6 : ban = "JUN"; break;
      case 7 : ban = "JUL"; break;
      case 8 : ban = "AUG"; break;
      case 9 : ban = "SEP"; break;
      case 10: ban = "OCT"; break;
      case 11: ban = "NOV"; break;
      case 12: ban = "DEC"; break;
   }

   return ban;
}

// also incorrect. Use the formatting options to use 2 digits for day and month
// and 4 digits for the year

std::string Date::toString()
{
   std::ostringstream sstr;
   //cout << "year : " << year << endl;
   //cout << "month : "; cout << monthCase(month); cout << endl;
   cout << "day : "  << day << endl;
   sstr << year << "-" << monthCase(month) << "-" << day;
   //cout<<"Number of Leap Years between :" << numOfLeapYears(year); cout << endl;
   //cout << "Days to 1800: " << daysTo1_1_1800(); cout<<endl;
   return sstr.str();
}


int main()
{
   int yyyy, mm, dd, n;
   /*cout << "Enter a date using format d yyyy-mm-dd : " << endl;
   cin >> yyyy >> mm >> dd;
   cout << endl;
   */
   cout << "Enter a number n of days to display the n consecutive dates beginning with d : " ;
   cin >> n;

   Date d(20,1,2016);
   
   for (int i=0; i < n; i++)
   {
      int c=0;
   Date d1=d+c; 
   cout << "d is " << d.toString() << endl;
   c++;
    
   }
   /*cout << "d is " << d.toString() << endl;
   Date d2=d + 30;
   cout << "d2 is " << d2.toString() << endl;
   */
   //int &ban=78912;
   /* Date d(20,1,2016);
   cout << "d is " << d.toString() << endl;
   //Date a(78912);
   
   //cout << "a is " << a.toString() << endl;
   Date d1=d+32;
      cout << "d1 is " << d1.toString() << endl;
      //std::cout << "d is " << d.toString() << endl;// " and d1 is " << d1.toString() << std::endl; 
      */
   return 0;
}
