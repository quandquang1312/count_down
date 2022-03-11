#include <chrono>
#include <algorithm>
#include <string>
#include <unistd.h>

#include "utils.cpp"

int sec_left;

void lunchTimeAnnounce(std::vector<int> time_v)
{
	int hour = time_v[0];
	int min = time_v[1];
	int sec = time_v[2];

	::sec_left = ((hour * 60) + min) *60 + sec;

	while (::sec_left--)
	{
		sleep(1);
		if (::sec_left <= (30*60) && ::sec_left % 60 == 0)
		{
			std::cout << "LUNCH TIME: " << ::sec_left/60 << " minutes to lunch time\n";
		}
	}
}

void request()
{
	std::string command;

	while (::sec_left)
	{
		std::cin >> command;
		lower(command);

		if (command == "lunch")
		{	
			std::cout << "LUNCH TIME is in " << ::sec_left/60 << " minutes\n";
		}
		else if (command == "exit")
		{
			std::cout << "You don't have that option\nThis program is too useful to be terminated by user\n";
		}
	}
}

void display(std::vector<int> time_v)
{	
	int hour = time_v[0];
	int min = time_v[1];
	int sec = time_v[2];

	std::string rm = "\b";
	std::cout << "TIME LEFT__\n";

	while (true)
	{
		std::cout << rm * 9;

		if (sec < 0)
		{
			sec = 59;
			min -= 1;
		}

		if (min < 0)
		{
			min = 59;
			hour -= 1;
		}
		
		std::cout << addZero(hour) << ":" << addZero(min) << ":" << addZero(sec--) << " " << std::flush;
		sleep(1);

		if (hour == 0 && min == 0 && sec == 0)
		{
			break;
		}
	}
}

std::vector<int> minusTime(int hour, int min, int sec, int hour2, int min2, int sec2)
{
	std::vector<int> result;

	int l_min = 0, l_sec = 0, l_hour = 0;

	l_sec = sec - sec2;
	if (l_sec < 0)
	{
		l_sec += 60;
		l_min -= 1;
	} 

	l_min += (min - min2);
	if (l_min < 0)
	{
		l_min += 60;
		l_hour -= 1;
	}

	l_hour += (hour - hour2);

	result.push_back(l_hour);
	result.push_back(l_min);
	result.push_back(l_sec);

	if (l_hour < 0)
	{
		result.clear();
	}
	return result;
}

std::vector<int> timeLeft(std::vector<int> vect)
{
	std::time_t t = std::time(0);
	struct tm *now = localtime(&t);

	return minusTime(vect[0], vect[1], vect[2], now->tm_hour, now->tm_min, now->tm_sec);
}
