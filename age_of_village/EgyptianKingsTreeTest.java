package sample;

import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;


public class EgyptianKingsTree implements ITree {
    private Canvas canvas;
    private GraphicsContext graphicsContext;
    private CurrentState currentState;
    private boolean shouldBeDrawn;

    private Point one;
    private Point two;
    private Point three;
    private Point four;
    private Point five;
    private Point six;
    private Point seven;
    private Point eight;
    private Point nine;


    public EgyptianKingsTree() {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        this.canvas = canvasSingleton.getCanvas();
        currentState = CurrentState.getInstance();
    }

    private void calculateCornerPoints(Point selectedPoint) {
        one = new Point(selectedPoint.x , selectedPoint.y + 8);
        two = new Point(selectedPoint.x - 6, selectedPoint.y );
        three = new Point(selectedPoint.x + 6, selectedPoint.y );

        four = new Point(selectedPoint.x - 12, selectedPoint.y );
        five = new Point(selectedPoint.x - 7, selectedPoint.y -4);
        six = new Point(selectedPoint.x - 2, selectedPoint.y - 4);

        seven = new Point(selectedPoint.x + 2, selectedPoint.y - 4);
        eight = new Point(selectedPoint.x + 7, selectedPoint.y - 4);
        nine = new Point(selectedPoint.x + 12, selectedPoint.y );
    }

    @Override
    public void draw(Point point) {
        calculateCornerPoints(point);

        new Line(one, two).draw();
        new Line(one, three).draw();

        new Line(two, four).draw();
        new Line(two, five).draw();
        new Line(two, six).draw();

        new Line(three, seven).draw();
        new Line(three, eight).draw();
        new Line(three, nine).draw();
    }

    @Override
    public void canvasController() {
        graphicsContext = canvas.getGraphicsContext2D();

        canvas.addEventHandler(MouseEvent.MOUSE_PRESSED,
                new EventHandler<MouseEvent>() {

                    @Override
                    public void handle(MouseEvent event) {
                        if (shouldBeDrawn) {
                            Point selectedPoint = new Point((int) event.getX(), (int) event.getY());
                            draw(selectedPoint);
                            currentState.addTree(selectedPoint);
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
