#include<iostream>
#include<string>
using namespace std;
//creacion matriz
char** createMatrix(int size);
//delete matriz
void deleteMatrix(int size,char** matrix);
//print matriz
void printMatrix(int size,char** matrix);
//eat function
void eatPiece(int x,int y,char** matrix);
void eatPiece2(int x,int y,char** matrix);
//GANOOO!!
char GANO(char**matrix);
//EMPATE!!
char EMPATE(char**matrix);

int main(){
	char* legit = new char[11];
	legit[0]='A';
	legit[1]='B';
	legit[2]='C';
	legit[3]='D';
	legit[4]='E';
	legit[5]='F';
	legit[6]='G';
	legit[7]='H';
	legit[8]='I';
	legit[9]='J';
	legit[10]='K';
	int num_letra;
	cout<<"BIEVENIDO AL MEJOR JUEGO DE LA HISTORIA"<<endl;
	cout<<"Ingrese su nombre jugador uno: ";
	string name_player1;
	cin>>name_player1;
	cout<<"Ingrese su nombre jugador dos: ";
	string name_player2;
	cin>>name_player2;
	char** matrix = createMatrix(11);
	printMatrix(11,matrix);
	cout<<name_player1<<" es las piezas #"<<endl;
	cout<<name_player2<<" es las piezas +"<<endl;
	cout<<"REGLAS"<<endl;
	cout<<"-Solo mover a lo maximo dos espacios"<<endl;
	cout<<"-Si mueve un espacio su pieza se clona , si se mueve dos su piezase mueve"<<endl;
	cout<<"-Ingresar primero letra(en MAYUSCULA) de donde se quiere mover luego ingresar numero"<<endl;
	bool finished = false;
	while(finished==false){
		cout<<name_player1<<" ingrese cual pieza movera"<<endl;
		cout<<"LETRA: ";
		char letra;
		cin>>letra;
		bool valid = false;
		while(cin.fail()){
			cin.clear();
			cin.ignore(256,'\n');
			cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
			cin>>letra;
		}
		while(valid==false){
			for ( int i = 0 ; i < 11  ; i++){
	         	       if(legit[i]==letra){
				       valid = true;
 	               	}
 	      		 }
			if(valid==false){
				cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
		                cin>>letra;
			}
		}
		cout<<"NUMERO: "<<endl;
		int num;
		cin>>num;
		while(cin.fail()){
	                cin.clear();
	                cin.ignore(256,'\n');
	                cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
	                cin>>num;
	        }
		while(num<0 || num>10){
			cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
			cin>>num;
		}
		
		for(int i = 0 ; i < 11 ; i++){
			if(legit[i]==letra){
			num_letra=i;
			}
		}
		while(matrix[num][num_letra]=='+' || matrix[num][num_letra]=='*'){
			cout<<"Ahi no existe pieza o esa pieza no es suya"<<endl;
			cout<<"LETRA: ";
			cin>>letra;
                	valid = false;
                	while(cin.fail()){
                        	cin.clear();
                        	cin.ignore(256,'\n');
                        	cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                        	cin>>letra;
                	}
			while(valid==false){
                        	for ( int i = 0 ; i < 11  ; i++){
                               		if(legit[i]==letra){
                                       		valid = true;
                        		}
                         	}
                        	if(valid==false){
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra;
                        	}
                	}
			cout<<"NUMERO: "<<endl;
			cin>>num;
                	while(cin.fail()){
                        	cin.clear();
                        	cin.ignore(256,'\n');
                        	cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                        	cin>>num;
                	}
                	while(num<0 || num>10){
                        	cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                        	cin>>num;
                	}
                
                	for(int i = 0 ; i < 11 ; i++){
                        	if(legit[i]==letra){
                        	num_letra=i;
                        	}
                	}
		}//fin while pieza mala
		cout<<"Donde quiere mover esa pieza: "<<endl;
		cout<<"LETRA: ";
		char letra_new;
		cin>>letra_new;
		bool valida=false;
		while(cin.fail()){
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra_new;
                        }
		while(valida==false){
                	for ( int i = 0 ; i < 11  ; i++){
                        	if(legit[i]==letra_new){
                                	valida = true;
                                	}
                        }
                        if(valida==false){
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra_new;
                                }
                        }
		int num_new;
		cout<<"NUMERO: "<<endl;
                cin>>num_new;
                while(cin.fail()){
                	cin.clear();
                        cin.ignore(256,'\n');
                        cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                        cin>>num_new;
                        }
              	while(num_new<0 || num_new>10){
                    	cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                  	cin>>num_new;
                        }
		int num_letra_new;
             	for(int i = 0 ; i < 11 ; i++){
                	if(legit[i]==letra_new){
                     		num_letra_new=i;
                       	}
             	}
		int change_num = num-num_new;
		int change_letra=num_letra - num_letra_new;
		bool validation = false;
		while(validation == false){
			bool last_val=true;
			if(change_num<-2 || change_num>2){
				last_val=false;
				cout<<"VAD1"<<endl;
			}
			if(change_letra<-2 || change_letra>2){
				last_val=false;
				cout<<"VAD2"<<endl;
			}
			if(matrix[num_new][num_letra_new]=='+' || matrix[num_new][num_letra_new]=='#'){
				last_val=false;
				cout<<"VAD3"<<endl;
			}
			if(last_val==false){
				cout<<"Hizo algo mal, porfavor ingrese de nuevo a donde quiere mover porfavor"<<endl;
				cout<<"LETRA: ";
                		cin>>letra_new;
                		while(cin.fail()){
                	                cin.clear();
                	                cin.ignore(256,'\n');
                	                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                	                cin>>letra_new;
                	        }
                		while(valid==false){//aqui
                        		for ( int i = 0 ; i < 11  ; i++){
                        	        	if(legit[i]==letra_new){
                        	                	valid = true;
                        	                }
                        	}
                        	if(valid==false){
               	        	        cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
               	        	        cin>>letra_new;
                		                }
                		        }
                	
                		cout<<"NUMERO: "<<endl;
                		cin>>num_new;
                		while(cin.fail()){
                	        	cin.clear();
                	        	cin.ignore(256,'\n');
                	        	cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                	        	cin>>num_new;
                	        }
                		while(num_new<0 || num_new>10){
                	        	cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                	        	cin>>num_new;
                	        }
                	
                		for(int i = 0 ; i < 11 ; i++){
                	        	if(legit[i]==letra_new){
                	                	num_letra_new=i;
                	        }
                	}
                		int change_num = num-num_new;
                		int change_letra=num_letra - num_letra_new;	
			}//fin if if false
			if(last_val==true){
	
				if(change_num==1 || change_num==-1){
		
					matrix[num_new][num_letra_new]='#';
				}
				if(change_letra==1 || change_letra==-1){
			
					matrix[num_new][num_letra_new]='#';
				}
				if(change_num==2 || change_num==-2){
					
					matrix[num][num_letra]='*';
					matrix[num_new][num_letra_new]='#';
				}
				if(change_letra==2 || change_letra==-2){
					
					matrix[num][num_letra]='*';
                                        matrix[num_new][num_letra_new]='#';
				}
				validation=true;
			}
		}
		//aqui se come
		eatPiece(num_new,num_letra_new,matrix); 
		printMatrix(11,matrix);
		char test = EMPATE(matrix);
		if(test == 't'){
			char winner = GANO(matrix);
			if(winner == '1'){
				cout<<"GANOOOOOO: "<<name_player1<<endl;
			}
			if(winner == '2'){
				cout<<"GANOOOOOO: "<<name_player2<<endl;
			}
			if(winner == '3'){
				cout<<"EMPATEEEE"<<endl;
			}
		} 
		//PLAYER2
		cout<<name_player2<<" ingrese cual pieza movera"<<endl;
                cout<<"LETRA: ";
                char letra2;
                cin>>letra2;
                bool valid2 = false;
                while(cin.fail()){
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                        cin>>letra2;
                }
		while(valid2==false){
                        for ( int i = 0 ; i < 11  ; i++){
                               if(legit[i]==letra){
                                       valid2 = true;
                        }
                         }
                        if(valid2==false){
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra2;
                        }
                }
                cout<<"NUMERO: "<<endl;
                int num2;
                cin>>num2;
                while(cin.fail()){
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                        cin>>num2;
                }
                while(num2<0 || num2>10){
                        cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                        cin>>num2;
                }
		int num_letra2;
                for(int i = 0 ; i < 11 ; i++){
                        if(legit[i]==letra2){
                        num_letra2=i;
                        }
		}
		while(matrix[num2][num_letra2]=='#' || matrix[num2][num_letra2]=='*'){
                        cout<<"Ahi no existe pieza o esa pieza no es suya"<<endl;
                        cout<<"LETRA: ";
                        cin>>letra2;
                        valid2 = false;
                        while(cin.fail()){
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra2;
                        }
                        while(valid2==false){
                                for ( int i = 0 ; i < 11  ; i++){
                                        if(legit[i]==letra2){
                                                valid2 = true;
                                        }
                                }
                                if(valid2==false){
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra2;
                                }
                        }
                        cout<<"NUMERO: "<<endl;
                        cin>>num2;
                        while(cin.fail()){
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>num2;
                        }
                        while(num2<0 || num2>10){
                                cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>num2;
                        }

                        for(int i = 0 ; i < 11 ; i++){
                                if(legit[i]==letra2){
                                num_letra2=i;
                                }
                        }
                }//fin while pieza mala
		cout<<"Donde quiere mover esa pieza: "<<endl;
                cout<<"LETRA: ";
                char letra_new2;
                cin>>letra_new2;
                bool valida2=false;
                while(cin.fail()){
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra_new2;
                        }
                while(valida2==false){
                        for ( int i = 0 ; i < 11  ; i++){
                                if(legit[i]==letra_new2){
                                        valida2 = true;
                                        }
                        }
                        if(valida2==false){
                                cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                cin>>letra_new2;
                                }
                        }
		int num_new2;
                cout<<"NUMERO: "<<endl;
                cin>>num_new2;
                while(cin.fail()){
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                        cin>>num_new2;
                        }
                while(num_new2<0 || num_new2>10){
                        cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                        cin>>num_new2;
                        }
                int num_letra_new2;
                for(int i = 0 ; i < 11 ; i++){
                        if(legit[i]==letra_new2){
                                num_letra_new2=i;
                        }
                }
		int change_num2 = num2-num_new2;
                int change_letra2=num_letra2 - num_letra_new2;
                bool validation2 = false;
		while(validation2 == false){
                        bool last_val2=true;
                        if(change_num2<-2 || change_num2>2){
                                last_val2=false;
                                cout<<"VAD1"<<endl;
                        }
                        if(change_letra2<-2 || change_letra2>2){
                                last_val2=false;
                                cout<<"VAD2"<<endl;
                        }
                        if(matrix[num_new2][num_letra_new2]=='+' || matrix[num_new2][num_letra_new2]=='#'){
                                last_val2=false;
                                cout<<"VAD3"<<endl;
                        }
                        if(last_val2==false){
                                cout<<"Hizo algo mal, porfavor ingrese de nuevo a donde quiere mover porfavor"<<endl;
                                cout<<"LETRA: ";
                                cin>>letra_new2;
                                while(cin.fail()){
                                        cin.clear();
                                        cin.ignore(256,'\n');
                                        cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                        cin>>letra_new2;
                                }
                                while(valid2==false){
                                        for ( int i = 0 ; i < 11  ; i++){
                                                if(legit[i]==letra_new2){
                                                        valid2 = true;
                                                }
                                }
                                if(valid2==false){
                                        cout<<"Letra no es legal porfavor ingrese de nuevo"<<endl;
                                        cin>>letra_new2;
                                                }
                                        }
				cout<<"NUMERO: "<<endl;
                                cin>>num_new2;
                                while(cin.fail()){
                                        cin.clear();
                                        cin.ignore(256,'\n');
                                        cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                                        cin>>num_new2;
                                }
                                while(num_new2<0 || num_new2>10){
                                        cout<<"NUMERO no es legal porfavor ingrese de nuevo"<<endl;
                                        cin>>num_new2;
                                }

                                for(int i = 0 ; i < 11 ; i++){
                                        if(legit[i]==letra_new2){
                                                num_letra_new2=i;
                                }
                        }
                                int change_num2 = num-num_new2;
                                int change_letra2=num_letra2 - num_letra_new2;
                        }//fin if if false
			if(last_val2==true){
                           
                                if(change_num2==1 || change_num2==-1){
                            
                                        matrix[num_new2][num_letra_new2]='+';
                                }
                                if(change_letra2==1 || change_letra2==-1){
                                        
                                        matrix[num_new2][num_letra_new2]='+';
                                }
                                if(change_num2==2 || change_num2==-2){
                                     
                                        matrix[num2][num_letra2]='*';
                                        matrix[num_new2][num_letra_new2]='+';
                                }
                                if(change_letra2==2 || change_letra2==-2){
                                       
                                        matrix[num2][num_letra2]='*';
                                        matrix[num_new2][num_letra_new2]='+';
                                }
                                validation2=true;
                        }
                }
                //aqui se come
                eatPiece2(num_new2,num_letra_new2,matrix);
                printMatrix(11,matrix);
		test = EMPATE(matrix);
                if(test == 't'){
                        char winner = GANO(matrix);
                        if(winner == '1'){
                                cout<<"GANOOOOOO: "<<name_player1<<endl;
                        }
                        if(winner == '2'){
                                cout<<"GANOOOOOO: "<<name_player2<<endl;
                        }
                        if(winner == '3'){
                                cout<<"EMPATEEEE"<<endl;
                        }
                }

	}//fin while mayor
	deleteMatrix(11,matrix);
	return 0;
}

