#include <iostream>
#include <string>
#include <string_view>

class MyString
{
public:
    MyString(std::string_view str): m_str {str} { }

    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
    
private:
    std::string m_str{};
};


std::ostream& operator<<(std::ostream& out, const MyString& str)
{   
    return out << str.m_str;
}



int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}