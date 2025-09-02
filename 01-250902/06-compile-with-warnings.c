int main(int argc, char **argv)  // GCC -Wall -Wextra (-Wunused-parameter), Clang -Wextra (-Wunused-parameter), MSVC /W4 (C4100)
{
    int x = 10;  // GCC/Clang -Wall (-Wunused-variable), MSVC /W4 (C4189)
    if (2 == 4);  // GCC -Wextra, Clang default (-Wempty-body), MSVC /W3 (C4127, C4390)
}