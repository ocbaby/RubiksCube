#include<iostream>
using namespace std;
enum color{RED,YELLOW,GREEN,BLUE,WHITE,BLACK};
color upsur[3][3], downsur[3][3], leftsur[3][3], rightsur[3][3], frontsur[3][3], backsur[3][3] ;
void initialize(color a[3][3], color b);
void Initialize();
void print(color * a);
color *sight = *frontsur;
void control();
color side[3];
void sur_cw(color a[3][3]);
void sur_anticw(color a[3][3]);
void u(), d(), l(), r(), f(), b(), U(), D(), L(), R(), F(), B();

int main()
{
	Initialize();
	print(sight);
	control();
	cin.get();
	return 0;
}

void initialize(color a[3][3],color b){
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2; j++)
			a[i][j] = b;
	}
}

void Initialize(){
	initialize(upsur, WHITE);
	initialize(downsur, BLACK);
	initialize(leftsur, RED);
	initialize(rightsur, YELLOW);
	initialize(frontsur, BLUE);
	initialize(backsur, GREEN);
}

void print(color * a){
	for (int i = 0; i <= 2; i++){
		for (int j = 0; j <= 2;j++)
			switch (*a){
			case WHITE: cout << " 8 "; a++; continue;
			case BLACK: cout << " 2 "; a++; continue;
			case RED: cout << " 4 "; a++; continue;
			case YELLOW: cout << " 6 "; a++; continue;
			case BLUE: cout << " 5 "; a++; continue;
			case GREEN: cout << " 0 "; a++; continue;
		}
		cout << endl;
	}
	for (int k = 1; k < 10; k++)a--;
}

void control (){
	cout << "输入udlrfb进行顺时针转动\n输入UDLRFB进行逆时针转动\n输入845620查看各面\n";
	while (1){
		char c = getchar();
		switch (c)
		{
		case 'u':u(); break;
		case 'd':d(); break;
		case 'l':l(); break;
		case 'r':r(); break;
		case 'f':f(); break;
		case 'b':b(); break;
		case 'U':U(); break;
		case 'D':D(); break;
		case 'L':L(); break;
		case 'R':R(); break;
		case 'F':F(); break;
		case 'B':B(); break;

		case '5':sight = *frontsur; break;
		case '8':sight = *upsur; break;
		case '4':sight = *leftsur; break;
		case '6':sight = *rightsur; break;
		case '2':sight = *downsur; break;
		case '0':sight = *backsur; break;

		}
		system("cls");
		print(sight);
		cout << "输入udlrfb进行顺时针转动\n输入UDLRFB进行逆时针转动\n输入845620查看各面\n";
		//win?
	}
}

