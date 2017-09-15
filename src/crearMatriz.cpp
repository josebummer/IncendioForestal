#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
  if(argc != 2){
    cout << endl << "Indique el numero de filas/columnas del mapa." << endl;
    return -1;
  }
  srand (time(NULL));
  int f = atoi(argv[1]);
  cout << f << endl;
  for(int i = 0; i < f; i++){
    for(int j = 0; j < f; j++){
      //AUMENTAR EL NUMERO QUE ACOMPAÑA AL RAND, DISMINUYE EL NUMERO DE ARBOLES DEL MAPA
      int v = random()%3;
      char valor = ( v == 0 )?'A':'T';  //NO MODIFICAR, SOLO EL RANDOM.
      cout << valor;
    }
    cout << endl;
  }

  return 0;
}
