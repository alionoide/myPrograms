#include <Arduino.h>
#include <FastLED.h>

FASTLED_USING_NAMESPACE
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

int checkArry[50] = {0};

// I think that if you can use a seperate arroy with classes in ti it would probablt work well

template<int pin, int ledCount>
class Strip{
public:
    int brightness = 150;
    int offset = 0;
    int end = 0;
    bool reverse = false;
    CRGB ledStrip[ledCount];
    

    Strip(int brightness, int offset = 0, int end = ledCount, bool reverse = false)
    {
        this->brightness = brightness;
        this->offset = offset;
        this->end = end;
        this->reverse = reverse;
    }
    
    void init()
    {
        if (checkArry[pin] == 0)
        {
            checkArry[pin]++;
            FastLED.addLeds<LED_TYPE,pin,COLOR_ORDER>(ledStrip, ledCount).setCorrection(TypicalLEDStrip);
            FastLED.setBrightness(brightness);

        }
        else
        {
            // deal with others here
        }
    }
    
    void clear()
    {
        for (int i = 0 + offset; i < end; i++)
        {
            this->ledStrip[i] = CRGB(0, 0, 0);
        }
        FastLED.show();
    }

    void singleColor(int r, int g, int b)
    {
        for (int i = 0 + offset; i < end; i++)
        {
            this->ledStrip[i] = CRGB(r, g, b);
        }
        FastLED.show();
    }

    void temperatureSense()
    {
        int red = (analogRead(A0)-575)*3;
        if (red > 256)
        {
            red = 255;
        }
        if (red < 0)
        {
            red = 0;
        }
        int blue = 64-(analogRead(A0)-600);
        if (blue < 0)
        {
            blue = 0;
        }
        singleColor(red, 0, blue);
    } 
};