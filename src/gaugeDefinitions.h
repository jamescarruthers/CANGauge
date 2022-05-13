//IAT, CLT, RPM
//MAP, DEG, AFR

struct gaugeDef {

    // title of the variable
    const char* title;

    // what units to display
    const char* units;

    // significant figures to round to (0 = x, 1 = x.x, 2 = x.xx)
    int sigFigs;

    // minimum to show on the gauge
    float min;

    // maximum to show on the gauge
    float max;

    // warn below this value
    float low;

    // warn above this value
    float high;

    // major ticks
    float majorTicks;

    //minor ticks
    float minorTicks;
};

gaugeDef GDrpm = { "RPM", "RPM", 0, 0, 7000, 250, 6500, 1000, 500 };
gaugeDef GDadv_deg = { "ADV", "degrees", 0, 0, 40, 0, 40, 10, 5};

gaugeDef GDmap = { "MAP", "kPa", 0, 0, 100, 10, 90, 10, 5};
gaugeDef GDmat = { "IAT", "c", 0, 0, 80, 0, 50, 10, 5 };
gaugeDef GDclt = { "CLT", "c", 0, 0, 120, 75, 110, 10, 5 };

gaugeDef GDtps = { "TPS", "%", 0, 0, 100, 0, 100, 10, 5};
gaugeDef GDbatt = { "BAT", "V", 1, 10, 16.0, 11, 15, 1, 0.5};
gaugeDef GDafr = { "AFR", "AFR", 1, 9.7, 19.7, 13, 16, 1, 0.5};

gaugeDef GDrpmRace = { "RPM", "RPM", 0, 3500, 6500, 3500, 6000, 1000, 500 };