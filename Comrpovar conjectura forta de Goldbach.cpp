#include<iostream>
#include<windows.h>

using namespace std;

bool test_primer(int n){
	bool condicio = true;
	
	for(int i=2; i<n; i++){
		if(n%i == 0){
			condicio = false;
		}
	}
	
	return condicio;
}

int main(){
	int Goldbach;
	char pregunta;
	int cicle;
	bool fin = false;
	
	cout<<"Introdueix un numero de cicle: "; cin>>cicle;
	
	for(int i=3; i<=cicle; i++){
		for(int j=3; j<=cicle; j++){
			if(test_primer(i) == true and test_primer(j) == true){
				Goldbach = i + j;
				if(Goldbach%2 != 0){
					fin = true;
					cout<<"No es compleix la conjectura de Goldbach";
					cout<<i<<" + "<<j<<" = "<<Goldbach<<endl;
					cout<<Goldbach<<" no es parell"<<endl;
					system("start audio.mp3");
					cout<<endl<<"Vols continuar?(s/n) --> "; cin>>pregunta;
					if(pregunta == 'n' or pregunta == 'N'){
						break;
					}
				}
				else {
					cout<<i<<" + "<<j<<" = "<<Goldbach<<" es parell"<<endl;
				}
			}
		}
	}
	
	if(fin == false){
		cout<<endl<<"La conjectura es compleix en l'interval (3,"<<cicle<<")"<<endl;
	}
	else {
		cout<<endl<<"La conjectura no es compleix"<<endl;
	}
	
	system("start audio.mp3");
	
	return 0;
}

