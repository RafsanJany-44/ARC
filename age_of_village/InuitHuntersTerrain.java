package sample;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class InuitHuntersTerrain implements ITerrain {
    @Override
    public void draw() {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        GraphicsContext graphicsContext = canvasSingleton.getCanvas().getGraphicsContext2D();
        graphicsContext.setFill(Color.web("#c5ede8"));
        graphicsContext.fillRect(0,0,600,400);
    }
}
