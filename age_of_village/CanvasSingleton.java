package sample;
import javafx.scene.canvas.Canvas;

    public class CanvasSingleton {
        private static CanvasSingleton instance = null;
        private Canvas canvas;

        private CanvasSingleton() {
            canvas = new Canvas(600, 400);
        }

        public static CanvasSingleton getInstance() {
            if (instance == null)
                instance = new CanvasSingleton();
            return instance;
        }

        public Canvas getCanvas(){
            return canvas;
        }

        public Canvas renewCanvas(){
            instance = new CanvasSingleton();
            return instance.getCanvas();
        }
}