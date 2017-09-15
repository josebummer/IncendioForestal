
#ifndef __incendioforestal_H
#define __incendioforestal_H

#include <iostream>
#include <fstream>
#include <utility>
#include <cstdlib>
#include <vector>

using namespace std;

class incendioforestal{
private:
  int direccion;
  int velocidad;
  int tamanio;
  vector<vector<char> > M;

  /*
  Quema los arboles de alrededor de un arbol quemado teniendo en cuenta la velocidad y la direccion
  */
  bool calcularNuevoEstado();

  /*
  Calcula al azar una velocidad y una direccion
  */
  void calcularViento();

  /*
  Quema un arbol del mapa al azar para que empiece a propagarse
  */
  void iniciar_fuego();

  /*
  Cambia los valores de los arboles que van a ser quemados
  */
  bool ActualizarElemento(int i, int j);

  /*
  Mira los vecinos de los arboles quemados segun la direccion y la velocidad
  */
  bool verVecinos(int h , int k);

public:
  /*
  Contructor por defecto
  */
  incendioforestal();

  /*
  Le el mapa de una fichero y lo carga en la matriz de la clase
  */
  bool leerMatriz(const char *nombre);

  /*
  Muestra el contenido de la matriz
  */
  void mostrarMatriz() const;

  /*
  Devuelve el numero de arboles que hay en el mapa
  */
  int cuantosArboles() const;

  /*
  Devuelve e lnumero de arboles quemados que hay en el mapa
  */
  int cuantosArbolesQuemados() const;

  /*
  Comienza la propagacion
  */
  void comenzar();

  /*
  Escribe la matriz final en un fichero de salida
  */
  void escribirMatriz(const char *salida) const;

};

#endif
