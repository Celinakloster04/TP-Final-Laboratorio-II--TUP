#ifndef ARCHIVODETALLEFACTURACION_H_INCLUDED
#define ARCHIVODETALLEFACTURACION_H_INCLUDED

class ArchivoDetalleFacturacion{
private:
    char nombre[30];
public:
    ArchivoDetalleFacturacion(const char *_nombre){
        strcpy(nombre,_nombre);
    }

    bool crearDetalleFactura(){
        ArchivoFacturacion archiFact("Facturacion.dat");
        ArchivoDetalleFacturacion archiDet("DetalleFacturacion.dat");
        ArchivoDescripcionServicio archiDesc("DescripcionServicio.dat");
        ArchivoServicio archiServicio("Servicios.dat");
        Servicio objServ;
        DescripcionServicio objDescS;
        Facturacion objFact;
        DetalleFacturacion objDet;
        int num, cantFact, cantDetS, existe, cantServ;
        cantFact=archiFact.contarRegistros();
        cantDetS=archiDesc.contarRegistros();
        cantServ=archiServicio.contarRegistros();
        cout<<"NUMERO DE FACTURA: ";
        cin>>num;
        existe=buscarRegistroEnFacturacion(num);
        if(existe==-1){
            cout<<"NO SE ENCONTRO LA FACTURA EL ARCHIVO"<<endl;
            return false;
        }
        if(buscarRegistroExistente(num)==num){
            cout<<"YA EXISTE EL ARCHIVO "<<endl;
            return false;
        }
        if(cantFact==0){
            cout<<"ARCHIVO VACIO"<<endl;
            return false;
        }
        for(int i=0; i<cantFact; i++){
            objFact=archiFact.leerRegistro(i);

            if(num==objFact.getNumeroDeFactura() && objFact.getEstado()==true){
                objDet.setNumeroDeDetalleFactura(objFact.getNumeroDeFactura());
                objDet.setFechaActualD(objFact.getFechaActual());
                objDet.setNombreDetalle(objFact.getNombreFacturacion());
                objDet.setApellidoDetalle(objFact.getApellidoFacturacion());
                objDet.setDNID(objFact.getNumeroDNI());
                objDet.setCantS(objFact.getCantServicios());

                objDet.setTotal(objFact.getTotal());
                objDet.setEstado(true);
            }
            for(int y=0;y<cantServ;y++){
            objServ=archiServicio.leerRegistro(y);
            for(int x=0;x<cantDetS;x++){
                objDescS=archiDesc.leerRegistro(x);
                if(objServ.getEstado()==true && objDescS.getEstado()==true && objFact.getNumeroHC()==objServ.getNumeroHC() && objServ.getidServicio()==objDescS.getidservicio()){
                    objDet.setPrecioServicio(objDescS.getprecio());
                    objDet.setNombreServicio(objDescS.getdescripcion());
                    objDet.setCantidad(1);
                    objDet.setIDServicio(objDescS.getidservicio());
                    archiDet.grabarRegistro(objDet);
                    }
                }
            }
        }
        if(objDet.getEstado()==true){
            cout<<"EL DETALLE DE FACTURACION SE GRABO CORRECTAMENTE :-)"<<endl;
            return true;
        }else{
            cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
            return false;
        }
    }

    int obtenerUltimoNumeroFacturacion() {
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            return 0;
        }
        fseek(p, -static_cast<long>(sizeof(DetalleFacturacion)), SEEK_END);
        DetalleFacturacion ultimaFactura;
        fread(&ultimaFactura, sizeof(DetalleFacturacion), 1, p);
        fclose(p);
        return ultimaFactura.getNumeroDeDetalleFactura();
    }

    void grabarRegistro(DetalleFacturacion obj){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            return;
        }
        fwrite(&obj, sizeof (DetalleFacturacion), 1, p);
        fclose(p);
    }

    int buscarRegistro(int num){
        DetalleFacturacion obj;
        int cant=contarRegistros();
        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getNumeroDeDetalleFactura()==num){
                return i;
            }
        }
        return -1;
    }

    int buscarRegistroExistente(int num){
        DetalleFacturacion obj;
        int cant=contarRegistros();
        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getNumeroDeDetalleFactura()==num){
                return i+1;
            }
        }
        return -1;
    }

    int buscarRegistroEnFacturacion(int num){
        ArchivoFacturacion archiFact("Facturacion.dat");
        Facturacion obj;
        int cant=archiFact.contarRegistros();
        for(int i=0; i<cant; i++){
            obj=archiFact.leerRegistro(i);
            if(obj.getNumeroDeFactura()==num){
                return i;
            }
        }
        return -1;
    }

    DetalleFacturacion leerRegistro(int pos){
        DetalleFacturacion obj;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
                cout<<"ERROR DE ARCHIVO "<<endl;
            obj.setNumeroDeDetalleFactura(-2);
            return obj;
        }
        fseek(p, pos * sizeof(DetalleFacturacion), 0);
        fread(&obj, sizeof (DetalleFacturacion), 1, p);
        fclose(p);
        return obj;
    }

    int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            return -1;
        }
        fseek(p, 0, 2);
        int cantBytes = ftell(p);
        fclose(p);
        int registro;
        registro= cantBytes/sizeof(DetalleFacturacion);

        return registro;
    }

    void modificarRegistro(DetalleFacturacion obj, int pos){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return;
        }
        fseek(p, pos * sizeof (DetalleFacturacion) , 0);
        fwrite(&obj, sizeof (DetalleFacturacion), 1, p);
        fclose(p);
    }

    void bajaFactura(){
        DetalleFacturacion obj;
        int fact;
        cout<<" INGRESE EL NUMERO DE FACTURA A DAR DE BAJA: "<<endl;
        cin>>fact;
        int pos= buscarRegistro(fact);
        if(pos<0){
            cout<<" NO HUBO COINCIDENCIA CON NINGUNA FACTURA EN EL ARCHIVO"<<endl;
            return;
        }

        obj=leerRegistro(pos);
        obj.setEstado(false);
        modificarRegistro(obj, pos);
        cout<<"LA FACTURA SE HA ELIMINADO CORRECTAMENTE: "<<endl;
        system("pause");
    }

    void listarDetalleFacturaServicios(int f){
        ArchivoDetalleFacturacion archiDetalleFact("DetalleFacturacion.dat");
        DetalleFacturacion *detF, obj;
        int tam = archiDetalleFact.contarRegistros();
        detF=new DetalleFacturacion[tam];
        if(detF==NULL){
            cout<<"ERROR AL PEDIR MEMORIA ";
            return;
        }

        for(int i=0;i<tam;i++){
            detF[i]=leerRegistro(i);

        }
        for(int i=0;i<tam;i++){
            if(obj.getNumeroDeDetalleFactura()==f){
                detF[i].mostrarServiciosDF();
                //if(obj.getEstado()==true)cout<<endl;
            }
        }
        delete[]detF;
    }

    void listarPorNumeroDetalleFactura(){
        DetalleFacturacion obj;
        int num;
            cout<<"INGRESE EN NUMERO DE DETALLE DE FACTURACION QUE DESEE MOSTRAR: "<<endl;
            cin>>num;
            system("cls");
            int pos= buscarRegistro(num);
        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA CON NINGUN ARCHIVO"<<endl;
            return;
        }else {
            obj=leerRegistro(pos);
            obj.MostrarDetalleFactura();
            listarDetalleFacturaServicios(pos);
            obj.mostrarTotal();
        }
    }
};



#endif // ARCHIVODETALLEFACTURACION_H_INCLUDED
