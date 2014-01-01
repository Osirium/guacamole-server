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

#include "config.h"

#include <cairo/cairo.h>
#include <guacamole/client.h>
#include <guacamole/protocol.h>
#include <guacamole/socket.h>

/* Macros for prettying up the embedded image. */
#define X 0x00,0x00,0x00,0xFF
#define O 0xFF,0xFF,0xFF,0xFF
#define _ 0x00,0x00,0x00,0x00

/* Dimensions */
const int guac_vnc_default_pointer_width  = 5;
const int guac_vnc_default_pointer_height = 5;

/* Format */
const cairo_format_t guac_vnc_default_pointer_format = CAIRO_FORMAT_ARGB32;
const int guac_vnc_default_pointer_stride = 20;

/* Embedded pointer graphic */
unsigned char guac_vnc_default_pointer[] = {

        _,O,O,O,_,
        O,X,X,X,O,
        O,X,X,X,O,
        O,X,X,X,O,
        _,O,O,O,_

};

void guac_vnc_set_default_pointer(guac_client* client) {

    guac_socket* socket = client->socket;

    /* Draw to buffer */
    guac_layer* cursor = guac_client_alloc_buffer(client);

    cairo_surface_t* graphic = cairo_image_surface_create_for_data(
            guac_vnc_default_pointer,
            guac_vnc_default_pointer_format,
            guac_vnc_default_pointer_width,
            guac_vnc_default_pointer_height,
            guac_vnc_default_pointer_stride);

    guac_protocol_send_png(socket, GUAC_COMP_SRC, cursor, 0, 0, graphic);
    cairo_surface_destroy(graphic);

    /* Set cursor */
    guac_protocol_send_cursor(socket, 2, 2, cursor,
            0, 0,
            guac_vnc_default_pointer_width,
            guac_vnc_default_pointer_height);

    /* Free buffer */
    guac_client_free_buffer(client, cursor);

}

