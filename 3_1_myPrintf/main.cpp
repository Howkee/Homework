#include <iostream>
#include <stdarg.h>

void myPrintf(char* str, ...)
{
    int d;
    double f;
    char c;
    bool b;
    std::string s;
    va_list vars;
    va_start(vars, str);


    for(char* p_str = str; *p_str !='\0'; p_str++)
    {
        if (*p_str != '%') {
            std::cout << *p_str;
        } else {
            switch (*++p_str){
                case 'd':
                    d = va_arg(vars, int);
                    std::cout << d;
                    break;
                case 'f':
                    f = va_arg(vars, double);
                    std::cout << f;
                    break;
                case 'c':
                    c = static_cast<char>(va_arg(vars, int));
                    std::cout << c;
                    break;
                case 'b':
                    b = static_cast<bool>(va_arg(vars, int));
                    std::cout << b;
                    break;
                default:
                    std::cout <<*p_str;
            }
        }
    }
    va_end(vars);
}

int main()
{
    myPrintf("Int: %d \nDouble: %f \nBool: %b \nChar: %c ", 500, 1234.765, false,'T');
    return 0;
}