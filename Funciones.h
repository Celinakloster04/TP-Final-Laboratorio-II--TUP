#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarCadena(char *palabra, int tam)
{
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ )
    {
        palabra[i] = std::cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}


#endif // FUNCIONES_H_INCLUDED
