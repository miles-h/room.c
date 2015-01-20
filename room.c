#include <stdio.h>

/* --- Function Prototypes --- */

float floor_area(float ax, float ay);
float room_volume(float vx, float vy, float vz);
float paint_needed(float px, float py, float pz, float obst, float coverage, float coats);

/* --- Main --- */

int main()
{
	char ret; //variable for yes loops

	do
	{
		int number;
		float x, y, z, coverage, coats;
		float obst = 1;

		//print
		printf("\nThis program will calculate (assuming rectangluar cuboid):\n\n1. Floor Area\n\n2. Room Volume\n\n3. Paint Required\n\n");
		printf("Please Enter Number (1, 2 or 3):\n\n");

		//switch
		number = getchar();
		switch(number)
		{
			case '1':

			//Dimentions
			printf("\nEnter Floor Length(m):\n");
			scanf("%f",&x);
			printf("\nEnter Floor Width(m):\n");
			scanf("%f",&y);

			//Final Output
			printf("\nThe area of the floor (to the nearest cm):\n%.2fm^2", floor_area(x, y));

			break;

			case '2':

			//Dimentions
			printf("\nEnter Floor Length(m):\n");
			scanf("%f",&x);
			printf("\nEnter Floor Width(m):\n");
			scanf("%f",&y);
			printf("\nEnter Room Height(m):\n");
			scanf("%f",&z);

			//Final Output
			printf("\nThe volume of the room (to the nearest cm):\n%.2fm^3", room_volume(x, y, z)); 

			break;

			case '3':

			//Dimentions
			printf("\nEnter Floor Length(m):\n");
			scanf("%f",&x);
			printf("\nEnter Floor Width(m):\n");
			scanf("%f",&y);
			printf("\nEnter Room Height(m):\n");
			scanf("%f",&z);

			//Other Obsitcles (Optional)
			printf("\nDo you need to take account of obstacles (e.g Doors)?\nEnter 'y' for yes:\n");
			while( getchar() != '\n'){            } //input buffer flush
			scanf ("%c",&ret);
			if (ret == 'y' || ret == 'Y')
			{
				int i,j,k;
				float temp_ox,temp_oy,ox,oy;
				printf("\nHow many?:\n");
				scanf("%d",&i);
				k = i;
				j = 0;
				temp_ox = temp_oy = ox = oy = 0;

				while(k != 0)
				{
					j++;
					printf("\nEnter dimensions(m) of no. %d:\n",j);
					printf("Height:\n");
					scanf("%f",&temp_ox);
					printf("\nWidth:\n");
					scanf("%f",&temp_oy);

					ox = ox + temp_ox;
					oy = oy + temp_oy;

					k--;

				}

				obst = ox*oy;	//total to subtract from surface area
			}
			else
			{
				obst = 0;	//total to subtract from surface area
			}

			printf("\nEnter coverage of paint(m^2/L) (average = 15m^2/L):\n");
			scanf("%f",&coverage);
			while( getchar() != '\n'){            } //input buffer flush
			printf("\nEnter Number of Coatings:\n");
			scanf("%f",&coats);

			//Final Output
			printf("\nThe amount of paint required (to the nearist ml): \n%.3fL", paint_needed(x, y, z, obst, coverage, coats ));

			break;

		}

		//Restart program prompt
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

float paint_needed(float x, float y, float z, float obst, float coverage, float coats)
{

	float paint;

	paint = (x * z)+(y * z);
	paint = paint * 2;
	paint = paint - obst;
	paint = paint / coverage;
	paint = paint * coats;

	return paint;

}
