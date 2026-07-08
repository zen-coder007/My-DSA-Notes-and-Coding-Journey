#include <bits/stdc++.h>
using namespace std;
// when a function call itself until a base condition is met, it is called recursion

// base condition is a condition which stops the recursion
// example of recursion 
 int cnt = 0;
 void print(){
    if(cnt == 3){
        return;
    }
    cout << cnt << endl;
    cnt++;
    print();
 }
 int main(){
    print();
    return 0;
 }
 output: // 0 1 2 
 //  it is recursion tree function call itself until the base condition is met, in this case cnt == 3 is the base condition which stops the recursion.
 

 second example of print name n times  using recursion
    void printName(int i, int n){ // i is the 1 initial
        if(i > n){
            return;
        }
        cout << "aman" << endl; 
        printName(i + 1, n);
    }
    int main(){
        int n;
        cin >> n;
        printName(1, n);
        return 0;
    }
    // output: // aman aman aman aman  (if n = 4) it function call printName(1,3) then printName(2,3) then printName(3,3) then printName(4,3) then printName(5,3) and then it will stop because i > n is the base condition which stops the recursion.

// time complexity of recursion is O(n) because it will call the function n times and space complexity is O(n) because it will use stack memory for each function call. space complexity can be reduced to O(n) if we use iteration instead of recursion.

    // next problem print numbers from 1 to n using linear  recursion
  void printNumbers(int n, int i = 1){
    if(i > n){
        return;
    }
    cout << i << endl;
    printNumbers(n, i + 1);
  }
  int main(){
    int n;
    cin >> n;
    printNumbers(1,n);
    return 0;
  }

  // print numbers from n to 1 using linear recursion

    void printNumbers(int n, int i = n){
        if(i < 1){
            return;
        }
        cout << i << endl;
        printNumbers(n, i - 1);
    }
    int main(){
        int n;
        cin >> n;
        printNumbers(n,n);
        return 0;
    }
// function start f(3,3) then f(3,2) then f(3,1) then f(3,0) and then it will stop because i < 1 is the base condition which stops the recursion.



// print number from 1 to n using backtracking recursion
    

    void printNumbers(int n, int i = n){
        if(i < 1){
            return;
        }
        printNumbers(n, i - 1);
        cout << i << endl;
    }
    int main(){
        int n;
        cin >> n;
        printNumbers(n,n);
        return 0;
    }
// output 1 2 3  (if n = 3) it function call printNumbers(3,3) then printNumbers(3,2) then printNumbers(3,1) then printNumbers(3,0) and then it will stop because i < 1 is the base condition which stops the recursion. after that it will print the value of i in reverse order because of backtracking.

// backtracking reccursion function call hota hai aur phir base condition check hoti hai aur phir function call ke baad print hota hai. isliye output 1 to n print hoga.

// simple recursion function call hota hai aur phir print hota hai aur phir base condition check hoti hai. isliye output n to 1 print hoga.

// exmple n to 1 using backtracking recursion
    void printNumbers(int n, int i = 1){
        if(i > n){
            return;
        }
        printNumbers(n, i + 1);
        cout << i << endl;
    }
    int main(){
        int n;
        cin >> n;
        printNumbers(n,1);
        return 0;
    }
// output 3 2 1 (if n = 3) it function call printNumbers(3,1) then printNumbers(3,2) then printNumbers(3,3) then printNumbers(3,4) and then it will stop because i > n is the base condition which stops the recursion. after that it will print the value of i in reverse order because of backtracking.

// print sum of n natural number using parameterized recursion
    int sum( int i = n, int s = 0){
        if(i < 1){
            cout << s << endl;
            return s;
        }
         sum(i-1,s+i);
    }
    int main(){
        int n;
        cin >> n;
         sum(n,0);
        return 0;
    }

// output 6 (if n = 3) it function call sum(3,0) then sum(2,3) then sum(1,5) then sum(0,6) and then it will stop because i < 1 is the base condition which stops the recursion. after that it will print the value of s which is 6.



// print sum of n natural number using functional recursion
    int sum(int n){
        if(n == 0){
            return 0;
        }
        return n + sum(n-1);
    }
    int main(){
        int n;
        cin >> n;
        cout << sum(n) << endl;
        return 0;
    }

// output 6 (if n = 3) it function call sum(3) then sum(2) then sum(1) then sum(0) and then it will stop because n == 0 is the base condition which stops the recursion.


