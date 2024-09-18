#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>

START_TEST(test_suma_matrices) {
    FILE *fp;
    char output[256];
    char expected_output[] = "Resultado de la suma:\n6\t8\t\n10\t12\t\n";

    // Ejecutar el programa principal
    fp = popen("./main_program", "w");
    if (fp == NULL) {
        perror("Error al abrir el programa");
        return;
    }

    // Proveer la entrada al programa
    fprintf(fp, "2 2\n2 2\n1 2\n3 4\n5 6\n7 8\n");
    pclose(fp);

    // Leer la salida
    fp = popen("./main_program", "r");
    fread(output, sizeof(char), 255, fp);
    pclose(fp);

    // Comparar la salida con la salida esperada
    ck_assert_str_eq(output, expected_output);
}
END_TEST

Suite* suma_suite(void) {
    Suite* suite;
    TCase* tcase;

    suite = suite_create("Suma");
    tcase = tcase_create("Pruebas");

    tcase_add_test(tcase, test_suma_matrices);
    suite_add_tcase(suite, tcase);

    return suite;
}

int main(void) {
    int number_failed;
    Suite* suite;
    SRunner* runner;

    suite = suma_suite();
    runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_failed == 0) ? 0 : 1;
}
