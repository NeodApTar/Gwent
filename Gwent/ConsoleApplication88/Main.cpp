#include <SDL_ttf.h>
#include <SDL.h>
#include <cstdio>
#include <windows.h>
#include <locale.h>
#include <ctime>
#include <SDL_image.h>

#pragma warning(disable : 4996) // для отключения предупреждения в стр 17-20

//Некоторые константы нашего окна
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//dost-достоинство
//mast- масть
//kozir-козырь
struct INFOKart
{
	int dost, mast;
};






//функция по присвоению значения карты
void Deckdost36(INFOKart* Karta)
{

	Karta[0].dost = 6;
	Karta[1].dost = 6;
	Karta[2].dost = 6;
	Karta[3].dost = 6;

	Karta[4].dost = 7;
	Karta[5].dost = 7;
	Karta[6].dost = 7;
	Karta[7].dost = 7;

	Karta[8].dost = 8;
	Karta[9].dost = 8;
	Karta[10].dost = 8;
	Karta[11].dost = 8;

	Karta[12].dost = 9;
	Karta[13].dost = 9;
	Karta[14].dost = 9;
	Karta[15].dost = 9;

	Karta[16].dost = 10;
	Karta[17].dost = 10;
	Karta[18].dost = 10;
	Karta[19].dost = 10;

	Karta[20].dost = 11; //вальты
	Karta[21].dost = 11;
	Karta[22].dost = 11;
	Karta[23].dost = 11;

	Karta[24].dost = 12; //дамы
	Karta[25].dost = 12;
	Karta[26].dost = 12;
	Karta[27].dost = 12;

	Karta[28].dost = 13; //короли
	Karta[29].dost = 13;
	Karta[30].dost = 13;
	Karta[31].dost = 13;

	Karta[32].dost = 14; //тузы
	Karta[33].dost = 14;
	Karta[34].dost = 14;
	Karta[35].dost = 14;
}

//функция по присвоению масти
void Deckmast36(INFOKart* Karta)
{

	Karta[0].mast = 1; //крести
	Karta[1].mast = 2; //бубны
	Karta[2].mast = 3; //черви
	Karta[3].mast = 4; //пики

	Karta[4].mast = 1;
	Karta[5].mast = 2;
	Karta[6].mast = 3;
	Karta[7].mast = 4;

	Karta[8].mast = 1;
	Karta[9].mast = 2;
	Karta[10].mast = 3;
	Karta[11].mast = 4;

	Karta[12].mast = 1;
	Karta[13].mast = 2;
	Karta[14].mast = 3;
	Karta[15].mast = 4;

	Karta[16].mast = 1;
	Karta[17].mast = 2;
	Karta[18].mast = 3;
	Karta[19].mast = 4;

	Karta[20].mast = 1;
	Karta[21].mast = 2;
	Karta[22].mast = 3;
	Karta[23].mast = 4;

	Karta[24].mast = 1;
	Karta[25].mast = 2;
	Karta[26].mast = 3;
	Karta[27].mast = 4;

	Karta[28].mast = 1;
	Karta[29].mast = 2;
	Karta[30].mast = 3;
	Karta[31].mast = 4;

	Karta[32].mast = 1;
	Karta[33].mast = 2;
	Karta[34].mast = 3;
	Karta[35].mast = 4;
}

//функция проверяет на совпадение, возвращает 1,если совпало, 0 если не совпало
int Proverka(INFOKart* KartaUIgroka, INFOKart Player)
{
	for (int i = 0; i < 36; i++)
	{
		if (KartaUIgroka[i].dost == Player.dost && KartaUIgroka[i].mast == Player.mast)
			return 1;
	}
	return 0;
}

int ProverkaNaBito(INFOKart* KartaBito, INFOKart Player)
{
	for (int i = 0; i < 36; i++)
	{
		if (KartaBito[i].dost == Player.dost && KartaBito[i].mast == Player.mast)
			return 1;
	}
	return 0;
}

