#include <cassert>
#include <cppmessenger/server/message_dispatcher.hpp>
#include <stdexcept>
#include <string>

namespace {

void test_register_handler()
{
    cppmessenger::server::MessageDispatcher dispatcher;

    dispatcher.register_handler(
        "ping",
        [](const std::string&) {
            return std::string{"pong"};
        });

    assert(dispatcher.has_handler("ping"));
}

void test_register_multiple_handlers()
{
    cppmessenger::server::MessageDispatcher dispatcher;

    dispatcher.register_handler(
        "ping",
        [](const std::string&) {
            return std::string{"pong"};
        });

    dispatcher.register_handler(
        "echo",
        [](const std::string& payload) {
            return payload;
        });

    assert(dispatcher.has_handler("ping"));
    assert(dispatcher.has_handler("echo"));
}

void test_unknown_handler_is_not_registered()
{
    cppmessenger::server::MessageDispatcher dispatcher;

    assert(!dispatcher.has_handler("unknown"));
}

void test_empty_message_type_is_rejected()
{
    cppmessenger::server::MessageDispatcher dispatcher;

    bool exception_thrown = false;

    try {
        dispatcher.register_handler(
            "",
            [](const std::string&) {
                return std::string{"invalid"};
            });
    } catch (const std::invalid_argument&) {
        exception_thrown = true;
    }

    assert(exception_thrown);
}

void test_empty_handler_is_rejected()
{
    cppmessenger::server::MessageDispatcher dispatcher;

    bool exception_thrown = false;

    try {
        dispatcher.register_handler("ping", {});
    } catch (const std::invalid_argument&) {
        exception_thrown = true;
    }

    assert(exception_thrown);
}

} // namespace

int main()
{
    test_register_handler();
    test_register_multiple_handlers();
    test_unknown_handler_is_not_registered();
    test_empty_message_type_is_rejected();
    test_empty_handler_is_rejected();

    return 0;
}