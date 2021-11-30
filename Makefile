%: %.cpp rss.cpp rss.h
	g++ `xml2-config --cflags` -O2 -g $< rss.cpp `xml2-config --libs` -lm -o $@

HEADER_FILES = gps.h proj3.h
IMPLEMENTATION_FILES = gps.cpp proj3.cpp
