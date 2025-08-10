#!/bin/bash

echo "Please say the command (listening for 3 seconds)..."

# Record 3 seconds from your mic device
arecord -D plughw:0,0 -d 3 -f cd /tmp/command.wav

# Recognize speech and look for the word "down"
if pocketsphinx_continuous -infile /tmp/command.wav 2>/dev/null | grep -iq "down"; then
  echo "Voice command 'down' detected. Shutting down now..."
  sudo shutdown -h now
else
  echo "Command not recognized or not 'down'. Shutdown cancelled."
fi
