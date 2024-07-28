#include <iostream>
#include <cstring>
#include <ctime>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <locale.h>

#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;
#include "ClaseFecha.h"
#include "Funciones.h"

#include "MenuPrincipal.h"

#include "ClaseMascota.h"
#include "ArchivoMascota.h"

#include "ClasePropietario.h"
#include "ArchivoPropietario.h"

#include "ClaseEmpleado.h"
#include "ArchivoEmpleado.h"

#include "ClaseDescripcionServicio.h"
#include "ArchivoDescripcionServicio.h"

#include "ClaseServicio.h"
#include "ArchivoServicio.h"

#include "ClaseFacturacion.h"
#include "ArchivoFacturacion.h"

#include "ClaseDetalleFacturacion.h"
#include "ArchivoDetalleFacturacion.h"

#include "submenuModificar.h"
#include "submenuPropietarios.h"

#include "submenuEmpleados.h"
#include "submenuServicio.h"

#include "submenuFacturacion.h"
#include "submenuConfiguracion.h"



int main(){

    setlocale(LC_ALL,"spanish");

    system("COLOR 57");

    menuPrincipal();
    cout<<"GRACIAS POR UTILIZAR EL PROGRAMA :-) "<<endl;
    return 0;
}

