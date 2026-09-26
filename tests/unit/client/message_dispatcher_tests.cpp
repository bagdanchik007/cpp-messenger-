#include <cassert>
#include <cppmessenger/client/message_dispatcher.hpp>
#include <stdexcept>
#include <string>

namespace {

void test_register_handler() {
    cppmessenger::client::MessageDispatcher dispatcher;

    dispatcher.register_handler("message", [](const std::string &) {});

    assert(dispatcher.has_handler("message"));
}

void test_register_multiple_handlers() {
    cppmessenger::client::MessageDispatcher dispatcher;

    dispatcher.register_handler("message", [](const std::string &) {});

    dispatcher.register_handler("notification", [](const std::string &) {});

    assert(dispatcher.has_handler("message"));
    assert(dispatcher.has_handler("notification"));
}

void test_unknown_handler_is_not_registered() {
    cppmessenger::client::MessageDispatcher dispatcher;

    assert(!dispatcher.has_handler("unknown"));
}

void test_empty_message_type_is_rejected() {
    cppmessenger::client::MessageDispatcher dispatcher;

    bool exception_thrown = false;

    try {
        dispatcher.register_handler("", [](const std::string &) {});
    } catch (const std::invalid_argument &) {
        exception_thrown = true;
    }

    assert(exception_thrown);
}

void test_empty_handler_is_rejected() {
    cppmessenger::client::MessageDispatcher dispatcher;

    bool exception_thrown = false;

    try {
        dispatcher.register_handler("message", {});
    } catch (const std::invalid_argument &) {
        exception_thrown = true;
    }

    assert(exception_thrown);
}

} // namespace

int main() {
    test_register_handler();
    test_register_multiple_handlers();
    test_unknown_handler_is_not_registered();
    test_empty_message_type_is_rejected();
    test_empty_handler_is_rejected();

    return 0;
}