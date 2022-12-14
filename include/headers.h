#ifndef HEADERS_H
#define HEADERS_H

#include <string.h>

typedef enum HeaderType {
    CONTENT_TYPE = 0,
    CONTENT_LENGTH,
} HeaderType;

static const char* const header_types_str[] = {
    [CONTENT_TYPE] = "Content-Type",
    [CONTENT_LENGTH] = "Content-Length"
};

/*
typedef union {
    int integer;
    char* string;
} HeaderValue;
*/

typedef struct Header {
    HeaderType type;
    char* value;
} Header;

typedef struct Headers {
    size_t nb_headers;
    Header* headers;
} Headers;

Headers empty_headers();
size_t header_string_length(const Header* const header);
void header_to_string(const Header* const header, char* const dest);

#endif // HEADERS_H
