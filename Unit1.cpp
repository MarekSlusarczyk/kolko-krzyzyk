//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int kolejka = 0; // 0 - kolko, 1 - krzyzyk
bool image2_clicked = false;
bool image3_clicked = false;
bool image4_clicked = false;
bool image5_clicked = false;
bool image6_clicked = false;
bool image7_clicked = false;
bool image8_clicked = false;
bool image9_clicked = false;
bool image10_clicked = false;


int ruchKolko = 0;
int ruchKrzyzyk = 0;
int wynikiKolko[9];
int wynikiKrzyzyk[9];
int kombinacje[8][3] = {
	{1, 4, 7},
	{2, 5, 8},
	{3, 6, 9},
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{1, 5, 9},
	{3, 5, 7},
};

int height = 0;
int width = 0;
int rysujLinie(int indeks) {

	if(indeks == 0) {
		Form1->Image11->Left = -128;
		Form1->Image11->Visible = True;
		Form1->Timer1->Enabled = True;

        return true;
	} else if (indeks == 1) {
		Form1->Image11->Left = -8;
		Form1->Image11->Visible = True;
		Form1->Timer1->Enabled = True;

		return true;
	} else if (indeks == 2) {
		Form1->Image11->Left = 96;
		Form1->Image11->Visible = True;
		Form1->Timer1->Enabled = True;

		return true;
	} else if (indeks == 3) {
		Form1->Image12->Top = -217;
		Form1->Image12->Visible = True;
		Form1->Timer2->Enabled = True;

		return true;
	} else if (indeks == 4) {
		Form1->Image12->Top = -113;
		Form1->Image12->Visible = True;
		Form1->Timer2->Enabled = True;

		return true;
	} else if (indeks == 5) {
		Form1->Image12->Top = -1;
		Form1->Image12->Visible = True;
		Form1->Timer2->Enabled = True;

		return true;
	} else if (indeks == 6) {
		Form1->Image14->Visible = True;
		Form1->Timer4->Enabled = True;

		return true;
	} else if (indeks == 7) {
		Form1->Image13->Visible = True;
		Form1->Timer3->Enabled = True;

		return true;
	}

    return false;

}


bool czyTablicaZawieraKombinacje(int wyniki[9], int kombinacje[3]) {
	int zgodneKombinacje = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			if (wyniki[i] == kombinacje[j]) {
				zgodneKombinacje++;
				break;
			}
		}
	}

	if(zgodneKombinacje == 3) {
		return true;
	} else {
		return false;
	}
}


int sprawdzKombinacje(int wyniki[9], int kombinacje[8][3]) {
	for (int i = 0; i < 8; i++) {
		if (czyTablicaZawieraKombinacje(wyniki, kombinacje[i])) {
		   //	ShowMessage("indeks kombinacji: " + IntToStr(i));
			return i;
        }
    }
	return -1;
}


int zmienKolejke() {
	if (kolejka == 0) {
		int indeks = sprawdzKombinacje(wynikiKolko, kombinacje);
		Form1->Label1->Caption = "Ruch: krzy¿yk";

		if(rysujLinie(indeks)) {
			Form1->Label1->Caption = "Wygrana: kó³ko";
			Form1->Button1->Visible = True;
		};

		kolejka = 1;
	} else {
		int indeks = sprawdzKombinacje(wynikiKrzyzyk, kombinacje);
		Form1->Label1->Caption = "Ruch: kó³ko";
		if(rysujLinie(indeks)) {
			Form1->Label1->Caption = "Wygrana: krzy¿yk";
			Form1->Button1->Visible = True;
		};

        kolejka = 0;
	}

	if (ruchKrzyzyk >= 4 && ruchKolko >= 4) {
		Form1->Label1->Caption = "Brak wygranej";
		Form1->Button1->Visible = True;
	}
}

