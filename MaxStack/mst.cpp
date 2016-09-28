
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main() 
{
  int n, q, x;
  cin >> n;
  
  stack<int> stk, max;
  max.push(0);
  
  for(int i = 0; i < n; i++)
  {
    cin >> q;
    
    switch(q)
    {
      case 1:
        cin >> x;
        stk.push(x);
      
        if(x > max.top())
        {
          cout << "new max = " << x << endl;
          max.push(x);
        }
        break;
      case 2:
        if(!stk.empty())
        {
          if(stk.top() == max.top())
          {
            max.pop();
            cout << "new max = " << max.top() << endl;
          }
          
          stk.pop();
        }
        break;
      case 3:
        cout << max.top() << endl;
      default:
        ;
    }
  }
  return 0;
}

