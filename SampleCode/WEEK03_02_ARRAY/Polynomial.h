#include <iostream>
#define MAX_DEGREE 80

class Polynomial{
    private:
        int degree; // 다항식의 최고 차수
        float coef[MAX_DEGREE];    // 각 항에 대한 계수

    public:
        Polynomial(){
            degree = 0;
        }
        void read(){
            std::cout << "다항식의 최고 차수를 입력하시오: \n";
            std::cin >> degree;
            std::cout << "각 항의 계수를 입력하세요: "<< degree +1 << "개 \n";
            for(int i = 0; i <= degree; i++){
                std::cin >> coef[i];
            }
        }

        void display(std::string str = " Poly = "){
            std::cout << str;
            for(int i = 0; i < degree; i++){
                std::cout << coef[i] << "x^" << degree - i << " + ";
            }
            std::cout << coef[degree] << "\n";
        }

        void add(Polynomial a, Polynomial b) {
            if(a.degree > b.degree) {
                *this = a;
                for(int i = 0 ; i <= b.degree ; i++){
                    coef[i+(degree-b.degree)] += b.coef[i];
                }
            }
            else{
                *this = b;
                for(int i = 0 ; i <= a.degree ; i++){
                    coef[i + (degree - a.degree)] += a.coef[i];
                }
            }
        }

        bool isZero(){
            return degree == 0; // 0이면 True 아니면 False!
        }

        void negate(){
            for(int i = 0; i < degree; i++){
                coef[i] = -coef[i] ;
            }
        }
};