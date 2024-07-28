#ifndef SUBMENUMODIFICAR_H_INCLUDED
#define SUBMENUMODIFICAR_H_INCLUDED
int menuModificar(){
    ArchivoMascota archiMascota("Mascotas.dat");
    ArchivoPropietario archiPropietario("Propietarios.dat");
    int opc;
    while(true){
        gotoxy(50,1);cout<<"SUBMENU MODIFICAR"<<endl;
        gotoxy(43,2);cout<<"*********************************************"<<endl;
        gotoxy(50,3);cout<<"1) MODIFICAR TELEFONO PROPIETARIO"<<endl;
        gotoxy(50,4);cout<<"2) MODIFICAR ESTADO MASCOTA"<<endl;
        gotoxy(50,5);cout<<"0) VOLVER"<<endl;
        gotoxy(43,6);cout<<"*********************************************"<<endl;
        gotoxy(50,7);cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:gotoxy(50,1);cout<<"» MODIFICAR EL TELEFONO DEL PROPIETARIO «"<<endl;
            archiPropietario.modificarRegistroTelefono();
            break;

        case 2:gotoxy(46,1);cout<<"» MODIFICAR EL ESTADO DE LA MASCOTA(BAJA LOGICA) «"<<endl;
            archiMascota.bajaMascota();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<<"OPCION INCORRECTA "<<endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}


#endif // SUBMENUMODIFICAR_H_INCLUDED
