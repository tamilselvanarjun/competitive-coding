//AC
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int rowMin = 1, rowMax = n;
    int colMin = 1, colMax = n;

    // diag1 = x+y = c
    // Store x coordinate for diags
    int diag1Min, diag1Max;
    // set diagmax
    if((r_q + c_q - n) >= 1)
        diag1Max = n;
    else
        diag1Max = (r_q + c_q - 1);

    // set diagmin
    if((r_q + c_q - 1) <= n) {
        diag1Min = 1;
    }
    else {
        diag1Min = (r_q + c_q - n);
    }

    // diag2 = x-y = c
    // store x coordinates
    int diag2Min, diag2Max;
    if((n + c_q - r_q) <= n)
        diag2Max = n;
    else
        diag2Max = r_q - c_q + n;

    if((1 + c_q - r_q) >= 1)
        diag2Min = 1;
    else
        diag2Min = r_q - c_q + 1;

    // time to crop out
    int x, y;
    for(int i=0; i<obstacles.size(); i++) {
        x = obstacles[i][0];
        y = obstacles[i][1];
        // Check cases
        // Same row, different columns
        if(x == r_q) {
            if(y > c_q)
                colMax = min(colMax, y-1);
            else
                colMin = max(colMin, y+1);
        }
        // Same column, different row
        else if(y == c_q) {
            if(x > r_q) 
                rowMax = min(rowMax, x-1);
            else
                rowMin = max(rowMin, x+1);
        }
        // Check for diag1
        else if((x + y) == (r_q + c_q)) {
            if(x > r_q) 
                diag1Max = min(diag1Max, x-1);
            else
                diag1Min = max(diag1Min, x+1);
        } 
        // Check for diag2
        else if((x - y) == (r_q - c_q)) {
            if(x > r_q)
                diag2Max = min(diag2Max, x-1);
            else
                diag2Min = max(diag2Min, x+1);
        }
    }
    // cout << " " << rowMax << " " << rowMin << " " << colMax << " " << colMin << " " << diag1Max << " " << diag1Min << " " << diag2Max << " " << diag2Min << endl;
    int count = (rowMax-rowMin) + (colMax-colMin) + (diag1Max-diag1Min) + (diag2Max - diag2Min);
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
