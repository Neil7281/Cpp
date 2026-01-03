#include<iostream>
#include<string>

class undoRedo{
private:
    std::string str_;
    std::string tempU;
    std::string tempR;

public:
    undoRedo(std::string& str){
        str_ = str;
    }

    void type(char c){
        tempU = str_;
        str_.push_back(c);
        tempR = str_;
    }

    void backspace(){
        tempU = str_;
        str_.pop_back();
        tempR = str_;
    }

    void undo(){
        str_ = tempU;
    }

    void redo(){
        str_ = tempR;

    }

};



int main(){
    std::string hello = "Hello";
    undoRedo S(hello);
    S.backspace();
    S.backspace();
    S.type(char c);
    std::cout<<hello<<std::endl;
    return 0;
}
