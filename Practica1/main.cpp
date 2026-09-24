#include <iostream>

using namespace std;

void pro1(){
    char a;
    cout<<"Hola, comprobemos si lo que ingresas es una vocal, consonante o ninguna!"<<endl;
    cout<<"Ingrese su letra: "<< endl;
    cin>>a;

    if (a==65 || a==69 || a==73 || a==79 || a==85 || a==97 || a==101 || a==105 || a==111 || a==117){
        cout<<a<<" es vocal"<<endl;
    }else if (a >=65 && a <=90 || a >=97 && a <=122){
        cout<<a<<" es una consonante"<< endl;
    } else {
        cout<<a<<" no es una letra"<<endl;
    }

}

void pro2(){
    int a;
    int cincuentamil=0;
    int veintemil=0;
    int diezmil=0;
    int cincomil=0;
    int dosmil=0;
    int mil=0;
    int quinientos=0;
    int doscientos=0;
    int cien=0;
    int cincuenta=0;
    int faltante=0;
    cout<<"Hola, Veamos como entregar la cantidad de dinero que quieres con la moneda en rotacion"<<endl;
    cout<<"Ingrese la cantidad de dinero "<<endl;
    cin>>a;

    while (cin.fail()){
        cout<<"Eso no es un numero"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>a;
    }

    while (a>=50000){
        a=(a-50000);
        cincuentamil=cincuentamil+1;
    }

    while (a>=20000){
        a=(a-20000);
        veintemil=veintemil+1;
    }

    while (a>=10000){
        a=(a-10000);
        diezmil=diezmil+1;
    }
    while (a>=5000){
        a=(a-5000);
        cincomil=cincomil+1;
    }
    while (a>=2000){
        a=(a-2000);
        dosmil=dosmil+1;
    }
    while (a>=1000){
        a=(a-1000);
        mil=mil+1;
    }
    while (a>=500){
        a=(a-500);
        quinientos=quinientos+1;
    }
    while (a>=200){
        a=(a-200);
        doscientos=doscientos+1;
    }
    while (a>=100){
        a=(a-100);
        cien=cien+1;
    }
    while (a>=50){
        a=(a-50);
        cincuenta=cincuenta+1;
    }
    faltante= a;
    cout<<"Debes entregar de a ..."<< endl;
    cout<<"50000: "<<cincuentamil<<endl;
    cout<<"20000: "<<veintemil<<endl;
    cout<<"10000: "<<diezmil<<endl;
    cout<<"5000: "<<cincomil<<endl;
    cout<<"2000: "<<dosmil<<endl;
    cout<<"1000: "<<mil<<endl;
    cout<<"500: "<<quinientos<<endl;
    cout<<"200: "<<doscientos<<endl;
    cout<<"100: "<<cien<<endl;
    cout<<"50: "<<cincuenta<<endl;
    cout<<"Faltante: "<<faltante<<endl;

}

void pro3(){
    int mes;
    int dia;

    cout<<"Hola, Veamos si la fecha que ingresas es valida"<<endl;



    cout << "Ingrese un dia: "<<endl;
    cin >> dia;

    while (cin.fail() || dia<1 || dia>31){
        cout<<dia<<" es un dia invalido"<<endl;
        cout<<"Ingrese un dia valido "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> dia;
    }

    cout << "Ahora Ingrese un numero de mes: ";
    cin >> mes;

    while (cin.fail() || mes<1 || mes>12){
        cout<<mes<<" es un mes invalido"<<endl;
        cout<<"Ingrese un mes valido "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> mes;
    }

    if (mes==2 && dia==29){
        cout<<dia<< " / " << mes <<" Es valida en año bisiesto"<<endl;
    }else if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8|| mes==10 || mes==12) && (dia>=1 && dia<=31)){
        cout<<dia<< "/" << mes <<" Es una Fecha valida"<<endl;
    }else if ((mes==4 || mes==6 || mes==9 || mes==11)&& (dia==31)) {
        cout<<dia<< "/" << mes <<" Es una Fecha invalida"<<endl;
    }else if ((mes==2)&&(dia>=30)){
        cout<<dia<< "/" << mes <<" Es una Fecha invalida"<<endl;
    }else {
        cout<<dia<< "/" << mes <<" Es una Fecha valida"<<endl;
    }

}

