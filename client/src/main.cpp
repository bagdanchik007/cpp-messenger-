#include <iostream>

#include <cppmessenger/shared.hpp>

int main()
{
    std::cout << cppmessenger::project_name
              << " client "
              << cppmessenger::project_version
              << '\n';

    return 0;
}
