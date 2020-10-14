using System;

namespace TestLab2_3._2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Console.WriteLine(findSum(4));
        }

        public static int findSum(int numItems){
            int total= 0;
            int[] numbers= new int[]{1,2,3,4,5,6,7,8,9,10};
            if (numItems<=10){
                for(int count=0;count<numItems;count=count+1){
                    if(numbers[count]>0){
                        total=total+numbers[count];
                    }
                }
            }
            return total;
        }




    }
}
