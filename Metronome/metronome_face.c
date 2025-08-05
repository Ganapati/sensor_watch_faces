/*
 * MIT License
 *
 * Copyright (c) 2025 GANA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "metronome_face.h"

void metronome_face_setup(uint8_t watch_face_index, void ** context_ptr) {
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(metronome_state_t));
        memset(*context_ptr, 0, sizeof(metronome_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void metronome_face_activate(void *context) {
    metronome_state_t *state = (metronome_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
}

bool metronome_face_loop(movement_event_t event, void *context) {
    metronome_state_t *state = (metronome_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_text_with_fallback(WATCH_POSITION_TOP, "Music", "MC");
            watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, " Off", "OO");
            state->menu_state = 0; // Reset menu state to normal
            state->bpm = 60; // Default BPM
            state->beats_per_measure = 4; // Default beats per measure
            state->muted = true; // Start muted
            state->is_active = false; // Start inactive
            state->current_beat = 1; // Start at the first beat

            break;
        case EVENT_TICK:
            if (state->is_active && state->menu_state == 0) {
                if (state->current_beat == state->beats_per_measure) {
                    watch_set_led_color_rgb(255, 0, 0); // Flash red for the last beat
                    if (!state->muted) {
                        watch_buzzer_play_note(BUZZER_NOTE_A4, 100);
                    }
                } else {
                    watch_set_led_off(); // Disable LEDs for non-last beats
                    if (!state->muted) {
                        watch_buzzer_play_note(BUZZER_NOTE_D4 , 100);
                    }
                }

                char beat_text[5];
                snprintf(beat_text, sizeof(beat_text), "%04d", state->current_beat);
                watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, beat_text, beat_text);

                state->current_beat++;
                if (state->current_beat > state->beats_per_measure) {
                    state->current_beat = 1; // Reset to first beat after reaching the last
                }
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (state->muted) {
                // If muted, unmute and display the current BPM
                state->muted = false;
                watch_set_indicator(WATCH_INDICATOR_BELL);
            } else {
                // Mute the metronome
                state->muted = true;
                watch_clear_indicator(WATCH_INDICATOR_BELL);
            }
            
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Increment BPM and display it
            if (state->menu_state == 1) {
                state->bpm++;
                if (state->bpm > 240) { // Limit BPM to a maximum of 240
                    state->bpm = 60;
                }
                char bpm_text[5];
                snprintf(bpm_text, sizeof(bpm_text), "%04d", state->bpm);
                watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, bpm_text, bpm_text);
            } else if (state->menu_state == 2) {
                // Increment beats and display it
                state->beats_per_measure++;
                if (state->beats_per_measure > 16) { // Limit beats to a maximum of 16
                    state->beats_per_measure = 1;
                }
                char beats_text[5];
                snprintf(beats_text, sizeof(beats_text), "  %02d", state->beats_per_measure);
                watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, beats_text, beats_text);
            }

            // If in normal mode, start/stop the metronome
            else {
                state->is_active = !state->is_active;
                if (!state->is_active) {
                    state->current_beat = 1;
                    watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, " Off", "00");
                    watch_set_led_off();
                    movement_request_tick_frequency(128); // Set a low tick frequency when inactive
                } else {
                    state->current_beat = 1; // Reset to first beat when starting
                    movement_request_tick_frequency(state->bpm / 60); // Update tick frequency based on BPM
                }

            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // Do nothing, just override light
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->menu_state == 0) {
                // Switch to BPM menu
                state->menu_state = 1;
                watch_display_text_with_fallback(WATCH_POSITION_TOP, "BPM  ", "BM");
                char bpm_text[5];
                snprintf(bpm_text, sizeof(bpm_text), "%04d", state->bpm);
                watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, bpm_text, bpm_text);
            } else if (state->menu_state == 1) {
                // Switch to Beats menu
                state->menu_state = 2;
                watch_display_text_with_fallback(WATCH_POSITION_TOP, "Beat ", "BT");
                char beats_text[5];
                snprintf(beats_text, sizeof(beats_text), "  %02d", state->beats_per_measure);
                watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, beats_text, beats_text);
            } else {
                // Return to normal mode
                state->menu_state = 0;
                watch_display_text_with_fallback(WATCH_POSITION_TOP, "Music", "MC");
                watch_display_text_with_fallback(WATCH_POSITION_BOTTOM, "  00", "00");
            }
            break;
        default:
            return movement_default_loop_handler(event);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void metronome_face_resign(void *context) {
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

