class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        // int l = log2(k)+1;
        int carry = 0;
        for(int i=num.size()-1; i>=0; i--)
        {
            int r = k%10;
            k /= 10;
            if(r+num[i]+carry >= 10)
            {
                num[i] = r+num[i]+carry - 10;
                carry = 1;
            }
            else
            {
                num[i] = r+num[i]+carry;
                carry = 0;
            }
        }
        
        // if(carry == 1)
        //     k += carry;
        
        while(k>0)
        {
            int r = k%10;
            k /= 10;
            if(r+carry >= 10)
            {
                num.insert(num.begin()+0, r+carry - 10);
                carry = 1;
            }
            else
            {
                num.insert(num.begin()+0, r+carry);
                carry = 0;
            }
        }
        
        if(carry == 1)
            num.insert(num.begin()+0, carry);
        
        return num;
    }
};