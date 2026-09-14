#include <cassert>

#include <cppmessenger/shared.hpp>

int main()
{
    assert(cppmessenger::project_name != nullptr);
    assert(cppmessenger::project_version != nullptr);
    return 0;
}
