package sample;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.shape.ArcType;

public class Circle implements IShape{
    private Point center;
    private int diameter;

    public Circle(Point center, int diameter) {
        this.center = center;
        this.diameter = diameter;
    }

    @Override
    public void draw() {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        GraphicsContext graphicsContext = canvasSingleton.getCanvas().getGraphicsContext2D();
        graphicsContext.strokeArc(center.x, center.y, diameter, diameter, 0, 360, ArcType.OPEN);
    }
}
