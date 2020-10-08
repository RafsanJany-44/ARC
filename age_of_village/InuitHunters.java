package sample;

public class InuitHunters implements INation {
    @Override
    public ITerrain getTerrain() {
        return new InuitHuntersTerrain();
    }

    @Override
    public IHouse getHouse() {
        return new InuitHuntersHouse();
    }

    @Override
    public ITree getTree() {
        return null;
    }

    @Override
    public IWaterSource getWaterSource() {
        return null;
    }
}
