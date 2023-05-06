#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char sexo;

}eMascota;

eMascota* new_Mascota();

eMascota* new_MascotaParam(int id, char* nombre, int edad, char sexo);

int mascotaSetId(eMascota* pMasc, int id);
int mascotaGetId(eMascota* pMasc, int* pId);

int mascotaSetNombre(eMascota* pMasc, char* nombre);
int mascotaGetNombre(eMascota* pMasc, char* pNombre);

int mascotaSetEdad(eMascota* pMasc, int edad);
int mascotaGetEdad(eMascota* pMasc, int* pEdad);

int mascotaSetSexo(eMascota* pMasc, char sexo);
int mascotaGetFullSexo(eMascota* pMasc, char* pSexo);


#endif // MASCOTA_H_INCLUDED

int mostrarMascota(eMascota* mascota);
void mostrarMascotas(LinkedList* lista);
// funcion filtro
int esMacho(void* m);

