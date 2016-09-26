#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
   int x;
   cin >> x;

   vector<int> pfs;

   // Collect all 2s - even numbers
   while(x % 2 == 0)
   {
      x /= 2;
      pfs.push_back(2);
   }

   int d = 3;
   while(x > 1)
   {
      if(x % d == 0)
      {
         x /= d;
         pfs.push_back(d);
      }
      else
      {
         d += 2;
      }
   }

   for(auto it = pfs.begin(); it != pfs.end(); it++)
   {
      cout << *it << " ";
   }
   cout << endl;
}
