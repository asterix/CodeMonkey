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

   map<pair<int, int>, int> gmap;
   vector<tuple<pair<int, int>, bool > ineff;
   
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

         // Direction 1
         pair edge = make_pair(u, v);
         if(gmap.find(edge) != gmap.end())
         {
            gmap.find(edge)->second = w;
         }
         else
         {
            gmap.insert(make_pair(make_pair(u, v), w));
         }

         ineff.push_back(make_tuple(edge, true));

         // Undirected - direction 2
         edge = make_pair(v, u);
         if(gmap.find(edge) != gmap.end())
         {
            gmap.find(edge)->second = w;
         }
         else
         {
            gmap.insert(make_pair(make_pair(v, u), w));
         }
      }

      // dijsktras shortest path search - remove nodes in shortest paths
      for(int p = 0; p < n; p++)
      {
         visited.clear();

         visited.push_back(p);


      }

      // print inefficient roads
      for(int i = 0; i < ineff.size(); i++)
      {
         if(get<1>(ineff.at(i)))
         {
            outfile << i << endl;
         }
      }
   }
   infile.close(); outfile.close();
   
   return 0;
}

