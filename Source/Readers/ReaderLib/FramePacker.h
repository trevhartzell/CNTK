//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#pragma once

#include "SequencePacker.h"

namespace Microsoft { namespace MSR { namespace CNTK {

//A packer optimized for the case of single-frame sequences.
class FramePacker : public SequencePacker
{
public:
    FramePacker(
        SequenceEnumeratorPtr sequenceEnumerator,
        const std::vector<StreamDescriptionPtr>& streams,
        bool useLocalTimeline = false,
        size_t numberOfBuffers = 2) :
        SequencePacker(sequenceEnumerator, streams, numberOfBuffers), m_useLocalTimeline(useLocalTimeline)
    {}

protected:
    MBLayoutPtr CreateMBLayout(const StreamBatch& batch) override;

    Sequences GetNextSequences() override;

private:
    bool m_useLocalTimeline;
};

typedef std::shared_ptr<FramePacker> FramePackerPtr;
} } }
