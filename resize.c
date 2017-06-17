/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember agruments
    int n = atoi(argv[1]);
    if (n < 1 || n >= 100)
    {
        
        fprintf(stderr, "Usage: Enter n between 1 to `100\n");
        return 1;
        
    }

    
    else if(n>=1 && n<100)
    {
    char *infile = argv[2];
    char *outfile = argv[3];
    
    //int p=0;
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    int inpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biHeight *=n;// abs(bi.biHeight)*n;
    bi.biWidth*=n;// = abs(bi.biWidth)*n;
    int outpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage =((sizeof(RGBTRIPLE)*bi.biWidth) + outpadding)*abs(bi.biHeight);
    //bi.biSizeImage = (bi.biSizeImage - inpadding * (bi.biHeight)/n) * (n *n) + outpadding * bi.biHeight;
    bf.bfSize= bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE *arr = (RGBTRIPLE *)malloc(sizeof(RGBTRIPLE) * bi.biWidth);
    
        // iterate over infile's scanlines
    for (int i = 0; i < (bi.biHeight)/n; i++)
    
    {
        int v=0;
      for (int j = 0; j < (bi.biWidth)/n; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile and store in buffer
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //iterate over each pixel factor times
            for (int k = 0; k < n; k++)
            {
                arr[v] = triple;
                v++;
            }
        }

        // skip over any input padding
        fseek(inptr, inpadding, SEEK_CUR);


        // print each row from buffer factor times
        for (int r = 0; r < n; r++)
        {
            // write RGB triple to outfile
            fwrite(arr, sizeof(RGBTRIPLE), bi.biWidth, outptr);

            // write padding to outfile
            for (int p = 0; p < outpadding; p++)
            fputc(0x00, outptr);
        }
        
    }
    free(arr);    
    fclose(inptr);
    fclose(outptr);

    }
    return 0;
    
    
}
        
 
