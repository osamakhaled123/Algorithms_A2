#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Job{
    public:
        char JopID;
        int Deadline;
        int profit;
};


bool compare(Job first, Job second){
    return first.profit > second.profit;
}

int main(){

    char ID;
    int n,i,deadline,profit;
    cin>>n;
    Job Jobs[n];
    vector<Job> final(n);
    for(i=0;i<n;i++){
        cin>>ID>>deadline>>profit;
        Jobs[i].JopID = ID;
        Jobs[i].Deadline = deadline;
        Jobs[i].profit = profit;
    }
    int time = 0;
    sort(Jobs,Jobs+n,compare);

//    for(i=0;i<n;i++){
//        cout<<final[i].JopID<<" "<<final[i].Deadline<<" "<<final[i].profit<<"\n";
//    }

    for(i=0;i<n;i++){
        if(Jobs[i].Deadline > time){
            //time = Jobs[i].Deadline;
            time++;
            for(int k=min(Jobs[i].Deadline,n) - 1;k >= 0;k--){
                if(final[k].profit == 0){
                    final[k] = Jobs[i];
                    break;
                }
            }
        }
    }


    int z = final.size();

    for(i=0;i<z;i++){
        if(final[i].profit == 0){
            continue;
        }
        if(i == 0){
        cout<<final[i].JopID;
        }
        else{
            cout<<", "<<final[i].JopID;
        }
    }

}