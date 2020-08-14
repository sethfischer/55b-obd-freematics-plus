"""
Validate that environment variables are correctly set

This script can not be run either manually or with a Python interpreter. It is
loaded automatically when the platformio run command processes the project
environment.
"""

# pylint: disable=undefined-variable

Import("env", "projenv")

name_prefix = "X55B"
defines = {}
error_messages = []


for define in projenv["CPPDEFINES"]:
    if type(define) is tuple:
        if define[0].startswith(name_prefix):
            defines[define[0]] = define[1]
    elif type(define) is str:
        if define.startswith(name_prefix):
            defines[define] = None


print("Checking required macros are set:")

for define in ["X55B_WIFI_PASS", "X55B_WIFI_SSID"]:
    if define not in defines:
        error_messages.append("{} is not defined.".format(define))
    elif len(defines[define].strip('\\"')) == 0:
        error_messages.append("{} has a zero-length value.".format(define))


if len(error_messages) > 0:
    for message in error_messages:
        print(" - [ERROR] {}".format(message))
    exit(1)
