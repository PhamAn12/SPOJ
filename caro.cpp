#include<iostream>
#include<conio.h>
#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif
#include <windows.h> 
using namespace std;

 int x= 42,y = 13;
 int p1 = 0, p2 =0;
 int XuLy[50][50] ;
 

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm d?ch chuy?n con tr? d?n t?a d? x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void LoadGame (){
	textcolor (5);
	for (int i=0 ;i<40;i++){
		gotoxy (30,15);
		cout << "Loading Game ...";
		gotoxy(19+i,17);
		cout << char (220);
		Sleep(100);
		
	}
	Sleep(1000);
	system("cls");
}
void TextcolorGotoxy( int x, int y, char str, int color){
	gotoxy (x,y);
	textcolor (color);
	cout << str;
	textcolor(7);
}
void TextcolorGotoxystring( int x, int y, string str, int color){
	gotoxy (x,y);
	textcolor (color);
	cout << str;
	textcolor(7);
}
void MangKhong (int a[50][50]){
	for (int i =0 ;i<50;i++){
		for (int j =0;j<50;j++){
			a[i][j]= 0;
		}
	}
}
void LoadSerVer(){
	
	for (int i = 0;i <=100 ;){
		gotoxy(24,15);
		cout << "Connecting to Server Game "<<"    "<<i <<"%";
		Sleep(100);
		XoaManHinh();
		gotoxy(24,15);
		cout << "Connecting to Server Game ."<<"   "<<i <<"%";
		Sleep(100);
		XoaManHinh();
		gotoxy(24,15);
		cout << "Connecting to Server Game .."<<"  "<<i <<"%";
		Sleep(100);
		XoaManHinh();
		gotoxy(24,15);
		cout << "Connecting to Server Game ..."<<" "<<i <<"%" ;
		Sleep(100);
		XoaManHinh();
		i+=10;
		Sleep(300);
		system("cls");
	}
}
void InHuongDan(){
	TextcolorGotoxystring (4,7,"d:RIGHT",14);
	TextcolorGotoxystring (4,9,"a:LEFT",14);
	TextcolorGotoxystring (4,11,"w:DOWN",14);
	TextcolorGotoxystring (4,13,"s:DOWN",14);
	TextcolorGotoxystring (4,15,"q:QUIT",5);
	TextcolorGotoxystring (4,17,"r:PLAY",12);
}
void KeKhungHuongDan(){
	 //veduong vien khung
	for (int i = 0; i<11;i++){
		TextcolorGotoxy(2+i ,3,char(220),10);
		TextcolorGotoxy(2+i ,20,char(220),10);
			
	}
	for (int i = 1; i< 18;i++){
		TextcolorGotoxy (2,i+3,char(219),10);
		TextcolorGotoxy(12 ,i+3,char(219),10);
	}
	InHuongDan();
	
}
void KeKhungCaRo(){

	
	
	for (int i = 3 ; i<=21 ; i++){
		for (int j = 21 ; j<= 60 ; j++){
			if (i%2==0){
				if (j%2 == 0){
					TextcolorGotoxy(j ,i,char(219),12);	
				}
				else TextcolorGotoxy(j ,i,char(219),7);
			}
			if (i%2!=0){
				if (j%2 == 0){
					TextcolorGotoxy(j ,i,char(219),7);
				}
				else TextcolorGotoxy(j ,i,char(219),12);
			}
			
		}
	}
	for (int i = 0;i <7;i++){
		TextcolorGotoxy(32+i, 22,char (220),11);
		TextcolorGotoxy (42+i,22,char (220),11);
		TextcolorGotoxy (32+i,28,char (220),11);
		TextcolorGotoxy (42+i,28,char (220),11);
	}
	for (int i =1 ;i< 7;i++){
		TextcolorGotoxy(32,22+i,char (219),11);
		TextcolorGotoxy(42,22+i,char (219),11);
		TextcolorGotoxy(38,22+i,char (219),11);
		TextcolorGotoxy(48,22+i,char (219),11);
	}
	TextcolorGotoxystring (34,24,"NOT",7);
	TextcolorGotoxystring (44,24,"NOT",7);
	TextcolorGotoxystring (33,26,"PHOTO",7);
	TextcolorGotoxystring (43,26,"PHOTO",7);
	
}
void NhapTenNguoiChoi(string str1,string str2){
	TextcolorGotoxystring (25,15,"Press Player1's Name ",11);
	cin >> str1;
	system("cls");
	TextcolorGotoxystring (25,15,"Press Player2's Name ",11);
	cin >> str2;
	system("cls");
	TextcolorGotoxystring (33,29,str1,13);
	TextcolorGotoxystring (43,29,str2,13);
}
int XuLyThang (int a[50][50]){
	int Win = 0;
	for (int i = 0;i <50;i++){
		for (int j =0 ;j<50;j++){
			if ((a[i][j]==a[i+1][j])&&(a[i][j]==a[i+2][j])&&(a[i][j]==a[i+3][j])&&(a[i+4][j]==a[i][j])&&(a[i][j]!=0)){
				Win = 1;
				
				break;
			}
			if((a[i][j]==a[i+1][j+1])&&(a[i][j]==a[i+2][j+2])&&(a[i][j]==a[i+3][j+3])&&(a[i][j]==a[i+4][j+4])&&(a[i][j]!=0)){
				Win = 1;
				break;
			}
			if((a[i][j]==a[i+1][j-1])&&(a[i][j]==a[i+2][j-2])&&(a[i][j]==a[i+3][j-3])&&(a[i][j]==a[i+4][j-4])&&(a[i][j]!=0)){
				Win = 1;
				break;
			}
			if ((a[i][j]==a[i][j+1])&&(a[i][j]==a[i][j+2])&&(a[i][j]==a[i][j+3])&&(a[i][j+4]==a[i][j])&&(a[i][j]!=0)){
				Win = 1;
				break;
		}
	}
	
	}
	return Win;
}
void DiChuyen (){
	int luot = 0;
	TextcolorGotoxystring (62,10,"Turn of Player1: X",10);
	gotoxy (x,y);
	while (1){
		
		if (kbhit()) {
			char c = getch ();
			if (c=='q'||c=='Q'){
				gotoxy(30,30);
				exit(0);
			}
			if (c == 'a'||c == 'A') {
				if (x<=21) {
					x = 60;
					gotoxy(x,y);
				}
				else {
					x--;
					gotoxy(x,y);
				}
				
			}
			if (c=='d'|| c=='D'){
				if (x>=60){
					x=21;
					gotoxy(x,y);
				}
				else {
					x++;
					gotoxy(x,y);
				}
				
			}
			if (c=='w'||c=='W'){
				if (y<=3){
					y=21;
					gotoxy(x,y);
				}
				else {
					y--;
					gotoxy(x,y);
				}
				
			}
			if (c=='s'||c=='S'){
				if (y>=21){
					y=3;
					gotoxy(x,y);
				}
				else {
					y++;
					gotoxy(x,y);
				}
				
			}
			if (c == 'r'||c=='R'){
				if (XuLy[x][y] != 0 ){
				TextcolorGotoxystring (62,10,"   No Play Here    ",11);
				gotoxy(x,y);
				luot--;	
				}
				else {
					if (luot %2 == 0){
					
					XuLy[x][y] = 1;
					TextcolorGotoxystring (x,y,"x",10);
				
					TextcolorGotoxystring (62,10,"Turn of Player2: O",12);

				
				
					gotoxy(x,y);
				}
				
				else {
					XuLy[x][y] = 2;
					textcolor (7);
					TextcolorGotoxystring (x,y,"o",12);
					TextcolorGotoxystring (62,10,"Turn of Player1: X",10);

					gotoxy(x,y);
				}
				}
				
				luot++;
			}
			if (XuLyThang(XuLy) ==1){
				if (luot %2 != 0) {
					TextcolorGotoxystring (62,10,"Player 1 is Win   ",11);
					
					p1++;
					break;
				}
				else {
					TextcolorGotoxystring (62,10,"Player 2 is Win   ",11);
					p2++;
					break;
					
				}
			} 
		}
	
	}
		
}
void inmang(int a[50][50]){
	for (int i=0;i<50;i++){
		for (int j=0;j<50;j++){
			cout <<a[i][j];
		}
		cout <<endl;
	}
}
void Tiso(){
 
  gotoxy(39,25);
  textcolor(10);
  cout << p1;
  
  gotoxy(41,25);
  textcolor(12);
  cout << p2;
  
 
}

void PlayGame (){
	DiChuyen();
	char c = getch();
	TextcolorGotoxystring (62,10," Continue?y/n  ",5);
		cin >>c;
		
		if (c=='y'|| c=='Y') {
			MangKhong(XuLy);
 			Tiso();
			KeKhungCaRo();
			KeKhungHuongDan();
			PlayGame();
		}
		else if (c=='n'|| c== 'N'){
			exit(0);
		}
	
}
 

int main (){
	string a,b;
	resizeConsole(700,400);
	LoadSerVer();
	LoadGame();
    NhapTenNguoiChoi(a,b);
    TextcolorGotoxystring (62,25,"Dev :  PhamAn   ",14);
	KeKhungCaRo();
	KeKhungHuongDan();
	Tiso();
	PlayGame();
	Tiso();

}
