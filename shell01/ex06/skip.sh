#!/bin/bash
ls -l | sed -n '1~2p'
# skips lines 1 3 5..
