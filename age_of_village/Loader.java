package sample;


import com.google.gson.JsonArray;


public class Loader { private CanvasSingleton canvasSingleton;
    private NationManager nationManager;

    public Loader(NationManager nationManager) {
        canvasSingleton = CanvasSingleton.getInstance();
        this.nationManager = nationManager;
    }

    public void TerrainLoader(){
        nationManager.getTerrain().draw();
    }

    public void TreeLoader(JsonArray tree_axisX, JsonArray tree_axisY){
        for (int i = 0; i< tree_axisX.size(); i++)
            nationManager.getTree().draw(new Point(tree_axisX.get(i).getAsInt(), tree_axisY.get(i).getAsInt()));
    }

    public void HouseLoader(JsonArray house_axisX, JsonArray house_axisY){
        for (int j = 0; j< house_axisX.size(); j++)
            nationManager.getHouse().draw(new Point(house_axisX.get(j).getAsInt(), house_axisY.get(j).getAsInt()));
    }

    public void WaterResourceLoader(JsonArray waterResource_axisX, JsonArray waterResource_axisY){
        for (int k = 0; k< waterResource_axisX.size(); k++)
            nationManager.getWaterSource().draw(new Point(waterResource_axisX.get(k).getAsInt(), waterResource_axisY.get(k).getAsInt()));
    }
}
