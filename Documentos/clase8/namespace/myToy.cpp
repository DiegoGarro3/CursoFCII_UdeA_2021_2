#include <iostream>

//using namespace std;

// first name space
namespace first_space {
  void myfunc() {
    std::cout << "Inside first_space" << std::endl;
  }
}

// second name space
namespace second_space {
  void myfunc() {
    std::cout << "Inside second_space" << std::endl;
  }
}

namespace Menagerie {
class Oxen {
public:
  
  int Weight;
  int NumberOfTeeth;
};
  
  class Cattle {
  public:
    int Weight;
    int NumberOfChildren;
  };
  
}

