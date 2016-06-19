#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
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
      outfile << "Case #" << to_string(i+1) << ": ";

      int n;
      infile >> n;
      
      for(int n = 0; n < numpairs; n++)
      {
      }
   }

   infile.close(); outfile.close();
   return 0;
}

