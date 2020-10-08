package sample;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EgyptianKingsTerrainTest {

    @Test
    void draw() {
        EgyptianKingsTerrain test= new EgyptianKingsTerrain();
        assertEquals("123and988",test.draw(123,988));
    }
}