#include "watchy_orbital_settings.h"

// Latitude and longitude of your position. Used for sunrise/sunset and moon phase calculation
float lat = 25.9479;
float lon = -80.1936;

// Translations of day of the week, starting at sunday (and ending at sunday too)
const char* daysOfWeek[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
// Very short month names, january to december. For the "details" mode, so should be short to be shown on the circle
const String shortMonths[] = {"ja", "fe", "mr", "ap", "my", "jn", "jl", "au", "se", "oc", "no", "de"};

/* Values of voltage considered as max (100%) and min (0%), to display the central circle.
 * Value is in milli-volt.
 * The default value is usually 3800 to 4100, but I found that my battery was more between 3500 and 4200. YMMV, hence the setting.
 */
int batteryVMax = 4150;
int batteryVMin = 3650;

/* Startup mode. Leave as is if you don't know what it is.
 * 8 modes
 * 0 : white on black, no details, 12h
 * 1 : white on black, no details, 24h
 * 2 : white on black, details, 12h
 * 3 : white on black, details, 24h
 * 4 : black on white, no details, 12h
 * 5 : black on white, no details, 24h
 * 6 : black on white, details, 12h
 * 7 : black on white, details, 24h
 */
RTC_DATA_ATTR int mode = 2; 