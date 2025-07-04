#!/bin/bash
# https://www.cyberciti.biz/faq/linux-show-groups-for-user/
id -Gn $FT_USER | tr ' ' ',' | tr -d '\n' 
