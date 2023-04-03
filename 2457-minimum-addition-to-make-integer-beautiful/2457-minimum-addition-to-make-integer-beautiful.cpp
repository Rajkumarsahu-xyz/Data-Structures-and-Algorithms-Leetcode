class Solution {
public:
    
//     bool isfeasible(long long n, long long x, int target)
//     {
//         long long a=n, sum=0;
//         while(a>0)
//         {
//             long long d = a%10;
//             // cout << d << " ";
//             sum += d;
//             a /= 10;
//         }
//         cout << sum+x<< endl;
        
//         if(sum+x <= target)
//             return true;
//         else 
//             return false;
//     }
    
    long long digsum(long long  n)
    {
        long long sum=0;
        while(n)
        {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) 
    {
//         long long a=n, sum=0;
//         while(a>0)
//         {
//             long long d = a%10;
//             sum += d;
//             a /= 10;
//         }
//         if(sum <= target)
//             return 0;
        
//         long long ans=INT_MAX;
//         long long min = INT_MAX;
        
//         long long i=0, j=n;
//         while(i <= j)
//         {
//             //cout << i << " " << j << endl;
//             long long mid = i + (j-i);
//             if(isfeasible(n, mid, target))
//             {
//                 ans =  mid;
//                 j = mid-1;
//             }
            
//             else
//                 i = mid+1;
//         }
        
//         return ans;
        
        
        long long a = n;
        long long sum = 0;
        while(a > 0)
        {
            sum += (a%10);
            a /= 10;
        }
        
        if(sum <= target)
            return 0;
        
        a = n;
        long long f = 10;
        long long ctr = n;
        while((a>0) && (digsum(ctr) > target))
        {
            long long r = a%f;
            // sum -= r;
            // cout << f << " " << r << endl;
            ctr = (a+f-r);
            f *= 10;
            // a /= 10;
        }
        
        return ctr-n;
        
        
        
//         if(digsum(n)<=target)
//             return 0;
//         long long count=10;
//         long long temp=n;
        
//         while(digsum(temp)> target){
//             long long mod=n%count;
//              temp=n+count-mod;
            
//             count*=10;
//         }
//         return temp-n;
        
    }
};