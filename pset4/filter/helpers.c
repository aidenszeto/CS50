#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blue;
    int green;
    int red;
    float count;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blue = 0;
            green = 0;
            red = 0;
            count = 0.00;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if ((i + k >= 0 && i + k < height) && (j + l >= 0 && j + l < width))
                    {
                        blue += image[i + k][j + l].rgbtBlue;
                        green += image[i + k][j + l].rgbtGreen;
                        red += image[i + k][j + l].rgbtRed;
                        count++;
                    }
                }
            }
            temp[i][j].rgbtBlue = round(blue / count);
            temp[i][j].rgbtGreen = round(green / count);
            temp[i][j].rgbtRed = round(red / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;

        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] =
    {
        {-1,  0,  1},
        {-2,  0,  2},
        {-1,  0,  1}
    };

    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0,  0,  0},
        {1,  2,  1}
    };

    int xblue;
    int xgreen;
    int xred;

    int yblue;
    int ygreen;
    int yred;

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            xblue = 0;
            xgreen = 0;
            xred = 0;

            yblue = 0;
            ygreen = 0;
            yred = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if ((i + k >= 0 && i + k < height) && (j + l >= 0 && j + l < width))
                    {
                        xblue += image[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                        xgreen += image[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        xred += image[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];

                        yblue += image[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                        ygreen += image[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                        yred += image[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    }
                }
            }
            if (round(sqrt(pow(xblue, 2) + pow(yblue, 2))) > 255)
            {
                temp[i][j].rgbtBlue = 255;
            }
            else
            {
                temp[i][j].rgbtBlue = round(sqrt(pow(xblue, 2) + pow(yblue, 2)));
            }

            if (round(sqrt(pow(xgreen, 2) + pow(ygreen, 2))) > 255)
            {
                temp[i][j].rgbtGreen = 255;
            }
            else
            {
                temp[i][j].rgbtGreen = round(sqrt(pow(xgreen, 2) + pow(ygreen, 2)));
            }

            if (round(sqrt(pow(xred, 2) + pow(yred, 2))) > 255)
            {
                temp[i][j].rgbtRed = 255;
            }
            else
            {
                temp[i][j].rgbtRed = round(sqrt(pow(xred, 2) + pow(yred, 2)));
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}
