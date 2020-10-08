package sample;
import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;


public class BangladeshiFarmersWaterSource implements IWaterSource{
    private Canvas canvas;
    private GraphicsContext graphicsContext;
    private boolean shouldBeDrawn;
    private CanvasSingleton canvasSingleton;
    private CurrentState currentState;

    private Point point_one;
    private Point point_two;
    private Point point_three;
    private Point point_four;
    private Point point_five;
    private Point point_six;
    private Point point_seven;
    private Point point_eight;
    private Point point_nine;

    public BangladeshiFarmersWaterSource() {
        canvasSingleton = CanvasSingleton.getInstance();
        this.canvas = canvasSingleton.getCanvas();
        currentState = CurrentState.getInstance();
    }

    private void calculateCornerPoints(Point selectedPoint) {
        point_one = new Point(selectedPoint.x - 12, selectedPoint.y);
        point_two = new Point(selectedPoint.x - 6, selectedPoint.y +4);
        point_three = new Point(selectedPoint.x - 3, selectedPoint.y + 8);
        point_four = new Point(selectedPoint.x - 2, selectedPoint.y + 1);
        point_five = new Point(selectedPoint.x + 4, selectedPoint.y + 8);
        point_six = new Point(selectedPoint.x + 12, selectedPoint.y + 4);
        point_seven = new Point(selectedPoint.x + 7, selectedPoint.y - 8);
        point_eight = new Point(selectedPoint.x + 2, selectedPoint.y - 2);
        point_nine = new Point(selectedPoint.x - 4, selectedPoint.y - 8);
    }


    @Override
    public void draw(Point point) {
        calculateCornerPoints(point);
        new Line(point_one, point_two).draw();
        new Line(point_two, point_three).draw();
        new Line(point_three, point_four).draw();
        new Line(point_four, point_five).draw();
        new Line(point_five, point_six).draw();
        new Line(point_six, point_seven).draw();
        new Line(point_seven, point_eight).draw();
        new Line(point_eight, point_nine).draw();
        new Line(point_nine,point_one).draw();
    }
    @Override
    public void canvasControlle() {
        graphicsContext = canvas.getGraphicsContext2D();

        canvas.addEventHandler(MouseEvent.MOUSE_PRESSED,
                new EventHandler<MouseEvent>() {

                    @Override
                    public void handle(MouseEvent event) {
                        if (shouldBeDrawn) {
                            Point selectedPoint = new Point((int) event.getX(), (int) event.getY());
                            draw(selectedPoint);
                            currentState.addWaterResource(selectedPoint);
                        }
                    }
                });
    }

    @Override
    public void releaseCanvas() {
        shouldBeDrawn = false;
    }

    @Override
    public void getCanvas() {
        shouldBeDrawn = true;
    }
}
