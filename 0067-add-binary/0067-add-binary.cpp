class Solution {
public:
    string addBinary(string a, string b) 
    {
        bitset<128> a1(a), b1(b), carry=0;
        string res;  
   
        while(b1!=0)
        {
            carry = (a1 & b1);
            a1 = (a1 ^ b1);
            b1 = carry << 1;
        }
    
        res = a1.to_string();
        
        int i=0; 
        while(res[i] == '0')
            i++;
        
        if(i >= res.size())
            return "0";
        
        return res.substr(i,-1);
    }
};