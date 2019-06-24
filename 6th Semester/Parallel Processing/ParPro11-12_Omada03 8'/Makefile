all: pthreadsO0 arxiko pthreadsO3 openmpO0 openmpO3 ipthreadsO0 ipthreadsO3 iopenmpO0 iopenmpO3

arxiko: SmithWaterman_pthreads.cpp
	g++ -O0 -o SmithWaterman SmithWaterman.cpp

pthreadsO0: SmithWaterman_pthreads.cpp
	g++ -O0 -o SmithWaterman_p0 SmithWaterman_pthreads.cpp -lpthread

pthreadsO3: SmithWaterman_pthreads.cpp
	g++ -O3 -o SmithWaterman_p3 SmithWaterman_pthreads.cpp -lpthread

openmpO0: SmithWaterman_openmp.cpp
	g++ -O0 -o SmithWaterman_openmp0 SmithWaterman_openmp.cpp -fopenmp

openmpO3: SmithWaterman_openmp.cpp
	g++ -O3 -o SmithWaterman_openmp3 SmithWaterman_openmp.cpp -fopenmp

ipthreadsO0: SmithWaterman_pthreads.cpp
	icpc -O0 -o iSmithWaterman_p0 SmithWaterman_pthreads.cpp -lpthread -I/usr/include/i386-linux-gnu/

ipthreadsO3: SmithWaterman_pthreads.cpp
	icpc -O3 -o iSmithWaterman_p3 SmithWaterman_pthreads.cpp -lpthread -I/usr/include/i386-linux-gnu/

iopenmpO0: SmithWaterman_openmp.cpp
	icpc -O0 -o iSmithWaterman_openmp0 SmithWaterman_openmp.cpp -fopenmp -I/usr/include/i386-linux-gnu/

iopenmpO3: SmithWaterman_openmp.cpp
	icpc -O3 -o iSmithWaterman_openmp3 SmithWaterman_openmp.cpp -fopenmp -I/usr/include/i386-linux-gnu/

clean:
	rm -f iSmithWaterman_p0 iSmithWaterman_p3 iSmithWaterman_openmp0 iSmithWaterman_openmp3 SmithWaterman_p0 SmithWaterman_p3 SmithWaterman SmithWaterman_openmp0 SmithWaterman_openmp3 
