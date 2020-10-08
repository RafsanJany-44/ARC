package sample;

public class ArabBedouin implements INation {
    @Override
    public ITerrain getTerrain() {
        return new ArabBedouinTerrain();
    }

    @Override
    public IHouse getHouse() {
        return new ArabBedouinHouse();
    }

    @Override
    public ITree getTree() {
        return new ArabBedouinTree();
    }

    @Override
    public IWaterSource getWaterSource() {
        return null;
    }

}