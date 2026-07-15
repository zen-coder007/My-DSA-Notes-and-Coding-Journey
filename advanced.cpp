

// combination of sum elements of an array using recursion
class solution{
    public:
    void findcombination(int ind,int target,vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        // pick the element
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findcombination(ind+1, target-arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        // not pick the element
        findcombination(ind+1, target, arr, ans, ds);
    }
    public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        findcombination(0, target, arr, ans, ds);
        return ans;
    }
};
// ouput for arr = [10,1,2,7,6,1,5], target = 8
// [[1,1,6],[1,2,5],[1,7],[2,6]] it will find all the combinations of the elements of the array which sum up to the target value. it will not include the same combination twice because we are sorting the array and checking if the current element is same as the previous element then we will not pick the current element. it will also not include the same combination twice because we are using a set to store the combinations.

// time complexity of this recursion is O(2^n) because it will call the function 2 times for each function call. space complexity is O(n) because it will use stack memory for each function call. space complexity can be reduced to O(1) if we use iteration instead of recursion.

// another example combination sum 2 

class solution{
    public:
    void findcombination(int ind,int target,vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findcombination(i+1, target-arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        findcombination(0, target, arr, ans, ds);
        return ans;
    }
};
// ouput for arr = [10,1,2,7,6,1,5], target = 8
// [[1,1,6],[1,2,5],[1,7],[2,6]] it will find all the combinations of the elements of the array which sum up to the target value. it will not include the same combination twice because we are sorting the array and checking if the current element is same as the previous element then we will not pick the current element. it will also not include the same combination twice because we are using a set to store the combinations.

                                   []
                               target = 8

              /----------------------|----------------------\
             1                       2                      5
          target=7                target=6              target=3
        /   |   |   \               |                    |
       1    2   5    6              6                    X
      t=6 t=5 t=2 t=1              t=0
      |    |         |               |
      |    |         X            ✔ [2,6]
      |
      2
     t=4
      |
      5
     t=-1

      |
      6
     t=0
      |
   ✔ [1,1,6]

From first 1:

1 → 2 → 5
target 8→7→5→0

✔ [1,2,5]

1 → 7

✔ [1,7]


// time complexity of this recursion is O(2^n) because it will call the function 2 times for each function call. space complexity is O(n) because it will use stack memory for each function call. space complexity can be reduced to O(1) if we use iteration instead of recursion.

// another example subset sum 1 problem using recursion

class solution{
    public:
    void findsubsets(int ind, int sum, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if( ind == arr.size()){
            ans.push_back(ds);
            return;
        }
        // pick the element
        ds.push_back(arr[ind]);
        findsubsets(ind+1, sum+arr[ind], arr, ans, ds);
        ds.pop_back();

        // not pick the element
        findsubsets(ind+1, sum, arr, ans, ds);
    }
    public:
    vector<vector<int>> subsets(vector<int> &arr){
        vector<vector<int>> ans;
        vector<int> ds;
        findsubsets(0, 0, arr, ans, ds);
        return ans;
    }
};
// ouput for arr = [1,2,3]
// [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] it will find all the subsets of the elements of the array. it will include the empty subset and the subset which includes all the elements of the array.

                           []
                        index = 0
                       /          \
                  Take 1        Not Take 1
                   [1]              []
                  /   \            /    \
            Take2   Not2      Take2    Not2
           [1,2]     [1]       [2]      []
           /   \      / \      / \      / \
       T3     N3   T3  N3   T3  N3   T3  N3
   [1,2,3][1,2][1,3][1][2,3][2][3][]

// time complexity of this recursion is O(2^n)


// another example subset sum 2 problem using recursion

class solution{
    public:
    void findsubsets(int ind, int sum, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        ans.push_back(ds);
        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            findsubsets(i+1, sum+arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int> &arr){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        findsubsets(0, 0, arr, ans, ds);
        return ans;
    }
};
// ouput for arr = [1,2,2]
// [[],[1],[2],[1,2],[2,2],[1,2,2]] it will find all the subsets of the elements of the array. it will include the empty subset and the subset which includes all the elements of the array. 

                           []
                         index=0
                      (Store [])

