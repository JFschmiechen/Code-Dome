/*
Author: Schmiechen, James
Description: My class programming assignment in C#. 
    This program creates a player roster that allows coaches to manipulate and update the
player list, ratings, jersey numbers, and to add new team members.
*/

/*
	TODO:
	- Fix bad input
    - Simplify booleans
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cSharpProject02
{
    class Program
    {

        static void badJersey(int x) // Checks for # not between 0 and 99
        {
            if (x > 99 || x < 0)
            {
                Console.WriteLine(x + " is an invalid value. Please try again. (0 - 99)\n");
            }
        }
        static void badRating(int y) // Checks for # not between 1 and 9
        {
            if (y < 1 || y > 9)
            {
                Console.WriteLine(y + " is an invalid value. Please try again. (1 - 9)\n");
            }
        }



        static void Main(string[] args)
        {
            List<int> jersey = new List<int>(5);
            List<int> rating = new List<int>(5);
            char menuChoice;
            int jerseyNum = 0, ratingNum = 0, tempJersey, playCount = 5;
            string temp;

            Console.WriteLine("Enter the jersey numbers (0 - 99) and ratings ( 1- 9) for five players." + Environment.NewLine);

            for (int i = 1; i <= playCount; i++)
            {
                do
                {

                    Console.WriteLine("Enter player " + i + "'s jersey number: ");
                    temp = Console.ReadLine();
                    Int32.TryParse(temp, out jerseyNum);
                    badJersey(jerseyNum); // Checks for bad input

                } while (jerseyNum > 99 || jerseyNum < 0);

                do
                {

                    Console.WriteLine("Enter Player " + i + "'s rating: ");
                    temp = Console.ReadLine();
                    Int32.TryParse(temp, out ratingNum);
                    badRating(ratingNum);

                } while ((ratingNum < 1 || ratingNum > 9));

                jersey.Add(jerseyNum);
                rating.Add(ratingNum);
                Console.WriteLine(Environment.NewLine);
            }
            do
            {
                Console.WriteLine(Environment.NewLine + "MENU" + Environment.NewLine
                + "a - Add player" + Environment.NewLine
                + "d - Remove player" + Environment.NewLine
                + "u - update player rating" + Environment.NewLine
                + "r - Output players above a rating" + Environment.NewLine
                + "o - Output roster" + Environment.NewLine
                + "q - Quit" + Environment.NewLine
                + Environment.NewLine + Environment.NewLine + "Choose an option: ");

                menuChoice = Console.ReadKey().KeyChar;
                switch (menuChoice)
                {
                case 'a': // Adds a player to the roster
                        do
                        {
                            Console.WriteLine(Environment.NewLine + "Enter a new player's jersey number: ");
                            temp = Console.ReadLine();
                            Int32.TryParse(temp, out jerseyNum);
                            badJersey(jerseyNum);

                            for (int i = 0; i < playCount; i++)
                            {
                                if (jerseyNum == jersey.ElementAt(i))
                                {

                                    Console.WriteLine(jerseyNum + " is already being used. Please enter a new number." + Environment.NewLine);
                                    break;

                                }
                            }

                            tempJersey = jersey.Find(item => item == jerseyNum);

                        } while ((jerseyNum > 99 || jerseyNum < 0) || (tempJersey == jerseyNum));
                               
                        do
                        {

                            Console.WriteLine(Environment.NewLine + "Enter the player's rating: ");
                            temp = Console.ReadLine();
                            Int32.TryParse(temp, out ratingNum);
                            badRating(ratingNum);

                        } while (ratingNum < 1 || ratingNum > 9);

                        jersey.Add(jerseyNum);
                        rating.Add(ratingNum);
                        playCount++;
                        break;

                case 'd': // Deletes a player from the roster

                        Console.WriteLine(Environment.NewLine + "Enter a jersey number: ");
                        temp = Console.ReadLine();
                        Int32.TryParse(temp, out jerseyNum);
                        badJersey(jerseyNum);
                        tempJersey = jersey.Find(item => item == jerseyNum);

                                jersey.Remove(jerseyNum);
                                rating.Remove(jerseyNum);
                                playCount--;
                            
                             if (!(Convert.ToBoolean(tempJersey)) && (jerseyNum < 99 && jerseyNum > 0))
                            {           
                                Console.WriteLine(jerseyNum + " is not on the roster. Please try a different number." + Environment.NewLine);
                                break;  // Specific error handling, returns error only if it cant find jerseyNum in jersey but still is in range (0 - 99)
                            }
                        
                        break;

                case 'r': // Outputs players above a rating

                        do
                        {

                            Console.WriteLine(Environment.NewLine + "Enter a rating: ");
                            temp = Console.ReadLine();
                            Int32.TryParse(temp, out ratingNum);
                            badRating(ratingNum);

                        } while (ratingNum < 1 || ratingNum > 9);

                        Console.WriteLine(Environment.NewLine + Environment.NewLine + "ABOVE" + Environment.NewLine + Environment.NewLine);

                        for (int i = 0, n = 1; i < playCount; i++, n++)
                        {
                            if (rating.ElementAt(i) > ratingNum)
                            {

                                Console.WriteLine(Environment.NewLine + "Player " + n + " -- Jersey number: " + jersey.ElementAt(i) + ", rating: " + rating.ElementAt(i) + Environment.NewLine);

                            }
                        }
                        break;

                case 'u': // Update player rating

                        do
                        {

                            Console.WriteLine(Environment.NewLine + "Enter a jersey number: ");
                            temp = Console.ReadLine();
                            Int32.TryParse(temp, out jerseyNum);
                            badJersey(jerseyNum);

                            tempJersey = jersey.Find(item => item == jerseyNum);
                            if (tempJersey != jerseyNum)
                            {
                                Console.WriteLine(jerseyNum + " is not part of the roster. Please try again." + Environment.NewLine);
                            }

                        } while (tempJersey != jerseyNum);
                        do
                        {

                            Console.WriteLine(Environment.NewLine + "Enter a new rating for the player: ");
                            temp = Console.ReadLine();
                            Int32.TryParse(temp, out ratingNum);
                            badRating(ratingNum);

                        } while (ratingNum < 1 || ratingNum > 9);

                        for (int i = 0; i < playCount; i++)
                        {
                            if (jerseyNum == jersey.ElementAt(i))
                            {
                                rating[i] = ratingNum;
                            }
                        }
                        break;

                case 'o': // Output roster

                        Console.WriteLine(Environment.NewLine);

                        for (int i = 0; i < playCount; i++)
                        {
                            Console.WriteLine("Player " + (i + 1) + " -- Jersey number: " + jersey.ElementAt(i) + ", Rating: " + rating.ElementAt(i) + Environment.NewLine);
                        }

                        Console.WriteLine(Environment.NewLine);
                        break;

                case 'q': // Quit

                        break;

                default:

                        Console.WriteLine(menuChoice + " is not a menu choice. Please try again." + Environment.NewLine);
                        break;
                }
            } while (menuChoice != 'q');
        }
    }
}