//функция раздаёт карты игрокам  Player1 и Player2
//заполняет массив карт у игроков
void RazdacaKartIgrokam(INFOKart* Karta, INFOKart Player1[], INFOKart Player2[], INFOKart* KartaUIgroka)
{
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
		//сделать проверку на то повторяется ли карта игрока
		j = rand() % (35 - 0 + 1) + 0;
		Player1[i].dost = Karta[j].dost;
		Player1[i].mast = Karta[j].mast;
		for (int o = 0; o < 36; o++)
		{
			if (Proverka(KartaUIgroka, Player1[i]))
			{
				while (Proverka(KartaUIgroka, Player1[i]))
				{
					j = rand() % (35 - 0 + 1) + 0;
					Player1[i].dost = Karta[j].dost;
					Player1[i].mast = Karta[j].mast;
				}

			}
		}
		for (int o = 0; o < 36; o++)
		{
			if (KartaUIgroka[o].dost == 0 && KartaUIgroka[o].mast == 0)
			{
				KartaUIgroka[o].dost = Karta[j].dost;
				KartaUIgroka[o].mast = Karta[j].mast;
				break;
			}
		}

		printf("%d-й) карта\n достоинство- %d\n масть-%d\n ", i + 1, Player1[i].dost, Player1[i].mast);
	}

	for (int i1 = 0; i1 < 6; i1++)
	{
		j = rand() % (35 - 0 + 1) + 0;
		Player2[i1].dost = Karta[j].dost;
		Player2[i1].mast = Karta[j].mast;
		for (int o = 0; o < 36; o++)
		{
			if (Proverka(KartaUIgroka, Player2[i1]))
			{
				while (Proverka(KartaUIgroka, Player2[i1]))
				{
					j = rand() % (35 - 0 + 1) + 0;
					Player2[i1].dost = Karta[j].dost;
					Player2[i1].mast = Karta[j].mast;
				}

			}
		}
		for (int o = 0; o < 36; o++)
		{
			if (KartaUIgroka[o].dost == 0 && KartaUIgroka[o].mast
				== 0)
			{
				KartaUIgroka[o].dost = Karta[j].dost;
				KartaUIgroka[o].mast = Karta[j].mast;
				break;
			}
		}
		printf("%d-й) карта\n достоинство- %d\n масть-%d\n ", i1 + 1, Player2[i1].dost, Player2[i1].mast);
	}
}

//функция рандомит число и проверяет его наличие у игроков
//если у игроков есть эта карта, то рандомится снова и так пока, её не будет у игроков
//последняя карта становится козырем
//возвращает козырную масть (kozir)
int SozdanieKolod(INFOKart* Karta, INFOKart* KartaKolod, INFOKart* KartaUIgroka)
{
	int kozir = 0;
	//kvk- карта колоды
	int kvk = 0;
	//kovlozapoln- количество заполненных карт колоды
	int kovlozapoln = 0;
	for (int o1 = 0; o1 < 24; o1++)
	{
		kvk = rand() % (35 - 0 + 1) + 0;
		//цикл по пробегу карт у игроков
		//пока сгенерированная карта= карте у игроков генеригуется заного
		while (Proverka(KartaUIgroka, Karta[kvk]) || Proverka(KartaKolod, Karta[kvk]))
		{
			kvk = rand() % (35 - 0 + 1) + 0;

		}

		KartaKolod[o1].dost = Karta[kvk].dost;
		KartaKolod[o1].mast = Karta[kvk].mast;

		kovlozapoln++;


		if (kovlozapoln == 24)
		{
			printf("%d-й) карта колоды| достоинство- %d\n масть-%d КОЗЫРЬ\n ", o1 + 1, KartaKolod[o1].dost, KartaKolod[o1].mast);
			kozir = KartaKolod[o1].mast;
		}
		else
			printf("%d-й) карта колоды| достоинство- %d\n масть-%d\n ", o1 + 1, KartaKolod[o1].dost, KartaKolod[o1].mast);
	}
	return kozir;
}

