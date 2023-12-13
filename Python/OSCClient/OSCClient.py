
"""Small example OSC client

This program sends 10 random values between 0.0 and 1.0 to the /filter address,
waiting for 1 seconds between each value.
"""
import argparse
import random
import time

from pythonosc import udp_client


if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--ip", default="127.0.0.1",
      help="The ip of the OSC server")
  parser.add_argument("--port", type=int, default=5005,
      help="The port the OSC server is listening on")
  args = parser.parse_args()

  client = udp_client.SimpleUDPClient(args.ip, args.port)

  #for x in range(100):
  count = -1

  while count<0:
    client.send_message("/ArucoMarker", "ArucoMarker")
    client.send_message("/PosX", random.random())
    client.send_message("/PosY", random.random())
    client.send_message("/PosZ", random.random())
    client.send_message("/AngX", random.random())
    client.send_message("/AngY", random.random())
    client.send_message("/AngZ", random.random())
    time.sleep(1)