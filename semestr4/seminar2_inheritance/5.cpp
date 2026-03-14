#include <iostream>
#include <raylib.h>


class Toggle
{
private:
    Rectangle mRect;           // прямоугольник тумблера
    bool mState;               // состояние: true - включен, false - выключен
    Color mOffColor;           // цвет в выключенном состоянии
    Color mOnColor;            // цвет во включенном состоянии
    Color mBorderColor;        // цвет границы
    float mBorderThickness;    // толщина границы
    const char* mOffText;      // текст для выключенного состояния
    const char* mOnText;       // текст для включенного состояния
    bool mIsHovered;           // наведен ли курсор
    bool mJustToggled;         // флаг для предотвращения множественных переключений

public:
    
    Toggle(Vector2 position, Vector2 size, 
           bool initialState = false,
           Color offColor = {150, 150, 150, 255},
           Color onColor = {0, 200, 0, 255},
           Color borderColor = {50, 50, 50, 255},
           const char* offText = "OFF",
           const char* onText = "ON")
        : mState(initialState), mOffColor(offColor), mOnColor(onColor),
          mBorderColor(borderColor), mBorderThickness(2.0f),
          mOffText(offText), mOnText(onText), mIsHovered(false), mJustToggled(false)
    {
        mRect.x = position.x;
        mRect.y = position.y;
        mRect.width = size.x;
        mRect.height = size.y;
    }
    
    
    void handleEvents()
    {
        Vector2 mousePoint = GetMousePosition();
        
        
        mIsHovered = CheckCollisionPointRec(mousePoint, mRect);
        
        
        if (mIsHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            toggle();
        }
    }
    
    
    void toggle()
    {
        mState = !mState;
        mJustToggled = true;
    }
    
    
    void setState(bool state)
    {
        if (mState != state)
        {
            mState = state;
            mJustToggled = true;
        }
    }
    
    
    bool getState() const
    {
        return mState;
    }
    
    
    bool wasJustToggled()
    {
        if (mJustToggled)
        {
            mJustToggled = false;
            return true;
        }
        return false;
    }
    
    
    void draw() const
    {
        
        Color currentColor = mState ? mOnColor : mOffColor;
        
        
        DrawRectangleRec(mRect, currentColor);
        
        
        DrawRectangleLinesEx(mRect, mBorderThickness, mBorderColor);
        
       
        if (mIsHovered)
        {
            DrawRectangleLinesEx(mRect, mBorderThickness + 1, {255, 255, 255, 100});
        }
        
        
        const char* text = mState ? mOnText : mOffText;
        int fontSize = (int)(mRect.height * 0.5f);
        Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
        
        DrawText(text, 
                 mRect.x + (mRect.width - textSize.x) / 2,
                 mRect.y + (mRect.height - textSize.y) / 2,
                 fontSize,
                 {255, 255, 255, 255});
    }
    
    
    void setPosition(Vector2 position)
    {
        mRect.x = position.x;
        mRect.y = position.y;
    }
    
    
    void setSize(Vector2 size)
    {
        mRect.width = size.x;
        mRect.height = size.y;
    }
    
    
    void setOffColor(Color color) { mOffColor = color; }
    void setOnColor(Color color) { mOnColor = color; }
    void setBorderColor(Color color) { mBorderColor = color; }
    
    
    void setOffText(const char* text) { mOffText = text; }
    void setOnText(const char* text) { mOnText = text; }
};


