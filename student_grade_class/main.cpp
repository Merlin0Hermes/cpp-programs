#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>


struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
public:
    char& operator[](std::string_view index)
    {
        auto found { std::find_if(m_list.begin(), m_list.end(), 
        [index] (StudentGrade s){return s.name == index;}
        )};

        if (found == m_list.end())
        {
            m_list.emplace_back(std::string{index});
            return m_list.back().grade;
        }
        else
            return found->grade;
    }
private:
    std::vector<StudentGrade> m_list{};
};


int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}