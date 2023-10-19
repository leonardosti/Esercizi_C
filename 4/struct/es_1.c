#include <stdio.h>
#include <stdlib.h>

struct punto
{
    int x;
    int y;
    int z;
};

void stampa_punto(struct punto pt1)
{
    printf("x: %d \n", pt1.x);
    printf("y: %d \n", pt1.y);
    printf("z: %d \n", pt1.z);
}

struct punto punto_modificato(struct punto pt1)
{
    int incremento = 0;

    printf("Inserire il valore di quanto si vuole incrementare i punto x, y, z:\n");
    scanf("%d", &incremento);
    pt1.x += incremento;
    pt1.y += incremento;
    pt1.z += incremento;

    return pt1;
}

int main(int argc, char *argv[])
{

    struct punto pt1;

    printf("Inserire x: \n");
    scanf("%d", &pt1.x);
    printf("Inserire y: \n");
    scanf("%d", &pt1.y);
    printf("Inserire z: \n");
    scanf("%d", &pt1.z);
    stampa_punto(pt1);
    struct punto pt2 = punto_modificato(pt1);
    stampa_punto(pt2);

    return 0;
}