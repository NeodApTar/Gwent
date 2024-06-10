#include <SDL_ttf.h>
#include <SDL.h>
#include <cstdio>
#include <windows.h>
#include <locale.h>
#include <ctime>
#include <SDL_image.h>
#include "font.h"
#include "LeaderBoard.h"
#pragma warning(disable : 4996) // для отключения предупреждения в стр 17-20
int dost; int mast;
int flag1 = 0;
int FirstHod = 1;
int RisovkaW = 0, RisovkaH = 0;
int Hod;
int bito=0;
int vzyat=0;
int FORXODI[6];
int DLYAOT[6];
int FirstXOD;
int LeaderBoard[5];
int kozmast = 0;
int PerviyXod = 1;
int BETT = 0;
int ANSWW = 0;
int Round = 0;
int perviy[36];
int vtoroy[36];
int firstXodInRound;
int journal[3][36];
int flagggg = 0;
SDL_Rect LastKardr = { 1500,400,64,96 };
 
int flag = 0;

int kolod = -1;


int space = 0;



int Vkid = 0;
int game = 0;
int Kolodaa[36];
int Bet = 0;
//Некоторые константы нашего окна
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int UIGROKA[36] = { (-1) };
int mka[4][9];
int nka[4][9];
int flagg1 = 0;


struct gweent
{
	int power, position;
	int koloda;
	//int medicflag;
	int Kard;
	SDL_Rect karta;
	int Uigroka;
	int Bito;
	SDL_Texture* texture;
	int nomerKarti = -100;
	int notshpion = -10;

};

gweent Gweent[114];

SDL_Rect RISKart[4][9] = { 100,600,48,64 };
SDL_Rect STOL = { 0,0,1920,1080 };


int Vkolode = 24;

SDL_Texture* KART[4][9];
SDL_Texture* KART1[36];
SDL_Rect RISKart1[36];
SDL_Rect RISKartt1[36];
SDL_Rect KARDXOD[6];
SDL_Rect KARDBET[6];

SDL_Rect OBLAST = { 200,200,900,300 };



SDL_Texture* monsterTex[17];
SDL_Texture* neutralTex[15];
SDL_Texture* northernTex[18];
SDL_Texture* nilfgaardianTex[18];
SDL_Texture* scoiataelTex[18];



SDL_Rect monsterR[16];
SDL_Rect neutralR[15];
SDL_Rect northernR[16];
SDL_Rect nilfgaardianR[18];
SDL_Rect scoiataelR[18];

gweent player1;

int v = 0;

struct uroven
{
	SDL_Rect uroven;
	int nomerKarti = -100;
	 
};

uroven uroven1[15];
uroven uroven2[15];
uroven uroven3[15];
uroven urovenDlyaPogodi[7];

uroven urovenVraga1[15];
uroven urovenVraga2[15];
uroven urovenVraga3[15];

uroven urovenplayer[15];

uroven truba[6];

void urovenn(SDL_Renderer* renderer)
{
	for (int i = 0; i < 15; i++)
	{


		uroven1[i].uroven.x = 700+i*60;
		uroven1[i].uroven.y = 700;
		uroven1[i].uroven.w = 60;
		uroven1[i].uroven.h = 100;
		

	}
	for (int i = 0; i < 15; i++)
	{


		uroven2[i].uroven.x = 700 + i * 60;
		uroven2[i].uroven.y = 580;
		uroven2[i].uroven.w = 60;
		uroven2[i].uroven.h = 100;


	}
	for (int i = 0; i < 15; i++)
	{


		uroven3[i].uroven.x = 700 + i * 60;
		uroven3[i].uroven.y = 430;
		uroven3[i].uroven.w = 60;
		uroven3[i].uroven.h = 100;


	}
	for (int i = 0; i < 15; i++)
	{


		urovenVraga1[i].uroven.x = 700 + i * 60;
		urovenVraga1[i].uroven.y = 30;
		urovenVraga1[i].uroven.w = 60;
		urovenVraga1[i].uroven.h = 100;


	}
	for (int i = 0; i < 15; i++)
	{


		urovenVraga2[i].uroven.x = 700 + i * 60;
		urovenVraga2[i].uroven.y = 160;
		urovenVraga2[i].uroven.w = 60;
		urovenVraga2[i].uroven.h = 100;


	}
	
	for (int i = 0; i < 15; i++)
	{


		urovenVraga3[i].uroven.x = 700 + i * 60;
		urovenVraga3[i].uroven.y = 280;
		urovenVraga3[i].uroven.w = 60;
		urovenVraga3[i].uroven.h = 100;


	}
	for (int i = 0; i < 7; i++)
	{


		urovenDlyaPogodi[i].uroven.x = 140 + i * 40;
		urovenDlyaPogodi[i].uroven.y = 480;
		urovenDlyaPogodi[i].uroven.w = 40;
		urovenDlyaPogodi[i].uroven.h = 60;


	}
	for (int i = 0; i < 15; i++)
	{


		urovenplayer[i].uroven.x = 570 + i * 65;
		urovenplayer[i].uroven.y = 850;
		urovenplayer[i].uroven.w = 70;
		urovenplayer[i].uroven.h = 150;


	}
	for (int i = 0; i < 6; i++)
	{


		truba[i].uroven.x = 600;
		truba[i].uroven.y = 10 + i * 140  ;
		truba[i].uroven.w = 100;
		truba[i].uroven.h = 100;


	}
	/*while (true)
	{
		for (int i = 0; i < 6; i++)
		{
			SDL_RenderDrawRect(renderer, &truba[i].uroven);
		}
		SDL_RenderPresent(renderer);
	}*/
	
}

char const* nilfgaardian[] = {
"aux_archers1.png",
"aux_archers2.png",
"black_infantry_archer1.png",
"black_infantry_archer2.png",
"eggebracht.png",
//"emhyr_white.png",
"fire_scorpion1.png",
"fire_scorpion2.png",
"heavy_fire_scorpion.png",
"letho.png",



"menno.png",
"shilard.png",
"siege_tech.png",
"stefan_skellen.png",
"vattier.png",
"voorhis.png",
"young_emissary1.png",
"young_emissary2.png",
//"avallach.png",
"ciri.png",
"dandelion.png",
"geralt.png",
"triss.png",
"yen.png",
"clear.png",

"decoy.png",
"decoy.png",
"decoy.png",
"fog.png",
"frost.png",
"rain.png",
"horn.png"





//"vesemir.png",
//"villentretenmerth.png",

//"zoltan.png"
};

char const* northern[] = {
"commando1.png",
"commando2.png",
"commando3.png",
"crinfrid1.png",
"crinfrid2.png",
"crinfrid3.png",
"dijkstra.png",
"eilhart.png",
"roche.png",
"stennis.png",
"thaler.png",
"thyssen.png",
"siegfried.png",
//"foltest_commander.png",
"dandelion.png",
"avallach.png",
"ciri.png",
"geralt.png",
"triss.png",
"yen.png",
"clear.png",

"decoy.png",
"decoy.png",
"fog.png",
"frost.png",
"rain.png",
"horn.png"





//"vesemir.png",
//"villentretenmerth.png",
//
//"zoltan.png"







};

char const* scoiatael[] = {
"eithne.png",
"fidhail.png",

"healer.png",
"healer2.png",
"iorveth.png",
"isengrim.png",
"milva.png",
"saesenthessis.png",



"scout1.png",
"scout2.png",
"scout3.png",
"sivney.png",
"skirmisher1.png",
"skirmisher2.png",
"smuggler1.png",
"smuggler2.png",
"smuggler3.png",




"ciri.png",
"geralt.png",
"dandelion.png",

"avallach.png",

"clear.png",
"decoy.png",
"decoy.png",
"fog.png",
"frost.png",
"rain.png",
"horn.png"





};

char const* monster[] = {
"arachas_behemoth.png",
"arachas1.png",
"arachas2.png",
"arachas3.png",
"crone_brewess.png",
"crone_weavess.png",
"crone_whispess.png",
"draug.png",
//"eredin_king.png",
"fiend.png",



"imlerith.png",
"kayran.png",
"leshen.png",
"vampire_bruxa.png",
"vampire_ekimmara.png",
"vampire_fleder.png",
"vampire_garkain.png",





"avallach.png",
"ciri.png",
"dandelion.png",
"geralt.png",
"vesemir.png",
"zoltan.png",
"villentretenmerth.png",
"clear.png",

//"decoy.png",
"fog.png",
"frost.png",
"rain.png",
"horn.png"




//"triss.png",
//
//
//"yen.png",

};

SDL_Texture* CreateCard(SDL_Renderer* render, const char* cards)
{


	SDL_Surface* sur = IMG_Load(cards);
	return SDL_CreateTextureFromSurface(render, sur);
}

void Scoiatael(SDL_Renderer* renderer)
{
	//eithne
	Gweent[0].power = 10;
	Gweent[0].position = 2;
	Gweent[0].Kard = 0;

	//fidhail
	Gweent[1].power = 4;
	Gweent[1].position = 1;
	///////////////////////////////////////////////////
	Gweent[1].Kard = 2;

	//healer
	Gweent[2].power = 0;
	Gweent[2].position = 2;
	Gweent[2].Kard = 1;

	//healer2
	Gweent[3].power = 0;
	Gweent[3].position = 2;
	Gweent[3].Kard = 1;

	//iorveth
	Gweent[4].power = 5;
	Gweent[4].position = 2;
	Gweent[4].Kard = 0;

	//isengrim
	Gweent[5].power = 5;
	Gweent[5].position = 1;
	////////////////////////////////////////////////
	Gweent[5].Kard = 1;
	//milva
	Gweent[6].power = 4;
	Gweent[6].position = 2;
	Gweent[6].Kard = 1;
	/////////////////////////////////////////////////

	//saesenthessis
	Gweent[7].power = 10;
	Gweent[7].position = 2;
	Gweent[7].Kard = 0;
	//scout1
	Gweent[8].power = 6;
	Gweent[8].position = 1;
	Gweent[8].Kard = 2;
	//scout2
	Gweent[9].power = 6;
	Gweent[9].position = 1;
	Gweent[9].Kard = 2;
	//scout3
	Gweent[10].power = 6;
	Gweent[10].position = 1;
	Gweent[10].Kard = 2;
	//sivney
	Gweent[11].power = 6;
	Gweent[11].position = 2;
	Gweent[11].Kard = 0;
	//skirmisher1
	Gweent[12].power = 3;
	Gweent[12].position = 1;
	Gweent[12].Kard = 3;
	//skirmisher2
	Gweent[13].power = 3;
	Gweent[13].position = 1;
	Gweent[13].Kard = 3;
	//smuggler1
	Gweent[14].power = 5;
	Gweent[14].position = 1;
	Gweent[14].Kard = 3;
	//smuggler2
	Gweent[15].power = 2;
	Gweent[15].position = 1;
	Gweent[15].Kard = 3;
	//smuggler3
	Gweent[16].power = 5;
	Gweent[16].position = 1;
	Gweent[16].Kard = 3;
	//ciri
	Gweent[17].power = 15;
	Gweent[17].position = 1;
	Gweent[17].Kard = 0;
	//geralt
	Gweent[18].power = 15;
	Gweent[18].position = 1;
	Gweent[18].Kard = 0;
	//dandelion
	Gweent[19].power = 2;
	Gweent[19].position = 1;
	Gweent[19].Kard = 0;/////////////////////////////////////
	//avallach
	Gweent[20].power = 0;
	Gweent[20].position = -1;
	Gweent[20].Kard = 5;
	//clear
	Gweent[21].power = 0;
	Gweent[21].position = 4;
	Gweent[21].Kard = 6;
	//decoy
	Gweent[22].power = 0;
	Gweent[22].position = 0;
	Gweent[22].Kard = 7;
	//decoy
	Gweent[23].power = 6;
	Gweent[23].position = 3;
	Gweent[23].Kard = 7;
	//fog
	Gweent[24].power = 0;
	Gweent[24].position = 4;
	Gweent[24].Kard = 8;
	//frost
	Gweent[25].power = 0;
	Gweent[25].position = 4;
	Gweent[25].Kard = 9;
	//rain
	Gweent[26].power = 0;
	Gweent[26].position = 4;
	Gweent[26].Kard = 10;
	//horn
	Gweent[27].power = 0;
	Gweent[27].position = 5;
	Gweent[27].Kard = 4;
	for (int i = 0; i < 28; i++)
	{
		Gweent[i].koloda = 0;
		Gweent[i].texture = CreateCard(renderer, scoiatael[i]);
		Gweent[i].nomerKarti = i;
	}
}