void u(){
	sur_cw(upsur);

	for (int i = 0; i <= 2; i++)side[i] = backsur[0][i];
	for (int i = 0; i <= 2; i++)backsur[0][i] = leftsur[0][i];
	for (int i = 0; i <= 2; i++)leftsur[0][i] = frontsur[0][i];
	for (int i = 0; i <= 2; i++)frontsur[0][i] = rightsur[0][i];
	for (int i = 0; i <= 2; i++)rightsur[0][i] = side[i];
}
void U(){
	sur_anticw(upsur);
	
	for (int i = 0; i <= 2; i++) side[i] = rightsur[0][i];
	for (int i = 0; i <= 2; i++) rightsur[0][i] = frontsur[0][i];
	for (int i = 0; i <= 2; i++)frontsur[0][i] = leftsur[0][i];
	for (int i = 0; i <= 2; i++)leftsur[0][i] = backsur[0][i];
	for (int i = 0; i <= 2; i++) backsur[0][i] = side[i];
}
void d(){
	sur_cw(downsur);

	for (int i = 0; i <= 2; i++)side[i] = frontsur[2][i];
	for (int i = 0; i <= 2; i++)frontsur[2][i] = leftsur[2][i];
	for (int i = 0; i <= 2; i++)leftsur[2][i] = backsur[2][i];
	for (int i = 0; i <= 2; i++)backsur[2][i] = rightsur[2][i];
	for (int i = 0; i <= 2; i++)rightsur[2][i] = side[i];
}
void D(){
	sur_anticw(downsur);

	for (int i = 0; i <= 2; i++)side[i] = rightsur[2][i];
	for (int i = 0; i <= 2; i++)rightsur[2][i] = backsur[2][i];
	for (int i = 0; i <= 2; i++)backsur[2][i] = leftsur[2][i];
	for (int i = 0; i <= 2; i++)leftsur[2][i] = frontsur[2][i];
	for (int i = 0; i <= 2; i++)frontsur[2][i] = side[i];
}
void l(){
	sur_cw(leftsur);

	for (int i = 0; i <= 2; i++)side[i] = upsur[i][0];
	for (int i = 0; i <= 2; i++)upsur[i][0] = backsur[i][2];
	for (int i = 0; i <= 2; i++)backsur[i][2] = downsur[i][0];
	for (int i = 0; i <= 2; i++)downsur[i][0] = frontsur[i][0];
	for (int i = 0; i <= 2; i++)frontsur[i][0] = side[i];
}
void L(){
	sur_anticw(leftsur);

	for (int i = 0; i <= 2; i++)side[i] = frontsur[i][0];
	for (int i = 0; i <= 2; i++)frontsur[i][0] = downsur[i][0];
	for (int i = 0; i <= 2; i++)downsur[i][0] = backsur[i][2];
	for (int i = 0; i <= 2; i++)backsur[i][2] = upsur[i][0];
	for (int i = 0; i <= 2; i++)upsur[i][0] = side[i];
}
void r(){
	sur_cw(rightsur);

	for (int i = 0; i <= 2; i++)side[i] = upsur[i][2];
	for (int i = 0; i <= 2; i++)upsur[i][2] = frontsur[i][2];
	for (int i = 0; i <= 2; i++)frontsur[i][2] = downsur[i][2];
	for (int i = 0; i <= 2; i++)downsur[i][2] = backsur[2 - i][0];
	for (int i = 0; i <= 2; i++)backsur[2 - i][0] = side[i];
}
void R(){
	sur_anticw(rightsur);

	for (int i = 0; i <= 2; i++)side[i] = backsur[2 - i][0];
	for (int i = 0; i <= 2; i++)backsur[2 - i][0] = downsur[i][2];
	for (int i = 0; i <= 2; i++)downsur[i][2] = frontsur[i][2];
	for (int i = 0; i <= 2; i++)frontsur[i][2] = upsur[i][2];
	for (int i = 0; i <= 2; i++)upsur[i][2] = side[i];
}
void f(){
	sur_cw(frontsur);

	for (int i = 0; i <= 2; i++)side[i] = upsur[2][i];
	for (int i = 0; i <= 2; i++)upsur[2][i] = leftsur[2 - i][2];
	for (int i = 0; i <= 2; i++)leftsur[2 - i][2] = downsur[0][2 - i];
	for (int i = 0; i <= 2; i++)downsur[0][2 - i] = rightsur[i][0];
	for (int i = 0; i <= 2; i++)rightsur[i][0] = side[i];
}
void F(){
	sur_anticw(frontsur);

	for (int i = 0; i <= 2; i++)side[i] = rightsur[i][0];
	for (int i = 0; i <= 2; i++)rightsur[i][0] = downsur[0][2 - i];
	for (int i = 0; i <= 2; i++)downsur[0][2 - i] = leftsur[2 - i][2];
	for (int i = 0; i <= 2; i++)leftsur[2 - i][2] = upsur[2][i];
	for (int i = 0; i <= 2; i++)upsur[2][i] = side[i];
}
void b(){
	sur_cw(backsur);

	for (int i = 0; i <= 2; i++)side[i] = upsur[0][2 - i];
	for (int i = 0; i <= 2; i++)upsur[0][2 - i] = rightsur[2 - i][2];
	for (int i = 0; i <= 2; i++)rightsur[2 - i][2] = downsur[2][2 - i];
	for (int i = 0; i <= 2; i++)downsur[2][2 - i] = leftsur[i][0];
	for (int i = 0; i <= 2; i++)leftsur[i][0] = side[i];
}
void B(){
	sur_anticw(backsur);

	for (int i = 0; i <= 2; i++)side[i] = leftsur[i][0];
	for (int i = 0; i <= 2; i++)leftsur[i][0] = downsur[2][2 - i];
	for (int i = 0; i <= 2; i++)downsur[2][2 - i] = rightsur[2 - i][2];
	for (int i = 0; i <= 2; i++)rightsur[2 - i][2] = upsur[0][2 - i];
	for (int i = 0; i <= 2; i++)upsur[0][2 - i] = side[i];
}

void sur_cw(color a[3][3]){
	color sur[2];
	sur[0] = a[0][0];
	sur[1] = a[0][1];
	a[0][0] = a[2][0];
	a[0][1] = a[1][0];
	a[2][0] = a[2][2];
	a[1][0] = a[2][1];
	a[2][2] = a[0][2];
	a[2][1] = a[1][2];
	a[0][2] = sur[0];
	a[1][2] = sur[1];
}
void sur_anticw(color a[3][3]){
	color sur[2];
	sur[1] = a[1][2];
	sur[0] = a[0][2];
	a[1][2] = a[2][1];
	a[0][2] = a[2][2];
	a[2][1] = a[1][0];
	a[2][2] = a[2][0];
	a[1][0] = a[0][1];
	a[2][0] = a[0][0];
	a[0][1] = sur[1];
	a[0][0] = sur[0];
}