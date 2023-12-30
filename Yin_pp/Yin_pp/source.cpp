#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "yin.hpp"

#define AUDIOBUFFER_SIZE 240000

int audioBuffer_idx = 0;
int* audioBuffer = new int[AUDIOBUFFER_SIZE]();

int main(int argc, char** argv)
{
	// Load data from wav to audioBuffer
	FILE* fp = fopen("audio/test_notes.wav", "rb");
	fseek(fp, 44, SEEK_SET);
	// Quick + hacky, wav file is of known size/format.
	fread(audioBuffer, sizeof(int), AUDIOBUFFER_SIZE, fp);
	fclose(fp);

	Yin myYin = Yin();

	// Evaluate audio and dump results to .csv
	fp = fopen("audio/result.csv", "w");
	fprintf(fp, "Sample,Pitch,Harmonic Rate\n");
	int i = 0;
	while (!myYin.done)
	{
		// Loads next chunk from audioBuffer + computes pitch/harmonic rates for sample
		myYin.compute_yin();
		fprintf(fp, "%d,%f,%f\n", i++, myYin.get_pitch(), myYin.get_harmonic_rate());
	}
	fclose(fp);


	return 0;
}