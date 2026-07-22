// deque basic;

#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(10);
    dq.push_front(5);
    dq.push_front(3);

    dq.push_back(6);
    dq.push_back(7);
    dq.push_back(1);

    dq.pop_back();    // 1 delete
    dq.pop_front();   // 3 delete

    for (auto it : dq) {
        cout << it << " ";
    }

    return 0;
}

ouput  after insert 3 5 10 6 7 1 after remove 5 10 6 7

// deque reverse basic;
#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq = {10, 20, 30, 40, 50};
    vector<int> ans;
    for(int i = 0;i<5;i++){
        ans.push_back(dq.back()); // dq.back() return data(int)  type hai 
        dq.pop_back(); // dq.pop_back() // void return type
    }
    for(int i = 0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

   

    return 0;
}
// output = {50,40,30,20,10};




// remove even number without make new deque and vector 

#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq = {11, 20, 31, 40, 55, 60, 71};

    for (auto it = dq.begin(); it != dq.end(); ) {
        if (*it % 2 == 0) {
            it = dq.erase(it);
        } else {
            it++;
        }
    }

    for (int x : dq) {
        cout << x << " ";
    }

    return 0;
}

// ouput 11 31 55 71




all the function of deque 
push_front()
push_back()

pop_front()
pop_back()

front()
back()

size()
empty()

erase()

begin()
end()

rbegin()
rend()