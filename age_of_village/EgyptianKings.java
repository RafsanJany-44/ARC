package sample;

public class EgyptianKings implements INation {
    @Override
    public ITerrain getTerrain() {
        return new EgyptianKingsTerrain();
    }

    @Override
    public IHouse getHouse() {
        return new EgyptianKingsHouse();
    }

    @Override
    public ITree getTree() {
        return new EgyptianKingsTree();
    }

    @Override
    public IWaterSource getWaterSource() {
        return new EgyptianKingsWaterSource();
    }
}
