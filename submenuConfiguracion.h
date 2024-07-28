#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

ArchivoPropietario archiprop ("Propietarios.dat");
ArchivoMascota archimasc ("Mascotas.dat");
ArchivoServicio archiserv ("Servicios.dat");
ArchivoFacturacion archifac ("Facturacion.dat");
ArchivoDescripcionServicio archidesc("DescripcionServicio.dat");

int submenuConfiguracion(){
    int opc;
    while(true){
        gotoxy(50,1);cout<<"SUBMENU CONFIGURACION"<<endl;
        gotoxy(43,2);cout<<"************************************************************"<<endl;
        gotoxy(43,3);cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO PROPIETARIOS"<<endl;
        gotoxy(43,4);cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO MASCOTAS"<<endl;
        gotoxy(43,5);cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO SERVICIOS"<<endl;
        gotoxy(43,6);cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO FACTURACION"<<endl;
        gotoxy(43,7);cout<<"5) COPIA DE SEGURIDAD DEL ARCHIVO DESCRIPCION DE SERVICIOS"<<endl;
        gotoxy(43,8);cout<<"6) RESTAURAR EL ARCHIVO DE PROPIETARIOS"<<endl;
        gotoxy(43,9);cout<<"7) RESTAURAR EL ARCHIVO DE MASCOTAS"<<endl;
        gotoxy(43,10);cout<<"8) RESTAURAR EL ARCHIVO DE SERVICIOS"<<endl;
        gotoxy(43,11);cout<<"9) RESTAURAR EL ARCHIVO DE FACTURACION"<<endl;
        gotoxy(43,12);cout<<"10) RESTAURAR EL ARCHIVO DE DESCRIPCION DE SERVICIOS"<<endl;
        gotoxy(43,13);cout<<"0) VOLVER"<<endl;
        gotoxy(43,14);cout<<"************************************************************"<<endl;
        gotoxy(50,15);cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            if(archiprop.RealizarCopiaSeguridad()){
                        cout<<"BACKUP REALIZADO"<<endl;
                    };
            break;
        case 2:if(archimasc.RealizarCopiaSeguridad()){
                        cout<<"BACKUP REALIZADO"<<endl;
                    };
            break;
        case 3:if(archiserv.RealizarCopiaSeguridad()){
                        cout<<"BACKUP REALIZADO"<<endl;
                    }
            break;
        case 4:if(archifac.RealizarCopiaSeguridad()){
                        cout<<"BACKUP REALIZADO"<<endl;
                    }
            break;
        case 5:if(archidesc.RealizarCopiaSeguridad()){
                        cout<<"BACKUP REALIZADO"<<endl;
                    }
            break;
        case 6:
            if(archiprop.restaurarArchivoConBackup()){
                        cout<<"ARCHIVO RESTAURADO"<<endl;
                    }
            break;
        case 7:
            if(archimasc.restaurarArchivoConBackup()){
                        cout<<"ARCHIVO RESTAURADO"<<endl;
                    }
            break;
        case 8:
            if(archiserv.restaurarArchivoConBackup()){
                        cout<<"ARCHIVO RESTAURADO"<<endl;
                    }
            break;
        case 9:
            if(archifac.restaurarArchivoConBackup()){
                        cout<<"ARCHIVO RESTAURADO"<<endl;
                    }
            break;
        case 10:
            if(archidesc.restaurarArchivoConBackup()){
                        cout<<"ARCHIVO RESTAURADO"<<endl;
                    }
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

#endif // SUBMENUCONFIGURACION_H_INCLUDED