void __fastcall TForm1::Image2Click(TObject *Sender)
{
	if (!image2_clicked) {
		if (kolejka == 0) {
			Image2->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 1;
			ruchKolko++;
		} else {
			Image2->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 1;
			ruchKrzyzyk++;
		}
		image2_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
	if(!image3_clicked) {
		if (kolejka == 0) {
			Image3->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 2;
			ruchKolko++;
		} else {
			Image3->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 2;
			ruchKrzyzyk++;
		}
		image3_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image4Click(TObject *Sender)
{
	if(!image4_clicked) {
		if (kolejka == 0) {
			Image4->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 3;
			ruchKolko++;
		} else {
			Image4->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 3;
			ruchKrzyzyk++;
		}
        image4_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
	if(!image5_clicked) {
		if (kolejka == 0) {
			Image5->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 4;
			ruchKolko++;
		} else {
			Image5->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 4;
			ruchKrzyzyk++;
		}
		image5_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
	if(!image6_clicked) {
		if (kolejka == 0) {
			Image6->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 5;
			ruchKolko++;
		} else {
			Image6->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 5;
			ruchKrzyzyk++;
		}
		image6_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image7Click(TObject *Sender)
{
	if(!image7_clicked) {
		if (kolejka == 0) {
			Image7->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 6;
			ruchKolko++;
		} else {
			Image7->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 6;
			ruchKrzyzyk++;
		}
		image7_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{
	if(!image8_clicked) {
		if (kolejka == 0) {
			Image8->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 7;
			ruchKolko++;
		} else {
			Image8->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 7;
			ruchKrzyzyk++;
		}
		image8_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{
	if(!image9_clicked) {
		if (kolejka == 0) {
			Image9->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 8;
			ruchKolko++;
		} else {
			Image9->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 8;
			ruchKrzyzyk++;
		}
		image9_clicked = true;
		zmienKolejke();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10Click(TObject *Sender)
{
	if(!image10_clicked) {
		if (kolejka == 0) {
			Image10->Picture->LoadFromFile("../../kolko.png");

			wynikiKolko[ruchKolko] = 9;
			ruchKolko++;
		} else {
			Image10->Picture->LoadFromFile("../../krzyzyk.png");

			wynikiKrzyzyk[ruchKrzyzyk] = 9;
			ruchKrzyzyk++;
		}
		image10_clicked = true;
		zmienKolejke();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if (height > 416) {
		Timer1->Enabled=false;
	 }  else {
		Image11->Height = height;
		height = height + 10;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	if (width > 425) {
		Timer2->Enabled=false;
	 }  else {
		Image12->Width = width;
		width = width + 10;
	 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	if (height > 423) {
		Timer1->Enabled=false;
	 }  else {
		Image13->Height = height;
		height = height + 10;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
	if (height > 433) {
		Timer1->Enabled=false;
	 }  else {
		Image14->Height = height;
		height = height + 10;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	kolejka = 0;
	image2_clicked = false;
	image3_clicked = false;
	image4_clicked = false;
	image5_clicked = false;
	image6_clicked = false;
	image7_clicked = false;
	image8_clicked = false;
	image9_clicked = false;
	image10_clicked = false;

	Image2->Picture->Bitmap->Assign(NULL);
	Image3->Picture->Bitmap->Assign(NULL);
	Image4->Picture->Bitmap->Assign(NULL);
	Image5->Picture->Bitmap->Assign(NULL);
	Image6->Picture->Bitmap->Assign(NULL);
	Image7->Picture->Bitmap->Assign(NULL);
	Image8->Picture->Bitmap->Assign(NULL);
	Image9->Picture->Bitmap->Assign(NULL);
	Image10->Picture->Bitmap->Assign(NULL);

	ruchKolko = 0;
	ruchKrzyzyk = 0;

	Image11->Visible = False;
	Image12->Visible = False;
	Image13->Visible = False;
	Image14->Visible = False;

    Form1->Button1->Visible = False;


	for (int i = 0; i <= 9; i++) {
		wynikiKolko[i] = -1;
	}

	for (int i = 0; i <= 9; i++) {
		wynikiKrzyzyk[i] = -1;
	}

    Form1->Label1->Caption = "Ruch: kó³ko";
}
//---------------------------------------------------------------------------

