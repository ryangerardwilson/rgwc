#ifndef RGWC_H
#define RGWC_H

/* Print a heading with the specified text in uppercase, formatted as '[call_count] TEXT ===== [hh:mm:ss]'
 * Total line length is at most 79 characters.
 * Args:
 *   text: The heading text to print.
 */
void heading(const char *text);

/* Print a sub-heading under the most recent heading, formatted as '[heading_num.sub_heading_num] TEXT ----- [hh:mm:ss]'
 * Total line length is at most 79 characters.
 * Args:
 *   text: The sub-heading text to print.
 * Returns:
 *   0 on success, -1 if no heading has been called.
 */
int sub_heading(const char *text);

#endif
