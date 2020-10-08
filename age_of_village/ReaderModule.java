package sample;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.io.File;

public class ReaderModule {
    private File file;
    private JsonObject jsonObject;

    public ReaderModule(File file) {
        this.file = file;
        loadJson();
    }

    private void loadJson(){
        JsonParser parser = new JsonParser();

        try {
            Object obj = parser.parse(new java.io.FileReader(file));
            jsonObject = (JsonObject) obj;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String getVillageName(){
        return jsonObject.get("villageName").getAsString();
    }

    public JsonArray getTree_axisX(){
        return jsonObject.getAsJsonArray("tree_axisX");
    }

    public JsonArray getTree_axisY(){
        return jsonObject.getAsJsonArray("tree_axisY");
    }

    public JsonArray getHouse_axisX(){
        return jsonObject.getAsJsonArray("house_axisX");
    }

    public JsonArray getHouse_axisY(){
        return jsonObject.getAsJsonArray("house_axisY");
    }
    public JsonArray getWaterResource_axisX(){
        return jsonObject.getAsJsonArray("waterResource_axisX");
    }

    public JsonArray getWaterResource_axisY(){
        return jsonObject.getAsJsonArray("waterResource_axisY");
    }

}
