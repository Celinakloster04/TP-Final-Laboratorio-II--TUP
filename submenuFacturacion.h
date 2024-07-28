#ifndef SUBMENUFACTURACION_H_INCLUDED
#define SUBMENUFACTURACION_H_INCLUDED

ArchivoFacturacion archiFacturacion("Facturacion.dat");
ArchivoDetalleFacturacion archiDetalleFact("DetalleFacturacion.dat");
DetalleFacturacion objDetalle;

int submenuFacturacion(){
    int opc;
    while(true){
        gotoxy(50,1);cout<<"SUBMENU FACTURACION"<<endl;
        gotoxy(43,2);cout<<"********************************************"<<endl;
        gotoxy(50,3);cout<<"1) CREAR FACTURA"<<endl;
        gotoxy(50,4);cout<<"2) MOSTRAR FACTURA"<<endl;
        gotoxy(50,5);cout<<"3) LISTAR HISTORIAL FACTURAS"<<endl;
        gotoxy(50,6);cout<<"4) CREAR DETALLE DE FACTURA"<<endl;
        gotoxy(50,7);cout<<"5) MOSTRAR DETALLLE DE FACTURA"<<endl;
        gotoxy(50,8);cout<<"0) VOLVER"<<endl;
        gotoxy(43,9);cout<<"********************************************"<<endl;
        gotoxy(50,10);cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1: gotoxy(50,1);cout<<"» CREANDO FACTURA «"<<endl;
                archiFacturacion.crearFactura();
            break;
        case 2: gotoxy(50,1);cout<<"» LISTAR POR NUMERO DE FACTURA «"<<endl;
                archiFacturacion.listarPorNumeroFactura();
            break;
        case 3: gotoxy(50,1);cout<<"» HISTORIAL DE FACTURAS «"<<endl;
                archiFacturacion.listarFacturas();
            break;
        case 4: gotoxy(50,1);cout<<"» CREANDO DETALLE DE FACTURA «"<<endl;
                archiDetalleFact.crearDetalleFactura();
            break;
        case 5: gotoxy(40,1);cout<<"» LISTA POR NUMERO DE FACTURA EL DETALLE DE FACTURA «"<<endl;
                archiDetalleFact.listarPorNumeroDetalleFactura();
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

#endif // SUBMENUFACTURACION_H_INCLUDED
