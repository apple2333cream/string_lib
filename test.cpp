#include "string_func.h"
#include <iostream>


int main()
{
    system("chcp 65001");
    std::string input = "  你好，世界！  ";
    std::string output = stripString(input);
    std::cout << "原始字符串： \"" << input << "\"" << std::endl;
    std::cout << "去除空格后的字符串： \"" << output << "\"" << std::endl;
    printf("%s12\n", input.c_str());
    return 0;
}