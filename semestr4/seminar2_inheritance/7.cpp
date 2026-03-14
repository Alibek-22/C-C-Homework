#include <raylib.h>
#include <vector>
#include <string>

class DropList
{
private:
    Rectangle mMainRect;
    std::vector<std::string> mItems;
    int mSelectedIndex;
    bool mIsOpen;
    Color mBgColor;
    Color mTextColor;
    Color mHoverColor;
    Color mBorderColor;
    int mHoveredIndex;
    float mItemHeight;

public:
    DropList(Vector2 position, float width, const std::vector<std::string>& items)
        : mItems(items), mSelectedIndex(0), mIsOpen(false), mHoveredIndex(-1)
    {
        mItemHeight = 30.0f;
        mMainRect.x = position.x;
        mMainRect.y = position.y;
        mMainRect.width = width;
        mMainRect.height = mItemHeight;
        
        mBgColor = {50, 50, 50, 255};
        mTextColor = {255, 255, 255, 255};
        mHoverColor = {100, 100, 200, 255};
        mBorderColor = {200, 200, 200, 255};
    }
    
    void handleEvents()
    {
        Vector2 mousePoint = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mousePoint, mMainRect))
            {
                mIsOpen = !mIsOpen;
            }
            else if (mIsOpen)
            {
                for (size_t i = 0; i < mItems.size(); i++)
                {
                    Rectangle itemRect = {
                        mMainRect.x,
                        mMainRect.y + (i + 1) * mItemHeight,
                        mMainRect.width,
                        mItemHeight
                    };
                    
                    if (CheckCollisionPointRec(mousePoint, itemRect))
                    {
                        mSelectedIndex = i;
                        mIsOpen = false;
                        break;
                    }
                }
                
                if (!CheckCollisionPointRec(mousePoint, mMainRect))
                {
                    mIsOpen = false;
                }
            }
        }
        
        if (mIsOpen)
        {
            mHoveredIndex = -1;
            for (size_t i = 0; i < mItems.size(); i++)
            {
                Rectangle itemRect = {
                    mMainRect.x,
                    mMainRect.y + (i + 1) * mItemHeight,
                    mMainRect.width,
                    mItemHeight
                };
                
                if (CheckCollisionPointRec(mousePoint, itemRect))
                {
                    mHoveredIndex = i;
                    break;
                }
            }
        }
    }
    
    void draw()
    {
        DrawRectangleRec(mMainRect, mBgColor);
        DrawRectangleLinesEx(mMainRect, 2, mBorderColor);
        
        const char* selectedText = mItems[mSelectedIndex].c_str();
        int fontSize = 20;
        Vector2 textSize = MeasureTextEx(GetFontDefault(), selectedText, fontSize, 1);
        DrawText(selectedText, 
                 mMainRect.x + 5, 
                 mMainRect.y + (mMainRect.height - textSize.y) / 2,
                 fontSize, mTextColor);
        
        DrawText(mIsOpen ? "▲" : "▼", 
                 mMainRect.x + mMainRect.width - 25, 
                 mMainRect.y + 5,
                 fontSize, mTextColor);
        
        if (mIsOpen)
        {
            for (size_t i = 0; i < mItems.size(); i++)
            {
                Rectangle itemRect = {
                    mMainRect.x,
                    mMainRect.y + (i + 1) * mItemHeight,
                    mMainRect.width,
                    mItemHeight
                };
                
                Color itemColor = (i == (size_t)mHoveredIndex) ? mHoverColor : mBgColor;
                DrawRectangleRec(itemRect, itemColor);
                DrawRectangleLinesEx(itemRect, 1, mBorderColor);
                
                const char* itemText = mItems[i].c_str();
                DrawText(itemText, 
                         itemRect.x + 5, 
                         itemRect.y + (itemRect.height - textSize.y) / 2,
                         fontSize, mTextColor);
            }
        }
    }
    
    int getSelectedIndex() const
    {
        return mSelectedIndex;
    }
    
    std::string getSelectedItem() const
    {
        return mItems[mSelectedIndex];
    }
};

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "DropList Example");
    SetTargetFPS(60);
    
    std::vector<std::string> items = {"Circle", "Square", "Triangle"};
    DropList dropList({300, 100}, 200, items);
    
    while (!WindowShouldClose())
    {
        dropList.handleEvents();
        
        BeginDrawing();
        ClearBackground({30, 30, 30, 255});
        
        dropList.draw();
        
        int selectedIndex = dropList.getSelectedIndex();
        Vector2 shapePos = {400, 300};
        
        if (selectedIndex == 0)
        {
            DrawCircleV(shapePos, 80, RED);
        }
        else if (selectedIndex == 1)
        {
            DrawRectangleV({shapePos.x - 80, shapePos.y - 80}, {160, 160}, GREEN);
        }
        else if (selectedIndex == 2)
        {
            DrawTriangle({shapePos.x, shapePos.y - 80},
                        {shapePos.x - 70, shapePos.y + 40},
                        {shapePos.x + 70, shapePos.y + 40},
                        BLUE);
        }
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
