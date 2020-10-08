package sample;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InuitHuntersTerrainTest {

    @Test
    void draw() {
        InuitHuntersTerrain test=new InuitHuntersTerrain();
        assertEquals("344and666",test.draw(344,666));
    }
}