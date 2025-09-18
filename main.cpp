#include <iostream>                                  		// Librerie
using namespace std;

int safe_divisione(int dividendo, int divisore, int quo_res);	// wrapper divisione
int divisione(int dividendo, int divisore, int quo_res);		// Prototipo divisione
int safe_moltiplicazione(int fattore1, int fattore2);	        // wrapper moltiplicazione
int moltiplicazione(int fattore1, int fattore2);    	        // Prototipo moltiplicazione
double safe_potenza(int base, int esponente);
int potenza(int base, int esponente);              	            // Prototipo potenza
void intDec(float numero);                         	            // Prototipo intero o decimale
void divisori(int numero);                       	            // Prototipo visualizza divisori
void tabellina(int numero);                     	            // Prototipo visualizza tabellina
void radiceQ(int numero);                       	            // Prototipo radice quadrata
void radiceC(int numero);                        	            // Prototipo radice cubica
void radiceE(int numero, int indice);                           // Prototipo radice ennesima
int MCD(int num_max, int num_min);              	            // Prototipo MCD
int mcm(int num_max, int num_min);                              // Prototipo mcm
void numeri_perfetti();                                         // Prototipo numeri perfetti
void scomposizioneNumero();                       	            // Prototipo scomposizione numero

int main(){
    int scelta;			// scelta del menu
    char risp;			// (s/n) per continuare
    int num1, num2;		// numeri da analizzare
    float numdec;
    int risultato;

    do{
        system("CLS");

	  // Inizio Menù
        cout << "\t\tMenu Esercizi Matematici" << endl << endl << endl;
        cout << "\t1............Quoziente divisione intera di due numeri interi" << endl << endl;
        cout << "\t2............Resto divisione intera di due numeri interi" << endl << endl;
        cout << "\t3............Moltiplicazione di due numeri interi" << endl << endl;
        cout << "\t4............Potenza di un numero" << endl << endl;
        cout << "\t5............Numero intero o decimale" << endl << endl;
        cout << "\t6............Visualizza divisori di un numero" << endl << endl;
        cout << "\t7............Visualizza tabellina di un numero" << endl << endl;
        cout << "\t8............Calcola radice quadrata di un numero" << endl << endl;
        cout << "\t9............Calcola radice cubica di un numero" << endl << endl;
        cout << "\t10...........Calcola radice ennesima di un numero" << endl << endl;
        cout << "\t11...........Calcola MCD di due numeri" << endl << endl;
        cout << "\t12...........Calcola mcm di due numeri" << endl << endl;
        cout << "\t13...........Visualizza 10 numeri perfetti" << endl << endl;
        cout << "\t14...........Scomposizione numero" << endl << endl;
        // fine menù

        cout << endl << "\tCosa preferisci eseguire? ";
        cin >> scelta;
        cout << endl;

        // flusso di elaborazione
        switch (scelta){
        case 1:
            cout << "\tinserisci il dividendo: ";
            cin >> num1;
            cout << "\tInserisci il divisore: ";
            cin >> num2;
            risultato = safe_divisione(num1, num2, scelta);
            if(risultato >= 0) cout << "Il quoziente della divisione e\': " << risultato << endl << endl;
            risultato = 0;
            break;
        case 2:
            cout << "\tinserisci il dividendo: ";
            cin >> num1;
            cout << "\tInserisci il divisore: ";
            cin >> num2;
            risultato = safe_divisione(num1, num2, scelta);
            if(risultato >= 0) cout << "Il resto della divisione e\': " << risultato << endl << endl;
            risultato = 0;
            break;
        case 3:
            cout << "\tinserisci il primo fattore: ";
            cin >> num1;
            cout << "\tInserisci il secondo fattore: ";
            cin >> num2;
            cout << "Il prodotto e\': " << safe_moltiplicazione(num1, num2) << endl << endl;
            break;
        case 4:
            cout << "\tinserisci la base: ";
            cin >> num1;
            cout << "\tInserisci l'esponente: ";
            cin >> num2;
            cout << "\tIl risultato e\': " << safe_potenza(num1, num2) << endl << endl;
            break;
        case 5:
            cout << "\tInserisci il numero: ";
            cin >> numdec;
            intDec(numdec);
            break;
        case 6:
            cout << "\tInserisci il numero di cui vuoi i divisori: ";
            cin >> num1;
            cout << endl;
            cout << "\tI divisori sono: ";
            divisori(num1);
            cout << endl << endl;
            break;
        case 7:
            cout << "\tInserisci il numero di cui vuoi la tabellina: ";
            cin >> num1;
            cout << endl;
            cout << "\tLa tabellina e\': ";
            tabellina(num1);
            cout << endl << endl;
            break;
        case 8:
            cout << "\tInserisci il numero di cui vuoi la radice quadrata: ";
            cin >> num1;
            cout << endl;
            cout << "\tLa radice quadrata  e\' ";
            radiceQ(num1);
            cout << endl << endl;
            break;
        case 9:
            cout << "\tInserisci il numero di cui vuoi la radice cubica: ";
            cin >> num1;
            cout << endl;
            cout << "\tLa radice cubuca  e\' ";
            radiceC(num1);
            cout << endl << endl;
            break;
        case 10:
            cout << "\tInserisci il numero di cui vuoi la radice: ";
            cin >> num1;
            cout << "\tInserisci l'indice: ";
            cin >> num2;
            cout << "\tIl risultato e\' ";
            radiceE(num1, num2);
            cout << endl << endl;
            break;
        case 11:
            cout << "\tInserisci il primo numero: ";
            cin >> num1;
            cout << "\tInserisci il secondo numero: ";
            cin >> num2;
            cout << "\tIl Massimo comune divisore e\' " << MCD(num1, num2) << endl << endl;
            break;
        case 12:
            cout << "\tInserisci il primo numero: ";
            cin >> num1;
            cout << "\tInserisci il secondo numero: ";
            cin >> num2;
            cout << "\tIl minimo comune multiplo e\' " << mcm(num1, num2) << endl << endl;
            break;
        case 13:
            cout << "\tI primi dieci numeri perfetti sono: ";
            numeri_perfetti();
            break;
        case 14:
            scomposizioneNumero();
            break;
        default:
            cout << "\tScelta non valida" << endl << endl;
        }
        cout << "Vuoi continuare? S/N: ";
        cin >> risp;
    } while (risp == 's' || risp == 'S');
}

