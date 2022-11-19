module;
#include <array>
#include <string_view>
export module the_module;

export namespace the_module
{
    // TODO: check 0x673B50 and 0xAC6F90
    void function();
}

module: private;
import utils;

namespace
{
    void implementation(std::wstring_view view)
    {
        std::array<wchar_t, 0x100> array { 'A' };
        utils::log_info(L"string view {} array {}", view, array.data());
    }
}

void the_module::function()
{
    implementation({});
}