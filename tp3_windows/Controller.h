int menu();
char menuListadoOrden();
char menuListado();
char menuCovocados();
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int buscarMayorId(LinkedList* pArrayListJugador, int* id);
int controller_buscarJugador(LinkedList* pArrayListJugador, int id);
int confirmarSalida(char *pControl);
int menuPosiciones(char posicion[]);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);
int menuModificacion();
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_ordenarJugadoresEdad(LinkedList* pArrayListJugador);
int controller_ordenarJugadoresNacionalidad(LinkedList* pArrayListJugador);
int controller_ordenarJugadoresNombre(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_buscarSeleccion(LinkedList* pArrayListSeleccion, int id);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_quitarConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

