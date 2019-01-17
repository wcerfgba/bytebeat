#!/bin/bash
aplay -t raw -f U8 -c 1 -r 8000 <($1)