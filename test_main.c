#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>

// Prototipo de la función main
int main();

TEST(MatrixSumTest, CorrectOutput) {
    // Redirigir stdin para simular la entrada
    FILE* input = freopen("input.txt", "w", stdin);
    fprintf(input, "2 2\n2 2\n1 2\n3 4\n5 6\n7 8\n");
    fclose(input);
    freopen("input.txt", "r", stdin);

    // Redirigir stdout a un archivo temporal para capturar la salida
    FILE* output = freopen("output.txt", "w", stdout);

    // Ejecutar la función main
    main();

    // Restaurar stdout y stdin
    freopen("/dev/tty", "w", stdout);  // En Linux/Mac (cambiar en Windows a "CON")
    freopen("/dev/tty", "r", stdin);

    // Leer el archivo de salida
    FILE* f = fopen("output.txt", "r");
    char result[256] = {0};
    fread(result, sizeof(char), 255, f);
    fclose(f);

    // La salida esperada
    const char* expectedOutput = "6\t8\t\n10\t12\t\n";

    // Comparar la salida con la salida esperada
    EXPECT_STREQ(result, expectedOutput);
}
