#ifndef ARCHIVOMASCOTA_H_INCLUDED
#define ARCHIVOMASCOTA_H_INCLUDED

class ArchivoMascota{
private:
    char nombre[30];
public:

    ArchivoMascota(const char *n){
        strcpy(this->nombre, n);
    }

    bool altaMascotaConChequeoDni(int dniPropietario) {
        Mascota obj;

        bool grabo=obj.CargarMascotaSinDni();

        if(grabo==false){
            cout<<"NO SE PUDO GRABAR LA MASCOTA"<<endl;
            obj.setEstado(false);
            return false;
        }

        obj.setDNI(dniPropietario);
        int ultimoNumero = obtenerUltimoNumeroMascota();
        obj.setNumeroHC(ultimoNumero + 1);
        if(obj.getEstado()==true){
            grabarRegistro(obj);
            cout<<"SE GRABO EL REGISTRO CORRECTAMENTE :-)"<<endl;
            return true;
        }else{
            obj.setEstado(false);
            return false;
        }
    }

    void altaMascota(int dni) {
        Mascota obj;
        if(obj.CargarMascotaSinDni()==true){
            obj.setDNI(dni);
            int ultimoNumero = obtenerUltimoNumeroMascota();
            obj.setNumeroHC(ultimoNumero + 1);
            if(obj.getEstado()==true){
                grabarRegistro(obj);
                return;
            }
        }else{
            cout<<"NO SE PUDO GRABAR EL ARCHIVO"<<endl;
            obj.setEstado(false);
            return;
        }
    }

    void buscaMascotaXdni(){
        int dniPropietario;
        cout <<"INGRESE EL DNI DEL PROPIETARIO: ";
        cin>>dniPropietario;
        system("cls");
        ArchivoMascota archiMascota("Mascotas.dat");
        Mascota *vecMascota;
        int tam = archiMascota.contarRegistros();


        vecMascota=new Mascota[tam];
        if(vecMascota==NULL){
            cout<<"ERROR AL PEDIR MEMORIA ";
            return;
        }

        for (int i=0;i<tam;i++){
            vecMascota[i]= archiMascota.leerRegistro(i);
        }

        bool bandera=false;
        for(int i=0;i<tam;i++){

            if(vecMascota[i].getEstado()&&vecMascota[i].getDNI()==dniPropietario){
                bandera=true;
                cout<<endl;
                vecMascota[i].MostrarMascota();
             }

        }

        if(bandera==false){
            cout<< "NO HUBO COINCIDENCIA"<<endl;
            delete[]vecMascota;
            return;
        }
        delete[]vecMascota;
        buscarOtraVez();
    }

    int buscarRegistro(int num){
        Mascota obj;
        int cant=contarRegistros();
        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getNumeroHC()==num){
                return i;
            }
        }
        return -1;
    }

    bool buscarOtraVez(){
       int opcion=1;
        cout << "DESEA SEGUIR BUSCANDO? 1-SI, 0-FINALIZAR "<<endl;
        cin>> opcion;

       if(opcion==1){
            buscaMascotaXdni();
            return true;
       }else if(opcion==0){
            cout<< "FIN DE LA BUSQUEDA"<<endl;
            return false;
        }else {
            cout<< "OPCION INCORRECTA"<<endl;
            return false;
        }
    }

    int obtenerUltimoNumeroMascota() {
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            return 0;
        }
        fseek(p, -static_cast<long>(sizeof(Mascota)), SEEK_END);
        Mascota ultimo;
        fread(&ultimo, sizeof(Mascota), 1, p);
        fclose(p);
        return ultimo.getNumeroHC();
    }

     void grabarRegistro(Mascota obj){
        FILE *p;
        p=fopen(nombre, "ab");

        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            return;
        }
        fwrite(&obj, sizeof (Mascota), 1, p);
        fclose(p);
    }


    Mascota leerRegistro(int pos){
        Mascota obj;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            obj.setNumeroHC(-2);
            return obj;
        }
        fseek(p, pos * sizeof(Mascota), 0);
        fread(&obj, sizeof (Mascota), 1, p);
        fclose(p);
        return obj;
    }

    int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cerr<<"ERROR DE ARCHIVO"<<endl;
            return -1;
        }
        fseek(p, 0, 2);
        int cantBytes = ftell(p);
        fclose(p);
        int registro;
        registro= cantBytes/sizeof(Mascota);
        return registro;
    }

    void modificarRegistro(Mascota obj, int pos){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return;
        }
        fseek(p, pos * sizeof (Mascota) , 0);
        fwrite(&obj, sizeof (Mascota), 1, p);
        fclose(p);

    }

    void bajaMascota(){
        Mascota obj;
        int numero;
        cout<<"INGRESE EL NUMERO DE HISTORIA CLINICA A DAR DE BAJA: ";
        cin>>numero;
        int pos= buscarRegistro(numero);

        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA EN EL ARCHIVO"<<endl;
            return;
        }
        obj=leerRegistro(pos);
        obj.setEstado(false);
        modificarRegistro(obj, pos);
        cout<<"EL ARCHIVO SE HA ELIMINADO CON EXITO "<<endl;
    }


    void listarPorNumero(){
        Mascota obj;
        int num;
        cout<<"INGRESE EL NUMERO DE HISTORIAL QUE DESEA MOSTRAR: "<<endl;
        cin>>num;

        int pos= buscarRegistro(num);
        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA EN EL ARCHIVO "<<endl;
            return;
        }else {
            obj=leerRegistro(pos);
            obj.MostrarMascota();
        }
    }

    bool RealizarCopiaSeguridad(const char *nombreAr="mascota.bkp"){
        FILE *pBackup;
        Mascota obj;

        pBackup = fopen(nombreAr,"wb");
        if( pBackup == NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        int cantReg = contarRegistros();
        for(int i=0;i<cantReg;i++){
            obj=leerRegistro(i);
            fwrite(&obj, sizeof (Mascota), 1, pBackup);
        }
        fclose(pBackup);

        return true;

    }

    bool restaurarArchivoConBackup(){
        FILE *p;
        Mascota obj;
        ArchivoMascota archiBackup("mascota.bkp");

        int cantReg = archiBackup.contarRegistros();
        p = fopen(nombre,"wb");
        if(p== NULL){
            return false;
        }
        for(int i=0;i<cantReg;i++){
                obj=archiBackup.leerRegistro(i);
                fwrite(&obj, sizeof (Mascota), 1, p);
        }
        fclose(p);
        return true;
    }
};

#endif // ARCHIVOMASCOTA_H_INCLUDED
