# Score Face

A watch face for keeping track of scores between two players during games or competitions on the Sensor Watch.

## Overview

The Score face allows you to maintain and display scores for two players simultaneously. It's perfect for keeping track of games like table tennis, badminton, card games, or any two-player competition where you need a simple scoreboard.

## Display

- **Top row**: Shows "SCORE" (or "SC" in compact mode)
- **Bottom row**: Shows the current scores in format `XXYY` where:
  - `XX` = Player 1 score (00-99)
  - `YY` = Player 2 score (00-99)

For example, if Player 1 has 15 points and Player 2 has 21 points, the display will show `1521`.

## Controls

### Light Button (Left Button)
- **Single Press**: Increment Player 1's score by 1
- **Long Press**: *(Light function disabled to prevent accidental activation)*

### Alarm Button (Right Button)
- **Single Press**: Increment Player 2's score by 1
- **Long Press**: Reset both players' scores to 00

### Mode Button (Bottom Button)
- **Single Press**: Move to next watch face
- **Long Press**: Return to first watch face

## Usage Instructions

1. **Starting a Game**:
   - Navigate to the Score face using the Mode button
   - Both scores will start at `0000` (00 for each player)

2. **Scoring Points**:
   - Press the Light button to give Player 1 a point
   - Press the Alarm button to give Player 2 a point
   - Scores update immediately on the display

3. **Resetting Scores**:
   - Hold the Alarm button (right button) for a long press
   - Both scores will reset to `0000`

4. **Maximum Scores**:
   - Each player's score is capped at 99 points
   - Attempting to increment beyond 99 will keep the score at 99

## Example Usage Scenarios

### Table Tennis Match
- Player 1 scores: Press Light button
- Player 2 scores: Press Alarm button  
- End of game: Long press Alarm to reset for next game

### Card Game Tracking
- Track cumulative points across multiple rounds
- Reset when starting a new game session

### General Competition
- Any two-player game where you need to track numerical scores
- Quick and easy score adjustments with immediate visual feedback

## Technical Details

- **State Persistence**: Scores are maintained in memory while the face is active
- **Score Range**: 0-99 for each player
- **Display Format**: 4-digit format (XXYY) for compact display
- **Memory Efficient**: Uses minimal memory with simple uint8_t variables

## Implementation

The Score face is implemented as a standard Sensor Watch movement face with:
- Setup function for initialization
- Loop function for handling button events
- Display function for updating the screen
- State management for score tracking

The face follows the standard Sensor Watch movement patterns and integrates seamlessly with the watch's power management and navigation system.
