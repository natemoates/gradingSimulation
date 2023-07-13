# Nate Oates's makefile

# This command compiles the driver file and 
# compiles all class .cpp files into object code
compile-all:
	g++ WorkPay.cpp -c
	g++ Simulation.cpp -c
	g++ driver.cpp WorkPay.o Simulation.o -o driver.out -Wall

# This command compiles the driver file and 
# compiles the Simulation.cpp file into object code
compile-simulation:
	g++ Simulation.cpp -c
	g++ driver.cpp Simulation.o -o driver.out -Wall

# This command compiles the driver file and
# compiles the WorkPay.cpp file into object code
compile-workpay:
	g++ WorkPay.cpp -c
	g++ driver.cpp WorkPay.o -o driver.out -Wall

# This command runs calculate.out
run:
	./driver.out

# This command removes all files in the directory ending in .out
clean:
	rm *.out
