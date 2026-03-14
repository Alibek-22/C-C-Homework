#include <iostream>
#include <cmath>
#include <raylib.h>

class Draggable
{
private:
    Rectangle mRect {};
    Color mColor {};
    bool mIsDragged {false};
    Vector2 mOffset {0.0f, 0.0f};

public:
    Draggable(Vector2 position, Vector2 size, Color color) : mColor{color}
    {
        mRect.x = position.x;
        mRect.y = position.y;
        mRect.width = size.x;
        mRect.height = size.y;
    }

    bool onMousePressed(Vector2 mousePosition)
    {
        if (CheckCollisionPointRec(mousePosition, mRect))
        {
            mIsDragged = true;
            mOffset.x = mousePosition.x - mRect.x;
            mOffset.y = mousePosition.y - mRect.y;
        }
        return mIsDragged;
    }

    void onMouseReleased()
    {
        mIsDragged = false;
    }

    void onMouseMoved(Vector2 mousePosition)
    {
        if (mIsDragged)
        {
            mRect.x = mousePosition.x - mOffset.x;
            mRect.y = mousePosition.y - mOffset.y;
        }
    }

    void handleEvents()
    {
        Vector2 mousePosition = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            onMousePressed(mousePosition);
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            onMouseReleased();
        }

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) || GetMouseDelta().x != 0 || GetMouseDelta().y != 0)
        {
            onMouseMoved(mousePosition);
        }
    }

    void setColor(Color c)
    {
        mColor = c;
    }

    void setSize(Vector2 sz)
    {
        mRect.width = sz.x;
        mRect.height = sz.y;
    }

    void setPosition(Vector2 pos)
    {
        mRect.x = pos.x;
        mRect.y = pos.y;
    }

    void draw() const
    {
        DrawRectangleRec(mRect, mColor);
    }
    
    
    bool isDragged() const
    {
        return mIsDragged;
    }
};


class DraggableWithColorChange : public Draggable
{
private:
    Color mBaseColor;  // цвет в обычном состоянии
    Color mDragColor;  // цвет при перетаскивании

public:
    DraggableWithColorChange(Vector2 position, Vector2 size, Color baseColor, Color dragColor)
        : Draggable(position, size, baseColor), mBaseColor(baseColor), mDragColor(dragColor)
    {
    }
    
    
    void handleEvents()
    {
        
        bool wasDragged = isDragged();
        
       
        Draggable::handleEvents();
        
        
        bool isCurrentlyDragged = isDragged();
        
        
        if (!wasDragged && isCurrentlyDragged)
        {
            setColor(mDragColor);
        }
        
        else if (wasDragged && !isCurrentlyDragged)
        {
            setColor(mBaseColor);
        }
    }
};

int main()
{
    InitWindow(800, 600, "Draggable With Color Change Test");
    SetTargetFPS(100);

    
    DraggableWithColorChange d {
        {100, 100},                // позиция
        {200, 400},                // размер
        {80, 80, 120, 255},        // baseColor (синеватый)
        {255, 100, 100, 255}       // dragColor (красноватый)
    };

   
    Draggable regularDraggable {
        {400, 100},                // позиция
        {200, 400},                // размер
        {80, 120, 80, 255}         // зеленоватый цвет (не меняется)
    };

    while (!WindowShouldClose())
    {
        d.handleEvents();
        regularDraggable.handleEvents();

        BeginDrawing();
        ClearBackground(BLACK);
        
        d.draw();
        regularDraggable.draw();
        
        
        DrawText("Left: цвет меняется при перетаскивании", 10, 10, 20, WHITE);
        DrawText("Right: цвет не меняется (обычный Draggable)", 10, 40, 20, WHITE);
        
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
