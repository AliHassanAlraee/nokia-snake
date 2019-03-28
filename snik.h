#ifndef SNIK_H
#define SNIK_H


class snik
{
    public:
        int food , snake;
        char o;                      // It will help in changing snake direction
        char arr[6][20];            // In which snake move and food generate
        int level;
        int points;

        snik();
        void playground();
        void turn();
        void moveOn();
};

#endif // SNIK_H
