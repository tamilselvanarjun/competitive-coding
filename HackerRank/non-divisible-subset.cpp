//AC
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the nonDivisibleSubset function below.
int nonDivisibleSubset(int k, vector<int> S) {
    vector<int> divisible;
    // Get all 0s
    for(int i=0;i<k;i++) {
        divisible.push_back(0);
    }

    // Get counts of all remainders
    for(int i=0;i<S.size();i++) {
        int remainder = S[i]%k;
        divisible[remainder]++;
    }

    // get count
    int count = 0;
    if(divisible[0] > 0)
        count += 1;

    for(int i=1; i<=k/2; i++) {
        int r1 = i, r2 = k-i;
        if(r1 == r2) {
            // i = k-i -> i = k/2 , then we can't include 2 numbers
            count += (int)(divisible[i] > 0);
        }
        else {
            // These 2 numbers sum to K. Can't add from both. Add max.
            count += max(divisible[i], divisible[k-i]);
        }
    }

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

    string S_temp_temp;
    getline(cin, S_temp_temp);

    vector<string> S_temp = split_string(S_temp_temp);

    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        int S_item = stoi(S_temp[i]);

        S[i] = S_item;
    }

    int result = nonDivisibleSubset(k, S);

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
