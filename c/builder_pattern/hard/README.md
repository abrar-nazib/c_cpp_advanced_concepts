# Layered Handles

- Layer 1: "writer" -> Writes raw bytes from somewhere
- Layer 2: "formatter" -> wraps a writter, adds timestamps and log levels
- Layer 3: "logger" -> wraps a formatter, provides conveninet info/warn/error functions

The user only sees logger handle. The formatter and writer are hidden inside