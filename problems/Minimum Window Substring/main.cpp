#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int, int> par;
int tLetters[255];
int sLetters[255];
int solLetters[255];
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> starts;
        memset(tLetters, 0, sizeof(tLetters));
        memset(sLetters, 0, sizeof(sLetters));
        memset(solLetters, 0, sizeof(solLetters));
        int ini = -1, fin = -1, size = -1, TL = 0, tl = 0, pos = 0;
        int iniSol, finSol;
        for (int i = 0; i < t.size(); i++)
        {
            if (!tLetters[t[i]])
                TL++;
            tLetters[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (tLetters[s[i]] == 0)
                continue;
            starts.push_back(i);
            solLetters[s[i]]++;
            tl += (solLetters[s[i]] == tLetters[s[i]]);
            if (ini == -1)
                ini = i;
            if (tl < TL)
                continue;
            if (fin == -1 && tl == TL)
            {
                fin = i;

                iniSol = ini;
                finSol = fin;
                size = fin - ini + 1;
            }

            while (solLetters[s[ini]] > tLetters[s[ini]])
            {
                pos++;
                solLetters[s[ini]]--;
                ini = starts[pos];
            }
            fin = i;
            if (size > fin - ini + 1)
            {
                iniSol = ini;
                finSol = fin;
                size = fin - ini + 1;
            }
        }
        if(size == -1)
            return "";
        return s.substr(iniSol, size);
    }
};
int main()
{
    string a, b;
    freopen("input.in", "r", stdin);
    // cin>>a>>b;
    a = "bba";
    b = "ab";
    Solution sol;
    cout << sol.minWindow(a, b);
}