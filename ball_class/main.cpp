#include <iostream>
#include <string>

class Ball 
{
private:
    std::string m_color {"blue"};
    double m_radius {};

    
}


int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}