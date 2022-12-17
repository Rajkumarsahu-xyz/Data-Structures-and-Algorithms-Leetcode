class Solution {
public:
    bool judgeSquareSum(int c) 
    {
    	if(c < 0)
    		return false;
        
    	long long int i=0, j=sqrt(c);
    	while(i<=j)
    	{
    		long long int mid = i*i + j*j;
            if(mid == c)
                return true;
    		else if(mid<c)
    			i++;
    		else
    			j--;
    	}
        
    	return false;
    }
};