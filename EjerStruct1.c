#include <stdio.h>
#include <time.h>


/*Se tienen */

void cargar();
void guardar();
void Lista();

int Matriz[20][20];


void cargar(){

    for (int i = 0; i < 20; i++) //En este for anidado, i va pasando de 1 en 1 cuando j haya dado 20 vueltas.
    {
        for (int j = 0; j < 20; j++)
        {
            Matriz[i][j] = (rand() % 901) + 100; //Primero se carga los numeros random en la matriz. El muero "&1000" indica que finaliza en 1000. la suma + 1 que empieza en 1;

        }
        
    }
}

void guardar()
{  
    FILE * Archivo; // Luego, guardo esos datos cargados en un archivo. Lo abro..
    Archivo = fopen("matriz.dat", "wt");

    for (int i = 0; i < 20; i++) //Reabro la matriz, para luego copiar con un fprintf..
    {
        for (int j = 0; j < 20; j++)
        {
            fprintf("&i \t", Matriz[i][j]);
        }
        
    }
    
    fclose(Archivo);

}

void Lista(){
    int Pares=0,Impares=0; // Se igualan a 0 porque son sumas
    int MatrizAux[20][20];

    FILE* Archivo;
    Archivo = fopen("matriz.dat","rt"); //Se reabre el archivo, y el siguiente for anidado va a agregar los valores del archivo en la matriz auxiliar

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            fscanf(Archivo,"%i \t", MatrizAux);//fscanf sirve para scanear la info del archivo y ponerla en pantalla
            printf("%i \t",MatrizAux[i][j]);
            if (i%2==0)
            {
            Pares += MatrizAux[i][j];
            }
            else
            {
            Impares += MatrizAux[i][j];
            }
        }
        
    }
    

    printf("\n La suma de las filas pares son : %i \n La suma de los impares es %i", Pares, Impares);


    fclose(Archivo);




}

main(){

    int Matriz[20][20];

    cargar(Matriz);

    guardar(Matriz);

    Lista();

}