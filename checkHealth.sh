#!/bin/bash

# Created by James Schmiechen
# 08/11/2019 at 6:40 PM.

# How to use:
# ./checkHealth.sh https://www.google.com Taskmgr.exe


# Get headers and use status code to check health.
status_code=$(curl --write-out %{http_code} --silent --output /dev/null $1)
	
if [[ $status_code -ne 200 ]]
then	
	echo "Could not connect to the requested URL. Status code: $status_code"
	
	# Check if given process is running on this system.
	# Could use pgrep here, but it may not be installed on the customers system.
	# ps aux and grep could work but it has false positives.
	# Tasklist ate up cpu resources which is not good when this script runs every minute.
	# Ended up using QPROCESS which is simple and works well. Requires admin privileges
	# which may not be possible for everyone. However it works on 90% of windows OSs
	if ! QPROCESS "$2" > NUL 2>&1
	then
		echo "Could not find any instances of $2 running on this system."
	fi
fi	

# Run this every minute using a cron job.