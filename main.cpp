#include <cstring>
#include <iostream>

char* copyString(const char* str)
{
    char* result{new char[strlen(str) + 1]};
    strcpy(result, str);
    return result;
}

int main()
{
    std::cout << std::format("There are {} ways I love you.", 219);
    return 0;
}
