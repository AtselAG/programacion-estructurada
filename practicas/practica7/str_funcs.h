/**
 * Convierte una letra minuscula a mayuscula usando su valor ASCII.
 *
 *@param letra: Caracter que se quiere convertir.
 *@returns La letra en mayuscula si era minuscula, 0 si ya era mayuscula,
 *         o -1 si no es una letra.
 *
 */
char aMayus(char letra);

/**
 * Obtiene el ultimo caracter de una cadena (antes del '\0').
 *
 *@param palabra: Cadena terminada en '\0'; no debe estar vacia.
 *@returns El ultimo caracter de la cadena.
 *
 */
char ultimoChar(char palabra[]);

/**
 * Calcula la longitud de una cadena, sin contar el caracter nulo '\0'.
 *
 *@param cad: Cadena terminada en '\0' a medir.
 *@returns El numero de caracteres de la cadena.
 *
 */
int mi_strlen(const char *cad);

/**
 * Concatena la cadena orig al final de la cadena dest.
 *
 *@param dest: Cadena destino; debe tener espacio suficiente para ambas cadenas
 *             mas el '\0'.
 *@param orig: Cadena que se agrega al final de dest.
 *@returns Un puntero a dest.
 *
 */
char *mi_strcat(char *dest, const char *orig);

/**
 * Compara dos cadenas caracter por caracter (orden lexicografico).
 *
 *@param a: Primera cadena a comparar.
 *@param b: Segunda cadena a comparar.
 *@returns 0 si son iguales, un valor negativo si a es menor que b,
 *         o un valor positivo si a es mayor que b.
 *
 */
int mi_strcmp(const char *a, const char *b);

/**
 * Copia la cadena orig en dest, incluyendo el caracter nulo '\0'.
 *
 *@param dest: Cadena destino; debe tener espacio suficiente para orig.
 *@param orig: Cadena que se va a copiar.
 *@returns Un puntero a dest.
 *
 */
char *mi_strcpy(char *dest, const char *orig);

int idx_ultima_letra(const char *cad);