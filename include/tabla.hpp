struct rep_tabla;

typedef rep_tabla *tabla;

/*
 Crea una tabla de asociaciones texto->numero.
 Podrá haber hasta `tamanio' asociaciones.
 */
tabla crear_tabla(int tamanio);

/*
  Inserta en `t' la asociación entre `clave' y `valor'.
  Si ya existía una asociación para `clave' es reemplazada por la
  nueva.
  Precondición: valor != INT_MAX.
  El tiempo de ejecución es O(1).
 */
void insertar_en_tabla(char clave, int valor, tabla &t);

/*
  Elimina de `t' la asociación entre `clave' y algún valor y libera la menoria
  asignada a mantener esa asociación.
  El tiempo de ejecución es O(1) en promedio.
 */
void eliminar_de_tabla(char clave, tabla &t);

/*
 Libera la memoria asignada a `t' y todos sus elementos.
 */
void liberar_tabla(tabla &t);

/*
  Devuelve el valor correspondiente a la asociación de `clave' en `t', o INT_MAX
  si no existe tal asociación.
  El tiempo de ejecución es O(1) en promedio.
 */
int valor_en_tabla(char clave, tabla t);
