package sample;

public class NationManager {
    private String nationType;
    private INation nation;
    private NationFactory nationFactory;

    public NationManager(String nationType) {
        this.nationType = nationType;
        nationFactory = new NationFactory();
        nation = nationFactory.getNation(nationType);
    }

    public IHouse getHouse(){
        return (IHouse)nation.getHouse();
    }
}
