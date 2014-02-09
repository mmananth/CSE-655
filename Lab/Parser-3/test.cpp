#include <iostream>
#include <string>
#include <sstream>
#include <locale>
using namespace std;

int main ()
{
  locale loc;
  string str="1776ad";
  if ( isdigit(str,loc) )
  {
    int year;
    stringstream(str) >> year;
    cout << "The year that followed " << year << " was " << (year+1) << ".\n";
  }
  return 0;
}
