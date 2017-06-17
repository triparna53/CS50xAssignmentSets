#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char* argv[])
{
		if (argc != 2)
		{
				fprintf(stderr, "Usage:recover image\n");
				return 1;
		}
		char* image = argv[1];
		// Open the cardfile, return if there's a problem with it
		FILE* fp = fopen(image, "r");	

		if(fp == NULL)
		{	
				fclose(fp);
				fprintf(stderr, "Wasn't able to open the cardfile.\n");
				return 1;
		}

		// These are the starting bytes of a jpeg file.
		uint8_t checkjpg1[4] = {0xff, 0xd8, 0xff, 0xe0};
		uint8_t checkjpg2[4] = {0xff, 0xd8, 0xff, 0xe1};

		// This keeps track of jpeg files found in the bytestream
		// We use it to create filenames.
		int jpg = 0;

		// Open outfile indicator
		int open = 0;
		FILE* op;

	  // Read 512b blocks from file.
		uint8_t buffer[512];
		uint8_t check[4];
		fread(buffer, 512, 1, fp);	

		while(fread(buffer, 512, 1, fp) > 0)
		{
				// Add first four bytes into the check buffer
			for(int i = 0; i < 4; i++)
			{
				check[i] = buffer[i];
			}

			if((memcmp(checkjpg1, check, 4) == 0 ) || (memcmp(checkjpg2, check, sizeof(check)) == 0))
			{
				char filename[8];
				sprintf(filename, "%03d.jpg", jpg);
					if(open == 0)
					{
    					op = fopen(filename, "w");
						fwrite(buffer, sizeof(buffer), 1, op);
						open = 1;
					}
					if(open == 1)
					{
						fclose(op);
						op = fopen(filename, "w");
						fwrite(buffer, sizeof(buffer), 1, op);
						jpg++;
					}
				}
				else
				{
					if(open == 1)
					fwrite(buffer, sizeof(buffer), 1, op);
				}
		}
    if(op)
      fclose(op);
    
	fclose(fp);
		return 0;
}