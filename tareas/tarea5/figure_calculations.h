#define pi 3.1415926535

/**
 *
 *@param base: Numero a elevar a una cierta potencia.
 *@param exp: Exponente a elevar la base :v.
 *@returns El resultado de elevar la base a potencia dada.
 *
 */
float elevar(float base, int exp);

/**
 *
 *@param radio: Radio del circulo que  se quiere calcular.
 *@returns El area del circulo.
 *
 */
float areaCirculo(float radio);

/**
 *
 *@param radio: Radio del circulo que  se quiere calcular.
 *@returns Circunferencia del circulo.
 *
 */
float circunf(float radio);

/**
 *
 *@param base: Base del rectangulo.
 *@param altura: Altura del rectangulo.
 *@returns El area de un rectangulo.
 *
 */
float areaRect(float base, float altura);

/**
 *
 *@param base: Base del rectangulo.
 *@param altura: Altura del rectangulo.
 *@returns El perimetro de un rectangulo
 *
 */
float perimRect(float base, float altura);

/**
 *
 *@param base: Base del triangulo.
 *@param altura: Altura del triangulo.
 *@returns El area de un triangulo
 *
 */
float areaTriangulo(float base, float altura);

/**
 *Importante, esto solo aplica para triangulos isosceles
 *@param base: Base del triangulo isosceles
 *@param altura: Altura del triangulo.
 *@returns El perimetro de un triangulo
 *
 */
float perTriangulo(float base, float altura);

/**
 *
 *@brief Valida un radio para asegurarse de que sea un valor positivo.
 *@returns El radio ingresado si es valida.
 *
 */
float validarRadio(void);

/**
 *
 *@brief Valida una base para asegurarse de que sea un valor positivo.
 *@returns La base ingresada si es valida.
 *
 */
float validarBase(void);

/**
 *
 *@brief Valida una altura para asegurarse de que sea un valor positivo.
 *@returns La altura ingresada si es valida.
 *
 */
float validarAltura(void);

/**
 *
 *@brief Checa si el numero ingresado es palindromo
 *@returns Regresa 0 si es palindromo o -1 si no lo es.
 *
 */
int esPalindromo(int n);