//функция просматривает карты колоды и игроков, если масть совпадает с козырной, то достоинство умножается на 10
void SozdanieKoz(INFOKart* Karta, int kozmast, INFOKart Player1[], INFOKart Player2[], INFOKart *KartaUIgroka, INFOKart* KartaKolod)
{	
	//пробег по картам игрока 1
	for (int i = 0; i < 6; i++)
	{
		if (kozmast == Player1[i].mast)
		{
			Player1[i].dost = Player1[i].dost * 10;
		}

		printf("%d-й) карта\n достоинство- %d\n масть-%d\n ", i + 1, Player1[i].dost, Player1[i].mast);

	}
	//пробег по картам игрока 2
	for (int i = 0; i < 6; i++)
	{
		if (kozmast == Player2[i].mast)
		{
			Player2[i].dost = Player2[i].dost * 10;
		}
		printf("%d-й) карта\n достоинство- %d\n масть-%d\n ", i + 1, Player2[i].dost, Player2[i].mast);
	}

	//увеличиваем достоинство карт у игроков
	for (int i = 0; i < 36; i++)
	{
		if (kozmast == KartaUIgroka[i].mast)
		{
			KartaUIgroka[i].dost = KartaUIgroka[i].dost * 10;
		}
		/*printf("-------------------------------------------------\n");
		printf("-------------------------------------------------\n");
		printf("-------------------------------------------------\n");
		printf("%d-й) карта\n достоинство- %d\n масть-%d\n ", i + 1, KartaUIgroka[i].dost, KartaUIgroka[i].mast);*/
	}
	for (int i = 0; i < 24; i++)
	{
		if (kozmast == KartaKolod[i].mast)
		{
			KartaKolod[i].dost = KartaKolod[i].dost * 10;
		}
	/*	printf("-------------------------------------------------\n");
		printf("-------------------------------------------------\n");
		printf("-------------------------------------------------\n");
		printf("%d-й) карта колоды| достоинство- %d\n масть-%d\n ", i + 1, KartaKolod[i].dost, KartaKolod[i].mast);*/
	}
}





