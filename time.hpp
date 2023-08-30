#pragma once

#include <time.h> // header file of C lib time, use time_t, ect. 
#include <limits> // use std::numeric_limits<uint32_t>::max()
#include <string> // use std::string
#include <stdint.h> // use uint32_t, int64_t

#define MAX_TIME std::numeric_limits<uint32_t>::max() // max time as max of uint32_t ()
#define MIN_TIME timlibs::Time(NULL)
#define NOW time(nullptr)

namespace timlibs
{
	/// @brief Time class as instrument for working with time
	class Time
	{
	public:
		Time(const std::string& time);
		Time(const time_t& time) : _time(time) {};
		Time(const Time& time);
		Time() : _time(NOW) {};
		std::string GetAsString() const;
		time_t GetAsInt() const;
		static bool IsValid(const std::string& time);
		bool operator<(const Time& operand) const;
		bool operator>(const Time& operand) const;
		bool operator<=(const Time& operand) const;
		bool operator>=(const Time& operand) const;
		bool operator==(const Time& operand) const;
		int64_t operator-(const Time& operand) const;
		Time& operator=(const Time& operand);
	private:
		time_t _time{ 0 }; //init _time as MIN_TIME
	};

	/// @brief Exceptions of Time class
	class TimeException
	{
	public:
		TimeException(const std::string& description = "") : problem(description) {}; // init problem as description
		std::string what() const { return this->problem; }; // returns what problem is throwed
	private:
		std::string problem{ "" }; //init problem as empty string
	};
}