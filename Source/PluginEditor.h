/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SoftwareSummativeAudioProcessorEditor  : public AudioProcessorEditor, Slider::Listener
{
public:
    SoftwareSummativeAudioProcessorEditor (SoftwareSummativeAudioProcessor&);
    ~SoftwareSummativeAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    

private:
    
    Slider filterCutoffDial;
    Slider filterResDial;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterResValue;
    
    Label filterCutoffLabel;
    Label filterResLabel;
    
    Slider mixSlider;
    Label mixLabel;
    

    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mixAttachment;
    
    void sliderValueChanged(Slider * slider) override;



    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SoftwareSummativeAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoftwareSummativeAudioProcessorEditor)
};
