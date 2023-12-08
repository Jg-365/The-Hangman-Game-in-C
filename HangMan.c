#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void menu() {

		printf("\
            ___     ___       ________      ____  ____    ___      ___  \n\
           |###    |###      |########     |#### |####   |###     |###  \n\
            |###  |###       |########      |##   |##     |##     |##   \n\
            |####|####       |##            |#### |##     |##     |##   \n\
            |## ###|##       |########      |##|##|##     |##     |##   \n\
            |##  # |##       |########      |## |####     |##     |##   \n\
            |##    |##       |##            |##  |###     |##     |##   \n\
            |##    |##       |########      |##   |##      |##   |##    \n\
           |####  |####      |########     |#### |####      |######     \n\
           -------------------------------------------------------------\n\
                   Aperte enter para iniciar o jogo da Forca: \n\
           -------------------------------------------------------------\n");


    getchar();
}

/*As palavras do arquivo de texto s�o extra�das e registradas numa matriz[100][100].*/
void registro_palavras(char matriz[][100]) {
    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");/*Abertura do arquivo.*/

    if (arquivo == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo.\n");
    }

    int numPalavras = 0;
    while (numPalavras < 100 && fscanf(arquivo, "%s", matriz[numPalavras]) == 1) {
        numPalavras++;
    }

    fclose(arquivo);
    
    return;
}
  
/*fun��o de sorteio.*/
int sorteio(){
	srand(time(NULL));
	int a = rand()%100;
	return a;
}

/*Fun��o que substitui a dica pelas letras acertadas nas devidas posi��es.*/
void subst(char word[], const char letrasAcertadas[],char dica[100]) {
    int size = strlen(word),i;
    for (i = 0; i <= size; i++) {
		if (word[i] != ' ' && strchr(letrasAcertadas, word[i]) == NULL) {
			dica[i]='_';
        } else {
            dica[i]=word[i];
        }
    }
    printf("Palavra: %s\n",dica);
}

/*Fun��o que verifica apenas se o usu�rio acertou ou errou a letra, me retornando ao final.*/
 int verify(char a,const char b[]){
	int c, j, size;
    size = strlen(b);
    for (c = 0; c < size; c++) {
        if (a == b[c]) {
            j=1;
            break;
        }
        else{
        	j=0;
		}
    }
    return j;
}

/*Fun��o que retorna uma string com as devidas posi��es das letras digitadas corretamente.*/
char* rastreador_pos(char digitado, const char palavraOriginal[],int numAcertos) {
    int size = strlen(palavraOriginal);
    int i = 0;
    char* pos = malloc((size + 1) * sizeof(char));

    for (i = 0; i < size; i++) {
        if (digitado == palavraOriginal[i]) {
            pos[numAcertos] = i;
            numAcertos++;
        }
    }

    pos[numAcertos] = '\0';
    pos = realloc(pos, (numAcertos + 1) * sizeof(char));

    return pos;
}

/*Fun��o de limpeza de p�gina.*/
void close(){     
    system("cls"); 
}

/*Fun��o de apresenta��o dos cen�rios poss�veis no jogo.*/
void letreiro(int num){
  if(num==6){
	printf("------------------------------------------------------------\n");
	printf("              VOCE TEM %d CHANCES DE ACERTAR!                \n",num);
	printf("------------------------------------------------------------\n");
    }
    else if(num<6 && num>0){
   	printf("------------------------------------------------------------\n");
	printf("                   RESTAM %d CHANCES.                        \n",num);
	printf("------------------------------------------------------------\n");
	}
}

/*Fun��o especifica para o caso de derrota do usuario.*/
void perdedor(const char a[]){
	int i;
	char palavra_upper[strlen(a) + 1];
    
    for (i = 0; i < strlen(a); i++) {
        palavra_upper[i] = toupper(a[i]);
    }
    palavra_upper[i] = '\0';
    
    printf("------------------------------------------------------------\n");
    printf("        VOCE ERROU =( A PALAVRA ERA %s!            \n", palavra_upper);
    printf("------------------------------------------------------------\n");
}

