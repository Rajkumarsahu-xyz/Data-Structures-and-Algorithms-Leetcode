class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 1) 
            return 1;
        
        int i=0;
        int a=1;
        for (int j=1; j<nums.size(); j++)
        {
            if(nums[j] != nums[i]  ||  (nums[j] == nums[i] && a==1))
            {
                a++;
                if (nums[j] != nums[i]) 
                    a=1;
                i++;
                // if (nums[j] != nums[i]) 
                //     a=1;
                nums[i] = nums[j];
                
                //cout << nums[i] << " " << nums[j] << " " << a << endl;
            }
        }
        
        return i+1;
    }
};