package sample;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ArabBedouinTerrainTest {

    @Test
    void draw() {
        ArabBedouinTerrain test=new ArabBedouinTerrain();
        assertEquals("12and13",test.draw(12,13));


    }
}