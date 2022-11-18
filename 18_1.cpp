#include <iostream>

using namespace std;
/* 
class Date
{
  public:
    Date(int month, int day, int year);
};
*/

struct Day {
  explicit Day(int d) : val(d) {}
  int val;
};

struct Month {
  explicit Month(int d) : val(d) {}
  int val;
};

struct Year {
  explicit Year(int d) : val(d) {}
  int val;
};

struct Date {
  Date(const Month& m, const Day& d, const Year& y);
  //Date(Month m, Day d, Year y);  ???  
};

int main() {
  Date d(Month(11), Day(18), Year(2022));
}

/* 
enum class Mon {
  JAN,
  FEB,
  MAR,
  APR
};
*/