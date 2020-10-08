package sample;

public class BangladeshiFarmers  implements INation{
    @Override
    public IHouse getHouse() {
        return new BangladeshiFarmersHouse();
    }

    @Override
    public ITree getTree() {
        return new BangladeshiFarmersTree();
    }

    @Override
    public IWaterSource getWaterSource() {
        return new BangladeshiFarmersWaterSource();
    }

    @Override
    public ITerrain getTerrain() {
        return new BangladeshiFarmerTerrain();
    }
}
