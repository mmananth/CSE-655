#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

class test
{
  private:
    int count,c;
  public:
    test();
    //~test();
    void print();
};

inline test::test()
{
  count=10;
  c=count;
}

/*
inline test::~test()
{
  if (count==0) cout<<"error"<<endl;
}
*/

inline void test::print()
{
  int i=0;
  cout<<count<<endl;
  for(i=0;i<c;i++) count--;
}

int main()
{
  test a;
  a.print();
  a.print();
}
