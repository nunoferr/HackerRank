#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long repeatedTimes = 0;
    
    char toFind = 'a';
    
    // number of times of the first char repeated in the original string
    long repeatedOriginal = std::count(s.begin(), s.end(), toFind);
    
    repeatedTimes = n /(long) s.length();
    
    repeatedTimes *= repeatedOriginal;
    
    s = s.substr(0, n % s.length());
    
    repeatedTimes += std::count(s.begin(), s.end(), toFind);
    
    return repeatedTimes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}