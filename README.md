# Yin_pp
C++ Implementation of Patrice Guyot's faster Yin pitch detection algorithm.

https://github.com/patriceguyot/Yin

Most methodology was taken directly from the difference function / CMNDF function in [yin.py](https://github.com/patriceguyot/Yin/blob/master/yin.py)

A very hacky first pass with lots of hard-coded values. Only works with the supplied audio file. 

Yin_pp/audio/ contains the source audio file and some excel files showing the results obtained by the yin algorithm.

## Dependencies
Uses the FFTW library for some calculations. https://www.fftw.org/install/windows.html
