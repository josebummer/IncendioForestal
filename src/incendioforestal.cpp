#include "incendioforestal.h"

bool incendioforestal::calcularNuevoEstado(){
  bool seguimos = false;
  for(int i = 0; i < tamanio; i++){
    for(int j = 0; j < tamanio;j++){
      if(M[i][j] == 'Q'){
        if(verVecinos(i,j) && !seguimos) seguimos = true;
      }
    }
  }
  return seguimos;
}

/*
Calcula al azar una velocidad y una direccion
*/
void incendioforestal::calcularViento(){
  // Calculo una direccion aleatoria valida COMENTAR ESTO PARA PONER UNA DIRECCION FIJA
  direccion = random()%8;

  /*
  0 --> 90º
  1 --> 135º
  2 --> 180º
  3 --> 225º
  4 --> 270º
  5 --> 315º
  6 --> 360º
  7 --> 45º

  */

    //DESCOMENTAR ESTO PARA PONER UNA DIRECCION FIJA
  // direccion = 225;


  //Calculo una velocidad aleatoria entre 0 y 2 COMENTAR ESTO PARA PONER UNA VELOCIDAD FIJA
  velocidad = random()%3;


  // DESCOMENTAR ESTO PARA PONER UNA VELOCIDAD FIJA
  // velocidad = 2;
}

/*
Quema un arbol del mapa al azar para que empiece a propagarse
*/
void incendioforestal::iniciar_fuego(){
  int i, j;
  do{
    //COMENTAR ESTO PARA QUEMAR UN ARBOL FIJO
    i = random()%tamanio;
    j = random()%tamanio;

    //DESCOMENTAR ESTO PARA PONER UN ARBOL FIJO
    // i = 99;
    // j = 93;
  }while(M[i][j] != 'A');
  cout << "El incendio ha empezado en: ";
  cout << "fila: " << i << " columna: " << j << endl;
  M[i][j] = 'Q';
}

/*
Cambia los valores de los arboles que van a ser quemados
*/
bool incendioforestal::ActualizarElemento(int i, int j){
  if(M[i][j] == 'A'){
    M[i][j] = 'Q';
    return true;
  }
  return false;
}