char** createMatrix(int size){
	char** matrix = new char*[size];
	for(int i = 0 ; i < size ; i++){
		matrix[i] = new char[size];
	}
	for(int i = 0 ; i <size ; i++){
		for(int b = 0 ; b < size ; b++){
			matrix[i][b]='*';
		}
	}
	matrix[0][0]='#';
	matrix[0][10]='#';
	matrix[10][0]='+';
	matrix[10][10]='+';
	return matrix;

}

void printMatrix(int size,char** matrix){
	cout<<"  A B C D E F G H I J K"<<endl;
	for(int i = 0 ; i < size ; i++){
		cout<<"|";
		for(int b = 0; b < size; b++){
			cout<<" "<<matrix[i][b];
		}
		cout<<" | "<<i<<endl;
	}
}

void deleteMatrix(int size,char** matrix){
	for(int i = 0 ; i < size ; i++){
		delete matrix[i];
	}
	delete matrix;	
}

void eatPiece(int x,int y,char** matrix){
	if(matrix[x+1][y]=='+'){
		matrix[x+1][y]='#';
	}
	if(matrix[x][y+1]=='+'){
                matrix[x][y+1]='#';
        }
	if(matrix[x-1][y]=='+'){
                matrix[x-1][y]='#';
        }
	if(matrix[x][y-1]=='+'){
                matrix[x][y-1]='#';
        }
	if(matrix[x+1][y+1]=='+'){
                matrix[x+1][y+1]='#';
        }
	if(matrix[x-1][y-1]=='+'){
                matrix[x-1][y-1]='#';
        }
	if(matrix[x+1][y-1]=='+'){
                matrix[x+1][y-1]='#';
        }
	if(matrix[x-1][y+1]=='+'){
                matrix[x-1][y+1]='#';
        }
}

