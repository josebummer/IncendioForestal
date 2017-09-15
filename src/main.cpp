#include "incendioforestal.h"

int main(int argc, char const *argv[]) {
  if(argc != 2){
    cout << endl << "Indica el fichero con el mapa." << endl;
    return -1;
  }
  incendioforestal incendio;
  srand (time(NULL));

  if(incendio.leerMatriz(argv[1])){
    cout << "Arboles inicio: " << incendio.cuantosArboles() << endl;
    incendio.comenzar();
    incendio.escribirMatriz("salida.txt");
    cout << "Arboles al final: " << incendio.cuantosArboles() << endl;
    cout << "Arboles Quemados: " << incendio.cuantosArbolesQuemados() << endl;
    cout << "Fichero salida.txt creado correctamente." << endl;
  }
  else{
    cout << "Error al leer el fichero de entrada" << endl;
    return -1;
  }
  return 0;
}
