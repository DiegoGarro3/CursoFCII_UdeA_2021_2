//#include <c:\\mibiblioteca\\myToy.cpp>
//#include "/home/jmejia/Escritorio/nuevacompu/UdeA/Cursos/ComputacionalII/lectures/clase8/namespace/myToy.cpp"
#include "myToy.cpp"

using namespace first_space;
//using namespace second_space;

//using namespace Menagerie;


int main()
{
  // This calls function from first name space.
  myfunc();
  //first_space::myfunc();
  //second_space::myfunc();

  /*
  Menagerie::Cattle bessie;
  bessie.Weight = 643;
  std::cout << bessie.Weight << std::endl;
  */
  
  return 0;
}
