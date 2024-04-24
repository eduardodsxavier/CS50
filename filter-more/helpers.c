#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int greyTone;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            greyTone = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = greyTone;
            image[i][j].rgbtGreen = greyTone;
            image[i][j].rgbtRed = greyTone;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflectedImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            reflectedImage[i][j] = image[i][width - (j + 1)];
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j] = reflectedImage[i][j];
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int redBlur = 0, greenBlur = 0, blueBlur = 0, validPixels = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int i2 = i-1; i2 <= i+1; i2++)
            {
                for (int j2 = j-1; j2 <= j+1; j2++)
                {
                    if (i2 >= 0 && i2 < height && j2 >= 0 && j2 < width)
                    {
                        redBlur += image[i2][j2].rgbtRed;
                        greenBlur += image[i2][j2].rgbtGreen;
                        blueBlur += image[i2][j2].rgbtBlue;
                        validPixels++;
                    }
                }
            }
            image[i][j].rgbtRed = redBlur / validPixels;
            image[i][j].rgbtGreen = greenBlur / validPixels;
            image[i][j].rgbtBlue = blueBlur / validPixels;
            redBlur = 0;
            greenBlur = 0;
            blueBlur = 0;
            validPixels = 0;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflectedImage[height][width];
    int GxTable[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int GyTable[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int GxRed = 0, GxGreen = 0, GxBlue = 0, GyRed = 0, GyGreen = 0, GyBlue = 0;
    for (int heightIndex = 0; heightIndex < height; heightIndex++)
    {
        for (int widthIndex = 0; widthIndex < width; widthIndex++)
        {
            reflectedImage[heightIndex][widthIndex] = image[heightIndex][widthIndex];
            for (int aroundHeightIndex = heightIndex - 1; aroundHeightIndex <= heightIndex + 1; aroundHeightIndex++)
            {
                for (int aroundWidthIndex = widthIndex - 1; aroundWidthIndex <= widthIndex + 1; aroundWidthIndex++)
                {
                    if ((aroundHeightIndex >= 0 && aroundHeightIndex < height) && (aroundWidthIndex >= 0 && aroundWidthIndex < width))
                    {
                        GxRed += image[aroundHeightIndex][aroundWidthIndex].rgbtRed * GxTable[aroundHeightIndex - (heightIndex - 1)][aroundWidthIndex - (widthIndex - 1)];
                        GxGreen += image[aroundHeightIndex][aroundWidthIndex].rgbtGreen * GxTable[aroundHeightIndex - (heightIndex - 1)][aroundWidthIndex - (widthIndex - 1)];
                        GxBlue += image[aroundHeightIndex][aroundWidthIndex].rgbtBlue * GxTable[aroundHeightIndex - (heightIndex - 1)][aroundWidthIndex - (widthIndex - 1)];
                        GyRed += image[aroundHeightIndex][aroundWidthIndex].rgbtRed * GyTable[aroundHeightIndex - (heightIndex - 1)][aroundWidthIndex - (widthIndex - 1)];
                        GyGreen += image[aroundHeightIndex][aroundWidthIndex].rgbtGreen * GyTable[aroundHeightIndex - (heightIndex - 1)][aroundWidthIndex - (widthIndex - 1)];
                        GyBlue += image[aroundHeightIndex][aroundWidthIndex].rgbtBlue * GyTable[aroundHeightIndex - (heightIndex - 1)][aroundWidthIndex - (widthIndex - 1)];
                    }
                }
            }
            reflectedImage[heightIndex][widthIndex].rgbtRed = sqrt((GxRed * GxRed) + (GyRed * GyRed));
            reflectedImage[heightIndex][widthIndex].rgbtGreen = sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen));
            reflectedImage[heightIndex][widthIndex].rgbtBlue = sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue));
            GxRed = 0;
            GxGreen = 0;
            GxBlue = 0;
            GyRed = 0;
            GyGreen = 0;
            GyBlue = 0;
        }
    }

    for (int heightIndex = 0; heightIndex < height; heightIndex++)
    {
        for (int widthIndex = 0; widthIndex < width; widthIndex++)
        {
            image[heightIndex][widthIndex] = reflectedImage[heightIndex][widthIndex];
        }
    }
    return;
}
