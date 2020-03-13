# StudentRecords

Created a custom hash function and overloading the equality operator. Then we create an instance of a certain unordered set which stores the instances of StudentRecord. You can then apply changes to this instance like querying the name,ID and grade, removing and adding new students.

Running Instructions
---------------------
Open the terminal and go to the directory containing the Makefile and student_hash.cpp and on the terminal type "make student", this will create the object.

To run the student_hash.cpp file, enter "./student" and press enter in the command terminal. 

Now you can insert,remove or query already existing through the student's name,grade or ID.
- To insert the following format is followed: 
	"I name ID grade"
  Remark: You cannot insert students with duplicate ID's. 

- To remove just enter:
	"R ID"
  Remark: You can't remove a non-existent ID.

- To query, you can use the student's name :
	"Q n/g/i name/grade/id" (respectively)

Remarks: Although two ID's cannot be the same, if querying a grade or name that is the same for two students, both those student's informations will be outputted.
Querying something that does not exist will output an error message.
- To end the program:
 "S" and press enter.
