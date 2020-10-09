using UnitTest;
using Xunit;
public class TestClass{
   Calc obj= new Calc("72","9","4","30");
   // acurate result what we are seeking for:
   float expectedAccuracy = 0.66086954;
    float expectedPrecision = 0.8888889;
    float expectedSensitivity = 0.7058824;
    float expectedSpecificity = 0.30769232;
    float expectedF1Score = 0.78688526;

    [Fact]
    public void TestAccuracy()
    {
        Assert.Equal(expectedAccuracy,obj.accuracy());
    }
}