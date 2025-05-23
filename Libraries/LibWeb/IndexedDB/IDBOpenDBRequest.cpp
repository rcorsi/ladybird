/*
 * Copyright (c) 2024, Shannon Booth <shannon@serenityos.org>
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 * Copyright (c) 2025, stelar7 <dudedbz@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/IDBOpenDBRequestPrototype.h>
#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/HTML/EventNames.h>
#include <LibWeb/IndexedDB/IDBOpenDBRequest.h>

namespace Web::IndexedDB {

GC_DEFINE_ALLOCATOR(IDBOpenDBRequest);

IDBOpenDBRequest::~IDBOpenDBRequest() = default;

// NOTE: The source of an open request is always null.
IDBOpenDBRequest::IDBOpenDBRequest(JS::Realm& realm)
    : IDBRequest(realm, {})
{
}

void IDBOpenDBRequest::initialize(JS::Realm& realm)
{
    WEB_SET_PROTOTYPE_FOR_INTERFACE(IDBOpenDBRequest);
    Base::initialize(realm);
}

GC::Ref<IDBOpenDBRequest> IDBOpenDBRequest::create(JS::Realm& realm)
{
    return realm.create<IDBOpenDBRequest>(realm);
}

// https://w3c.github.io/IndexedDB/#dom-idbopendbrequest-onblocked
void IDBOpenDBRequest::set_onblocked(WebIDL::CallbackType* event_handler)
{
    set_event_handler_attribute(HTML::EventNames::blocked, event_handler);
}

// https://w3c.github.io/IndexedDB/#dom-idbopendbrequest-onblocked
WebIDL::CallbackType* IDBOpenDBRequest::onblocked()
{
    return event_handler_attribute(HTML::EventNames::blocked);
}

// https://w3c.github.io/IndexedDB/#dom-idbopendbrequest-onupgradeneeded
void IDBOpenDBRequest::set_onupgradeneeded(WebIDL::CallbackType* event_handler)
{
    set_event_handler_attribute(HTML::EventNames::upgradeneeded, event_handler);
}

// https://w3c.github.io/IndexedDB/#dom-idbopendbrequest-onupgradeneeded
WebIDL::CallbackType* IDBOpenDBRequest::onupgradeneeded()
{
    return event_handler_attribute(HTML::EventNames::upgradeneeded);
}

}
