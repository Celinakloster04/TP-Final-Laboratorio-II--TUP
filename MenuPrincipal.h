#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED
int submenuPropietarios();
int submenuServicios();
int submenuEmpleado();
int submenuFacturacion();
int submenuConfiguracion();


int menuPrincipal()
{
    int opc;
    while(true)
    {

        gotoxy(4,7);
        cout<< "(\\___/)" <<"       "<<  " (\\___/)"<<"      "<<"MENU PRINCIPAL"<<"    "<< " (\\___/)" <<"         "<< " (\\___/)" <<endl;
        gotoxy(3,8);
        cout<<" (='.'=)" <<"       "<< " (='.'=)"<<"    "<< "*******************"<<" "<< " (='.'=)" <<"         "<< " (='.'=)" <<endl;
        gotoxy(3,9);
        cout<< " (\")_(\")" <<"       "<< " (\")_(\")" <<"     "<<"1) PROPIETARIOS"<<"    "<< " (\")_(\")" <<"         "<< " (\")_(\")" <<endl;
        gotoxy(31,10);
        cout<<"2) SERVICIOS"<<endl;
        gotoxy(8,11);
        cout<<"   (\\___/)" <<"             "<<"3) EMPLEADOS"<<"                "<< " (\\___/)" <<endl;
        gotoxy(8,12);
        cout<< "   (='.'=)" <<"             "<<"4) FACTURACION"<<"              "<< " (='.'=)" <<endl;
        gotoxy(8,13) ;
        cout<< "   (\")_(\")" <<"             "<<"5) CONFIGURACION"<<"            "<< " (\")_(\")" <<endl;
        gotoxy(31,14);
        cout<<"0) SALIR"<<endl;
        gotoxy(31,15);
        cout<< "*******************"<<endl;
        gotoxy(31,16) ;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            submenuPropietarios();
            break;
        case 2:
            submenuServicios();
            break;
        case 3:
            submenuEmpleado();
            break;
        case 4:
            submenuFacturacion();
            break;
        case 5:
            submenuConfiguracion();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<<"OPCION INCORRECTA "<<endl;
            break;
        }
        system("cls");
    }
    return 0;
}

#endif // MENUPRINCIPAL_H_INCLUDED
