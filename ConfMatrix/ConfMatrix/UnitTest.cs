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

}