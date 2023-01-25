#include<iostream>

#ifdef __cplusplus
extern "C" {
#endif
    void add(int, int);
    void add(int x, float y);
#ifdef __cplusplus
}
#endif

void add(int x, int y)
{
    std::cout << x+y << std::endl;
}
void add(int x, float y)
{
    std::cout << x+y << std::endl;
}
int main() {
    add(1,2);
    add(1,2.5f);

return 0;
}
