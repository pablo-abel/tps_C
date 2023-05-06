#ifndef UTN_H_
#define UTN_H_

int esNumero(char* cadena);
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);

#endif /* UTN_H_ */
