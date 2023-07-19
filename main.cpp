/*     __                         ______                       _
      / /___  _________ ____     / ____/___  __  ___   _____  (_)___ _
 __  / / __ \/ ___/ __ `/ _ \   / / __/ __ \/ / / / | / / _ \/ / __ `/
/ /_/ / /_/ / /  / /_/ /  __/  / /_/ / /_/ / /_/ /| |/ /  __/ / /_/ /
\____/\____/_/   \__, /\___/   \____/\____/\__,_/ |___/\___/_/\__,_/
	        	    /____/      21093 - Programação por Objetos @ UAb 


** file: main.cpp
**
** UC: 21093 - Programação por Objetos @ UAb
** e-fólio Global Recruso: 17-07-2032
**
** Aluno: 2003777 - Jorge Gouveia
*/

//**** Includes ****//
#include "main.h"
#include "vinho.h"
#include "adega.h"
//**** Protótipos Funções ****// 

int main(){

vector<Adega> adegas;
vector<Vinho> vinhos;
// **** Crair vinhos e adegas ****//
vinhos.push_back(Vinho());
vinhos[0].setNome("Vinho 1");
vinhos[0].setTipo("Tinto");
vinhos[0].setCastas({"Casta 1", "Casta 2"});
vinhos[0].setTipoRefeicao({"Peixe", "Queijo"});
vinhos[0].setVolume(14);

vinhos.push_back(Vinho());
vinhos[1].setNome("Vinho 2");
vinhos[1].setTipo("Verde");
vinhos[1].setCastas({"Casta 3", "Casta 4"});
vinhos[1].setTipoRefeicao({"Carne", "Peixe"});
vinhos[1].setVolume(11);

vinhos.push_back(Vinho());
vinhos[2].setNome("Vinho 3");
vinhos[2].setTipo("Branco");
vinhos[2].setCastas({"Casta 5", "Casta 6"});
vinhos[2].setTipoRefeicao({"Carne", "Fruta"});
vinhos[2].setVolume(11);

vinhos.push_back(Vinho());
vinhos[3].setNome("Vinho 4");
vinhos[3].setTipo("Rose");
vinhos[3].setCastas({"Casta 7", "Casta 8"});
vinhos[3].setTipoRefeicao({"Peixe", "Queijo"});
vinhos[3].setVolume(12);

adegas.push_back(Adega());
adegas[0].setNome("Adega 1");
adegas[0].setLocalidade("Porto");
adegas[0].setPais("Portugal");
adegas[0].setPaginaWeb("www.adega1.pt");
adegas[0].adicionarVinho({vinhos[0], vinhos[1]});    

adegas.push_back(Adega());
adegas[1].setNome("Adega 2");
adegas[1].setLocalidade("Lisboa");
adegas[1].setPais("Portugal");
adegas[1].setPaginaWeb("www.adegadeLisboa.pt");
adegas[1].adicionarVinho({vinhos[2], vinhos[3]});  

//**** Imprimir Adegas e Vinhos ****//
adegas[0].imprimirAdega();
adegas[0].mediaVolumeTipo("Tinto");
adegas[0].mediaVolume();

cout<<endl;


adegas[1].imprimirAdega();
adegas[1].mediaVolumeTipo("Branco");
adegas[1].mediaVolume();

cout<<"\n*** Media Total de todos os vinhos ***"<<endl;
adegas[0].mediaVolumeTodasAdegas(adegas);
    
cout<<endl;
adegas[0].vinhosCom(adegas, "Peixe");
adegas[0].vinhosCom(adegas, "Carne");
adegas[0].vinhosCom(adegas, "Queijo");
adegas[0].vinhosCom(adegas, "Fruta");  
    
return 0;
}
