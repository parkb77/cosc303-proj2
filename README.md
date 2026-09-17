#CONTRIBUTORS
Parker Babb - pbabb2 - pbabb2@vols.utk.edu
Casey Higgins - 

#HOW TO RUN
git clone https://github.com/parkb77/cosc303-proj2.git
git pull
make test

#PERFORMANCE

| Mode    | Size      |  Elapsed Time | Memory     |
|---------|-----------|---------------|------------|
| STL     | 100000    | 0.57 sec      | 10528 KB   |
| STL     | 500000    | 1.57 sec      | 38824 KB   |
| STL     | 1000000   | 3.71 sec      | 75200 KB   |
| STL     | 10000000  | 73.66 sec     | 759464 KB  |
| STL     | 25000000  | 184.49 sec    | 1828140 KB |
| QSORT   | 100000    | 0.22 sec      | 10976 KB   |
| QSORT   | 500000    | 1.19 sec      | 42176 KB   |
| QSORT   | 1000000   | 2.24 sec      | 81236 KB   |
| QSORT   | 10000000  | 52.50 sec     | 784256 KB  |
| QSORT   | 25000000  | 113.43 sec    | 1955604 KB |
| MERGE   | 100000    | 0.08 sec      | 9856 KB    |
| MERGE   | 500000    | 0.47 sec      | 34816 KB   |
| MERGE   | 1000000   | 1.11 sec      | 66048 KB   |
| MERGE   | 10000000  | 14.47 sec     | 628608 KB  |
| MERGE   | 25000000  | 41.19 sec     | 1566080 KB |
| QUICK   | 100000    | 0.09 sec      | 9856 KB    |
| QUICK   | 500000    | 0.79 sec      | 34816 KB   |
| QUICK   | 1000000   | 1.90 sec      | 66048 KB   |
| QUICK   | 10000000  | 36.22 sec     | 628608 KB  |
| QUICK   | 25000000  | 95.88 sec     | 1566080 KB |

#DISCUSSION
Merge sort was the fastest, followed by quick, Q, then STL. Both Merge and Quick were
faster and used significantly less memory than STL and Q. This was likely due to the latter using temporary vectors to help 
sort the nodes rather than simply redirecting the pointers.


#CONTRIBUTIONS / REFLECTION

Once again, the workload was fairly split and good communication maintained. I completed the STL 
and MERGE algorithms, timed the MERGE and QUICK programs, and created the README. We exchanged ideas on implementation and helped one another 
debug. This project made me a lot more comfortable navigating GitHub while also solidifying my understanding of pointers.
- Parker Babb
