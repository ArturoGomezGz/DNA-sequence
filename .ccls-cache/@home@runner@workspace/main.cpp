/* Implementation of the longest common substring using dynamic programming.
The program receives the names of two text files containing the strings
to be compared and prints out the longest common substring.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
// Function to read the content of a file into a string
std::string readFile(const std::string &fileName) {
std::ifstream file(fileName);
if (!file.is_open()) {
std::cerr << "Error: Could not open the file " << fileName << std::endl;
exit(1);
}
std::string content((std::istreambuf_iterator<char>(file)),
std::istreambuf_iterator<char>());
file.close();
return content;
}
// Function to find the longest common substring using dynamic programming
std::string longestCommonSubstring(const std::string &s1, const std::string &s2) {
int n = s1.length();
int m = s2.length();
std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
int maxLength = 0;
int endingIndex = 0;

// Build the DP table
for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                        if (dp[i][j] > maxLength) {
                                maxLength = dp[i][j];
                                endingIndex = i;
                        }
                } else {
                        dp[i][j] = 0;
                }
        }
}

if (maxLength == 0) {
        return "";
}
return s1.substr(endingIndex - maxLength, maxLength);
}
int main() {
std::string file1, file2;
std::cout << "Enter the name of the first file: ";
std::cin >> file1;
std::cout << "Enter the name of the second file: ";
std::cin >> file2;
std::string s1 = readFile(file1);
std::string s2 = readFile(file2);
std::string lcs = longestCommonSubstring(s1, s2);
std::cout << "Longest common substring: " << lcs << std::endl;
return 0;
}
/*
Example:
Enter the name of the first file: file1.txt
Enter the name of the second file: file2.txt
Longest common substring: bcd
*/
