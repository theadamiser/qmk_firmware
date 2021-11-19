#pragma once

// Key behavior
#define ONESHOT_TIMEOUT 1000
#define TAPPING_TERM  180
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// QMK timeouts are broken. Disable them (and configure our own)
#define OLED_TIMEOUT 0
#define DISABLE_OLED_TIMEOUT
#define RGB_DISABLE_TIMEOUT 0
#define RGB_DISABLE_WHEN_USB_SUSPENDED // Required for rgb_matrix_set_suspend_state()
#define IDLE_TIMEOUT_RGB_OLED 120000

// State syncing between keyboard halves
// See: https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_split_keyboard
#define SPLIT_OLED_ENABLE
//#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_MODS_ENABLE

// OLED setup
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// RGB setup
#define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 8

// RGB Effects; Disable to enable
// #define DISABLE_RGB_MATRIX_ALPHAS_MODS 				  // Static dual hue, speed is hue for secondary hue
// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN			// Static gradient top to bottom, speed controls how much gradient changes
// #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT		// Static gradient left to right, speed controls how much gradient changes
#define DISABLE_RGB_MATRIX_BREATHING				        // Single hue brightness cycling animation
#define DISABLE_RGB_MATRIX_BAND_SAT 				        // Single hue band fading saturation scrolling left to right
#define DISABLE_RGB_MATRIX_BAND_VAL 				        // Single hue band fading brightness scrolling left to right
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT		    // Single hue 3 blade spinning pinwheel fades saturation
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL 		    // Single hue 3 blade spinning pinwheel fades brightness
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT 			    // Single hue spinning spiral fades saturation
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL 			    // Single hue spinning spiral fades brightness
#define DISABLE_RGB_MATRIX_CYCLE_ALL  				      // Full keyboard solid hue cycling through full gradient
// #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT 		  // Full gradient scrolling left to right
// #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN			    // Full gradient scrolling top to bottom
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN				      // Full gradient scrolling out to in
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL	    	// Full dual gradients scrolling out to in
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON	  // Full gradent Chevron shapped scrolling left to right
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL		    	  // Full gradient spinning pinwheel around center of keyboard
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL				      // Full gradient spinning spiral around center of keyboard
#define DISABLE_RGB_MATRIX_DUAL_BEACON				      // Full gradient spinning around center of keyboard
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON			      // Full tighter gradient spinning around center of keyboard
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS		    // Full dual gradients spinning two halfs of keyboard
// #define DISABLE_RGB_MATRIX_RAINDROPS				      // Randomly changes a single key's hue
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS		  // Randomly changes a single key's hue and saturation
#define DISABLE_RGB_MATRIX_HUE_BREATHING       		  // Hue shifts up a slight ammount at the same time, then shifts back
#define DISABLE_RGB_MATRIX_HUE_PENDULUM         	  // Hue shifts up a slight ammount in a wave to the right, then back to the left
#define DISABLE_RGB_MATRIX_HUE_WAVE             	  // Hue shifts up a slight ammount and then back down in a wave to the right

// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS 				  // Required for these...
#define DISABLE_RGB_MATRIX_TYPING_HEATMAP 			    // How hot is your WPM!
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN 			      // That famous computer simulation

// #define RGB_MATRIX_KEYPRESSES 						        // Required for these...
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE			      // Static single hue, pulses keys hit to shifted hue then fades to current hue
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE	  // Pulses keys hit to hue & value then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE 		  // Hue & value pulse near a single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE // Hue & value pulse near multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS		  // Hue & value pulse the same column and row of a single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS// Hue & value pulse the same column and row of multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS		  // Hue & value pulse away on the same column and row of a single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS// Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SPLASH					          // Full gradient & value pulse away from a single key hit then fades value out
#define DISABLE_RGB_MATRIX_MULTISPLASH		      		// Full gradient & value pulse away from multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_SPLASH				      // Hue & value pulse away from a single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH		    // Hue & value pulse away from multiple key hits then fades value out
