/* Copyright 2021 eithanshavit
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
enum my_keycodes {
   NAVY_SEAL = SAFE_RANGE,
   REPORTED,
   DCRD_MUTE,
   DCRD_DEAFEN,
   FROG,
   ALTF4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_MNXT, KC_MPLY, KC_MPRV, MO(3), MO(2), TG(1)),
	[1] = LAYOUT(KC_X, KC_Z, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(FROG, NAVY_SEAL, REPORTED, ALTF4, KC_TRNS, KC_D),
	[3] = LAYOUT(KC_MNXT, DCRD_MUTE, DCRD_DEAFEN, KC_TRNS, KC_VOLU, KC_VOLD)
};

uint16_t startup_timer; 

//shows layer status
void render_info(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            oled_write_P(PSTR("OSU    Macros   Media\n"), false);
            oled_write_P(PSTR("Prev   Pause    Next"), false);
            break;
        case 1:
            oled_write_P(PSTR("Osu\n"), false);
            oled_write_P(PSTR("Base   Macros   Media\n"), false);
            oled_write_P(PSTR("ESC    Z        X   "), false);
            break;
        case 2:
            oled_write_P(PSTR("Macros\n"), false);
            oled_write_P(PSTR("Alt-F4 Macros   D    \n"), false);
            oled_write_P(PSTR("Racism Navy     Frog"), false);
            break;
        case 3:
            oled_write_P(PSTR("Media\n"), false);
            oled_write_P(PSTR("VolDn  VolUp    Media\n"), false);
            oled_write_P(PSTR("Deaf   Mute     Next"), false);
            break;
        default:
            break;
    }
}



/*void render_info(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_set_cursor(0, 0);
            oled_write_P(PSTR("Layer: Base\nOSU    Macros   Media\nPrev   Pause    Next \n"), false);
            break;
        case 1:
            oled_set_cursor(0, 0);
            oled_write_P(PSTR("Layer: OSU\nBase   Macros   Media\nZ      X        ESC  \n"), false);
            break;
        case 2:
            oled_set_cursor(0, 0);
            oled_write_P(PSTR("Layer: Macros\nAlt F4 Macros   Media\nNavy   Racism   FROG  \n"), false);
            break;
        case 3:
            oled_set_cursor(0, 0);
            oled_write_P(PSTR("Layer: Media\n"), false);
            break;
        default:
            oled_set_cursor(0, 0);
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }

}*/

//rotates the display by 180 degrees
//can be removed if rotation is not needed
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

//calls the oled render funcitons
void oled_task_user(void) {
    static bool finished_logo = false;
   if ((timer_elapsed(startup_timer) < 3000) && !finished_logo) {
        render_logo();
    } else {
        finished_logo = true;
        render_info();
    }
}

//defines macro
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case NAVY_SEAL:
         if (record->event.pressed) {
            // when keycode NAVY_SEAL is pressed
            SEND_STRING("What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills. I am trained in gorilla warfare and I'm the top sniper in the entire US armed forces. You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You're fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with my bare hands. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little clever comment was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn't, you didn't, and now you're paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You're fucking dead, kiddo.");
         } else {
            // when keycode NAVY_SEAL is released
         }
         break;
      case REPORTED:
         if (record->event.pressed) {
            // when keycode REPORTED is pressed
            SEND_STRING("reported for racism."SS_TAP(X_ENTER));
         } else {
            // when keycode REPORTED is pressed
         }
         break;
      case FROG:
         if (record->event.pressed) {
            // when keycode Q_REAL is pressed
            SEND_STRING("Poison dart frog (also known as dart-poison frog, poison frog or formerly known as poison arrow frog) is the common name of a group of frogs in the family Dendrobatidae which are native to tropical Central and South America.[2] These species are diurnal and often have brightly colored bodies. This bright coloration is correlated with the toxicity of the species, making them aposematic. Some species of the family Dendrobatidae exhibit extremely bright coloration along with high toxicity, while others have cryptic coloration with minimal to no amount of observed toxicity.[3] The species that have great toxicity derive this from their diet of ants, mites and termites.[3][4] Other species however, that exhibit cryptic coloration and low to no amounts of toxicity, eat a much larger variety of prey.[4] Many species of this family are threatened due to human infrastructure encroaching on their habitats. ");
         } else {
            // when keycode DCRD_MUTE is pressed
         }
         break;
      case ALTF4:
         if (record->event.pressed) {
            // when keycode ALTF4 is pressed
            SEND_STRING("hih");

         } else {
            // when keycode ALTF4 is released
         }
         break;
      case DCRD_MUTE:
         if (record->event.pressed) {
            // when keycode DCRD_MUTE is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("m")));
         } else {
            // when keycode DCRD_MUTE is pressed
         }
         break;
      case DCRD_DEAFEN:
         if (record->event.pressed) {
            // when keycode DCRD_DEAFEN is pressed
            SEND_STRING(SS_LCTL(SS_LSFT("d")));
         } else {
            // when keycode DCRD_DEAFEN is pressed
         }
         break;
   }
   return true;
};