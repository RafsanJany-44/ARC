package sample;

import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;


public class EgyptianKingsWaterSource implements IWaterSource {
    private Canvas canvas;
    private GraphicsContext graphicsContext;
    private CurrentState currentState;
    private boolean shouldBeDrawn;
    private CanvasSingleton canvasSingleton;

    private Point center;

    public EgyptianKingsWaterSource() {
        canvasSingleton = CanvasSingleton.getInstance();
        this.canvas = canvasSingleton.getCanvas();
        currentState = CurrentState.getInstance();
    }

    private void calculateCornerPoints(Point selectedPoint) {
        center = new Point(selectedPoint.x, selectedPoint.y);
    }

    @Override
    public void draw(Point point) {
        calculateCornerPoints(point);
        new Circle(center, 12).draw();
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