void pro5(){

    int x;

    cout<<"Hola, Hagamos un patron de diamante"<<endl;

    cout<<"Ingrese un numero impar para el tamaño de la figura: "<<endl;
    cin>>x;

    while (cin.fail() || x%2==0){
        cout<<"Ingrese un numero impar valido: "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>x;
    }

    int mitad = x/2+1;
    for(int i=1; i<=mitad; i++){
        for (int j=1;j<=mitad-i;j++){
            cout<<" ";
        }

        for (int j=1; j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;

    }
    for (int i = mitad - 1; i >= 1; i--) {
        for (int j = 1; j <= mitad - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pro7() {
    int a;
    int b=1;
    int c=1;
    int d=0;
    int e=0;

    cout<<"Hola, hallemos la suma de los numeros pares en fibonacci menores a un numero: "<<endl;
    cout<<"Ingrese un numero: "<<endl;
    cin>>a;

    while (cin.fail()){
        cout<<"Ingrese un numero "<<endl;
        cin.clear();
        cin.ignore (1000, '\n');
        cin>>a;
    }
    while (d<=a){
        d=b+c;
        if (d%2==0 && d<a){
            e=e+d;
        }
        c=b;
        b=d;
    }
    cout<<"El resultado de la suma es: "<< e<<endl;
}

void pro9(){
    int n;

    cout<<"Hola, Calculemos la suma de los digitos que ingresas elevados a si mismos"<<endl;
    cout<<"Ingrese un numero"<<endl;
    cin>>n;

    while(cin.fail()){
        cout<<"Ingrese un numero valido"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>n;
    }

    int suma=0;

    while(n>0){
        int digito=n%10;
        int resultado=1;
        int i=1;

        while(i<=digito){
            resultado=resultado*digito;
            i++;
        }

        suma=suma+resultado;
        n=n/10;
    }

    cout<<"El resultado de la suma es: "<<suma<<endl;
}


void pro11(){
    int n;

    cout<<"Hola, Calculemos el minimo comun multiplo desde 1 hasta un numero"<<endl;
    cout<<"Ingrese un numero"<<endl;
    cin>>n;

    while(cin.fail()){
        cout<<"Ingrese un numero valido"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>n;
    }

    long long resultado=1;

    for(int i=1;i<=n;i++){
        int anterior=resultado;

        while(resultado%i!=0){
            resultado=resultado+anterior;
        }
    }

    cout<<"El minimo comun multiplo es: "<<resultado<<endl;
}


void pro13(){
    int n;

    cout<<"Hola, Sumemos todos los numeros primos menores a un numero"<<endl;
    cout<<"Ingrese un numero"<<endl;
    cin>>n;

    while(cin.fail()){
        cout<<"Ingrese un numero valido"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>n;
    }

    int suma=0;

    for(int i=2;i<n;i++){
        int divisores=0;

        for(int j=1;j<=i;j++){
            if(i%j==0){
                divisores=divisores+1;
            }
        }

        if(divisores==2){
            suma=suma+i;
        }
    }

    cout<<"El resultado de la suma es: "<<suma<<endl;
}


void pro15(){
    int n;

    cout<<"Hola, vamos a calcular la suma de las diagonales de una espiral"<<endl;
    cout<<"Ingrese un numero impar"<<endl;
    cin>>n;

    while(cin.fail() || n%2==0 || n<=0){
        cout<<"Ingrese un numero impar valido"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>n;
    }

    int espiral[100][100];

    int fila=n/2;
    int columna=n/2;
    int numero=1;

    espiral[fila][columna]=numero;

    int pasos=1;

    while(numero<n*n){

        for(int i=0;i<pasos && numero<n*n;i++){
            columna=columna-1;
            numero=numero+1;
            espiral[fila][columna]=numero;
        }

        for(int i=0;i<pasos && numero<n*n;i++){
            fila=fila+1;
            numero=numero+1;
            espiral[fila][columna]=numero;
        }

        pasos=pasos+1;

        for(int i=0;i<pasos && numero<n*n;i++){
            columna=columna+1;
            numero=numero+1;
            espiral[fila][columna]=numero;
        }

        for(int i=0;i<pasos && numero<n*n;i++){
            fila=fila-1;
            numero=numero+1;
            espiral[fila][columna]=numero;
        }

        pasos=pasos+1;
    }

    long long suma=0;

    for(int i=0;i<n;i++){
        suma=suma+espiral[i][i];

        if(i!=n-1-i){
            suma=suma+espiral[i][n-1-i];
        }
    }

    cout<<"La suma de las diagonales es: "<<suma<<endl;
}


void pro17(){
    int k;

    cout<<"Hola, Busquemos el primer numero triangular que tenga mas divisores"<<endl;
    cout<<"Ingrese un numero"<<endl;
    cin>>k;

    while(cin.fail()){
        cout<<"Ingrese un numero valido"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>k;
    }

    int n=1;
    long long triangular=1;
    int divisores=0;

    while(divisores<=k){

        triangular=(long long)n*(n+1)/2;
        divisores=0;

        for(int i=1;i<=triangular;i++){
            if(triangular%i==0){
                divisores=divisores+1;
            }
        }

        n=n+1;
    }

    cout<<"El numero es: "<<triangular<<" que tiene "<<divisores<<" divisores."<<endl;
}


int main()
{
    int x=1;



    while (x!=0){

        cout<<"-------------------------------"<<endl;
        cout<<"         Ejercicios"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Vocales/consonantes/ninguno"<<endl;
        cout<<"2. Distribucion dinero"<<endl;
        cout<<"3. Fecha valida"<<endl;
        cout<<"5. Patron Diamante"<<endl;
        cout<<"7. Fibonacci"<<endl;
        cout<<"9. Suma de digitos elevados"<<endl;
        cout<<"11. Minimo Comun Multiplo "<<endl;
        cout<<"13. Suma de Numeros Primos menores"<<endl;
        cout<<"15. Espiral nxn"<<endl;
        cout<<"17. Numero triangular"<<endl;
        cout <<"0. Salir"<<endl;
        cout<<endl;
        cout<<"Que ejercicio deseas revisar?"<<endl;
        cin>>x;
        while (cin.fail()) {
            cout << "Ingrese una opcion valida: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> x;
        }

        switch(x){
        case 1: pro1(); break;
        case 2: pro2(); break;
        case 3: pro3(); break;
        case 5: pro5(); break;
        case 7: pro7(); break;
        case 9: pro9(); break;
        case 11: pro11(); break;
        case 13: pro13(); break;
        case 15: pro15(); break;
        case 17: pro17(); break;



        case 0:
            cout<<"Chaolin Pinguin"<<endl;
            break;
        default:
            cout << "Opcion invalida, Sigue intentando"<< endl;
        }
    }
}
