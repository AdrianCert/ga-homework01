#include <string>
#include <sstream>

#pragma once
constexpr auto pi = 3.1415926535897;
constexpr auto e = 2.71828182845904523536;

template< typename T >
T convert_from_string(const std::string& str)
{
	std::istringstream iss(str);
	T result;
	if (!(iss >> result)) throw "Error reading string";
	return result;
}

#define int_arg(a, str, n); if (argc > n){ a = atoi(argv[n]); } else { cout << str; cin >> a;}
#define str_arg(a, str, n); if (argc > n){ strcpy(a,argv[n]); } else { cout << str; cin >> a;}
#define float_arg(a, str, n); if (argc > n){ a = convert_from_string<float>(argv[n]); } else { cout << str; cin >> a;}