#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node{
    public:
        int start;
        int end;
        node* left;
        node* right;
        node(int s, int n){
            left = nullptr;
            right = nullptr;
            start = s;
            end = n;
        }
};

class interval_tree{

    public:
    node* root;
    int size;
        interval_tree(){
            root = nullptr;
            size = 0;
        }
        node* insert(node* rot,node* obj){
            if(rot == nullptr){
                size++;
                //rot = obj;

                //cout << "{" << obj->start << "," << obj->end << "}" << " ";
                return obj;
            }
            else if(obj->start > rot->end){
                rot->right = insert(rot->right,obj);
            }
            else if((obj->end < rot->start)){
                rot->left =  insert(rot->left,obj);
            }
            else{
                return rot;
            }
        }

        void preorder(node *rot){
            if(rot != nullptr) {
                preorder(rot->left);
                cout << "{" << rot->start << "," << rot->end << "}" << " ";
                preorder(rot->right);
            }
        }
};

int main(){

    interval_tree obj;

    int n,i,start,end;
    vector<node> array;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>start>>end;
        node objj (start,end);
        array.push_back(objj);
    }

//    for(i=0;i<n;i++){
//        cout<<"{"<<array[i].start<<","<<array[i].end<<"}"<<"\n";
//    }

    obj.size++;
    obj.root =&array[0];
    for(i=1;i<n;i++){
        obj.insert(obj.root,&array[i]);
    }

    obj.preorder(obj.root);
    //cout<<obj.root->right->start<<","<<obj.root->r->end;

}

/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
 */