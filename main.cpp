#include "count_down.cpp"
#include <thread>

#define LOGCP std::cout << "cp" << std::endl

int main()
{
	std::string left_time;
	std::cout << "SET LEFT TIME (hh:mm:ss): ";
	std::cin >> left_time;

	std::string lunch_time;
	std::cout << "SET LUNCH TIME (hh:mm:ss): ";
	std::cin >> lunch_time;

	std::vector<int> left_time_vector = splitString(left_time);
	std::vector<int> lunch_time_vector = splitString(lunch_time);

	std::vector<int> time_left = timeLeft(left_time_vector);	
	std::vector<int> lunch_time_left = timeLeft(lunch_time_vector);

	if (time_left.empty())
	{
		std::cout << "You're already home!\n";
	} 
	else 
	{
		std::thread t1(display, time_left);
		
		if (!lunch_time_left.empty())
		{

			std::thread t2(lunchTimeAnnounce, lunch_time_left);
			std::thread t3(request);
			t2.join();
			t3.join();

		}
	
		t1.join();
	}

	return 0;
}
