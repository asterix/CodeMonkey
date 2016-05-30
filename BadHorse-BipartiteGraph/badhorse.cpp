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

   map<string, vector<string>> xymap;
   map<string, int> cmap;
   
   for(int i = 0; i < num_tests; i++)
   {
      bool check = true;
      cmap.clear(); xymap.clear();

      outfile << "Case #" << to_string(i+1) << ": ";

      int numpairs;
      infile >> numpairs;
      
      // graph create
      for(int m = 0; m < numpairs; m++)
      {
         string xx, yy;
         infile >> xx >> yy;

         if(xymap.find(xx) == xymap.end())
         {
            // create node
            vector<string> v; v.push_back(yy);
            xymap.insert(make_pair(xx, v));
         }
         else
         {
            // insert edge
            xymap.find(xx)->second.push_back(yy);
         }

        /* if(xymap.find(yy) == xymap.end())
         {
            // create node
            vector<string> v; v.push_back(xx);
            xymap.insert(make_pair(yy, v));
         }
         else
         {
            // insert edge
            xymap.find(yy)->second.push_back(xx);
         }*/
      }


      for(auto it = xymap.begin(); it != xymap.end(); it++)
      {
         int d = 0;
         queue<string> q;
         q.push(it->first);

         while(!q.empty())
         {
            auto x = xymap.find(q.front());

            // look for start depth
            if(cmap.find(q.front()) != cmap.end())
            {
               d = cmap.find(q.front())->second;
            }

            //cout << "d = " << d << endl;

            if(x != xymap.end())
            {
               for(auto vt = x->second.begin(); vt != x->second.end(); vt++)
               {
                  if(cmap.find(*vt) == cmap.end())
                  {
                     // color bipartite graph
                     cmap.insert(make_pair(*vt, ((d + 1) % 2)));
                     q.push(*vt);
                  }
                  else
                  {
                     if(cmap.find(*vt)->second != ((d + 1) % 2))
                     {
                        check = false;
                     }
                  }
               }
            }
            
            q.pop();
         }
      }
      

      if(check)
      {
         outfile << "Yes" << endl;
      }
      else
      {
         outfile << "No" << endl;
      }
   }
   return 0;
}