void Northern(SDL_Renderer* renderer)
{
	int j = 0;
	for (int i = 28; i < 54; i++)
	{
		Gweent[i].koloda = 1;
		Gweent[i].texture = CreateCard(renderer, northern[j]);
		Gweent[i].nomerKarti = j;
		j++;
	}
	//commando1
	Gweent[28].power = 4;
	Gweent[28].position = 1;
	Gweent[28].Kard = 11;
	//commando2
	Gweent[29].power = 4;
	Gweent[29].position = 1;
	Gweent[29].Kard = 11;
	//commando3
	Gweent[30].power = 4;
	Gweent[30].position = 1;
	Gweent[30].Kard = 11;
	//crinfrid1
	Gweent[31].power = 5;
	Gweent[31].position = 2;
	Gweent[31].Kard = 11;
	//crinfrid2
	Gweent[32].power = 5;
	Gweent[32].position = 2;
	Gweent[32].Kard = 11;
	//crinfrid3
	Gweent[33].power = 5;
	Gweent[33].position = 2;
	Gweent[33].Kard = 11;
	//dijkstra
	Gweent[34].power = 4;
	Gweent[34].position = -1;
	Gweent[34].Kard = 5;

	//eilhart
	Gweent[35].power = 10;
	Gweent[35].position = 2;
	Gweent[35].Kard = 0;
	//roche
	Gweent[36].power = 10;
	Gweent[36].position = 1;
	Gweent[36].Kard = 0;
	//stennis
	Gweent[37].power = 5;
	Gweent[37].position = -1;
	Gweent[37].Kard = 5;
	//thaler
	Gweent[38].power = 1;
	Gweent[38].position = -3;
	Gweent[38].Kard = 5;
	//thyssen
	Gweent[39].power = 10;
	Gweent[39].position = 1;
	Gweent[39].Kard = 0;
	//siegfried
	Gweent[40].power = 5;
	Gweent[40].position = 1;
	Gweent[40].Kard = 0;
	//dandelion
	Gweent[41].power = 2;
	Gweent[41].position = 1;
	Gweent[41].Kard = 4;
	//avallach
	Gweent[42].power = 0;
	Gweent[42].position = -1;
	Gweent[42].Kard = 5;
	//ciri
	Gweent[43].power = 15;
	Gweent[43].position = 1;
	Gweent[43].Kard = 0;
	//geralt
	Gweent[44].power = 15;
	Gweent[44].position = 1;
	Gweent[44].Kard = 0;
	//triss
	Gweent[45].power = 7;
	Gweent[45].position = 1;
	Gweent[45].Kard = 0;
	//yen
	Gweent[46].power = 7;
	Gweent[46].position = 2;
	Gweent[46].Kard = 1;
	//clear
	Gweent[47].power = 0;
	Gweent[47].position = 4;
	Gweent[47].Kard = 6;
	//decoy
	Gweent[48].power = 0;
	Gweent[48].position = 0;
	Gweent[48].Kard = 7;
	//decoy
	Gweent[49].power = 0;
	Gweent[49].position = 0;
	Gweent[49].Kard = 7;
	//fog
	Gweent[50].power = 0;
	Gweent[50].position = 4;
	Gweent[50].Kard = 8;
	//frost
	Gweent[51].power = 0;
	Gweent[51].position = 4;
	Gweent[51].Kard = 9;
	//rain
	Gweent[52].power = 0;
	Gweent[52].position = 4;
	Gweent[52].Kard = 10;
	//horn
	Gweent[53].power = 0;
	Gweent[53].position = 5;
	Gweent[53].Kard = 4;
}

int fla = 0;

void Nilfgaardian(SDL_Renderer* renderer)
{
	int j = 0;
	for (int i = 54; i < 84; i++)
	{
		Gweent[i].koloda = 2;
		Gweent[i].texture = CreateCard(renderer, nilfgaardian[j]);
		Gweent[i].nomerKarti = j;
		j++;
		
	}
	//aux_archers1
	Gweent[54].power = 1;
	Gweent[54].position = 2;
	Gweent[54].Kard = 1;
	//aux_archers2
	Gweent[55].power = 1;
	Gweent[55].position = 2;
	Gweent[55].Kard = 1;
	//black_infantry_archer1
	Gweent[56].power = 10;
	Gweent[56].position = 2;
	Gweent[56].Kard = 0;
	//black_infantry_archer2
	Gweent[57].power = 10;
	Gweent[57].position = 2;
	Gweent[57].Kard = 0;
	//eggebracht
	Gweent[58].power = 10;
	Gweent[58].position = 2;
	Gweent[58].Kard = 0;
	//fire_scorpion1
	Gweent[59].power = 5;
	Gweent[59].position = 3;
	Gweent[59].Kard = 0;
	//fire_scorpion2
	Gweent[60].power = 5;
	Gweent[60].position = 3;
	Gweent[60].Kard = 0;
	//heavy_fire_scorpion
	Gweent[61].power = 10;
	Gweent[61].position = 3;
	Gweent[61].Kard = 0;
	//letho
	Gweent[62].power = 10;
	Gweent[62].position = 1;
	Gweent[62].Kard = 0;
	//menno
	Gweent[63].power = 10;
	Gweent[63].position = 1;
	Gweent[63].Kard = 1;
	//shilard
	Gweent[64].power = 7;
	Gweent[64].position = -1;
	Gweent[64].Kard = 5;
	//siege_tech
	Gweent[65].power = 0;
	Gweent[65].position = 3;
	Gweent[65].Kard = 1;
	//stefan_skellen
	Gweent[66].power = 9;
	Gweent[66].position = -1;
	Gweent[66].Kard = 5;
	//vattier
	Gweent[67].power = 4;
	Gweent[67].position = -1;
	Gweent[67].Kard = 5;
	//voorhis
	Gweent[68].power = 10;
	Gweent[68].position = 3;
	Gweent[68].Kard = 0;
	//young_emissary1
	Gweent[69].power = 5;
	Gweent[69].position = 1;
	Gweent[69].Kard = 11;
	//young_emissary2
	Gweent[70].power = 5;
	Gweent[70].position = 1;
	Gweent[70].Kard = 11;
	//ciri
	Gweent[71].power = 15;
	Gweent[71].position = 1;
	Gweent[71].Kard = 0;
	//dandelion
	Gweent[72].power = 2;
	Gweent[72].position = 1;
	Gweent[72].Kard = 4;
	//geralt
	Gweent[73].power = 15;
	Gweent[73].position = 1;
	Gweent[73].Kard = 0;
	//triss
	Gweent[74].power = 7;
	Gweent[74].position = 1;
	Gweent[74].Kard = 0;
	//yen
	Gweent[75].power = 7;
	Gweent[75].position = 2;
	Gweent[75].Kard = 1;
	//clear
	Gweent[76].power = 0;
	Gweent[76].position = 4;
	Gweent[76].Kard = 6;
	//decoy
	Gweent[77].power = 0;
	Gweent[77].position = 0;
	Gweent[77].Kard = 7;
	//decoy
	Gweent[78].power = 0;
	Gweent[78].position = 0;
	Gweent[78].Kard = 7;
	//decoy
	Gweent[79].power = 0;
	Gweent[79].position = 0;
	Gweent[79].Kard = 7;
	//fog
	Gweent[80].power = 0;
	Gweent[80].position = 4;
	Gweent[80].Kard = 8;
	//frost
	Gweent[81].power = 0;
	Gweent[81].position = 4;
	Gweent[81].Kard = 9;
	//rain
	Gweent[82].power = 0;
	Gweent[82].position = 4;
	Gweent[82].Kard = 10;
	//horn
	Gweent[83].power = 0;
	Gweent[83].position = 5;
	Gweent[83].Kard = 4;
}

void Monsters(SDL_Renderer* renderer)
{
	//arachas_behemoth
	Gweent[84].power = 6;
	Gweent[84].position = 3;
	Gweent[84].Kard = 3;

	//arachas1 ///////////////////////////////////////////////////////////////////////////////////////
	Gweent[85].power = 4;
	Gweent[85].position = 1;
	Gweent[85].Kard = 3;
	//arachas2
	Gweent[86].power = 4;
	Gweent[86].position = 1;
	Gweent[86].Kard = 3;
	//arachas3
	Gweent[87].power = 4;
	Gweent[87].position = 1;
	Gweent[87].Kard = 3;
	//crone_brewess
	Gweent[88].power = 6;
	Gweent[88].position = 1;
	Gweent[88].Kard = 3;
	//crone_weavess
	Gweent[89].power = 6;
	Gweent[89].position = 1;
	Gweent[89].Kard = 3;
	//crone_whispess
	Gweent[90].power = 6;
	Gweent[90].position = 1;
	Gweent[90].Kard = 3;
	//draug
	Gweent[91].power = 10;
	Gweent[91].position = 1;
	Gweent[91].Kard = 0;
	//fiend
	Gweent[92].power = 6;
	Gweent[92].position = 1;
	Gweent[92].Kard = 0;
	//imlerith
	Gweent[93].power = 10;
	Gweent[93].position = 1;
	Gweent[93].Kard = 0;
	//kayran
	Gweent[94].power = 8;
	Gweent[94].position = 2;
	Gweent[94].Kard = 1;
	//leshen
	Gweent[95].power = 10;
	Gweent[95].position = 2;
	Gweent[95].Kard = 0;
	//vampire_bruxa
	Gweent[96].power = 4;
	Gweent[96].position = 1;
	Gweent[96].Kard = 3;
	//vampire_ekimmara
	Gweent[97].power = 4;
	Gweent[97].position = 1;
	Gweent[97].Kard = 3;
	//vampire_fleder
	Gweent[98].power = 4;
	Gweent[98].position = 1;
	Gweent[98].Kard = 3;
	//vampire_garkain
	Gweent[99].power = 4;
	Gweent[99].position = 1;
	Gweent[99].Kard = 3;
	//avallach
	Gweent[100].power = 0;
	Gweent[100].position = -1;
	Gweent[100].Kard = 5;
	//ciri
	Gweent[101].power = 15;
	Gweent[101].position = 1;
	Gweent[101].Kard = 0;
	//dandelion
	Gweent[102].power = 2;
	Gweent[102].position = 1;
	Gweent[102].Kard = 0;
	//geralt
	Gweent[103].power = 15;
	Gweent[103].position = 1;
	Gweent[103].Kard = 0;
	//vesemir
	Gweent[104].power = 6;
	Gweent[104].position = 1;
	Gweent[104].Kard = 0;
	//zoltan
	Gweent[105].power = 5;
	Gweent[105].position = 1;
	Gweent[105].Kard = 0;
	//villentretenmerth
	Gweent[106].power = 7;
	Gweent[106].position = 1;
	Gweent[106].Kard = 0;
	//clear
	Gweent[107].power = 0;
	Gweent[107].position = 4;
	Gweent[107].Kard = 6;
	//fog
	Gweent[108].power = 0;
	Gweent[108].position = 4;
	Gweent[108].Kard = 8;
	//frost
	Gweent[109].power = 0;
	Gweent[109].position = 4;
	Gweent[109].Kard = 9;
	//rain
	Gweent[110].power = 0;
	Gweent[110].position = 4;
	Gweent[110].Kard = 10;
	//horn
	Gweent[111].power = 0;
	Gweent[111].position = 5;
	Gweent[111].Kard = 4;
	int j = 0;
	for (int i = 84; i < 112; i++)
	{
		Gweent[i].koloda = 3;
		Gweent[i].texture = CreateCard(renderer, monster[j]);
		Gweent[i].nomerKarti = j;
		j++;
	}
}
int IIKOLOD = -1;
int IIKARDS = -1;
gweent ISKUSTVENNIYINTELLEKTPLAYER[114];
int IIKARD = -10;

