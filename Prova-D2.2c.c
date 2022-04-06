// Antonio Macena

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
  int i, j, k, m, numeros[11], letras[11], nav1A=1, nav1B=1, nav1C=1, nav1D=1, nav2A=1, nav2B=1, nav2C=1, nav2D=1;

  int h=65, v=49, frota1[7][2], frota2[7][2], p=0, w=0;
  char cenario[12][12];

  time_t t;
  srand((unsigned) time(&t));
  

  //======================<--Iniciando o terreno 11*11 com blocos vazios.
  for(k=0;k<11;k++){
    numeros[k]=v; v+=1;
    letras[k]=h; h+=1;
  }

  for(i=1;i<12;i++){
    for(j=1;j<12;j++){
      cenario[i][j]='.';
    }
  }
  for(k=1;k<12;k++){
    for(m=1;m<12;m++){
      cenario[0][k]=numeros[k-1];
      cenario[k][0]=letras[k-1];
    }
  }

  //===========================<---Distribuindo Embarcações e coletando posições.
    while(nav2D>0){                    //   @ para embarcações de 1 bloco
                                       //  ## para  embarcações de 2 blocos horizontais
    i = (rand() % 11)+1;               //   %  
    j = (rand() % 11)+1;               //  %   para  embarcações de 2 blocos diagonais a direita
    if(i==0){continue;}                //  &
    if(j==0){continue;}                //    & para  embarcações de 2 blocos diagonais a esquerda
    if(i-1==0){continue;} //evitar coordenadas fora do campo
    if(j-1==0){continue;}
    if(i+1>11){continue;}
    if(j+1>11){continue;}
    if(cenario[i][j]!='.'){continue;}  //<--- Evitar sobrescreve
    if(nav1A>0){cenario[i][j]='@';nav1A--;frota1[p][0]=i;frota1[p][1]=j; p++; continue;}
    if(nav2A>0){cenario[i][j]='@';nav2A--;frota2[w][0]=i;frota2[w][1]=j; w++;continue;}
    if(nav1B>0&&cenario[i][j+1]=='.'){cenario[i][j]='#';cenario[i][j+1]='#';nav1B--;
        frota1[p][0]=i;frota1[p][1]=j; p++; frota1[p][0]=i;frota1[p][1]=j+1; p++;continue;
    }
    if(nav1B>0&&cenario[i][j-1]=='.'){cenario[i][j]='#';cenario[i][j-1]='#';nav1B--;
        frota1[p][0]=i;frota1[p][1]=j; p++; frota1[p][0]=i;frota1[p][1]=j-1; p++;continue;
    }
    if(nav2B>0&&cenario[i][j+1]=='.'){cenario[i][j]='#';cenario[i][j+1]='#';nav2B--;
        frota2[w][0]=i;frota2[w][1]=j; w++; frota2[w][0]=i;frota2[w][1]=j+1; w++;continue;
    }
    if(nav2B>0&&cenario[i][j-1]=='.'){cenario[i][j]='#';cenario[i][j-1]='#';nav2B--;
        frota2[w][0]=i;frota2[w][1]=j; w++; frota2[w][0]=i;frota2[w][1]=j-1; w++;continue;
    }
    if(nav1C>0&&cenario[i-1][j+1]=='.'){cenario[i][j]='%';cenario[i-1][j+1]='%';nav1C--;
        frota1[p][0]=i;frota1[p][1]=j; p++; frota1[p][0]=i-1;frota1[p][1]=j+1; p++;continue;
    }
    if(nav2C>0&&cenario[i-1][j+1]=='.'){cenario[i][j]='%';cenario[i-1][j+1]='%';nav2C--;
        frota2[w][0]=i;frota2[w][1]=j; w++; frota2[w][0]=i-1;frota2[w][1]=j+1; w++;continue;
    }
    if(nav1D>0&&cenario[i-1][j-1]=='.'){cenario[i][j]='&';cenario[i-1][j-1]='&';nav1D--;
        frota1[p][0]=i;frota1[p][1]=j; p++; frota1[p][0]=i-1;frota1[p][1]=j-1; p++;continue;
    }
    if(nav2D>0&&cenario[i-1][j-1]=='.'){cenario[i][j]='&';cenario[i-1][j-1]='&';nav2D--;
        frota2[w][0]=i;frota2[w][1]=j; w++; frota2[w][0]=i-1;frota2[w][1]=j-1; w++;continue;
    }  
    }

    //====================criando tela para cada jogador.

    char tela1[12][12], tela2[12][12];

    for(k=0; k<12;k++){
      for(m=0;m<12;m++){
        tela1[k][m]=cenario[k][m];
        tela2[k][m]=cenario[k][m];
      }
    }
    for(k=0; k<7;k++){
      tela1[frota2[k][0]][frota2[k][1]]='.';
      tela2[frota1[k][0]][frota1[k][1]]='.';
    }

    //==============Inicio do Jogo

    int b1, n1, ind1, ind2, jogador1=4, jogador2=4, vez=1;
    char temp, temp1;

    while(jogador1>0&&jogador2>0){

      printf("\t\t\t\t BATALHA NAVAL \n\n\n");
      printf("\t\t\tTela do jogador %i\n\n\n", vez);

      //==============Impressão das telas de cada jogador
      for(i=0; i<12;i++){
        for(j=0;j<12;j++){
          if(vez==1){
            if(tela1[i][j]==':'){printf("10\t");continue;}
            if(tela1[i][j]==';'){printf("11\t");continue;}
            printf("%c\t", tela1[i][j]);
          }
          else{
            if(tela2[i][j]==':'){printf("10\t");continue;}
            if(tela2[i][j]==';'){printf("11\t");continue;}
            printf("%c\t", tela2[i][j]);
          }
        }
        printf("\n");
      }
      printf("\nJogador %i Digite as Coordenadas para o ataque:", vez);
      scanf("%c%i", &temp,&n1);
      getchar();
      temp1 = toupper(temp); //=============< ajustar para o caso de letras minusculas
      if(temp1=='A'){b1=1;}else if(temp1=='B'){b1=2;}else if(temp1=='C'){b1=3;}else if(temp1=='D'){b1=4;}else if(temp1=='E'){b1=5;}
      else if(temp1=='F'){b1=6;}else if(temp1=='G'){b1=7;}else if(temp1=='H'){b1=8;}else if(temp1=='I'){b1=9;}else if(temp1=='J'){b1=10;}
      else if(temp1=='K'){b1=11;}
      ind1=-1;
      ind2=-1;
      //==================Teste de acerto de ataques
      for(k=0;k<7;k++){
        if(frota2[k][0]==b1&&frota2[k][1]==n1){jogador2--; ind2=k; break;}
        if(frota1[k][0]==b1&&frota1[k][1]==n1){jogador1--; ind1=k; break;}
      }

      if(ind1==-1&&ind2==-1){printf("\n\t\t\tNao houve Destruicao.\n\n");}
      if((ind2!=-1&&vez==1)||(ind1!=-1&&vez==2)){printf("\n\t\tEmbarcacao inimiga destruida!\n\n");}
      if((ind2!=-1&&vez==2)||(ind1!=-1&&vez==1)){printf("\n\t\tErro. Propria navegacao destruida!\n\n");}

      //============atualização das telas
      if(ind1!=-1){
        if(ind1==0){tela1[frota1[0][0]][frota1[0][1]]='.';}
        if(ind1==1||ind1==2){tela1[frota1[1][0]][frota1[1][1]]='.';tela1[frota1[2][0]][frota1[2][1]]='.';}
        if(ind1==3||ind1==4){tela1[frota1[3][0]][frota1[3][1]]='.';tela1[frota1[4][0]][frota1[4][1]]='.';}
        if(ind1==5||ind1==6){tela1[frota1[5][0]][frota1[5][1]]='.';tela1[frota1[6][0]][frota1[6][1]]='.';}
      }
      if(ind2!=-1){
        if(ind2==0){tela2[frota2[0][0]][frota2[0][1]]='.';}
        if(ind2==1||ind2==2){tela2[frota2[1][0]][frota2[1][1]]='.';tela2[frota2[2][0]][frota2[2][1]]='.';}
        if(ind2==3||ind2==4){tela2[frota2[3][0]][frota2[3][1]]='.';tela2[frota2[4][0]][frota2[4][1]]='.';}
        if(ind2==5||ind2==6){tela2[frota2[5][0]][frota2[5][1]]='.';tela2[frota2[6][0]][frota2[6][1]]='.';}
      }
      if(vez==1){vez=2;}else{vez=1;}

      }
      if(jogador1>0){printf("\nJogador 1 Venceu!");}else{printf("\nJogador 2 Venceu!");}
    
    return 0;
  }