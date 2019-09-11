#include <iostream>
#include <fcntl.h>   // open
#include <unistd.h>  // read, write, close
#include <cstdio>    // BUFSIZ
#include <ctime>
using namespace std;

int main() {
    clock_t start, end;
    start = clock();

    // BUFSIZE defaults to 8192
    // BUFSIZE of 1 means one chareter at time
    // good values should fit to blocksize, like 1024 or 4096
    // higher values reduce number of system calls
    // size_t BUFFER_SIZE = 4096;

    char buf[BUFSIZ];
    size_t size;

    int source = open("from.ogv", O_RDONLY, 0);
    int dest = open("to.ogv", O_WRONLY | O_CREAT /*| O_TRUNC/**/, 0644);

    while ((size = read(source, buf, BUFSIZ)) > 0) {
        write(dest, buf, size);
    }

    close(source);
    close(dest);

    end = clock();

    cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
    cout << "CPU-TIME START " << start << "\n";
    cout << "CPU-TIME END " << end << "\n";
    cout << "CPU-TIME END - START " << end - start << "\n";
    cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}