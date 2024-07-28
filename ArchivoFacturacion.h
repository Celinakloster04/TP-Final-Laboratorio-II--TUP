#ifndef ARCHIVOFACTURACION_H_INCLUDED
#define ARCHIVOFACTURACION_H_INCLUDED

int obtenerUltimoNumeroFacturacion();


class ArchivoFacturacion{
private:
    char nombre[30];
public:
    ArchivoFacturacion(const char *_nombre){
    strcpy(nombre,_nombre);
    }

    bool crearFactura(){
        ArchivoServicio archiServicio("Servicios.dat");
        ArchivoDescripcionServicio archiDesc("DescripcionServicio.dat");
        ArchivoPropietario archiProp("Propietarios.dat");
        ArchivoMascota archiMasc("Mascotas.dat");
        ArchivoFacturacion archiFact("Facturacion.dat");
        int cantServ=archiServicio.contarRegistros();
        int cantDesc=archiDesc.contarRegistros();
        int cantProp=archiProp.contarRegistros();
        int cantMasc=archiMasc.contarRegistros();
        Servicio objServ;
        DescripcionServicio objDescServ;
        Mascota objMasc;
        Propietario objProp;
        Facturacion objFact;

        Fecha f;
        float total=0;
        int HC, numEmpleado, existe, contador=0;
        cout<<"NUMERO DE HISTORIA CLINICA: ";
        cin>>HC;
        existe=buscarServicio(HC);
        if(existe==-1 ){
            cout<<"NUMERO DE HC INVALIDO"<<endl;
            return false;
        }
        cout<<"FECHA: ";
        f.Cargar();

        if(cantServ==0){
            cout<<"ARCHIVO VACIO"<<endl;
            return false;
        }

        for(int i=0;i<cantServ;i++){
            objServ=archiServicio.leerRegistro(i);

            for(int x=0;x<cantDesc;x++){
                objDescServ =archiDesc.leerRegistro(x);
                if(objServ.getEstado()==true && objDescServ.getEstado()==true &&objServ.getFechaServicio()==f && objServ.getNumeroHC()==HC&& objServ.getidServicio()==objDescServ.getidservicio()){
                    contador++;
                    total+=objDescServ.getprecio();
                    numEmpleado=objServ.getNumeroEmpelado();
                    objFact.setEstado(objServ.getEstado());
                }
            }
        }

        for(int z=0;z<cantProp;z++){
            objProp=archiProp.leerRegistro(z);
            for(int y=0;y<cantMasc;y++){
                objMasc=archiMasc.leerRegistro(y);
                if(objMasc.getNumeroHC()==HC && objMasc.getDNI()==objProp.getDNI() && objMasc.getEstado()==true && objProp.getEstado()==true){
                    int ultimoNumero=obtenerUltimoNumeroFacturacion();
                    objFact.setNumeroHC(HC);
                    objFact.setNumeroDeFactura(ultimoNumero + 1);
                    objFact.setNumeroDni(objProp.getDNI());
                    objFact.setNombreFacturacion(objProp.getNombrePropietario());
                    objFact.setApellidoFacturacion(objProp.getApellido());
                    objFact.setFechaActual(f);
                    objFact.setTotal(total);
                    objFact.setEmpleado(numEmpleado);
                    objFact.setCantServicios(contador);
                    if(objFact.getEstado()==true){
                       archiFact.grabarRegistro(objFact);
                       cout<<"SE GRABO "<<endl;
                       return true;
                    }

                }
            }
        }

        if(objFact.getEstado()==false){
            cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
            return false;
        }
        return true;
    }

    int buscarServicio(int num){
        ArchivoServicio archiServicio("Servicios.dat");
        Servicio obj;
        int cant=archiServicio.contarRegistros();
        for(int i=0; i<cant; i++){
            obj = archiServicio.leerRegistro(i);
            if(obj.getNumeroHC()==num){
                return i;
            }
        }
        return -1;
    }

    int obtenerUltimoNumeroFacturacion() {
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            return 0;
        }
        fseek(p, -static_cast<long>(sizeof(Facturacion)), SEEK_END);
        Facturacion ultimaFactura;
        fread(&ultimaFactura, sizeof(Facturacion), 1, p);
        fclose(p);
        return ultimaFactura.getNumeroDeFactura();
    }

    void grabarRegistro(Facturacion obj){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            return;
        }
        fwrite(&obj, sizeof (Facturacion), 1, p);
        fclose(p);
    }

    int buscarRegistro(int num){
        Facturacion obj;
        int cant=contarRegistros();
        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getNumeroDeFactura()==num){
                return i;
            }
        }
        return -1;
    }

    Facturacion leerRegistro(int pos){
        Facturacion obj;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            obj.setNumeroDeFactura(-2);
            return obj;
        }
        fseek(p, pos * sizeof(Facturacion), 0);
        fread(&obj, sizeof (Facturacion), 1, p);
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
        registro= cantBytes/sizeof(Facturacion);

        return registro;
    }

    void listarFacturas(){
        Facturacion obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj =leerRegistro(i);
            obj.MostrarFactura();
        if(obj.getEstado()==true)cout<<endl;
        }
    }

    void listarPorNumeroFactura(){
        Facturacion obj;
        int num;
            cout<<"INGRESE EN NUMERO DE FACTURA DE DESEE MOSTRAR: "<<endl;
            cin>>num;
            int pos= buscarRegistro(num);

        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA CON NINGUN ARCHIVO"<<endl;
            return;
        }else {
            system("cls");
            obj=leerRegistro(pos);
            obj.MostrarFactura();
        }
    }

    bool RealizarCopiaSeguridad(const char *nombreAr="facturacion.bkp"){
        FILE *pBackup;
        Facturacion obj;

        pBackup = fopen(nombreAr,"wb");
        if( pBackup == NULL){    cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        int cantReg = contarRegistros();
        for(int i=0;i<cantReg;i++){
              obj=leerRegistro(i);
                fwrite(&obj, sizeof (Facturacion), 1, pBackup);
        }
        fclose(pBackup);

        return true;

    }

    bool restaurarArchivoConBackup(){
        FILE *p;
        Facturacion obj;
        ArchivoFacturacion archiBackup("facturacion.bkp");

        int cantReg = archiBackup.contarRegistros();

        p = fopen(nombre,"wb");
        if(p== NULL){
            return false;
        }

        for(int i=0;i<cantReg;i++){
                obj=archiBackup.leerRegistro(i);
                fwrite(&obj, sizeof (Facturacion), 1, p);
        }
        fclose(p);
        return true;
    }

};




#endif // ARCHIVOFACTURACION_H_INCLUDED
