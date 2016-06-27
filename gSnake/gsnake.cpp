#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>

#define LIM 1e9

using namespace std;

// Hashing a pair
struct hash_pair
{
   template<typename F, typename S>
   size_t operator()(const std::pair<F,S> &x) const
   {
      return std::hash<F>()(x.first) ^ std::hash<S>()(x.second);
   }
};


bool move_snake(unordered_map<pair<int,int>, int, hash_pair> &s,
                unordered_set<pair<int,int>, hash_pair> &f,
                pair<int,int> d, pair<int,int> &nxt,
                int r, int c, int &len, int t)
{
   // Go to the next box in head's direction
   nxt.first += d.first,
   nxt.second += d.second;

   if(nxt.first > r) nxt.first = 1;
   if(nxt.first < 1) nxt.first = r;

   if(nxt.second > c) nxt.second = 1;
   if(nxt.second < 1) nxt.second = c;

   // Food box?
   if((nxt.first + nxt.second) % 2 != 0 &&
      f.find(nxt) == f.end())
   {
      f.insert(nxt);
      len++;
   }

   bool res;
   auto it = s.find(nxt);
   if(it != s.end() and t - len < it->second)
   {
      cout << "GAME OVER" << endl;
      res = true;
   }
   else
   {
      res = false;
   }

   s[nxt] = t;
   return res;
}


int main()
{
   ifstream infile;
   infile.open("test.in");
   ofstream outfile;
   outfile.open("test.out");

   int num_tests;
   infile >> num_tests;

   pair<int,int> left = make_pair(1,-1), right = make_pair(-1,1);

   for(int i = 0; i < num_tests; i++)
   {
      outfile << "Case #" << to_string(i+1) << ": ";
      cout << "Case #" << to_string(i+1) << ": ";

      int s, r, c, t = 0, xi, nr = 0, len = 1;
      char lr;
      infile >> s >> r >> c;

      pair<int,int> dir = make_pair(0,1), nxt = make_pair(1,1);
      unordered_map<pair<int,int>, int, hash_pair> snake;
      unordered_set<pair<int,int>, hash_pair> food;

      food.clear(); snake.clear();

      // Snake is a collection of points
      snake[nxt] = t; 

      bool over = false;
      while(nr < s)
      {
         infile >> xi >> lr;
         cout << "T= " << xi << " D=" << lr << endl;
         while(t <= xi && !over && t <= LIM)
         {
            // @ t=T turn
            if(t == xi)
            {
               if(lr == 'R')
               {
                  dir = make_pair(dir.second*right.second, dir.first*right.first);
               }
               else
               {
                  dir = make_pair(dir.second*left.second, dir.first*left.first);
               }
            }

            over = move_snake(snake, food, dir, nxt, r, c, len, t);
            cout << "t= " << t << " Head= (" << nxt.first << "," << nxt.second << ")"
                 << " Len= " << snake.size() << " Dir= (" << dir.first << "," << dir.second << ")" << endl;
            t++;
         }

         nr++;
      }

      int limit = dir.first == 0 ? t+c : t+r;
      while(!over && t <= limit)
      {
         over = move_snake(snake, food, dir, nxt, r, c, len, t);
         cout << "t= " << t << " Head= (" << nxt.first << "," << nxt.second << ")"
              << " Len= " << snake.size() << " Dir= (" << dir.first << "," << dir.second << ")" << endl;
         t++;
      }
      outfile << len << endl;
   }

   infile.close(); outfile.close();
   return 0;
}

