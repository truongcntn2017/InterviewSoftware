# Interview Software In Leetcode

This is my solution of series interview in leetcode. I have cleanedmy code many times. In my opinion, it is optimal and easy to learn.The interview includes some topics. For example: Array, String, Sorting, Searching, Tree, Graphs, Dynamic Progamming, Math, Bits etc.

# Array 
## Level Easy
## Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

**Example 1**
```C++
Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
```

**Example 2**
```C++
Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
```

**Clarification**

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

```C++
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```



## Solution 
```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.empty()){
            int lastUniqueIndex = 0;
            
            for (int cur = 1; cur<nums.size(); ++cur){
                if (nums[lastUniqueIndex] != nums[cur]){
                    nums[++lastUniqueIndex] = nums[cur]; 
                }
            }
            
            nums.resize(lastUniqueIndex+1);
        }
        return nums.size();
    }
};


```

# String
## Level Easy
## First Unique Character in a String

 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1. 

 **Examples 0** 
 ```C++
 s = "leetcode"
 return 0.

 s = "loveleetcode",
 return 2.
 ```
## Solution

```C++
class Solution {
public:
    bool isUniqueCharacter( char ch, vector<int> freq){
        return freq[ch - 'a'] == 1;
    }
    vector<int> calculateFrequency(string s){
        vector<int> freq('z'-'a'+1, 0);
        
        for (int i=0; i<s.size();++i)
            freq[s[i] - 'a']++;
        
        return freq;
    }
    
    int firstUniqChar(string s) {
        int index = -1;
        vector<int> freq = calculateFrequency(s);
        
        for (int i=0; i<s.size();++i)
            if (isUniqueCharacter(s[i], freq)){ 
                index = i;
                break;
            }
        
        return index;
    }
};
```

# Sorting and Searching
## Level Easy
## Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

**Example**
```
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
```

## Solution 

```C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        if (m > 0 || n > 0){
            vector<int> res;
            int index1 = 0;
            int index2 = 0;
        
            while (index1 < m || index2<n){
                if ((index2 >= n) ||(index1 < m && nums1[index1] <= nums2[index2])){
                    res.push_back(nums1[index1++]);
                }
                else{
                    res.push_back(nums2[index2++]);
                }
            }   
            
            nums1 = res;
        }
    }
};
```

## First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**Example**
```C++
Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
```

## Solution
```C++
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        
        
        while (left < right){
            mid = left  + (right-left) / 2;
            if (isBadVersion(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};
```

# Dynamic Programming
## Level Easy
## Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

**Example 1**
```C++
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2**
```C++
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

## Solution

```C++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
            
        for (int i=2;i<=n;++i)
            f[i] = f[i-1]+f[i-2];
            
        return f[n];
    }
};
```

# Design 
## Level Easy
## Min stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

**Example**

```C++
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

## Solution
```C++
class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> myStack;
    stack<int> minStack;
    
    MinStack() {
    }
    void push(int x) {
        if (myStack.size()){
            minStack.push(min(x, minStack.top()));
            myStack.push(x);
        }
        else{
            myStack.push(x);
            minStack.push(x);
        }
    }
    
    void pop() {
        myStack.pop();
        minStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

```

# Math 
## Level: easy
## Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```C++
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

**Example 1**

```C++
Input: "III"
Output: 3
```

**Example 2**
```C++
Input: "IV"
Output: 4
```

**Example 3**
```C++
Input: "IX"
Output: 9
```

**Example 4**
```C++
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

**Example 5**
```
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

## Solution
```C++
class Solution {
public:
    int values['Z' - 'A' + 1] = {0};
   
    void initValues(){
         values['I' - 'A'] = 1;
         values['V' - 'A'] = 5;
         values['X' - 'A'] = 10;
         values['L' - 'A'] = 50;
         values['C' - 'A'] = 100;
         values['D' - 'A'] = 500;
         values['M' - 'A'] = 1000;
    }
    
    int caculateValues(stack<int>& myStack){
        int res = 2*myStack.top();
            
        while (!myStack.empty()){
            res -= myStack.top();
            myStack.pop();
        }
        
        return res;
    }
    
    int romanToInt(string s) {
        int sum = 0;
        
        if (!s.empty()){
            stack<int> myStack;
            // Step 1: init value in values array
            initValues();
            myStack.push(0);
            myStack.push(values[s[0] - 'A']);
            
            for (int i=1; i<s.size();++i){
                if (myStack.top() < values[s[i] - 'A']){
                    myStack.push(values[s[i] - 'A']);
                }
                else{
                    sum += caculateValues(myStack);
                    myStack.push(values[s[i] - 'A']);
                }
            }
            
            sum += caculateValues(myStack);
        }
        
        return sum;
    }
};
```
# Other 
## Level Easy
## Reverse Bits

Reverse bits of a given 32 bits unsigned integer.
**Example 1**
```C++
Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
```

**Example 2**
```C++
Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
```
 
## Solution
```C++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sum = 0;
        bitset<32> digits(n);
        
        for (int i=0; i<32; ++i){
            sum = sum << 1;
            sum += digits[i];
        }
        
        return sum;
    }
};
```

# Reference
* [Leetcode level easy](https://leetcode.com/explore/featured/card/top-interview-questions-easy/)

* [Leetcode level medium](https://leetcode.com/explore/interview/card/top-interview-questions-medium/)

* [Linkedin](https://www.linkedin.com/in/truong-le-19b755195/)