void eatPiece2(int x,int y,char** matrix){
        if(matrix[x+1][y]=='#'){
                matrix[x+1][y]='+';
        }
        if(matrix[x][y+1]=='#'){
                matrix[x][y+1]='+';
        }
        if(matrix[x-1][y]=='#'){
                matrix[x-1][y]='+';
        }
        if(matrix[x][y-1]=='#'){
                matrix[x][y-1]='+';
        }
        if(matrix[x+1][y+1]=='#'){
                matrix[x+1][y+1]='+';
        }
        if(matrix[x-1][y-1]=='#'){
                matrix[x-1][y-1]='+';
        }
	if(matrix[x+1][y-1]=='#'){
                matrix[x+1][y-1]='+';
        }
	if(matrix[x-1][y+1]=='#'){
                matrix[x-1][y+1]='+';
        }

}

char GANO(char** matrix){
	int cont_player1=0;
	int cont_player2=0;
	for(int i = 0 ; i < 11 ; i++){
		for(int b = 0 ; i < 11 ; i++){
			if(matrix[i][b]=='#'){
				cont_player1++;
			}
			if(matrix[i][b]=='+'){
                                cont_player2++;
                        }

		}
	}
	char winner;
	if(cont_player1>cont_player2){
		winner = '1';
	}
	if(cont_player2>cont_player1){
		winner = '2';
	}
	if(cont_player2==cont_player1){
		winner = '3';
	}
	return winner;
}

char EMPATE(char** matrix){
	int cont=0;
	for(int i = 0 ; i < 11 ; i++){
		for(int b = 0 ; b < 11; b++){
			if(matrix[i][b]=='*'){
				cont++;
			}
		}
	}
	char empate;
	if(cont>0){
		empate='f';
	}
	if(cont==0){
		empate='t';
	}
	return empate;
}
