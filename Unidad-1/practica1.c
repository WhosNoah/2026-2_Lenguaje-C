#include <stdio.h>
#include <math.h>

const double PI = 3.141592653589;

int capturarBase(char* mensaje, double *base);
int capturarAltura(char* mensaje, double *altura);
double calculoHipotenusa(double base, double altura);
double calculoArea(double base, double altura);
double calcularPerimetro(double base, double altura, double hipotenusa);
double calcularTheta(double base, double altura);
double calcularBeta(double theta);

int main(void) {
    double base, altura, hipotenusa, area, perimetro, theta, beta;

    capturarBase("Captura la base de tu triangulo: ", &base); // 5
    capturarAltura("Captura la altura de tu triangulo: ", &altura); // 8
    hipotenusa = calculoHipotenusa(base, altura); // 9.433981
    area = calculoArea(base, altura); // 20
    perimetro = calcularPerimetro(base, altura, hipotenusa); // 22.433981
    theta = calcularTheta(base, altura);
    beta = calcularBeta(theta);

    printf("La hipotenusa es: %lf\n", hipotenusa);
    printf("El area es: %lf\n", area);
    printf("El perimetro es: %lf\n", perimetro);
    printf("Theta es (en radianes): %lf\n", theta);
    printf("Theta es (en grados): %lf\n", theta*180/PI);
    printf("Beta es (en grados): %lf\n", beta);

    return 0;
}

int capturarBase(char* mensaje, double *base) {
    printf("%s", mensaje);
    scanf("%lf", base);
}

int capturarAltura(char* mensaje, double *altura) {
    printf("%s", mensaje);
    scanf("%lf", altura);
}

double calculoHipotenusa(double base, double altura) {
    double res;
    return res = sqrt(pow(base,2) + pow(altura,2));
}

double calculoArea(double base, double altura) {
    double res;
    return res = (base*altura)/2;
}

double calcularPerimetro(double base, double altura, double hipotenusa) {
    double res;
    return res = base+altura+hipotenusa;
}

double calcularTheta(double base, double altura) {
    double res;
    return res = atan(altura/base);
}

double calcularBeta(double theta) {
    double res;
    return res = 90-((theta*180)/PI);
}