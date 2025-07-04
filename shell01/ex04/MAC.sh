#!/bin/bash
ifconfig -a | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}'
# https://stackoverflow.com/questions/245916/best-way-to-extract-mac-address-from-ifconfigs-output
