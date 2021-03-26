#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    std::string alphabetLetters = "QWERTYUIOPASDFGHJKLZXCVBNM";

    int deletions = 0;
    int str1C, str2C;
    for (auto i = alphabetLetters.begin(); i != alphabetLetters.end(); ++i) {
        str1C = std::count(a.begin(), a.end(), tolower(*i));
        str2C = std::count(b.begin(), b.end(), tolower(*i));

        if (str1C > str2C) {
            deletions += str1C - str2C;
        } else {
            deletions += str2C - str1C;
        }
    }
    
    return deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}