using UnitTest;
using Xunit;
public class TestClass{
   Calc actual= new Calc("72","9","4","30");
   // acurate result what we are seeking for:
   float expectedAccuracy = 0.66086954f;
    float expectedPrecision = 0.8888889f;
    float expectedSensitivity = 0.7058824f;
    float expectedSpecificity = 0.30769232f;
    float expectedF1Score = 0.78688526f;

    [Fact]
    public void TestAccuracy()
    {
        Assert.Equal(expectedAccuracy,actual.accuracy());
    }
    [Fact]
    public void TestPrecision()
    {
        Assert.Equal(expectedPrecision,actual.precision());
    }
    [Fact]
    public void TestSensitivity()
    {
        Assert.Equal(expectedSensitivity,actual.sensitivity());
    }
    [Fact]
    public void TestSpecificity()
    {
        Assert.Equal(expectedSpecificity,actual.specificity());
    }
    [Fact]
    public void TestF1Score()
    {
        Assert.Equal(expectedF1Score,actual.f1Score());
    }


    Calc corrupt=new Calc("27","90","40","3");

    [Fact]
    public void TestAccuracy2()
    {
        Assert.Equal(expectedAccuracy,corrupt.accuracy());
    }
    [Fact]
    public void TestPrecisio2()
    {
        Assert.Equal(expectedPrecision,corrupt.precision());
    }
    [Fact]
    public void TestSensitivity2()
    {
        Assert.Equal(expectedSensitivity,corrupt.sensitivity());
    }
    [Fact]
    public void TestSpecificity2()
    {
        Assert.Equal(expectedSpecificity,corrupt.specificity());
    }
    [Fact]
    public void TestF1Score2()
    {
        Assert.Equal(expectedF1Score,corrupt.f1Score());
    }

    Calc emty=new Calc("34","","6","");

    [Fact]
    public void TestAccuracy3()
    {
        Assert.Equal(expectedAccuracy,emty.accuracy());
    }
    [Fact]
    public void TestPrecisio3()
    {
        Assert.Equal(expectedPrecision,emty.precision());
    }
    [Fact]
    public void TestSensitivity3()
    {
        Assert.Equal(expectedSensitivity,emty.sensitivity());
    }
    [Fact]
    public void TestSpecificity3()
    {
        Assert.Equal(expectedSpecificity,emty.specificity());
    }
    [Fact]
    public void TestF1Score3()
    {
        Assert.Equal(expectedF1Score,emty.f1Score());
    }

    
    
    
    
// checking some failed test
    
    Calc cha=new Calc("a","34","b","56");
   
   [Fact]
    public void FaildTestAccuracy4()
    {
        Assert.NotEqual(expectedAccuracy,cha.accuracy());
    }
    [Fact]
    public void FaildTestPrecisio4()
    {
        Assert.NotEqual(expectedPrecision,cha.precision());
    }
    [Fact]
    public void FaildTestSensitivity4()
    {
        Assert.NotEqual(expectedSensitivity,cha.sensitivity());
    }
    [Fact]
    public void FaildTestSpecificity3()
    {
        Assert.NotEqual(expectedSpecificity,cha.specificity());
    }
    [Fact]
    public void FaildTestF1Score4()
    {
        Assert.NotEqual(expectedF1Score,cha.f1Score());
    }

}