#include "time.h"

int main()
{
  Tiempo despertar( 6, 45, 0 ); // objeto no constante
  const Tiempo mediodia( 12, 0, 0 ); // objeto constante
  
  // OBJETO     FUNCIÓN MIEMBRO
  despertar.setHora( 18 );      // no const   // no const
  
  mediodia.setHora( 12 );       // const      no const
  
  despertar.getHora();          // no const    const
  
  mediodia.getMinuto();          // const      const 
  mediodia.imprimirUniversal();  // const      const
  
  mediodia.imprimirEstandar();   // const      no const
  
  return 0;
}