////загрузка 2-ек
//SDL_Surface* myImage2k = SDL_LoadBMP("2k.bmp");
//SDL_Surface* myImage2b = SDL_LoadBMP("2b.bmp");
//SDL_Surface* myImage2c = SDL_LoadBMP("2c.bmp");
//SDL_Surface* myImage2p = SDL_LoadBMP("2p.bmp");
//
////загрузка 3-ек
//SDL_Surface* myImage3k = SDL_LoadBMP("3k.bmp");
//SDL_Surface* myImage3b = SDL_LoadBMP("3b.bmp");
//SDL_Surface* myImage3c = SDL_LoadBMP("3c.bmp");
//SDL_Surface* myImage3p = SDL_LoadBMP("3p.bmp");
//
////загрузка 4-ок
//SDL_Surface* myImage4k = SDL_LoadBMP("4k.bmp");
//SDL_Surface* myImage4b = SDL_LoadBMP("4b.bmp");
//SDL_Surface* myImage4c = SDL_LoadBMP("4c.bmp");
//SDL_Surface* myImage4p = SDL_LoadBMP("4p.bmp");
//
////загрузка 5-ок
//SDL_Surface* myImage5k = SDL_LoadBMP("5k.bmp");
//SDL_Surface* myImage5b = SDL_LoadBMP("5b.bmp");
//SDL_Surface* myImage5c = SDL_LoadBMP("5c.bmp");
//SDL_Surface* myImage5p = SDL_LoadBMP("5p.bmp");
//
////загрузка 6-ок
//SDL_Surface* myImage6k = SDL_LoadBMP("6k.bmp");
//SDL_Surface* myImage6b = SDL_LoadBMP("6b.bmp");
//SDL_Surface* myImage6c = SDL_LoadBMP("6c.bmp");
//SDL_Surface* myImage6p = SDL_LoadBMP("6p.bmp");
//
////загрузка 7-ок
//SDL_Surface* myImage7k = SDL_LoadBMP("7k.bmp");
//SDL_Surface* myImage7b = SDL_LoadBMP("7b.bmp");
//SDL_Surface* myImage7c = SDL_LoadBMP("7c.bmp");
//SDL_Surface* myImage7p = SDL_LoadBMP("7p.bmp");
//
////загрузка 8-ок
//SDL_Surface* myImage8k = SDL_LoadBMP("8k.bmp");
//SDL_Surface* myImage8b = SDL_LoadBMP("8b.bmp");
//SDL_Surface* myImage8c = SDL_LoadBMP("8c.bmp");
//SDL_Surface* myImage8p = SDL_LoadBMP("8p.bmp");
//
////загрузка 9-ок
//SDL_Surface* myImage9k = SDL_LoadBMP("9k.bmp");
//SDL_Surface* myImage9b = SDL_LoadBMP("9b.bmp");
//SDL_Surface* myImage9c = SDL_LoadBMP("9c.bmp");
//SDL_Surface* myImage9p = SDL_LoadBMP("9p.bmp");
//
////загрузка 10-ок
//SDL_Surface* myImage10k = SDL_LoadBMP("10k.bmp");
//SDL_Surface* myImage10b = SDL_LoadBMP("10b.bmp");
//SDL_Surface* myImage10c = SDL_LoadBMP("10c.bmp");
//SDL_Surface* myImage10p = SDL_LoadBMP("10p.bmp");
//
////загрузка вальтов
//SDL_Surface* myImageVk = SDL_LoadBMP("Vk.bmp");
//SDL_Surface* myImageVb = SDL_LoadBMP("Vb.bmp");
//SDL_Surface* myImageVc = SDL_LoadBMP("Vc.bmp");
//SDL_Surface* myImageVp = SDL_LoadBMP("Vp.bmp");
//
////загрузка дам
//SDL_Surface* myImageDk = SDL_LoadBMP("Dk.bmp");
//SDL_Surface* myImageDb = SDL_LoadBMP("Db.bmp");
//SDL_Surface* myImageDc =SDL_LoadBMP("Dc.bmp");
//SDL_Surface* myImageDp = SDL_LoadBMP("Dp.bmp");
//
////загрузка королей
//SDL_Surface* myImageKk = SDL_LoadBMP("Kk.bmp");
//SDL_Surface* myImageKb = SDL_LoadBMP("Kb.bmp");
//SDL_Surface* myImageKc = SDL_LoadBMP("Kc.bmp");
//SDL_Surface* myImageKp = SDL_LoadBMP("Kp.bmp");
//
////загрузка тузов
//SDL_Surface* myImagetk = SDL_LoadBMP("tk.bmp");
//SDL_Surface* myImagetb = SDL_LoadBMP("tb.bmp");
//SDL_Surface* myImagetc = SDL_LoadBMP("tc.bmp");
//SDL_Surface* myImagetp = SDL_LoadBMP("tp.bmp");

//загрузка рубашки
SDL_Surface* myImageback = SDL_LoadBMP("back.bmp");
//загрузка места для карты
SDL_Surface* myImagemestodK = SDL_LoadBMP("mestodK.bmp");
//стол
SDL_Surface* myImagestol = IMG_Load("stol.jpg");


//путь к текстурам карт
char const* PUTKART[] = {
	"6k.bmp",
	"7k.bmp",
	"8k.bmp",
	"9k.bmp",
	"10k.bmp",
	"Vk.bmp",
	"Dk.bmp",
	"Kk.bmp",
	"tk.bmp",

	"6b.bmp",
	"7b.bmp",
	"8b.bmp",
	"9b.bmp",
	"10b.bmp",
	"Vb.bmp",
	"Db.bmp",
	"Kb.bmp",
	"tb.bmp",

	"6c.bmp",
	"7c.bmp",
	"8c.bmp",
	"9c.bmp",
	"10c.bmp",
	"Vc.bmp",
	"Dc.bmp",
	"Kc.bmp",
	"tc.bmp",

	"6p.bmp",
	"7p.bmp",
	"8p.bmp",
	"9p.bmp",
	"10p.bmp",
	"Vp.bmp",
	"Dp.bmp",
	"Kp.bmp",
	"tp.bmp"

};









