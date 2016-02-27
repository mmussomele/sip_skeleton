
all: functions pointers testing sorting using_objects recursion

functions: tasks/functions/functions.cpp tasks/functions/functions_main.cpp
	g++ -Wall -std=c++11 tasks/functions/functions.cpp tasks/functions/functions_main.cpp -o functions_compiled

pointers: tasks/pointers/pointers.cpp tasks/pointers/pointers.h
	g++ -Wall -std=c++11 tasks/pointers/pointers.cpp -c -o pointers_compiled

testing: tasks/makefiles_and_testing/testing.cpp 
	g++ -Wall -std=c++11 tasks/makefiles_and_testing/testing.cpp -c -o testing_compiled

sorting: tasks/sorting/sorting.cpp tasks/sorting/sorting.h tasks/sorting/sorting_main.cpp
	g++ -Wall -std=c++11 tasks/sorting/sorting.cpp tasks/sorting/sorting_main.cpp -o sorting_compiled

using_objects: tasks/using_objects/rooms.cpp tasks/using_objects/rooms.h tasks/using_objects/Robot.cpp tasks/using_objects/Robot.h 
	g++ -Wall -std=c++11 tasks/using_objects/rooms.cpp -c -o rooms_compiled
	g++ -Wall -std=c++11 tasks/using_objects/Robot.cpp -c -o Robot_compiled

recursion: tasks/recursion/recursion.cpp
	g++ -Wall -std=c++11 tasks/recursion/recursion.cpp -c -o recursion_compiled

clean: 
	rm *_compiled