/*Fun��o especifica para o caso vencedor.*/
void vencedor(const char a[]) {
    int i;
    char palavra_upper[strlen(a) + 1];
    
    for (i = 0; i < strlen(a); i++) {
        palavra_upper[i] = toupper(a[i]);
    }
    palavra_upper[i] = '\0';
    
    printf("------------------------------------------------------------\n");
    printf("        PARABENS! VOCE ACERTOU! A PALAVRA ERA %s!            \n", palavra_upper);
    printf("------------------------------------------------------------\n");
    printf("                                                           \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                      o  #      #  o                       \n");
    printf("                       #  ######  #                        \n");
    printf("                        #   ##   #                         \n");
    printf("                         #  ##  #                           \n");
    printf("                           ####                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                           #  #                              \n");
    printf("                          #    #                            \n");
    printf("                         #      #                           \n");
    printf("                        #        #                          \n");
    printf("                       o          o                         \n");
}

/*Fun��o do boneco mostrado em casos de jogo.*/
void boneco(int num){
	
	switch(num){
    case 0:
    printf("#################################                           \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  X  X  #                          \n");
    printf("                        #   __   #                          \n");
    printf("                        #  /  \\  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ####                             \n");
    printf("                          # ## #                            \n");
    printf("                         #  ##  #                           \n");
    printf("                        #   ##   #                          \n");
    printf("                       o    ##    o                         \n");
    printf("                           #  #                             \n");
    printf("                          #    #                            \n");
    printf("                         #      #                           \n");
    printf("                        #        #                          \n");
    printf("                       o          o                         \n");
	break;
	
	case 1:
    printf("#################################                            \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ####                             \n");
    printf("                          # ## #                            \n");
    printf("                         #  ##  #                           \n");
    printf("                        #   ##   #                          \n");
    printf("                       o    ##    o                         \n");
    printf("                           #                               \n");
    printf("                          #                                \n");
    printf("                         #                                 \n");
    printf("                        #                                  \n");
    printf("                       o                                   \n");
	break;
	
	case 2:
    printf(" ################################                              \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ####                             \n");
    printf("                          # ## #                            \n");
    printf("                         #  ##  #                           \n");
    printf("                        #   ##   #                          \n");
    printf("                       o    ##    o                         \n\n\n\n\n\n");
   
    break;
    
    case 3:
    printf(" ################################                              \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ###                             \n");
    printf("                          # ##                             \n");
    printf("                         #  ##                             \n");
    printf("                        #   ##                             \n");
    printf("                       o    ##                             \n\n\n\n\n\n");
    	
    break;
    
    case 4:
    printf(" ################################                              \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n\n\n\n\n\n");
    
	break;
	
	case 5:
	printf(" ################################                           \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                         \n");
    printf("                         #      #                           \n");
    printf("                          ######    \n\n\n\n\n\n\n\n\n\n\n\n\n");
    
	
	break;
	
	case 6:
	printf(" ################################                           \n");
    printf("                            ##                              \n"); 
    printf("                            ##      \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    	
	break;	
}
}

/*Mecanismos do jogo propriamente dito.*/
void jogo_da_forca() {
    char forca[100][100];
    int palavra;

    registro_palavras(forca);
    palavra = sorteio();

    close();
  
    int tamanho = strlen(forca[palavra]), k;
    int chances = 6, numAcertos = 0, tentativas = 0, repeticao = 0, acertou_errou = 0;
    char certas[tamanho], tentadas[26], digitado,segredo[100];
    
    memset(certas, 0, sizeof(certas));
    
    while (chances > 0) {
         if (repeticao == 0) {
    	/*Parte Ilustrativa:*/
        letreiro(chances);                               /* >Aqui, � chamado o letreiro que informa as chances restantes do jogador. */
        boneco(chances);                                 /* >Aqui, � chamado o boneco que ilustra a situa��o atual em fun�a�o do numero de chances. */
        
                                    
            if (acertou_errou == 1) {                    /* >Aqui s�o mostradas informa��es para que, apenas se n�o. */
                printf("Voce acertou a letra!\n");       /*  existirem repeti��es, o jogador seja informado da sua situa��o. */
                printf("As letras tentadas foram: ");
                for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n\n");
            } else if (acertou_errou == 0 && chances == 6) {
                for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n\n");
            } else {
                printf("Voce errou a letra. Tente outra vez.\n");
                printf("As letras tentadas foram: ");
                for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n\n");
            }	
                                                            
        } else {
		    close();  
		    letreiro(chances);
			boneco(chances);                      /* >Caso contr�rio, ser� informado, que a letra digitada, foi repetida.*/
			printf("As letras tentadas foram: ");
			for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n");
            printf("A letra ja foi tentada previamente, digite outra.\n\n");
        }
        
        /*Parte de substitui��o de letras nas devidas posi��es*/
        subst(forca[palavra],certas, segredo);
        
        /*Caso de vit�ria: */
        if (strcmp(segredo,forca[palavra])==0) {
        close();
        vencedor(forca[palavra]);
        break;
       }
        
        /*Aqui o usu�rio interage com a m�quina, digitando uma letra do alfabeto*/
        printf("Digite uma letra: \n");
        scanf(" %c", &digitado);
        
        /*Parte de l�gica condicional do programa*/
        repeticao = 0;                             /* >O jogo precisa come�ar com essa atribui��o para garantir que se uma letra digitada */
                                                   /*  for repetida, essa condi��o n�o seja passada para a pr�xima letra. */
        int z; /*Vari�vel de itera��o*/
		for (z = 0; z < tentativas; z++) {         /* >Aqui � executado um loop procurando nas letras tentadas, uma repeti��o. */
            if (digitado == tentadas[z]) {         /* >Se esse for o caso, atribui-se 1, � vari�vel "Repeticao" e o loop quebra.*/
                repeticao = 1;                     /* >Se n�o for, a vari�vel continua zero, e, portanto, a mec�nica flui. */ 
                break;
            }
        }
        
        if (repeticao == 1) {                      /* >Se houver repeti��o, � chamada uma fun��o de limpeza de p�gina e o loop reinicia. */
            close;
            continue;
        }

        tentadas[tentativas] = digitado;           /* >Em n�o ocorrendo repeti��o, invariavelmente o loop atribui a letra digitada a uma */
        tentativas++;                              /*  posi��o correspondente ao n�mero de tentativas at� o momento do vetor "tentadas". */

		char* posicoes = rastreador_pos(digitado, forca[palavra],numAcertos); /* >Em seguida � chamada a fun��o de rastreio de posi��o, retornando um */
        acertou_errou = verify(digitado, forca[palavra]);   /* >Aqui � verificado qual o status da letra, se certa ou se errada. */                                                                   /*  char posi��es que possui as posi��es das letras digitas corretamente*/

        if (acertou_errou == 1) {
        int i, j;
         for (i = 0, j = 0; i < tamanho; i++) {            /* >Itera-se a condi��o para que as letras digitadas corretamente */       
            if (i == posicoes[j]) {                        /*  sejam colocadas na string "certas" de maneira que � medida que */
                char letra[2] = { digitado, '\0' };        /*  a posic�o i, seja condizente com a posi��o da letra correta */
                strcat(certas, letra);                     /*  dentro da string "posicoes". */
                j++;
                }
            }
        }                                                   
    
		else {
          chances--;                                        /* >Aqui se aplica uma condi��o, para que, o jogador, perca chances, */
        }                                                   /*  caso nenhuma condi��o for satisfeita.*/
      close();
}
    
    /*Caso espec�fico de derrota:*/
    if (chances == 0) {
        perdedor(forca[palavra]);
        boneco(0);
    }
}

/*Execu��o do c�digo em forma de fun��es organizadas previamente.*/
int main(){
	char ctn;
    int i;
    
    menu();  /*Abertura do Menu.*/
	 
    for(i=0;i<1;i++){
    jogo_da_forca(); /* >O jogo � chamado*/
      
    int j;
	for(j=0;j<1;j++){
    printf("\nDeseja continuar jogando?(s/n)");/* >Intera��o com o usu�rio para loop de continuidade.*/
    scanf(" %c",&ctn);
    
    if(ctn=='s'){   /* >Loop para interagir com o usu�rio para a continua��o ou n�o do jogo. */
    i--;	
    }
    else if(ctn!='s' && ctn!='n') {
  	close();
    printf("Letra invalida. Apenas s ou n.");
	j--;	
	}  
	else{
		system("exit");
	}
  }
}
    return 0;
}
