#define _CRT_SECURE_NO_WARNINGS

#include "time.hpp" // header file of lib
#include <regex> // use regex_match


namespace timlibs
{
	/// @brief Constructor of Time class
	/// @param passed_time time as std::string in format "hh:mm:ss dd:mm:yyyy"
	Time::Time(const std::string& passed_time)
	{
		if (Time::IsValid(passed_time))
		{
			uint32_t hours, minuts, seconds, day, month, year;
			std::sscanf(passed_time.c_str(), "%d:%d:%d %d.%d.%d", &hours, &minuts, &seconds, &day, &month, &year);

			tm time_tm{ 0 };
			time_tm.tm_isdst = -1;
			time_tm.tm_year = year - 1900;
			time_tm.tm_mon = month - 1;
			time_tm.tm_hour = hours;
			time_tm.tm_mday = day;
			time_tm.tm_min = minuts;
			time_tm.tm_sec = seconds;
			
			this->_time = mktime(&time_tm);
		}
		else
		{
			throw TimeException("Time format is not valid");
		}
	}

    /// @brief Constructor of Time class
    /// @param time time as time_t c-style format
    Time::Time(const time_t &time) : _time(time) {}

    /// @brief Constructor of Time class (Copy constructor)
	/// @param time time as Time class object
	Time::Time(const Time& time)
	{
		this->_time = time.GetAsInt();
	}

    /// @brief Empty constructor of Time class, inits _time as localtime
    Time::Time() : _time(NOW) {}

    /// @brief Gets time as string
	/// @return time as std::string in format "hh:mm:ss dd:mm:yyyy"
	std::string Time::GetAsString() const
	{
		std::tm* ptm = std::localtime(&(this->_time));
		char buffer[50];
		std::strftime(buffer, 50, "%H:%M:%S %d.%m.%Y", ptm);
		return std::string(buffer);
	}

	/// @brief Gets time as integer
	/// @return time as unsigned integer 32 bits, as seconds since 1900 year
	time_t Time::GetAsInt() const
	{
		return this->_time;
	}

	/// @brief Checks that string is formated like time
	/// @param time time as std::string in format "hh:mm:ss dd:mm:yyyy"
	/// @return boolean flag "is valid" (true) or "isn't valid" (false)
	bool Time::IsValid(const std::string& time)
	{
		static const std::regex r(R"(([0-1][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9]) ([0-2][0-9]|3[0-1])\.(0[1-9]|1[0-2])\.(19|20)[0-9]{2})");
		return std::regex_match(time, r);
	}

	/// @brief Operator "<"
	/// @param operand the second operand of operation
	/// @return boolean flag "is 1-st operator less than 2-nd operand"
	bool Time::operator<(const Time& operand) const
	{
		return (this->GetAsInt() < operand.GetAsInt());
	}

	/// @brief Operator ">"
	/// @param operand the second operand of operation
	/// @return boolean flag "is 1-st operator more than 2-nd operand"
	bool Time::operator>(const Time& operand) const
	{
		return (this->GetAsInt() > operand.GetAsInt());
	}

	/// @brief Operator "<="
	/// @param operand the second operand of operation
	/// @return boolean flag "is 1-st operator less or equal than 2-nd operand"
	bool Time::operator<=(const Time& operand) const
	{
		return (this->GetAsInt() <= operand.GetAsInt());
	}

	/// @brief Operator ">="
	/// @param operand the second operand of operation
	/// @return boolean flag "is 1-st operator more or equal than 2-nd operand"
	bool Time::operator>=(const Time& operand) const
	{
		return (this->GetAsInt() >= operand.GetAsInt());
	}

	/// @brief Operator "=="
	/// @param operand the second operand of operation
	/// @return boolean flag "is 1-st operator equal with 2-nd operand"
	bool Time::operator==(const Time& operand) const
	{
		return (this->GetAsInt() == operand.GetAsInt());
	}

	/// @brief Operator "-"
	/// @param operand the second operand of operation
	/// @return signed integer 64 bits, as representation as 1-st operand time as integer minus 2-nd operand time as integer
	int64_t Time::operator-(const Time& operand) const
	{
		return ((int64_t)this->GetAsInt() - (int64_t)operand.GetAsInt());
	}

	/// @brief Operator "-"
	/// @param operand the second operand of operation
	/// @return time as Time class object as copy of 2-nd operand
	Time& Time::operator=(const Time& operand)
	{
		this->_time = operand.GetAsInt();
		return *this;
	}

    /// @brief Constructor of TimeException
    /// @param description problem as string, ex. "Incorrect format of time"
    TimeException::TimeException(const std::string &description = "") : problem(description) {}
    
	/// @brief Returs description of problem
	/// @return Description of problem as string
	std::string TimeException::what() const
    {
        return this->problem;
    }
}