int main(int argc, char* args[])
{
	int kozmast = 0;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));//окно
	struct INFOKart Karta[36];
	//двумерный массив в котором у нас содержится о количестве кврт у определённого игрока
	//изначально заполнить карты игрока (картами с мастью -1), -1 обозначает, что это карты у нас нет
	INFOKart igra[3][35];
	INFOKart Player1[36] = {0,0};
	INFOKart Player2[36]= { 0,0 };
	INFOKart Player3[36]= { 0,0 };

	INFOKart KartXOD[6];
	INFOKart KartBET[6];



	INFOKart KartaUIgroka[36] = { 0,0 };
	INFOKart KartaBito[36] = { 0,0 };

	//карты колоды
	INFOKart KartaKolod[24] = { 0,0 };


	//
	SDL_Texture* KART[4][9];

	//нужен ещё двумерный массив (для показания того, что происходит на поле)
	//карты бьются и карты которыми бьют



	//присвоение картам достоинства
	Deckdost36(Karta);
	//присвоение картам масти
	Deckmast36(Karta);
	////////////////////////


	
	RazdacaKartIgrokam(Karta, Player1, Player2, KartaUIgroka);
	printf("-------------------------------------------------\n");
	kozmast=SozdanieKolod(Karta, KartaKolod, KartaUIgroka);
	printf("-------------------------------------------------\n");
	printf("-------------------------------------------------\n");
	printf("-------------------------------------------------\n");
	SozdanieKoz(Karta, kozmast, Player1, Player2, KartaUIgroka, KartaKolod);


	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("balloon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1240, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	//SDL_Texture* texture2k = SDL_CreateTextureFromSurface(renderer, myImage2k);
	//SDL_Texture* texture2b = SDL_CreateTextureFromSurface(renderer, myImage2b);
	//SDL_Texture* texture2c = SDL_CreateTextureFromSurface(renderer, myImage2c);
	//SDL_Texture* texture2p = SDL_CreateTextureFromSurface(renderer, myImage2p);

	//SDL_Texture* texture3k = SDL_CreateTextureFromSurface(renderer, myImage3k);
	//SDL_Texture* texture3b = SDL_CreateTextureFromSurface(renderer, myImage3b);
	//SDL_Texture* texture3c = SDL_CreateTextureFromSurface(renderer, myImage3c);
	//SDL_Texture* texture3p = SDL_CreateTextureFromSurface(renderer, myImage3p);

	//SDL_Texture* texture4k = SDL_CreateTextureFromSurface(renderer, myImage4k);
	//SDL_Texture* texture4b = SDL_CreateTextureFromSurface(renderer, myImage4b);
	//SDL_Texture* texture4c = SDL_CreateTextureFromSurface(renderer, myImage4c);
	//SDL_Texture* texture4p = SDL_CreateTextureFromSurface(renderer, myImage4p);

	//SDL_Texture* texture5k = SDL_CreateTextureFromSurface(renderer, myImage5k);
	//SDL_Texture* texture5b = SDL_CreateTextureFromSurface(renderer, myImage5b);
	//SDL_Texture* texture5c = SDL_CreateTextureFromSurface(renderer, myImage5c);
	//SDL_Texture* texture5p = SDL_CreateTextureFromSurface(renderer, myImage5p);

	//SDL_Texture* texture6k = SDL_CreateTextureFromSurface(renderer, myImage6k);
	//SDL_Texture* texture6b = SDL_CreateTextureFromSurface(renderer, myImage6b);
	//SDL_Texture* texture6c = SDL_CreateTextureFromSurface(renderer, myImage6c);
	//SDL_Texture* texture6p = SDL_CreateTextureFromSurface(renderer, myImage6p);

	//SDL_Texture* texture7k = SDL_CreateTextureFromSurface(renderer, myImage7k);
	//SDL_Texture* texture7b = SDL_CreateTextureFromSurface(renderer, myImage7b);
	//SDL_Texture* texture7c = SDL_CreateTextureFromSurface(renderer, myImage7c);
	//SDL_Texture* texture7p = SDL_CreateTextureFromSurface(renderer, myImage7p);

	//SDL_Texture* texture8k = SDL_CreateTextureFromSurface(renderer,myImage8k);
	//SDL_Texture* texture8b = SDL_CreateTextureFromSurface(renderer, myImage8b);
	//SDL_Texture* texture8c =SDL_CreateTextureFromSurface(renderer, myImage8c);
	//SDL_Texture* texture8p = SDL_CreateTextureFromSurface(renderer, myImage8p);

	//SDL_Texture* texture9k = SDL_CreateTextureFromSurface(renderer, myImage9k);
	//SDL_Texture* texture9b = SDL_CreateTextureFromSurface(renderer, myImage9b);
	//SDL_Texture* texture9c = SDL_CreateTextureFromSurface(renderer, myImage9c);
	//SDL_Texture* texture9p = SDL_CreateTextureFromSurface(renderer, myImage9p);

	//SDL_Texture* texture10k = SDL_CreateTextureFromSurface(renderer, myImage10k);
	//SDL_Texture* texture10b =SDL_CreateTextureFromSurface(renderer, myImage10b);
	//SDL_Texture* texture10c = SDL_CreateTextureFromSurface(renderer, myImage10c);
	//SDL_Texture* texture10p = SDL_CreateTextureFromSurface(renderer, myImage10p);

	//SDL_Texture* textureVk = SDL_CreateTextureFromSurface(renderer, myImageVk);
	//SDL_Texture* textureVb = SDL_CreateTextureFromSurface(renderer, myImageVb);
	//SDL_Texture* textureVc = SDL_CreateTextureFromSurface(renderer, myImageVc);
	//SDL_Texture* textureVp = SDL_CreateTextureFromSurface(renderer, myImageVp);

	//SDL_Texture* textureDk = SDL_CreateTextureFromSurface(renderer, myImageDk);
	//SDL_Texture* textureDb = SDL_CreateTextureFromSurface(renderer, myImageDb);
	//SDL_Texture* textureDc = SDL_CreateTextureFromSurface(renderer, myImageDc);
	//SDL_Texture* textureDp = SDL_CreateTextureFromSurface(renderer, myImageDp);

	//SDL_Texture* textureKk = SDL_CreateTextureFromSurface(renderer, myImageKk);
	//SDL_Texture* textureKb = SDL_CreateTextureFromSurface(renderer, myImageKb);
	//SDL_Texture* textureKc = SDL_CreateTextureFromSurface(renderer, myImageKc);
	//SDL_Texture* textureKp = SDL_CreateTextureFromSurface(renderer, myImageKp);

	//SDL_Texture* texturetk = SDL_CreateTextureFromSurface(renderer, myImagetk);
	//SDL_Texture* texturetb = SDL_CreateTextureFromSurface(renderer, myImagetb);
	//SDL_Texture* texturetc = SDL_CreateTextureFromSurface(renderer, myImagetc);
	//SDL_Texture* texturetp = SDL_CreateTextureFromSurface(renderer, myImagetp);


	SDL_Texture* textureback = SDL_CreateTextureFromSurface(renderer, myImageback);
	SDL_Texture* texturemestodK = SDL_CreateTextureFromSurface(renderer, myImagemestodK);
	SDL_Texture* texturestol = SDL_CreateTextureFromSurface(renderer, myImagestol);


	SDL_Surface* popit[4][9] = { NULL };

	for(int i=1;i<=4;i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			popit[i - 1][j - 1] = SDL_LoadBMP(PUTKART[(i - 1) * (j - 1)]);
		}

	}


	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			KART[i - 1][j - 1] = SDL_CreateTextureFromSurface(renderer,popit[i-1][j-1]);
		}

	}

	SDL_Rect STOL = { 0,0,1240,720 };

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	SDL_Event event;
	


	SDL_Rect RISKart = { 100,600,32,48 };

	while (true)
	{
		SDL_PollEvent(&event);

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texturestol, NULL, &STOL);

		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 9; j++)
			{

				if ((Player1[(i - 1) * (j - 1)].mast) == 0 || (Player1[(i - 1) * (j - 1)].dost) == 0)
				{
					continue;
				}

				RISKart.x = 100 + j * 20;

				//RISKart.y = 600 - j * 48;

				SDL_RenderCopy(renderer, KART[Player1[(i-1)*(j-1)].mast-1][Player1[(i - 1) * (j - 1)].dost-1], NULL, &RISKart);
			
			}

		}


		
		SDL_RenderPresent(renderer);
	}
	SDL_RenderClear(renderer);

	

	return 0;
}