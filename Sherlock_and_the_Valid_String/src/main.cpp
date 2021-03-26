#include <bits/stdc++.h>
#include <map>
using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    std::map<char, int> container;
    
    for (auto i = s.begin(); i != s.end(); ++i) {
        std::map<char,int>::iterator p = container.find(*i);
        if (p != container.end()) {
            p->second += 1;
        } else {
            container.insert(std::pair<char,int>(*i, 1));
        }
        // container.insert(std::pair<char,int>(i, 1));
    }
    
    int difference = container.begin()->second;
    
    
    auto differentVal = std::find_if(container.begin(), container.end(), [&](std::pair<char,int> ppair) {
        return ppair.second != difference;
    });
    
     if (differentVal == container.end())
        return "YES";
    

    container.erase(differentVal);
    
     if (std::all_of(container.begin(), container.end(), [&](std::pair<char,int> ppair) {
        return (ppair.second == difference);
    })) {
        return "YES";
    } else {
        return "NO";
    }



}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}