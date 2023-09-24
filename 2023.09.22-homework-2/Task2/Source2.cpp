#include <iostream>

int main(int argc, char* argv[]) 
{
    int ans_comp = 0;
    int ans_stu = 0;
    std::cin >> ans_comp;
    std::cin >> ans_stu;
    if (((ans_comp != 1) && (ans_stu != 1)) || ((ans_comp == 1) && (ans_stu == 1)))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    return EXIT_SUCCESS;
}