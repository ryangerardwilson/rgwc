#define _POSIX_C_SOURCE 200112L // Enable POSIX features for nanosleep
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "rgwc.h"

static unsigned int current_call = 0;           // Tracks heading count
static unsigned int current_heading_num = 0;    // Tracks current heading number
static unsigned int sub_heading_counts[100] = {0}; // Tracks sub-heading counts per heading

void heading(const char *text)
{
    char buf[80] = "";                         // Final output buffer (79 chars + null)
    char temp[62] = "";                        // Temp buffer for prefix + text (max 61 chars)
    char upper_text[55] = "";                  // Text after prefix (61 - 7 for "[99999] ")
    size_t i, text_len = strlen(text);

    // Convert text to uppercase, truncate to fit within 61 - prefix length
    size_t max_prefix_len = 7;                 // Max "[99999] " length
    for (i = 0; i < text_len && i < 54; i++) { // 54 = 61 - 7
        upper_text[i] = toupper(text[i]);
    }
    upper_text[i] = '\0';

    // Increment heading call
    current_call++;
    current_heading_num = current_call;
    sub_heading_counts[current_heading_num] = 0;

    // Format heading: [call_count] TEXT
    char prefix[8];                            // Max "[99999] " (7 chars + null)
    snprintf(prefix, sizeof(prefix), "[%u] ", current_call);
    strncat(temp, prefix, sizeof(temp) - strlen(temp) - 1);
    strncat(temp, upper_text, sizeof(temp) - strlen(temp) - 1);
    temp[61] = '\0';                           // Cap temp at 61 chars

    // Get timestamp
    char timestamp[9];                         // Max "hh:mm:ss" (8 chars + null)
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%H:%M:%S", tm);
    timestamp[8] = '\0';                       // Cap timestamp at 8 chars

    // Calculate padding
    int padding_length = 79 - strlen(temp) - 1 - strlen(timestamp) - 2; // 1 for space, 2 for [ ]
    char padding[80] = "";
    if (padding_length > 0) {
        memset(padding, '=', padding_length);
        padding[padding_length] = '\0';
    } else {
        padding[0] = '\0';                     // No padding if negative
    }

    // Combine full line: temp + space + padding + space + [timestamp]
    snprintf(buf, sizeof(buf), "%s %s [%s", temp, padding, timestamp);
    buf[79] = '\0';                            // Ensure max 78 chars (leave room for ])

    // Print with typewriter effect
    printf("\n\033[92m");                      // Empty line before, green font
    for (i = 0; i < strlen(buf); i++) {
        putchar(buf[i]);
        fflush(stdout);
        struct timespec ts = {0, (long)(0.01 * 1000000000)}; // 10ms delay
        nanosleep(&ts, NULL);
    }
    putchar(']');
    fflush(stdout);
    printf("\n\033[0m\n");                     // Newline, reset color, empty line after
}

int sub_heading(const char *text)
{
    if (current_heading_num == 0) {
        fprintf(stderr, "Error: No heading called before sub_heading.\n");
        return -1;
    }

    char buf[80] = "";                         // Final output buffer (79 chars + null)
    char temp[62] = "";                        // Temp buffer for prefix + text (max 61 chars)
    size_t i;

    // Increment sub-heading count
    sub_heading_counts[current_heading_num]++;

    // Format sub-heading: [heading_num.sub_heading_num] TEXT
    size_t max_prefix_len = 9;                 // Max "[999.999] " length
    char prefix[10];                           // Max "[999.999] " (9 chars + null)
    snprintf(prefix, sizeof(prefix), "[%u.%u] ", current_heading_num, sub_heading_counts[current_heading_num]);
    size_t max_text_length = 61 - strlen(prefix);
    char formatted_text[53];                   // 61 - 9 for "[999.999] "
    strncpy(formatted_text, text, max_text_length);
    formatted_text[max_text_length] = '\0';
    strncat(temp, prefix, sizeof(temp) - strlen(temp) - 1);
    strncat(temp, formatted_text, sizeof(temp) - strlen(temp) - 1);
    temp[61] = '\0';                           // Cap temp at 61 chars

    // Get timestamp
    char timestamp[9];                         // Max "hh:mm:ss" (8 chars + null)
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%H:%M:%S", tm);
    timestamp[8] = '\0';                       // Cap timestamp at 8 chars

    // Calculate padding
    int padding_length = 79 - strlen(temp) - 1 - strlen(timestamp) - 2; // 1 for space, 2 for [ ]
    char padding[80] = "";
    if (padding_length > 0) {
        memset(padding, '-', padding_length);
        padding[padding_length] = '\0';
    } else {
        padding[0] = '\0';                     // No padding if negative
    }

    // Combine full line: temp + space + padding + space + [timestamp]
    snprintf(buf, sizeof(buf), "%s %s [%s", temp, padding, timestamp);
    buf[79] = '\0';                            // Ensure max 78 chars (leave room for ])

    // Print with typewriter effect
    printf("\n\033[92m");                      // Empty line before, green font
    for (i = 0; i < strlen(buf); i++) {
        putchar(buf[i]);
        fflush(stdout);
        struct timespec ts = {0, (long)(0.01 * 1000000000)}; // 10ms delay
        nanosleep(&ts, NULL);
    }
    putchar(']');
    fflush(stdout);
    printf("\n\033[0m\n");                     // Newline, reset color, empty line after

    return 0;
}
