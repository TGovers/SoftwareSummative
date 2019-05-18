/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoftwareSummativeAudioProcessorEditor::SoftwareSummativeAudioProcessorEditor (SoftwareSummativeAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setSize (400, 300);
    
    mixSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mixSlider.setRange(0, 100.0);
    mixSlider.setTextValueSuffix("%");
    mixSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::pink);
    
    mixSlider.addListener(this);
    addAndMakeVisible(mixSlider);
    //mixAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "mix", mixSlider));
    
    addAndMakeVisible(mixLabel);
    mixLabel.setText("Wet/Dry Mix", dontSendNotification);
    mixLabel.attachToComponent(&mixSlider, false);
    
    filterCutoffDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterCutoffDial.setSize(150, 100);
    filterCutoffDial.setRange(20.0, 20000.0);
    filterCutoffDial.setTextValueSuffix("f");
    filterCutoffDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    filterCutoffDial.addListener(this);
    addAndMakeVisible(filterCutoffDial);
    
    filterResDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterResDial.setRange(1.0, 5.0);
    filterResDial.setTextValueSuffix("f");
    filterResDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
    
    filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "cutoff", filterCutoffDial);
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "resonance", filterResDial);
    
    filterCutoffDial.setSkewFactorFromMidPoint(1000.0f);

    
    
}

SoftwareSummativeAudioProcessorEditor::~SoftwareSummativeAudioProcessorEditor()
{
}

//==============================================================================
void SoftwareSummativeAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
    g.fillAll (Colours::darkorchid);
    
    g.setColour (Colours::aqua);
    g.setFont (15.0f);
    g.drawFittedText ("GOVERSA2 PLUGIN", getLocalBounds(), Justification::centred, 1);
    
    g.setColour(Colours::black);
    g.setFont(Font ("Arial", 20.0f, Font::italic));
    g.drawFittedText("Random Test Font! Hi There!", 10, 10, getWidth(), 50,
                     Justification::left, 1);
}

void SoftwareSummativeAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    mixSlider.setBounds(10, getHeight()-100, 80, 80);
    filterCutoffDial.setBounds(70, getHeight()-100, 80, 80);
    filterResDial.setBounds(50, getHeight()-100, 80, 80);
    
    
}

void SoftwareSummativeAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &mixSlider)
    {
        
        // get the value on the current slider, pass to audio processor
        processor.mixLevel.setTargetValue(mixSlider.getValue());
        
    }
    
    /*if (slider == &filterCutoffDial)
    {
        
        // get the value on the current slider, pass to audio processor
        processor.freqLevel.setTargetValue(filterCutoffDial.getValue());
        
    }
    
    if (slider == &filterResDial)
    {
        
        // get the value on the current slider, pass to audio processor
        processor.resLevel.setTargetValue(filterResDial.getValue());
        
    }*/
    
}
