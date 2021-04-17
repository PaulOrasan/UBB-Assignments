#ifndef PRODUCER_COUNT_H
#define PRODUCER_COUNT_H
#include <string>
class ProducerCount
{
private:
	std::string producer;
	int count;
public:
	/*
	* Implicit constructor
	*/
	ProducerCount() noexcept { count = 0; }
	/*
	* Constructor
	*/
	ProducerCount(const std::string& prod) : producer(prod), count(1) {}
	/*
	* Method that increments the count of the class
	*/
	void incrementCount() noexcept {
		count++;
	}
	/*
	* Method that gets the count of the class
	*/
	int getCount() const  noexcept{
		return count;
	}
};
#endif

