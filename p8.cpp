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
    vector<Job> final;
    for(i=0;i<n;i++){
        cin>>ID>>deadline>>profit;
        Jobs[i].JopID = ID;
        Jobs[i].Deadline = deadline;
        Jobs[i].profit = profit;
    }
    int time = 0;
    sort(Jobs,Jobs+n,compare);

//    for(i=0;i<n;i++){
//        cout<<Jobs[i].JopID<<" "<<Jobs[i].Deadline<<" "<<Jobs[i].profit<<"\n";
//    }

    for(i=0;i<n;i++){
        if(Jobs[i].Deadline > time){
            //time = Jobs[i].Deadline;
            time++;
            final.push_back(Jobs[i]);
        }
    }

    int z = final.size();

    for(i=z-1;i>=0;i--){
        if(final[i].Deadline == final[i-1].Deadline){
            if(final[i].profit < final[i-1].profit){
                swap(final[i],final[i-1]);
            }
        }
    }

    for(i=0;i<z;i++){
        if(i == 0){
        cout<<final[i].JopID;
        }
        else{
            cout<<", "<<final[i].JopID;
        }
    }

}