
#include <stdio.h>
#include <stdlib.h>
int arrGolpesDoMonstro[10];
int arrGolpesDoHeroi[10];
int golpeDoheroi, golpeDoMonstro;
int x,i;
int perdeu = 0;
int blMonstro = 0;
int pocaoDoTempo=1;
int repetirNumero=0;
int main(){
system("cls");
	printf("\n\t\t\tbem vindo bravo guerreiro! \n\n\t voce tem 10 batalhas contra inimigos inimaginaveis pela frente!\n\tderrote-os com um so golpe!\n");
	printf("\n\n em cada batalha voce deve escolher um numero de 1 a 10 para dar o seu golpe \n mas nunca use o mesmo numero 2 vezes!\n");
	printf("\n boa sorte, e conquiste a gloria!!!\n");

	for (i = 0; i < 10; i++){

		printf("\n --golpes do monstro:");
		for(x=0;x<=i;x++){
			printf("  [%d] ",arrGolpesDoMonstro[x]);
		}

		printf("\n --seus golpes:      ");
		for(x=0;x<=i;x++){

			printf("  [%d] ",arrGolpesDoHeroi[x]);
		}
		printf("\n --pocao do tempo:     [%d] (permite voltar no tempo e evitar a derrota)",pocaoDoTempo);		
		printf("\n --pocao da repeticao: [%d] (permite reperir um golpe)",repetirNumero);
		printf("\n \n\t\t\tmonstro %d : de seu melhor golpe!\n",i+1);
		
	    scanf_s("%d",&golpeDoheroi);
	    system("cls");
	    //checa se o golpe está entre 1 e 10
	    if(golpeDoheroi>0&&golpeDoheroi<=10){
	    	//checa se o golpe ja foi dado
		    for(x=0;x<=i;x++){
		    	if(golpeDoheroi == arrGolpesDoHeroi[x]){
		    		if(repetirNumero){
		    			printf("\n utilizada \"pocao da repeticao\" tenha cuidado!\n");	
		    			repetirNumero = repetirNumero-1;
		    			perdeu= 0;
		    			break;		    		
		    		}
		    		else{
			    		printf("\n golpe repetido!\n");
			    		perdeu= 1;
		    			break;
		    		}
		    	}
		    }
		    if(perdeu){

		    	break;
		    }
		    //grava o golpe do heroi
		    		arrGolpesDoHeroi[i]=golpeDoheroi;
		    	 blMonstro =0;  
		    while(!blMonstro){
		    	srand(time(NULL));
		    	golpeDoMonstro = (rand() % 100 +10) / 10;//numero aleatório de 1 a 10
	    		for(x=0;x<=i;x++){
	    			rand();
	    			if(golpeDoMonstro == arrGolpesDoMonstro[x]){
	    				blMonstro =0;
	    				break;
	    			}
	    			blMonstro =1;
	    		}		    		
		    }
		    arrGolpesDoMonstro[i]=golpeDoMonstro;
		    if(golpeDoheroi>golpeDoMonstro){//vitória

		    	printf("\n \tVoce trouxe honra aos seus ancestrais!! \n\t\t\t Vitoria!!!! \n\n\t seu golpe: %d golpe do monstro: %d \n",golpeDoheroi,golpeDoMonstro);
		    	if(i+1 ==5|| i+1==7){
		    		printf("\n o monstro deixou cair uma das armas do seu arsenal!\n agora voce pode repetir um numero!\n");
		    		repetirNumero = repetirNumero+1;
		    	}
		    }
		    else{
				if (golpeDoheroi == golpeDoMonstro){//empate
					printf("\napos uma ardua batalha o inimigo fugiu com vida!\n seu golpe:%d golpe do monstro: %d \n", golpeDoheroi, golpeDoMonstro);
					if (i + 1 == 5 || i + 1 == 1){
						printf("\n o monstro deixou cair uma das armas do seu arsenal!\n agora voce pode repetir um numero!\n");
						repetirNumero = repetirNumero + 1;
					}
					else{
						pocaoDoTempo = pocaoDoTempo + 1;
						printf("\n o monstro deixou cair uma poção do tempo!! \n agora voce tem %d.", pocaoDoTempo);


					}

				}
		    	else{//derrota
		    		printf("\nderrota vergonhosa :(\n seu golpe:%d golpe do monstro: %d \n",golpeDoheroi,golpeDoMonstro);
		    			if(pocaoDoTempo){
		    				printf("\n o destino te deu uma nova chance! \n ativar pocao no tempo!");
		    				arrGolpesDoHeroi[i]=0;
		    				arrGolpesDoMonstro[i] = 0;
		    				i--;
		    				pocaoDoTempo = pocaoDoTempo-1;
		    				perdeu = 0;
		    			}
		    			else{
		   					perdeu = 1;
		   				}
		   		}
		    }
		}
		else{

			printf("\ngolpe invaldo!\n");
			if(pocaoDoTempo){
				printf("\n o destino te deu uma nova chance! \n ativar pocao no tempo!");
				arrGolpesDoHeroi[i]=0;
				arrGolpesDoMonstro[i] = 0;
				i = i-1;
				pocaoDoTempo = pocaoDoTempo-1;
				perdeu = 0;
			}
			else{
					perdeu = 1;
					break;
				}
			
		}
		//sai do loop em caso de derrota
		if(perdeu){
			break;
		}


	}
	// exibe o resultado da batalha
	if(perdeu){
		printf("\nvoce perdeu\n");
	}
	else{
		//todo: salvar os feitos do heroi em "todaEternidade.txt"
		printf("\nparabens guerreiro!\nvoce venceu!\n seus feitos serao lembrados por toda a eternidade!!!");
	}
	system("pause");
return 0;
}
