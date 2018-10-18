#include "Adder.h"
#include "Substractor.h"

#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  if (argc < 4)
  {
    std::cerr << "Usage: <Symbol> <integer 1> <interger 2>" << std::endl;
    return EXIT_FAILURE;
  }

  char symbol = *argv[2];
  int a;
  int b;
  try
  {
    a = std::stoi(argv[1]);
    b = std::stoi(argv[3]);
  }
  catch (std::invalid_argument&)
  {
    std::cerr << "Unable to convert " << argv[1] << " or " << argv[3] << " to an integer value." << std::endl;
    return EXIT_FAILURE;
  }
  catch (std::out_of_range&)
  {
    std::cerr << argv[1] << " or " << argv[3] << " is out of range." << std::endl;
    return EXIT_FAILURE;
  }

  int res = -1;
  switch (symbol)
  {
  case '+':
  {
    Adder adder;
    res = adder.Add(a, b);
    break;
  }
  case '-':
  {
    Substractor substractor;
    res = substractor.Substract(a, b);
    break;
  }
  default:
  {
    std::cerr << a << " " << symbol << " " << b << " is not a valid expression." << std::endl;
    return EXIT_FAILURE;
  }
  }

  std::cout << a << " " << symbol << " " << b << " = " << res << std::endl;
  
  return EXIT_SUCCESS;
}