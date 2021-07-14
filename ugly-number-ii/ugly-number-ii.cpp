class Solution {
public:
    int nthUglyNumber(int n) {
        long long A=2,B=3,C=5;
        vector<int>v={1};
        int a=0,b=0,c=0;
        while(v.size()<n)
        {
            if(v[a]*A<=v.back()) a++;
            if(v[b]*B<=v.back()) b++;
            if(v[c]*C<=v.back()) c++;
            if(v[a]*A<=v[b]*B && v[a]*A<=v[c]*C) 
            {

                v.push_back(v[a]*A);
                a++;
            }
            else if(v[a]*A>=v[b]*B && v[b]*B<=v[c]*C) 
            {
                v.push_back(v[b]*B);
                b++;
            }
            else
            {
                v.push_back(v[c]*C);
                c++;
            }
        }
        return v.back();
    }
};

