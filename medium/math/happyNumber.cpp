class Solution {
public:

vector<int> toDigits(int n){
    vector<int> res;

    while (n>0){
        res.push_back(n % 10);
        n /= 10;
    }

    return res;
}

int sumSquare(vector<int> a){
    int sum = 0;

    for (int x: a){
        sum += x*x;
    }

    return sum;
}

bool isHappy(int n) {
    unordered_set<int> visited;
    int tempSum = sumSquare(toDigits(n));

    // Init
    while (!visited.count(n) && tempSum != 1){
        visited.insert(n);
        n = tempSum;
        tempSum = sumSquare(toDigits(n));
    }

    return (tempSum == 1);
}
};