                  /----------------\
             take 1               take 2
           index=1              index=2
          Store [1]            Store [2]
            /    \                |
      take 2    skip 2         take 2
      index=2                 index=3
    Store[1,2]              Store[2,2]
         |
      take 2
      index=3
   Store[1,2,2]

// time complexity of this recursion is O(2^n) 

// both difference subset sum 1 and subset sum 2 problems are similar but the difference is that in subset sum 2 problem we have to find the subsets of the array which have duplicate elements. so we have to sort the array and check if the current element is same as the previous element then we will not pick the current element. this will avoid the duplicate subsets.

// another example of print all permuation of the array using recursion

class solution{
    public:
    void findpermutation(int ind, vector<int> &arr, vector<vector<int>> &ans){
        if(ind == arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i = ind; i < arr.size(); i++){
            swap(arr[ind], arr[i]);
            findpermutation(ind+1, arr, ans);
            swap(arr[ind], arr[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int> &arr){
        vector<vector<int>> ans;
        findpermutation(0, arr, ans);
        return ans;
    }
};
// ouput for arr = [1,2,3]
// [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]] it will find all the permutations of the elements of the array. it will include the permutation which includes all the elements of the array. it will not include the same permutation twice because we are swapping the elements
                           []
                     (freq = 000)

            /---------------|---------------\
           1                2                3
      (100)             (010)            (001)

        /   \             /   \            /   \
       2     3           1     3          1     2
   (110) (101)      (110) (011)     (101) (011)

      |      |          |      |         |      |
      3      2          3      1         2      1
   (111)  (111)      (111)  (111)     (111)  (111)

      |      |          |      |         |      |
  [1,2,3] [1,3,2]  [2,1,3] [2,3,1]  [3,1,2] [3,2,1]

// second method of finding all the permutations of the array using recursion (swapping method )

class solution{
    public:
    void findpermutation(int ind, vector<int> &arr, vector<vector<int>> &ans){
        if(ind == arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i = ind; i < arr.size(); i++){
            swap(arr[ind], arr[i]);
            findpermutation(ind+1, arr, ans);
            swap(arr[ind], arr[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int> &arr){
        vector<vector<int>> ans;
        findpermutation(0, arr, ans);
        return ans;
    }
};

// this is recursion tree like that Level 0
                         [1,2,3]
                         index=0

          /----------------|----------------\
     swap(0,0)         swap(0,1)       swap(0,2)
      [1,2,3]          [2,1,3]         [3,2,1]

       /    \            /    \           /    \
 swap11   swap12     swap11  swap12   swap11  swap12
[1,2,3] [1,3,2]    [2,1,3] [2,3,1]  [3,2,1] [3,1,2]

     |        |          |       |         |       |
   Store    Store      Store   Store     Store   Store


// hard example sudoku 


class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {

        for (int i = 0; i < 9; i++) {

            // Row Check
            if (board[row][i] == c)
                return false;

            // Column Check
            if (board[i][col] == c)
                return false;

            // 3 x 3 Box Check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Traverse the complete board
        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                // Empty cell found
                if (board[i][j] == '.') {

                    // Try digits 1 to 9
                    for (char c = '1'; c <= '9'; c++) {

                        if (isValid(board, i, j, c)) {

                            // Place the digit
                            board[i][j] = c;

                            // Solve remaining board
                            if (solve(board))
                                return true;

                            // Backtrack
                            board[i][j] = '.';
                        }
                    }

                    // No digit worked
                    return false;
                }
            }
        }

        // No empty cell left
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// another example of n queen problem using recursion

class Solution{
     void solve( int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftrow,vector<int> &upper , vector<int> &lower,int n){
         if( col == n){
             ans.push_back(board);
             return;
         }
         for(int row = 0;row<n;row++){
             if( leftrow[row] == 0 &&  lower[row+col] == 0 && upper[n-1+col-row] == 0 ){
                 
                 // check if the queen can be placed in the current row and column or not if it is not placed in the same row or diagonal then we can place the queen in the current row and column

                 board[row][col] = 'Q';
                 leftrow[row] = 1;
                 lower[row+col] = 1;
                 upper[n-1+col-row] = 1;
                 
                 solve(col+1,board,ans,leftrow,upper,lower,n); // function call for next column

                 // backtracking

                 board[row][col] = '.';
                  leftrow[row] = 0;
                 lower[row+col] = 0;
                 upper[n-1+col-row] = 0;
                 
                 
             }
         }
     }
     public:
          vector<vector<string>>solveNQueens(int n){ // function to solve n queen problem
              vector<vector<string>> ans;
              vector<string> board(n);
              string s ( n,'.');
              for(int i = 0;i<n;i++){
                  board[i] = s;
              } 
              
          vector<int> leftrow(n,0),upper(2*n-1,0),lower(2*n-1,0); // to check if the queen is placed in the same row or diagonal or not
          
          solve(0,board,ans,leftrow,upper,lower,n); // function passed to solve the n queen problem
          return ans;
     }
          
};

// time complexity of this recursion is O(n!) because it will call the function n times for each function call. space complexity is O(n^2) because it will use stack memory for each function call. space complexity can be reduced to O(n) if we use iteration instead of recursion.

// another example m coloring problem using recursion


class Solution{

    // Check karta hai ki current node ko 'col' color dena safe hai ya nahi
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col){

        // Sabhi nodes ko check karo
        for(int k = 0; k < n; k++){

            // Agar k current node nahi hai,
            // aur k aur node ke beech edge hai,
            // aur k ka color bhi same hai,
            // to color assign nahi kar sakte.
            if(k != node && graph[k][node] && color[k] == col){
                return false;
            }
        }

        // Kisi neighbour ka same color nahi mila
        return true;
    }

    // Recursive function jo har node ko color assign karta hai
    bool solve(int node, int color[], int m, int N, bool graph[101][101]){

        // Base Case:
        // Agar saare nodes color ho gaye
        if(node == N){
            return true;
        }

        // Current node ke liye 1 se m tak har color try karo
        for(int col = 1; col <= m; col++){

            // Agar ye color safe hai
            if(isSafe(node, color, graph, N, col)){

                // Color assign kar do
                color[node] = col;

                // Next node ko color karne ki koshish karo
                if(solve(node + 1, color, m, N, graph)){
                    return true;
                }

                // Backtracking:
                // Agar aage solution nahi mila,
                // to current color hata do
                color[node] = 0;
            }
        }

        // Koi bhi color kaam nahi kiya
        return false;
    }

public:

    bool graphColoring(bool graph[101][101], int m, int N){

        // Sabhi nodes initially uncolored (0)
        int color[101] = {0};

        // Node 0 se recursion start
        return solve(0, color, m, N, graph);
    }
};