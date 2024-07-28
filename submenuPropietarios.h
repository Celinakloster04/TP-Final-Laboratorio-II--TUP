#ifndef SUBMENUPROPIETARIOS_H_INCLUDED
#define SUBMENUPROPIETARIOS_H_INCLUDED
int menuModidicar();

ArchivoPropietario archiPropietario("Propietarios.dat");
ArchivoMascota archiMascota("Mascotas.dat");

int submenuPropietarios(){
    int opc;
    while(true){
        gotoxy(50,1);cout<<"SUBMENU PROPIETARIOS"<<endl;
        gotoxy(43,2);cout<<"*******************************************"<<endl;
        gotoxy(46,3);cout<<"1) ALTA NUEVO PROPIETARIO"<<endl;
        gotoxy(46,4);cout<<"2) AGREGAR MASCOTAS A PROPIETARIO"<<endl;
        gotoxy(46,5);cout<<"3) BUSCAR MASCOTAS POR DNI PROPIETARIO"<<endl;
        gotoxy(46,6);cout<<"4) MODIFICAR INFORMACION DEL PROPIETARIO"<<endl;
        gotoxy(46,7);cout<<"5) LISTAR PROPIETARIOS"<<endl;
        gotoxy(46,8);cout<<"0) VOLVER"<<endl;
        gotoxy(43,9);cout<<"*******************************************"<<endl;
        gotoxy(50,10);cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:gotoxy(50,1);cout<<"» ALTA DE PROPIETARIO «"<<endl;
            archiPropietario.altaPropietario();
            break;
        case 2:gotoxy(50,1);cout<<"» AGREGAR MASCOTA A PROPIETARIO «"<<endl;
            archiPropietario.agregarMascotaApropietario();
            break;
        case 3:gotoxy(50,1);cout<<"» BUSCAR MASCOTA POR DNI DE PROPIETARIO «"<<endl;
            archiMascota.buscaMascotaXdni();
            break;
        case 4:
            menuModificar();
            break;
        case 5:gotoxy(50,1);cout<<"» LISTA DE TODOS LOS PROPIETARIOS «"<<endl;
            archiPropietario.listarPropietario();

            break;
        case 0:
            return 0;
            break;
        default:
            cout<<"OPCION INCORRECTA "<<endl;
            break;
        }
        system ("pause");
        system("cls");
    }
    return 0;
}


#endif // SUBMENUPROPIETARIOS_H_INCLUDED
