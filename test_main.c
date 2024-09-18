#include <gtest/gtest.h>
#include <stdio.h>

// Prototipo de la función main
int main();

TEST(MainTest, CapturaSalida) {
    // Redirigir stdout a un archivo temporal
    FILE* file = freopen("output.txt", "w", stdout);

    // Llamar a la función main
    main();

    // Restaurar stdout
    freopen("/dev/tty", "w", stdout);  // En Linux/Mac

    // Leer el archivo de salida
    FILE* f = fopen("output.txt", "r");
    char output[256] = {0};
    fread(output, sizeof(char), 255, f);
    fclose(f);

    // La salida esperada
    char salidaEsperada[] = "Resultado de la suma:\n6 8 \n10 12 \n";

    // Comparar la salida con la salida esperada
    EXPECT_STREQ(output, salidaEsperada);
}
