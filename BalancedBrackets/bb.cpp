
#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;


int main(){
  
    int t;
    cin >> t;
    map<char, char> mp = {{'[',']'},{'{','}'},{'(',')'}};
    
    for(int i = 0; i < t; i++)
    {
      string s;
      stack<char> stk;
      cin >> s;
      
      bool done = true;
      for(int k = 0; k < s.length(); k++)
      {
        char ls = s[k];
                
        if(mp.find(ls) != mp.end())
        {
          stk.push(mp[ls]);
        }
        else
        {
          if(!stk.empty())
          {
            if(stk.top() != ls)
            {
              done = false;
              break;
            }
            stk.pop();
          }
        }
      }
      
      if(!stk.empty() && done)
      {
        done = false;
      }
      
      if(done)
        cout << "YES";
      else
        cout << "NO";
      cout << endl;
    }
    return 0;
}
