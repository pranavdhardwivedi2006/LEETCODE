class Bank {
vector<long long> trker;
int n;
public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        trker = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        int a1 = account1 - 1;
        int a2 = account2 - 1;
        if((a1 >= n || a1 < 0)) return false;
        if((a2 >= n || a2 < 0)) return false;
        if(trker[a1] < money) return false;
        trker[a1] -= money;
        trker[a2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        int a = account - 1;
        if((a >= n || a < 0)) return false;
        trker[a] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int a = account - 1;
        if((a >= n || a < 0) || trker[a] < money) return false;
        trker[a] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */