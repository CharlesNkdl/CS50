#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum = 0;
            sum = round(((image[i][j].rgbtBlue)+(image[i][j].rgbtRed)+(image[i][j].rgbtGreen)) / 3.0);
            image[i][j].rgbtBlue = sum;
            image[i][j].rgbtGreen = sum;
            image[i][j].rgbtRed = sum;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w = width / 2.0;

    for (int i=0; i < height; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int tempb = image[i][j].rgbtBlue;
            int tempg = image[i][j].rgbtGreen;
            int tempr = image[i][j].rgbtRed;
            image[i][j]=image[i][width-(j+1)];
            image[i][width-(j+1)].rgbtBlue = tempb;
            image[i][width-(j+1)].rgbtGreen = tempg;
            image[i][width-(j+1)].rgbtRed = tempr;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //RGBTRIPLE temp[height][width];
    //for (int p=0;p < height; p++)
    //{
      //  for (int l=0; l < width; l++)
        //{
          //  temp[p][l] = image[p][l];
        //}
    //}
    //for (int i=0; i < height-1; i++)
    //{
      //  for (int j=0; j < width-1; j++)
        //{
          //  int count=0;
            //int sumr = temp[i][j].rgbtRed;
            //int sumb = temp[i][j].rgbtBlue;
            //int sumg = temp[i][j].rgbtGreen;
            //count++;
            //if (i != 0)
            //{
              //  sumr += temp[i-1][j].rgbtRed;
                //sumb += temp[i-1][j].rgbtBlue;
                //sumg += temp[i-1][j].rgbtGreen;
                //count++;
                //if ( j != 0)
                //{
                  //  sumr += temp[i-1][j-1].rgbtRed;
                    //sumb += temp[i-1][j-1].rgbtBlue;
                    //sumg += temp[i-1][j-1].rgbtGreen;
                    //count++;
                //}
                //if (j != width-1)
                //{
                  //  sumr += temp[i-1][j+1].rgbtRed;
                   // sumb += temp[i-1][j+1].rgbtBlue;
                    //sumg += temp[i-1][j+1].rgbtGreen;
                    //count++;
                //}
            //}
            //if (i != height-1)
            //{
              //  sumr += temp[i+1][j].rgbtRed;
                //sumb += temp[i+1][j].rgbtBlue;
               // sumg += temp[i+1][j].rgbtGreen;
                //count++;
                //if (j !=0)
                //{
                  //  sumr += temp[i+1][j-1].rgbtRed;
                   // sumb += temp[i+1][j-1].rgbtBlue;
                    //sumg += temp[i+1][j-1].rgbtGreen;
                    //count++;
                //}
                //if (j != width-1)
                //{
                  //  sumr += temp[i+1][j+1].rgbtRed;
                   // sumb += temp[i+1][j+1].rgbtBlue;
                   // sumg += temp[i+1][j+1].rgbtGreen;
                   // count++;
                //}
            //}
            //if (j != 0)
            //{
              //  sumr += temp[i][j-1].rgbtRed;
               // sumb += temp[i][j-1].rgbtBlue;
                //sumg += temp[i][j-1].rgbtGreen;
                //count++;
            //}
            //if (j != width-1)
            //{
              //  sumr += temp[i][j+1].rgbtRed;
               // sumb += temp[i][j+1].rgbtBlue;
                //sumg += temp[i][j+1].rgbtGreen;
                //count++;
            //}
            //image[i][j].rgbtRed = round((sumr + (count / 2))/ count);
            //image[i][j].rgbtBlue = round((sumb + (count / 2)) / count);
            //image[i][j].rgbtGreen = round((sumg + (count / 2)) / count);
        //}
        // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise values
            float sum_red;
            float sum_blue;
            float sum_green;
            int counter;
            sum_red = sum_blue = sum_green = counter = 0;
            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }
            // Get average and blur image
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Initialise Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise ints
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;
            Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;
            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    Gx_red += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_blue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                    Gy_red += temp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    Gy_green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_blue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                }
            }
             // Calculate Sobel operator
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));
            // Cap at 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            // Assign new values to pixels
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
