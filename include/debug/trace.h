/*
 * Debug via printing to the serial port.
 *
 * The Freematics ONE Plus A and B devices do not make GPIO pins 12 to 15
 * available for JTAG debugging. Therefore we must use Serial.println() to
 * implement basic tracing.
 */

#ifndef DEBUGTRACE_H
#define DEBUGTRACE_H

#ifdef DEBUG
#define DEBUG_TRACE(message) Serial.println(message);
#else
#define DEBUG_TRACE(x)
#endif

#endif
