#include <iostream>
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
      int moves = 0;
      vector<string> deck; deck.clear();
      outfile << "Case #" << to_string(i+1) << ": ";

      int num;
      infile >> num;
      infile.ignore(INT_MAX, '\n');
      
      // copy cards
      for(int m = 0; m < num; m++)
      {
         string card;
         getline(infile, card);
         deck.push_back(card);
      }

      // insertion sort
      // p+++++jk------------r
      // p = start, + = sorted, - = unsorted, r = end
      for(auto it = (deck.begin() + 1); it != deck.end(); it++)
      {
         if(*(it - 1) > *it)
         {
            vector<string>::iterator index;
            for(auto itx = deck.begin(); itx <= (it - 1); itx++)
            {
               if(*it < *itx)
               {
                  index = itx;
                  break;
               }
            }
            string elem = *it;
            deck.erase(it);
            deck.insert(index, elem);
            moves++;
         }
      }

      // print sorted
      /*cout << "Case #" << to_string(i+1) << ": ";
      for(auto it = deck.begin(); it != deck.end(); it++)
      {
         cout << *it << endl;
      }
      cout << endl;*/

      outfile << moves << endl;
   }

   infile.close(); outfile.close();
   return 0;
}

