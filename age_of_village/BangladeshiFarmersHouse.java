package sample;

import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;


public class BangladeshiFarmersHouse implements IHouse {

    private Canvas can;
    private GraphicsContext graphicsContext;

    private Point top_left;
    private Point bottom_right;
    private Point x;
    private Point y;

    private boolean Draw = true;
    private CurrentState currentState;

    public BangladeshiFarmersHouse() {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        this.can = canvasSingleton.getCanvas();
        currentState = CurrentState.getInstance();
    }

    private void calculateCornerPoints(Point selectedPoint) {
        top_left = new Point(selectedPoint.x - 8, selectedPoint.y - 2);
        bottom_right = new Point(selectedPoint.x + 8, selectedPoint.y + 8);

        x = new Point(selectedPoint.x, selectedPoint.y - 8);
        y = new Point(selectedPoint.x + 8, selectedPoint.y - 2);
    }

    @Override
    public void draw(Point point) {
        calculateCornerPoints(point);
        new Triangle(x, top_left, y).draw();
        new Rectangle(top_left, bottom_right).draw();
    }

    @Override
    public void canvasController() {
        graphicsContext = can.getGraphicsContext2D();

        can.addEventHandler(MouseEvent.MOUSE_PRESSED,
                new EventHandler<MouseEvent>() {

                    @Override
                    public void handle(MouseEvent event) {
                        if (Draw) {
                            Point selectedPoint = new Point((int) event.getX(), (int) event.getY());
                            draw(selectedPoint);
                            currentState.addHouse(selectedPoint);
                        }
                    }
                });
    }

    @Override
    public void releaseCanvas() {
        Draw = false;
    }

    @Override
    public void getCanvas() {
        Draw = true;
    }
}
