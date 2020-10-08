package sample;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BangladeshiFarmersWaterSourceTest {
    BangladeshiFarmersWaterSource test= new BangladeshiFarmersWaterSource();
    @Test
    void canvasController() {
        assertEquals("123 and 123",test.canvasController(123,123));
    }

    @Test
    void releaseCanvas() {
        assertEquals("123 and 123",test.releaseCanvas(123,123));
    }

    @Test
    void getCanvas() {
        assertEquals("123 and 123",test.getCanvas(123,123));
    }
}