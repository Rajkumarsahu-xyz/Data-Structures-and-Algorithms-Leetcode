class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int fives=0, tens=0, twenties=0;
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                //cout << "f" << " ";
                fives++;
            }
            
            else if(bills[i] == 10)
            {
                //cout << "t" << " ";
                if(fives > 0)
                {
                    tens++;
                    fives--;
                }
                
                else
                    return false;
            }
            
            else if(bills[i] == 20)
            {
                //cout << "tw" << " ";
                twenties++;
                while(tens > 0   &&  bills[i]-5 >= 10)
                {
                    tens--;
                    bills[i] -= 10;
                }
                
                while(fives > 0  &&  bills[i]-5 >= 5)
                {
                    fives--;
                    bills[i] -= 5;
                }
                
                if(bills[i] > 5)
                {
                    return false;
                }
            }
            
            //cout << fives << " " << tens << " " << twenties << endl;
            
        }
        
        return true;
    }
};