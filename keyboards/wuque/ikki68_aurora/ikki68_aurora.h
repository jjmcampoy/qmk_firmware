/* Copyright 2021 wuquestudio
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

#include "quantum.h"


/* Standard Arrangement
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │2d │ │0e │0f │        ISO
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┤      ┌─────┐
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d   │ │1e │1f │      │1d   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┘   ┌──┴┐    │
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c      │             │2c │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤ ┌───┐       └───┴────┘
 * │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c    │3d │ │3e │
 * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬────┬┴─┬─┴─┼───┼───┐
 * │40  │41  │42  │44      │46  │48        │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────┴────┴──────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_all( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K2D,   K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,        K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C,                  \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,        K3E,      \
    K40, K41, K42,      K44,      K46,      K48,      K4A, K4B, K4C,        K4D, K4E, K4F  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F    }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F    }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   KC_NO, KC_NO  }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   KC_NO  }, \
    { K40,   K41,   K42,   KC_NO, K44,   KC_NO, K46,   KC_NO, K48,   KC_NO, K4A,   K4B,   K4C,   K4D,   K4E,   K4F    }, \
}


/* LAYOUT_68_ansi
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d     │ │0e │0f │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d   │ │1e │1f │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤ ┌───┐
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c        │ │3e │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬──┬─┴─┼───┼───┐
 * │40  │41  │42  │46                      │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_68_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C,             \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,   K3E,      \
    K40, K41, K42,                K46,                K4A, K4B, K4C,   K4D, K4E, K4F  \
) { \
    { K00,   K01,    K02,   K03,    K04,    K05,   K06,   K07,   K08,    K09,   K0A,   K0B,   K0C,   K0D,    K0E,   K0F    }, \
    { K10,   K11,    K12,   K13,    K14,    K15,   K16,   K17,   K18,    K19,   K1A,   K1B,   K1C,   K1D,    K1E,   K1F    }, \
    { K20,   K21,    K22,   K23,    K24,    K25,   K26,   K27,   K28,    K29,   K2A,   K2B,   K2C,   KC_NO,  KC_NO, KC_NO  }, \
    { K30,   KC_NO,  K32,   K33,    K34,    K35,   K36,   K37,   K38,    K39,   K3A,   K3B,   K3C,   KC_NO,  K3E,   KC_NO  }, \
    { K40,   K41,    K42,   KC_NO,  KC_NO,  KC_NO, K46,   KC_NO, KC_NO,  KC_NO, K4A,   K4B,   K4C,   K4D,    K4E,   K4F    }, \
}


/* LAYOUT_68_ansi_split_lshift
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d     │ │0e │0f │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d   │ │1e │1f │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c      │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤ ┌───┐
 * │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c        │ │3e │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬──┬─┴─┼───┼───┐
 * │40  │41  │42  │46                      │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_68_ansi_split_lshift( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C,             \
    K30, k31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,   K3E,      \
    K40, K41, K42,                K46,                K4A, K4B, K4C,   K4D, K4E, K4F  \
) { \
    { K00,   K01,    K02,   K03,    K04,    K05,   K06,   K07,   K08,    K09,   K0A,   K0B,   K0C,   K0D,    K0E,   K0F    }, \
    { K10,   K11,    K12,   K13,    K14,    K15,   K16,   K17,   K18,    K19,   K1A,   K1B,   K1C,   K1D,    K1E,   K1F    }, \
    { K20,   K21,    K22,   K23,    K24,    K25,   K26,   K27,   K28,    K29,   K2A,   K2B,   K2C,   KC_NO,  KC_NO, KC_NO  }, \
    { K30,   k31,    K32,   K33,    K34,    K35,   K36,   K37,   K38,    K39,   K3A,   K3B,   K3C,   KC_NO,  K3E,   KC_NO  }, \
    { K40,   K41,    K42,   KC_NO,  KC_NO,  KC_NO, K46,   KC_NO, KC_NO,  KC_NO, K4A,   K4B,   K4C,   K4D,    K4E,   K4F    }, \
}


/* LAYOUT_68_ansi_split_rshift
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d     │ │0e │0f │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d   │ │1e │1f │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤ ┌───┐
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c    │3d │ │3e │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┴─┬─┴─┼───┼───┐
 * │40  │41  │42  │46                      │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_68_ansi_split_rshift( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C,             \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,   K3E,      \
    K40, K41, K42,                K46,                K4A, K4B, K4C,   K4D, K4E, K4F  \
) { \
    { K00,   K01,    K02,   K03,    K04,    K05,   K06,   K07,   K08,    K09,   K0A,   K0B,   K0C,   K0D,    K0E,   K0F    }, \
    { K10,   K11,    K12,   K13,    K14,    K15,   K16,   K17,   K18,    K19,   K1A,   K1B,   K1C,   K1D,    K1E,   K1F    }, \
    { K20,   K21,    K22,   K23,    K24,    K25,   K26,   K27,   K28,    K29,   K2A,   K2B,   K2C,   KC_NO,  KC_NO, KC_NO  }, \
    { K30,   KC_NO,  K32,   K33,    K34,    K35,   K36,   K37,   K38,    K39,   K3A,   K3B,   K3C,   K3D,    K3E,   KC_NO  }, \
    { K40,   K41,    K42,   KC_NO,  KC_NO,  KC_NO, K46,   KC_NO, KC_NO,  KC_NO, K4A,   K4B,   K4C,   K4D,    K4E,   K4F    }, \
}


/* LAYOUT_68_ansi_split_bs
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │2d │ │0e │0f │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d   │ │1e │1f │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤ ┌───┐
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c        │ │3e │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬──┬─┴─┼───┼───┐
 * │40  │41  │42  │46                      │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_68_ansi_split_bs( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K2D,   K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,        K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C,                  \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,        K3E,      \
    K40, K41, K42,                K46,                K4A, K4B, K4C,        K4D, K4E, K4F  \
) { \
    { K00,   K01,    K02,   K03,    K04,    K05,   K06,   K07,   K08,    K09,   K0A,   K0B,   K0C,   K0D,    K0E,   K0F    }, \
    { K10,   K11,    K12,   K13,    K14,    K15,   K16,   K17,   K18,    K19,   K1A,   K1B,   K1C,   K1D,    K1E,   K1F    }, \
    { K20,   K21,    K22,   K23,    K24,    K25,   K26,   K27,   K28,    K29,   K2A,   K2B,   K2C,   K2D,    KC_NO, KC_NO  }, \
    { K30,   KC_NO,  K32,   K33,    K34,    K35,   K36,   K37,   K38,    K39,   K3A,   K3B,   K3C,   KC_NO,  K3E,   KC_NO  }, \
    { K40,   K41,    K42,   KC_NO,  KC_NO,  KC_NO, K46,   KC_NO, KC_NO,  KC_NO, K4A,   K4B,   K4C,   K4D,    K4E,   K4F    }, \
}


/* LAYOUT_68_iso
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d     │ │0e │0f │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d   │ │1e │1f │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │ └───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │    │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤ ┌───┐
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c        │ │3e │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬──┬─┴─┼───┼───┐
 * │40  │41  │42  │46                      │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_68_iso( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,        K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K1D,             \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,   K3E,      \
    K40, K41, K42,                K46,                K4A, K4B, K4C,   K4D, K4E, K4F  \
) { \
    { K00,   K01,    K02,   K03,    K04,    K05,   K06,   K07,   K08,    K09,   K0A,   K0B,   K0C,   K0D,    K0E,   K0F    }, \
    { K10,   K11,    K12,   K13,    K14,    K15,   K16,   K17,   K18,    K19,   K1A,   K1B,   K1C,   K1D,    K1E,   K1F    }, \
    { K20,   K21,    K22,   K23,    K24,    K25,   K26,   K27,   K28,    K29,   K2A,   K2B,   K2C,   KC_NO,  KC_NO, KC_NO  }, \
    { K30,   KC_NO,  K32,   K33,    K34,    K35,   K36,   K37,   K38,    K39,   K3A,   K3B,   K3C,   KC_NO,  K3E,   KC_NO  }, \
    { K40,   K41,    K42,   KC_NO,  KC_NO,  KC_NO, K46,   KC_NO, KC_NO,  KC_NO, K4A,   K4B,   K4C,   K4D,    K4E,   K4F    }, \
}

/* LAYOUT_68_iso_split_lshift_split_rshift
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d     │ │0e │0f │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │2c   │ │1e │1f │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │ └───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │1d │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┤ ┌───┐
 * │30  |31 │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c    |3d │ │3e │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┴─┬─┴─┼───┼───┐
 * │40  │41  │42  │46                      │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_68_iso_split_lshift_split_rshift( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,  K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,       K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K1D, K2C,            \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,  K3E,      \
    K40, K41, K42,                K46,                K4A, K4B, K4C,  K4D, K4E, K4F  \
) { \
    { K00,   K01,    K02,   K03,    K04,    K05,   K06,   K07,   K08,    K09,   K0A,   K0B,   K0C,   K0D,    K0E,   K0F    }, \
    { K10,   K11,    K12,   K13,    K14,    K15,   K16,   K17,   K18,    K19,   K1A,   K1B,   K1C,   K1D,    K1E,   K1F    }, \
    { K20,   K21,    K22,   K23,    K24,    K25,   K26,   K27,   K28,    K29,   K2A,   K2B,   K2C,   KC_NO,  KC_NO, KC_NO  }, \
    { K30,   K31,    K32,   K33,    K34,    K35,   K36,   K37,   K38,    K39,   K3A,   K3B,   K3C,   K3D,    K3E,   KC_NO  }, \
    { K40,   K41,    K42,   KC_NO,  KC_NO,  KC_NO, K46,   KC_NO, KC_NO,  KC_NO, K4A,   K4B,   K4C,   K4D,    K4E,   K4F    }, \
}

/* LAYOUT_68_ansi_split_space
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d     │ │0e │0f │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d   │ │1e │1f │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤ ┌───┐
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c        │ │3e │
 * ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬────┬──┬─┴─┼───┼───┐
 * │40  │41  │42  │44      │46  │48        │4a  │4b  │4c  │  │4d │4e │4f │
 * └────┴────┴────┴────────┴────┴──────────┴────┴────┴────┘  └───┴───┴───┘
 */
#define LAYOUT_68_ansi_split_space( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,   K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,   K1E, K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C,             \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,   K3E,      \
    K40, K41, K42,      K44,      K46,      K48,      K4A, K4B, K4C,   K4D, K4E, K4F  \
) { \
    { K00,   K01,    K02,   K03,    K04,    K05,   K06,   K07,   K08,    K09,   K0A,   K0B,   K0C,   K0D,    K0E,   K0F    }, \
    { K10,   K11,    K12,   K13,    K14,    K15,   K16,   K17,   K18,    K19,   K1A,   K1B,   K1C,   K1D,    K1E,   K1F    }, \
    { K20,   K21,    K22,   K23,    K24,    K25,   K26,   K27,   K28,    K29,   K2A,   K2B,   K2C,   KC_NO,  KC_NO, KC_NO  }, \
    { K30,   KC_NO,  K32,   K33,    K34,    K35,   K36,   K37,   K38,    K39,   K3A,   K3B,   K3C,   KC_NO,  K3E,   KC_NO  }, \
    { K40,   K41,    K42,   KC_NO,  K44,    KC_NO, K46,   KC_NO, K48,    KC_NO, K4A,   K4B,   K4C,   K4D,    K4E,   K4F    }, \
}
