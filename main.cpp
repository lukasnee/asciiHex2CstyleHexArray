#include <iostream>
#include <cstring>
#include <string>

int main (int argc, char* argv[])
{
  if(argc != 2)
  {
    std::cout << argv[0] << " <hexInAscii>" << std::endl;
    return -1;
  }

  std::string inStr(argv[1]);

  if(inStr.length() % 2)
  {
    std::cout << "input must be even length" << std::endl;
    return -2;
  }


  for(auto &c : inStr)
  {
    if(false == (std::isdigit(c) or (c >= 'a' and c <= 'f') or (c >= 'A' and c <= 'F'))) 
    {
      std::cout << "string is not in hex ascii" << std::endl;
      return -3;
    }  
  }

  std::cout << "const char * hex[] = {" << std::endl;

  const int maxElementsInLine = 8;
  int symbolNumber = 0;
  int line = 0;
  int elementNumber = 0;
  for(auto &c : inStr)
  {
    if(elementNumber % maxElementsInLine == 0 and symbolNumber % 2 == 0)
    {
      std::cout << "    ";
    }

    if(symbolNumber % 2 == 0)
    {
      std::cout << "0x" << c;
    }
    else if(symbolNumber % 2 == 1)
    {
      std::cout << c << ", ";
    }

    if(elementNumber % maxElementsInLine == maxElementsInLine - 1 and symbolNumber % 2 == 1)
    {
      std::cout << std::endl;
    }

    symbolNumber++;
    if(symbolNumber % 2 == 0)
    {
      elementNumber++;
      if(elementNumber % maxElementsInLine == 0)
      {
        line++;
      }
    }
  }

  if(elementNumber % maxElementsInLine != 0)
  {
    std::cout << std::endl;
  }

  std::cout << "};" << std::endl;

  std::cout << std::endl << "done!" << std::endl;

  return 0;
}
