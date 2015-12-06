#!/bin/bash
mencoder <($1 | $(dirname $0)/expand_video) \
         -audiofile <($1) -audio-demuxer rawaudio \
         -rawaudio channels=1:rate=8000:samplesize=1 -af channels=2 \
         -demuxer rawvideo -rawvideo fps=31.25:w=400:h=400:y8 \
         -o $(basename $1).avi -oac pcm -ovc lavc
