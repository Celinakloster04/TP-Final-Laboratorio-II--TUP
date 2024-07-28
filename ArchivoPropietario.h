#ifndef ARCHIVOPROPIETARIO_H_INCLUDED
#define ARCHIVOPROPIETARIO_H_INCLUDED

class ArchivoPropietario{
private:
    char nombre[30];
public:
    ArchivoPropietario(const char *n){
      strcpy(this->nombre, n);
    }

     void altaPropietario(){
        Propietario obj;
        obj.CargarPropietario();
        int pos=buscarRegistro(obj.getDNI());

        if(pos == obj.getDNI()){
            cout<<"YA EXISTE EL DNI EN EL ARCHIVO "<<endl;
            obj.setEstado(false);
        }else if(obj.getEstado()==true){
            grabarRegistro(obj);
            obj.agregarMascota(obj.getDNI());
            cout<<"SE GRABO EL ARCHIVO CORRECTAMENTE :-)";
        } else {
            cout<<"NO SE PUDO GRABAR EL REGISTRO "<<endl;
            obj.setEstado(false);
            return;
        }
    }

    void grabarRegistro(Propietario obj){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){

            return;
        }
        fwrite(&obj, sizeof (Propietario), 1, p);
        fclose(p);
    }

    int buscarRegistro(int num){
        Propietario obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getDNI()==num){
                return obj.getDNI();
            }
        }
        return -1;
    }

      int buscarRegistroRetotnaI(int num){
        Propietario obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getDNI()==num){
                return i;
            }
        }
        return -1;
    }

    bool agregarMascotaApropietario(){
        ArchivoPropietario archiPropietario("Propietarios.dat");
        ArchivoMascota archiMascota("Mascotas.dat");

        int dniPropietario;
        cout <<"INGRESE EL DNI DEL PROPIETARIO: ";
        cin>>dniPropietario;
        system("cls");
        int posicionPropietario = archiPropietario.buscarRegistro(dniPropietario);

        if(posicionPropietario<0){
            cout<<"NO EXISTEN REGISTROS DEL DNI INGRESADO"<<endl;
            return false;
        }else{
            archiMascota.altaMascotaConChequeoDni(dniPropietario);
            return true;
        }
    }

    Propietario leerRegistro(int pos){
        Propietario obj;

        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){

            obj.setDNI(-2);
            return obj;
        }
        fseek(p, pos * sizeof(Propietario), 0);
        fread(&obj, sizeof (Propietario), 1, p);
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
        registro= cantBytes/sizeof(Propietario);

        return registro;
    }

    void modificarRegistro(Propietario obj, int pos){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return;
        }
        fseek(p, pos * sizeof (Propietario) , 0);
        fwrite(&obj, sizeof (Propietario), 1, p);
        fclose(p);
    }

    void listarPropietario(){
        Propietario obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj =leerRegistro(i);
               obj.MostrarPropietario();
                         if(obj.getEstado()==true)
            cout<<endl;
                }

        }


    void modificarRegistroTelefono(){
        int num;
        cout<<"INGRESE EL NUMERO DE DNI DEL PROPIETARIO QUE DESEA MODIFICAR: ";
        cin>>num;
        int pos=buscarRegistroRetotnaI(num);
        if(pos<0){
            cout<<"EL NUMERO DE DNI INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
            return;
        }
        Propietario obj;
        obj = leerRegistro(pos);
        int nuevo;
        cout<<"INGRESE EL NUEVO NUMERO DE TELEFONO : ";
        cin>>nuevo;
        obj.setTelefono(nuevo);
        modificarRegistro(obj, pos);
        cout<<"EL NUEVO NUMERO DE TELEFONO A SIDO MODIFICADO CORRECTAMENTE! "<<endl;
    }

    bool RealizarCopiaSeguridad(const char *nombreAr="propietario.bkp"){
        FILE *pBackup;
        Propietario obj;

        pBackup = fopen(nombreAr,"wb");
        if(pBackup == NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        int cantReg = contarRegistros();
        for(int i=0;i<cantReg;i++){
            obj=leerRegistro(i);
            fwrite(&obj, sizeof (Propietario), 1, pBackup);
        }
        fclose(pBackup);

        return true;
    }

    bool restaurarArchivoConBackup(){
        FILE *p;
        Propietario obj;
        ArchivoPropietario archiBackup("propietario.bkp");

        int cantReg = archiBackup.contarRegistros();

        p = fopen(nombre,"wb");
        if(p== NULL){
            return false;
        }

        for(int i=0;i<cantReg;i++){
            obj=archiBackup.leerRegistro(i);
            fwrite(&obj, sizeof (Propietario), 1, p);
        }
        fclose(p);
        return true;
    }

};

bool Noserepite(int num){
    ArchivoPropietario archiPropietario("Propietarios.dat");
    Propietario obj;
    int cant=archiPropietario.contarRegistros();
    for(int i=0; i<cant; i++){
        obj =archiPropietario.leerRegistro(i);
        if(obj.getDNI()==num){
            return false;
        }
    }
    return true;
}

#endif // ARCHIVOPROPIETARIO_H_INCLUDED
