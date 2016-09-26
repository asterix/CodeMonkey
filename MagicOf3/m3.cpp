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

   ulli tri = inpx + 4;

   while(!is_all_ones(tri * inpx))
   {
      tri += 10;
   }

   cout << "The least with all ones is: " << tri*inpx << endl;
   return 0;
}


bool is_all_ones(ulli num)
{
   bool res = true;

   while(num > 1)
   {
      if(num % 10 != 1)
      {
         res = false;
         break;
      }

      num /= 10;
   }

   return res;
}