// divisione fatta con sottrazioni ripetute
// wrapper per divisione con controllo sullo 0
int safe_divisione(int dividendo, int divisore, int quo_res){
    if(divisore == 0){
        cout << "La divisione per 0 è impossibile";
        return -1;
    }else{
        return divisione(dividendo, divisore, quo_res);
    }
}

// divisione di interi caso base, in base al terzo parametro
// ritorna il resto o il quoziente
int divisione(int dividendo, int divisore, int quo_res){
    int quoziente = 0;
    int resto = dividendo;

    while(resto >= divisore){		// divisione con sottrazioni ripetute
        resto = resto - divisore;	// calcolo del resto
        quoziente++;			    // calcolo del quoziente
    }
    if (quo_res == 1 ) return quoziente;
    else return resto;
}

// Moltiplicazione fatta cion addizioni ripetute
// wrapper per gestione del segno della moltiplicazione
int safe_moltiplicazione(int fattore1, int fattore2){
    int prodotto;			// contiene il risultato
    bool segno = true;		// gestione del segno
    if((fattore1 < 0) && (fattore2 < 0)){
        fattore1 = -fattore1;
        fattore2 = -fattore2;
    }else if(fattore1 < 0){
        fattore1 = -fattore1;
        segno = !segno;
    }else if(fattore2 < 0){
        fattore2 = -fattore2;
        segno = !segno;
    }

    prodotto = moltiplicazione(fattore1, fattore2);

    if(segno) return prodotto;
    else return -prodotto;
}

// Moltiplicazione di interi caso base
int moltiplicazione(int fattore1, int fattore2){
    int cont = 0, prodotto = 0;
    while (cont < fattore2){
        prodotto = prodotto + fattore1;
        cont++;
    }
    return prodotto;
}

