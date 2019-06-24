#!/bin/bash
echo "  POSIX Threads  "
echo " GCC Compiler "
echo "To SmithWaterman: "
./SmithWaterman 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To SmithWaterman_p0 me 1 thread: "
./SmithWaterman_p0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To SmithWaterman_p0 me 2 thread: "
./SmithWaterman_p0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To SmithWaterman_p0 me 4 thread: "
./SmithWaterman_p0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To SmithWaterman_p3 me 1 thread: "
./SmithWaterman_p3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To SmithWaterman_p3 me 2 thread: "
./SmithWaterman_p3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To SmithWaterman_p3 me 4 thread: "
./SmithWaterman_p3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo " Intel icpc Compiler "
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To iSmithWaterman_p0 me 1 thread: "
./iSmithWaterman_p0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To iSmithWaterman_p0 me 2 thread: "
./iSmithWaterman_p0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To iSmithWaterman_p0 me 4 thread: "
./iSmithWaterman_p0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To iSmithWaterman_p3 me 1 thread: "
./iSmithWaterman_p3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To iSmithWaterman_p3 me 2 thread: "
./iSmithWaterman_p3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To iSmithWaterman_p3 me 4 thread: "
./iSmithWaterman_p3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "  OpenMP  "
echo "__________"
echo " GCC Compiler "
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To SmithWaterman_openmp0 me 1 thread: "
./SmithWaterman_openmp0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To SmithWaterman_openmp0 me 2 thread: "
./SmithWaterman_openmp0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To SmithWaterman_openmp0 me 4 thread: "
./SmithWaterman_openmp0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To SmithWaterman_openmp3 me 1 thread: "
./SmithWaterman_openmp3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To SmithWaterman_openmp3 me 2 thread: "
./SmithWaterman_openmp3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To SmithWaterman_openmp3 me 4 thread: "
./SmithWaterman_openmp3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo " Intel icpc Compiler "
echo "To iSmithWaterman: "
./iSmithWaterman 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To iSmithWaterman_openmp0 me 1 thread: "
./iSmithWaterman_openmp0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To iSmithWaterman_openmp0 me 2 thread: "
./iSmithWaterman_openmp0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To iSmithWaterman_openmp0 me 4 thread: "
./iSmithWaterman_openmp0 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"
echo "To iSmithWaterman_openmp3 me 1 thread: "
./iSmithWaterman_openmp3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 1 | grep seconds
echo "To iSmithWaterman_openmp3 me 2 thread: "
./iSmithWaterman_openmp3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 2 | grep seconds
echo "To iSmithWaterman_openmp3 me 4 thread: "
./iSmithWaterman_openmp3 0.33 1.33 Adenovirus-C15.txt Enterobacteria-phage-T715.txt 1000 4 | grep seconds
echo "~~~~~~~~~~~~             	~~~~~~~~~~~~"

