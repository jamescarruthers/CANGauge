// because, why not.

typedef struct Star {
    float x;
    float y;
    float z;
} Star;

const int STARNUMBER = 100;
Star stars[STARNUMBER];

void initStars() {

    for (int i = 0; i < STARNUMBER; i++) {
        stars[i].x = random(127);
        stars[i].y = random(63);
        stars[i].z = 0;
    }
}

void drawStars(int _x, int _y, int _w, int _h) {

    for (int i = 0; i < STARNUMBER; i++) {

        stars[i].z += 1;
        stars[i].x = (stars[i].x - (_x + _w / 2)) * 1.02  + (_x + _w / 2);
        stars[i].y = (stars[i].y - (_y + _h / 2)) * 1.02  + (_y + _h / 2);

        if (stars[i].x < _x || stars[i].x > _x + _w || stars[i].y < _y || stars[i].y > _y + _h || stars[i].z > 256) {
            stars[i].x = random(_w) + _x;
            stars[i].y = random(_h) + _y;
            stars[i].z = 0;
        }

        int starSize = map(stars[i].z, 0, _h, 0, 1);

        starSize = constrain(starSize, 0, 1);

        //u8g2.drawPixel(stars[i].x, stars[i].y);
        u8g2.drawDisc(stars[i].x, stars[i].y, starSize);

    }

}