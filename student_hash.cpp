//------------------------------------------------------
// Names: Amro Amanuddein
// ID: 1572498
// CMPUT275, Winter 2020
// 
// Weekly Exercise 6: STL Concepts
//------------------------------------------------------

#include <iostream>
#include <unordered_set>
#include <string>


struct StudentRecord {
	std::string name;
	int id, grade;

	bool operator ==(const StudentRecord & obj) const{
		if (id == obj.id)
			return true;
		else
			return false;
	}
};

namespace std
{
  template<>
    struct hash<StudentRecord>
    {
      size_t
      operator()(const StudentRecord & obj) const
      {
        return hash<int>()(obj.id);
      }
    };
  }  

int main() {
	std::unordered_set<StudentRecord> table;
	StudentRecord instance;

  while (true) {
    std::string input;
    std::string i_n_g;
    std::cin >> input;
   	//
    if (input == "S") {
      break;
    }
    else{
    	// initialization of flags
    	bool dup_id = 0;
    	bool flag=0;

    if (input == "I") {
    	// Input all the details of the student, check if they're a duplicate from the ID and if they aren't, insert it 
    	std::cin >> instance.name;
    	std::cin >> instance.id;
    	std::cin >> instance.grade;
    	std::unordered_set<StudentRecord>::iterator iter = table.begin();
    	while(iter!=table.end()){
    		// if the inputted ID already exists in the table
    		if (iter->id == instance.id){
    			dup_id = 1;
    			iter=table.end();
    			std::cout<< "Error: Cannot insert duplicate ID" << std::endl;
    		}
    		else{
    			iter++;
    		}
    	}
    	if (dup_id == 0){
      	table.insert(instance);
      	}
    }
    // Q to query either a name, id or grade
    if (input == "Q"){
    	std::cin >> i_n_g;
    	// To query a name
    	if(i_n_g == "n"){
    		std::string name_check;
    		std::cin >> name_check;
    		// Run through the table to check if the queried name is found or not and find all instances of this name
    		for (std::unordered_set<StudentRecord>::iterator iter = table.begin(); iter != table.end();iter++){
    			if (iter->name == name_check){
    				std::cout << "Name: "<< iter->name <<", ID: " << iter->id << ", Grade: " << iter->grade << std::endl;
    				flag=1;
    			}
    		}
    		// Otherwise there is no match for this name
    		if (flag == 0){
    			std::cout <<"Error: No matches found" <<std::endl;
    		}
    			
    	}
    	// To query a grade
		if(i_n_g == "g"){
			int grade_check;
			std::cin >> grade_check;
			// Run through the table to check if the queried grade is found or not and find all instances of this grade
			for (std::unordered_set<StudentRecord>::iterator iter = table.begin(); iter != table.end(); iter++){
				if (iter->grade == grade_check){
					std::cout << "Name: " << iter->name << ", ID: " << iter->id << ", Grade: " << iter->grade << std::endl;
					flag = 1;
				}

			}
			// Otherwise there is not match for this grade
			if (flag == 0){
				std::cout << "Error: No matches found" <<std::endl;
			}
		}
		// To query an ID
		if(i_n_g == "i"){
			int ID_check;
			std::cin >> ID_check;
			// Run through the table to check if the queried ID is found or not and find all instances of this ID
			for (std::unordered_set<StudentRecord>::iterator iter = table.begin(); iter != table.end(); iter++){
				if (iter->id == ID_check){
					std::cout << "Name: " << iter->name << ", ID: " << iter->id << ", Grade: " << iter->grade << std::endl;
					flag=1;
				}
			}
			// Otherwise there is no match for this ID
			if (flag == 0){
				std::cout <<"Error: No matches found" <<std::endl;
			}
		}
	}
	// To remove an instance
	if (input == "R"){
		int ID_remove;
		std::cin >> ID_remove;
		// Find the ID that is wanted to be removed
		for (std::unordered_set<StudentRecord>::iterator iter = table.begin(); iter != table.end(); iter++){
			if (iter->id == ID_remove){
				// Remove the instance
				table.erase(instance);
				//std::cout << "Removal Successful! "<< std::endl;
				flag =1;
			}
			// Realise this is gona print it every time the for loop iterates
		}
		// Otherwise this ID does not exist in the table
		if (flag == 0){
				std::cout << "Error: Cannot remove non-existent ID" << std::endl;
		}
		}
    }
}

  return 0;
}

/*
R 1111111I 
Emilia 1234567 24
Q i 1234560
Q i 1234567
I Henry 1234567 89
R 1234567
I Henry 1234567 88
Q i 1234567
S


*/

