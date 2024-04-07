/* Copyright 2020 Jrodna
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

#pragma once

#define KC_SHSP SHIFTSPACE

#include "quantum.h"

<<<<<<< HEAD:keyboards/afternoonlabs/gust/rev1/rev1.h
#define LAYOUT( \
    M00, M01, M02, \
    M10, M11, M12  \
) \
{ \
    { M00, M01, M02 }, \
    { M10, M11, M12 }  \
}
=======
enum custom_keycodes {
    SHIFTSPACE = QK_KB_0,
};
>>>>>>> b0e948c380a073833a38881e998963db4da456e0:keyboards/orthocode/orthocode.h
