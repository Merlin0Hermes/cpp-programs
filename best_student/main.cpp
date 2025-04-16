#include <string>
#include <array>
#include <algorithm>
#include <iostream>

struct Student
{
    std::string name{};
    int points{};
};


int main()
{
    std::array<Student, 8> arr{
        { { "Albert", 3 },
          { "Ben", 5 },
          { "Christine", 2 },
          { "Dan", 8 }, // Dan has the most points (8).
          { "Enchilada", 4 },
          { "Francis", 1 },
          { "Greg", 3 },
          { "Hagrid", 5 } }
      };

    auto func {
    [] (const Student& a, const Student& b)
    {
        return a.points < b.points;
    } 
    };

    auto best_student { std::max_element(arr.begin(), arr.end(), func) };

    std::cout << best_student->name << " is the best student.\n";

    return 0;

}