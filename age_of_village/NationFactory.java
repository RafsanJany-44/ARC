package sample;

public class NationFactory {
    public INation getNation(String nationType) {

        if(nationType == "Arab Bedouin")
            return new ArabBedouin();
        return null;
    }
}
