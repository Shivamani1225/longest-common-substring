#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findLongestCommonSubstring(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    
    vector<vector<int> > table(len1 + 1, vector<int>(len2 + 1, 0));
    
    int maxLength = 0;
    int endIndex = 0;
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                if (table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }
    
    cout << "Table:" << endl;
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    
    string result = str1.substr(endIndex - maxLength + 1, maxLength);
    cout << "\nLongest Common Substring: " << result << endl;
    cout << "Length: " << maxLength << endl;
}

int main() {
    string str1, str2;
    
    cout << "Enter the first string: ";
    cin >> str1;
    
    cout << "Enter the second string: ";
    cin >> str2;
    
    cout << "\nString 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl << endl;
    
    findLongestCommonSubstring(str1, str2);
    
    return 0;
}
