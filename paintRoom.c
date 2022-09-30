#include "paintRoom.h"

void recPaintRoom( RoomData room, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/ );
/* declare any other helper functions here*/
void findA( RoomData, int*, int* );
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

    /* Call any other helper functions (a helper function to find the location of 'A' in room may be handy) */
    int *rowA, *colA;
    
    findA( room, &rowA, &colA );
    
    /* Call your recursive function here */
    recPaintRoom( room, rowA, colA, 'A' );
}

/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location being explored, the distance traveled from 'A'
 * output: N/A
 */
void recPaintRoom( RoomData room, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/ )
{
    /* Base cases: */
    /*All directions are asterisks or previously explored*/

    if(room.roomArray[row][col] == '*' )
    {
      return;
    } 
           
    else if (room.roomArray[row][col] <= distanceFromA && room.roomArray[row][col] != ' ' && distanceFromA !=  'A' ){
      return;
    }
    
    else {
    
    if( distanceFromA > 90 )
    {
        distanceFromA = 90;
    }
    
    room.roomArray[row][col] = distanceFromA; 
    /* Recursive cases: */
    recPaintRoom( room, row, col + 1, distanceFromA + 1);
    recPaintRoom( room, row, col - 1, distanceFromA + 1);
    recPaintRoom( room, row + 1, col, distanceFromA + 1 );
    recPaintRoom( room, row - 1, col, distanceFromA + 1 );
    }
}
void findA ( RoomData room, int *rowA, int *colA ) 
{
    int i, j;
    
    for( i = 0; i < room.numrows; i++){
      for( j = 0; j < room.numcols; j++){
        if( room.roomArray[i][j] == 'A'){
          *rowA = i;
          *colA = j;
          return;     
        }
      }
    }
}
