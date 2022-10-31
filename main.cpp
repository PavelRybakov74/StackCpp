#include "Stack.h"

int main() {
    try {
        Stack<int> st({ 10,57,57 });
        st.push(55);
        st << 69 << 18 << 30;
        std::cout << "st = " << st << std::endl;
        int a,b;
        st >> a >> b;
        
        std::cout <<"a = " << a << " b = " << b << std::endl;
        std::cout << "st = " << st << std::endl;

        Stack<int> st2(st);
        std::cout <<"st2 = " << st2 << std::endl;

        Stack<int> st3({ 15,49,33 });
        std::cout <<"st3 = " << st3 << std::endl;

        Stack<int> st4(std::move(st3));
        std::cout <<"st4 = " << st4 << std::endl;

        int j = st.check_pop();
        std::cout << "st.check_pop = " << j << std::endl;
        std::cout <<"st.size() = " << st.size() << std::endl;

        Stack<double> st6({ 15.2,77.55 });
        Stack<double> st8=st6;
        st6=st6;
        std::cout <<"st6 =  " << st6 << std::endl;
        std::cout <<"st8 = "<< st8 << std::endl;

        Stack<std::string> st9({ "abc","defg" });
        std::cout <<"st9 = "<< st9 << std::endl;
        st9.pop();
        std::cout <<"st9.pop() " << st9 << std::endl;

        Stack<int>st11;
        st11.pop();
    }
    catch (const char* e) {
        std::cout << e <<std::endl;
    }

}