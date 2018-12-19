//AC
#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);


// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	vector<int> densescore;
	densescore.push_back(scores[0]);
	for(size_t i=1; i<scores.size(); i++) {
		if(scores[i] != scores[i-1])
			densescore.push_back(scores[i]);
	}

	vector<int> ranks;
	int pointerDense = densescore.size()-1;
	int pointerRank = 0;
	// All less than last element
	while(pointerRank < alice.size()) {
		if(alice[pointerRank] < densescore[pointerDense]) 
			ranks.push_back(densescore.size()+1);
		else
			break;
		pointerRank++;
	}
	// In between
	while((pointerRank < alice.size())&&(pointerDense >= 0)) {
		if(densescore[pointerDense] > alice[pointerRank]) {
			ranks.push_back(pointerDense + 2);
			pointerRank++;
		}
		else {
			pointerDense--;			
		}
	}

	// End, either all alice scores are greater
	while(pointerRank < alice.size()) {
		ranks.push_back(1);
		pointerRank++;
	}

	return ranks;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
