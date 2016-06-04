#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;

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
      outfile << "Case #" << to_string(i+1) << ": " << endl;

      int n, m;
      int a[1000];
      infile >> n >> m;

      // read dimensions
      for(int k = 0; k < n; k++)
      {
         infile >> a[k];
      }
      
      // each query
      for(int p = 0; p < m; p++)
      {
         int l, r;
         long double dd = 1.0;
         infile >> l >> r;
         long double d = r - l + 1;

         for(int v = l; v <= r; v++)
         {
            dd *= pow(a[v], 1.0/d);
         }

         outfile << fixed << setprecision(9) << dd << endl;
      }
   }
   
   infile.close(); outfile.close();
   return 0;
}

