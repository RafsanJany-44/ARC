package sample;

import com.google.gson.*;

import java.util.ArrayList;

public class CurrentState {
    private static CurrentState instance = null;
    private JsonObject state;
    private JsonArray houseX;
    private JsonArray houseY;
    private JsonArray treeX;
    private JsonArray treeY;
    private JsonArray waterX;
    private JsonArray waterY;
    private ArrayList<Point> tree;
    private ArrayList<Point> house;
    private ArrayList<Point> waterResource;

    private  CurrentState(){
        state = new JsonObject();
        tree = new ArrayList<>();
        house = new ArrayList<>();
        waterResource = new ArrayList<>();
        houseX = new JsonArray();
        houseY = new JsonArray();

        treeX = new JsonArray();
        treeY = new JsonArray();

        waterX = new JsonArray();
        waterY = new JsonArray();
    }

    public static CurrentState getInstance(){
        if(instance == null)
            instance = new CurrentState();
        return instance;
    }

    public void setVillageName(String village){
        state.addProperty("villageName", village);
        System.out.println(state);
    }

    public void addTree(Point point){
        System.out.println("x: "+point.x+" y: "+point.y+" added");
        tree.add(point);
    }

    public void addHouse(Point point){
        house.add(point);
    }

    public void addWaterResource(Point point){
        waterResource.add(point);
    }

    private void addTreeData(){
        for (int i = 0; i< tree.size(); i++)
            treeX.add(tree.get(i).x);
        for (int i = 0; i< tree.size(); i++)
            treeY.add(tree.get(i).y);

        state.add("treeX", treeX);
        state.add("treeY", treeY);
    }

    private void addHouseData(){
        for (int i = 0; i< house.size(); i++)
            houseX.add(house.get(i).x);
        for (int i = 0; i< house.size(); i++)
            houseY.add(house.get(i).y);

        state.add("houseX", houseX);
        state.add("houseY", houseY);
    }

    private void addWaterResourceData(){
        for (int i = 0; i< waterResource.size(); i++)
            waterX.add(waterResource.get(i).x);
        for (int i = 0; i< waterResource.size(); i++)
            waterY.add(waterResource.get(i).y);

        state.add("waterResourceX", waterX);
        state.add("waterResourceY", waterY);
    }


    public JsonObject getCurrentStateObject(){
        addHouseData();
        addTreeData();
        addWaterResourceData();
        return state;
    }


}
