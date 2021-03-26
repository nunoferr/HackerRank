#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int biggestSum = arr[0][0] + arr[0][1] + arr[0][2] + arr[1][1] + arr[2][0] + arr[2][1] + arr[2][2];
    
    for (int line = 0; line < arr.size() - 2; line++) {
  
        for (int columnInLine = 0; columnInLine < arr[line].size() - 2; columnInLine++) {
            int glass = arr[line][columnInLine] + arr[line][columnInLine + 1] + arr[line][columnInLine + 2];
            glass += arr[line + 1] [columnInLine + 1];
            glass += arr[line + 2][columnInLine] + arr[line + 2][columnInLine + 1] + arr[line + 2][columnInLine + 2];
            if (glass > biggestSum) {
                biggestSum = glass;
            }
        }
    }
    return biggestSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}