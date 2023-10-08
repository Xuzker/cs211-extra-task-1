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

int main() {
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    assert(fabs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);
    assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
    assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);

    return 0;
}