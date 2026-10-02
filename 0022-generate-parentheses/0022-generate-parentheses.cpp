#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;

                char top = st.top();

                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }

    void getParenthesis(int size, vector<string>& ans, string cs) {
        if (cs.size() == size) {
            if (isValid(cs)) {
                ans.push_back(cs);
            }
            return;
        }

        getParenthesis(size, ans, cs + '(');
        getParenthesis(size, ans, cs + ')');
    }

    vector<string> generateParenthesis(int n) {
        int size = n * 2;
        vector<string> ans;

        getParenthesis(size, ans, "");

        return ans;
    }
};