using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TanchetoGamesMadafaka
{
    class MazeGame
    {
        //Console variables
        const int WINDOW_WIDTH = 70;
        const int WINDOW_HEIGHT = 30;

        //Player variables
        static int playerX;
        static int playerY;
        const char player = '*';

        static List<int> wallsX = new List<int>();
        static List<int> wallsY = new List<int>();
        const char wall = '#';

        static bool playing = true;

        //Directions
        const int RIGHT = 0;
        const int LEFT = 1;
        const int UP = 2;
        const int DOWN = 3;

        static void Main()
        {
            //Set the console
            Console.SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
            Console.SetBufferSize(WINDOW_WIDTH, WINDOW_HEIGHT);
            Console.CursorVisible = false;

            //Set starting position for the player
            playerX = WINDOW_WIDTH / 2;
            playerY = WINDOW_HEIGHT / 2;

            //Set the walls
            SetTheWalls();
            DrawTheMap();

            GameLoop();

        }

        static void DrawThePlayer()
        {
            Console.SetCursorPosition(playerX, playerY);
            Console.Write(player);
        }

        static void GameLoop()
        {
            while (playing)
            {
                DrawThePlayer();
                MoveThePlayer();
            }
        }

        static void MoveThePlayer()
        {
            if (Console.KeyAvailable)
            {
                ConsoleKeyInfo key = Console.ReadKey();
                Console.SetCursorPosition(playerX, playerY);
                Console.Write(" ");

                if (key.Key == ConsoleKey.LeftArrow && playerCanMove(LEFT))
                {
                    playerX--;
                }
                else if (key.Key == ConsoleKey.RightArrow && playerCanMove(RIGHT))
                {
                    playerX++;
                }
                else if (key.Key == ConsoleKey.UpArrow && playerCanMove(UP))
                {
                    playerY--;
                }
                else if (key.Key == ConsoleKey.DownArrow && playerCanMove(DOWN))
                {
                    playerY++;
                }
                else if (key.Key == ConsoleKey.Escape)
                {
                    playing = false;
                }

                DrawTheMap();
            }
        }

        static void DrawTheMap()
        {
            for (int i = 0; i < wallsX.Count; i++)
            {
                Console.SetCursorPosition(wallsX[i], wallsY[i]);
                Console.WriteLine(wall);
            }
        }

        static void SetTheWalls()
        {
            wallsX.Add(10);
            wallsY.Add(10);

            wallsX.Add(11);
            wallsY.Add(10);

            wallsX.Add(12);
            wallsY.Add(10);

            wallsX.Add(13);
            wallsY.Add(10);

            wallsX.Add(14);
            wallsY.Add(10);

            wallsX.Add(15);
            wallsY.Add(10);

            wallsX.Add(15);
            wallsY.Add(11);

            wallsX.Add(15);
            wallsY.Add(12);

            wallsX.Add(16);
            wallsY.Add(12);
        }

        static bool playerCanMove(int direction)
        {
            for (int i = 0; i < wallsX.Count; i++)
            {
                if (direction == RIGHT)
                {
                    if (playerX + 1 == wallsX[i] && playerY == wallsY[i] && playerX < WINDOW_WIDTH - 1)
                    {
                        return false;
                    }
                }
                else if (direction == LEFT)
                {
                    if (playerX - 1 == wallsX[i] && playerY == wallsY[i] && playerX > 0)
                    {
                        return false;
                    }
                }
                else if (direction == DOWN)
                {
                    if (playerX == wallsX[i] && playerY + 1 == wallsY[i] && playerY < WINDOW_HEIGHT - 1)
                    {
                        return false;
                    }
                }
                else if (direction == UP)
                {
                    if (playerX == wallsX[i] && playerY - 1 == wallsY[i] && playerY > 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}