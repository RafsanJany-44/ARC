package sample;

import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;

public class BangladeshiFarmersTree implements ITree{
    private Canvas canvas;

    private Point top_left;
    private Point bottom_right;
    private Point center;

    private GraphicsContext graphicsContext;
    private CanvasSingleton canvasSingleton;

    private boolean shouldBeDrawn = true;

    private CurrentState currentState;

    public BangladeshiFarmersTree() {
        canvasSingleton = CanvasSingleton.getInstance();
        this.canvas = canvasSingleton.getCanvas();
        currentState = CurrentState.getInstance();
    }

    private void calculateCornerPoints(Point selectedPoint) {
        center = new Point(selectedPoint.x - 8, selectedPoint.y - 12);

        top_left = new Point(selectedPoint.x + 2, selectedPoint.y - 4);
        bottom_right = new Point(selectedPoint.x - 2, selectedPoint.y + 12);
    }

    @Override
    public void draw(Point point) {
        System.out.println(point.x);
        calculateCornerPoints(point);
        new Rectangle(top_left, bottom_right).draw();
        new Circle(center, 16).draw();
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
