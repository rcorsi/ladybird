/*
 * Copyright (c) 2025, Rocco Corsi <5201151+rcorsi@users.noreply.github.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWebView/Options.h>

namespace Gfx {

extern bool s_webgl_available;

ALWAYS_INLINE bool is_webgl_available() { return s_webgl_available; }
void init_graphics(WebView::GraphicalOptions);

};
