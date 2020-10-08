package sample;

public class Triangle implements IShape {
    private Point x;
    private Point y;
    private Point z;

    public Triangle(Point x, Point y, Point z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Override
    public void draw() {
        new Line(x, y).draw();
        new Line(y, z).draw();
        new Line(x, z).draw();
    }
}
