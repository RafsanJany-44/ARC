using System;

namespace UnitTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("________________________________________");
        
          

            Calc obj= new Calc("72","9","4","30");
            Console.WriteLine(obj.accuracy());
            Console.WriteLine(obj.precision());
            
            Console.WriteLine(obj.sensitivity());
            Console.WriteLine(obj.specificity());
            
            Console.WriteLine(obj.f1Score());
            
        }

    }
}
