// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#include <graphics.h>
#include <stdlib.h>

class tPoint {
private:
	int x, y, tipe, Color;
	bool flag;
public:
		void putPoint(){
			setcolor(Color);
			circle(x,y,2);
		}

		void setColor(int COLOR){
			Color = COLOR;
		}

		void setX(int newX){
		x = newX;
		}

		void setY(int newY){
		y = newY;
		}

		int getColor() { return Color; }
		
		int getX(){return x;}

		int getY(){return y;}

        void clear(){
            setcolor(COLOR(0,0,0));
            circle (x,y,2);
            setcolor(Color);
            }

		void linearMovement(){
            if (x == 490) flag = true;
            if (x == 0) flag = false;
            //if (x == )
				if (flag)
					x--;
				else
					x++;
		}
			void randomMovement(){
				while(1){
					if (x > 0 && x < 500) x += rand()%11 - 5;
					else x = rand()%250 + 150;
					if (y > 0 && y < 500) y += rand()%11 - 5;
					else y = rand()%250 + 150;
				}
			}
		
};

int main()
{
	tPoint arr[100];
	initwindow(500,500);
	for (int i = 0; i < 100; i++){
		arr[i].setX(rand()%300 + 100);
		arr[i].setY(rand()%300 + 100);
		arr[i].putPoint();
	}
	while(1){
        for (int i = 0; i < 100; i++){
            arr[i].clear();
            arr[i].linearMovement();
            arr[i].putPoint();  
        }
        delay(2);
        }
	getch();
}

