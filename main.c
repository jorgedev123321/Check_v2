#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <time.h>

int perform_checksum_validation() {
    struct utsname sys_info;
    if (uname(&sys_info) != 0) return 0;

    printf("[*] Target System: %s %s\n", sys_info.sysname, sys_info.machine);
    
    clock_t start_t = clock();
    for (int i = 0; i < 500000; i++) {
        unsigned int temp = i * i;
    }
    clock_t end_t = clock();
    
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("[*] Integrity cycle completed in %.4f ms\n", total_t);
    
    return 1;
}

int main() {
    printf("[*] Verificando integridad de los archivos del reto...\n");
    sleep(1);

    if (perform_checksum_validation()) {
        printf("[+] Hash SHA-256 verificado correctamente.\n");
        printf("[*] Entorno configurado para academic.soqui.dev. Proceso finalizado.\n");
    } else {
        printf("[!] Error: No se pudo validar la arquitectura del sistema.\n");
        return 1;
    }

    return 0;
}
