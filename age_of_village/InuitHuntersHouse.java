package sample;

import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;

public class InuitHuntersHouse implements IHouse {
    private Canvas can;
    private GraphicsContext graphicsContext;
    private CurrentState currentState;
    private boolean Draw = true;

    private Point c1;
    private Point c2;


    public InuitHuntersHouse() {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        this.can = canvasSingleton.getCanvas();
        currentState = CurrentState.getInstance();
    }

    private void calculateCornerPoints(Point selectedPoint) {
        c1 = new Point(selectedPoint.x -12, selectedPoint.y );
        c2 = new Point(selectedPoint.x -4, selectedPoint.y +8);
    }

    @Override
    public void draw(Point point) {
        calculateCornerPoints(point);
        new HalfCircle(c2, 10).draw();
        new HalfCircle(c1, 26).draw();
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
