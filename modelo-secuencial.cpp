#include <iostream>
#include <thread>
#include <string>

using namespace std;

void escaneoSeguridad(string disco) {

    cout << "[SEGURIDAD] Iniciando escaneo profundo en: " << disco << "..." << endl;

    this_thread::sleep_for(chrono::seconds(5));

    cout << "[SEGURIDAD] Escaneo finalizado. No se encontraron amenazas en " << disco << "." << endl;

}

void verificarIntegridad() {

    cout << "[SISTEMA] Verificando tablas de la base de datos..." << endl;

    for(int i = 1; i <= 3; i++) {

        this_thread::sleep_for(chrono::seconds(1));

        cout << "[SISTEMA] Procesando bloque " << i << "/3..." << endl;

    }

    cout << "[SISTEMA] Integridad verificada correctamente." << endl;

}

int main() {

    cout << "   SISTEMA DE AUDITORIA MULTIPROCESO V1.0" << endl;

    thread hilo1(escaneoSeguridad, "Disco Local C:");

    thread hilo2(verificarIntegridad);



    cout << "AVISO: El sistema esta trabajando en segundo plano..." << endl;


    hilo1.join();

    hilo2.join();

    cout << "AUDITORIA FINALIZADA: El reporte ha sido generado." << endl;

    return 0;

}
