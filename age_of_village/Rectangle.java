package sample;

public class Rectangle implements IShape {
    private Point top_left;
    private Point top_right;
    private Point bottom_right;
    private Point bottom_left;

    public Rectangle(Point top_left, Point bottom_right) {
        this.top_left = top_left;
        this.bottom_right = bottom_right;

        top_right = new Point(bottom_right.x, top_left.y);
        bottom_left = new Point(top_left.x, bottom_right.y);
    }

    @Override
    public void draw() {
        new Line(top_left, top_right).draw();
        new Line(top_right, bottom_right).draw();
        new Line(bottom_right, bottom_left).draw();
        new Line(bottom_left, top_left).draw();
    }
}
