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

   map<int, vector<pair<int, int> > > gmap;
   vector<int> ineff, visited;
   
   for(int i = 0; i < num_tests; i++)
   {
      gmap.clear();
      ineff.clear();

      outfile << "Case #" << to_string(i+1) << ": " << endl;

      int n, m;
      infile >> n >> m;
      
      // graph create
      for(int p = 0; p < m; p++)
      {
         int u, v, w;
         infile >> u >> v >> w;

         if(gmap.find(u) != gmap.end())
         {
            gmap.find(u)->second.push_back(make_pair(v, w));
         }
         else
         {
            vector<pair<int, int> > x;
            x.push_back(make_pair(v, w));
            gmap.insert(make_pair(u, x));
         }
      }

      // consider all road inefficient at first
      for(int p = 0; p < n; p++)
      {
         ineff.push_back(p);
      }

      // dijsktras shortest path search - remove nodes in shortest paths
      for(int p = 0; p < n; p++)
      {
         visited.clear();

         visited.push_back(p);


      }

      // print inefficient roads
      for(auto it = ineff.begin(); it != ineff.end(); it++)
      {
         outfile << *it << endl;
      }
   }
   infile.close(); outfile.close();
   
   return 0;
}

