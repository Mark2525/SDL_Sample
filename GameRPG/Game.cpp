#include "GameWindow.h"
#include "GameObject.h"
#include "GameTexture.h"
#include <vector>

int screenWidth = 800;
int screenHeight = 600;

class monster
{
public:
	bool gameStart;
	int x, y, width, height;
	int mX;
	monster(SDL_Renderer* renderer);
	~monster();

	int Range;
	int base;

	bool HitTest(GameObject* ob);

	void Render();
private:
	GameObject* gameObject;
	bool Chkk;

};

monster::monster(SDL_Renderer* renderer)
{
	gameStart = true;
	Range = 200;
	x = 0;
	y = 0;
	base = 0;
	Chkk = false;
	gameObject = new GameObject(renderer);
	gameObject->Load("source/SPmonster2.png");
	gameObject->LoadClip("source/SPmoster2.animate");
	gameObject->width = 150;
	gameObject->height = 150;
	gameObject->SetAnimation(0, 19);
	gameObject->SetTimeScale(0.1);
	gameObject->Play();

}

monster::~monster()
{
	delete gameObject;
	gameObject = NULL;
}

void monster::Render()
{
	if(!gameStart)
		gameObject->Stop();
	gameObject->x = x;
	gameObject->y = y;
	gameObject->Render();

	if(!Chkk)
	{
		if(gameObject->GetStart() != 10 && gameObject->GetEnd() != 14)
		gameObject->SetAnimation(10, 14);
	if(gameStart)
		x+=1;

		if(base + (x - base) >= base + Range)
		{
			Chkk = true;
			//gameObject->SetFlip(SDL_FLIP_HORIZONTAL);
		}
	}else{
		if(gameObject->GetStart() != 5 && gameObject->GetEnd() != 9)

		gameObject->SetAnimation(5, 9);
	if(gameStart)
		x-=1;

		if(base + (x - base) <= base)
		{
			Chkk = false;
			//gameObject->SetFlip(SDL_FLIP_NONE);
		}
	}
}

bool monster::HitTest(GameObject* ob)
{
	return gameObject->HitTest(ob);
}	

GameWindow* bis;
GameObject* bg;
GameObject* wall;
GameObject* gameOver;
GameObject* gameWin;
GameObject* mc;

monster* mon;
monster* mon2;


SDL_Rect Clip[8];


int speed;
int mX,mY;
bool startGame;
bool end;
bool Kup, Kdown, Kleft, Kright, gameEnd;
/*
int Map[6][8] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
	
};*/
/*
struct position
{
	int x, y;
	position(int _x, int _y):x(_x), y(_y){}
};*/
/*vector<position*> tile;*/
vector<GameObject*> coin;
vector<monster*> monList;
/*
void GenMap()
{
	int i, a;

	for(i = 0; i < 6; i++)
	{
		for(a = 0; a < 8; a++)
		{
			if(Map[i][a] == 1)
			{
				tile.push_back(new position(a*100, i*100));
			}
		}
	}
}*/

void AddCoin(int x, int y)
{
	GameObject* ob = new GameObject(bis->GetRenderer());
	ob->Load("source/Coin.png");
	ob->LoadClip("source/Coin.animate");
	ob->x = (x*100)+28;
	ob->y = (y*100)+56;
	ob->width = 44;
	ob->height = 40;
	ob->SetTimeScale(0.8);
	ob->SetAnimation(0, 9);
	ob->Play();

	coin.push_back(ob);
}

void addMonster(int x, int y)
{
	monster* mon = new monster(bis->GetRenderer());
	mon->x = x*100;
	mon->y = (y*100)+(100-mon->height);;
	monList.push_back(mon);
}


void Start()
{
	mX = 0;
	mY = 0;

	startGame = true;
	
	speed = 4;
	Kup = false;
	Kdown = false;
	Kleft = false;
	Kright = false;

	bg = new GameObject(bis->GetRenderer());
	bg->Load("source/BGRPG.png");
	bg->width = 800;
	bg->height = 600;

	wall = new GameObject(bis->GetRenderer());
	wall->Load("source/BGRPG.png");
	wall->width = 100;
	wall->height = 100;

	//GenMap();

	AddCoin(1, 1);
	AddCoin(2, 1);
	AddCoin(5, 1);
	AddCoin(6, 1);
	AddCoin(1, 4);
	AddCoin(2, 4);
	AddCoin(5, 4);
	AddCoin(6, 4);

	mc = new GameObject(bis->GetRenderer());
	mc->Load("source/SPplayer2.png");
	mc->LoadClip("source/SPplayer2.animate");


	mc->x = 0;
	mc->y = 500;
	mc->width = 50;
	mc->height = 100;

	mc->SetTimeScale(0.3);
	mc->SetAnimation(0, 27);
	mc->Play();

	
	mon = new monster(bis->GetRenderer());
	mon->x = 0;
	mon->y = 100;
	mon->base = 0;
	
	mon2 = new monster(bis->GetRenderer());
	mon2->x = 400;
	mon2->y = 100;
	mon2->base = 400;

	monList.push_back(mon);
	monList.push_back(mon2);


	gameOver = new GameObject(bis->GetRenderer());
	gameOver->Load("source/GameOver2.png");
	gameOver->x = 150;
	gameOver->y = 100;
	gameOver->width = 500;
	gameOver->height = 400;

	gameWin = new GameObject(bis->GetRenderer());
	gameWin->Load("source/GameWin.png");
	gameWin->x = 150;
	gameWin->y = 100;
	gameWin->width = 500;
	gameWin->height = 400;

}
/*
bool CheckCollision(GameObject* ob, bool chk = false)
{
	int topLeft = Map[ob->y/100][ob->x/100];
	int topRight = Map[ob->y/100][(ob->x+ob->width-1)/100];
	int buttomLeft = Map[(ob->y+ob->height-1)/100][ob->x/100];
	int buttomRight = Map[(ob->y+ob->height-1)/100][(ob->x+ob->width-1)/100];

	if(topLeft == 1 || topRight == 1 || buttomLeft == 1 || buttomRight == 1)
	{
		if(chk)
		{
			if(topLeft == 1 && topRight == 1)
			{
					ob->y = ((ob->y/100)*100)+100;
					mY = 0;
			}
			if (buttomLeft == 1 || buttomRight == 1)
			{
				mY =0;
				ob->y = (((ob->y+ob->height-1)/100)*100)-ob->height;
				
			}
		}
		return true;
	}
	return false;
}*/

