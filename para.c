#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

int main() {
/* request auto detection */
int gdriver = DETECT, gmode, err;
int i, x, y;

/* initialize graphic mode */
initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
err = graphresult();

if (err != grOk) {
/* error occurred */
printf("Graphics Error: %s",
grapherrormsg(err));
return 0;
}

x = 50;
y = getmaxy() - 100;

for (i = 0; i < 900; i++) {
/* drawing the balloon first */
setcolor(LIGHTRED);
setfillstyle(SOLID_FILL, LIGHTRED);
arc(x, y, 0, 180, 40);

/* arcs in the baloon */
arc(x - 10, y, 0, 180, 10);
arc(x - 30, y, 0, 180, 10);
arc(x + 10, y, 0, 180, 10);
arc(x + 30, y, 0, 180, 10);
floodfill(x, y - 35, LIGHTRED);

/* threads connecting basket and balloon */
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL, DARKGRAY);
sector(x, y + 40, 0, 360, 30, 5);
line(x - 40, y, x - 30, y + 40);
line(x + 40, y, x + 30, y + 40);
line(x, y, x, y + 40);
line(x - 20, y, x - 10, y + 40);
line(x + 20, y, x + 10, y + 40);

/* basket in parachute */
setcolor(BROWN);
setfillstyle(SOLID_FILL, BROWN);
line(x - 30, y + 40, x - 18, y + 65);
line(x - 18, y + 65, x + 18, y + 65);
line(x + 30, y + 40, x + 18, y + 65);
ellipse(x, y + 40, 180, 360, 30, 5);
floodfill(x + 15, y + 60, BROWN);

/* manipulate subsequent position of parachute */
setcolor(WHITE);
line(0, getmaxy(), x - 30, y + 40);
if (i % 3 == 0) {
x = x - 1;
y = y + 1;
} else {
x = x + 1;
y = y - 1;
}
delay(500);
cleardevice();

}

getch();

/* deallocate memory allocated for graphic screen */
closegraph();
return 0;
}
