#include <Arduino.h>
#include <FastLED.h>

FASTLED_USING_NAMESPACE
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB


// I think that if you can use a seperate arroy with classes in ti it would probablt work well



template<int pin, int ledCount>
class Strip{
public:
    int brightness = 150;
    int offset = 0;
    int end = 0;
    bool reverse = false;
    CRGB ledStrip[ledCount];
    Strip* target;
    

    Strip(int brightness, int offset = 0, int end = ledCount, bool reverse = false)
    {
        this->brightness = brightness;
        this->offset = offset;
        this->end = end;
        this->reverse = reverse;
        target = this;
    
        FastLED.addLeds<LED_TYPE,pin,COLOR_ORDER>(ledStrip, ledCount).setCorrection(TypicalLEDStrip);
        FastLED.setBrightness(brightness);
    }
    
    Strip(Strip* copy, int offset = 0, int end = ledCount, bool reverse = false)
    {
        target = copy;
        this->offset = offset;
        this->end = end;
        this->reverse = reverse;
    }
    
    void clear()
    {
        for (int i = 0 + offset; i < end; i++)
        {
            target->ledStrip[i] = CRGB(0, 0, 0);
        }
        FastLED.show();
    }

    void singleColor(int r, int g, int b)
    {
        for (int i = 0 + offset; i < end; i++)
        {
            target->ledStrip[i] = CRGB(r, g, b);
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

    void firefly(CRGB max = CRGB(255, 255, 0), int steps = 25)
    {
        static int* ptr = new int [ledCount];
        randomSeed(timer0_millis);
        for (int i = offset; i < end; i++)
        {
            if (ptr[i] > 0 && ptr[i] < steps)
            {
                target->ledStrip[i] += CRGB(max.r/steps, max.g/steps, max.b/steps);
                ptr[i]++;
            }
            else if(ptr[i] == steps)
            {
                target->ledStrip[i] -= CRGB(max.r/steps, max.g/steps, max.b/steps);
                if( target->ledStrip[i] == CRGB(0, 0, 0))
                {
                    ptr[i] = -1;
                }
            }
            else if(random(0, 50) < 1)
            {
                ptr[i]++;
            }
            
        }

        FastLED.show();
    }
};