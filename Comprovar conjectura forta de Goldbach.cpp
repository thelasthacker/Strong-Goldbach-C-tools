#include<iostream>
#include<windows.h>

using namespace std;

//la funció que comprovarà si els dos sumands són primers és la següent
bool test_primer(int n){
	//la variable que retorna aquesta funció és booleana, ja que, per comprovar primers només necessitem saber 'True' o 'False' 
	bool condicio = true;
	
	for(int i=2; i<n; i++){
		if(n%i == 0){
			/*Si per algun nombre i de 2 a n - 1 (on n és el nombre que estem comprovant) obtenim un residu 0 al fer la divisió n/i, a llavors, n no és primer, 
			ja que, si fos primer els divisors de n només serien dos: 1 i n, però els hem restringit. */
			condicio = false;
			//a llavors, immediatament la condició és falsa
		}
	}
	
	return condicio;
}
//En la funció principal necessitem una entrada de dades per indicar el límit per als dos sumands
int main(){
	//Declarem les variables principals
	int Goldbach;
	char pregunta;
	int l;
	bool es_compleix = true;
	
	//Entrada de dades, nombre límit per als dos sumands primers
	cout<<"Introdueix un numero limit per els dos sumands: "; cin>>l;
	
	/*muntem el cicle for per cada i i j en l'interval (3,l) (perque la conjectura de Goldbach s'estén des de n>2 fins a infinit) on l és 
	el valor que hem especificat abans */
	for(int i=3; i<=l; i++){
		for(int j=3; j<=l; j++){
			if(test_primer(i) == true and test_primer(j) == true){
				//Calculem la suma de nombres que, per la línia anterior, sabem que són primers 
				Goldbach = i + j;
				if(Goldbach%2 != 0){
					/* Si la suma de primers no és parell, a llavors, no es compleix la conjectura, ja que, que tot nombre parell es pugui expressar com a suma
					de nombres primers implica que per tot nombre primer p existeix un altre nombre primer q tal que p + q = 2k on k és un nombre natural. */
					es_compleix = false;
					//Així, la condició es_compleix es fa falsa, ja que, la suma no és parell
					//Mostrem un missatge d'alerta en pantalla i els sumands que donen lloc a la suma senar 
					cout<<"[!] "<<i<<" + "<<j<<" = "<<Goldbach<<endl;
					cout<<Goldbach<<" no es parell"<<endl;
					cout<<"[!] No es compleix la conjectura de Goldbach"<<endl;
					//I per avisar del que hem trobat executem un audio d'alerta
					/* Ara, mostrem un missatge en pantalla en que preguntem a l'usuari si vol continuar amb la recerca després d'haver descobert aquesta suma
					senar */ 
					system("start audio.mp3");
					while(true){
						cout<<endl<<"Vols continuar?(s/n) --> "; cin>>pregunta;
						if(pregunta == 'n' or pregunta == 'N'){
							//Si introdueix n o N (no) finalitzem el cicle
							break;
						}
						else if(pregunta != 'n' or pregunta != 'N' or pregunta != 's' or pregunta != 'S'){
							//Si introdueix un caràcter diferent de s o S i de n o N, l'entrada no és vàlida, així que ho indiquem.
							cout<<"[!] "<<pregunta<<" no es reconeix com un resposta valida. Introdueix s o S (si) o n o N (no)"<<endl;
						}
				    }
			    }
			    //Si la suma és parell, tot va bé, la conjectura es compleix per i i j, així que mostrem el resultat en pantalla.
				else if(pregunta == 's' or pregunta == 'S'){
					cout<<"[~] "<<i<<" + "<<j<<" = "<<Goldbach<<" es parell"<<endl;
				}
			}
		}
	}
	
	/* Ara, havent finalitzat la recerca, utilitzem la variable es_compleix que és certa si la conjectura de Goldbach es compleix i viceversa per mostrar un
	missatge o un altre en la pantalla. */
	if(es_compleix == true){
		//Si es_compleix és cert (true), a llavors, indiquem l'interval en el qual la conjectura es compleix.
		cout<<endl<<"[+] La conjectura es compleix en l'interval (3,"<<l<<")"<<endl;
	}
	else {
		/* Si es_compleix és fals (false), a llavors, si per algun parell de primers no es compleix, la conjectura de Goldbach no es compleix,
		ja que, afirma que per tot parell de nombres primers s'ha de complir, així que només fa falta un contraexemple perque definitivament
		no sigui certa. */
		cout<<endl<<"[-] La conjectura no es compleix"<<endl;
	}
	
	//Quan el programa finalitza reproduim un audio d'alerta.
	system("start audio2.mp3");
	
	return 0;
}

/* Això és un exemple, molt bàsic, de contraexemple si es dona el primer cas de la línia 40. No obstant, per a nombres molt grans aquest programa és molt lent,
obviament. Tot i això, pot servir per entendre la conjectura de Goldbach i aplicar-ho a ordinadors més potents.
Podem iniciar els valors iteradors i,j des d'un valor més gran simplement fent:
for(int i=4000; i<=l; i++)
  etc.
Aquesta manera d'utilitzar-lo és millor, és més, podriem demanar a l'usuari els valors i i j inicials d'aquesta manera:
int i,j;
cout<<"Valor inicial del primer sumand: "; cin>>i;
cout<<"Valor inicial del segon sumand: "; cin>>j;

etc.

Així el codi seria més útil per buscar possibles sumes senars.

Aquesta manera de comprovar la conjectura forta de Goldbach funcionaria igual per a comprovar la conjectura débil, encara que ja està demostrada, 
les variables que iteren serien tres i,j,k tal que formariem ternes i + j + k on i,j,k són primers. Bé, doncs, la conjectura débil implicaria que
i + j + k = nombre compost = p1p2p3...pn. En aquest cas hauriem de muntar un cicle for "anidat" així:

for(i...)
 for(j...)
   for(k...)
...

*/  

