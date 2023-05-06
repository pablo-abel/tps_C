#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getArchivo( char *pArchivo, int limite, char *mensaje, char *mensajeError, int reintentos);
int myGets(char* cadena, int longitud);
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);

int utn_getFloatPositivo(float *pFloat, int limite, char *mensaje, char *mensajeError, int reintentos);
int utn_getEnteroSoloNumeros(int *pEntero, int limite, char *mensaje, char *mensajeError, int reintentos);

#endif // UTN_H_INCLUDED
