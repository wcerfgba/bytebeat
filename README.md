bytebeat A/V hacking tools
==========================

This is music:
`((t>>1%128)+20)*3*t>>14*t>>18`

See
[http://countercomplex.blogspot.co.uk/2011/10/algorithmic-symphonies-from-one-line-of.html]
for original work on 'bytebeat',
[http://canonical.org/~kragen/bytebeat/]
for an overview.

0xA did some video work, documented at
[https://web.archive.org/web/20160320001528/http://0xa.kuri.mu/2011/10/09/bitop-videos/]
which led to me recreating his mplayer work. Along with a horrible hack to get 
more pixels because I hate upscaling.


philez
------

 * codes/

   C source for various bytebeat tunes.

 * tools/expand_video.c

   Takes output from a tune and formats for 400x400 pixel Y800 raw video, 
   consisting of a 16x16 array of 25x25 pixel blocks, each representative of 
   1 byte of output. This creates a video stream at 31.25 fps.

 * tools/play.sh

   Takes tune binary as an argument and plays in mplayer. Audio plays through 
   JACK because I couldn't make ALSA do 8kHz, so start jackd first (see sauce).

 * tools/render.sh

   Renders to AVI with mencoder.

 * tools/expand_video_color.c

   Same as expand_video.c but prints each byte twice for use with 16-bit color 
   formats.

 * tools/expand_video_color_int16.c

   Same as expand_video.c but takes 2 bytes of input each time and gives a 
   256x256 array of 2x2 pixel blocks.

 * tools/play_color.sh

   Same as play.sh but uses bgr16 pixel format and expands with 
   expand_video_color.c.

 * tools/play_color_int16.sh

   Same as play_color.sh but also sets up audio for 2-byte samples. This 
   necessitates high sample rate.
