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
    setSize (800, 600);
    
    /*mixSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mixSlider.setRange(0, 100.0);
    mixSlider.setTextValueSuffix("%");
    mixSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::pink);
    
    mixSlider.addListener(this);
    addAndMakeVisible(mixSlider);
    //mixAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "mix", mixSlider));
    
    addAndMakeVisible(mixLabel);
    mixLabel.setText("Wet/Dry Mix", dontSendNotification);
    mixLabel.attachToComponent(&mixSlider, false);
    */
     
    filterCutoffDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterCutoffDial.setSize(150, 100);
    //filterCutoffDial.setRange(20.0, 20000.0);
    filterCutoffDial.setTextValueSuffix("f");
    //filterCutoffDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    filterCutoffDial.addListener(this);
    addAndMakeVisible(filterCutoffDial);
    
    filterResDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterResDial.setSize(150, 100);
    //filterResDial.setRange(1.0, 5.0);
    filterResDial.setTextValueSuffix("f");
    //filterResDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
    
    // dont change these two
    filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "cutoff", filterCutoffDial);
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "resonance", filterResDial);
    
    filterCutoffDial.setSkewFactorFromMidPoint(1000.0f);
    
    filterCutoffDial.setLookAndFeel(&otherLookAndFeel2);
    filterResDial.setLookAndFeel(&otherLookAndFeel2);
    
    addAndMakeVisible(filterCutoffLabel);
    filterCutoffLabel.setText("Cutoff Freq", dontSendNotification);
    mixLabel.attachToComponent(&filterCutoffDial, false);
    
    addAndMakeVisible(filterResLabel);
    filterResLabel.setText("Q", dontSendNotification);
    filterResLabel.attachToComponent(&filterResDial, false);
    
    distDriveDial.setSliderStyle(Slider::SliderStyle::Rotary);
    distDriveDial.setSize(150, 100);
    //distDriveDial.setRange(20.0, 20000.0);
    distDriveDial.setTextValueSuffix("f");
    //distDriveDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distDriveDial.addListener(this);
    addAndMakeVisible(distDriveDial);
    
    distRangeDial.setSliderStyle(Slider::SliderStyle::Rotary);
    distRangeDial.setSize(150, 100);
    //distRangeDial.setRange(20.0, 20000.0);
    distRangeDial.setTextValueSuffix("f");
    //distRangeDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distRangeDial.addListener(this);
    addAndMakeVisible(distRangeDial);
    
    distBlendDial.setSliderStyle(Slider::SliderStyle::Rotary);
    distBlendDial.setSize(150, 100);
    //distBlendDial.setRange(20.0, 20000.0);
    distBlendDial.setTextValueSuffix("f");
    //distBlendDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distBlendDial.addListener(this);
    addAndMakeVisible(distBlendDial);
    
    distVolumeDial.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    distVolumeDial.setSize(150, 100);
    //distVolumeDial.setRange(20.0, 20000.0);
    distVolumeDial.setTextValueSuffix("f");
    //distVolumeDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distVolumeDial.addListener(this);
    addAndMakeVisible(distVolumeDial);
    
    distDriveDial.setLookAndFeel(&otherLookAndFeel);
    distRangeDial.setLookAndFeel(&otherLookAndFeel);
    distBlendDial.setLookAndFeel(&otherLookAndFeel);
    distVolumeDial.setLookAndFeel(&otherLookAndFeel);
    
    
    // dont change these four
    distDriveValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "drive", distDriveDial);
    distRangeValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "range", distRangeDial);
    distBlendValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "blend", distBlendDial);
    distVolumeValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "volume", distVolumeDial);
    
    addAndMakeVisible(distDriveLabel);
    distDriveLabel.setText("DistDrive", dontSendNotification);
    distDriveLabel.attachToComponent(&distDriveDial, false);
    
    addAndMakeVisible(distRangeLabel);
    distRangeLabel.setText("DistRange", dontSendNotification);
    distRangeLabel.attachToComponent(&distRangeDial, false);
    
    addAndMakeVisible(distBlendLabel);
    distBlendLabel.setText("DistBlend", dontSendNotification);
    distBlendLabel.attachToComponent(&distBlendDial, false);
    
    addAndMakeVisible(distVolumeLabel);
    distVolumeLabel.setText("DistVolume", dontSendNotification);
    distVolumeLabel.attachToComponent(&distVolumeDial, false);
    
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
    
    //mixSlider.setBounds(10, getHeight()-100, 80, 80);
    filterCutoffDial.setBounds(150, getHeight()-200, 80, 80);
    filterResDial.setBounds(300, getHeight()-200, 80, 80);
    distDriveDial.setBounds(150, getHeight()-400, 80, 80);
    distRangeDial.setBounds(300, getHeight()-400, 80, 80);
    distBlendDial.setBounds(450, getHeight()-400, 80, 80);
    distVolumeDial.setBounds(600, getHeight()-400, 80, 80);
    
    
}

void SoftwareSummativeAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &mixSlider)
    {
        // dont change any of this void function
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
