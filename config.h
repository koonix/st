/* st's config
 * See LICENSE file for copyright and license details. */

/* fonts */
static char *font = "monospace:size=13";
static char *font2[] = {
	":lang=fa:spacing=mono:size=14",
	"Symbols Nerd Font:size=11", /* you must put nerd fonts under the alias 'nerd' in fontconfig */
};

/* width of the border relative to the width of a terminal cell */
static float borderwidth = 1.8;

/* wether to interpret space+modkeys and backspace+modkeys as special bindings.
 * these bindings are annoying since these key combos are
 * pressed accidentally very often when typing */
#define SPACE_BINDINGS 0

/* wether to confirm before closing when there is an active child process */
static const int allowforceclose = 1;

/*
 * What program is execed by st depends of these precedence rules:
 * 1: program passed with -e
 * 2: scroll and/or utmp
 * 3: SHELL environment variable
 * 4: value of shell in /etc/passwd
 * 5: value of shell in config.h
 */
static char *shell = "/bin/sh";
char *utmp = NULL;
/* scroll program: to enable use a string like "scroll" */
char *scroll = NULL;
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";

/* identification sequence returned in DA and DECID */
char *vtiden = "\033[?6c";

/* Kerning / character bounding-box multipliers */
static float cwscale = 1.0;
static float chscale = 1.0;

/* word delimiter string */
wchar_t *worddelimiters = L" `'\"()[]{}│<>│";

/* selection timeouts (in milliseconds) */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

/* alt screens */
int allowaltscreen = 1;

/* allow certain non-interactive (insecure) window operations such as:
   setting the clipboard text */
int allowwindowops = 0;

/* reset title too on 'ESC c' (RIS) escape code */
int resettitleonris = 0;

/*
 * draw latency range in ms - from new content/keypress/etc until drawing.
 * within this range, st draws when content stops arriving (idle). mostly it's
 * near minlatency, but it waits longer for slow updates to avoid partial draw.
 * low minlatency will tear/flicker more, as it can "detect" idle too early.
 */
static double minlatency = 8;
static double maxlatency = 33;

/*
 * blinking timeout (set to 0 to disable blinking) for the terminal blinking
 * attribute.
 */
static unsigned int blinktimeout = 800;

/*
 * 1: render most of the lines/blocks characters without using the font for
 *    perfect alignment between cells (U2500 - U259F except dashes/diagonals).
 *    Bold affects lines thickness if boxdraw_bold is not 0. Italic is ignored.
 * 0: disable (render all U25XX glyphs normally from the font).
 */
const int boxdraw = 1;
const int boxdraw_bold = 0;

/* braille (U28XX):  1: render as adjacent "pixels",  0: use font */
const int boxdraw_braille = 1;

/*
 * thickness of underline and bar cursors
 */
static unsigned int cursorthickness = 1;

/*
 * bell volume. It must be a value between -100 and 100. Use 0 for disabling
 * it
 */
static int bellvolume = 0;

/* default TERM value */
char *termname = "st-256color";

/* default class and name hints */
static char *defaultclass = "st-256color";
static char *defaultname = "st";

/*
 * spaces per tab
 *
 * When you are changing this value, don't forget to adapt the »it« value in
 * the st.info and appropriately install the st.info in the environment where
 * you use this st version.
 *
 *	it#$tabspaces,
 *
 * Secondly make sure your kernel is not expanding tabs. When running `stty
 * -a` »tab0« should appear. You can tell the terminal to not expand tabs by
 *  running following command:
 *
 *	stty tabs
 */
unsigned int tabspaces = 8;

/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
	/* 8 normal colors */
	"#3c3836", /* black   */
	"#e0261f", /* red     */
	"#a7a51c", /* green   */
	"#eca624", /* yellow  */
	"#4c9496", /* blue    */
	"#c36c95", /* magenta */
	"#73ad75", /* cyan    */
	"#c7c4bb", /* white   */

	/* 8 bright colors */
	"#665c54", /* black   */
	"#fb4934", /* red     */
	"#b8bb26", /* green   */
	"#fabd2f", /* yellow  */
	"#83a598", /* blue    */
	"#d3869b", /* magenta */
	"#8ec07c", /* cyan    */
	"#e6e2d8", /* white   */

	[255] = 0,

	/* more colors can be added after 255 to use with defaultXX */
	"#181b1c", /* default background */
	"#c7c4bb", /* default foreground */
	"#bdae93", /* cursor */
	"#504945", /* selection */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor, selection
 */
unsigned int defaultfg = 257;
unsigned int defaultbg = 256;
unsigned int defaultcs = 258;
static unsigned int defaultrcs = 256;
static unsigned int selectionbg = 259;
static unsigned int selectionfg = 257;
/* Owerwrite foreground colors of selected cells with selectionfg */
static int useselectionfg = 0;

/*
 * Default shape of cursor
 * 2: Block ("█")
 * 4: Underline ("_")
 * 6: Bar ("|")
 * 7: Snowman ("☃")
 */
static unsigned int cursorshape = 6;

/*
 * Default columns and rows numbers
 */

static unsigned int cols = 80;
static unsigned int rows = 24;

/*
 * Default colour and shape of the mouse cursor
 */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;

/*
 * Color used to display font attributes when fontconfig selected a font which
 * doesn't match the ones requested.
 */
static unsigned int defaultattr = 11;

/*
 * Force mouse select/shortcuts while mask is active (when MODE_MOUSE is set).
 * Note that if you want to use ShiftMask with selmasks, set this to an other
 * modifier, set to 0 to not use it.
 */
static uint forcemousemod = ShiftMask;

/*
 * Internal mouse shortcuts.
 * Beware that overloading Button1 will disable the selection.
 * If altsreen is 1, shortcut will only work when altscreen is active and if -1,
 * only when altscreen is not active.
 */
