#ifndef ARCHIVOEMPLEADO_H_INCLUDED
#define ARCHIVOEMPLEADO_H_INCLUDED

class ArchivoEmpleado{
private:
    char nombre[30];
public:
    ArchivoEmpleado(const char *_nombre){
    strcpy(nombre,_nombre);
    }
    void altaEmpleado(){
        Empleado obj;
        obj.CargarEmpleado();
        int pos=buscarRegistro(obj.getlegajo());
        int ultimoLegajo = obtenerUltimoNumeroEmpleado();
        obj.setlegajo(ultimoLegajo+1);
        if(pos != -1){
            cout<<"YA EXISTE UN LEGAJO IGUAL EN EL ARCHIVO "<<endl;
            obj.setEstado(false);
        }else if(obj.getEstado()==true){
            grabarRegistro(obj);
            cout<<"SE GRABO EL REGISTRO CORRECTAMENTE :-)"<<endl;
        }else{
            cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
        }
    }

    int obtenerUltimoNumeroEmpleado() {
        FILE *p;
        p = fopen(nombre, "rb");
        if (p == NULL) {
            return 0;
        }
        fseek(p, -static_cast<long>(sizeof(Empleado)), SEEK_END);
        Empleado ultimoLegajo;
        fread(&ultimoLegajo, sizeof(Empleado), 1, p);
        fclose(p);
        return ultimoLegajo.getlegajo();
    }

    void grabarRegistro(Empleado obj){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            return;
        }
        fwrite(&obj, sizeof (Empleado), 1, p);
        fclose(p);
    }

    int buscarRegistro(int num){
        Empleado obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getlegajo()==num && obj.getEstado()==true){
                return i;
            }
        }
        return -1;
    }


    Empleado leerRegistro(int pos){
        Empleado obj;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            obj.setlegajo(-2);
            return obj;
        }
        fseek(p, pos * sizeof(Empleado), 0);
        fread(&obj, sizeof (Empleado), 1, p);
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
        registro= cantBytes/sizeof(Empleado);

        return registro;
    }

    void modificarRegistro(Empleado obj, int pos){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return;
        }
        fseek(p, pos * sizeof (Empleado) , 0);
        fwrite(&obj, sizeof (Empleado), 1, p);
        fclose(p);
    }


    void bajaEmpleado(){
        Empleado obj;
        int legajo;
        cout<<"INGRESE EL LEGAJO A DARLE DE BAJA: ";
        cin>>legajo;
        int pos= buscarRegistro(legajo);
        if(pos<0){
            cout<<"NO HUBO COINCIDENCIA CON NINGUN LEGAJO EN EL ARCHIVO"<<endl;
            return;
        }

        obj=leerRegistro(pos);
        obj.setEstado(false);
        modificarRegistro(obj, pos);
        cout<<"EL LEGAJO SE HA ELIMINADO CORRECTAMENTE :-)"<<endl;
    }

    void listarEmpleado(){
        Empleado obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj =leerRegistro(i);

       if(obj.getEstado()==true)
        obj.MostrarEmpleado();
            cout<<endl;
        }
    }


    void listarPorNumeroEmpleado() {
        Empleado obj;
        int num;
        cout << "INGRESE EL LEGAJO QUE DESEA MOSTRAR: ";
        cin >> num;
        system("cls");
        int pos = buscarRegistro(num);
        if (pos < 0) {
            cout << "NO HUBO COINCIDENCIA EN EL ARCHIVO" << endl;
            return;
        }
        else {
            obj = leerRegistro(pos);
            if (obj.getEstado()){
                obj.MostrarEmpleado();
            }
            else {
                cout << "YA FUE DADO DE BAJA " << endl;
                obj.setEstado(false);
            }
        }
    }

    void ModificarEspecialidad(){
        int legajo;
        cout <<"INRESE EL LEGAJO DEL EMPLEADO: ";
        cin>>legajo;

        Empleado reg;
        char nomNuevo[30];
        int pos=buscarRegistro(legajo);

        if(pos<0){
            cout<<"NO EXISTE EL LEGAJO"<<endl;
            return;
        }
        reg=leerRegistro(pos);

        cout<<"NUEVA ESPECIALIDAD: ";
        cargarCadena(nomNuevo, 29);
        reg.setespecialidad(nomNuevo);
        modificarRegistro(reg,pos);
        cout<<"REGISTRO MODIFICADO CON EXITO :-)"<<endl;
        return;
    }

};

#endif // ARCHIVOEMPLEADO_H_INCLUDED
