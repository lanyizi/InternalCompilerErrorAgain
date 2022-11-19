module;
#include <CodeAnalysis/Warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include <fmt/chrono.h>
#include <fmt/format.h>
#include <fmt/xchar.h>
#pragma warning(pop)
export module utils;

export namespace utils
{
    void log_info(std::string_view line) noexcept;
    void log_info(std::wstring_view line) noexcept;
    void log_error(std::string_view line) noexcept;
    void log_error(std::wstring_view line) noexcept;

    template<typename... Args>
    void log_info(fmt::format_string<Args...> format, Args&&... args) noexcept
    {
        log_info(fmt::vformat(format, fmt::make_format_args(args...)));
    }

    template<typename... Args>
    void log_info(fmt::wformat_string<Args...> format, Args&&... args) noexcept
    {
        log_info(fmt::vformat<wchar_t>(format, fmt::make_wformat_args(args...)));
    }

    template<typename... Args>
    void log_error(fmt::format_string<Args...> format, Args&&... args) noexcept
    {
        log_error(fmt::vformat(format, fmt::make_format_args(args...)));
    }

    template<typename... Args>
    void log_error(fmt::wformat_string<Args...> format, Args&&... args) noexcept
    {
        log_error(fmt::vformat<wchar_t>(format, fmt::make_wformat_args(args...)));
    }
}

module: private;

void utils::log_info(std::string_view line) noexcept
{
}

void utils::log_info(std::wstring_view line) noexcept
{
}

void utils::log_error(std::string_view line) noexcept
{
}

void utils::log_error(std::wstring_view line) noexcept
{
}
