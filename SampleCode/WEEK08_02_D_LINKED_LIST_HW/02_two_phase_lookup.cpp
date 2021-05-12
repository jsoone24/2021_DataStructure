#include <iostream>

//template <class T> // 이렇게 해도 가능합니다.
template <typename T> 
class Base{
    public:
        Base(){std::cout << "Base init\n";}
        ~Base(){}
        void f(){
            std::cerr << "Base<T>::f\n";
        }
}; // 부모 클래스 Base를 정의합니다

template <typename T> 
class Derived : Base<T>{
    public:
        Derived(){std::cout << "Derived init\n";}
        ~Derived(){}    
        void g(){
            std::cerr << "Derived<T>::g\n  ";
            this->f(); // 이렇게 써야만 합니다.
        }
}; // 자식 클래스 Derived를 정의합니다.

/* 
왜 this->같은 것을 써야 할까요?
Typename은 template 내부에서 사용하면서 컴파일러에게 T가 타입형태임을 
알려주는데 사용합니다. 

Template에는 2가지 종류의 이름이 있습니다
Dependent name: 여기서 T는 타입을 인자로 받아서 그것을 타입으로 쓰지요.
그래서 T를 dependent name이라고 합니다. 어떤형태로든 탬플릿 인자에 
영향을 받으면 dependent name이라고 할 수 있습니다. 
Nondependent name: int나 double같은 것은 T에 의존적이지 않죠. 
그래서 이런 것들을 dependent name이라고 합니다. 

C++ 컴파일러가 컴파일을 할 때, Dependent name의 경우는 정의된 이후에 
실제로 코드에서 template가 초기화될 때 까지 컴파일되지 않고 기다립니다.
왜냐 하면 실제 template가 어떤 변수형으로 작동할지 알 수 없기 때문입니다.

하지만 non-dependent name은 template 정의 시점에 컴파일을 합니다.
근데 그냥 f(); 이렇게 정의를 하면, 이 함수는 template와 무관한 non-dependent
name이 됩니다. 그래서 template가 정의되는 시점에 이 함수의 정보를 모두
알고 있어야 합니다. 문제는 Base<T>가 아직 초기화가 안 되어 있다는 점입니다. 
그래서 이 f()라는 함수가 Base<T>의 함수라는 것을 컴파일러가 모릅니다!
*/

template <typename T> 
class Base2{
    public:
        Base2(){std::cout << "Base init\n";}
        ~Base2(){}
        void f(){
            std::cerr << "Base<T>::f\n";
        }
}; // 부모 클래스 Base를 정의합니다


void f(){
    std::cerr << "f() outside base called \n";
}

template <typename T> 
class Derived2 : Base2<T>{
    public:
        Derived2(){std::cout << "Derived init\n";}
        ~Derived2(){}    
        void g(){
            std::cerr << "Derived<T>::g\n  ";
            f(); // 이렇게 써야만 합니다.
        }
}; // 자식 클래스 Derived를 정의합니다.

// 이런 경우를 생각해보죠. 이런 경우면 Base2가 초기화되기 전에 이미 global 함수로
// 다른 f()가 있지요. 그래서 이 f()가 호출됩니다. 
// 즉 이런 식으로 코드에 모호성이 생깁니다. 

int main(){
    Derived<float> df; 
    // 자식 클래스를 초기화하면 부모 클래스도 당연히 초기화가 됩니다.
    df.g();
    Derived<int> di;
    di.g();

    Derived2<float> dg; 
    dg.g();
    return 0;
}

/* 
*/