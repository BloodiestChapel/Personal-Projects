import java.util.*;

//package Projects.SnakeJava;

public class SnakeJava
{
    // Define arrowkeys/WASD
    private static final int KEY_UP		    = 72;
    private static final int KEY_DOWN	    = 80;
    private static final int KEY_LEFT	    = 75;
    private static final int KEY_RIGHT	    = 77;
	private static final eDirection STOP    = 0;

    // Gameover or not?
    boolean gameOver    = false;

    // Dimensions
    final int width		= 40; 
    final int height	= 20;

    // Snakehead Position
    int x;
    int y;

    // Prey Position
    int preyPosX;
    int preyPosY;

    // Score
    int score;

    // Tail Position
    int[] tailX = new tailX[100];

    int[] tailY = new tailY[100];

    // Tail length
    int nTail = 0;

    // Directions and STOP
    enum eDirection{
        STOP,
        LEFT,
        RIGHT,
        UP,
        DOWN;
    }


    eDirection dir;

    // Initialize Variables
    void Setup(){
        gameOver = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;

        // Random prey position
        preyPosX = width.random();
        preyPosY = height.random();

        score = 0;
    }

    // Input Function
    // What direction are ya pressin?
    void Input(){
        if (_kbhit()){
            switch (_getch()){
                // "A" or "Left Arrow"
            case 'a':
                dir = LEFT;
                break;

            case KEY_LEFT:
                dir = LEFT;
                break;

                // "D" or "Right Arrow"
            case 'd':
                dir = RIGHT;
                break;

            case KEY_RIGHT:
                dir = RIGHT;
                break;

                // "W" or "Up Arrow"
            case 'w':
                dir = UP;
                break;

            case KEY_UP:
                dir = UP;
                break;

                // "S" or "Down Arrow"
            case 's':
                dir = DOWN;
                break;

            case KEY_DOWN:
                dir = DOWN;
                break;

                // "X" or "Force Quit"
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    // Logic Function
    // Generic snake logic to be used
    // in a couple different languages
    void Logic(){
        // Initialize tail
        int prevX = tailX[0];
        int prevY = tailY[0];

        int prev2X;
        int prev2Y;

        tailX[0] = x;
        tailY[0] = y;

        // Movement is done by the
        // snake replacing it's previous
        // index when the screen refreshes
        // Must start at int i = 1 because
        // otherwise the snake will leave
        // it's butt behind
        for (int i = 1; i < nTail; i++){
            prev2X = tailX[i];
            prev2Y = tailY[i];

            tailX[i] = prevX;
            tailY[i] = prevY;

            prevX = prev2X;
            prevY = prev2Y;
        }

        // Change snake position when
        // valid key is pressed
        switch (dir){
        case LEFT:
            x--;
            break;

        case RIGHT:
            x++;
            break;

        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;

        default:
            break;
        }

        // Hitting walls ends the game
        if (x >= width){
            gameOver = true;
        }
        else if (x < 0){
            gameOver = true;
        }

        if (y >= height){
            gameOver = true;
        }
        else if (y < 0){
            gameOver = true;
        }

        // Crashing into body, reversing
        // direction, or hitting wall
        // ends game
        for (int i = 0; i < nTail; i++){
            if (tailX[i] == x && tailY[i] == y){
                gameOver = true;
            }
        }

        // Increase tail length when 
        // eating prey
        if (x == preyPosX && y == preyPosY){
            score += 10;
            preyPosX = rand() % width;
            preyPosY= rand() % height;
            nTail++;

        }
    }

    public static void main(String[] args){
        Setup();
        Logic();
        Input();
    }

}