#include <bits/stdc++.h>
using namespace std;

class IPO {
public:
    // for same capital, we give more priority to the
    // project with higher profit
    static bool compare(pair<int,int>& a, pair<int,int>& b) {
        if(a.first == b.first) return a.second>b.second;
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int> profits, vector<int> capital) {
        int n = profits.size();
        vector<pair<int,int>> arr;

        for(int i=0; i<n; ++i) {
            arr.push_back(make_pair(capital[i],profits[i]));
        }
   //using camparator sorting
        sort(begin(arr), end(arr), compare);

        int idx = 0;
        //making maximum heap or maximum priority Queue;
        priority_queue<int> pq;

        // while we are left with some projects
        while(k>0 and idx<n) {
            // we insert profits of all the projects with capital <= w
            // into the priority queue
            while(idx<n && arr[idx].first <= w) {
                pq.push(arr[idx].second);
                ++idx;
            }
            // if profit<=0 then simply skip
            while(!pq.empty() and pq.top() <= 0) {
                pq.pop();
            }
            // if we don't have any project with capital <= w, then we
            // can't do any more project as arr is sorted on the
            // basis of capital
            if(pq.empty() and idx<n and arr[idx].first > w) break;
            // else do the current project with maximum profit
            --k;
            w += pq.top();
            pq.pop();
        }
        // All the projects present in pq are having capital <= w
        // So, if we can still complete some projects
        while(k>0 and !pq.empty() and pq.top() > 0) {
            --k;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
 int main(){
   IPO ipo;
   int n,c,PC;
      cout<<"ENTER the  no of project to be done:"<<endl;
        cin>>n;
          cout<<"Enter the present capital:"<<endl;
            cin>>c;
             cout<<"Enter the number of work that give profit with certain capital:"<<endl;
              cin>>PC;
               vector<int>v,v1;
                for(int i=0;i<PC;i++)
{
                   int a[i],b[i];
                   cout<<"Enter the profit"<<" "<<i+1<<":"<<endl;
                    cin>>a[i];
                     v.push_back(a[i]);
                      cout<<"Enter the capital for"<<" "<<i+1<<" " <<"profit"<<":";
                        cin>>b[i];
                        v1.push_back(b[i]);
}


// verify for the description portion
//   vector<int> v = {1,2,3}, v1 = {0,1,1};
// cout<<ipo.findMaximizedCapital(2,0,v,v1);
   cout<<"The total capital is:"<< ipo.findMaximizedCapital(n,c, v, v1);
}
