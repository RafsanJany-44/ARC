package sample;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BangladeshiFarmerTerrainTest {

    @Test
    void draw() {
        BangladeshiFarmerTerrain test =new BangladeshiFarmerTerrain();
        assertEquals("100and1300",test.draw(100,1300));
    }
}