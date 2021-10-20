#include <iostream>
#include <chrono>
/*
 * g++ -o c.exe chrono.c++  -std=gnu++11
 */

int main ()
{
  using namespace std::chrono;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  std::cout << "Imprimindo 1000 estrelas...\n";
  for (int i=0; i<1000; ++i) {
    std::cout << "*";
  }
    std::cout << std::endl;

  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span =
     duration_cast<duration<double>>(t2 - t1);

  std::cout << "Tempo : " << time_span.count() << " segundos para impressao.";
  std::cout << std::endl;
  return 0;
}
