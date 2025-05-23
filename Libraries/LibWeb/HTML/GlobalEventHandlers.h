/*
 * Copyright (c) 2021, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Forward.h>
#include <LibWeb/Forward.h>

#define ENUMERATE_GLOBAL_EVENT_HANDLERS(E)                                    \
    E(onabort, HTML::EventNames::abort)                                       \
    E(onauxclick, UIEvents::EventNames::auxclick)                             \
    E(onbeforeinput, HTML::EventNames::beforeinput)                           \
    E(onbeforematch, HTML::EventNames::beforematch)                           \
    E(onbeforetoggle, HTML::EventNames::beforetoggle)                         \
    E(onblur, HTML::EventNames::blur)                                         \
    E(oncancel, HTML::EventNames::cancel)                                     \
    E(oncanplay, HTML::EventNames::canplay)                                   \
    E(oncanplaythrough, HTML::EventNames::canplaythrough)                     \
    E(onchange, HTML::EventNames::change)                                     \
    E(onclick, UIEvents::EventNames::click)                                   \
    E(onclose, HTML::EventNames::close)                                       \
    E(oncommand, HTML::EventNames::command)                                   \
    E(oncontextlost, HTML::EventNames::contextlost)                           \
    E(oncontextmenu, HTML::EventNames::contextmenu)                           \
    E(oncontextrestored, HTML::EventNames::contextrestored)                   \
    E(oncopy, HTML::EventNames::copy)                                         \
    E(oncuechange, HTML::EventNames::cuechange)                               \
    E(oncut, HTML::EventNames::cut)                                           \
    E(ondblclick, UIEvents::EventNames::dblclick)                             \
    E(ondrag, HTML::EventNames::drag)                                         \
    E(ondragend, HTML::EventNames::dragend)                                   \
    E(ondragenter, HTML::EventNames::dragenter)                               \
    E(ondragleave, HTML::EventNames::dragleave)                               \
    E(ondragover, HTML::EventNames::dragover)                                 \
    E(ondragstart, HTML::EventNames::dragstart)                               \
    E(ondrop, HTML::EventNames::drop)                                         \
    E(ondurationchange, HTML::EventNames::durationchange)                     \
    E(onemptied, HTML::EventNames::emptied)                                   \
    E(onended, HTML::EventNames::ended)                                       \
    E(onerror, HTML::EventNames::error)                                       \
    E(onfocus, HTML::EventNames::focus)                                       \
    E(onfocusin, HTML::EventNames::focusin)                                   \
    E(onfocusout, HTML::EventNames::focusout)                                 \
    E(onformdata, HTML::EventNames::formdata)                                 \
    E(ongotpointercapture, UIEvents::EventNames::gotpointercapture)           \
    E(oninput, HTML::EventNames::input)                                       \
    E(oninvalid, HTML::EventNames::invalid)                                   \
    E(onkeydown, UIEvents::EventNames::keydown)                               \
    E(onkeypress, UIEvents::EventNames::keypress)                             \
    E(onkeyup, UIEvents::EventNames::keyup)                                   \
    E(onload, HTML::EventNames::load)                                         \
    E(onloadeddata, HTML::EventNames::loadeddata)                             \
    E(onloadedmetadata, HTML::EventNames::loadedmetadata)                     \
    E(onloadstart, HTML::EventNames::loadstart)                               \
    E(onlostpointercapture, UIEvents::EventNames::lostpointercapture)         \
    E(onmousedown, UIEvents::EventNames::mousedown)                           \
    E(onmouseenter, UIEvents::EventNames::mouseenter)                         \
    E(onmouseleave, UIEvents::EventNames::mouseleave)                         \
    E(onmousemove, UIEvents::EventNames::mousemove)                           \
    E(onmouseout, UIEvents::EventNames::mouseout)                             \
    E(onmouseover, UIEvents::EventNames::mouseover)                           \
    E(onmouseup, UIEvents::EventNames::mouseup)                               \
    E(onpaste, HTML::EventNames::paste)                                       \
    E(onpause, HTML::EventNames::pause)                                       \
    E(onplay, HTML::EventNames::play)                                         \
    E(onplaying, HTML::EventNames::playing)                                   \
    E(onpointercancel, UIEvents::EventNames::pointercancel)                   \
    E(onpointerdown, UIEvents::EventNames::pointerdown)                       \
    E(onpointerenter, UIEvents::EventNames::pointerenter)                     \
    E(onpointerleave, UIEvents::EventNames::pointerleave)                     \
    E(onpointermove, UIEvents::EventNames::pointermove)                       \
    E(onpointerout, UIEvents::EventNames::pointerout)                         \
    E(onpointerover, UIEvents::EventNames::pointerover)                       \
    E(onpointerrawupdate, UIEvents::EventNames::pointerrawupdate)             \
    E(onpointerup, UIEvents::EventNames::pointerup)                           \
    E(onprogress, HTML::EventNames::progress)                                 \
    E(onratechange, HTML::EventNames::ratechange)                             \
    E(onreset, HTML::EventNames::reset)                                       \
    E(onresize, HTML::EventNames::resize)                                     \
    E(onscroll, HTML::EventNames::scroll)                                     \
    E(onscrollend, HTML::EventNames::scrollend)                               \
    E(onsecuritypolicyviolation, HTML::EventNames::securitypolicyviolation)   \
    E(onseeked, HTML::EventNames::seeked)                                     \
    E(onseeking, HTML::EventNames::seeking)                                   \
    E(onselect, HTML::EventNames::select)                                     \
    E(onselectionchange, HTML::EventNames::selectionchange)                   \
    E(onslotchange, HTML::EventNames::slotchange)                             \
    E(onstalled, HTML::EventNames::stalled)                                   \
    E(onsubmit, HTML::EventNames::submit)                                     \
    E(onsuspend, HTML::EventNames::suspend)                                   \
    E(ontimeupdate, HTML::EventNames::timeupdate)                             \
    E(ontoggle, HTML::EventNames::toggle)                                     \
    E(onvolumechange, HTML::EventNames::volumechange)                         \
    E(onwaiting, HTML::EventNames::waiting)                                   \
    E(onwebkitanimationend, HTML::EventNames::webkitAnimationEnd)             \
    E(onwebkitanimationiteration, HTML::EventNames::webkitAnimationIteration) \
    E(onwebkitanimationstart, HTML::EventNames::webkitAnimationStart)         \
    E(onwebkittransitionend, HTML::EventNames::webkitTransitionEnd)           \
    E(onwheel, UIEvents::EventNames::wheel)

namespace Web::HTML {

class GlobalEventHandlers {
public:
    virtual ~GlobalEventHandlers();

#undef __ENUMERATE
#define __ENUMERATE(attribute_name, event_name)       \
    void set_##attribute_name(WebIDL::CallbackType*); \
    WebIDL::CallbackType* attribute_name();
    ENUMERATE_GLOBAL_EVENT_HANDLERS(__ENUMERATE)
#undef __ENUMERATE

protected:
    virtual GC::Ptr<DOM::EventTarget> global_event_handlers_to_event_target(FlyString const& event_name) = 0;
};

}
