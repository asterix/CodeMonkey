#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>

#define LIM 10e9

using namespace std;


bool move_snake(vector<pair<int,int> > *s,
                vector<pair<int,int> > *f,
                pair<int,int> d,
                int r, int c)
{

}


int main()
{
   ifstream infile;
   infile.open("test.in");
   ofstream outfile;
   outfile.open("test.out");

   int num_tests;
   infile >> num_tests;

   pair<int,int> left = make_pair(-1,1), right = make_pair(1,-1);

   for(int i = 0; i < num_tests; i++)
   {
      outfile << "Case #" << to_string(i+1) << ": ";

      int s, r, c, t = 0, xi;
      char lr;
      infile >> s >> r >> c;

      pair<int,int> dir = make_pair(1,0);
      pair<int,int> head = make_pair(0,0), tail = make_pair(0,0);
      vector<pair<int,int> > food, snake;

      food.clear(); snake.clear();

      // Snake is represented by line segments between every pair
      snake.push_back(head); snake.push_back(tail);

      while(t < LIM && t < s)
      {
         bool over;
         infile >> xi >> lr;

         // Forward until the move
         while(t < xi)
         {
            over = move_snake(&snake, &food, dir, r, c);
            t++;
         }

         if(over)
         {
            break;
         }

         // Turn
         pair<int,int> ndir;
         if(lr == 'R')
         {
            ndir = make_pair(dir.first * right.first, dir.second * right.second);
         }
         else
         {
            ndir = make_pair(dir.first * left.first, dir.second * left.second);
         }

         dir = ndir;
      }

      outfile << snake.size() << endl;
   }

   infile.close(); outfile.close();
   return 0;
}

