#include<iostream>
#include<vector>
#include<algorithm>


class minStack{
    protected: 
    std::vector<int> vectr;
    public:
        Stack(std::vector<int> v){
             vectr = v;

        }

        std::vector<int> push (int p){
            vectr.push_back(p);
            return vectr;
        }

        std::vector<int> pop (){
            vectr.pop_back();
            return vectr;
        }

        int top (){
            int n = vectr.size();
            int top_ = vectr.at(n-1);
            return top_;
        }

        bool isEmpty(){
            if (vectr.size() == 0){return true;}
            return false;
        }

         int getMini(){
        if (vectr.size()==0){
            throw std::out_of_range("vectr is empty");
        }
        int min_ = vectr[0];
        for (int i =1;i<vectr.size();i++){
            min_ = std::min(vectr[i],min_);
        }
        return min_;

    }
};

class Queue {
protected: 
    std::vector<int> vectr;
public:
    Queue(std::vector<int> v){
            vectr = v;
    }
    std::vector<int> enqueue(int p){
        vectr.push_back(p);
        return vectr;
    }
    std::vector<int> denqueue(){
        if (vectr.size() ==0){
            std::cerr<<"Queue is emphty";
        }
        vectr.erase(vectr.begin());
        return vectr;
    }
    int front(){
         if (vectr.size() ==0){
            std::cerr<<"Queue is emphty";
        }
        int front_ = vectr.at(0);
        return front_;
    }

    bool isEmpty(){
        if (vectr.size() == 0){return true;}
        return false;
    }

    int getMini(){
        if (vectr.size()==0){
            throw std::out_of_range("vectr is empty");
        }
        int min_ = vectr[0];
        for (size_t i =1;i<vectr.size();i++){
            min_ = std::min(vectr[i],min_);
        }
        return min_;

    }


};
int main(){
    // std::vector<int> vectr_  = {};
    // auto s = Stack(vectr_);
    // for (int i = 1;i<5;i++){
    //     s.push(i);
    // }
    // for (int j = 0;j<5;j++){
    //     s.pop();
    // }
    Stack s({2,2,3,4,5});
    std::cout<<s.top()<<std::endl;
    std::cout<<s.isEmpty()<<std::endl;
    std::cout<<s.getMini();
    // Queue Q({1,2,3,4,5});
    // Q.denqueue();
    // Q.enqueue(6);
    // std::cout<<Q.front()<<std::endl;
    // return 0;

}