//  factorial of n using functional recursion
    int factorial(int n){
        if(n == 0){
            return 1;
        }
        return n * factorial(n-1);
    }
    int main(){
        int n;
        cin >> n;
        cout << factorial(n) << endl;
        return 0;
    }
// time complexity of factorial is O(n) and space complexity is O(n) because it will use stack memory for each function call. space complexity can be reduced to O(1) if we use iteration instead of recursion.

// reverse the array using  parameterized recursion
    void reverseArray(int arr[], int n, int i = 0){
        if(i >= n/2){
            return;
        }
        swap(arr[i], arr[n-i-1]);
        reverseArray(arr, n, i+1);
    }
    int main(){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        reverseArray(arr, n);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        return 0;
    }
    // second method fuctional recursion
    void reverseArray(int l ,int r){
        if(l >= r){
            return;
        }
        swap(arr[l], arr[r]);
        reverseArray(l+1, r-1);
    }
    int main(){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        reverseArray(0, n-1);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        return 0;
    }
    // function call reverseArray(0, n-1) then reverseArray(1, n-2) then reverseArray(2, n-3) and then it will stop because l >= r is the base condition which stops the recursion. after that it will print the array in reverse order.

    // example of palindrome using recursion
    bool isPalindrome(int i , string &s){
        if(i >= s.size()/2){
            return true;
        }
        if(s[i] != s[s.size()-i-1]){
            return false;
        }
        return isPalindrome(i+1, s);
    }
    int main(){
        string s;
        cin >> s;
        if(isPalindrome(0, s)){
            cout << "Palindrome" << endl;
        }
        else{
            cout << "Not Palindrome" << endl;
        }
        return 0;
    }

    // multiple recursion example print fibonacci series using recursion

    int fibonacci(int n){
        if(n <= 1){
            return n;
        }
        return fibonacci(n-1) + fibonacci(n-2);
    }
    int main(){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cout << fibonacci(i) << " ";
        }
        return 0;
    }

    // time complexity of fibonacci is O(2^n) 
    // because it will call the function 2 times for each function call. space complexity is O(n) because it will use stack memory for each function call. space complexity can be reduced to O(1) if we use iteration instead of recursion.

    // it makes a recursion tree f(4) then f(3) and f(2) then f(3) will call f(2) and f(1) and f(2) will call f(1) and f(0) and f(2) call f(1) and f(0) and f(1) will call f(0) and f(0) will return 0 and f(1) will return 1 and f(2) will return 1 and f(3) will return 2 and f(4) will return 3. so the output will be 0 1 1 2 3.



    // print all subsequences -----  a contiguous or non-contiguous sequence of characters that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. for example, the subsequences of "abc" are "", "a", "b", "c", "ab", "ac", "bc", "abc". , another example of sequence is array [3 2 1] the subsequences are [], [3], [2], [1], [3,2], [3,1], [2,1], [3,2,1].

    #include <bits/stdc++.h>
    using namespace std;
    void printf(int ind,vector<int> &ds, int arr[], int n){
        if(ind == n){
            for(auto it: ds){
                cout << it << " ";
            }
            if( ds.size() == 0){
                cout << "[]";
            }
            cout << endl;
            return;
        }
    // not pick the element
        printf(ind+1, ds, arr, n);
    // pick the element
        ds.push_back(arr[ind]);
        printf(ind+1, ds, arr, n);
        ds.pop_back();
    }
    int main(){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<int> ds;
        printf(0, ds, arr, n);
        return 0;
    }
// time complexity of this recursion is O(2^n) because it will call the function 2 times for each function call. space complexity is O(n) because it will use stack memory for each function call. space complexity can be reduced to O(1) if we use iteration instead of recursion.


// another example print sum of v subsequences

    #include <bits/stdc++.h>
    using namespace std;
    void printf(int ind,vector<int> &ds, int arr[], int n, int sum){
        if(ind == n){
            cout << sum << endl;
            return;
        }
    // not pick the element
        printf(ind+1, ds, arr, n, sum);
    // pick the element
        ds.push_back(arr[ind]);
        printf(ind+1, ds, arr, n, sum + arr[ind]);
        ds.pop_back();
    }
    int main(){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<int> ds;
        printf(0, ds, arr, n, 0);
        return 0;
    }