class ToggleGroup
{
private:
    static const int MAX_TOGGLES = 10;
    Toggle* mToggles[MAX_TOGGLES];
    int mCount;
    int mActiveIndex;
    
public:
    ToggleGroup() : mCount(0), mActiveIndex(-1) {}
    
    
    void add(Toggle* toggle)
    {
        if (mCount < MAX_TOGGLES)
        {
            mToggles[mCount] = toggle;
            mCount++;
        }
    }
    
    
    void handleEvents()
    {
        for (int i = 0; i < mCount; i++)
        {
            mToggles[i]->handleEvents();
            
            
            if (mToggles[i]->wasJustToggled() && mToggles[i]->getState())
            {
                
                for (int j = 0; j < mCount; j++)
                {
                    if (j != i)
                    {
                        mToggles[j]->setState(false);
                    }
                }
                mActiveIndex = i;
            }
        }
    }
    
    
    void draw() const
    {
        for (int i = 0; i < mCount; i++)
        {
            mToggles[i]->draw();
        }
    }
    
    
    int getActiveIndex() const { return mActiveIndex; }
    
    
    Toggle* getActiveToggle() const
    {
        if (mActiveIndex >= 0 && mActiveIndex < mCount)
        {
            return mToggles[mActiveIndex];
        }
        return nullptr;
    }
};

int main()
{
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Toggle Switch Demo");
    SetTargetFPS(60);
    
    
    
    
    Toggle toggle1({100, 100}, {120, 50}, false, 
                   {150, 150, 150, 255}, {0, 200, 0, 255},
                   {50, 50, 50, 255}, "OFF", "ON");
    
   
    Toggle toggle2({100, 200}, {120, 50}, true,
                   {100, 100, 150, 255}, {200, 100, 0, 255},
                   {80, 80, 80, 255}, "NO", "YES");
    
    
    Toggle toggle3({100, 300}, {120, 50}, false,
                   {150, 100, 100, 255}, {100, 200, 100, 255},
                   {50, 50, 50, 255}, "DISABLE", "ENABLE");
    
   
    Toggle radio1({300, 100}, {100, 40}, true,
                  {180, 180, 180, 255}, {100, 150, 255, 255},
                  {50, 50, 50, 255}, "Opt 1", "Opt 1");
    
    Toggle radio2({300, 160}, {100, 40}, false,
                  {180, 180, 180, 255}, {100, 150, 255, 255},
                  {50, 50, 50, 255}, "Opt 2", "Opt 2");
    
    Toggle radio3({300, 220}, {100, 40}, false,
                  {180, 180, 180, 255}, {100, 150, 255, 255},
                  {50, 50, 50, 255}, "Opt 3", "Opt 3");
    
    ToggleGroup group;
    group.add(&radio1);
    group.add(&radio2);
    group.add(&radio3);
    
    
    Toggle toggle4({500, 100}, {50, 120}, false,
                   {200, 100, 100, 255}, {100, 200, 100, 255},
                   {50, 50, 50, 255}, "OFF", "ON");
    
    Toggle toggle5({600, 100}, {50, 120}, true,
                   {200, 100, 100, 255}, {100, 200, 100, 255},
                   {50, 50, 50, 255}, "OFF", "ON");
    
    while (!WindowShouldClose())
    {
        
        toggle1.handleEvents();
        toggle2.handleEvents();
        toggle3.handleEvents();
        toggle4.handleEvents();
        toggle5.handleEvents();
        group.handleEvents();
        
        
        BeginDrawing();
        ClearBackground({30, 30, 30, 255});
        
        DrawText("Individual Toggles:", 20, 20, 20, WHITE);
        
       
        toggle1.draw();
        toggle2.draw();
        toggle3.draw();
        toggle4.draw();
        toggle5.draw();
        
        
        DrawText("Radio Button Group (ToggleGroup):", 300, 50, 20, WHITE);
        group.draw();
        
        
        DrawText(TextFormat("Toggle 1: %s", toggle1.getState() ? "ON" : "OFF"), 
                 250, 110, 20, WHITE);
        DrawText(TextFormat("Toggle 2: %s", toggle2.getState() ? "YES" : "NO"), 
                 250, 210, 20, WHITE);
        DrawText(TextFormat("Toggle 3: %s", toggle3.getState() ? "ENABLE" : "DISABLE"), 
                 250, 310, 20, WHITE);
        
        DrawText(TextFormat("Active radio: Option %d", group.getActiveIndex() + 1), 
                 420, 270, 20, WHITE);
        
       
        DrawText("Vertical toggles:", 500, 250, 20, WHITE);
        
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
