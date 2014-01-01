/*
 * Copyright (C) 2013 Glyptodon LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#ifndef _SSH_GUAC_TERMINAL_HANDLERS
#define _SSH_GUAC_TERMINAL_HANDLERS

#include "config.h"

#include "terminal.h"

int guac_terminal_echo(guac_terminal* term, char c);
int guac_terminal_escape(guac_terminal* term, char c);
int guac_terminal_g0_charset(guac_terminal* term, char c);
int guac_terminal_g1_charset(guac_terminal* term, char c);
int guac_terminal_g2_charset(guac_terminal* term, char c);
int guac_terminal_g3_charset(guac_terminal* term, char c);
int guac_terminal_csi(guac_terminal* term, char c);
int guac_terminal_guac_download(guac_terminal* term, char c);
int guac_terminal_guac_set_directory(guac_terminal* term, char c);
int guac_terminal_osc(guac_terminal* term, char c);
int guac_terminal_ctrl_func(guac_terminal* term, char c);

#endif