// potenza fatta con moltiplicazioni ripetute
// wrapper per controllo sui segni e dello 0 della potenza
double safe_potenza(int base, int esponente){
    int segno = 1;

    if((base == 0) && (esponente == 0)){
            cout << "Attenzione: 0 elevato a 0 è indeterminato. Restituisco 1 per convenzione.\n";
            return 1;
    }
    if ((base < 0) && (esponente > 0)){	            // se base negativa e esponente positivo
        base = -base;				                // base diventa positivs

        if (divisione(esponente, 2, 2) == 1)        // se eponente è dispari
            segno = -segno;                         // il segno della potenza diventa negativo
        return segno * potenza(base, esponente);
    }

    if((base > 0) && (esponente < 0)){
        esponente = -esponente;
        return 1.0 / potenza(base, esponente);
    }

    if((base < 0) && (esponente < 0)){
        base = -base;
        esponente = -esponente;
        if (divisione(esponente, 2, 2) == 1)
            segno = -segno;
        return segno * (1.0 / potenza(base, esponente));

    }

    // Caso base > 0 e esponente > 0
    return potenza(base, esponente);
}

// Potenza di un numero caso base
int potenza (int base, int esponente){
    int cont = 0;
    int potenza = 1;
    while (cont < esponente){
        potenza = potenza * base;
        cont++;
    }
    return potenza;
}

// numero intero o decimale
void intDec(float numero){
    if(numero < 0) numero = -numero;			        // se negativo lo metto positivo
    while(numero >= 1)					                // divido per 1
        numero = numero - 1;				            // trovo il resto
    if (numero == 0)
        cout << "\tIl numero e\' intero" << endl << endl;
    else
        cout << "\tIl numero e\' decimale" << endl << endl;
}

// Divisori di un numero
void divisori(int numero){
    int divisore = 1;						            // candidato divisore
    int resto = numero;						            // resto della divisione
    if(numero <= 0){
        cout << "Il numero inserito non ha divisori\n";
    }else{
        while (divisore <= numero / 2){			        // trovo i divisori
            while ( resto >= divisore)				    // trovo il resto
                resto = resto - divisore;
            if (resto == 0) cout << divisore << " ";	// se resto 0 è un divisore
            divisore++;						            // cambio candidato divisore
            resto = numero;					            // reinizializzo il resto
        }
    }
    cout << numero << endl;
}

// Tabellina di un numero
void tabellina(int numero){
    if(numero <= 0){
        cout << "Errore: il numero e' negativo\n";
        return;
    }
    cout << "tabellina del numero " << numero << ":";
    for ( int i = 1; i <= 10; i++)
        cout << numero * i << "\t";
    cout << endl;
}

// Radice quadrata di un numero
void radiceQ(int numero){
    if(numero < 0){						            // controllo negativo
        cout << "La radice di un numero negativo non e' definita\n";
        return;
    }

    int cont = 0;

    while (cont * cont < numero){			        // calcolo quadrato dei naturali
        cont++;
    }
    if (cont * cont == numero)
        cout << "La radice quadrata di " << numero << " e': " << cont;
    else
        cout << "La radice quadrata di " << numero << " non e' un intero. E' compresa tra " << cont-1 << " e " << cont;
}

// Radice cubica di un numero
void radiceC(int numero){
    int segno;
    if(numero < 0){
        segno = -1;
        numero = -numero;
    }

    // calcolo il cubo dei naturali
    int cont = 0;
    while (cont * cont * cont < numero){
        cont++;
    }

    // gestione output
    if (cont * cont * cont == numero)
         cout << "La radice cubica di " << segno * numero << " e': "
<< segno * cont << endl;
    else
        cout << "La radice cubica di " << segno * numero << " non e' un intero. E' compresa tra " << segno * (cont - 1) << " e " << segno * cont << endl;
}

