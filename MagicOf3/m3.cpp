#include <iostream>
#include <cmath>
#include <string>

typedef unsigned long long int ulli;
using namespace std;

bool is_all_ones(ulli num);

int main(int argc, char** argv)
{
   // Take input
   ulli inpx;
   cout << "Enter the number ending with 3 " << endl;
   cin >> inpx;

   if(inpx % 10 != 3)
   {
      cout << "Does not end with 3" << endl;
      return 1;
   }

   ulli d = 1, m = 1;

   while(m != 0)
   {
      m = ((m * 10) + 1) % inpx;
      d++;
   }

   string op = "";
   while(d != 0)
   {
      op += '1';
      d--;
   }

   cout << "The least multiple with all ones is: " << op << endl;
   return 0;
}