void Update()
{

	if(startGame)
	{

	int i;

	if(!end)
	{

	if(Kup)
	{
		mY = -speed;
		mX = 0;
	}
	else if(Kdown)
	{
		mY = speed;
		mX = 0;
	}
	else if(Kleft)
	{
		mX = -speed;
		mY = 0;
	}
	else if(Kright)
	{
		mX = speed;
		mY = 0;
	}
	else if(!Kleft && !Kright && !Kup && !Kdown)
	{
		mX = 0;
		mY = 0;
	}
	
	if(Kdown)
	{
		if(mc->GetStart() != 1 && mc->GetEnd() != 6)
		mc->SetAnimation(1, 6);
	}
	else if(Kleft)
	{
		if(mc->GetStart() != 7 && mc->GetEnd() != 13)
		mc->SetAnimation(7, 13);
	}
	else if(Kup)
	{
		if(mc->GetStart() != 14 && mc->GetEnd() != 20)
		mc->SetAnimation(14, 20);
	}
	else if(Kright)
	{
		if(mc->GetStart() != 21 && mc->GetEnd() != 27)
		mc->SetAnimation(21, 27);
	}
	else if(!Kdown && !Kleft && !Kup && !Kright)
	{
		mc->SetAnimation(0, 0);
	}




	cout << mY << endl;

	mc->y += mY;
	if(mc->y <= 0 || mc->y >= screenHeight-mc->height/* || mc->HitTest(wall)*/) 
	{
		mc->y -= mY;
	}

	mc->x += mX;
	if(mc->x <= 0 || mc->x >= screenWidth-mc->width /*|| mc->HitTest(wall)*/)
	{
		mc->x -= mX;
	}

	}
	bg->Render();	
	/*
	for(i = 0; i < tile.size(); i++)
 	{
 		wall->x = tile[i]->x;
 		wall->y = tile[i]->y;
 		wall->Render();
 	}*/

 		for(i = 0; i < monList.size(); i++)
 		{
 			//cout << "mon" << endl;
			monList[i]->gameStart = !end;

			//if(!end)
				//monList[i]->x += monList[i]->mX;

			monList[i]->Render();

			if(monList[i]->HitTest(mc))
			{
	
	cout << "END " << endl;
					end = true;
					mc->Stop();
	
			}
 		}

	cout << coin.size() << endl;

	for(i = 0; i < coin.size(); i++)
	{
		if(end)
			coin[i]->Stop();
		if(coin[i]->HitTest(mc))
		{
			delete coin[i];
			coin[i] = NULL;
			coin.erase(coin.begin()+i);
		}else{
			coin[i]->Render();
		}
	}
	}
	mc->Render();
	
	if(mon->HitTest(mc) || mon2->HitTest(mc))
	{
		gameOver->Render();
		gameEnd = true;
	}
	if(coin.size() == 0)
	{
		gameWin->Render();
		gameEnd = true;
		
	}

	
	
}

void Event()
{
	switch(bis->GetEvent().type)
	{
	case SDL_KEYDOWN:
		if(bis->GetEvent().key.keysym.sym == SDLK_UP)
		{
			Kup = true;
		}
		else if(bis->GetEvent().key.keysym.sym == SDLK_DOWN)
		{
		Kdown = true;
		}
		else if(bis->GetEvent().key.keysym.sym == SDLK_LEFT)
		{
			Kleft = true;
		}
		else if(bis->GetEvent().key.keysym.sym == SDLK_RIGHT)
		{
			Kright = true;
		}
		break;
	case SDL_KEYUP:
		if(bis->GetEvent().key.keysym.sym == SDLK_UP)
		{
			Kup = false;
		}
		else if(bis->GetEvent().key.keysym.sym == SDLK_DOWN)
		{
			Kdown = false;
		}
		else if(bis->GetEvent().key.keysym.sym == SDLK_LEFT)
		{
			Kleft = false;
		}
		else if(bis->GetEvent().key.keysym.sym == SDLK_RIGHT)
		{
			Kright = false;
		}
		break;
	}
}

void Close()
{
	int i;
	delete bg;
	bg = NULL;
	/*
	for(i = 0; i < tile.size(); i++)
	{
		delete tile[i];
		tile[i] = NULL;
	}
	tile.clear();*/

	for(i =0;i<coin.size();i++)
	{
		delete coin[i];
		coin[i] = NULL;
	}
	coin.clear();

 	delete mc;
 	mc = NULL;

 	delete mon;
 	mon = NULL;

 	delete mon2;
 	mon2 = NULL;

 	delete gameOver;
 	gameOver = NULL;

 	delete gameWin;
 	gameWin = NULL;

 	delete bis;
 	bis = NULL;
}

int main(int argc, char* argv[])
{
	bis = new GameWindow();
	if(!bis->CreateWindow("Sample Game", screenWidth, screenHeight))
	{
		cerr << "Can't Create GameWindow" << endl;
	}else{
		bis->Run((void*)&Start, (void*)&Update, (void*)&Event);
	}

	Close();

	return 0;
}