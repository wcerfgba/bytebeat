#!/bin/bash
echo "did you start jackd? jackd -R -dalsa -r8000"
mplayer -audiofile <($1) -audio-demuxer rawaudio \
        -rawaudio rate=8000:samplesize=1:channels=1 -af channels=2 -ao jack \
        -demuxer rawvideo -rawvideo fps=31.25:w=400:h=400:format=bgr16 \
        <($1 | $(dirname $0)/expand_video_color)
