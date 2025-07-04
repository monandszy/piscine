#!/bin/bash
find . -name "*.sh" -type f -exec basename {} .sh ';'
# searches current and subdirectory, only for files, then executes basename  to remove .sh
