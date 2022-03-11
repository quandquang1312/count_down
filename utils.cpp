#include <vector>
#include <iostream>
#include <sstream>

std::string addZero(int x)
{
	return x < 10 ? "0" + std::to_string(x) : std::to_string(x);
}

void lower(std::string &str)
{
	auto lower = [](char &c) {c = ::tolower(c); };
    std::for_each(str.begin(), str.end(), lower);
}

std::string operator*(std::string a, unsigned int b) {
    std::string output = "";
    
    while (b--)
    {
        output += a;
    }
    
    return output;
}

std::vector<int> splitString(std::string str)
{
    std::vector<int> time;

    std::istringstream split(str);
    std::string tmp;
    
    while(std::getline(split, tmp, ':'))
    {
        try
        {
            time.push_back(std::stoi(tmp));
        }
        catch (...)
        {
            std::cerr << "Error: Integer Parsing Error" << std::endl;
            time.clear();
        }
    }

    if (time.size() != 3)
    {
        time.clear();
    }
    return time;
}
