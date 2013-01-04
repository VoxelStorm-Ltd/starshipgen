#ifndef COMPONENTTYPE_H_INCLUDED
#define COMPONENTTYPE_H_INCLUDED

#include <string>

class componenttype {
public:
  enum failuremode {
    NONE         = 0,
    DEACTIVATED  = 1<<1,    // it's just been switched off
    DISCONNECTED = 1<<2,    // it's been physically disconnected (makes sense for conduits etc) (repairable)
    SURGING      = 1<<3,    // delivering excess power/fuel (conduits etc) (repairable)
    STUCKON      = 1<<4,    // it's stuck in on operation (repairable)
    STUCKOFF     = 1<<5,    // it's stuck in off operation (repairable)
    TOGGLING     = 1<<6,    // it's rapidly toggling on and off (repairable)
    RANDOM       = 1<<7,    // it's toggling on and off at random (repairable)
    SLOWON       = 1<<8,    // there is an unusual delay in activation
    SLOWOFF      = 1<<9,    // there is an unusual delay in deactivation
    NOPOWER      = 1<<10,   // power's not being delivered (repairable)
    NOFUEL       = 1<<11,   // fuel's not being delivered (repairable)
    UNDERPOWER   = 1<<12,   // insufficient power being delivered (repairable)
    UNDERFUEL    = 1<<13,   // insufficient fuel being delivered (repairable)
    ONFIRE       = 1<<14,   // is currently in flames (repairable with fire extinguisher)
    LEAKING      = 1<<15,   // is currently letting out some of whatever it contains (conduits etc)
  };
  enum state {
    STATE_OK,               // normal operation
    STATE_WORN,             // normal operation but showing cosmetic signs of wear
    STATE_REDUCEDFUNCTION,  // impaired / slow functionality, but still functional, can be fixed
    STATE_NONFUNCTIONAL,    // it's broken (but can be fixed)
    STATE_REPAIRING,        // someone's got a spanner to it right now
    STATE_DESTROYED,        // it's broken beyond repair, requires removal and replacement
    STATE_ABSENT,           // it's just not there, requires replacement (but nothing to remove)
  };

  std::string name;
  std::string description;

  uint64_t mtbf;      // mean time between failures, in seconds
  uint64_t time_on;   // how long it takes from activation to full function
  uint64_t time_off;  // how long it takes from deactivation to cease function
  unsigned int failuremodes;  // allowed failure modes
  unsigned char vuln_mechanical;  // how vulnerable it is to mechanical damage (bullets, spanners)
  unsigned char vuln_electric;    // how vulnerable it is to electric damage (power surges)
  unsigned char vuln_laser;       // how vulnerable it is to laser fire
  unsigned char vuln_heat;        // how vulnerable it is to heat damage
  unsigned char vuln_cold;        // how vulnerable it is to cold damage
  unsigned char vuln_shock;       // how vulnerable it is to physical impact
  unsigned char vuln_pressure;    // how vulnerable it is to overpressure
  unsigned char vuln_vacuum;      // how vulnerable it is to underpressure
  unsigned char flammability;     // how likely it is to catch on fire from nearby objects
  unsigned char explosiveness;    // how likely it is to explode if ignited, heated or shot
  unsigned int explosivepower;    // how much damage it does if exploding
  unsigned int required_energy;     // how much energy it needs per second to function correctly
  unsigned int required_fuel;       // how much fuel it needs per second to function correctly
  unsigned int required_energy_min; // how much energy it needs per second to function at all
  unsigned int required_fuel_min;   // how much fuel it needs per second to function at all

  componenttype();
  ~componenttype();
};

#endif // COMPONENTTYPE_H_INCLUDED
