#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdint>
#include <queue>
#include <climits>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;


int getbit(uint64_t k)
{
   // N = log2(K + 1)
   uint64_t n = llround(ceil(log2(static_cast<long double>(k + 1))));

   // L = 2^N - 1
   uint64_t l = (static_cast<uint64_t>(1) << n) - 1;
   cout << "k = " << k << ", l = " << l << ", n = " << n << endl;

   // recurrence
   if(k == (l + 1)/2)
   {
      return 0;
   }
   else
   {
      return (1 - getbit(l - k + 1));
   }
}

int main()
{
   ifstream infile;
   infile.open("test.in");
   ofstream outfile;
   outfile.open("test.out");

   int num_tests;
   infile >> num_tests;

   for(int i = 0; i < num_tests; i++)
   {
      int bit = 0;
      outfile << "Case #" << to_string(i+1) << ": ";
      cout << "Case #" << to_string(i+1) << ": ";

      uint64_t k;
      infile >> k;

      int p = getbit(k);
      outfile << p << endl;
      cout << p << endl;
   }


   infile.close(); outfile.close();
   return 0;
}


