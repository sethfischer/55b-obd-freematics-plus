#!/usr/bin/env python3
"""Generate device UUID"""

import uuid


UUID_VERSION = 4
filename = "uuid.txt"


def validate_uuid4(uuid_string):
    """
    Validate that a string is a valid uuid4.
    """

    uuid_string = uuid_string.replace("-", "")

    try:
        val = uuid.UUID(uuid_string, version=UUID_VERSION)
    except ValueError:
        raise

    return val.hex == uuid_string


try:
    with open(filename, "r") as file:
        uuid_string = file.read().replace("\n", "").strip()
        validate_uuid4(uuid_string)
        device_uuid = uuid.UUID("urn:uuid:{}".format(uuid_string), version=UUID_VERSION)
except (FileNotFoundError, ValueError):
    device_uuid = uuid.uuid4()
    with open(filename, "w") as file:
        file.write(str(device_uuid))

print("-D X55B_DEVICE_UUID='\"{}\"'".format(str(device_uuid)))
