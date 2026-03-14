#include <iostream>
#include <raylib.h>


class Slider
{
private:
    Rectangle mBar;          
    Rectangle mKnob;           
    float mMinValue;           
    float mMaxValue;           
    float mCurrentValue;       
    bool mIsDragged;           
    Color mBarColor;           
    Color mKnobColor;          
    Color mActiveColor;        
    
public:
    Slider(Vector2 position, float width, float height, 
           float minValue = 0.0f, float maxValue = 255.0f, 
           float initialValue = 0.0f)
        : mMinValue(minValue), mMaxValue(maxValue), 
          mCurrentValue(initialValue), mIsDragged(false)
    {
        mBar.x = position.x;
        mBar.y = position.y;
        mBar.width = width;
        mBar.height = height * 0.3f;  
        
        
        float knobSize = height;
        mKnob.width = knobSize;
        mKnob.height = knobSize;
        updateKnobPosition();
        
        
        mBarColor = {80, 80, 80, 255};
        mKnobColor = {200, 200, 200, 255};
        mActiveColor = {255, 255, 255, 255};
    }
    
    void updateKnobPosition()
    {
       
        float t = (mCurrentValue - mMinValue) / (mMaxValue - mMinValue);
        mKnob.x = mBar.x + t * (mBar.width - mKnob.width);
        mKnob.y = mBar.y - (mKnob.height - mBar.height) / 2;
    }
    
    void handleEvents()
    {
        Vector2 mousePoint = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            
            if (CheckCollisionPointRec(mousePoint, mKnob))
            {
                mIsDragged = true;
            }
        }
        
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            mIsDragged = false;
        }
        
        if (mIsDragged && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            
            float newX = mousePoint.x - mKnob.width / 2;
            
            
            if (newX < mBar.x)
                newX = mBar.x;
            if (newX > mBar.x + mBar.width - mKnob.width)
                newX = mBar.x + mBar.width - mKnob.width;
            
            mKnob.x = newX;
            
            
            float t = (mKnob.x - mBar.x) / (mBar.width - mKnob.width);
            mCurrentValue = mMinValue + t * (mMaxValue - mMinValue);
        }
    }
    
    void draw() const
    {
        
        DrawRectangleRec(mBar, mBarColor);
        
        
        Color knobColor = mIsDragged ? mActiveColor : mKnobColor;
        DrawRectangleRec(mKnob, knobColor);
        
        /
        DrawRectangleLinesEx(mKnob, 1, {50, 50, 50, 255});
    }
    
    float getValue() const
    {
        return mCurrentValue;
    }
    
    void setValue(float value)
    {
        if (value < mMinValue) value = mMinValue;
        if (value > mMaxValue) value = mMaxValue;
        mCurrentValue = value;
        updateKnobPosition();
    }
    
    void setPosition(Vector2 position)
    {
        float width = mBar.width;
        float height = mKnob.height;
        
        mBar.x = position.x;
        mBar.y = position.y + (height - mBar.height) / 2;
        
        updateKnobPosition();
    }
};


class ColorCircle
{
private:
    Vector2 mPosition;
    float mRadius;
    Color mColor;
    
public:
    ColorCircle(Vector2 position, float radius, Color initialColor)
        : mPosition(position), mRadius(radius), mColor(initialColor)
    {
    }
    
    void setColor(Color color)
    {
        mColor = color;
    }
    
    void setColorComponents(int red, int green, int blue)
    {
        mColor.r = red;
        mColor.g = green;
        mColor.b = blue;
    }
    
    void draw() const
    {
        DrawCircleV(mPosition, mRadius, mColor);
        
        
        DrawCircleLines(mPosition.x, mPosition.y, mRadius, {255, 255, 255, 100});
    }
    
    Vector2 getPosition() const { return mPosition; }
    float getRadius() const { return mRadius; }
    Color getColor() const { return mColor; }
};

int main()
{
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Color Circle with RGB Sliders");
    SetTargetFPS(60);
    
    ColorCircle circle({screenWidth / 2.0f, 200.0f}, 80.0f, {128, 128, 128, 255});
    
    
    float sliderWidth = 400.0f;
    float sliderHeight = 30.0f;
    float startX = (screenWidth - sliderWidth) / 2.0f;
    float startY = 350.0f;
    float spacing = 50.0f;
    
    Slider redSlider({startX, startY}, sliderWidth, sliderHeight, 0, 255, 128);
    Slider greenSlider({startX, startY + spacing}, sliderWidth, sliderHeight, 0, 255, 128);
    Slider blueSlider({startX, startY + spacing * 2}, sliderWidth, sliderHeight, 0, 255, 128);
    
    
    Color redColor = {255, 0, 0, 255};
    Color greenColor = {0, 255, 0, 255};
    Color blueColor = {0, 0, 255, 255};
    
    while (!WindowShouldClose())
    {
        
        redSlider.handleEvents();
        greenSlider.handleEvents();
        blueSlider.handleEvents();
        
       
        circle.setColorComponents(
            (int)redSlider.getValue(),
            (int)greenSlider.getValue(),
            (int)blueSlider.getValue()
        );
        
        
        BeginDrawing();
        ClearBackground({30, 30, 30, 255});
        
        
        DrawText("RGB Color Mixer", 20, 20, 30, WHITE);
        DrawText("Drag sliders to change circle color", 20, 60, 20, LIGHTGRAY);
        
       
        circle.draw();
        
        
        Color currentColor = circle.getColor();
        DrawText(TextFormat("R: %d  G: %d  B: %d", 
                 currentColor.r, currentColor.g, currentColor.b), 
                 screenWidth / 2 - 100, 280, 25, WHITE);
        
        
        DrawRectangle(screenWidth / 2 - 120, 110, 240, 30, currentColor);
        DrawRectangleLines(screenWidth / 2 - 120, 110, 240, 30, WHITE);
        
        DrawText("RED", startX - 80, startY + 5, 20, redColor);
        redSlider.draw();
        DrawText(TextFormat("%.0f", redSlider.getValue()), 
                 startX + sliderWidth + 20, startY + 5, 20, WHITE);
        
       
        DrawText("GREEN", startX - 80, startY + spacing + 5, 20, greenColor);
        greenSlider.draw();
        DrawText(TextFormat("%.0f", greenSlider.getValue()), 
                 startX + sliderWidth + 20, startY + spacing + 5, 20, WHITE);
        
       
        DrawText("BLUE", startX - 80, startY + spacing * 2 + 5, 20, blueColor);
        blueSlider.draw();
        DrawText(TextFormat("%.0f", blueSlider.getValue()), 
                 startX + sliderWidth + 20, startY + spacing * 2 + 5, 20, WHITE);
        
       
        DrawText("Press ESC to exit", screenWidth - 150, screenHeight - 30, 15, GRAY);
        
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
