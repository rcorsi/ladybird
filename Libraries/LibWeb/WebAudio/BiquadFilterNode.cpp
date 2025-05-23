/*
 * Copyright (c) 2024, Bar Yemini <bar.ye651@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/Math.h>
#include <LibWeb/Bindings/AudioParamPrototype.h>
#include <LibWeb/Bindings/BiquadFilterNodePrototype.h>
#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/WebAudio/AudioNode.h>
#include <LibWeb/WebAudio/AudioParam.h>
#include <LibWeb/WebAudio/BaseAudioContext.h>
#include <LibWeb/WebAudio/BiquadFilterNode.h>

namespace Web::WebAudio {

GC_DEFINE_ALLOCATOR(BiquadFilterNode);

BiquadFilterNode::BiquadFilterNode(JS::Realm& realm, GC::Ref<BaseAudioContext> context, BiquadFilterOptions const& options)
    : AudioNode(realm, context)
    , m_type(options.type)
    , m_frequency(AudioParam::create(realm, context, options.frequency, 0, context->nyquist_frequency(), Bindings::AutomationRate::ARate))
    , m_detune(AudioParam::create(realm, context, options.detune, -1200 * AK::log2(NumericLimits<float>::max()), 1200 * AK::log2(NumericLimits<float>::max()), Bindings::AutomationRate::ARate))
    , m_q(AudioParam::create(realm, context, options.q, NumericLimits<float>::lowest(), NumericLimits<float>::max(), Bindings::AutomationRate::ARate))
    , m_gain(AudioParam::create(realm, context, options.gain, NumericLimits<float>::lowest(), 40 * AK::log10(NumericLimits<float>::max()), Bindings::AutomationRate::ARate))
{
}

BiquadFilterNode::~BiquadFilterNode() = default;

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-type
void BiquadFilterNode::set_type(Bindings::BiquadFilterType type)
{
    m_type = type;
}

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-type
Bindings::BiquadFilterType BiquadFilterNode::type() const
{
    return m_type;
}

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-frequency
GC::Ref<AudioParam> BiquadFilterNode::frequency() const
{
    return m_frequency;
}

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-detune
GC::Ref<AudioParam> BiquadFilterNode::detune() const
{
    return m_detune;
}

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-q
GC::Ref<AudioParam> BiquadFilterNode::q() const
{
    return m_q;
}

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-gain
GC::Ref<AudioParam> BiquadFilterNode::gain() const
{
    return m_gain;
}

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-getfrequencyresponse
WebIDL::ExceptionOr<void> BiquadFilterNode::get_frequency_response(GC::Root<WebIDL::BufferSource> const& frequency_hz, GC::Root<WebIDL::BufferSource> const& mag_response, GC::Root<WebIDL::BufferSource> const& phase_response)
{
    (void)frequency_hz;
    (void)mag_response;
    (void)phase_response;
    dbgln("FIXME: Implement BiquadFilterNode::get_frequency_response(Float32Array, Float32Array, Float32Array)");
    return {};
}

WebIDL::ExceptionOr<GC::Ref<BiquadFilterNode>> BiquadFilterNode::create(JS::Realm& realm, GC::Ref<BaseAudioContext> context, BiquadFilterOptions const& options)
{
    return construct_impl(realm, context, options);
}

// https://webaudio.github.io/web-audio-api/#dom-biquadfilternode-biquadfilternode
WebIDL::ExceptionOr<GC::Ref<BiquadFilterNode>> BiquadFilterNode::construct_impl(JS::Realm& realm, GC::Ref<BaseAudioContext> context, BiquadFilterOptions const& options)
{
    // When the constructor is called with a BaseAudioContext c and an option object option, the user agent
    // MUST initialize the AudioNode this, with context and options as arguments.
    auto node = realm.create<BiquadFilterNode>(realm, context, options);

    // Default options for channel count and interpretation
    // https://webaudio.github.io/web-audio-api/#BiquadFilterNode
    AudioNodeDefaultOptions default_options;
    default_options.channel_count_mode = Bindings::ChannelCountMode::Max;
    default_options.channel_interpretation = Bindings::ChannelInterpretation::Speakers;
    default_options.channel_count = 2;
    // FIXME: Set tail-time to yes

    TRY(node->initialize_audio_node_options(options, default_options));

    return node;
}

void BiquadFilterNode::initialize(JS::Realm& realm)
{
    WEB_SET_PROTOTYPE_FOR_INTERFACE(BiquadFilterNode);
    Base::initialize(realm);
}

void BiquadFilterNode::visit_edges(Cell::Visitor& visitor)
{
    Base::visit_edges(visitor);
    visitor.visit(m_frequency);
    visitor.visit(m_detune);
    visitor.visit(m_q);
    visitor.visit(m_gain);
}

}
