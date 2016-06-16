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


struct graph
{
   unsigned int g[100][100];

   // Clear graph
   void clear()
   {
      for(int a = 0; a < 100; a++)
         for(int b = 0; b < 100; b++)
            g[a][b] = -1;
   }
};


void dijkstra_sps(int a, graph *g, vector<pair<int, int> > *p)
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

   graph g, e;
   vector<pair<int, int> > p;
   vector<tuple<pair<int, int>, bool> > ed;
   
   for(int i = 0; i < num_tests; i++)
   {
      outfile << "Case #" << to_string(i+1) << ": " << endl;
      
      int n, m, u, v;
      unsigned int w;
      infile >> n >> m;

      g.clear(); e.clear(); p.clear();

      // Create graph - mark efficient paths
      for(int a = 0; a < m; a++)
      {
         infile >> u >> v >> w;
         if(g.g[u][v] > w)
         {
            g.g[u][v] = w; g.g[v][u] = w;
            e.g[u][v] = a; e.g[v][u] = a;
         }
         ed.push_back(make_tuple(make_pair(u, v), true));
      }

      // Search shortest paths
      for(int a = 0; a < n; a++)
      {
         // a -> all shortest paths
         dijkstra_sps(a, &g, &p);

         // Mark shortest paths as efficient
         for(int h = 0; h < ed.size(); h++)
         {
            if(find(p.begin(), p.end(), get<0>(ed.at(h))) != p.end())
            {
               if(e.g[get<0>(ed.at(h)).first][get<0>(ed.at(h)).second] == h)
               {
                  get<1>(ed.at(h)) = false;
               }
            }
         }
      }
      
   }


   infile.close(); outfile.close();
   return 0;
}


