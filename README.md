# Time

## Defenition of Time class

```cpp
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
		time_t _time{ 0 };
	};
```

### Constructors

`Time(const std::string& time)` - A constructor that accepts time as input, represented as a string in the format "hh:mm:ss dd:mm:yyyy".

`Time(const time_t& time)` - A constructor that accepts time as input, represented as a variable of the time_t type.

`Time(const Time& time)` - Copy constructor.

`Time()` - Empty constructor initialize time with 0.

### Methods

`GetAsString()` - Returns time as string in the format "hh:mm:ss dd:mm:yyyy".

`GetAsInt()` - Returns time as unsigned integer 32 bit.

`IsValid(const std::string& time)` - Returns boolean flag: if parametr mathing correct format (hh:mm:ss dd:mm:yyyy) - true, else - false.
Parametrs: `time` - Time as string.

## Defenition of TimeException class

```cpp
class TimeException
	{
	public:
		TimeException(const std::string& description = "") : problem(description) {};
		std::string what() const { return this->problem; };
	private:
		std::string problem{ "" };
	};
```



