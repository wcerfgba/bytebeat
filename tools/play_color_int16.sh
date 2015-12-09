#!/bin/bash
echo "did you start jackd? jackd -R -dalsa -r131072"
mplayer -audiofile <($1) -audio-demuxer rawaudio \
        -rawaudio rate=131072:samplesize=2:channels=1 -af channels=2 -ao jack \
        -demuxer rawvideo -rawvideo fps=2:w=512:h=512:format=bgr16 \
        <($1 | $(dirname $0)/expand_video_color_int16)
