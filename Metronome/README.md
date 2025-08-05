# Metronome Face

A digital metronome watch face for the Sensor Watch that provides accurate timing for musical practice and performance.

## Overview

The Metronome face transforms your Sensor Watch into a portable metronome with customizable BPM (Beats Per Minute), time signatures, and both audio and visual feedback. Perfect for musicians, dancers, and anyone who needs precise timing assistance.

## Features

- **Adjustable BPM**: 60-240 beats per minute
- **Variable Time Signatures**: 1-16 beats per measure
- **Audio Feedback**: Different tones for downbeats and regular beats
- **Visual Feedback**: LED flashes red on the last beat of each measure
- **Mute Function**: Silent operation with visual-only feedback
- **Beat Counter**: Shows current beat position in the measure

## Display Modes

### Normal Mode
- **Top row**: "Music" (or "MC" in compact mode)
- **Bottom row**: Shows current beat number or "Off" when inactive

### BPM Configuration Mode
- **Top row**: "BPM" (or "BM" in compact mode)
- **Bottom row**: Shows current BPM value (e.g., "0120" for 120 BPM)

### Beats Configuration Mode
- **Top row**: "Beat" (or "BT" in compact mode) 
- **Bottom row**: Shows beats per measure (e.g., " 04" for 4/4 time)

## Controls

### Light Button (Left Button)
- **Single Press**: Toggle mute/unmute
  - When unmuted: Bell indicator appears, audio feedback enabled
  - When muted: Bell indicator disappears, visual-only feedback
- **Long Press**: Cycle through configuration modes
  - Normal → BPM → Beats → Normal

### Alarm Button (Right Button)
- **Single Press**: 
  - **Normal Mode**: Start/Stop the metronome
  - **BPM Mode**: Increment BPM by 1 (60-240, wraps to 60 after 240)
  - **Beats Mode**: Increment beats per measure by 1 (1-16, wraps to 1 after 16)

### Mode Button (Bottom Button)
- **Single Press**: Move to next watch face
- **Long Press**: Return to first watch face

## Usage Instructions

### Basic Operation

1. **Starting the Metronome**:
   - Navigate to the Metronome face
   - Press the Alarm button (right) to start
   - The display will show the current beat number
   - LED will flash red on the last beat of each measure

2. **Stopping the Metronome**:
   - Press the Alarm button again to stop
   - Display will show "Off"
   - LED will turn off

3. **Muting/Unmuting**:
   - Press the Light button to toggle sound on/off
   - Bell indicator shows when sound is enabled
   - Visual feedback continues when muted

### Configuration

#### Setting BPM (Tempo)
1. Long press the Light button to enter BPM mode
2. Display shows "BPM" and current tempo
3. Press Alarm button to increment BPM
4. Long press Light button to exit configuration

#### Setting Time Signature
1. From BPM mode, long press Light button to enter Beats mode
2. Display shows "Beat" and current beats per measure
3. Press Alarm button to increment beats per measure
4. Long press Light button to return to normal mode

## Audio and Visual Feedback

### Audio Cues
- **Regular Beats**: Lower tone (D4 note)
- **Last Beat of Measure**: Higher tone (A4 note) - the "downbeat"
- **Duration**: 100ms per beep

### Visual Cues
- **Regular Beats**: LED off
- **Last Beat of Measure**: LED flashes red
- **Muted Mode**: Bell indicator disappears

## Example Usage Scenarios

### 4/4 Time at 120 BPM (Common Rock/Pop)
1. Set beats per measure to 4
2. Set BPM to 120
3. Start metronome - counts 1-2-3-4 with red flash on beat 4

### 3/4 Time at 180 BPM (Waltz)
1. Set beats per measure to 3
2. Set BPM to 180
3. Start metronome - counts 1-2-3 with red flash on beat 3

### Practice Session
1. Start with slower tempo for learning
2. Gradually increase BPM as you improve
3. Use mute mode for silent practice with visual cues only

## Technical Details

### BPM Range and Accuracy
- **Minimum**: 60 BPM (1 beat per second)
- **Maximum**: 240 BPM (4 beats per second)
- **Increment**: 1 BPM steps
- **Accuracy**: Based on watch crystal oscillator precision

### Time Signatures
- **Range**: 1-16 beats per measure
- **Common Uses**:
  - 2: 2/4 time (marches)
  - 3: 3/4 time (waltzes)
  - 4: 4/4 time (most popular music)
  - 6: 6/8 time (compound time)

### Power Management
- **Active Mode**: Higher tick frequency for precise timing
- **Inactive Mode**: Low tick frequency (128 Hz) for power saving
- **Automatic**: Frequency adjusts based on BPM when active

## Default Settings

When first activated, the metronome starts with:
- **BPM**: 60 (moderate tempo)
- **Beats per Measure**: 4 (4/4 time signature)
- **State**: Muted and inactive
- **Current Beat**: 1 (ready to start on downbeat)

## Tips for Musicians

1. **Start Slow**: Begin practice at a comfortable tempo, then gradually increase
2. **Use Visual Mode**: Practice silently with mute on to avoid disturbing others
3. **Accent Awareness**: Pay attention to the red LED flash for proper downbeat emphasis
4. **Odd Time Signatures**: Experiment with different beat counts for complex rhythms
5. **Subdivision Practice**: Use higher BPM settings to practice note subdivisions

## Troubleshooting

- **No Sound**: Check if muted (bell indicator should be visible when unmuted)
- **Wrong Tempo**: Enter BPM mode and verify the displayed tempo
- **Inconsistent Timing**: Ensure watch has adequate battery level
- **LED Not Flashing**: Metronome may not be active - press Alarm button to start
