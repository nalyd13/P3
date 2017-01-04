#include <iostream>
using namespace std;

void draw(int miss);

int main(){

draw(0);	
draw(1);
draw(2);
draw(3);
draw(4);
draw(5);
draw(6);
draw(7);

return 0;

}


void draw(int miss){

switch(miss){

case 0:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||            ó\n    ||\n    ||\n    ||\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;
case 1:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (ಠ_ಠ)\n    ||\n    ||\n    ||\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;
case 2:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (ಥ_ಥ)\n    ||            |\n    ||            |\n    ||\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;
case 3:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (Ͼ˳Ͽ)\n    ||            |\n    ||            |\n    ||           /\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;	
case 4:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (◕_◕)\n    ||            |\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;	
case 5:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (Ͼ˳Ͽ)..!!\n    ||           /|\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;	
case 6:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (x_x)\n    ||           /|\\\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;
case 7:
	cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||            0\n    ||           /|\\\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	break;					

}


}