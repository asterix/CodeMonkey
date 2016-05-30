#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

#define PI 3.14159265
#define G  9.8

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
      long double v, d;
      infile >> v >> d;

      long double interim = (d * G)/pow(v, 2);
      long double theta = (asin(interim > 1.0? 1.0 : (interim < -1.0? -1.0 : interim)) / 2) * (180 / PI);
      outfile << setprecision(9) << theta << endl;
   }

   infile.close(); outfile.close();
   return 0;
}

