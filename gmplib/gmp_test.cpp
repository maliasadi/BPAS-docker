// g++ -o gmp_test.bin gmp_test.cpp -lgmp

#include <iostream>
#include <gmp.h>

using namespace std;

int main (int argc, char *argv[]) {

	cout << "Test gmp_test.cpp" << endl;

   	mpz_t x,y,z;
    mpz_inits(x,y,z,NULL);

    mpz_set_str(x, "1024", 10);
    mpz_set_str(y, "2048", 10);

    cout << "x = ";
    mpz_out_str(stdout, 10, x);
    cout << endl;

    cout << "y = ";
    mpz_out_str(stdout, 10, y);
    cout << endl;

    mpz_add(z, x, y);

    cout << "Add(x, y) = ";
    mpz_out_str(stdout, 10, z);
    cout << endl;

    mpz_sub(z, y, x);

    cout << "Sub(y,x) = ";
    mpz_out_str(stdout, 10, z);
    cout << endl;

    mpz_clears(x,y,z,NULL);
    return 0;
}