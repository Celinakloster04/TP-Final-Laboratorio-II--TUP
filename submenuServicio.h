#ifndef SUBMENUSERVICIO_H_INCLUDED
#define SUBMENUSERVICIO_H_INCLUDED

ArchivoServicio archiServicio("Servicios.dat");
ArchivoDescripcionServicio archidescripcion("DescripcionServicio.dat");

int submenuServicios(){
    int opc;
    while(true){

        gotoxy(50,1);cout<<"SUBMENU SERVICIOS"<<endl;
        gotoxy(43,2);cout<<"******************************************"<<endl;
        gotoxy(45,3);cout<<"1) AGREGAR SERVICIO A MASCOTA"<<endl;
        gotoxy(45,4);cout<<"2) FILTRAR HISTORIA CLINICA "<<endl;
        gotoxy(45,5);cout<<"4) LISTAR TODOS LOS SERVICIOS EN BD"<<endl;
        gotoxy(45,6);cout<<"5) ACTUALIZAR PRECIO DE SERVICIOS EN BD"<<endl;
        gotoxy(45,7);cout<<"0) VOLVER"<<endl;
        gotoxy(43,8);cout<<"******************************************"<<endl;
        gotoxy(50,9);cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:gotoxy(50,1);cout<<"» ALTA DE SERVICIO CON NUMERO DE HC «"<<endl;
            archiServicio.altaServicio();
            break;
        case 2:gotoxy(50,1);cout<<"» LISTA DE SERVICIO CON NUMERO DE HC «"<<endl;
            archiServicio.listarServicioPorNumeroHC();
            break;
        case 3:gotoxy(50,1);cout<<"» ALTA DESCRIPCION DE SERVICIO «"<<endl;
            archidescripcion.altaDescripcionServicio();
            break;
        case 4:gotoxy(50,1);cout<<"» LISTA DE TODOS LOS SERVICIOS «"<<endl;
            archidescripcion.listardescripcion();
            break;
        case 5:gotoxy(50,1);cout<<"» MODIFICAR EL PRECIO DE UN SERVICIO «"<<endl;
            archidescripcion.modificarPrecioServicio();
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

    void AgregarMASServicios(Fecha fechaServicio, int numeroHC, int numeroEmpleado, const char* observacion){
        ArchivoServicio archiServicio("Servicios.dat");
        Servicio obj;
        int opc;
        cout<<"INDIQUE CUANTOS SERVICIOS DESEA AGREGAR:";
        cin>>opc;
        if(opc>0 && opc <=15){
            for(int i=0; i<opc; i++){
                obj.CargarServicioSinHcDia();
                obj.setFechaServicio(fechaServicio);
                obj.setNumeroEmpleado(numeroEmpleado);
                obj.setNumeroHC(numeroHC);
                obj.setObservacion(observacion);

                archiServicio.grabarRegistro(obj);
            }
            cout<<"SE GRABO EL REGISTRO CORRECTAMENTE"<<endl;
        }else if(opc<0 || opc>15){
            cout<<"NUMERO INCORRECTO"<<endl;
        }return;
    }

#endif // SUBMENUSERVICIO_H_INCLUDED
