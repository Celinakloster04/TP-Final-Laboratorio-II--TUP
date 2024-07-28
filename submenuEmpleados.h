#ifndef SUBMENUEMPLEADOS_H_INCLUDED
#define SUBMENUEMPLEADOS_H_INCLUDE
void ModificarEspecialidad();
ArchivoEmpleado archiEmpleado("Empleados.dat");

int submenuEmpleado(){
    int opc;
    while(true){
        gotoxy(50,1);cout<<"SUBMENU EMPLEADOS"<<endl;
        gotoxy(45,2);cout<<"**********************************"<<endl;
        gotoxy(50,3);cout<<"1) ALTA EMPLEADO"<<endl;
        gotoxy(50,4);cout<<"2) MODIFICAR ESPECIALIDAD"<<endl;
        gotoxy(50,5);cout<<"3) BAJA EMPLEADO"<<endl;
        gotoxy(50,6);cout<<"4) LISTAR TODOS LOS EMPLEADOS"<<endl;
        gotoxy(50,7);cout<<"5) LISTAR POR LEGAJO"<<endl;
        gotoxy(50,8);cout<<"0) VOLVER"<<endl;
        gotoxy(45,9);cout<<"**********************************"<<endl;
        gotoxy(50,10);cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:gotoxy(50,1);cout<<"» ALTA EMPLEADO «"<<endl;
            archiEmpleado.altaEmpleado();
            break;
        case 2:gotoxy(50,1);cout<<"» MODIFICAR ESPECIALIDAD «"<<endl;
            archiEmpleado.ModificarEspecialidad();
            break;
        case 3:gotoxy(50,1);cout<<"» BAJA EMPLEADO «"<<endl;
            archiEmpleado.bajaEmpleado();
            break;
        case 4:gotoxy(50,1);cout<<"» LISTA DE TODOS LOS EMPLEADOS «"<<endl;
            archiEmpleado.listarEmpleado();
            break;
        case 5:gotoxy(50,1);cout<<"» LISTAR POR LEGAJO «"<<endl;
            archiEmpleado.listarPorNumeroEmpleado();
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



#endif // SUBMENUEMPLEADOS_H_INCLUDED
