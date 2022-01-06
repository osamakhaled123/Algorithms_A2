#include <iostream>
#include <vector>

using namespace std;

class node{
    public:
    string name;
    int value;
    bool exist;
    vector<pair<node,int>> edges;
    int index;
};

int main(){

    vector<node> MST(7);

    MST[0].name = "v1";
    MST[0].value = 0;
    MST[0].exist = true;
    MST[0].index = 0;

    MST[1].name = "v2";
    MST[1].value = 1000;
    MST[1].exist = true;
    MST[1].index = 1;

    MST[2].name = "v3";
    MST[2].value = 1000;
    MST[2].exist = true;
    MST[2].index = 2;

    MST[3].name = "v4";
    MST[3].value = 1000;
    MST[3].exist = true;
    MST[3].index = 3;

    MST[4].name = "v5";
    MST[4].value = 1000;
    MST[4].exist = true;
    MST[4].index = 4;

    MST[5].name = "v6";
    MST[5].value = 1000;
    MST[5].exist = true;
    MST[5].index = 5;

    MST[6].name = "v7";
    MST[6].value = 1000;
    MST[6].exist = true;
    MST[6].index = 6;

    MST[0].edges.emplace_back(MST[1],2);
    MST[0].edges.emplace_back(MST[2],4);
    MST[0].edges.emplace_back(MST[3],1);

    MST[1].edges.emplace_back(MST[0],2);
    MST[1].edges.emplace_back(MST[3],3);
    MST[1].edges.emplace_back(MST[4],10);

    MST[2].edges.emplace_back(MST[0],4);
    MST[2].edges.emplace_back(MST[3],2);
    MST[2].edges.emplace_back(MST[5],5);

    MST[3].edges.emplace_back(MST[0],1);
    MST[3].edges.emplace_back(MST[1],3);
    MST[3].edges.emplace_back(MST[2],2);
    MST[3].edges.emplace_back(MST[4],7);
    MST[3].edges.emplace_back(MST[5],8);
    MST[3].edges.emplace_back(MST[6],4);

    MST[4].edges.emplace_back(MST[1],10);
    MST[4].edges.emplace_back(MST[3],7);
    MST[4].edges.emplace_back(MST[6],6);

    MST[5].edges.emplace_back(MST[2],5);
    MST[5].edges.emplace_back(MST[3],8);
    MST[5].edges.emplace_back(MST[6],1);

    MST[6].edges.emplace_back(MST[3],4);
    MST[6].edges.emplace_back(MST[4],6);
    MST[6].edges.emplace_back(MST[5],1);

    //vector<node> final;
    int MST_size = MST.size();

    while(MST_size > 0){
        //node min_value = MST[0];
        int index = 0;
        int min = 10000;
        for(int i = 0;i < MST.size();i++) {
            if (MST[i].value < min && MST[i].exist) {
                min = MST[i].value;
                index = i;
            }
        }
        //if(MST[MST[index].index].edges[j].second < MST[index].edges[j].first.value
        //                && MST[MST[index].edges[j].first.index].edges[j].first.exist)

            for(int j = 0;j < MST[index].edges.size();j++) {
                if (MST[index].edges[j].second < MST[index].edges[j].first.value && MST[index].edges[j].first.exist) {

                    MST[index].edges[j].first.value = MST[index].edges[j].second;
                    MST[MST[index].edges[j].first.index].value = MST[index].edges[j].second;

                    for(int e=0;e<MST.size();e++){
                        for(int u=0;u<MST[e].edges.size();u++){
                            if(MST[e].edges[u].first.name == MST[index].edges[j].first.name){
                                MST[e].edges[u].first.value =  MST[index].edges[j].second;
                            }
                        }
                    }
                }
                if (MST[index].edges[j].first.exist) {
                    for (int h = 0; h < MST[MST[index].edges[j].first.index].edges.size(); h++) {
                        if (MST[MST[index].edges[j].first.index].edges[h].first.name == MST[index].name) {
                            MST[MST[index].edges[j].first.index].edges[h].first.exist = false;
                        }
                    }
                }
            }
        MST[index].exist = false;
        //cout<<MST[index].name<<" "<<MST[index].value<<"\n";
        MST_size--;

    }

    cout<<"name of node    it' value\n";
    for(auto & k : MST){
        cout<<k.name<<"              "<<k.value<<"\n";
    }
}