void cardR()
{
	
	for (int i = 0; i < 15; i++)
	{
		neutralR[i].x = i * 100;
		neutralR[i].y = 0;
		neutralR[i].w = 100;
		neutralR[i].h = 200;
	}
	for (int i = 0; i < 16; i++)
	{
		monsterR[i].x = i * 100;
		monsterR[i].y = 210;
		monsterR[i].w = 100;
		monsterR[i].h = 200;
	}
	for (int i = 0; i < 18; i++)
	{
		nilfgaardianR[i].x = i * 100;
		nilfgaardianR[i].y = 420;
		nilfgaardianR[i].w = 100;
		nilfgaardianR[i].h = 200;
	}
	for (int i = 0; i < 16; i++)
	{
		northernR[i].x = i * 100;
		northernR[i].y = 630;
		northernR[i].w = 100;
		northernR[i].h = 200;
	}
	for (int i = 0; i < 18; i++)
	{
		scoiataelR[i].x = i * 100;
		scoiataelR[i].y = 840;
		scoiataelR[i].w = 100;
		scoiataelR[i].h = 200;
	}
}

//путь к текстурам карт
char const* neutral[] = {
"avallach.png",
"ciri.png",
"clear.png",
"dandelion.png",
"decoy.png",
"fog.png",
"frost.png",
"geralt.png",
"horn.png",



"rain.png",
"triss.png",
"vesemir.png",
"villentretenmerth.png",
"yen.png",
"zoltan.png"
};

int LIVESV = 2;
int LIVESR = 2;

void Cards(SDL_Renderer* render)

