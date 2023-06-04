//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans = ""; // string which store our ans
            stack<char> st; //stack for reversing the string 
            for (int i = 0; i < s.length(); i++) // input in the stack
            {
                st.push(s[i]);
            }
        
            string num = "";// string which store the number 
            string sym = "";// string which store the operator
            while (!st.empty()) //run till stack is non empty
            {
                
                // first of all we have to get all the number which are before the
                // oerator
                if (st.top() >= '0' && st.top() <= '9') // this keep track of all the number before ops
                {
                    num.push_back(st.top());
                    st.pop();
                }
                //if we found any operator sym the we do reverse of our number then add to our ans variable with operator
                else {
        
                    sym.push_back(st.top()); // take the operator
                    st.pop(); // remove it from the stack
                    reverse(num.begin(), num.end()); // freverse the number eg if we have 56(in original) then our num varible store it as 65
                    // stack top will be 6 then 5 so we have to perform reverse;
                    ans.append(num); // store it in ans
                    ans.append(sym);
                    num = ""; sym = ""; // make again num and sym empty
                }
            }
            reverse(num.begin(), num.end()); // for last digit of the string suppose we have 20+9 so till our stack empty the ans will be 9+
            // and loop exit while the stack is empty our last digit which is store in the num = "02" we have to reverse it and again store in ans
            ans.append(num);
        
            return ans;

        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends