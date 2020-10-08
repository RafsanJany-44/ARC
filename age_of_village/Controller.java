package sample;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import javafx.stage.FileChooser;


import java.io.File;


public class Controller {
    @FXML
    private RadioButton tree;

    @FXML
    private RadioButton house;

    @FXML
    private RadioButton waterSource;

    @FXML
    private Button saveVillage;

    @FXML
    private Button newVillage;

    @FXML
    private Button openVillage;

    @FXML
    private AnchorPane drawingSpace;

    @FXML
    private AnchorPane infoLayout;

    @FXML
    private TextField inputVillageName;

    @FXML
    private ComboBox<String> inputNationName;

    private String nation[] =
            {"Bangladeshi Farmers", "Arab Bedouin", "Egyptian Kings", "Inuit Hunters"};

    @FXML
    private Button createVillage;


    @FXML
    private Label villageName;

    @FXML
    private Label nationName;

    @FXML
    private AnchorPane openLayout;

    @FXML
    private ComboBox<String> inputNationNameForOpen;

    @FXML
    private Button openVillageButton;

    private CurrentState currentState = CurrentState.getInstance();

    private Canvas canvas;
    private NationManager nationManager;
    private ITree iTree;
    private IHouse iHouse;
    private IWaterSource iWaterSource;
    private ITerrain iTerrain;

    private ReaderModule fileReader;


    @FXML
    void createVillage(ActionEvent event) {
        villageName.setText(inputVillageName.getText());
        nationName.setText(inputNationName.getValue());
        currentState.setVillageName(inputVillageName.getText());
        infoLayout.setVisible(false);
        initialize();
    }

    private void initialize() {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        canvas = canvasSingleton.getCanvas();
        drawingSpace.getChildren().add(canvas);

        nationManager = new NationManager(inputNationName.getValue());
        iTerrain = nationManager.getTerrain();
        iTerrain.draw();
    }


    @FXML
    void newVillage(ActionEvent event) {
        inputNationName.setItems(FXCollections.observableArrayList(nation));
        infoLayout.setVisible(true);
    }

    @FXML
    void openVillage(ActionEvent event) {
        FileChooser fileChooser = new FileChooser();

        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("Age of Villagers files (*.aov)", "*.aov");
        fileChooser.getExtensionFilters().add(extFilter);

        File file = fileChooser.showOpenDialog(null);
        fileReader = new ReaderModule(file);
        villageName.setText(fileReader.getVillageName());
        drawingSpace.getChildren().remove(canvas);
        inputNationNameForOpen.setItems(FXCollections.observableArrayList(nation));
        openLayout.setVisible(true);

    }

    @FXML
    void loadVillage(ActionEvent event) {
        CanvasSingleton canvasSingleton = CanvasSingleton.getInstance();
        canvas = canvasSingleton.getCanvas();
        drawingSpace.getChildren().add(canvas);
        openLayout.setVisible(false);
        nationManager = new NationManager(inputNationNameForOpen.getValue());
        Loader villageLoader = new Loader(nationManager);
        villageLoader.TerrainLoader();
        villageLoader.TreeLoader(fileReader.getTree_axisX(), fileReader.getTree_axisY());
        villageLoader.HouseLoader(fileReader.getHouse_axisX(), fileReader.getHouse_axisY());
        villageLoader.WaterResourceLoader(fileReader.getWaterResource_axisX(), fileReader.getWaterResource_axisY());
    }

    @FXML
    void saveVillage(ActionEvent event) {
        FileChooser fileChooser = new FileChooser();

        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("Age of Villagers files (*.aov)", "*.aov");
        fileChooser.getExtensionFilters().add(extFilter);

        File file = fileChooser.showSaveDialog(null);


        if (file != null) {
            SaverModule fileSaver = new SaverModule(file);
            fileSaver.FileSever();
        }
    }

    @FXML
    void selectHouse(ActionEvent event) {
        if (house.isSelected()) {
            iHouse = nationManager.getHouse();
            iHouse.getCanvas();
            iHouse.canvasController();
        } else {
            iHouse.releaseCanvas();
        }
    }

    @FXML
    void selectTree(ActionEvent event) {
        if (tree.isSelected()) {
            iTree = nationManager.getTree();
            iTree.getCanvas();
            iTree.canvasController();
        } else {
            iTree.releaseCanvas();
        }
    }


    @FXML
    void selectWaterSource(ActionEvent event) {
        if (waterSource.isSelected()) {
            iWaterSource = nationManager.getWaterSource();
            iWaterSource.getCanvas();
            iWaterSource.canvasControlle();
        } else {
            iWaterSource.releaseCanvas();
        }
    }
}