/*
Mira los vecinos de los arboles quemados segun la direccion y la velocidad
*/
bool incendioforestal::verVecinos(int h , int k){
  bool seguimos = false;
  if(velocidad == 0){
    for(int i = h-1; i <= h+1 && i < tamanio && i >= 0; i++){
      for(int j = k-1; j <= k+1 && j < tamanio && j >= 0; j++ ){
        if( i != h || j != k ){
          if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
        }
      }
    }
  }
  else{
      switch (direccion) {
        case 0:
          for(int i = h-1; i <= h+1 && i < tamanio && i >= 0; i++){
            for(int j = k-velocidad; j <= k && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        break;
        case 1:
        if(velocidad == 1){
          for(int i = h-velocidad; i <= h+velocidad && i < tamanio && i >= 0; i++){
            for(int j = k-velocidad; j <= k+velocidad && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(i == h-1 || j == k-1)
                  if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        }
        else{
          for(int i = h-velocidad; i <= h && i < tamanio && i >= 0; i++){
            for(int j = k-velocidad; j <= k && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        }
        break;
        case 2:
          for(int i = h-velocidad; i <= h && i < tamanio && i >= 0; i++){
            for(int j = k-1; j <= k+1 && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        break;
        case 3:
          if(velocidad == 1){
            for(int i = h-velocidad; i <= h+velocidad && i < tamanio && i >= 0; i++){
              for(int j = k-velocidad; j <= k+velocidad && j < tamanio && j >= 0; j++ ){
                if( i != h || j != k ){
                  if(i == h-1 || j == k+1)
                    if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
                }
              }
            }
          }
          else{
            for(int i = h-velocidad; i <= h && i < tamanio && i >= 0; i++){
              for(int j = k; j <= k+velocidad && j < tamanio && j >= 0; j++ ){
                if( i != h || j != k ){
                  if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
                }
              }
            }
          }
        break;
        case 4:
          for(int i = h-1; i <= h+1 && i < tamanio && i >= 0; i++){
            for(int j = k; j <= k+velocidad && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        break;
        case 5:
        if(velocidad == 1){
          for(int i = h-velocidad; i <= h+velocidad && i < tamanio && i >= 0; i++){
            for(int j = k-velocidad; j <= k+velocidad && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(i == h+1 || j == k+1)
                  if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        }
        else{
          for(int i = h; i <= h+velocidad && i < tamanio && i >= 0; i++){
            for(int j = k; j <= k+velocidad && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        }
        break;
        case 6:
          for(int i = h; i <= h+velocidad && i < tamanio && i >= 0; i++){
            for(int j = k-1; j <= k+1 && j < tamanio && j >= 0; j++ ){
              if( i != h || j != k ){
                if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
              }
            }
          }
        break;
        case 7:
          if(velocidad == 1){
            for(int i = h-velocidad; i <= h+velocidad && i < tamanio && i >= 0; i++){
              for(int j = k-velocidad; j <= k+velocidad && j < tamanio && j >= 0; j++ ){
                if( i != h || j != k ){
                  if(i == h+1 || j == k-1)
                    if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
                }
              }
            }
          }
          else{
            for(int i = h; i <= h+velocidad && i < tamanio && i >= 0; i++){
              for(int j = k-velocidad; j <= k && j < tamanio && j >= 0; j++ ){
                if( i != h || j != k ){
                  if(ActualizarElemento(i,j) && !seguimos) seguimos = true;
                }
              }
            }
          }
        break;
      }
  }
  return seguimos;
}

/*
Contructor por defecto
*/
incendioforestal::incendioforestal(){
  direccion = velocidad = tamanio = 0;
}

/*
Le el mapa de una fichero y lo carga en la matriz de la clase
*/
bool incendioforestal::leerMatriz(const char *nombre){
  // Abrir fichero de entrada
  ifstream fichero (nombre);

  // Si no se abre bien el fichero da error
  if(fichero.is_open()){
    fichero >> tamanio;
    M.reserve(tamanio);
    for(int i = 0; i < tamanio; i++){
      M[i].reserve(tamanio);
    }
    int i, j;
    i = j = 0;
      while(i < tamanio){
        j = 0;
        while(j < tamanio){
          fichero >> M[i][j];
          j++;
        }
        i++;
      }
  }
  else{
    perror("El fichero no pudo ser leido");
    return false;
  }

  fichero.close();
  return true;
}

/*
Muestra el contenido de la matriz
*/
void incendioforestal::mostrarMatriz() const{
  for (int i = 0; i < tamanio; i++) {
    for (int j = 0; j < tamanio; j++) {
      cout << M[i][j];
    }
    cout << endl;
  }
}

/*
Devuelve el numero de arboles que hay en el mapa
*/
int incendioforestal::cuantosArboles() const{
  int c = 0;
  for(int i = 0; i < tamanio; i++){
    for(int j = 0; j < tamanio;j++){
      if(M[i][j] == 'A') c++;
    }
  }
  return c;
}

/*
Devuelve e lnumero de arboles quemados que hay en el mapa
*/
int incendioforestal::cuantosArbolesQuemados() const{
  int c = 0;
  for(int i = 0; i < tamanio; i++){
    for(int j = 0; j < tamanio;j++){
      if(M[i][j] == 'Q') c++;
    }
  }
  return c;
}

/*
Comienza la propagacion
*/
void incendioforestal::comenzar(){
  iniciar_fuego();

  calcularViento();
  // cout << endl << "velocidad: " << velocidad << " direccion: " << direccion << endl;
  while(calcularNuevoEstado()){
    calcularViento();
    // cout << endl << "velocidad: " << velocidad << " direccion: " << direccion << endl;
  }
}

/*
Escribe la matriz final en un fichero de salida
*/
void incendioforestal::escribirMatriz(const char *salida) const{
  // Abrir fichero de entrada
  ofstream fichero (salida);

  // Si no se abre bien el fichero da error
  if(fichero.is_open()){
    int i, j;
    i = j = 0;
      while(i < tamanio){
        j = 0;
        while(j < tamanio){
          fichero << M[i][j];
          j++;
        }
        fichero << endl;
        i++;
      }
  }
  fichero.close();
}
