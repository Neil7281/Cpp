#include<iostream>
#include<string>


class runLengthEcoding{
    public:
        runLengthEcoding(std::string str){
            this->str = str;
        }

        std::string RLE(){
            int n = str.length();
            int count = 1;
            std::string newStr;
            for (int i = 0; i<n; i++){
                if (str[i+1]!=str[i]){
                    newStr.push_back(str[i]);
                    // if(count != 0){
                    newStr.append(std::to_string(count));
                    count = 1;
                    // }
                }else{
                    count+=1;

                }
            }
            return newStr;
        }


    private:
    std::string str;
    
};





int main(){
    std::string strg = "aaabbc";
    runLengthEcoding rle(strg);
    
    std::cout<< rle.RLE() <<std::endl;

    return 0;
}