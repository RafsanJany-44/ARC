
using Xunit;

public class Test{
    [Fact]
    public void test1(){
        Assert.Equal(10,TestLab2_3._2.Program.findSum(4));
    }

    [Fact]
    public void test2(){
        Assert.Equal(3,TestLab2_3._2.Program.vod_return(3,4));
    }



    [Fact]
    public void test3(){
        Assert.Equal(5,TestLab2_3._2.Program.vod_return(3,4));
    }

}