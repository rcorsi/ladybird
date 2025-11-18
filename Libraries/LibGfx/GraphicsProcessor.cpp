/*
 * Copyright (c) 2025, Rocco Corsi <5201151+rcorsi@users.noreply.github.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibGfx/GraphicsProcessor.h>
#ifdef AK_OS_MACOS
#    include <LibGfx/MetalContext.h>
#endif
#ifdef USE_VULKAN
#    include <LibGfx/VulkanContext.h>
#endif
#include <LibWebView/Options.h>

namespace Gfx {

bool s_webgl_available { false };

void init_graphics(WebView::GraphicalOptions graphical_options)
{
    if (graphical_options.force_cpu_painting == WebView::ForceCpuPainting::Yes) {
        dbgln("Falling back to CPU Backend painting");
        return;
    }

#ifdef USE_VULKAN
    Gfx::init_vulkan_context();
    s_webgl_available = Gfx::is_vulkan_webgl_available();
    dbgln("WebGL is: {}", s_webgl_available ? "available"sv : "unavailable"sv);
    return;
#elif defined(AK_OS_MACOS)
    Gfx::init_metal_context();
    s_webgl_available = true;
    dbgln("WebGL is: {}", s_webgl_available ? "available"sv : "unavailable"sv);
    return;
#endif

    dbgln("Falling back to CPU Backend painting");
}

}
