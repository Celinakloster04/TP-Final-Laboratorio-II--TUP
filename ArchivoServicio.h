#ifndef ARCHIVOSERVICIO_H_INCLUDED
#define ARCHIVOSERVICIO_H_INCLUDED

class ArchivoServicio{
private:
    char nombre[30];
public:
    ArchivoServicio(const char *_nombre){
    strcpy(nombre,_nombre);
    }

    void altaServicio(){
        Servicio obj;
        obj.CargarServicio();
        int pos=buscarRegistro(obj.getNumeroHC());

        if(pos != -1&&obj.getEstado()==true){
            grabarRegistro(obj);
            cout<<"SE GRABO EL REGISTRO CORRECTAMENTE :-)"<<endl;
        }else{
            cout<<"NO SE GRABO EL REGISTRO"<<endl;
        }
    }

    void grabarRegistro(Servicio obj){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            return;
        }
        fwrite(&obj, sizeof (Servicio), 1, p);

        fclose(p);
    }

    int buscarRegistro(int num){
        Servicio obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getNumeroHC()==num){
                return i;
            }
        }
        return -1;
    }

    int buscarRegistroPorHC(int num){
        Servicio obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getNumeroHC()==num){
                return i;
            }
        }
        return -1;
    }

    Servicio leerRegistro(int pos){
        Servicio obj;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            obj.setidServicio(-2);
            return obj;
        }
        fseek(p, pos * sizeof(Servicio), 0);
        fread(&obj, sizeof (Servicio), 1, p);
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
        registro= cantBytes/sizeof(Servicio);

        return registro;
    }

    void modificarRegistro(Servicio obj, int pos){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return;
        }
        fseek(p, pos * sizeof (Servicio) , 0);
        fwrite(&obj, sizeof (Servicio), 1, p);
        fclose(p);
    }


    void bajaServicio(){
        Servicio obj;

        int idServicio;
        cout<<"INGRESE EL ID DE SERVICIO A DARLE DE BAJA: "<<endl;
        cin>>idServicio;
        int pos= buscarRegistro(idServicio);
        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA CON NINGUN ID DE SERVICIO EN EL ARCHIVO"<<endl;
            return;
        }

        obj=leerRegistro(pos);
        obj.setEstado(false);
        modificarRegistro(obj, pos);
        cout<<"EL ID SE HA ELIMINADO CORRECTAMENTE :-)"<<endl;
        system("pause");
    }

    void listarServicio(){
        Servicio obj;
        int cant=contarRegistros();
        for(int i=0; i<cant; i++){
            obj =leerRegistro(i);
            obj.MostrarServicio();
       if(obj.getEstado()==true)
            cout<<endl;
        }
    }

    void modificarRegistroServicio(){
        int idservicio;
        cout<<"INGRESE EL ID DE SERVICIO QUE DESEA MODIFICAR: ";
        cin>>idservicio;
        int pos=buscarRegistro(idservicio);
        if(pos<0){
            cout<<"EL ID INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
            return;
        }
        Servicio obj;
        obj = leerRegistro(pos);
        int nuevoIdServicio;
        cout<<"INGRESE EL NUEVO ID DE SERVICIO: ";
        cin>>nuevoIdServicio;
        obj.setidServicio(nuevoIdServicio);
        modificarRegistro(obj, pos);
        cout<<"EL NUEVO ID DE SERVICIO FUE INGRESADO CORRECTAMENTE :-)"<<endl;
    }

    void listarServicioPorNumeroId(){
        Servicio obj;
        int num;
        cout<<"INGRESE EL ID DEL SERVICIO QUE DESEA MOSTRAR: ";
        cin>>num;

        int pos= buscarRegistro(num);
        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA EN EL ARCHIVO"<<endl;
            return;
        }else {
            obj=leerRegistro(pos);
            cout<<"HUBO COINCIDENCIA: "<<endl;
            obj.MostrarServicio();
        }
    }

    void listarServicioPorNumeroHC(){
        ArchivoServicio archiServicio("Servicios.dat");
        Servicio objServicio;
        ArchivoDescripcionServicio archiDescr("DescripcionServicio.dat");
        DescripcionServicio objDesc;

        int numHc;
        cout<<"INGRESE EL NUMERO DE HISTORIA CLINICA DEL PACIENTE: ";
        cin>>numHc;

        int pos= archiServicio.buscarRegistroPorHC(numHc);
        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA EN EL ARCHIVO"<<endl;
            return;
        }

        int contReg= archiDescr.contarRegistros();
        int cantReg=archiServicio.contarRegistros();

        for(int i=0; i<cantReg; i++){
            objServicio=archiServicio.leerRegistro(i);
            for(int x=0; x<contReg; x++){
                objDesc=archiDescr.leerRegistro(x);
                if(objDesc.getEstado()&&objServicio.getEstado()&&objDesc.getidservicio()==objServicio.getidServicio()&&objServicio.getNumeroHC()==numHc){
                    cout<<"FECHA: ";
                    objServicio.getFechaServicio().Mostrar();
                    cout<<"EMPLEADO: "<<objServicio.getNumeroEmpelado()<<endl;
                    cout<<"DESCRIPCION: "<<objServicio.getObservacion()<<endl;
                    cout<<"ID: "<<objDesc.getidservicio()<<'\t'<<"SERVICIO: "<<objDesc.getdescripcion()<<endl;
                    cout<<endl;
                }
            }
        }
    }



    bool RealizarCopiaSeguridad(const char *nombreAr="servicio.bkp"){
        FILE *pBackup;
        Servicio obj;

        pBackup = fopen(nombreAr,"wb");
        if( pBackup == NULL){    cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        int cantReg = contarRegistros();
        for(int i=0;i<cantReg;i++){
              obj=leerRegistro(i);
                fwrite(&obj, sizeof (Servicio), 1, pBackup);
        }
        fclose(pBackup);

        return true;
    }
bool restaurarArchivoConBackup(){
    FILE *p;
    Servicio obj;
    ArchivoServicio archiBackup("servicio.bkp");

    int cantReg = archiBackup.contarRegistros();

    p = fopen(nombre,"wb");
    if(p== NULL){
        return false;
    }

    for(int i=0;i<cantReg;i++){
        obj=archiBackup.leerRegistro(i);
        fwrite(&obj, sizeof (Servicio), 1, p);
    }
    fclose(p);
    return true;
}

};



#endif // ARCHIVOSERVICIO_H_INCLUDED