static MouseShortcut mshortcuts[] = {
	/* mask                 button   function        argument       release altscreen */
	{ XK_ANY_MOD,           Button4, kscrollup,      {.i = 1},      0,      -1 },
	{ XK_ANY_MOD,           Button5, kscrolldown,    {.i = 1},      0,      -1 },
	{ XK_ANY_MOD,           Button2, selpaste,       {.i = 0},      1 },
	{ ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
	{ ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
};

/* commands */
#define CMD(...) { .histlines = -1, .cmd = (char *const[]){ __VA_ARGS__, NULL } };
static ExternalPipe pipeurl = CMD("pipeurl", "ask")
static ExternalPipe editor  = CMD( "/bin/sh", "-c",
    "f=$(mktemp) && trap 'rm -f \"$f\"' EXIT && cat > \"$f\" && st -e nvim -Rc'normal G' \"$f\""
)

#define Alt           Mod1Mask
#define CtrlAlt       Alt|ControlMask
#define CtrlShift     ControlMask|ShiftMask
#define CtrlShiftAlt  Alt|CtrlShift

/* Internal keyboard shortcuts. */
static Shortcut shortcuts[] = {
	/* mask                   keysym          function        argument */
	{ XK_ANY_MOD,             XK_Break,       sendbreak,      {.i =  0} },
	{ CtrlShift,              XK_Num_Lock,    numlock,        {.i =  0} },
	{ CtrlShiftAlt,           XK_Y,           clipcopy,       {.i =  0} },
	{ CtrlShiftAlt,           XK_P,           clippaste,      {.i =  0} },
	{ CtrlShift,              XK_K,           kscrollup,      {.i =  1} },
	{ CtrlShift,              XK_J,           kscrolldown,    {.i =  1} },
	{ CtrlShift,              XK_U,           kscrollup,      {.i = -2} },
	{ CtrlShift,              XK_D,           kscrolldown,    {.i = -2} },
	{ CtrlShiftAlt,           XK_K,           zoom,           {.f =  1} },
	{ CtrlShiftAlt,           XK_J,           zoom,           {.f = -1} },
	{ CtrlShiftAlt,           XK_N,           zoomreset,      {.f =  0} },
	{ CtrlShiftAlt,           XK_U,           externalpipe,   {.v = &pipeurl } },
	{ CtrlShift,              XK_O,           externalpipe,   {.v = &editor  } },
	{ CtrlShift,              XK_space,       ttysend,        {.s = "    "   } },
};

/*
 * Special keys (change & recompile st.info accordingly)
 *
 * Mask value:
 * * Use XK_ANY_MOD to match the key no matter modifiers state
 * * Use XK_NO_MOD to match the key alone (no modifiers)
 * appkey value:
 * * 0: no value
 * * > 0: keypad application mode enabled
 * *   = 2: term.numlock = 1
 * * < 0: keypad application mode disabled
 * appcursor value:
 * * 0: no value
 * * > 0: cursor application mode enabled
 * * < 0: cursor application mode disabled
 *
 * Be careful with the order of the definitions because st searches in
 * this table sequentially, so any XK_ANY_MOD must be in the last
 * position for a key.
 */

/*
 * If you want keys other than the X11 function keys (0xFD00 - 0xFFFF)
 * to be mapped below, add them to this array.
 */
static KeySym mappedkeys[] = {
	XK_m, XK_i, XK_A, XK_B, XK_C, XK_D, XK_E, XK_F, XK_G, XK_H,
	XK_I, XK_K, XK_J, XK_L, XK_M, XK_N, XK_O, XK_P, XK_Q, XK_R, XK_S, XK_T,
	XK_U, XK_V, XK_W, XK_X, XK_Y, XK_Z, XK_Z, XK_0, XK_1, XK_2, XK_3, XK_4,
	XK_5, XK_6, XK_7, XK_8, XK_9, XK_exclam, XK_quotedbl, XK_numbersign,
	XK_dollar, XK_percent, XK_ampersand, XK_apostrophe, XK_parenleft,
	XK_parenright, XK_asterisk, XK_plus, XK_comma, XK_minus, XK_period,
	XK_slash, XK_colon, XK_semicolon, XK_less, XK_equal, XK_greater,
	XK_question, XK_at, XK_bracketleft, XK_backslash, XK_bracketright,
	XK_asciicircum, XK_underscore, XK_grave, XK_braceleft, XK_bar,
	XK_braceright, XK_asciitilde,
#if SPACE_BINDINGS
	XK_space,
#endif
};

/*
 * State bits to ignore when matching key or button events.  By default,
 * numlock (Mod2Mask) and keyboard layout (XK_SWITCH_MOD) are ignored.
 */
static uint ignoremod = Mod2Mask|XK_SWITCH_MOD;

#define CSI_1b5b "\033["
#define CSI_9b   "\233"
/* wether to use 0x1b+0x9b (Esc+[) or 0x9b as the escape sequence for
 * key combos. more info: https://st.suckless.org/patches/fix_keyboard_input */
#define ESC CSI_9b

/*
 * This is the huge key array which defines all compatibility to the Linux
 * world. Please decide about changes wisely.
 */
static Key key[] = {
	/* keysym           mask            string      appkey appcursor */
	{ XK_KP_Home,       ShiftMask,      "\033[2J",       0,   -1},
	{ XK_KP_Home,       ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_KP_Prior,      ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_KP_End,        ControlMask,    "\033[J",       -1,    0},
	{ XK_KP_End,        ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[K",       -1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_KP_Next,       ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[4l",      -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[L",       -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[M",       -1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[2K",      -1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[3;2~",    +1,    0},
	{ XK_Up,            ShiftMask,      "\033[1;2A",     0,    0},
	{ XK_Up,            Mod1Mask,       "\033[1;3A",     0,    0},
	{ XK_Up,         ShiftMask|Mod1Mask,"\033[1;4A",     0,    0},
	{ XK_Up,            ControlMask,    "\033[1;5A",     0,    0},
	{ XK_Up,      ShiftMask|ControlMask,"\033[1;6A",     0,    0},
	{ XK_Up,       ControlMask|Mod1Mask,"\033[1;7A",     0,    0},
	{ XK_Up,ShiftMask|ControlMask|Mod1Mask,"\033[1;8A",  0,    0},
	{ XK_Up,            XK_ANY_MOD,     "\033[A",        0,   -1},
	{ XK_Up,            XK_ANY_MOD,     "\033OA",        0,   +1},
	{ XK_Down,          ShiftMask,      "\033[1;2B",     0,    0},
	{ XK_Down,          Mod1Mask,       "\033[1;3B",     0,    0},
	{ XK_Down,       ShiftMask|Mod1Mask,"\033[1;4B",     0,    0},
	{ XK_Down,          ControlMask,    "\033[1;5B",     0,    0},
	{ XK_Down,    ShiftMask|ControlMask,"\033[1;6B",     0,    0},
	{ XK_Down,     ControlMask|Mod1Mask,"\033[1;7B",     0,    0},
	{ XK_Down,ShiftMask|ControlMask|Mod1Mask,"\033[1;8B",0,    0},
	{ XK_Down,          XK_ANY_MOD,     "\033[B",        0,   -1},
	{ XK_Down,          XK_ANY_MOD,     "\033OB",        0,   +1},
	{ XK_Left,          ShiftMask,      "\033[1;2D",     0,    0},
	{ XK_Left,          Mod1Mask,       "\033[1;3D",     0,    0},
	{ XK_Left,       ShiftMask|Mod1Mask,"\033[1;4D",     0,    0},
	{ XK_Left,          ControlMask,    "\033[1;5D",     0,    0},
	{ XK_Left,    ShiftMask|ControlMask,"\033[1;6D",     0,    0},
	{ XK_Left,     ControlMask|Mod1Mask,"\033[1;7D",     0,    0},
	{ XK_Left,ShiftMask|ControlMask|Mod1Mask,"\033[1;8D",0,    0},
	{ XK_Left,          XK_ANY_MOD,     "\033[D",        0,   -1},
	{ XK_Left,          XK_ANY_MOD,     "\033OD",        0,   +1},
	{ XK_Right,         ShiftMask,      "\033[1;2C",     0,    0},
	{ XK_Right,         Mod1Mask,       "\033[1;3C",     0,    0},
	{ XK_Right,      ShiftMask|Mod1Mask,"\033[1;4C",     0,    0},
	{ XK_Right,         ControlMask,    "\033[1;5C",     0,    0},
	{ XK_Right,   ShiftMask|ControlMask,"\033[1;6C",     0,    0},
	{ XK_Right,    ControlMask|Mod1Mask,"\033[1;7C",     0,    0},
	{ XK_Right,ShiftMask|ControlMask|Mod1Mask,"\033[1;8C",0,   0},
	{ XK_Right,         XK_ANY_MOD,     "\033[C",        0,   -1},
	{ XK_Right,         XK_ANY_MOD,     "\033OC",        0,   +1},
	{ XK_ISO_Left_Tab,  ShiftMask,      "\033[Z",        0,    0},
	{ XK_Return,        Mod1Mask,       "\033\r",        0,    0},
	{ XK_Return,        XK_NO_MOD,      "\r",            0,    0},
	{ XK_Insert,        ShiftMask,      "\033[4l",      -1,    0},
	{ XK_Insert,        ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_Insert,        ControlMask,    "\033[L",       -1,    0},
	{ XK_Insert,        ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_Delete,        ControlMask,    "\033[M",       -1,    0},
	{ XK_Delete,        ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_Delete,        ShiftMask,      "\033[2K",      -1,    0},
	{ XK_Delete,        ShiftMask,      "\033[3;2~",    +1,    0},
	{ XK_BackSpace,     XK_NO_MOD,      "\177",          0,    0},
	{ XK_BackSpace,     Mod1Mask,       "\033\177",      0,    0},
	{ XK_Home,          ShiftMask,      "\033[2J",       0,   -1},
	{ XK_Home,          ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_End,           ControlMask,    "\033[J",       -1,    0},
	{ XK_End,           ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_End,           ShiftMask,      "\033[K",       -1,    0},
	{ XK_End,           ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_Prior,         ControlMask,    "\033[5;5~",     0,    0},
	{ XK_Prior,         ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_Next,          ControlMask,    "\033[6;5~",     0,    0},
	{ XK_Next,          ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_F1,            XK_NO_MOD,      "\033OP" ,       0,    0},
	{ XK_F1, /* F13 */  ShiftMask,      "\033[1;2P",     0,    0},
	{ XK_F1, /* F25 */  ControlMask,    "\033[1;5P",     0,    0},
	{ XK_F1, /* F37 */  Mod4Mask,       "\033[1;6P",     0,    0},
	{ XK_F1, /* F49 */  Mod1Mask,       "\033[1;3P",     0,    0},
	{ XK_F1, /* F61 */  Mod3Mask,       "\033[1;4P",     0,    0},
	{ XK_F2,            XK_NO_MOD,      "\033OQ" ,       0,    0},
	{ XK_F2, /* F14 */  ShiftMask,      "\033[1;2Q",     0,    0},
	{ XK_F2, /* F26 */  ControlMask,    "\033[1;5Q",     0,    0},
	{ XK_F2, /* F38 */  Mod4Mask,       "\033[1;6Q",     0,    0},
	{ XK_F2, /* F50 */  Mod1Mask,       "\033[1;3Q",     0,    0},
	{ XK_F2, /* F62 */  Mod3Mask,       "\033[1;4Q",     0,    0},
	{ XK_F3,            XK_NO_MOD,      "\033OR" ,       0,    0},
	{ XK_F3, /* F15 */  ShiftMask,      "\033[1;2R",     0,    0},
	{ XK_F3, /* F27 */  ControlMask,    "\033[1;5R",     0,    0},
	{ XK_F3, /* F39 */  Mod4Mask,       "\033[1;6R",     0,    0},
	{ XK_F3, /* F51 */  Mod1Mask,       "\033[1;3R",     0,    0},
	{ XK_F3, /* F63 */  Mod3Mask,       "\033[1;4R",     0,    0},
	{ XK_F4,            XK_NO_MOD,      "\033OS" ,       0,    0},
	{ XK_F4, /* F16 */  ShiftMask,      "\033[1;2S",     0,    0},
	{ XK_F4, /* F28 */  ControlMask,    "\033[1;5S",     0,    0},
	{ XK_F4, /* F40 */  Mod4Mask,       "\033[1;6S",     0,    0},
	{ XK_F4, /* F52 */  Mod1Mask,       "\033[1;3S",     0,    0},
	{ XK_F5,            XK_NO_MOD,      "\033[15~",      0,    0},
	{ XK_F5, /* F17 */  ShiftMask,      "\033[15;2~",    0,    0},
	{ XK_F5, /* F29 */  ControlMask,    "\033[15;5~",    0,    0},
	{ XK_F5, /* F41 */  Mod4Mask,       "\033[15;6~",    0,    0},
	{ XK_F5, /* F53 */  Mod1Mask,       "\033[15;3~",    0,    0},
	{ XK_F6,            XK_NO_MOD,      "\033[17~",      0,    0},
	{ XK_F6, /* F18 */  ShiftMask,      "\033[17;2~",    0,    0},
	{ XK_F6, /* F30 */  ControlMask,    "\033[17;5~",    0,    0},
	{ XK_F6, /* F42 */  Mod4Mask,       "\033[17;6~",    0,    0},
	{ XK_F6, /* F54 */  Mod1Mask,       "\033[17;3~",    0,    0},
	{ XK_F7,            XK_NO_MOD,      "\033[18~",      0,    0},
	{ XK_F7, /* F19 */  ShiftMask,      "\033[18;2~",    0,    0},
	{ XK_F7, /* F31 */  ControlMask,    "\033[18;5~",    0,    0},
	{ XK_F7, /* F43 */  Mod4Mask,       "\033[18;6~",    0,    0},
	{ XK_F7, /* F55 */  Mod1Mask,       "\033[18;3~",    0,    0},
	{ XK_F8,            XK_NO_MOD,      "\033[19~",      0,    0},
	{ XK_F8, /* F20 */  ShiftMask,      "\033[19;2~",    0,    0},
	{ XK_F8, /* F32 */  ControlMask,    "\033[19;5~",    0,    0},
	{ XK_F8, /* F44 */  Mod4Mask,       "\033[19;6~",    0,    0},
	{ XK_F8, /* F56 */  Mod1Mask,       "\033[19;3~",    0,    0},
	{ XK_F9,            XK_NO_MOD,      "\033[20~",      0,    0},
	{ XK_F9, /* F21 */  ShiftMask,      "\033[20;2~",    0,    0},
	{ XK_F9, /* F33 */  ControlMask,    "\033[20;5~",    0,    0},
	{ XK_F9, /* F45 */  Mod4Mask,       "\033[20;6~",    0,    0},
	{ XK_F9, /* F57 */  Mod1Mask,       "\033[20;3~",    0,    0},
	{ XK_F10,           XK_NO_MOD,      "\033[21~",      0,    0},
	{ XK_F10, /* F22 */ ShiftMask,      "\033[21;2~",    0,    0},
	{ XK_F10, /* F34 */ ControlMask,    "\033[21;5~",    0,    0},
	{ XK_F10, /* F46 */ Mod4Mask,       "\033[21;6~",    0,    0},
	{ XK_F10, /* F58 */ Mod1Mask,       "\033[21;3~",    0,    0},
	{ XK_F11,           XK_NO_MOD,      "\033[23~",      0,    0},
	{ XK_F11, /* F23 */ ShiftMask,      "\033[23;2~",    0,    0},
	{ XK_F11, /* F35 */ ControlMask,    "\033[23;5~",    0,    0},
	{ XK_F11, /* F47 */ Mod4Mask,       "\033[23;6~",    0,    0},
	{ XK_F11, /* F59 */ Mod1Mask,       "\033[23;3~",    0,    0},
	{ XK_F12,           XK_NO_MOD,      "\033[24~",      0,    0},
	{ XK_F12, /* F24 */ ShiftMask,      "\033[24;2~",    0,    0},
	{ XK_F12, /* F36 */ ControlMask,    "\033[24;5~",    0,    0},
	{ XK_F12, /* F48 */ Mod4Mask,       "\033[24;6~",    0,    0},
	{ XK_F12, /* F60 */ Mod1Mask,       "\033[24;3~",    0,    0},
	{ XK_F13,           XK_NO_MOD,      "\033[1;2P",     0,    0},
	{ XK_F14,           XK_NO_MOD,      "\033[1;2Q",     0,    0},
	{ XK_F15,           XK_NO_MOD,      "\033[1;2R",     0,    0},
	{ XK_F16,           XK_NO_MOD,      "\033[1;2S",     0,    0},
	{ XK_F17,           XK_NO_MOD,      "\033[15;2~",    0,    0},
	{ XK_F18,           XK_NO_MOD,      "\033[17;2~",    0,    0},
	{ XK_F19,           XK_NO_MOD,      "\033[18;2~",    0,    0},
	{ XK_F20,           XK_NO_MOD,      "\033[19;2~",    0,    0},
	{ XK_F21,           XK_NO_MOD,      "\033[20;2~",    0,    0},
	{ XK_F22,           XK_NO_MOD,      "\033[21;2~",    0,    0},
	{ XK_F23,           XK_NO_MOD,      "\033[23;2~",    0,    0},
	{ XK_F24,           XK_NO_MOD,      "\033[24;2~",    0,    0},
	{ XK_F25,           XK_NO_MOD,      "\033[1;5P",     0,    0},
	{ XK_F26,           XK_NO_MOD,      "\033[1;5Q",     0,    0},
	{ XK_F27,           XK_NO_MOD,      "\033[1;5R",     0,    0},
	{ XK_F28,           XK_NO_MOD,      "\033[1;5S",     0,    0},
	{ XK_F29,           XK_NO_MOD,      "\033[15;5~",    0,    0},
	{ XK_F30,           XK_NO_MOD,      "\033[17;5~",    0,    0},
	{ XK_F31,           XK_NO_MOD,      "\033[18;5~",    0,    0},
	{ XK_F32,           XK_NO_MOD,      "\033[19;5~",    0,    0},
	{ XK_F33,           XK_NO_MOD,      "\033[20;5~",    0,    0},
	{ XK_F34,           XK_NO_MOD,      "\033[21;5~",    0,    0},
	{ XK_F35,           XK_NO_MOD,      "\033[23;5~",    0,    0},

	/* libtermkey compatible keyboard input */
	{ XK_KP_Home,      XK_NO_MOD,                      "\033[H",      0, -1},
	{ XK_KP_Home,      XK_NO_MOD,                      "\033[1~",     0, +1},
	{ XK_KP_Home,      ControlMask,                    ESC"149;5u",   0,  0},
	{ XK_KP_Home,      ControlMask|ShiftMask,          ESC"149;6u",   0,  0},
	{ XK_KP_Home,      Mod1Mask,                       ESC"149;3u",   0,  0},
	{ XK_KP_Home,      Mod1Mask|ControlMask,           ESC"149;7u",   0,  0},
	{ XK_KP_Home,      Mod1Mask|ControlMask|ShiftMask, ESC"149;8u",   0,  0},
	{ XK_KP_Home,      Mod1Mask|ShiftMask,             ESC"149;4u",   0,  0},
	{ XK_KP_Home,      ShiftMask,                      ESC"149;2u",   0,  0},
	{ XK_KP_Up,        XK_NO_MOD,                      "\033Ox",     +1,  0},
	{ XK_KP_Up,        XK_NO_MOD,                      "\033[A",      0, -1},
	{ XK_KP_Up,        XK_NO_MOD,                      "\033OA",      0, +1},
	{ XK_KP_Up,        ControlMask,                    ESC"151;5u",   0,  0},
	{ XK_KP_Up,        ControlMask|ShiftMask,          ESC"151;6u",   0,  0},
	{ XK_KP_Up,        Mod1Mask,                       ESC"151;3u",   0,  0},
	{ XK_KP_Up,        Mod1Mask|ControlMask,           ESC"151;7u",   0,  0},
	{ XK_KP_Up,        Mod1Mask|ControlMask|ShiftMask, ESC"151;8u",   0,  0},
	{ XK_KP_Up,        Mod1Mask|ShiftMask,             ESC"151;4u",   0,  0},
	{ XK_KP_Up,        ShiftMask,                      ESC"151;2u",   0,  0},
	{ XK_KP_Down,      XK_NO_MOD,                      "\033Or",     +1,  0},
	{ XK_KP_Down,      XK_NO_MOD,                      "\033[B",      0, -1},
	{ XK_KP_Down,      XK_NO_MOD,                      "\033OB",      0, +1},
	{ XK_KP_Down,      ControlMask,                    ESC"153;5u",   0,  0},
	{ XK_KP_Down,      ControlMask|ShiftMask,          ESC"153;6u",   0,  0},
	{ XK_KP_Down,      Mod1Mask,                       ESC"153;3u",   0,  0},
	{ XK_KP_Down,      Mod1Mask|ControlMask,           ESC"153;7u",   0,  0},
	{ XK_KP_Down,      Mod1Mask|ControlMask|ShiftMask, ESC"153;8u",   0,  0},
	{ XK_KP_Down,      Mod1Mask|ShiftMask,             ESC"153;4u",   0,  0},
	{ XK_KP_Down,      ShiftMask,                      ESC"153;2u",   0,  0},
	{ XK_KP_Left,      XK_NO_MOD,                      "\033Ot",     +1,  0},
	{ XK_KP_Left,      XK_NO_MOD,                      "\033[D",      0, -1},
	{ XK_KP_Left,      XK_NO_MOD,                      "\033OD",      0, +1},
	{ XK_KP_Left,      ControlMask,                    ESC"150;5u",   0,  0},
	{ XK_KP_Left,      ControlMask|ShiftMask,          ESC"150;6u",   0,  0},
	{ XK_KP_Left,      Mod1Mask,                       ESC"150;3u",   0,  0},
	{ XK_KP_Left,      Mod1Mask|ControlMask,           ESC"150;7u",   0,  0},
	{ XK_KP_Left,      Mod1Mask|ControlMask|ShiftMask, ESC"150;8u",   0,  0},
	{ XK_KP_Left,      Mod1Mask|ShiftMask,             ESC"150;4u",   0,  0},
	{ XK_KP_Left,      ShiftMask,                      ESC"150;2u",   0,  0},
	{ XK_KP_Right,     XK_NO_MOD,                      "\033Ov",     +1,  0},
	{ XK_KP_Right,     XK_NO_MOD,                      "\033[C",      0, -1},
	{ XK_KP_Right,     XK_NO_MOD,                      "\033OC",      0, +1},
	{ XK_KP_Right,     ControlMask,                    ESC"152;5u",   0,  0},
	{ XK_KP_Right,     ControlMask|ShiftMask,          ESC"152;6u",   0,  0},
	{ XK_KP_Right,     Mod1Mask,                       ESC"152;3u",   0,  0},
	{ XK_KP_Right,     Mod1Mask|ControlMask,           ESC"152;7u",   0,  0},
	{ XK_KP_Right,     Mod1Mask|ControlMask|ShiftMask, ESC"152;8u",   0,  0},
	{ XK_KP_Right,     Mod1Mask|ShiftMask,             ESC"152;4u",   0,  0},
	{ XK_KP_Right,     ShiftMask,                      ESC"152;2u",   0,  0},
	{ XK_KP_Prior,     XK_NO_MOD,                      "\033[5~",     0,  0},
	{ XK_KP_Prior,     ControlMask,                    ESC"154;5u",   0,  0},
	{ XK_KP_Prior,     ControlMask|ShiftMask,          ESC"154;6u",   0,  0},
	{ XK_KP_Prior,     Mod1Mask,                       ESC"154;3u",   0,  0},
	{ XK_KP_Prior,     Mod1Mask|ControlMask,           ESC"154;7u",   0,  0},
	{ XK_KP_Prior,     Mod1Mask|ControlMask|ShiftMask, ESC"154;8u",   0,  0},
	{ XK_KP_Prior,     Mod1Mask|ShiftMask,             ESC"154;4u",   0,  0},
	{ XK_KP_Begin,     XK_NO_MOD,                      "\033[E",      0,  0},
	{ XK_KP_Begin,     ControlMask,                    ESC"157;5u",   0,  0},
	{ XK_KP_Begin,     ControlMask|ShiftMask,          ESC"157;6u",   0,  0},
	{ XK_KP_Begin,     Mod1Mask,                       ESC"157;3u",   0,  0},
	{ XK_KP_Begin,     Mod1Mask|ControlMask,           ESC"157;7u",   0,  0},
	{ XK_KP_Begin,     Mod1Mask|ControlMask|ShiftMask, ESC"157;8u",   0,  0},
	{ XK_KP_Begin,     Mod1Mask|ShiftMask,             ESC"157;4u",   0,  0},
	{ XK_KP_Begin,     ShiftMask,                      ESC"157;2u",   0,  0},
	{ XK_KP_End,       XK_NO_MOD,                      "\033[4~",     0,  0},
	{ XK_KP_End,       ControlMask|ShiftMask,          ESC"156;6u",   0,  0},
	{ XK_KP_End,       Mod1Mask,                       ESC"156;3u",   0,  0},
	{ XK_KP_End,       Mod1Mask|ControlMask,           ESC"156;7u",   0,  0},
	{ XK_KP_End,       Mod1Mask|ControlMask|ShiftMask, ESC"156;8u",   0,  0},
	{ XK_KP_End,       Mod1Mask|ShiftMask,             ESC"156;4u",   0,  0},
	{ XK_KP_Next,      XK_NO_MOD,                      "\033[6~",     0,  0},
	{ XK_KP_Next,      ControlMask,                    ESC"155;5u",   0,  0},
	{ XK_KP_Next,      ControlMask|ShiftMask,          ESC"155;6u",   0,  0},
	{ XK_KP_Next,      Mod1Mask,                       ESC"155;3u",   0,  0},
	{ XK_KP_Next,      Mod1Mask|ControlMask,           ESC"155;7u",   0,  0},
	{ XK_KP_Next,      Mod1Mask|ControlMask|ShiftMask, ESC"155;8u",   0,  0},
	{ XK_KP_Next,      Mod1Mask|ShiftMask,             ESC"155;4u",   0,  0},
	{ XK_KP_Insert,    XK_NO_MOD,                      "\033[4h",    -1,  0},
	{ XK_KP_Insert,    XK_NO_MOD,                      "\033[2~",    +1,  0},
	{ XK_KP_Insert,    ControlMask|ShiftMask,          ESC"158;6u",   0,  0},
	{ XK_KP_Insert,    Mod1Mask,                       ESC"158;3u",   0,  0},
	{ XK_KP_Insert,    Mod1Mask|ControlMask,           ESC"158;7u",   0,  0},
	{ XK_KP_Insert,    Mod1Mask|ControlMask|ShiftMask, ESC"158;8u",   0,  0},
	{ XK_KP_Insert,    Mod1Mask|ShiftMask,             ESC"158;4u",   0,  0},
	{ XK_KP_Delete,    XK_NO_MOD,                      "\033[P",     -1,  0},
	{ XK_KP_Delete,    XK_NO_MOD,                      "\033[3~",    +1,  0},
	{ XK_KP_Delete,    ControlMask|ShiftMask,          ESC"159;6u",   0,  0},
	{ XK_KP_Delete,    Mod1Mask,                       ESC"159;3u",   0,  0},
	{ XK_KP_Delete,    Mod1Mask|ControlMask,           ESC"159;7u",   0,  0},
	{ XK_KP_Delete,    Mod1Mask|ControlMask|ShiftMask, ESC"159;8u",   0,  0},
	{ XK_KP_Delete,    Mod1Mask|ShiftMask,             ESC"159;4u",   0,  0},
	{ XK_KP_Multiply,  XK_NO_MOD,                      "\033Oj",     +2,  0},
	{ XK_KP_Multiply,  ControlMask,                    ESC"170;5u",   0,  0},
	{ XK_KP_Multiply,  ControlMask|ShiftMask,          ESC"170;6u",   0,  0},
	{ XK_KP_Multiply,  Mod1Mask,                       ESC"170;3u",   0,  0},
	{ XK_KP_Multiply,  Mod1Mask|ControlMask,           ESC"170;7u",   0,  0},
	{ XK_KP_Multiply,  Mod1Mask|ControlMask|ShiftMask, ESC"170;8u",   0,  0},
	{ XK_KP_Multiply,  Mod1Mask|ShiftMask,             ESC"170;4u",   0,  0},
	{ XK_KP_Multiply,  ShiftMask,                      ESC"170;2u",   0,  0},
	{ XK_KP_Add,       XK_NO_MOD,                      "\033Ok",     +2,  0},
	{ XK_KP_Add,       ControlMask,                    ESC"171;5u",   0,  0},
	{ XK_KP_Add,       ControlMask|ShiftMask,          ESC"171;6u",   0,  0},
	{ XK_KP_Add,       Mod1Mask,                       ESC"171;3u",   0,  0},
	{ XK_KP_Add,       Mod1Mask|ControlMask,           ESC"171;7u",   0,  0},
	{ XK_KP_Add,       Mod1Mask|ControlMask|ShiftMask, ESC"171;8u",   0,  0},
	{ XK_KP_Add,       Mod1Mask|ShiftMask,             ESC"171;4u",   0,  0},
	{ XK_KP_Add,       ShiftMask,                      ESC"171;2u",   0,  0},
	{ XK_KP_Enter,     XK_NO_MOD,                      "\033OM",     +2,  0},
	{ XK_KP_Enter,     XK_NO_MOD,                      "\r",         -1,  0},
	{ XK_KP_Enter,     XK_NO_MOD,                      "\r\n",       -1,  0},
	{ XK_KP_Enter,     ControlMask,                    ESC"141;5u",   0,  0},
	{ XK_KP_Enter,     ControlMask|ShiftMask,          ESC"141;6u",   0,  0},
	{ XK_KP_Enter,     Mod1Mask,                       ESC"141;3u",   0,  0},
	{ XK_KP_Enter,     Mod1Mask|ControlMask,           ESC"141;7u",   0,  0},
	{ XK_KP_Enter,     Mod1Mask|ControlMask|ShiftMask, ESC"141;8u",   0,  0},
	{ XK_KP_Enter,     Mod1Mask|ShiftMask,             ESC"141;4u",   0,  0},
	{ XK_KP_Enter,     ShiftMask,                      ESC"141;2u",   0,  0},
	{ XK_KP_Subtract,  XK_NO_MOD,                      "\033Om",     +2,  0},
	{ XK_KP_Subtract,  ControlMask,                    ESC"173;5u",   0,  0},
	{ XK_KP_Subtract,  ControlMask|ShiftMask,          ESC"173;6u",   0,  0},
	{ XK_KP_Subtract,  Mod1Mask,                       ESC"173;3u",   0,  0},
	{ XK_KP_Subtract,  Mod1Mask|ControlMask,           ESC"173;7u",   0,  0},
	{ XK_KP_Subtract,  Mod1Mask|ControlMask|ShiftMask, ESC"173;8u",   0,  0},
	{ XK_KP_Subtract,  Mod1Mask|ShiftMask,             ESC"173;4u",   0,  0},
	{ XK_KP_Subtract,  ShiftMask,                      ESC"173;2u",   0,  0},
	{ XK_KP_Decimal,   XK_NO_MOD,                      "\033On",     +2,  0},
	{ XK_KP_Decimal,   ControlMask,                    ESC"174;5u",   0,  0},
	{ XK_KP_Decimal,   ControlMask|ShiftMask,          ESC"174;6u",   0,  0},
	{ XK_KP_Decimal,   Mod1Mask,                       ESC"174;3u",   0,  0},
	{ XK_KP_Decimal,   Mod1Mask|ControlMask,           ESC"174;7u",   0,  0},
	{ XK_KP_Decimal,   Mod1Mask|ControlMask|ShiftMask, ESC"174;8u",   0,  0},
	{ XK_KP_Decimal,   Mod1Mask|ShiftMask,             ESC"174;4u",   0,  0},
	{ XK_KP_Decimal,   ShiftMask,                      ESC"174;2u",   0,  0},
	{ XK_KP_Divide,    XK_NO_MOD,                      "\033Oo",     +2,  0},
	{ XK_KP_Divide,    ControlMask,                    ESC"175;5u",   0,  0},
	{ XK_KP_Divide,    ControlMask|ShiftMask,          ESC"175;6u",   0,  0},
	{ XK_KP_Divide,    Mod1Mask,                       ESC"175;3u",   0,  0},
	{ XK_KP_Divide,    Mod1Mask|ControlMask,           ESC"175;7u",   0,  0},
	{ XK_KP_Divide,    Mod1Mask|ControlMask|ShiftMask, ESC"175;8u",   0,  0},
	{ XK_KP_Divide,    Mod1Mask|ShiftMask,             ESC"175;4u",   0,  0},
	{ XK_KP_Divide,    ShiftMask,                      ESC"175;2u",   0,  0},
	{ XK_KP_0,         XK_NO_MOD,                      "\033Op",     +2,  0},
	{ XK_KP_0,         ControlMask,                    ESC"176;5u",   0,  0},
	{ XK_KP_0,         ControlMask|ShiftMask,          ESC"176;6u",   0,  0},
	{ XK_KP_0,         Mod1Mask,                       ESC"176;3u",   0,  0},
	{ XK_KP_0,         Mod1Mask|ControlMask,           ESC"176;7u",   0,  0},
	{ XK_KP_0,         Mod1Mask|ControlMask|ShiftMask, ESC"176;8u",   0,  0},
	{ XK_KP_0,         Mod1Mask|ShiftMask,             ESC"176;4u",   0,  0},
	{ XK_KP_0,         ShiftMask,                      ESC"176;2u",   0,  0},
	{ XK_KP_1,         XK_NO_MOD,                      "\033Oq",     +2,  0},
	{ XK_KP_0,         ControlMask,                    ESC"177;5u",   0,  0},
	{ XK_KP_0,         ControlMask|ShiftMask,          ESC"177;6u",   0,  0},
	{ XK_KP_0,         Mod1Mask,                       ESC"177;3u",   0,  0},
	{ XK_KP_0,         Mod1Mask|ControlMask,           ESC"177;7u",   0,  0},
	{ XK_KP_0,         Mod1Mask|ControlMask|ShiftMask, ESC"177;8u",   0,  0},
	{ XK_KP_0,         Mod1Mask|ShiftMask,             ESC"177;4u",   0,  0},
	{ XK_KP_0,         ShiftMask,                      ESC"177;2u",   0,  0},
	{ XK_KP_2,         XK_NO_MOD,                      "\033Or",     +2,  0},
	{ XK_KP_2,         ControlMask,                    ESC"178;5u",   0,  0},
	{ XK_KP_2,         ControlMask|ShiftMask,          ESC"178;6u",   0,  0},
	{ XK_KP_2,         Mod1Mask,                       ESC"178;3u",   0,  0},
	{ XK_KP_2,         Mod1Mask|ControlMask,           ESC"178;7u",   0,  0},
	{ XK_KP_2,         Mod1Mask|ControlMask|ShiftMask, ESC"178;8u",   0,  0},
	{ XK_KP_2,         Mod1Mask|ShiftMask,             ESC"178;4u",   0,  0},
	{ XK_KP_2,         ShiftMask,                      ESC"178;2u",   0,  0},
	{ XK_KP_3,         XK_NO_MOD,                      "\033Os",     +2,  0},
	{ XK_KP_3,         ControlMask,                    ESC"179;5u",   0,  0},
	{ XK_KP_3,         ControlMask|ShiftMask,          ESC"179;6u",   0,  0},
	{ XK_KP_3,         Mod1Mask,                       ESC"179;3u",   0,  0},
	{ XK_KP_3,         Mod1Mask|ControlMask,           ESC"179;7u",   0,  0},
	{ XK_KP_3,         Mod1Mask|ControlMask|ShiftMask, ESC"179;8u",   0,  0},
	{ XK_KP_3,         Mod1Mask|ShiftMask,             ESC"179;4u",   0,  0},
	{ XK_KP_3,         ShiftMask,                      ESC"179;2u",   0,  0},
	{ XK_KP_4,         XK_NO_MOD,                      "\033Ot",     +2,  0},
	{ XK_KP_4,         ControlMask,                    ESC"180;5u",   0,  0},
	{ XK_KP_4,         ControlMask|ShiftMask,          ESC"180;6u",   0,  0},
	{ XK_KP_4,         Mod1Mask,                       ESC"180;3u",   0,  0},
	{ XK_KP_4,         Mod1Mask|ControlMask,           ESC"180;7u",   0,  0},
	{ XK_KP_4,         Mod1Mask|ControlMask|ShiftMask, ESC"180;8u",   0,  0},
	{ XK_KP_4,         Mod1Mask|ShiftMask,             ESC"180;4u",   0,  0},
	{ XK_KP_4,         ShiftMask,                      ESC"180;2u",   0,  0},
	{ XK_KP_5,         XK_NO_MOD,                      "\033Ou",     +2,  0},
	{ XK_KP_5,         ControlMask,                    ESC"181;5u",   0,  0},
	{ XK_KP_5,         ControlMask|ShiftMask,          ESC"181;6u",   0,  0},
	{ XK_KP_5,         Mod1Mask,                       ESC"181;3u",   0,  0},
	{ XK_KP_5,         Mod1Mask|ControlMask,           ESC"181;7u",   0,  0},
	{ XK_KP_5,         Mod1Mask|ControlMask|ShiftMask, ESC"181;8u",   0,  0},
	{ XK_KP_5,         Mod1Mask|ShiftMask,             ESC"181;4u",   0,  0},
	{ XK_KP_5,         ShiftMask,                      ESC"181;2u",   0,  0},
	{ XK_KP_6,         XK_NO_MOD,                      "\033Ov",     +2,  0},
	{ XK_KP_6,         ControlMask,                    ESC"182;5u",   0,  0},
	{ XK_KP_6,         ControlMask|ShiftMask,          ESC"182;6u",   0,  0},
	{ XK_KP_6,         Mod1Mask,                       ESC"182;3u",   0,  0},
	{ XK_KP_6,         Mod1Mask|ControlMask,           ESC"182;7u",   0,  0},
	{ XK_KP_6,         Mod1Mask|ControlMask|ShiftMask, ESC"182;8u",   0,  0},
	{ XK_KP_6,         Mod1Mask|ShiftMask,             ESC"182;4u",   0,  0},
	{ XK_KP_6,         ShiftMask,                      ESC"182;2u",   0,  0},
	{ XK_KP_7,         XK_NO_MOD,                      "\033Ow",     +2,  0},
	{ XK_KP_7,         ControlMask,                    ESC"183;5u",   0,  0},
	{ XK_KP_7,         ControlMask|ShiftMask,          ESC"183;6u",   0,  0},
	{ XK_KP_7,         Mod1Mask,                       ESC"183;3u",   0,  0},
	{ XK_KP_7,         Mod1Mask|ControlMask,           ESC"183;7u",   0,  0},
	{ XK_KP_7,         Mod1Mask|ControlMask|ShiftMask, ESC"183;8u",   0,  0},
	{ XK_KP_7,         Mod1Mask|ShiftMask,             ESC"183;4u",   0,  0},
	{ XK_KP_7,         ShiftMask,                      ESC"183;2u",   0,  0},
	{ XK_KP_8,         XK_NO_MOD,                      "\033Ox",     +2,  0},
	{ XK_KP_8,         ControlMask,                    ESC"184;5u",   0,  0},
	{ XK_KP_8,         ControlMask|ShiftMask,          ESC"184;6u",   0,  0},
	{ XK_KP_8,         Mod1Mask,                       ESC"184;3u",   0,  0},
	{ XK_KP_8,         Mod1Mask|ControlMask,           ESC"184;7u",   0,  0},
	{ XK_KP_8,         Mod1Mask|ControlMask|ShiftMask, ESC"184;8u",   0,  0},
	{ XK_KP_8,         Mod1Mask|ShiftMask,             ESC"184;4u",   0,  0},
	{ XK_KP_8,         ShiftMask,                      ESC"184;2u",   0,  0},
	{ XK_KP_9,         XK_NO_MOD,                      "\033Oy",     +2,  0},
	{ XK_KP_9,         ControlMask,                    ESC"185;5u",   0,  0},
	{ XK_KP_9,         ControlMask|ShiftMask,          ESC"185;6u",   0,  0},
	{ XK_KP_9,         Mod1Mask,                       ESC"185;3u",   0,  0},
	{ XK_KP_9,         Mod1Mask|ControlMask,           ESC"185;7u",   0,  0},
	{ XK_KP_9,         Mod1Mask|ControlMask|ShiftMask, ESC"185;8u",   0,  0},
	{ XK_KP_9,         Mod1Mask|ShiftMask,             ESC"185;4u",   0,  0},
	{ XK_KP_9,         ShiftMask,                      ESC"185;2u",   0,  0},
	{ XK_Tab,          ControlMask,                    ESC"9;5u",     0,  0},
	{ XK_Tab,          ControlMask|ShiftMask,          "\033[1;5Z",   0,  0},
	{ XK_Tab,          Mod1Mask,                       "\033[1;3Z",   0,  0},
	{ XK_Tab,          Mod1Mask|ControlMask,           "\033[1;7Z",   0,  0},
	{ XK_Tab,          Mod1Mask|ControlMask|ShiftMask, "\033[1;8Z",   0,  0},
	{ XK_Tab,          Mod1Mask|ShiftMask,             "\033[1;4Z",   0,  0},
	{ XK_Return,       ControlMask,                    ESC"13;5u",    0,  0},
	{ XK_Return,       ControlMask|ShiftMask,          ESC"13;6u",    0,  0},
	{ XK_Return,       Mod1Mask,                       ESC"13;3u",    0,  0},
	{ XK_Return,       Mod1Mask|ControlMask,           ESC"13;7u",    0,  0},
	{ XK_Return,       Mod1Mask|ControlMask|ShiftMask, ESC"13;8u",    0,  0},
	{ XK_Return,       Mod1Mask|ShiftMask,             ESC"13;4u",    0,  0},
	{ XK_Return,       ShiftMask,                      ESC"13;2u",    0,  0},
	{ XK_Pause,        ControlMask,                    ESC"18;5u",    0,  0},
	{ XK_Pause,        ControlMask|ShiftMask,          ESC"18;6u",    0,  0},
	{ XK_Pause,        Mod1Mask,                       ESC"18;3u",    0,  0},
	{ XK_Pause,        Mod1Mask|ControlMask,           ESC"18;7u",    0,  0},
	{ XK_Pause,        Mod1Mask|ControlMask|ShiftMask, ESC"18;8u",    0,  0},
	{ XK_Pause,        Mod1Mask|ShiftMask,             ESC"18;4u",    0,  0},
	{ XK_Pause,        ShiftMask,                      ESC"18;2u",    0,  0},
	{ XK_Scroll_Lock,  ControlMask,                    ESC"20;5u",    0,  0},
	{ XK_Scroll_Lock,  ControlMask|ShiftMask,          ESC"20;6u",    0,  0},
	{ XK_Scroll_Lock,  Mod1Mask,                       ESC"20;3u",    0,  0},
	{ XK_Scroll_Lock,  Mod1Mask|ControlMask,           ESC"20;7u",    0,  0},
	{ XK_Scroll_Lock,  Mod1Mask|ControlMask|ShiftMask, ESC"20;8u",    0,  0},
	{ XK_Scroll_Lock,  Mod1Mask|ShiftMask,             ESC"20;4u",    0,  0},
	{ XK_Scroll_Lock,  ShiftMask,                      ESC"20;2u",    0,  0},
	{ XK_Escape,       ControlMask,                    ESC"27;5u",    0,  0},
	{ XK_Escape,       ControlMask|ShiftMask,          ESC"27;6u",    0,  0},
	{ XK_Escape,       Mod1Mask,                       ESC"27;3u",    0,  0},
	{ XK_Escape,       Mod1Mask|ControlMask,           ESC"27;7u",    0,  0},
	{ XK_Escape,       Mod1Mask|ControlMask|ShiftMask, ESC"27;8u",    0,  0},
	{ XK_Escape,       Mod1Mask|ShiftMask,             ESC"27;4u",    0,  0},
	{ XK_Escape,       ShiftMask,                      ESC"27;2u",    0,  0},
	{ XK_Home,         XK_NO_MOD,                      "\033[H",      0, -1},
	{ XK_Home,         XK_NO_MOD,                      "\033[1~",     0, +1},
	{ XK_Home,         ControlMask|ShiftMask,          ESC"80;6u",    0,  0},
	{ XK_Home,         Mod1Mask,                       ESC"80;3u",    0,  0},
	{ XK_Home,         Mod1Mask|ControlMask,           ESC"80;7u",    0,  0},
	{ XK_Home,         Mod1Mask|ControlMask|ShiftMask, ESC"80;8u",    0,  0},
	{ XK_Home,         Mod1Mask|ShiftMask,             ESC"80;4u",    0,  0},
	{ XK_End,          XK_NO_MOD,                      "\033[4~",     0,  0},
	{ XK_End,          ControlMask|ShiftMask,          ESC"87;6u",    0,  0},
	{ XK_End,          Mod1Mask,                       ESC"87;3u",    0,  0},
	{ XK_End,          Mod1Mask|ControlMask,           ESC"87;7u",    0,  0},
	{ XK_End,          Mod1Mask|ControlMask|ShiftMask, ESC"87;8u",    0,  0},
	{ XK_End,          Mod1Mask|ShiftMask,             ESC"87;4u",    0,  0},
	{ XK_Prior,        XK_NO_MOD,                      "\033[5~",     0,  0},
	{ XK_Prior,        ControlMask|ShiftMask,          ESC"85;6u",    0,  0},
	{ XK_Prior,        Mod1Mask,                       ESC"85;3u",    0,  0},
	{ XK_Prior,        Mod1Mask|ControlMask,           ESC"85;7u",    0,  0},
	{ XK_Prior,        Mod1Mask|ControlMask|ShiftMask, ESC"85;8u",    0,  0},
	{ XK_Prior,        Mod1Mask|ShiftMask,             ESC"85;4u",    0,  0},
	{ XK_Next,         XK_NO_MOD,                      "\033[6~",     0,  0},
	{ XK_Next,         ControlMask|ShiftMask,          ESC"86;6u",    0,  0},
	{ XK_Next,         Mod1Mask,                       ESC"86;3u",    0,  0},
	{ XK_Next,         Mod1Mask|ControlMask,           ESC"86;7u",    0,  0},
	{ XK_Next,         Mod1Mask|ControlMask|ShiftMask, ESC"86;8u",    0,  0},
	{ XK_Next,         Mod1Mask|ShiftMask,             ESC"86;4u",    0,  0},
	{ XK_Print,        ControlMask,                    ESC"97;5u",    0,  0},
	{ XK_Print,        ControlMask|ShiftMask,          ESC"97;6u",    0,  0},
	{ XK_Print,        Mod1Mask,                       ESC"97;3u",    0,  0},
	{ XK_Print,        Mod1Mask|ControlMask,           ESC"97;7u",    0,  0},
	{ XK_Print,        Mod1Mask|ControlMask|ShiftMask, ESC"97;8u",    0,  0},
	{ XK_Print,        Mod1Mask|ShiftMask,             ESC"97;4u",    0,  0},
	{ XK_Print,        ShiftMask,                      ESC"97;2u",    0,  0},
	{ XK_Insert,       XK_NO_MOD,                      "\033[4h",    -1,  0},
	{ XK_Insert,       XK_NO_MOD,                      "\033[2~",    +1,  0},
	{ XK_Insert,       ControlMask|ShiftMask,          ESC"99;6u",    0,  0},
	{ XK_Insert,       Mod1Mask,                       ESC"99;3u",    0,  0},
	{ XK_Insert,       Mod1Mask|ControlMask,           ESC"99;7u",    0,  0},
	{ XK_Insert,       Mod1Mask|ControlMask|ShiftMask, ESC"99;8u",    0,  0},
	{ XK_Insert,       Mod1Mask|ShiftMask,             ESC"99;4u",    0,  0},
	{ XK_Menu,         ControlMask,                    ESC"103;5u",   0,  0},
	{ XK_Menu,         ControlMask|ShiftMask,          ESC"103;6u",   0,  0},
	{ XK_Menu,         Mod1Mask,                       ESC"103;3u",   0,  0},
	{ XK_Menu,         Mod1Mask|ControlMask,           ESC"103;7u",   0,  0},
	{ XK_Menu,         Mod1Mask|ControlMask|ShiftMask, ESC"103;8u",   0,  0},
	{ XK_Menu,         Mod1Mask|ShiftMask,             ESC"103;4u",   0,  0},
	{ XK_Menu,         ShiftMask,                      ESC"103;2u",   0,  0},
	{ XK_Delete,       XK_NO_MOD,                      "\033[P",     -1,  0},
	{ XK_Delete,       XK_NO_MOD,                      "\033[3~",    +1,  0},
	{ XK_Delete,       ControlMask|ShiftMask,          ESC"255;6u",   0,  0},
	{ XK_Delete,       Mod1Mask,                       ESC"255;3u",   0,  0},
	{ XK_Delete,       Mod1Mask|ControlMask,           ESC"255;7u",   0,  0},
	{ XK_Delete,       Mod1Mask|ControlMask|ShiftMask, ESC"255;8u",   0,  0},
	{ XK_Delete,       Mod1Mask|ShiftMask,             ESC"255;4u",   0,  0},
	{ XK_i,            Mod1Mask|ControlMask,           ESC"105;7u",   0,  0},
	{ XK_m,            Mod1Mask|ControlMask,           ESC"109;7u",   0,  0},
	{ XK_0,            ControlMask,                    ESC"48;5u",    0,  0},
	{ XK_A,            ControlMask|ShiftMask,          ESC"65;6u",    0,  0},
	{ XK_B,            ControlMask|ShiftMask,          ESC"66;6u",    0,  0},
	{ XK_C,            ControlMask|ShiftMask,          ESC"67;6u",    0,  0},
	{ XK_D,            ControlMask|ShiftMask,          ESC"68;6u",    0,  0},
	{ XK_E,            ControlMask|ShiftMask,          ESC"69;6u",    0,  0},
	{ XK_F,            ControlMask|ShiftMask,          ESC"70;6u",    0,  0},
	{ XK_G,            ControlMask|ShiftMask,          ESC"71;6u",    0,  0},
	{ XK_H,            ControlMask|ShiftMask,          ESC"72;6u",    0,  0},
	{ XK_I,            ControlMask|ShiftMask,          ESC"73;6u",    0,  0},
	{ XK_I,            Mod1Mask|ControlMask|ShiftMask, ESC"73;8u",    0,  0},
	{ XK_J,            ControlMask|ShiftMask,          ESC"75;6u",    0,  0},
	{ XK_K,            ControlMask|ShiftMask,          ESC"74;6u",    0,  0},
	{ XK_L,            ControlMask|ShiftMask,          ESC"76;6u",    0,  0},
	{ XK_M,            ControlMask|ShiftMask,          ESC"77;6u",    0,  0},
	{ XK_M,            Mod1Mask|ControlMask|ShiftMask, ESC"77;8u",    0,  0},
	{ XK_N,            ControlMask|ShiftMask,          ESC"78;6u",    0,  0},
	{ XK_O,            ControlMask|ShiftMask,          ESC"79;6u",    0,  0},
	{ XK_P,            ControlMask|ShiftMask,          ESC"80;6u",    0,  0},
	{ XK_Q,            ControlMask|ShiftMask,          ESC"81;6u",    0,  0},
	{ XK_R,            ControlMask|ShiftMask,          ESC"82;6u",    0,  0},
	{ XK_S,            ControlMask|ShiftMask,          ESC"83;6u",    0,  0},
	{ XK_T,            ControlMask|ShiftMask,          ESC"84;6u",    0,  0},
	{ XK_U,            ControlMask|ShiftMask,          ESC"85;6u",    0,  0},
	{ XK_V,            ControlMask|ShiftMask,          ESC"86;6u",    0,  0},
	{ XK_W,            ControlMask|ShiftMask,          ESC"87;6u",    0,  0},
	{ XK_X,            ControlMask|ShiftMask,          ESC"88;6u",    0,  0},
	{ XK_Y,            ControlMask|ShiftMask,          ESC"89;6u",    0,  0},
	{ XK_Z,            ControlMask|ShiftMask,          ESC"90;6u",    0,  0},
	{ XK_Z,            ControlMask|ShiftMask,          ESC"90;6u",    0,  0},
	{ XK_0,            Mod1Mask|ControlMask,           ESC"48;7u",    0,  0},
	{ XK_1,            ControlMask,                    ESC"49;5u",    0,  0},
	{ XK_1,            Mod1Mask|ControlMask,           ESC"49;7u",    0,  0},
	{ XK_2,            ControlMask,                    ESC"50;5u",    0,  0},
	{ XK_2,            Mod1Mask|ControlMask,           ESC"50;7u",    0,  0},
	{ XK_3,            ControlMask,                    ESC"51;5u",    0,  0},
	{ XK_3,            Mod1Mask|ControlMask,           ESC"51;7u",    0,  0},
	{ XK_4,            ControlMask,                    ESC"52;5u",    0,  0},
	{ XK_4,            Mod1Mask|ControlMask,           ESC"52;7u",    0,  0},
	{ XK_5,            ControlMask,                    ESC"53;5u",    0,  0},
	{ XK_5,            Mod1Mask|ControlMask,           ESC"53;7u",    0,  0},
	{ XK_6,            ControlMask,                    ESC"54;5u",    0,  0},
	{ XK_6,            Mod1Mask|ControlMask,           ESC"54;7u",    0,  0},
	{ XK_7,            ControlMask,                    ESC"55;5u",    0,  0},
	{ XK_7,            Mod1Mask|ControlMask,           ESC"55;7u",    0,  0},
	{ XK_8,            ControlMask,                    ESC"56;5u",    0,  0},
	{ XK_8,            Mod1Mask|ControlMask,           ESC"56;7u",    0,  0},
	{ XK_9,            ControlMask,                    ESC"57;5u",    0,  0},
	{ XK_9,            Mod1Mask|ControlMask,           ESC"57;7u",    0,  0},
	{ XK_ampersand,    ControlMask,                    ESC"38;5u",    0,  0},
	{ XK_ampersand,    ControlMask|ShiftMask,          ESC"38;6u",    0,  0},
	{ XK_ampersand,    Mod1Mask,                       ESC"38;3u",    0,  0},
	{ XK_ampersand,    Mod1Mask|ControlMask,           ESC"38;7u",    0,  0},
	{ XK_ampersand,    Mod1Mask|ControlMask|ShiftMask, ESC"38;8u",    0,  0},
	{ XK_ampersand,    Mod1Mask|ShiftMask,             ESC"38;4u",    0,  0},
	{ XK_apostrophe,   ControlMask,                    ESC"39;5u",    0,  0},
	{ XK_apostrophe,   ControlMask|ShiftMask,          ESC"39;6u",    0,  0},
	{ XK_apostrophe,   Mod1Mask,                       ESC"39;3u",    0,  0},
	{ XK_apostrophe,   Mod1Mask|ControlMask,           ESC"39;7u",    0,  0},
	{ XK_apostrophe,   Mod1Mask|ControlMask|ShiftMask, ESC"39;8u",    0,  0},
	{ XK_apostrophe,   Mod1Mask|ShiftMask,             ESC"39;4u",    0,  0},
	{ XK_asciicircum,  ControlMask,                    ESC"94;5u",    0,  0},
	{ XK_asciicircum,  ControlMask|ShiftMask,          ESC"94;6u",    0,  0},
	{ XK_asciicircum,  Mod1Mask,                       ESC"94;3u",    0,  0},
	{ XK_asciicircum,  Mod1Mask|ControlMask,           ESC"94;7u",    0,  0},
	{ XK_asciicircum,  Mod1Mask|ControlMask|ShiftMask, ESC"94;8u",    0,  0},
	{ XK_asciicircum,  Mod1Mask|ShiftMask,             ESC"94;4u",    0,  0},
	{ XK_asciitilde,   ControlMask,                    ESC"126;5u",   0,  0},
	{ XK_asciitilde,   ControlMask|ShiftMask,          ESC"126;6u",   0,  0},
	{ XK_asciitilde,   Mod1Mask,                       ESC"126;3u",   0,  0},
	{ XK_asciitilde,   Mod1Mask|ControlMask,           ESC"126;7u",   0,  0},
	{ XK_asciitilde,   Mod1Mask|ControlMask|ShiftMask, ESC"126;8u",   0,  0},
	{ XK_asciitilde,   Mod1Mask|ShiftMask,             ESC"126;4u",   0,  0},
	{ XK_asterisk,     ControlMask,                    ESC"42;5u",    0,  0},
	{ XK_asterisk,     ControlMask|ShiftMask,          ESC"42;6u",    0,  0},
	{ XK_asterisk,     Mod1Mask,                       ESC"42;3u",    0,  0},
	{ XK_asterisk,     Mod1Mask|ControlMask,           ESC"42;7u",    0,  0},
	{ XK_asterisk,     Mod1Mask|ControlMask|ShiftMask, ESC"42;8u",    0,  0},
	{ XK_asterisk,     Mod1Mask|ShiftMask,             ESC"42;4u",    0,  0},
	{ XK_at,           ControlMask,                    ESC"64;5u",    0,  0},
	{ XK_at,           ControlMask|ShiftMask,          ESC"64;6u",    0,  0},
	{ XK_at,           Mod1Mask,                       ESC"64;3u",    0,  0},
	{ XK_at,           Mod1Mask|ControlMask,           ESC"64;7u",    0,  0},
	{ XK_at,           Mod1Mask|ControlMask|ShiftMask, ESC"64;8u",    0,  0},
	{ XK_at,           Mod1Mask|ShiftMask,             ESC"64;4u",    0,  0},
	{ XK_backslash,    ControlMask,                    ESC"92;5u",    0,  0},
	{ XK_backslash,    ControlMask|ShiftMask,          ESC"92;6u",    0,  0},
	{ XK_backslash,    Mod1Mask,                       ESC"92;3u",    0,  0},
	{ XK_backslash,    Mod1Mask|ControlMask,           ESC"92;7u",    0,  0},
	{ XK_backslash,    Mod1Mask|ControlMask|ShiftMask, ESC"92;8u",    0,  0},
	{ XK_backslash,    Mod1Mask|ShiftMask,             ESC"92;4u",    0,  0},
	{ XK_bar,          ControlMask,                    ESC"124;5u",   0,  0},
	{ XK_bar,          ControlMask|ShiftMask,          ESC"124;6u",   0,  0},
	{ XK_bar,          Mod1Mask,                       ESC"124;3u",   0,  0},
	{ XK_bar,          Mod1Mask|ControlMask,           ESC"124;7u",   0,  0},
	{ XK_bar,          Mod1Mask|ControlMask|ShiftMask, ESC"124;8u",   0,  0},
	{ XK_bar,          Mod1Mask|ShiftMask,             ESC"124;4u",   0,  0},
	{ XK_braceleft,    ControlMask,                    ESC"123;5u",   0,  0},
	{ XK_braceleft,    ControlMask|ShiftMask,          ESC"123;6u",   0,  0},
	{ XK_braceleft,    Mod1Mask,                       ESC"123;3u",   0,  0},
	{ XK_braceleft,    Mod1Mask|ControlMask,           ESC"123;7u",   0,  0},
	{ XK_braceleft,    Mod1Mask|ControlMask|ShiftMask, ESC"123;8u",   0,  0},
	{ XK_braceleft,    Mod1Mask|ShiftMask,             ESC"123;4u",   0,  0},
	{ XK_braceright,   ControlMask,                    ESC"125;5u",   0,  0},
	{ XK_braceright,   ControlMask|ShiftMask,          ESC"125;6u",   0,  0},
	{ XK_braceright,   Mod1Mask,                       ESC"125;3u",   0,  0},
	{ XK_braceright,   Mod1Mask|ControlMask,           ESC"125;7u",   0,  0},
	{ XK_braceright,   Mod1Mask|ControlMask|ShiftMask, ESC"125;8u",   0,  0},
	{ XK_braceright,   Mod1Mask|ShiftMask,             ESC"125;4u",   0,  0},
	{ XK_bracketleft,  ControlMask,                    ESC"91;5u",    0,  0},
	{ XK_bracketleft,  ControlMask|ShiftMask,          ESC"91;6u",    0,  0},
	{ XK_bracketleft,  Mod1Mask,                       ESC"91;3u",    0,  0},
	{ XK_bracketleft,  Mod1Mask|ControlMask,           ESC"91;7u",    0,  0},
	{ XK_bracketleft,  Mod1Mask|ControlMask|ShiftMask, ESC"91;8u",    0,  0},
	{ XK_bracketleft,  Mod1Mask|ShiftMask,             ESC"91;4u",    0,  0},
	{ XK_bracketright, ControlMask,                    ESC"93;5u",    0,  0},
	{ XK_bracketright, ControlMask|ShiftMask,          ESC"93;6u",    0,  0},
	{ XK_bracketright, Mod1Mask,                       ESC"93;3u",    0,  0},
	{ XK_bracketright, Mod1Mask|ControlMask,           ESC"93;7u",    0,  0},
	{ XK_bracketright, Mod1Mask|ControlMask|ShiftMask, ESC"93;8u",    0,  0},
	{ XK_bracketright, Mod1Mask|ShiftMask,             ESC"93;4u",    0,  0},
	{ XK_colon,        ControlMask,                    ESC"58;5u",    0,  0},
	{ XK_colon,        ControlMask|ShiftMask,          ESC"58;6u",    0,  0},
	{ XK_colon,        Mod1Mask,                       ESC"58;3u",    0,  0},
	{ XK_colon,        Mod1Mask|ControlMask,           ESC"58;7u",    0,  0},
	{ XK_colon,        Mod1Mask|ControlMask|ShiftMask, ESC"58;8u",    0,  0},
	{ XK_colon,        Mod1Mask|ShiftMask,             ESC"58;4u",    0,  0},
	{ XK_comma,        ControlMask,                    ESC"44;5u",    0,  0},
	{ XK_comma,        ControlMask|ShiftMask,          ESC"44;6u",    0,  0},
	{ XK_comma,        Mod1Mask,                       ESC"44;3u",    0,  0},
	{ XK_comma,        Mod1Mask|ControlMask,           ESC"44;7u",    0,  0},
	{ XK_comma,        Mod1Mask|ControlMask|ShiftMask, ESC"44;8u",    0,  0},
	{ XK_comma,        Mod1Mask|ShiftMask,             ESC"44;4u",    0,  0},
	{ XK_dollar,       ControlMask,                    ESC"36;5u",    0,  0},
	{ XK_dollar,       ControlMask|ShiftMask,          ESC"36;6u",    0,  0},
	{ XK_dollar,       Mod1Mask,                       ESC"36;3u",    0,  0},
	{ XK_dollar,       Mod1Mask|ControlMask,           ESC"36;7u",    0,  0},
	{ XK_dollar,       Mod1Mask|ControlMask|ShiftMask, ESC"36;8u",    0,  0},
	{ XK_dollar,       Mod1Mask|ShiftMask,             ESC"36;4u",    0,  0},
	{ XK_equal,        ControlMask,                    ESC"61;5u",    0,  0},
	{ XK_equal,        ControlMask|ShiftMask,          ESC"61;6u",    0,  0},
	{ XK_equal,        Mod1Mask,                       ESC"61;3u",    0,  0},
	{ XK_equal,        Mod1Mask|ControlMask,           ESC"61;7u",    0,  0},
	{ XK_equal,        Mod1Mask|ControlMask|ShiftMask, ESC"61;8u",    0,  0},
	{ XK_equal,        Mod1Mask|ShiftMask,             ESC"61;4u",    0,  0},
	{ XK_exclam,       ControlMask,                    ESC"33;5u",    0,  0},
	{ XK_exclam,       ControlMask|ShiftMask,          ESC"33;6u",    0,  0},
	{ XK_exclam,       Mod1Mask,                       ESC"33;3u",    0,  0},
	{ XK_exclam,       Mod1Mask|ControlMask,           ESC"33;7u",    0,  0},
	{ XK_exclam,       Mod1Mask|ControlMask|ShiftMask, ESC"33;8u",    0,  0},
	{ XK_exclam,       Mod1Mask|ShiftMask,             ESC"33;4u",    0,  0},
	{ XK_grave,        ControlMask,                    ESC"96;5u",    0,  0},
	{ XK_grave,        ControlMask|ShiftMask,          ESC"96;6u",    0,  0},
	{ XK_grave,        Mod1Mask,                       ESC"96;3u",    0,  0},
	{ XK_grave,        Mod1Mask|ControlMask,           ESC"96;7u",    0,  0},
	{ XK_grave,        Mod1Mask|ControlMask|ShiftMask, ESC"96;8u",    0,  0},
	{ XK_grave,        Mod1Mask|ShiftMask,             ESC"96;4u",    0,  0},
	{ XK_greater,      ControlMask,                    ESC"62;5u",    0,  0},
	{ XK_greater,      ControlMask|ShiftMask,          ESC"62;6u",    0,  0},
	{ XK_greater,      Mod1Mask,                       ESC"62;3u",    0,  0},
	{ XK_greater,      Mod1Mask|ControlMask,           ESC"62;7u",    0,  0},
	{ XK_greater,      Mod1Mask|ControlMask|ShiftMask, ESC"62;8u",    0,  0},
	{ XK_greater,      Mod1Mask|ShiftMask,             ESC"62;4u",    0,  0},
	{ XK_less,         ControlMask,                    ESC"60;5u",    0,  0},
	{ XK_less,         ControlMask|ShiftMask,          ESC"60;6u",    0,  0},
	{ XK_less,         Mod1Mask,                       ESC"60;3u",    0,  0},
	{ XK_less,         Mod1Mask|ControlMask,           ESC"60;7u",    0,  0},
	{ XK_less,         Mod1Mask|ControlMask|ShiftMask, ESC"60;8u",    0,  0},
	{ XK_less,         Mod1Mask|ShiftMask,             ESC"60;4u",    0,  0},
	{ XK_minus,        ControlMask,                    ESC"45;5u",    0,  0},
	{ XK_minus,        ControlMask|ShiftMask,          ESC"45;6u",    0,  0},
	{ XK_minus,        Mod1Mask,                       ESC"45;3u",    0,  0},
	{ XK_minus,        Mod1Mask|ControlMask,           ESC"45;7u",    0,  0},
	{ XK_minus,        Mod1Mask|ControlMask|ShiftMask, ESC"45;8u",    0,  0},
	{ XK_minus,        Mod1Mask|ShiftMask,             ESC"45;4u",    0,  0},
	{ XK_numbersign,   ControlMask,                    ESC"35;5u",    0,  0},
	{ XK_numbersign,   ControlMask|ShiftMask,          ESC"35;6u",    0,  0},
	{ XK_numbersign,   Mod1Mask,                       ESC"35;3u",    0,  0},
	{ XK_numbersign,   Mod1Mask|ControlMask,           ESC"35;7u",    0,  0},
	{ XK_numbersign,   Mod1Mask|ControlMask|ShiftMask, ESC"35;8u",    0,  0},
	{ XK_numbersign,   Mod1Mask|ShiftMask,             ESC"35;4u",    0,  0},
	{ XK_parenleft,    ControlMask,                    ESC"40;5u",    0,  0},
	{ XK_parenleft,    ControlMask|ShiftMask,          ESC"40;6u",    0,  0},
	{ XK_parenleft,    Mod1Mask,                       ESC"40;3u",    0,  0},
	{ XK_parenleft,    Mod1Mask|ControlMask,           ESC"40;7u",    0,  0},
	{ XK_parenleft,    Mod1Mask|ControlMask|ShiftMask, ESC"40;8u",    0,  0},
	{ XK_parenleft,    Mod1Mask|ShiftMask,             ESC"40;4u",    0,  0},
	{ XK_parenright,   ControlMask,                    ESC"41;5u",    0,  0},
	{ XK_parenright,   ControlMask|ShiftMask,          ESC"41;6u",    0,  0},
	{ XK_parenright,   Mod1Mask,                       ESC"41;3u",    0,  0},
	{ XK_parenright,   Mod1Mask|ControlMask,           ESC"41;7u",    0,  0},
	{ XK_parenright,   Mod1Mask|ControlMask|ShiftMask, ESC"41;8u",    0,  0},
	{ XK_parenright,   Mod1Mask|ShiftMask,             ESC"41;4u",    0,  0},
	{ XK_percent,      ControlMask,                    ESC"37;5u",    0,  0},
	{ XK_percent,      ControlMask|ShiftMask,          ESC"37;6u",    0,  0},
	{ XK_percent,      Mod1Mask,                       ESC"37;3u",    0,  0},
	{ XK_percent,      Mod1Mask|ControlMask,           ESC"37;7u",    0,  0},
	{ XK_percent,      Mod1Mask|ControlMask|ShiftMask, ESC"37;8u",    0,  0},
	{ XK_percent,      Mod1Mask|ShiftMask,             ESC"37;4u",    0,  0},
	{ XK_period,       ControlMask,                    ESC"46;5u",    0,  0},
	{ XK_period,       ControlMask|ShiftMask,          ESC"46;6u",    0,  0},
	{ XK_period,       Mod1Mask|ControlMask,           ESC"46;7u",    0,  0},
	{ XK_period,       Mod1Mask|ControlMask|ShiftMask, ESC"46;8u",    0,  0},
	{ XK_period,       Mod1Mask|ShiftMask,             ESC"46;4u",    0,  0},
	{ XK_plus,         ControlMask,                    ESC"43;5u",    0,  0},
	{ XK_plus,         ControlMask|ShiftMask,          ESC"43;6u",    0,  0},
	{ XK_plus,         Mod1Mask,                       ESC"43;3u",    0,  0},
	{ XK_plus,         Mod1Mask|ControlMask,           ESC"43;7u",    0,  0},
	{ XK_plus,         Mod1Mask|ControlMask|ShiftMask, ESC"43;8u",    0,  0},
	{ XK_plus,         Mod1Mask|ShiftMask,             ESC"43;4u",    0,  0},
	{ XK_question,     ControlMask,                    ESC"63;5u",    0,  0},
	{ XK_question,     ControlMask|ShiftMask,          ESC"63;6u",    0,  0},
	{ XK_question,     Mod1Mask,                       ESC"63;3u",    0,  0},
	{ XK_question,     Mod1Mask|ControlMask,           ESC"63;7u",    0,  0},
	{ XK_question,     Mod1Mask|ControlMask|ShiftMask, ESC"63;8u",    0,  0},
	{ XK_question,     Mod1Mask|ShiftMask,             ESC"63;4u",    0,  0},
	{ XK_quotedbl,     ControlMask,                    ESC"34;5u",    0,  0},
	{ XK_quotedbl,     ControlMask|ShiftMask,          ESC"34;6u",    0,  0},
	{ XK_quotedbl,     Mod1Mask,                       ESC"34;3u",    0,  0},
	{ XK_quotedbl,     Mod1Mask|ControlMask,           ESC"34;7u",    0,  0},
	{ XK_quotedbl,     Mod1Mask|ControlMask|ShiftMask, ESC"34;8u",    0,  0},
	{ XK_quotedbl,     Mod1Mask|ShiftMask,             ESC"34;4u",    0,  0},
	{ XK_semicolon,    ControlMask,                    ESC"59;5u",    0,  0},
	{ XK_semicolon,    ControlMask|ShiftMask,          ESC"59;6u",    0,  0},
	{ XK_semicolon,    Mod1Mask,                       ESC"59;3u",    0,  0},
	{ XK_semicolon,    Mod1Mask|ControlMask,           ESC"59;7u",    0,  0},
	{ XK_semicolon,    Mod1Mask|ControlMask|ShiftMask, ESC"59;8u",    0,  0},
	{ XK_semicolon,    Mod1Mask|ShiftMask,             ESC"59;4u",    0,  0},
	{ XK_slash,        ControlMask|ShiftMask,          ESC"47;6u",    0,  0},
	{ XK_slash,        Mod1Mask,                       ESC"47;3u",    0,  0},
	{ XK_slash,        Mod1Mask|ControlMask,           ESC"47;7u",    0,  0},
	{ XK_slash,        Mod1Mask|ControlMask|ShiftMask, ESC"47;8u",    0,  0},
	{ XK_slash,        Mod1Mask|ShiftMask,             ESC"47;4u",    0,  0},
	{ XK_underscore,   ControlMask,                    ESC"95;5u",    0,  0},
	{ XK_underscore,   ControlMask|ShiftMask,          ESC"95;6u",    0,  0},
	{ XK_underscore,   Mod1Mask,                       ESC"95;3u",    0,  0},
	{ XK_underscore,   Mod1Mask|ControlMask,           ESC"95;7u",    0,  0},
	{ XK_underscore,   Mod1Mask|ControlMask|ShiftMask, ESC"95;8u",    0,  0},
	{ XK_underscore,   Mod1Mask|ShiftMask,             ESC"95;4u",    0,  0},
#if SPACE_BINDINGS
	{ XK_space,        ControlMask|ShiftMask,          ESC"32;6u",    0,  0},
	{ XK_space,        Mod1Mask,                       ESC"32;3u",    0,  0},
	{ XK_space,        Mod1Mask|ControlMask,           ESC"32;7u",    0,  0},
	{ XK_space,        Mod1Mask|ControlMask|ShiftMask, ESC"32;8u",    0,  0},
	{ XK_space,        Mod1Mask|ShiftMask,             ESC"32;4u",    0,  0},
	{ XK_space,        ShiftMask,                      ESC"32;2u",    0,  0},
	{ XK_BackSpace,    ControlMask,                    ESC"127;5u",   0,  0},
	{ XK_BackSpace,    ControlMask|ShiftMask,          ESC"127;6u",   0,  0},
	{ XK_BackSpace,    Mod1Mask,                       ESC"127;3u",   0,  0},
	{ XK_BackSpace,    Mod1Mask|ControlMask,           ESC"127;7u",   0,  0},
	{ XK_BackSpace,    Mod1Mask|ControlMask|ShiftMask, ESC"127;8u",   0,  0},
	{ XK_BackSpace,    Mod1Mask|ShiftMask,             ESC"127;4u",   0,  0},
	{ XK_BackSpace,    ShiftMask,                      ESC"127;2u",   0,  0},
#endif

	/* if these two are enabled, ctrl+i and ctrl+m won't act as Tab and Enter respectively. */
	/* { XK_i,            ControlMask,                    ESC"105;5u",   0,  0}, */
	/* { XK_m,            ControlMask,                    ESC"109;5u",   0,  0}, */
};

/*
 * Selection types' masks.
 * Use the same masks as usual.
 * Button1Mask is always unset, to make masks match between ButtonPress.
 * ButtonRelease and MotionNotify.
 * If no match is found, regular selection is used.
 */
static uint selmasks[] = {
	[SEL_RECTANGULAR] = ControlMask,
};

/*
 * Printable characters in ASCII, used to estimate the advance width
 * of single wide characters.
 */
static char ascii_printable[] =
	" !\"#$%&'()*+,-./0123456789:;<=>?"
	"@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
	"`abcdefghijklmnopqrstuvwxyz{|}~";
