#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

/**
 * Función que muestra los participantes del grupo
 */
void participante();

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */

int aleatoreo(int inferior, int superior);
float promedio(float _nem, float _ranking, float _matematica, float _lenguaje, float _ciencia, float _historia);

int main(int argc, char** argv) {
    srand((unsigned int) time(0));
    
    std::ofstream archivoSalida("puntajes.csv");
    std::ofstream archivoSalida2("rutypromedio.csv");
    
    for (unsigned long rut=14916641; rut<= 19932391; rut++){
        int nem = aleatoreo(475,750);
        int ranking = aleatoreo(475,750);
        int matematica = aleatoreo(475,750);
        int lenguaje = aleatoreo(475,750);
        int ciencia = aleatoreo(475,750);
        int historia = aleatoreo(475,750);
        float prom = promedio(nem, ranking, matematica, lenguaje, ciencia, historia);
            
        archivoSalida << rut << ";" << nem << ";" << ranking << ";" << matematica << ";" << lenguaje << ";" << ciencia << ";" << historia << ";" << prom << std::endl;
        archivoSalida2 << rut << ";" << prom << std::endl;
    }
    
    archivoSalida.close();
    archivoSalida2.close();

    participante();
    return EXIT_SUCCESS;
}

void participante() {
    std::cout << std::endl << "=== Puntaje PSU ===" << std::endl;
    std::cout << std::endl << "Sion-Jei Mamani León" << std::endl; 
    std::cout << std::endl << "Janira Navarro Quilaqueo" << std::endl;
    std::cout << std::endl << "Shu-Yi Wong Baxter" << std::endl;
}

int aleatoreo(int inferior, int superior) {
    return (rand() % (superior - (inferior + 1))) + inferior;

}

float promedio(float _nem, float _ranking, float _matematica, float _lenguaje, float _ciencia, float _historia) {
    return roundf(((_nem + _ranking + _matematica + _lenguaje + _ciencia + _historia)/6)*100)/100;
}