#include <iostream>
using namespace std;
 
int getNoOfWays(int n)
{
   
    if (n <= 2)
      return n;
 
    return getNoOfWays(n - 1) + getNoOfWays(n - 2);
}
int main()
{
    cout << getNoOfWays(4) << endl;
    cout << getNoOfWays(3);
    return 0;
}
