#include "SPI.h"
using namespace std;

int main (int argc, char **argv)
{
	uint8_t **segment;
	
	unsigned int length, spi_device, n, i, j;

	length = 164;
	n = 60;
	spi_device = 0;
	segment = new uint8_t *[n];
	for (i=0; i<n; i++)
		segment[i] = new uint8_t[length];

	SpiOpenPort(spi_device);
	for (i=0; i<n; i++)
		SpiRead(0, segment[i], length);

	SpiClosePort(spi_device);
	for (j=0; j<n; j++) 
	{
		for (i = 0; i < length; i++)
		{
			cout << (unsigned int) (segment[j][i]);
			cout << " "; 
		}
		cout << endl;
	}
	
	for (i=0; i<n; i++)
		delete[] segment[i];
	delete[] segment;

	return 0;
}
