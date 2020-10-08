package sample;

import javafx.event.EventHandler;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;



public class ArabBedouinTree implements ITree {
    private Canvas canvas;
    private GraphicsContext graphicsContext;
    private CurrentState currentState;
    private boolean shouldBeDrawn;

    private Point top_left;
    private Point bottom_right;
    private Point x;
    private Point y;
    private Point z;
    private Point w;
    private Point u;


    public ArabBedouinTree() {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        this.canvas = canvasSingleton.getCanvas();
        currentState = CurrentState.getInstance();
    }

    private void calculateCornerPoints(Point selectedPoint) {
        top_left = new Point(selectedPoint.x + 2, selectedPoint.y - 4);
        bottom_right = new Point(selectedPoint.x - 2, selectedPoint.y + 12);

        x = new Point(selectedPoint.x, selectedPoint.y - 12);
        y = new Point(selectedPoint.x + 4, selectedPoint.y - 9);
        z = new Point(selectedPoint.x - 4, selectedPoint.y - 9);
        w = new Point(selectedPoint.x + 8, selectedPoint.y - 6);
        u = new Point(selectedPoint.x - 8, selectedPoint.y - 6);
    }

    @Override
    public void draw(Point point) {
        calculateCornerPoints(point);
        new Rectangle(top_left, bottom_right).draw();

        new Line(top_left, x).draw();
        new Line(top_left, y).draw();
        new Line(top_left, z).draw();
        new Line(top_left, w).draw();
        new Line(top_left, u).draw();
    }

    @Override
    public void canvasController() {
        graphicsContext = canvas.getGraphicsContext2D();

        canvas.addEventHandler(MouseEvent.MOUSE_PRESSED,
                new EventHandler<MouseEvent>() {

                    @Override
                    public void handle(MouseEvent event) {
                        if(shouldBeDrawn){
                            Point selectedPoint = new Point((int) event.getX(), (int) event.getY()) ;
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

