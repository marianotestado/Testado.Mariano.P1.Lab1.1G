#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eEmpresa;

#endif // EMPRESA_H_INCLUDED


/** \brief
 *
 * \param empresas[] eEmpresa pide los datos del array de estructura eEmpresa.
 * \param tam int pide el tamanio del array.
 * \return int devuelve 1 si esta todo ok y devuelve 0 si surgio un error.
 *
 */
int mostrarEmpresas(eEmpresa empresas[], int tam);
/** \brief
 *
 * \param id int
 * \param empresas[] eEmpresa eEmpresa pide los datos del array de estructura eEmpresa.
 * \param tam int
 * \return int devuelve 1 si esta todo ok y devuelve 0 si surgio un error.
 *
 */
int validarIdEmpresa(int id, eEmpresa empresas[], int tam);
/** \brief
 *
 * \param empresas[] eEmpresa eEmpresa pide los datos del array de estructura eEmpresa.
 * \param tam int
 * \param idEmpresa int
 * \param descripcionEmpresa[] char
 * \return int devuelve 1 si esta todo ok y devuelve 0 si surgio un error.
 *
 */
int cargarDescripcionEmpresa(eEmpresa empresas[],int tam,int idEmpresa, char descripcionEmpresa[]);
