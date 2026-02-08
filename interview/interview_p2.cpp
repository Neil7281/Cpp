#include<iostream>

class shape{
    public:
        virtual void area() = 0;
};

class circle : public shape{
    
    public:
        circle(double radius){
            r = radius;
        }
        void area() override{
            double pi = 3.14;
            std::cout<<"The area of the circle is "<< pi*r*r<<std::endl;
        }
    private:
        double r;

};

class ragtangle : public shape {
    public:
        ragtangle(double width, double height){
            h = height;
            w = width;
        }

        void area() override {
            std::cout<<"The area of the ragtangle is "<<w*h<<std::endl;
        }

    private:
        double h;
        double w;

};


int main(){
    circle c(5);
    ragtangle r(3,4);

    shape* s1 = &c;
    
    s1->area();

    s1 = &r;
    s1->area();

    return 0;
}