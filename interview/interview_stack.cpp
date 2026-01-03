#include<iostream>
#include<vector>

using namespace std;

class Stack{
    private:
        vector<int> vec_;

    public:

        Stack(vector<int>& vec){
            vec_ = vec;
        }

        
        void push(int p){
            vec_.push_back(p);
        }

        void pop(){
             if (vec_.empty()){
                cerr<<"vector is empty\n";
            }else{
                vec_.pop_back();
            }
        }
        
        int top()const{
            if (vec_.empty()){
                cerr <<"vector is empty\n";
                return -1;                   //only this was missing during the interview
            }
            return vec_.back();
        }

       bool isEmpty()const{
            return vec_.empty();
        }



};




int main(){

    vector<int> vec = {};

    Stack s(vec);

    s.push(6);

    cout<<s.top()<<endl;

    s.pop();

    cout<<s.top();
    return 0;
}