{
	for (int i = 0; i < 15; i++)
	{
		neutralTex[i] = CreateCard(render, neutral[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		monsterTex[i] = CreateCard(render, monster[i]);
	}
	for (int i = 0; i < 16; i++)
	{
		northernTex[i] = CreateCard(render, northern[i]);
	}
	for (int i = 0; i < 18; i++)
	{
		nilfgaardianTex[i] = CreateCard(render, nilfgaardian[i]);
	}
	for (int i = 0; i < 17; i++)
	{
		scoiataelTex[i] = CreateCard(render, scoiatael[i]);
	}
}

struct karta
{
	int pugalo = 3;
	int rain = 3;
	int fog = 3;
	int frost = 3;
	int clear = 3;
	int horn = 3;
};
SDL_Rect player1kard[3][15];
gweent player11[114];

// Чтобы не было повторов 
int proverka(int w)
{
	for (int i = 0; i < 15; i++)
	{
		if (player11[i].nomerKarti == w)
			return 1;
	}
	return 0;
}
// Чтобы не было повторов 
int ISKUSTVENNIYINTELLEKTproverka(int w)
{
	for (int i = 0; i < 30; i++)
	{
		
		if (ISKUSTVENNIYINTELLEKTPLAYER[i].nomerKarti == w-w-w-1)
			return 1;
	}
	return 0;
}
//Графически-
void razdachashpion(SDL_Renderer* renderer)
{
	int f = 0;
	for (int i = 0; i < 114; i++)
	{
		if (f == 2)
			break;
		if (player11[i].Uigroka == 1&&player11[i].notshpion!=1)
		{
			for (int j = 0; j < 15; j++)
			{
				if (urovenplayer[j].nomerKarti == -100)
				{
					urovenplayer[j].nomerKarti = player11[i].nomerKarti;
					player11[i].notshpion = 1;
					f++;
					break;

				}
			}
		}
	}
}

void razdacha(SDL_Renderer* renderer)
{

	for (int i = 0; i < 114; i++)
	{
		if (player11[i].Uigroka == 1)
		{
			for (int j = 0; j < 10; j++)
			{
				if (urovenplayer[j].nomerKarti == -100)
				{
					urovenplayer[j].nomerKarti = player11[i].nomerKarti;
					break;

				}
			}
		}
	}
}

void RazdacaShpion(int koloda)
{
	int j = 0;
	int f = 0;
	int e = 0;
	if (koloda == 0)
	{
		for (int i = 0; i < 28; i++)
		{
			if (player11[i].nomerKarti == -100)
			{
				e = rand() % (27 - 0 + 1) + 0;
				if (proverka(e))
				{
					while (proverka(e))
					{
						e = rand() % (27 - 0 + 1) + 1;
					}
				}
				player11[i].power = Gweent[e].power;
				player11[i].position = Gweent[e].position;
				player11[i].Kard = Gweent[e].Kard;
				Gweent[i].Uigroka = 1;
				Gweent[i].Bito = 0;
				player11[i].Bito = 0;
				player11[i].koloda = Gweent[e].koloda;
				player11[i].texture = Gweent[e].texture;
				player11[i].nomerKarti = Gweent[e].nomerKarti;
				player11[i].Uigroka = 1;
				printf_s("%d\n", player11[i].power);
				printf_s("%d\n", player11[i].position);
				printf_s("%d\n", player11[i].Kard);
				printf_s("%d\n", player11[i].koloda);
				printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				f++;
				if (f == 2)
					break;
			}
		}
	}
	if (koloda == 1)
	{
		for (int i = 0; i < 26; i++)
		{
			if (player11[i].nomerKarti == -100)
			{
				e = rand() % (53 - 28 + 1) + 28;
				if (proverka(Gweent[e].nomerKarti))
				{
					while (proverka(Gweent[e].nomerKarti))
					{
						e = rand() % (53 - 28 + 1) + 28;
					}
				}
				player11[i].power = Gweent[e].power;
				player11[i].position = Gweent[e].position;
				player11[i].Kard = Gweent[e].Kard;
				player11[i].koloda = Gweent[e].koloda;
				Gweent[i].Uigroka = 1;
				Gweent[i].Bito = 0;
				player11[i].Bito = 0;
				player11[i].texture = Gweent[e].texture;
				player11[i].nomerKarti = Gweent[e].nomerKarti;
				player11[i].Uigroka = 1;
				printf_s("%d\n", player11[i].power);
				printf_s("%d\n", player11[i].position);
				printf_s("%d\n", player11[i].Kard);
				printf_s("%d\n", player11[i].koloda);
				printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				f++;
				if (f == 2)
					break;
			}
		}
	}
	if (koloda == 2)
	{
		for (int i = 0; i < 30; i++)
		{
			if (player11[i].nomerKarti == -100)
			{
				e = rand() % (83 - 54 + 1) + 54;
				if (proverka(Gweent[e].nomerKarti))
				{
					while (proverka(Gweent[e].nomerKarti))
					{
						e = rand() % (83 - 54 + 1) + 54;
					}
				}
				player11[i].power = Gweent[e].power;
				player11[i].position = Gweent[e].position;
				player11[i].Kard = Gweent[e].Kard;
				player11[i].koloda = Gweent[e].koloda;
				Gweent[i].Uigroka = 1;
				Gweent[i].Bito = 0;
				player11[i].Bito = 0;
				player11[i].texture = Gweent[e].texture;
				player11[i].nomerKarti = Gweent[e].nomerKarti;
				player11[i].Uigroka = 1;
				printf_s("%d\n", player11[i].power);
				printf_s("%d\n", player11[i].position);
				printf_s("%d\n", player11[i].Kard);
				printf_s("%d\n", player11[i].koloda);
				printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				f++;
				if (f == 2)
					break;
			}
		}
	}
	if (koloda == 3)
	{
		for (int i = 0; i < 28; i++)
		{
			if (player11[i].nomerKarti == -100)
			{
				e = rand() % (111 - 84 + 1) + 84;
				if (proverka(Gweent[e].nomerKarti))
				{
					while (proverka(Gweent[e].nomerKarti))
					{
						e = rand() % (111 - 84 + 1) + 84;
					}
				}
				player11[i].power = Gweent[e].power;
				player11[i].position = Gweent[e].position;
				player11[i].Kard = Gweent[e].Kard;
				player11[i].koloda = Gweent[e].koloda;
				Gweent[i].Uigroka = 1;
				Gweent[i].Bito = 0;
				player11[i].Bito = 0;
				player11[i].Uigroka = 1;
				player11[i].texture = Gweent[e].texture;
				player11[i].nomerKarti = Gweent[e].nomerKarti;
				printf_s("%d\n", player11[i].power);
				printf_s("%d\n", player11[i].position);
				printf_s("%d\n", player11[i].Kard);
				printf_s("%d\n", player11[i].koloda);
				printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				f++;
				if (f == 2)
					break;
			}
		}
	}

}

void RazdacaKartIgrokam1(int koloda)
{
	int j = 0;
	int e = 0;
	if (koloda == 0)
	{
		for (int i = 0; i < 11; i++)
		{
			e = rand() % (27 - 0 + 1) + 0;
			if (proverka(e))
			{
				while (proverka(e))
				{
					e = rand() % (27 - 0 + 1) + 1;
				}
			}
			player11[i].power = Gweent[e].power;
			player11[i].position = Gweent[e].position;
			player11[i].Kard = Gweent[e].Kard;
			Gweent[e].Uigroka = 1;
			Gweent[e].Bito = 0;
			player11[i].Bito = 0;
			player11[i].koloda = Gweent[e].koloda;
			player11[i].texture = Gweent[e].texture;
			player11[i].nomerKarti = Gweent[e].nomerKarti;
			player11[i].Uigroka = 1;
			player11[i].notshpion = 1;
			Gweent[e].notshpion = 1;
			printf_s("%d\n", player11[i].power);
			printf_s("%d\n", player11[i].position);
			printf_s("%d\n", player11[i].Kard);
			printf_s("%d\n", player11[i].koloda);
			printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
		}
	}
	if (koloda == 1)
	{
		for (int i = 0; i < 11; i++)
		{
			e = rand() % (53 - 28 + 1) + 28;
			if (proverka(Gweent[e].nomerKarti))
			{
				while (proverka(Gweent[e].nomerKarti))
				{
					e = rand() % (53 - 28 + 1) + 28;
				}
			}
			player11[i].power = Gweent[e].power;
			player11[i].position = Gweent[e].position;
			player11[i].Kard = Gweent[e].Kard;
			player11[i].koloda = Gweent[e].koloda;
			Gweent[e].Uigroka = 1;
			Gweent[e].Bito = 0;
			player11[i].Bito = 0;
			player11[i].texture = Gweent[e].texture;
			player11[i].nomerKarti = Gweent[e].nomerKarti;
			player11[i].Uigroka = 1;
			player11[i].notshpion = 1;
			Gweent[e].notshpion = 1;
			printf_s("%d\n", player11[i].power);
			printf_s("%d\n", player11[i].position);
			printf_s("%d\n", player11[i].Kard);
			printf_s("%d\n", player11[i].koloda);
			printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
		}
	}
	if (koloda == 2)
	{
		for (int i = 0; i < 11; i++)
		{
			e = rand() % (83 - 54 + 1) + 54;
			if (proverka(Gweent[e].nomerKarti))
			{
				while (proverka(Gweent[e].nomerKarti))
				{
					e = rand() % (83 - 54 + 1) + 54;
				}
			}
			player11[i].power = Gweent[e].power;
			player11[i].position = Gweent[e].position;
			player11[i].Kard = Gweent[e].Kard;
			player11[i].koloda = Gweent[e].koloda;
			Gweent[e].Uigroka = 1;
			Gweent[e].Bito = 0;
			player11[i].Bito = 0;
			player11[i].texture = Gweent[e].texture;
			player11[i].nomerKarti = Gweent[e].nomerKarti;
			player11[i].Uigroka = 1;
			player11[i].notshpion = 1;
			Gweent[e].notshpion = 1;
			printf_s("%d\n", player11[i].power);
			printf_s("%d\n", player11[i].position);
			printf_s("%d\n", player11[i].Kard);
			printf_s("%d\n", player11[i].koloda);
			printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
		}
	}
	if (koloda == 3)
	{
		for (int i = 0; i < 11; i++)
		{
			e = rand() % (111 - 84 + 1) + 84;
			if (proverka(Gweent[e].nomerKarti))
			{
				while (proverka(Gweent[e].nomerKarti))
				{
					e = rand() % (111 - 84 + 1) + 84;
				}
			}
			player11[i].power = Gweent[e].power;
			player11[i].position = Gweent[e].position;
			player11[i].Kard = Gweent[e].Kard;
			player11[i].koloda = Gweent[e].koloda;
			Gweent[e].Uigroka = 1;
			Gweent[e].Bito = 0;
			player11[i].Bito = 0;
			player11[i].Uigroka = 1;
			player11[i].texture = Gweent[e].texture;
			player11[i].nomerKarti = Gweent[e].nomerKarti;
			player11[i].notshpion = 1;
			Gweent[e].notshpion = 1;
			printf_s("%d\n", player11[i].power);
			printf_s("%d\n", player11[i].position);
			printf_s("%d\n", player11[i].Kard);
			printf_s("%d\n", player11[i].koloda);
			printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
		}
	}

}

int flagok = -100;
//Рисовка карт
void RenderCard(SDL_Renderer* renderer, int flag)
{
	for (int i = 0; i < 15; i++)
	{
		if (urovenplayer[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == urovenplayer[i].nomerKarti && flag != player11[j].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &urovenplayer[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (uroven3[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == uroven3[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &uroven3[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (uroven2[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == uroven2[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &uroven2[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (uroven1[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == uroven1[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &uroven1[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (urovenVraga3[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == urovenVraga3[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &urovenVraga3[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (urovenVraga2[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == urovenVraga2[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &urovenVraga2[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (urovenVraga1[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == urovenVraga1[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &urovenVraga1[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (flagok == 1)
		{
			if (truba[i].nomerKarti != -100)
			{
				for (int j = 0; j < 114; j++)
				{
					if (player11[j].nomerKarti == truba[i].nomerKarti)
					{
						SDL_RenderCopy(renderer, player11[j].texture, NULL, &player11[j].karta);
						//SDL_RenderPresent(renderer);
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{

		if (urovenDlyaPogodi[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (player11[j].nomerKarti == urovenDlyaPogodi[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, player11[j].texture, NULL, &player11[j].karta);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}

	}

}

void ISKUSTVENNIYINTELLEKTRenderCard(SDL_Renderer* renderer, int flag)
{

	for (int i = 0; i < 15; i++)
	{
		if (uroven3[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == uroven3[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &uroven3[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (uroven2[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == uroven2[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &uroven2[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (uroven1[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == uroven1[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &uroven1[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (urovenVraga3[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
 				if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == urovenVraga3[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &urovenVraga3[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (urovenVraga2[i].nomerKarti != -10)
		{
			for (int j = 0; j < 114; j++)
			{
				if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == urovenVraga2[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &urovenVraga2[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (urovenVraga1[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == urovenVraga1[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &urovenVraga1[i].uroven);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (flagok == 1)
		{
			if (truba[i].nomerKarti != -100)
			{
				for (int j = 0; j < 114; j++)
				{
					if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == truba[i].nomerKarti)
					{
						SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &ISKUSTVENNIYINTELLEKTPLAYER[j].karta);
						//SDL_RenderPresent(renderer);
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{

		if (urovenDlyaPogodi[i].nomerKarti != -100)
		{
			for (int j = 0; j < 114; j++)
			{
				if (ISKUSTVENNIYINTELLEKTPLAYER[j].nomerKarti == urovenDlyaPogodi[i].nomerKarti)
				{
					SDL_RenderCopy(renderer, ISKUSTVENNIYINTELLEKTPLAYER[j].texture, NULL, &ISKUSTVENNIYINTELLEKTPLAYER[j].karta);
					//SDL_RenderPresent(renderer);
					break;
				}
			}
		}

	}

}
int powerr = 0;
char powerc[5];
int IIPOWERR = 0;
char IIPOWERC[5];

char IILIVE[5];
char LIVEC[5];

void rendert(SDL_Renderer* renderer)
{
	sprintf(IIPOWERC, "%d", IIPOWERR);
	MenuText(renderer, MainMenuFont, white, 20, 800, 30, 60, IIPOWERC);
	sprintf(powerc, "%d", powerr);
	MenuText(renderer, MainMenuFont, white, 20, 200, 30, 60, powerc);
	
	
	
	sprintf(LIVEC, "%d", LIVESR);
	MenuText(renderer, MainMenuFont, white, 70, 900, 30, 60, "LIVES:");
	MenuText(renderer, MainMenuFont, white, 200, 900, 30, 60, LIVEC);
	sprintf(IILIVE, "%d", LIVESV);
	MenuText(renderer, MainMenuFont, white, 70, 100, 30, 60, "LIVES:");
	MenuText(renderer, MainMenuFont, white, 200, 100, 30, 60, IILIVE);
}
//Прорисовка позиций
int kart(int uroven)
{
	int j = 0;
	if (uroven == 1)
	{
		for (int i = 0; i < 15; i++)
		{
			if (uroven3[i].nomerKarti > 0)
				j++;
		}
		return j;
	}
	if (uroven == 2)
	{
		for (int i = 0; i < 15; i++)
		{
			if (uroven2[i].nomerKarti > 0)
				j++;
		}
		return j;
	}
	if (uroven == 3)
	{
		for (int i = 0; i < 15; i++)
		{
			if (uroven1[i].nomerKarti > 0)
				j++;
		}
		return j;
	}
}

int power(int uroven)
{
	int j = 0;
	if (uroven == 1)
	{
		for (int i = 0; i < 15; i++)
		{
			if (uroven3[i].nomerKarti > 0) 
				for (int f = 0; f < 15; f++)
				{
					if (player11[f].nomerKarti == uroven3[i].nomerKarti)
					{
						j += player11[f].power;
						break;
					}
				}
				
		}
		return j;
	}
	if (uroven == 2)
	{
		for (int i = 0; i < 15; i++)
		{
			if (uroven2[i].nomerKarti > 0)
				for (int f = 0; f < 15; f++)
				{
					if (player11[f].nomerKarti == uroven2[i].nomerKarti)
					{
						j += player11[f].power;
						break;
					}
				}
		}
		return j;
	}
	if (uroven == 3)
	{
		for (int i = 0; i < 15; i++)
		{
			if (uroven1[i].nomerKarti > 0)
				for (int f = 0; f < 15; f++)
				{
					if (player11[f].nomerKarti == uroven1[i].nomerKarti)
					{
						j += player11[f].power;
						break;
					}
				}
		}
		return j;
	}



	/////////////
	if (uroven == 0)
	{
		for (int i = 0; i < 15; i++)
		{
			if (urovenVraga3[i].nomerKarti < 0)
				for (int f = 0; f < 15; f++)
				{
					if (ISKUSTVENNIYINTELLEKTPLAYER[f].nomerKarti == urovenVraga3[i].nomerKarti)
					{
						j += ISKUSTVENNIYINTELLEKTPLAYER[f].power;
						break;
					}
				}

		}
		return j;
	}
	if (uroven == -1)
	{
		for (int i = 0; i < 15; i++)
		{
			if (urovenVraga2[i].nomerKarti < 0)
				for (int f = 0; f < 15; f++)
				{
					if (ISKUSTVENNIYINTELLEKTPLAYER[f].nomerKarti == urovenVraga2[i].nomerKarti)
					{
						j += ISKUSTVENNIYINTELLEKTPLAYER[f].power;
						break;
					}
				}
		}
		return j;
	}
	if (uroven == -2)
	{
		for (int i = 0; i < 15; i++)
		{
			if (urovenVraga1[i].nomerKarti < 0)
				for (int f = 0; f < 15; f++)
				{
					if (ISKUSTVENNIYINTELLEKTPLAYER[f].nomerKarti == urovenVraga1[i].nomerKarti)
					{
						j += ISKUSTVENNIYINTELLEKTPLAYER[f].power;
						break;
					}
				}
		}
		return j;
	}
}

int  ISKUSTVENNIYINTELLEKTproverka1(int kard)
{
	for (int i = 0; i < 15; i++)
	{
		if (urovenplayer[i].nomerKarti == kard)
			return 0;
		
	}
	return 1;
}

int frost = 0;
int fog = 0;
int clear = 0;
int rain = 0;
int storm = 0;
int uroven1d = 0;
int uroven2d = 0;
int uroven3d = 0;
int uroven1v = 0;
int uroven2v = 0;
int uroven3v = 0;
int uroven1dd = 0;
int uroven2dd = 0;
int uroven3dd = 0;
int uroven1vv = 0;
int uroven2vv = 0;
int uroven3vv = 0;

int flagi = 0;
int hod = 0;

void kards(SDL_Renderer* renderer, int nomerkarti, SDL_Texture* texturestol)
{
	SDL_Event eventus;
	int x, y;
	int f = 0;
	int flag = 0;
	int nomer1;
	int nomer=-1;
	int urov;
	while (true)
	{
		rendert(renderer);
		RenderCard(renderer, nomerkarti);
		ISKUSTVENNIYINTELLEKTRenderCard(renderer, -20);
		SDL_PollEvent(&eventus);
		if (eventus.type == SDL_MOUSEMOTION)
		{
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, texturestol, NULL, &STOL);
			for (int i = 0; i < 30; i++)
			{
				if (player11[i].nomerKarti != nomerkarti)
				{
					RenderCard(renderer, nomerkarti);
				}
				else
				{
					player11[i].karta.x = eventus.motion.x;
					player11[i].karta.y = eventus.motion.y;
					player11[i].karta.w = 50;
					player11[i].karta.h = 100;
					if (flag == 0)
					{
						nomer = i;
						flag = 1;
					}
					SDL_RenderCopy(renderer, player11[i].texture, NULL, &player11[i].karta);
				}


			}
		}
			if (eventus.type==SDL_MOUSEBUTTONDOWN)
			{
				if (player11[nomer].position == 1)
				{
					for (int i = 0; i < 15; i++)
					{
						if (SDL_HasIntersection(&player11[nomer].karta, &uroven3[i].uroven))
						{
							for (int j = 0; j < 15; j++)
							{
								if (uroven3[j].nomerKarti ==-100)
								{
								//	uroven3[j].nomerKarti = nomer;
									for (int ii = 0; ii < 15; ii++)
									{
										if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
										{
											nomer1 = ii;
											break;
										}
									}
									player11[nomer].karta.x = uroven3[j].uroven.x;
									player11[nomer].karta.y = uroven3[j].uroven.y;
									player11[nomer].karta.w = uroven3[j].uroven.w;
									player11[nomer].karta.h = uroven3[j].uroven.h;
									powerr += player11[nomer].power;
									uroven3d++;
									uroven3dd += player11[nomer].power;
									uroven3[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
									urovenplayer[nomer1].nomerKarti = -100;
									if (player11[nomer].Kard == 1)
									{
										f = kart(1);
										powerr += f * f;
									}
									hod = 1;
									return;

								}
							}
						}
					}
				}
				else
				{
					if (player11[nomer].position == 2)
					{
						for (int i = 0; i < 15; i++)
						{
							if (SDL_HasIntersection(&player11[nomer].karta, &uroven2[i].uroven))
							{
								for (int j = 0; j < 15; j++)
								{
									if (uroven2[j].nomerKarti ==-100)
									{
										for (int ii = 0; ii < 15; ii++)
										{
											if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
											{
												nomer1 = ii;
												break;
											}
										}
										//uroven2[j].nomerKarti = nomer;
										player11[nomer].karta.x = uroven2[j].uroven.x;
										player11[nomer].karta.y = uroven2[j].uroven.y;
										player11[nomer].karta.w = uroven2[j].uroven.w;
										player11[nomer].karta.h = uroven2[j].uroven.h;
										powerr += player11[nomer].power;
										uroven2d++;
										uroven2dd += player11[nomer].power;
										uroven2[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
										urovenplayer[nomer1].nomerKarti = -100;
										if (player11[nomer].Kard == 1)
										{
											f=kart(2);
											powerr += f * f;
										}
										hod = 1;
										return;

									}
								}
							}
						}
					}
					else {

						if (player11[nomer].position == 3)
						{
							for (int i = 0; i < 15; i++)
							{
								if (SDL_HasIntersection(&player11[nomer].karta, &uroven1[i].uroven))
								{
									for (int j = 0; j < 15; j++)
									{
										if (uroven1[j].nomerKarti == -100)
										{
											//uroven1[j].nomerKarti = nomer;
											for (int ii = 0; ii < 15; ii++)
											{
												if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
												{
													nomer1 = ii;
													break;
												}
											}
											player11[nomer].karta.x = uroven1[j].uroven.x;
											player11[nomer].karta.y = uroven1[j].uroven.y;
											player11[nomer].karta.w = uroven1[j].uroven.w;
											player11[nomer].karta.h = uroven1[j].uroven.h;
											powerr += player11[nomer].power;
											uroven1d++;
											uroven1dd += player11[nomer].power;
											uroven1[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
											urovenplayer[nomer1].nomerKarti = -100;
											if (player11[nomer].Kard == 1)
											{
												f=kart(3);
												powerr += f * f;
											}
											hod = 1;
											return;

										}
									}
								}
							}
						}
						else
						{
							if (player11[nomer].position == 5)
							{
								for (int i = 3; i < 6; i++)
								{
									if (SDL_HasIntersection(&player11[nomer].karta, &truba[i].uroven))
									{
										
											if (truba[i].nomerKarti ==-100)
											{
												flagok = 1;
												//uroven1[j].nomerKarti = nomer;
												for (int ii = 0; ii < 15; ii++)
												{
													if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
													{
														nomer1 = ii;
														break;
													}
												}
												player11[nomer].karta.x = truba[i].uroven.x;
												player11[nomer].karta.y = truba[i].uroven.y;
												player11[nomer].karta.w = truba[i].uroven.w;
												player11[nomer].karta.h = truba[i].uroven.h;
												//powerr += player11[nomer].power;
												truba[i].nomerKarti = urovenplayer[nomer1].nomerKarti;
												urovenplayer[nomer1].nomerKarti = -100;
 												f = power(i-2);
												powerr+=f;
												hod = 1;
												return;

											}
										
									}
								} 
							}
							else {
								if (player11[nomer].position == -1)
								{
									for (int f = 0; f < 15; f++)
									{
										if (SDL_HasIntersection(&player11[nomer].karta, &urovenVraga3[f].uroven))
										{
											for (int j = 0; j < 15; j++)
											{
												if (urovenVraga3[j].nomerKarti == -100)
												{
													//uroven1[j].nomerKarti = nomer;
													for (int ii = 0; ii < 15; ii++)
													{
														if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
														{
															nomer1 = ii;
															break;
														}
													}
													player11[nomer].karta.x = urovenVraga3[j].uroven.x;
													player11[nomer].karta.y = urovenVraga3[j].uroven.y;
													player11[nomer].karta.w = urovenVraga3[j].uroven.w;
													player11[nomer].karta.h = urovenVraga3[j].uroven.h;
													IIPOWERR += player11[nomer].power;
													uroven3v++;
													uroven3vv += player11[nomer].power;
													urovenVraga3[nomer].nomerKarti = urovenplayer[nomer1].nomerKarti;
													urovenplayer[nomer1].nomerKarti = -100;
													RazdacaShpion(kolod);
													razdachashpion(renderer);
													hod = 1;
													return;

												}
											}
										}
									}
								
								
								}
								else
								{
									if (player11[nomer].position == -2)
									{
										for (int i = 0; i < 15; i++)
										{
											if (SDL_HasIntersection(&player11[nomer].karta, &urovenVraga2[i].uroven))
											{
												for (int j = 0; j < 15; j++)
												{
													if (urovenVraga2[j].nomerKarti == -100)
													{
														//uroven1[j].nomerKarti = nomer;
														for (int ii = 0; ii < 15; ii++)
														{
															if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
															{
																nomer1 = ii;
																break;
															}
														}
														player11[nomer].karta.x = urovenVraga2[j].uroven.x;
														player11[nomer].karta.y = urovenVraga2[j].uroven.y;
														player11[nomer].karta.w = urovenVraga2[j].uroven.w;
														player11[nomer].karta.h = urovenVraga2[j].uroven.h;
														IIPOWERR += player11[nomer].power;
														uroven2v++;
														uroven2vv += player11[nomer].power;
														urovenVraga2[nomer].nomerKarti = urovenplayer[nomer1].nomerKarti;
														urovenplayer[nomer1].nomerKarti = -100;
														RazdacaShpion(kolod);
														razdachashpion(renderer);
														hod = 1;
														return;

													}
												}
											}
										}


									}
									else
									{
										if (player11[nomer].position == -3)
										{
											for (int i = 0; i < 15; i++)
											{
												if (SDL_HasIntersection(&player11[nomer].karta, &urovenVraga1[i].uroven))
												{
													for (int j = 0; j < 15; j++)
													{
														if (urovenVraga1[j].nomerKarti == -100)
														{
															//uroven1[j].nomerKarti = nomer;
															for (int ii = 0; ii < 15; ii++)
															{
																if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
																{
																	nomer1 = ii;
																	break;
																}
															}
															player11[nomer].karta.x = urovenVraga1[j].uroven.x;
															player11[nomer].karta.y = urovenVraga1[j].uroven.y;
															player11[nomer].karta.w = urovenVraga1[j].uroven.w;
															player11[nomer].karta.h = urovenVraga1[j].uroven.h;
															IIPOWERR += player11[nomer].power;
															uroven1v++;
															uroven1vv += player11[nomer].power;
															urovenVraga1[nomer].nomerKarti = urovenplayer[nomer1].nomerKarti;
															urovenplayer[nomer1].nomerKarti = -100;
															RazdacaShpion(kolod);
															razdachashpion(renderer);
															hod = 1;
															return;

														}
													}
												}
											}


										}
									}
								}
							}
						}
					}
			
				}
				if (player11[nomer].Kard == 7)
				{
					
						for (int i = 0; i < 15; i++)
						{
							if (SDL_HasIntersection(&player11[nomer].karta, &uroven3[i].uroven))
							{
								for (int j = 0; j < 15; j++)
								{
									if (uroven3[j].nomerKarti == -100)
									{
										//	uroven3[j].nomerKarti = nomer;
										for (int ii = 0; ii < 15; ii++)
										{
											if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
											{
												nomer1 = ii;
												break;
											}
										}
										player11[nomer].karta.x = uroven3[j].uroven.x;
										player11[nomer].karta.y = uroven3[j].uroven.y;
										player11[nomer].karta.w = uroven3[j].uroven.w;
										player11[nomer].karta.h = uroven3[j].uroven.h;
										powerr += player11[nomer].power;
										uroven3[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
										urovenplayer[nomer1].nomerKarti = -100;
										if (player11[nomer].Kard == 1)
										{
											f = kart(1);
											powerr += f * f;
										}
										hod = 1;
										return;

									}
								}
							}
							if (SDL_HasIntersection(&player11[nomer].karta, &uroven2[i].uroven))
							{
								for (int j = 0; j < 15; j++)
								{
									if (uroven2[j].nomerKarti == -100)
									{
										for (int ii = 0; ii < 15; ii++)
										{
											if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
											{
												nomer1 = ii;
												break;
											}
										}
										//uroven2[j].nomerKarti = nomer;
										player11[nomer].karta.x = uroven2[j].uroven.x;
										player11[nomer].karta.y = uroven2[j].uroven.y;
										player11[nomer].karta.w = uroven2[j].uroven.w;
										player11[nomer].karta.h = uroven2[j].uroven.h;
										powerr += player11[nomer].power;
										uroven2[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
										urovenplayer[nomer1].nomerKarti = -100;
										if (player11[nomer].Kard == 1)
										{
											f = kart(2);
											powerr += f * f;
										}
										hod = 1;
										return;

									}
								}
							}
							if (SDL_HasIntersection(&player11[nomer].karta, &uroven1[i].uroven))
							{
								for (int j = 0; j < 15; j++)
								{
									if (uroven1[j].nomerKarti == -100)
									{
										//uroven1[j].nomerKarti = nomer;
										for (int ii = 0; ii < 15; ii++)
										{
											if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
											{
												nomer1 = ii;
												break;
											}
										}
										player11[nomer].karta.x = uroven1[j].uroven.x;
										player11[nomer].karta.y = uroven1[j].uroven.y;
										player11[nomer].karta.w = uroven1[j].uroven.w;
										player11[nomer].karta.h = uroven1[j].uroven.h;
										powerr += player11[nomer].power;
										uroven1[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
										urovenplayer[nomer1].nomerKarti = -100;
										if (player11[nomer].Kard == 1)
										{
											f = kart(3);
											powerr += f * f;
										}
										hod = 1;
										return;

									}
								}
							}
						}
						}
						if (player11[nomer].Kard == 9)
						{
							for (int i = 0; i < 7; i++)
							{
								if (SDL_HasIntersection(&player11[nomer].karta, &urovenDlyaPogodi[i].uroven))
								{
									for (int j = 0; j < 7; j++)
									{
										if (urovenDlyaPogodi[j].nomerKarti == -100)
										{
											//	uroven3[j].nomerKarti = nomer;
											for (int ii = 0; ii < 15; ii++)
											{
												if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
												{
													nomer1 = ii;
													break;
												}
											}
											player11[nomer].karta.x = urovenDlyaPogodi[j].uroven.x;
											player11[nomer].karta.y = urovenDlyaPogodi[j].uroven.y;
											player11[nomer].karta.w = urovenDlyaPogodi[j].uroven.w;
											player11[nomer].karta.h = urovenDlyaPogodi[j].uroven.h;
											
											urovenDlyaPogodi[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
											urovenplayer[nomer1].nomerKarti = -100;
											frost = 1;

											powerr -= uroven3dd - uroven3d;

											IIPOWERR -= uroven3vv - uroven3v;

											hod = 1;
											return;

										}
									}
								}
							}
						}
						if (player11[nomer].Kard == 8)
						{
							for (int i = 0; i < 7; i++)
							{
								if (SDL_HasIntersection(&player11[nomer].karta, &urovenDlyaPogodi[i].uroven))
								{
									for (int j = 0; j < 7; j++)
									{
										if (urovenDlyaPogodi[j].nomerKarti == -100)
										{
											//	uroven3[j].nomerKarti = nomer;
											for (int ii = 0; ii < 15; ii++)
											{
												if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
												{
													nomer1 = ii;
													break;
												}
											}
											player11[nomer].karta.x = urovenDlyaPogodi[j].uroven.x;
											player11[nomer].karta.y = urovenDlyaPogodi[j].uroven.y;
											player11[nomer].karta.w = urovenDlyaPogodi[j].uroven.w;
											player11[nomer].karta.h = urovenDlyaPogodi[j].uroven.h;

											urovenDlyaPogodi[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
											urovenplayer[nomer1].nomerKarti = -100;
											fog = 1;

											powerr -= uroven2dd - uroven2d;

											IIPOWERR -= uroven2vv - uroven2v;

											hod = 1;
											return;

										}
									}
								}
							}
						}
						if (player11[nomer].Kard == 10)
						{
							for (int i = 0; i < 7; i++)
							{
								if (SDL_HasIntersection(&player11[nomer].karta, &urovenDlyaPogodi[i].uroven))
								{
									for (int j = 0; j < 7; j++)
									{
										if (urovenDlyaPogodi[j].nomerKarti == -100)
										{
											//	uroven3[j].nomerKarti = nomer;
											for (int ii = 0; ii < 15; ii++)
											{
												if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
												{
													nomer1 = ii;
													break;
												}
											}
											player11[nomer].karta.x = urovenDlyaPogodi[j].uroven.x;
											player11[nomer].karta.y = urovenDlyaPogodi[j].uroven.y;
											player11[nomer].karta.w = urovenDlyaPogodi[j].uroven.w;
											player11[nomer].karta.h = urovenDlyaPogodi[j].uroven.h;

											urovenDlyaPogodi[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
											urovenplayer[nomer1].nomerKarti = -100;
											rain = 1;

											powerr -= uroven1dd - uroven1d;


											IIPOWERR -= uroven1vv - uroven1v;
											hod = 1;
											return;

										}
									}
								}
							}
						}
						if (player11[nomer].Kard == 6)
						{
							for (int i = 0; i < 7; i++)
							{
								if (SDL_HasIntersection(&player11[nomer].karta, &urovenDlyaPogodi[i].uroven))
								{
									for (int j = 0; j < 7; j++)
									{
										if (urovenDlyaPogodi[j].nomerKarti == -100)
										{
											//	uroven3[j].nomerKarti = nomer;
											for (int ii = 0; ii < 15; ii++)
											{
												if (player11[nomer].nomerKarti == urovenplayer[ii].nomerKarti)
												{
													nomer1 = ii;
													break;
												}
											}
											player11[nomer].karta.x = urovenDlyaPogodi[j].uroven.x;
											player11[nomer].karta.y = urovenDlyaPogodi[j].uroven.y;
											player11[nomer].karta.w = urovenDlyaPogodi[j].uroven.w;
											player11[nomer].karta.h = urovenDlyaPogodi[j].uroven.h;

											urovenDlyaPogodi[j].nomerKarti = urovenplayer[nomer1].nomerKarti;
											urovenplayer[nomer1].nomerKarti = -100;
											if (frost == 1)
											{
												powerr += uroven3dd - uroven3d;
												IIPOWERR += uroven3vv - uroven3v;
												frost = 0;
											}

											
											if (rain == 1)
											{
												powerr += uroven1dd - uroven1d;
												IIPOWERR += uroven1vv - uroven1v;
												rain = 0;
											}

											if (fog == 1)
											{
												powerr += uroven2dd - uroven2d;
												IIPOWERR += uroven2vv - uroven2v;
												fog = 0;
											}



											hod = 1;
											return;

										}
									}
								}
							}
						}
			}
			if (eventus.type == SDL_MOUSEBUTTONDOWN)
				return;
		
		SDL_RenderPresent(renderer);
	}
}


int ISKUSTVENNIYINTELLEKTKART[30];
void ISKUSTVENNIYINTELLEKTKARTVOID(int flag)
{
	if (flag==1)
	{ 
		for (int i = 0; i < 30; i++)
			ISKUSTVENNIYINTELLEKTKART[i] = -100;
	}
}

int  PROVERKAINSKUSTVENNIYINTELLEKT(int kard)
{
	for (int i = 0; i < 30; i++)
	{
		if (kard == ISKUSTVENNIYINTELLEKTKART[i])
			return 0;
	}
	return 1;
}
int kolodaII = 0;
int kolvokards = 10;
void ISKUSTVENNIYINTELLEKT()
{
	if (kolvokards == 0)
	{
		flag = 2;
		space += 1;
		return;
	}
	if (flag != 2)
	{
		if (IIKOLOD == -1)
		{
			if (kolod == 0)
			{
				IIKOLOD = rand() % (3 - 1 + 1) + 1;
			}
			if (kolod == 1)
			{
				IIKOLOD = rand() % (3 - 0 + 1) + 0;
				while (IIKOLOD == 1)
				{
					IIKOLOD = rand() % (3 - 0 + 1) + 0;
				}
			}
			if (kolod == 2)
			{
				IIKOLOD = rand() % (3 - 0 + 1) + 0;
				while (IIKOLOD == 2)
				{
					IIKOLOD = rand() % (3 - 0 + 1) + 0;
				}
			}
			if (kolod == 3)
			{
				IIKOLOD = rand() % (2 - 0 + 1) + 0;

			}
		}
		if (IIKARDS == -1)
		{
			int j = 0;
			int e = 0;
			if (IIKOLOD == 0)
			{
				for (int i = 0; i < 28; i++)
				{
					e = rand() % (27 - 0 + 1) + 0;
					if (ISKUSTVENNIYINTELLEKTproverka(e))
					{
						while (ISKUSTVENNIYINTELLEKTproverka(e))
						{
							e = rand() % (27 - 0 + 1) + 1;
						}
					}
					ISKUSTVENNIYINTELLEKTPLAYER[i].power = Gweent[e].power;
					ISKUSTVENNIYINTELLEKTPLAYER[i].position = Gweent[e].position;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Kard = Gweent[e].Kard;
					Gweent[e].Uigroka = 1;
					Gweent[e].Bito = 0;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Bito = 0;
					ISKUSTVENNIYINTELLEKTPLAYER[i].koloda = Gweent[e].koloda;
					ISKUSTVENNIYINTELLEKTPLAYER[i].texture = Gweent[e].texture;
					ISKUSTVENNIYINTELLEKTPLAYER[i].nomerKarti = Gweent[e].nomerKarti - Gweent[e].nomerKarti - Gweent[e].nomerKarti - 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Uigroka = 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].notshpion = 1;
					Gweent[e].notshpion = 1;
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].power);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].position);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].Kard);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].koloda);
					IIKARDS = 1;
					printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				}
			}
			if (IIKOLOD == 1)
			{
				for (int i = 0; i < 26; i++)
				{
					e = rand() % (53 - 28 + 1) + 28;
					if (ISKUSTVENNIYINTELLEKTproverka(Gweent[e].nomerKarti))
					{
						while (ISKUSTVENNIYINTELLEKTproverka(Gweent[e].nomerKarti))
						{
							e = rand() % (53 - 28 + 1) + 28;
						}
					}
					ISKUSTVENNIYINTELLEKTPLAYER[i].power = Gweent[e].power;
					ISKUSTVENNIYINTELLEKTPLAYER[i].position = Gweent[e].position;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Kard = Gweent[e].Kard;
					ISKUSTVENNIYINTELLEKTPLAYER[i].koloda = Gweent[e].koloda;
					Gweent[e].Uigroka = 1;
					Gweent[e].Bito = 0;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Bito = 0;
					ISKUSTVENNIYINTELLEKTPLAYER[i].texture = Gweent[e].texture;
					ISKUSTVENNIYINTELLEKTPLAYER[i].nomerKarti = Gweent[e].nomerKarti - Gweent[e].nomerKarti - Gweent[e].nomerKarti - 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Uigroka = 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].notshpion = 1;
					Gweent[e].notshpion = 1;
					IIKARDS = 1;
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].power);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].position);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].Kard);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].koloda);
					printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				}
			}
			if (IIKOLOD == 2)
			{
				for (int i = 0; i < 30; i++)
				{
					e = rand() % (83 - 54 + 1) + 54;
					if (ISKUSTVENNIYINTELLEKTproverka(Gweent[e].nomerKarti))
					{
						while (ISKUSTVENNIYINTELLEKTproverka(Gweent[e].nomerKarti))
						{
							e = rand() % (83 - 54 + 1) + 54;
						}
					}
					ISKUSTVENNIYINTELLEKTPLAYER[i].power = Gweent[e].power;
					ISKUSTVENNIYINTELLEKTPLAYER[i].position = Gweent[e].position;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Kard = Gweent[e].Kard;
					ISKUSTVENNIYINTELLEKTPLAYER[i].koloda = Gweent[e].koloda;
					Gweent[e].Uigroka = 1;
					IIKARDS = 1;
					Gweent[e].Bito = 0;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Bito = 0;
					ISKUSTVENNIYINTELLEKTPLAYER[i].texture = Gweent[e].texture;
					ISKUSTVENNIYINTELLEKTPLAYER[i].nomerKarti = Gweent[e].nomerKarti - Gweent[e].nomerKarti - Gweent[e].nomerKarti - 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Uigroka = 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].notshpion = 1;
					Gweent[e].notshpion = 1;
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].power);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].position);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].Kard);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].koloda);
					printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				}
			}
			if (IIKOLOD == 3)
			{
				for (int i = 0; i < 28; i++)
				{
					e = rand() % (111 - 84 + 1) + 84;
					if (ISKUSTVENNIYINTELLEKTproverka(Gweent[e].nomerKarti))
					{
						while (ISKUSTVENNIYINTELLEKTproverka(Gweent[e].nomerKarti))
						{
							e = rand() % (111 - 84 + 1) + 84;
						}
					}
					ISKUSTVENNIYINTELLEKTPLAYER[i].power = Gweent[e].power;
					ISKUSTVENNIYINTELLEKTPLAYER[i].position = Gweent[e].position;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Kard = Gweent[e].Kard;
					ISKUSTVENNIYINTELLEKTPLAYER[i].koloda = Gweent[e].koloda;
					Gweent[e].Uigroka = 1;
					Gweent[e].Bito = 0;
					IIKARDS = 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Bito = 0;
					ISKUSTVENNIYINTELLEKTPLAYER[i].Uigroka = 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].texture = Gweent[e].texture;
					ISKUSTVENNIYINTELLEKTPLAYER[i].nomerKarti = Gweent[e].nomerKarti - Gweent[e].nomerKarti - Gweent[e].nomerKarti - 1;
					ISKUSTVENNIYINTELLEKTPLAYER[i].notshpion = 1;
					Gweent[e].notshpion = 1;
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].power);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].position);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].Kard);
					printf_s("%d\n", ISKUSTVENNIYINTELLEKTPLAYER[i].koloda);
					printf_s("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
				}
			}
		}
		int nomer1;

		if (hod == 1)
		{
			if (IIKOLOD == 0)
			{
				IIKARD = rand() % (29 - 0 + 1) + 0;
				if (IIKARD == 29)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
				{
					while (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
					{
						IIKARD = rand() % (29 - 0 + 1) + 0;
						if (IIKARD == 29)
						{
							flag = 2;
							space += 1;
							return;
						}
					}
				}
				if (kolodaII == 28)
				{
					flag = 2;
					space += 1;
					return;
				}
				else
				{
					kolodaII++;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (IIKARD == 29)
				{
					flag = 2;
					space += 1;
					return;
				}
			}
			if (IIKOLOD == 1)
			{
				IIKARD = rand() % (27 - 0 + 1) + 0;
				if (IIKARD == 27)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
				{
					while (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
					{
						IIKARD = rand() % (27 - 0 + 1) + 0;
						if (IIKARD == 27)
						{
							flag = 2;
							space += 1;
							return;
						}
					}
				}
				if (kolodaII == 26)
				{
					flag = 2;
					space += 1;
					return;
				}
				else
				{
					kolodaII++;
				}
				if (IIKARD == 27)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
			}
			if (IIKOLOD == 2)
			{
				IIKARD = rand() % (31 - 0 + 1) + 0;
				if (IIKARD == 31)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
				{
					while (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
					{
						IIKARD = rand() % (31 - 0 + 1) + 0;
						if (IIKARD == 31)
						{
							flag = 2;
							space += 1;
							return;
						}
					}
				}
				if (kolodaII == 30)
				{
					flag = 2;
					space += 1;
					return;
				}
				else
				{
					kolodaII++;
				}
				if (IIKARD == 31)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
			}
			if (IIKOLOD == 3)
			{
				IIKARD = rand() % (29 - 0 + 1) + 0;
				if (IIKARD == 29)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
				if (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
				{
					while (!PROVERKAINSKUSTVENNIYINTELLEKT(ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti))
					{
						IIKARD = rand() % (29 - 0 + 1) + 0;
						if (IIKARD == 29)
						{
							flag = 2;
							space += 1;
							return;
						}
					}
				}
				if (kolodaII == 28)
				{
					flag = 2;
					space += 1;
					return;
				}
				else
				{
					kolodaII++;
				}
				if (kolvokards == 0)
				{
					flag = 2;
					space += 1;
					return;
				}
			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].position == 1)
			{


				for (int j = 0; j < 15; j++)
				{
					if (urovenVraga3[j].nomerKarti == -100)
					{
						//uroven1[j].nomerKarti = nomer;

						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenVraga3[j].uroven.x;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenVraga3[j].uroven.y;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenVraga3[j].uroven.w;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenVraga3[j].uroven.h;
						IIPOWERR += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven3v++;
						uroven3vv += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						urovenVraga3[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						hod = 0;
						
						break;

					}
				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}


			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].position == 2)
			{


				for (int j = 0; j < 15; j++)
				{
					if (urovenVraga2[j].nomerKarti == -100)
					{
						//uroven1[j].nomerKarti = nomer;

						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenVraga2[j].uroven.x;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenVraga2[j].uroven.y;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenVraga2[j].uroven.w;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenVraga2[j].uroven.h;
						IIPOWERR += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven2v++;
						uroven2vv += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						urovenVraga2[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						hod = 0;
						
						break;

					}
				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}

			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].position == 3)
			{


				for (int j = 0; j < 15; j++)
				{
					if (urovenVraga1[j].nomerKarti == -100)
					{

						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenVraga1[j].uroven.x;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenVraga1[j].uroven.y;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenVraga1[j].uroven.w;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenVraga1[j].uroven.h;
						IIPOWERR += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven1v++;
						uroven1vv += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						urovenVraga1[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						hod = 0;
						
						break;

					}
				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}

			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].position == -1)
			{


				for (int j = 0; j < 15; j++)
				{
					if (urovenVraga3[j].nomerKarti == -100)
					{

						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = uroven3[j].uroven.x;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = uroven3[j].uroven.y;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = uroven3[j].uroven.w;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = uroven3[j].uroven.h;
						IIPOWERR += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven3v++;
						uroven3vv += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven3[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						hod = 0;
						
						break;

					}
				}kolvokards--;
						kolvokards += 2;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}

			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].position == -2)
			{


				for (int j = 0; j < 15; j++)
				{
					if (urovenVraga3[j].nomerKarti == -100)
					{

						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = uroven2[j].uroven.x;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = uroven2[j].uroven.y;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = uroven2[j].uroven.w;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = uroven2[j].uroven.h;
						IIPOWERR += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven2v++;
						uroven2vv += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven2[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						hod = 0;
						
						break;

					}
				}kolvokards--;
						kolvokards += 2;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}

			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].position == -3)
			{


				for (int j = 0; j < 15; j++)
				{
					if (urovenVraga3[j].nomerKarti == -100)
					{

						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = uroven1[j].uroven.x;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = uroven1[j].uroven.y;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = uroven1[j].uroven.w;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = uroven1[j].uroven.h;
						IIPOWERR += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						uroven1v++;
						uroven1vv += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
						urovenVraga1[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						hod = 0;
						
						break;

					}
				}kolvokards--;
						kolvokards += 2;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}

			}







			//////////////////////////////





			int f = -100;
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].position == 5)
			{
				for (int i = 0; i < 3; i++)
				{


					if (truba[i].nomerKarti == -100)
					{
						flagok = 1;
						//uroven1[j].nomerKarti = nomer;

						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = truba[i].uroven.x;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = truba[i].uroven.y;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = truba[i].uroven.w;
						ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = truba[i].uroven.h;
						//powerr += player11[nomer].power;
						truba[i].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;

						f = power(i - 2);
						IIPOWERR += f;
						hod = 1;
						
						
						break;

					}


				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}
			}






			///////////////////////////////






			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].Kard == 7)
			{

				for (int i = 0; i < 15; i++)
				{

					for (int j = 0; j < 15; j++)
					{
						if (urovenVraga3[j].nomerKarti == -100)
						{
							//	uroven3[j].nomerKarti = nomer;

							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenVraga3[j].uroven.x;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenVraga3[j].uroven.y;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenVraga3[j].uroven.w;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenVraga3[j].uroven.h;
							IIPOWERR += ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].power;
							urovenVraga3[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;

							if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].Kard == 1)
							{
								f = kart(1);
								IIPOWERR += f * f;
							}
							hod = 0;
							
							break;

						}

					}

				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}
			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].Kard == 9)
			{

					for (int j = 0; j < 7; j++)
					{
						if (urovenDlyaPogodi[j].nomerKarti == -100)
						{
							//	uroven3[j].nomerKarti = nomer;

							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenDlyaPogodi[j].uroven.x;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenDlyaPogodi[j].uroven.y;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenDlyaPogodi[j].uroven.w;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenDlyaPogodi[j].uroven.h;

							urovenDlyaPogodi[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;

							frost = 1;

							powerr -= uroven3dd - uroven3d;

							IIPOWERR -= uroven3vv - uroven3v;

							hod = 0;
							
							break;


						}
					
				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{

						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}
			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].Kard == 8)
			{
				

					for (int j = 0; j < 7; j++)
					{
						if (urovenDlyaPogodi[j].nomerKarti == -100)
						{
							//	uroven3[j].nomerKarti = nomer;

							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenDlyaPogodi[j].uroven.x;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenDlyaPogodi[j].uroven.y;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenDlyaPogodi[j].uroven.w;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenDlyaPogodi[j].uroven.h;

							urovenDlyaPogodi[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;

							fog = 1;

							powerr -= uroven2dd - uroven2d;

							IIPOWERR -= uroven2vv - uroven2v;

							hod = 0;
							
							break;

						}

					
				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}
			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].Kard == 10)
			{
				

					for (int j = 0; j < 7; j++)
					{
						if (urovenDlyaPogodi[j].nomerKarti == -100)
						{
							//	uroven3[j].nomerKarti = nomer;

							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenDlyaPogodi[j].uroven.x;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenDlyaPogodi[j].uroven.y;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenDlyaPogodi[j].uroven.w;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenDlyaPogodi[j].uroven.h;

							urovenDlyaPogodi[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;

							rain = 1;

							powerr -= uroven1dd - uroven1d;


							IIPOWERR -= uroven1vv - uroven1v;
							hod = 0;
							
							break;

						}

					
				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}
			}
			if (ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].Kard == 6)
			{
				

					for (int j = 0; j < 7; j++)
					{
						if (urovenDlyaPogodi[j].nomerKarti == -100)
						{
							//	uroven3[j].nomerKarti = nomer;

							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.x = urovenDlyaPogodi[j].uroven.x;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.y = urovenDlyaPogodi[j].uroven.y;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.w = urovenDlyaPogodi[j].uroven.w;
							ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].karta.h = urovenDlyaPogodi[j].uroven.h;

							urovenDlyaPogodi[j].nomerKarti = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;

							if (frost == 1)
							{
								powerr += uroven3dd - uroven3d;
								IIPOWERR += uroven3vv - uroven3v;
								frost = 0;
							}


							if (rain == 1)
							{
								powerr += uroven1dd - uroven1d;
								IIPOWERR += uroven1vv - uroven1v;
								rain = 0;
							}

							if (fog == 1)
							{
								powerr += uroven2dd - uroven2d;
								IIPOWERR += uroven2vv - uroven2v;
								fog = 0;
							}



							hod = 0;
							
							break;

						}
					

				}kolvokards--;
				for (int i = 0; i < 30; i++)
				{
					if (ISKUSTVENNIYINTELLEKTKART[i] == -100)
					{
						ISKUSTVENNIYINTELLEKTKART[i] = ISKUSTVENNIYINTELLEKTPLAYER[IIKARD].nomerKarti;
						return;
					}
				}
			}
		}
	}

}

//стол
SDL_Surface* myImagestol = IMG_Load("stol.png");
SDL_Texture* statTexture;
SDL_Texture* vs;

void kardbito()
{
	flag = -100;
	space = 0;
	fla = 0;
	for (int i = 0; i < 15; i++)
	{
		uroven1[i].nomerKarti = -100;
		uroven2[i].nomerKarti = -100;
		uroven3[i].nomerKarti = -100;
		urovenVraga1[i].nomerKarti = -100;
		urovenVraga2[i].nomerKarti = -100;
		urovenVraga3[i].nomerKarti = -100;
	}
	for (int i = 0; i < 7; i++)
		urovenDlyaPogodi[i].nomerKarti = -100;
	for (int i = 0; i < 6; i++)
	{
		truba[i].nomerKarti = -100;
	}
	powerr = 0;
	IIPOWERR = 0;
}

void LIVES()
{
	if (IIPOWERR > powerr)
	{
		LIVESR--;
		kardbito();
	}
	else
	{
		LIVESV--; kardbito();
	}
}

int WIN()
{
	if (LIVESR == 0)
		return 1;
	if (LIVESV == 0)
		return 0;
}

int t;

int menu(SDL_Renderer* renderer,SDL_Texture* TextureStol)
{
	 kolodaII = 0;
	 kolvokards = 10;
	SDL_Rect BUTTON = { 610,200,200,100 };
	for (int i = 0; i < 15; i++)
	{
		uroven1d = 0;
		uroven1dd = 0;
		uroven1v = 0;
		uroven1vv = 0;

		uroven2d = 0;
		uroven2dd = 0;
		uroven2v = 0;
		uroven2vv = 0;

		uroven3d = 0;
		uroven3dd = 0;
		uroven3v = 0;
		uroven3vv = 0;
		urovenplayer[i].nomerKarti = -100;
	}
	for (int i = 0; i < 114; i++)

	{
		player11[i].nomerKarti = -100;
		player11[i].Kard = -100;
		player11[i].koloda = -100;
		player11[i].notshpion = -100;
		player11[i].position = -100;
		player11[i].power = -100;
		player11[i].Uigroka = -100;
		player11[i].texture = NULL;



		ISKUSTVENNIYINTELLEKTPLAYER[i].nomerKarti = -100;
		ISKUSTVENNIYINTELLEKTPLAYER[i].Kard = -100;
		ISKUSTVENNIYINTELLEKTPLAYER[i].koloda = -100;
		ISKUSTVENNIYINTELLEKTPLAYER[i].notshpion = -100;
		ISKUSTVENNIYINTELLEKTPLAYER[i].position = -100;
		ISKUSTVENNIYINTELLEKTPLAYER[i].power = -100;
		ISKUSTVENNIYINTELLEKTPLAYER[i].Uigroka = -100;
		ISKUSTVENNIYINTELLEKTPLAYER[i].texture = NULL;
	}
	LIVESR = 2;
	LIVESV = 2;
	
	Scoiatael(renderer);
	Monsters(renderer);
	Northern(renderer);
	Nilfgaardian(renderer);
	int quit = 0;
	SDL_Event e;
	int flag = 0;
	char VMENU[10] = "Menu";

	char numer[10];
	char numerr[10];
	SDL_Rect neuR = { 100,0,200,400 };
	SDL_Rect monR = { 400,0,200,400 };
	SDL_Rect norR = { 700,0,200,400 };
	SDL_Rect nilR = { 1000,0,200,400 };
	SDL_Rect scoR = { 1300,0,200,400 };
	SDL_Rect LeaderBoardButton = { 760,900,200,100 };
	for (int i = 0; i < 36; i++)
	{
		UIGROKA[i] = -1;
		Kolodaa[i] = -1;
	}
	Cards(renderer);
	cardR();
	char LeaderBoards[5];
	int leaders = 0;
	char ii[5];
	while (!quit)
	{
		SDL_RenderClear(renderer);
		//SDL_PollEvent(&e);
		SDL_RenderCopy(renderer, TextureStol, NULL, &STOL);
		
		/*for (int i = 0; i < 15; i++)
		{
			SDL_RenderCopy(renderer, neutralTex[i], NULL, &neutralR[i]);
		}
		for (int i = 0; i < 16; i++)
		{
			SDL_RenderCopy(renderer, monsterTex[i], NULL, &monsterR[i]);
		}
		for (int i = 0; i < 16; i++)
		{
			SDL_RenderCopy(renderer, northernTex[i], NULL, &northernR[i]);
		}
		for (int i = 0; i < 18; i++)
		{
			SDL_RenderCopy(renderer, nilfgaardianTex[i], NULL, &nilfgaardianR[i]);
		}
		for (int i = 0; i < 18; i++)
		{
			SDL_RenderCopy(renderer, scoiataelTex[i], NULL, &scoiataelR[i]);
		}*/
		
		/*SDL_RenderCopy(renderer, neutralTex[0], NULL, &neuR);
		MenuText(renderer, MainMenuFont, white, 100, 500, 80, 160, "Neutral");*/
		SDL_RenderCopy(renderer, monsterTex[0], NULL, &monR);
		MenuText(renderer, MainMenuFont, white, 400, 500, 80, 160, "Monsters");
		SDL_RenderCopy(renderer, northernTex[15], NULL, &norR);
		MenuText(renderer, MainMenuFont, white, 700, 500, 80, 160, "Northern");
		SDL_RenderCopy(renderer, nilfgaardianTex[0], NULL, &nilR);
		MenuText(renderer, MainMenuFont, white, 1000, 500, 80, 160, "Nilfgaardian");
		SDL_RenderCopy(renderer, scoiataelTex[0], NULL, &scoR);
		MenuText(renderer, MainMenuFont, white, 1300, 500, 80, 160, "Scoiatael");
		MenuText(renderer, MainMenuFont, white, 760, 900, 100, 200, "Leaderboards");
		if (!flag)
		{/*
			BUTTON.y = 200;
			SDL_RenderCopy(renderer, vs, NULL, &BUTTON);
			BUTTON.y = 400;
			SDL_RenderCopy(renderer, statTexture, NULL, &BUTTON);*/

			SDL_PollEvent(&e);
			/*if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (SDL_BUTTON_LEFT && e.motion.x >= 100 && e.motion.x <= 300 && e.motion.y >= 0 && e.motion.y <= 400)
				{
					return 0;
				}
			}*/

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (SDL_BUTTON_LEFT && e.motion.x >= 400 && e.motion.x <= 600 && e.motion.y >= 0 && e.motion.y <= 400)
				{
					kolod = t;
					RazdacaKartIgrokam1(t);
					urovenn(renderer);
					ISKUSTVENNIYINTELLEKTKARTVOID(1);
					razdacha(renderer);
					return 3;
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (SDL_BUTTON_LEFT && e.motion.x >= 700 && e.motion.x <= 900 && e.motion.y >= 0 && e.motion.y <= 400)
				{
					kolod = t;
					RazdacaKartIgrokam1(t);
					urovenn(renderer);
					ISKUSTVENNIYINTELLEKTKARTVOID(1);
					razdacha(renderer);
					return 1;
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (SDL_BUTTON_LEFT && e.motion.x >= 1000 && e.motion.x <= 1200 && e.motion.y >= 0 && e.motion.y <= 400)
				{
					kolod = t;
					RazdacaKartIgrokam1(t);
					urovenn(renderer);
					ISKUSTVENNIYINTELLEKTKARTVOID(1);
					razdacha(renderer);
					return 2;
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (SDL_BUTTON_LEFT && e.motion.x >= 1300 && e.motion.x <= 1500 && e.motion.y >= 0 && e.motion.y <= 400)
				{
					kolod = t;
					RazdacaKartIgrokam1(t);
					urovenn(renderer);
					ISKUSTVENNIYINTELLEKTKARTVOID(1);
					razdacha(renderer);
					return 0;
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (SDL_BUTTON_LEFT && e.motion.x >= 760 && e.motion.x <= 960 && e.motion.y >= 900 && e.motion.y <= 1000)
				{
					leaders = !leaders;
					
				}
			}
			if (leaders == 1)
			{
				for (int i = 0; i < 5; i++)
				{
					_itoa(i, ii, 5);
					MenuText(renderer, MainMenuFont, white, 0, 50 + i * 200, 40, 60, ii);
					_itoa(LeaderBoard[i], LeaderBoards, 5);
					MenuText(renderer, MainMenuFont, white, 100, 50 + i * 200, 40, 60, LeaderBoards);
				}
			}
		}
		if (flag)
		{
			for (int i = 0; i < 5; i++)
			{
				_itoa(LeaderBoard[i], numer, 10);
				_itoa(i + 1, numerr, 10);
				MenuText(renderer, MainMenuFont, white, 300, 100 + i * 100, 40, 80, numerr);
				MenuText(renderer, MainMenuFont, white, 1200, 100 + i * 100, 40, 80, numer);
				

			}
			MenuText(renderer, MainMenuFont, white, 710, 620, 40, 100, VMENU);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (SDL_BUTTON_LEFT && e.motion.x >= 710 && e.motion.x <= 810 && e.motion.y >= 620 && e.motion.y <= 660)
				{
					flag = 0;
				}
			}

		}

		SDL_RenderPresent(renderer);
	}

	
	
}

int main(int argc, char* args[])
{
	
	

	leaderboardInit(LeaderBoard);
	int score = 0;
	TextInit();
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));//окно
	
	//карты колоды
	
	
	int j = 0;
	//
	
	//нужен ещё двумерный массив (для показания того, что происходит на поле)
	//карты бьются и карты которыми бьют

	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("balloon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	
	SDL_Texture* texturestol = SDL_CreateTextureFromSurface(renderer, myImagestol);


	
	
	 menu(renderer, texturestol);

	
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	SDL_Event event;

	
	
	int win = -100;
	//
	
	RisovkaW = 0;
	
	
	while (true)
	{
		SDL_PollEvent(&event);


		
			

		SDL_RenderCopy(renderer, texturestol, NULL, &STOL);
		

		
	
		
		


		//if (Win() == 1)
		//{
		//	score = 1;
		//	printf_s("Первый победил");
		//	leaderboardUpdate(LeaderBoard, score);
		//	break;
		//}
		//if (Win() == 2)
		//{
		//	score = 2;
		//	printf_s("Второй победил");
		//	leaderboardUpdate(LeaderBoard, score);
		//	break;
		//}
		if (hod == 0)
		{

			for (int i = 0; i < 15; i++)
			{
				if (player11[i].nomerKarti != -1)
				{
					if (event.type == SDL_MOUSEBUTTONDOWN)
					{
						if (event.motion.x >= urovenplayer[i].uroven.x && event.motion.x <= urovenplayer[i].uroven.x + urovenplayer[i].uroven.w && event.motion.y >= urovenplayer[i].uroven.y && event.motion.y <= urovenplayer[i].uroven.y + urovenplayer[i].uroven.h)
						{
							kards(renderer, urovenplayer[i].nomerKarti, texturestol);
						}
					}
				}
			}
			
			if (keystates[SDL_SCANCODE_SPACE]&&fla==0)
			{
				flag = 1;
				space += 1;
				fla = 1;
			}
			
		}
		if (hod == 1)
		{
			ISKUSTVENNIYINTELLEKT();
		}
		if (flag == 1)
			hod = 1;
		if (flag == 2)
			hod = 0;
		if (space != 1&&space!=0)
			LIVES();
		
			RenderCard(renderer,-20);
			ISKUSTVENNIYINTELLEKTRenderCard(renderer, -20);
			rendert(renderer);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		SDL_Delay(5);
		//SDL_RenderPresent(renderer);
		if (LIVESR == 0 || LIVESV == 0)
		{

			win = WIN();
			if (win == 0)
			{
				score = 1;
				printf_s("Алексей победил");
				leaderboardUpdate(LeaderBoard, score);
				kardbito();
				
				ISKUSTVENNIYINTELLEKTKARTVOID(1);
				menu(renderer, texturestol);
				 kolodaII = 0;
				 kolvokards = 10;
				 win = 0;
				 IIKARDS = -1;
				 flag = 0;
			}
			if (win == 1)
			{
				score = 2;
				printf_s("Не Алексей победил");
				leaderboardUpdate(LeaderBoard, score);
				kardbito();
				
				ISKUSTVENNIYINTELLEKTKARTVOID(1);
				menu(renderer, texturestol);
				 kolodaII = 0;
				 kolvokards = 10;
				 win = 0;
				 IIKARDS = -1;
				 flag = 0;
			}

		}
	}
	SDL_RenderClear(renderer);



	return 0;
}
