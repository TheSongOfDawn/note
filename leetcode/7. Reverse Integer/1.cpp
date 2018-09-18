class Solution {
public:
    int reverse(int x) {
        bool flag=false;
        if(x<0)
        {
            x*=-1;
            flag=true;
        }
        long r=0;
        while(x)
        {
            r=r*10+(x%10);
            x=x/10;
            if(r>INT_MAX||r<INT_MIN)
            {
                r=0;
                break;
            }
        }
        if(flag)
        {
            r*=-1;   
        }
        return r;
    }
};