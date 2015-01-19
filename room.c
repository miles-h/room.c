#include <stdio.h>

/* --- Function Prototypes --- */

float floor_area(float ax, float ay);
float room_volume(float vx, float vy, float vz);
float paint_needed(float px, float py, float pz, float coverage, float coats);

/* --- Main --- */

int main()
{
	char ret;

	do
	{
		int number;
		float x, y, z, coverage, coats;

		//print
		printf("\nThis program will calculate (assuming rectangluar cuboid):\n\n1. Floor Area\n\n2. Room Volume\n\n3. Paint Required\n\n");
		printf("Please Enter Number (1, 2 or 3):\n\n");

		//switch
		number = getchar();
		switch(number)
		{
			case '1':

			printf("\nEnter Floor Length(m):\n");
			scanf("%f",&x);

			printf("\nEnter Floor Width(m):\n");
			scanf("%f",&y);

			printf("\nThe area of the floor (to the nearest cm):\n%.2fm^2", floor_area(x, y));

			break;

			case '2':

			printf("\nEnter Floor Length(m):\n");
			scanf("%f",&x);
			printf("\nEnter Floor Width(m):\n");
			scanf("%f",&y);
			printf("\nEnter Room Height(m):\n");
			scanf("%f",&z);

			printf("\nThe volume of the room (to the nearest cm):\n%.2fm^3", room_volume(x, y, z)); 

			break;

			case '3':

			printf("\nEnter Floor Length(m):\n");
			scanf("%f",&x);
			printf("\nEnter Floor Width(m):\n");
			scanf("%f",&y);
			printf("\nEnter Room Height(m):\n");
			scanf("%f",&z);

			printf("\nEnter coverage of paint(m^2/L) (average = 9.1m^2/L)\n");
			scanf("%f",&coverage);
			while( getchar() != '\n'){            } //input buffer flush
			printf("\nEnter Number of Coatings\n");
			scanf("%f",&coats);

			printf("\nThe amount of paint required (to the nearist ml): \n%.3fL", paint_needed(x, y, z, coverage, coats ));

			break;
			//case 'default':
		}

		printf("\n\nEnter 'y' to return to menu\n");
		while( getchar() != '\n'){            } //input buffer flush
		scanf("%c",&ret);
		while( getchar() != '\n'){            } //input buffer flush

	}
	while (ret == 'y' || ret == 'Y');
}

/* --- Functions --- */

float floor_area(float x, float y)
{

	float area;

	area = x*y;

	return area;

}

float room_volume(float x, float y, float z)
{

	float volume;

	volume = x*y*z;

	return volume;

}

float paint_needed(float x, float y, float z, float coverage, float coats)
{

	float paint;

	paint = ((2 * x * z)+(2 * y * z));
	paint = paint / coverage;
	paint = paint * coats;

	return paint;

}
