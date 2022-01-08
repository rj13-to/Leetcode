class Cashier {
public:
    unordered_map<int,int>mp;
    int k;
    int nn;
    int discountt; 
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
    {
        for(int i=0;i<products.size();i++)
        {
            mp[products[i]] = prices[i];
        }
        k = nn = n;
        discountt = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        double f = 0;
        for(int i=0;i<product.size();i++)
        {
            f += mp[product[i]] * amount[i];
        }
        k--;
        if(k == 0)
        {
            k = nn;
            return ((f) * (100-discountt)) / 100;
        }
        else return f;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */