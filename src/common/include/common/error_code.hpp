#pragma once

#include <system_error>

namespace basic_namespace
{
enum class error_code
{
	success = 0,
	network_error,
	file_error,
};

struct error_category : public std::error_category
{
	const char* name() const noexcept override
	{
		return "basic_namespace::error_category";
	}

	std::string message(int ev) const noexcept override
	{
		switch (static_cast<error_code>(ev))
		{
		case error_code::success:
			return "Success";
			break;
		case error_code::network_error:
			return "Newwork error";
			break;
		case error_code::file_error:
			return "File error";
			break;
		default:
			return "Unkown error";
			break;
		}
	}
};

inline const error_category error_category_instance;

inline error_category const& get_error_category() noexcept
{
	return error_category_instance;
}

inline std::error_code make_error_code(error_code ec) noexcept
{
	return {static_cast<int>(ec), get_error_category()};
}

void test_error_code();

} // namespace basic_namespace

template <>
struct std::is_error_code_enum<basic_namespace::error_code> : public std::true_type
{
};
