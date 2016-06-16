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
   unsigned int *g;
   unsigned int *d;
   int sz;

   vector<vector<pair<int,int> > > p;

   // Clear graph
   void clear()
   {
      for(int a = 0; a < sz * sz; a++)
         g[a] = -1;
      for(int a = 0; a < sz; a++)
         g[a*sz+a] = 0;
   }

   void cleard()
   {
      for(int a = 0; a < sz; a++)
         d[a] = -1;
   }

   void clearp()
   {
      for(auto i = p.begin(); i != p.end(); i++)
         i->clear();
   }

   graph() = delete;
   graph(int s)
   {
      sz = s;
      g = new unsigned int [sz * sz];
      d = new unsigned int [sz];

      for(int i = 0; i < sz; i++)
      {
         vector<pair<int,int> > x;
         p.push_back(x);
      }
   }

   ~graph()
   {
      delete[] g;
      delete[] d;
   }
};


int search_min(graph &g, vector<int> &v)
{
   unsigned int min = -1;
   int min_idx = -1;
   for(int i = 0; i < g.sz; i++)
   {
      if((g.d[i] < min) &&
         (find(v.begin(), v.end(), i) == v.end()))
      {
         min = g.d[i];
         min_idx = i;
      }
   }

   return min_idx;
}


void dijkstra_sps(int a, graph &g)
{
   g.cleard(); g.clearp();
   g.d[a] = 0;

   vector<int> v; v.clear();

   while(v.size() < g.sz)
   {
      int min = search_min(g, v);
      v.push_back(min);

      for(int i = 0; i < g.sz; i++)
      {
         if(g.g[min*g.sz+i] != -1)
         {
            if(g.d[i] > (g.d[min] + g.g[min*g.sz+i]))
            {
               g.d[i] = g.d[min] + g.g[min*g.sz+i];
               g.p.at(i) = g.p.at(min);
               g.p.at(i).push_back(make_pair(min, i));
            }
         }
      }
   }
}


int main()
{
   ifstream infile;
   infile.open("test.in");
   ofstream outfile;
   outfile.open("test.out");

   int num_tests;
   infile >> num_tests;

   vector<tuple<int, int, unsigned int> > ed, ef;
   
   for(int i = 0; i < num_tests; i++)
   {
      outfile << "Case #" << to_string(i+1) << ": " << endl;
      
      int n, m, u, v;
      unsigned int w;
      infile >> n >> m;
      graph g(n), e(n);

      g.clear(); e.clear(); ed.clear(); ef.clear();

      // Create graph - mark efficient paths
      for(int a = 0; a < m; a++)
      {
         infile >> u >> v >> w;
         if(g.g[u*g.sz+v] > w)
         {
            g.g[u*g.sz+v] = w; g.g[v*g.sz+u] = w;
         }
         ed.push_back(make_tuple(u, v, w));
      }

      // Search shortest paths
      for(int a = 0; a < n; a++)
      {
         // a -> all shortest paths
         dijkstra_sps(a, g);

         // Save efficient paths
         for(auto q = g.p.begin(); q != g.p.end(); q++)
         {
            for(auto c = q->begin(); c != q->end(); c++)
            {
               ef.push_back(make_tuple(c->first, c->second, g.g[c->first*g.sz+c->second]));
            }
         }
      }

      // Write inefficient paths out
      for(int a = 0; a < ed.size(); a++)
      {
         if(find(ef.begin(), ef.end(), ed.at(a)) == ef.end())
            outfile << a << endl;
      }
   }


   infile.close(); outfile.close();
   return 0;
}


