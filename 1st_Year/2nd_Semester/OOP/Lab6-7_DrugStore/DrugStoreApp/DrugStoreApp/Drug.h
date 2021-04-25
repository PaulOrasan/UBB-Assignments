#ifndef DRUG_H
#define DRUG_H
#include <string>
class Drug
{
	private:
		int id;
		std::string name, producer, activeSubstance;
		double price;
	public:
		/*
		* implicit constructor for class Drug
		*/
		Drug() noexcept { id = 0; price = 0; }

		Drug(const Drug& copy);
		/*
		* constructor for class Drug with initialisation
		*/
		Drug(int id, const std::string& name, const std::string& producer, const std::string& activeSubstance, double price) :
			id{ id }, name { name }, producer{ producer }, activeSubstance{ activeSubstance }, price{ price } {}

		//Drug(const Drug& newDrug);
		/*
		* Getter method
		* Returns an int which represents the id of the drug
		*/
		int getID() const noexcept{
			return id;
		}

		/*
		* Setter method
		* newId - int
		* Sets the id of the object to newId
		*/
		void setID(int newId) noexcept {
			id = newId;
		}

		/*
		* Getter method
		* Returns a string which represents the name of the drug
		*/
		const std::string& getName() const noexcept {
			return name;
		}

		/*
		* Setter method
		* newName - const reference to a string 
		* Sets the name of the object to newName
		*/
		void setName(const std::string& newName) {
			name = newName;
		}

		/*
		* Getter method
		* Returns a string which represents the producer of the drug
		*/
		const std::string& getProducer() const noexcept {
			return producer;
		}

		/*
		* Setter method
		* newProducer - const reference to a string
		* Sets the producer of the object to newProducer
		*/
		void setProducer(const std::string& newProducer) {
			producer = newProducer;
		}

		/*
		* Getter method
		* Returns a string which represents the active substance of the drug
		*/
		const std::string& getSubstance() const noexcept {
			return activeSubstance;
		}

		/*
		* Setter method
		* newSubstance - const reference to a string
		* Sets the substance of the object to newSubstance
		*/
		void setSubstance(const std::string& newSubstance) {
			activeSubstance = newSubstance;
		}

		/*
		* Getter method
		* Returns a double which represents the price of the drug
		*/
		double getPrice() const noexcept {
			return price;
		}

		/*
		* Setter method
		* newPrice - double
		* Sets the price of the object to newPrice
		*/
		void setPrice(double newPrice) noexcept {
			price = newPrice;
		}

		/*
		* Method for output operator
		*/
		friend std::ostream& operator<<(std::ostream& out, const Drug& d);
};
/*
* Checks if two drug objects are equal (all atributtes must be equal)
* a - const reference to an object of the Drug
* b - const reference to an object of the Drug
* Returns true if a is considered equal to b and false otherwise
*/
bool operator==(const Drug& a, const Drug& b) noexcept;

/*
* Checks if the prices of drug objects are equal
* a - const reference to an object of the Drug
* b - const reference to an object of the Drug
* Returns true if a's price is considered equal to b's and false otherwise
*/
bool equalPrices(const Drug& a, const Drug& b) noexcept;
#endif

