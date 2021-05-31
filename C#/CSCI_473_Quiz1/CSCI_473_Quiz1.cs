/* 
 * 1.   A screenshot of a successfully run "Hello World" program. It needs to print your name, 
 *      and for bonus Cool Person Points, something about yourself.
 * 2.   In the background, should be the source code that built this executable
 * 3.   ... opened within Visual Studios, or some other alternate development enviroment.
*/

using System;
using system.collections.generic;
using system.Linq;
using system.Text;
using system.Threading.Tasks;

namespace Quiz1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Hello World! My name is: ");
            Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.Black;
            Console.Write("Dillon Chappell");
            Console.ResetColor();
            Console.WriteLine("\nI love horror as a genre. Some of my favorite franchises, stories, and media come from:\n");
            Console.WriteLine("\tCall of Cthulu by H.P. Lovecraft"); 
            Console.WriteLine("\tAlien & H.R. Giger");
            Console.WriteLine("\tJunji Ito and his artwork");
            Console.WriteLine("\tI hope I can become proficient enough with programming to make my own horror game someday!");
        }
    }
}