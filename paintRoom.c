#include "paintRoom.h"

void recPaintRoom( RoomData room, int row, int col, int distanceFromA, char distance /* feel free to remove/add any other parameters here*/ );
/* declare any other helper functions here*/
void findStart( int*, int*, RoomData );
/* printName
 * input: none
 * output: none
 *
 * Prints name the student who worked on this solution
 */
void printName( )
{
    /* TODO : Fill in your name*/
    printf("\nThis solution was completed by:\n");
    printf("Brent Harries\n");
}

/* TODO
 * paintRoom
 * input: the room to process
 * output: N/A
 *
 * This non-recursive function is called by the driver and it makes the initial call to recursive function recPaintRoom.
 */
void paintRoom( RoomData room )
{
    int row = 0;
    int col = 0;
    char distance = 'B';
    
    int* prow = &row;
    int* pcol = &col;
    
    /* Call any other helper functions (a helper function to find the location of 'A' in room may be handy) */
    findStart( row, col, room);
    /* Call your recursive function here */
    recPaintRoom( room, row, col, 0, distance);
}

/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location being explored, the distance traveled from 'A'
 * output: N/A
 */
void recPaintRoom( RoomData room, int row, int col, int distanceFromA, char distance /* feel free to remove/add any other parameters here*/ )
{
    /* Base cases: */
    /*All directions are asterisks or previously explored*/
    if(room.roomArray[row][col] == '*'){
      return;
    }

    room.roomArray[row][col] == distance;
    /* Recursive cases: */
    int i;
    for( i = 1; i < row; i++){
      recPaintRoom( room, i, col + 1, distanceFromA + 1, distance + 1 );
      recPaintRoom( room, i, col - 1, distanceFromA + 1,distance + 1  );
      recPaintRoom( room, i + 1, col, distanceFromA + 1,distance + 1  );
      recPaintRoom( room, i - 1, col, distanceFromA + 1,distance + 1  );
    }
    

}

void findStart( int* row, int* col, RoomData room )
{
    int i, j;
    
    for( i = 0; i < col; i++){
      for( j = 0; j < row; j++){
        if( room.roomArray[i][j] == 'A'){
          col = i;
          row = j;
          printf("Starting location of A: %d %d", room.roomArray[i], room.roomArray[j]);
          return;     
        }
      }
    }
} /*End findStart */
