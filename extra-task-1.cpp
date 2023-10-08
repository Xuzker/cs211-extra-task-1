#include <cassert>
#include <iostream>
#include <cmath>
#include <cfloat>

const double DBL_EPSILON = 1e-9;

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);

    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);

    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

int get_hours(int seconds)
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    return (seconds % 3600) % 60;
}

double time_to_utc(int utc_offset, double time)
{
    assert(-12 <= utc_offset && utc_offset <= 14);

    double utc_time = time - utc_offset;
    if (utc_time < 0)
    {
        utc_time += 24.0;
    }

    return fmod(utc_time, 24.0);
}

double time_from_utc(int utc_offset, double time)
{
    assert(-12 <= utc_offset && utc_offset <= 14);

    double local_time = time + utc_offset;
    if (local_time < 0)
    {
        local_time += 24.0;
    }

    return fmod(local_time, 24.0);
}