// Radice ennesima
void radiceE(int numero, int indice){
    int segno_numero = 1;		// segno radicando
    int segno_indice = 1;		// segno indice
    if(indice == 0){
        cout << "ERRORE: indice 0 non ha significato\n";
        return;
    }

    if((numero == 0) && (divisione(indice, 2, 2) == 0)){
        cout << "La radice di 0 e' sempre 0\n";
        return;
    }

    if((numero < 0) && (indice < 0)){
       if(divisione(indice, 2, 2) == 0){
            cout << "ERRORE: Radice di un negativo con indice pari, non definita nei reali.\n";
            return;
        }else{
            segno_numero = -segno_numero;
            segno_indice = -segno_indice;
            numero = -numero;
            indice = -indice;
        }
    }

    if((numero < 0) && (indice > 0)){
        segno_numero = -segno_numero;
        numero = -numero;
    }

    if((numero > 0) && (indice < 0)){
            segno_indice = -segno_indice;
            indice = -indice;
    }

    int potenza = 0, cont = 0;
    while (potenza < numero){	// calcolo potenza alla indice dei naturali
        cont++;
        potenza = 1;
        for (int i = 1; i <= indice; i++)
            potenza = potenza * cont;
    }

    // gestione output
    if (potenza == numero){
        if((segno_numero == 1) && (segno_indice == 1)){
            cout << "La radice di " << numero << " con indice " << indice << " e': " << cont << "\n";
            return;
        }
        if((segno_numero == -1) && (segno_indice == 1)){
            cout << "La radice di " << -numero << " con indice " << indice << " e': " << -cont << "\n";
            return;
        }
        if((segno_numero == 1) && (segno_indice == -1)){
            cout << "La radice di " << numero << " con indice " << -indice << " e': " << 1.0 /cont << "\n";
            return;
        }

    }

    if (potenza != numero){
        if((segno_numero == 1) && (segno_indice == 1)){
            cout << "La radice di " << numero << " con indice " << indice << " e' un numero compreso tra " << cont - 1 << " e " << cont << "\n";
            return;
        }
        if((segno_numero == -1) && (segno_indice == 1)){
            cout << "La radice di " << -numero << " con indice " << indice << " e' un numero compreso tra " << -(cont - 1) << " e " << -cont << "\n";
            return;
        }
        if((segno_numero == 1) && (segno_indice == -1)){
            cout << "La radice di " << numero << " con indice " << -indice << " e' il reciproco di un numero compreso tra " << cont - 1 << " e " << cont << "\n";
            return;
        }

    }
}

// Massimo Comune Divisore
int MCD(int num_max, int num_min){
    int temp, MCD = 0, divisore;
    if (num_max < num_min){
        temp = num_max;
        num_max = num_min;
        num_min = temp;
    }
    divisore = num_min;
    while (MCD == 0){
        if (divisione(num_min, divisore, 2) == 0)		// controllo resto 0 min
            if (divisione(num_max, divisore, 2) == 0)	// controllo resto 0 max
                MCD = divisore;
        divisore = divisore - 1;				        // cambio candidato divisore
    }
    return MCD;
}

// Minimo comune multiplo
int mcm(int num_max, int num_min){
    int temp;
    if (num_max < num_min){		                        // swap dei dati
        temp = num_max;
        num_max = num_min;
        num_min = temp;
    }
    // controllo i candidati multipli
    for (int multiplo = num_max; multiplo <= num_max * num_min; multiplo++)
        if((divisione(multiplo, num_max, 2) == 0) &&
(divisione(multiplo, num_min, 2) == 0))
            return multiplo;
}

// Numeri perfetti
void numeri_perfetti(){
    int num;			                // candidato perfetto
    int somma_divisori;	                // somma parziale dei divisori
    int conta_perfetti;	                // contatore dei numeri perfetti
    int res;			                // resto divisione
    int cont;		                    // contatore di naturali
    num = 1;
    conta_perfetti = 0;
    while (conta_perfetti < 4){
        somma_divisori = 0;
        cont = 1;
        while(cont <= num/2){		    // trova divisori
            res = num;
            while(res >= cont)		    // divisione intera tra res e cont
                res = res - cont;
            if(res == 0)
                somma_divisori = somma_divisori + cont;
            cont++;
        }
        if(somma_divisori == num){
            conta_perfetti++;
            cout << num << "  ";
        }
        num++;
    }
}

// Scomposizione numero
void scomposizioneNumero(){
    int num, numeroCifre, pot, quoziente, divisore, res;
    pot = 1;
    numeroCifre = 0;
    divisore = 1;
    quoziente = 0;

    cout << "Inserisci il numero da scomporre: ";
    cin >> num;
    cout << endl;

    while(pot < num){               // Calcolo il numero di cifre di cui è composto num
        pot = pot * 10;
        numeroCifre++;
    }
    res = num;

    while(numeroCifre > 1){
        for(int x = 1; x < numeroCifre; x++)           // Trovo il  divisore
            divisore = divisore * 10;
        while(res >= divisore){                        // Divisione tra res e divisore
            res = res - divisore;
            quoziente++;
        }
        cout << quoziente << "  ";
        numeroCifre--;
        quoziente = 0;
        divisore = 1;
    }
    cout << res;
    cout << endl << endl;
}
