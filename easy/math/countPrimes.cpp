class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        
        if (n > 2){
            vector<char> is_prime(n, true);
            is_prime[0] = is_prime[1] = false;
        
            for (int i = 2; i * i < n; i++) {
                if (is_prime[i]) {
                    for (int j = i * i; j < n; j += i)
                        is_prime[j] = false;
                }
            }
            
            // count prime number
            for (int i=0; i<n;++i){
                if (is_prime[i]){
                    res++;
                }
            }
        }
        
        return res;
    }
};
