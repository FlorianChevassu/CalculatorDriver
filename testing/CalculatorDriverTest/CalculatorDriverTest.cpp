#include <cstdlib>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		return EXIT_FAILURE;
	}

  std::string failureState(argv[1]);
  int expectedOutput = (failureState == "ERROR") ? EXIT_FAILURE : EXIT_SUCCESS;
  
  std::string calculatorDriverExecutable(argv[2]);

  std::stringstream cmd;
  cmd << calculatorDriverExecutable << " ";
  for (size_t i = 3; i < argc; ++i)
  {
    cmd << argv[i] << " ";
  }
  std::cout << cmd .str()<< std::endl;


  int result = std::system(cmd.str().c_str());

  if (expectedOutput == result)
  {
    return EXIT_SUCCESS;
  }
  else
  {
    return EXIT_FAILURE;
  }
}