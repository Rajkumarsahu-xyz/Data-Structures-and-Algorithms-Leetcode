class Allocator {
public:
    
    vector<int> blocks;
    Allocator(int n) 
    {
        blocks.resize(n);
    }
    
    int allocate(int size, int mID) 
    {
        int ctr = 0;
        int j = -1;
        for(int i=0; i<blocks.size(); i++)
        {
            if(blocks[i] != 0)
            {
                j = -1;
                if(ctr < size)
                {
                    ctr = 0;
                    continue;
                }
            }
            
            else
            {
                if(ctr == 0)
                    j = i;
                ctr++;
                if(ctr == size)
                {
                    for(int k=0; k<ctr; k++)
                    {
                        blocks[j+k] = mID;
                    }
                    return j;
                }
            }
        }
        
        return -1;
    }
    
    int free(int mID) 
    {
        int ctr = 0;
        for(int i=0; i<blocks.size(); i++)
        {
            if(blocks[i] == mID)
            {
                ctr++;
                blocks[i] = 0;
            }
        }
        
        return ctr;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */