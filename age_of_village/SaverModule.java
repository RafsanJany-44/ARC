package sample;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class SaverModule {
    private File file;
    private CurrentState currentState;

    public SaverModule(File file) {
        this.file = file;
        currentState = CurrentState.getInstance();
    }

    public boolean FileSever(){
        try {
            PrintWriter writer;
            writer = new PrintWriter(file);
            writer.println(currentState.getCurrentStateObject());
            writer.close();
        } catch (IOException ex) {
            return false;
        }
        return true;
    }

}
