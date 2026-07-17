// Two Pointer Technique 

// longest substring without repeating characters

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> hash(256, -1);
    int left = 0, right = 0, maxlength = 0;
    while (right < n) {
        if(hash[s[right]]!=-1){
            if(hash[s[right]] >= left)
            left = hash[s[right]] + 1;
        }
        hash[s[right]] = right;
        maxlength = max(maxlength, right - left + 1);
        right++;
    }
    cout << maxlength << endl;
    return 0;
}

// abcabcbb
// output = maxlength = 3;


// next example longest substring with atmost k distinct characters

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int maxlength = 0;
    int ll = 0;
    map<char,int>mpp;
    for(int r = 0;r<s.size();r++){
        mpp[s[r]]++;
        while(mpp.size() > k){
            mpp[s[ll]]--;
        if( mpp[s[ll]] == 0)
          mpp.erase(s[ll]);
           ll++;
        }
        maxlength = max(maxlength,r-ll+1);
    }
    cout << maxlength << endl;
}

// time complexity 0(n log k)

1. r को आगे बढ़ाओ।
2. mpp[s[r]]++
3. अगर distinct characters > k
      left से frequency घटाओ।
      frequency 0 हो जाए तो map से erase करो।
      left++
4. हर step पर answer update करो।
//



// next example max consecutive  ones 3

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int>a(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        int ll = 0;
        int maxlength = 0;
        int i = 0;
        int zero = 0;
        while(i<n){
            if(a[i] == 0)
            zero++;
        if( zero > k){
            if(a[ll] == 0) zero--;
            ll++;
        }
        if( zero <= k){
            maxlength = max(maxlength ,i-ll+1);
            i++;
        }
        }
    cout << maxlength << endl;
           
    }
}

//
1. Right pointer बढ़ाओ।
2. अगर element 0 है → zero++
3. अगर zero > k
      Left pointer बढ़ाओ
      अगर left वाला 0 था → zero--
4. हर valid window पर answer update करो।

//  a = [1,0,1,1]
// k = 1 output = 4 time complexity 


// another example fruits into baskets 

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int maxlength = 0;
    int ll = 0;
    map<int,int>mpp;
    int r = 0;
    while(r<n){
        mpp[a[r]]++;
        if(mpp.size() > k){
            mpp[a[ll]]--;
        if( mpp[a[ll]] == 0)
          mpp.erase(a[ll]);
           ll++;
        }
        if( mpp.size() <= k){
            maxlength = max(maxlength,r-ll+1);
        }
        r++;
    }
    cout << maxlength << endl;
}
// a = [1,2,1,3] k = 2 output = 3 time complexity 0(n log k)



// number of substrings containing all three characters a,b,c

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ll = 0;
    int r = 0;
    map<char,int>mpp;
    int ans = 0;
    while(r<n){
        mpp[s[r]]++;
        while(mpp.size() == 3){
            mpp[s[ll]]--;
            if(mpp[s[ll]] == 0)
            mpp.erase(s[ll]);
            ll++;
        }
        ans += ll;
        r++;
    }
    cout << ans << endl;
}
// a = "abcabc" output = 10 time complexity 0(n log k)


// second method to solve the same problem

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int>lastseen(3,-1);
    int cnt = 0;
    for(int i = 0;i<s.size();i++){
        lastseen[s[i]-'a'] = i;
        if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
            int mn = min({lastseen[0],lastseen[1],lastseen[2]}) + 1;
            cnt += mn;
        }
    }
    cout << cnt << endl;
}

// a = "abcabc"  no of substring containg all three characters output = 10 time complexity 0(n)



// longest repeating character replacement

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int ll = 0;
    int maxlength = 0;
    vector<int>hash(26,0);
    int maxf = 0;
    int r = 0;
         while(r<s.size()){
        hash[s[r]-'A']++;
        maxf = max(maxf,hash[s[r]-'A']);
        while(r-ll+1 - maxf > k){
            hash[s[ll]-'A']--;
            ll++;
        }
        maxlength = max(maxlength,r-ll+1);
        r++;
    }
    cout << maxlength << endl;
}


// AABABBA k = 1 output = 4 time complexity 0(n)
1. Right pointer बढ़ाओ।
2. frequency update करो।
3. maxf update करो।
4. अगर window size - maxf > k → left pointer बढ़ाओ और frequency update करो
5. हर valid window पर answer update करो।

// next example binary subarrays with sum = k; count subarrays with sum = k

int atmost(vector<int>&a,int k){
    if( goal < 0) return 0;
    int ll = 0;
    int cnt = 0;
    int sum = 0;
    for(int r = 0;r<a.size();r++){
        sum += a[r];
        while(sum > k){
            sum -= a[ll];
            ll++;
        }
        cnt += r-ll+1;
    }
    return cnt;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    cout << atmost(a,k) - atmost(a,k-1) << endl;
}


// most important  concept agar question equal to k ask kare 
// [<=k] - [<=k-1]  == atmost(a,k) - atmost(a,k-1); 

// example nums = [1,0,1,0,1] k = 2 [1,0,1]
[1,0,1,0]
[0,1,0,1]
[1,0,1]
ouput = 4;

//AtMost(2) = 14
//AtMost(1) = 10

//Exactly(2) = 14 - 10 = 4


// next example subarray with k means numbers of subarray with k different integers

#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& a, int k) {
    if (k < 0) return 0;

    map<int, int> mpp;
    int l = 0;
    int cnt = 0;

    for (int r = 0; r < a.size(); r++) {

        mpp[a[r]]++;

        while (mpp.size() > k) {
            mpp[a[l]]--;

            if (mpp[a[l]] == 0)
                mpp.erase(a[l]);

            l++;
        }

        cnt += r - l + 1;
    }

    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << fun(a, k) - fun(a, k - 1) << endl;
}
// nums = [1,2,1,2,3] k = 2;
// [1,2]
[1,2,1]
[1,2,1,2]
[2,1]
[2,1,2]
[1,2]
[1,2,3]
[2,3]
//
output 8;
AtMost(2) = 12
AtMost(1) = 4

Exactly(2) = 12 - 4 = 8

// minmum window substring 
// means ek string dusri string find karo return first index yha vo charcter aaya hai example string1 amanvv string2 vv output 3 index return

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<int> hash(256, 0);

    for (char c : t)
        hash[c]++;

    int l = 0;
    int r = 0;
    int cnt = 0;
    int minlen = INT_MAX;
    int start = -1;

    while (r < s.size()) {

        if (hash[s[r]] > 0)
            cnt++;

        hash[s[r]]--;

        while (cnt == t.size()) {

            if (r - l + 1 < minlen) {
                minlen = r - l + 1;
                start = l;
            }

            hash[s[l]]++;

            if (hash[s[l]] > 0)
                cnt--;

            l++;
        }

        r++;
    }

    if (start == -1)
        cout << "";
    else
        cout << s.substr(start, minlen);

    return 0;
}

// Input:
ADOBECODEBANC
ABC

Output:
BANC
// 


Revision Points
hash me t ki frequency store karte hain.
cnt = kitne required characters match ho chuke hain.
hash[s[r]]-- har baar karna hai.
Jab cnt == t.size() ho jaye, tab window ko left se shrink karo.
Sabse chhoti valid window ko answer bana lo.
Complexity
Time: O(n + m)
Space: O(256) = O(1)






