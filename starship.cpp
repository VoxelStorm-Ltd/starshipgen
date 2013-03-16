#include "starship.h"
#include "civilisation.h"
#include "componentlist.h"
#include "component.h"

starship::starship(unsigned int seed,
                   civilisation *thisciv,
                   componentlist *thiscomponenttypes) {
  /// Constructor to generate a spaceship based on a given civilisation
  randomgen = new randomgenerator(seed);
  civ = thisciv;
  componenttypes = thiscomponenttypes;

  shipclock = 0;

  // set up overall cultural factors
  std::cout << "DEBUG: This ship has a redundancy level " << (unsigned int)civ->redundancy << std::endl;

  // Check if we have FTL
  if(civ->invented_ftl) {
    propulsiontype ftlpropulsion = (propulsiontype)randomgen->pick_one(
      PROPULSION_WARPBUBBLE,
      PROPULSION_HYPERDRIVE,
      PROPULSION_JUMPFINS,
      PROPULSION_WITCHSPACE,
      PROPULSION_WORMHOLE,
      PROPULSION_WARPGATE
    );
    // Decide whether FTL travel is on-board or external
    if(ftlpropulsion == PROPULSION_WORMHOLE ||
       ftlpropulsion == PROPULSION_WARPGATE) {
      has_ftldrive = false;
      std::cout << "This ship can travel faster than light by entering certain fixed anomalies." << std::endl;
    } else {
      has_ftldrive = true;
      // Populate engines based on type
      unsigned int numengines = 1;
      switch(ftlpropulsion) {
      case PROPULSION_WARPBUBBLE:
        //numengines = randomgen->pick_one(1, 2, 3, 4);
        numengines = 1 + ((double)civ->redundancy / 255.0 * 3) + 0.5;
        std::cout << "This ship can travel faster than light, using " << numengines << " warp bubble engines." << std::endl;
        break;
      case PROPULSION_HYPERDRIVE:
        numengines = 1 + randomgen->random_bool_weighted((double)civ->redundancy / 255.0);
        std::cout << "This ship can travel faster than light, using " << numengines << " hyperdrives." << std::endl;
        break;
      case PROPULSION_JUMPFINS:
        numengines = randomgen->pick_one(16, 32, 64, 128);
        std::cout << "This ship can travel faster than light, using " << numengines << " jump fins." << std::endl;
        break;
      case PROPULSION_WITCHSPACE:
        numengines = 1;
        std::cout << "This ship can travel faster than light, using a witchspace jump drive." << std::endl;
        break;
      default:
        std::cout << "ERROR: FTL propulsion determination error, unhandled enum " << ftlpropulsion << std::endl;
      }
    }
  } else {
    ftlpropulsion = PROPULSION_NONE;
  }
  // Decide on slower-than-light propulsion system appropriate to the tech level
  if(civ->techlevel > 191) {
    propulsion = (propulsiontype)randomgen->pick_one(
      PROPULSION_ION,
      PROPULSION_RAMSCOOP,
      PROPULSION_VASIMR,
      PROPULSION_ANTIMATTERFUSION
    );
  } else if(civ->techlevel > 127) {
    propulsion = (propulsiontype)randomgen->pick_one(
      PROPULSION_NONE,
      PROPULSION_FUSION,
      PROPULSION_FUSIONTHERMAL,
      PROPULSION_ANTIMATTER,
      PROPULSION_ION,
      PROPULSION_RAMSCOOP,
      PROPULSION_SAIL,
      PROPULSION_VASIMR,
      PROPULSION_ANTIMATTERFUSION
    );
  } else if(civ->techlevel > 63) {
    propulsion = (propulsiontype)randomgen->pick_one(
      PROPULSION_NONE,
      PROPULSION_FUSION,
      PROPULSION_FUSIONTHERMAL,
      PROPULSION_FISSIONTHERMAL,
      PROPULSION_FISSIONFRAGMENT,
      PROPULSION_ION,
      PROPULSION_RAMSCOOP,
      PROPULSION_SAIL,
      PROPULSION_VASIMR
    );
  } else if(civ->techlevel > 16) {
    propulsion = (propulsiontype)randomgen->pick_one(
      PROPULSION_NONE,
      PROPULSION_FUSION,
      PROPULSION_FISSION,
      PROPULSION_FUSIONTHERMAL,
      PROPULSION_FISSIONTHERMAL,
      PROPULSION_FISSIONFRAGMENT,
      PROPULSION_CHEMICAL,
      PROPULSION_ION,
      PROPULSION_SAIL,
      PROPULSION_VASIMR
    );
  } else {
    propulsion = (propulsiontype)randomgen->pick_one(
      PROPULSION_FISSION,
      PROPULSION_FISSIONTHERMAL,
      PROPULSION_FISSIONFRAGMENT,
      PROPULSION_CHEMICAL
    );
  }
  if(propulsion == PROPULSION_NONE) {
    has_stldrive = false;
    has_atmospheric = false;
    if(has_ftldrive == false) {
      std::cout << "This vessel is on a fixed trajectory, with no active means of adjusting its direction of motion." << std::endl;
    }
  } else {
    has_stldrive = true;
    unsigned int numengines = 1;
    switch(propulsion) {
    case PROPULSION_FUSION:
      {
        numengines = 1;
        has_atmospheric = true;
        std::cout << "This ship has one inertial confinement direct exhaust fusion rocket engine." << std::endl;
        // radiation shielding
        // fusion pellet magazines (duterium/helium3 mix)
        // inertial confinement reactor
        // lasers
        // magnetic nozzle
        // exhaust plasma tapping induction coils
        component *thisengine = new component(componenttypes->getcomponent("engine_fusionrocket"), this);
        component *thisnozzle = new component(componenttypes->getcomponent("engine_rocket_nozzle"), this);
        parts.push_back(thisengine);
        parts.push_back(thisnozzle);
        component_engines_stl.push_back(thisengine);
        component_engines_stl.push_back(thisnozzle);
      }
      break;
    case PROPULSION_FISSION:
      {
        numengines = 1;
        has_atmospheric = true;
        std::cout << "This ship has one external nuclear pulse rocket engine." << std::endl;
        component *thisengine = new component(componenttypes->getcomponent("engine_nuclearpulse"), this);
        parts.push_back(thisengine);
        component_engines_stl.push_back(thisengine);
        // radiation shielding
        // nuclear pulse unit magazines
        // ejector gas tank
        // pulse unit launcher
        // coolant storage tanks
        // plasma deflector cone
        // second stage shock absorbers
        // intermediate platform
        // first stage shock absorbers
        // pusher plate
      }
      break;
    case PROPULSION_FUSIONTHERMAL:
      {
        numengines = 1 + ((double)civ->redundancy / 255.0 * 6) + 0.5;
        has_atmospheric = true;
        std::cout << "This ship has " << numengines << " thermal fusion nuclear rocket engines." << std::endl;
        parts.push_back(new component(componenttypes->getcomponent("fueltank_hydrogen"), this));
        for(unsigned int i = 0; i < numengines; ++i) {
          // inertial confinement reactor core
          // plasma compression guns
          // external disc shield
          component *thisengine = new component(componenttypes->getcomponent("engine_thermalfusion"), this);
          parts.push_back(thisengine);
          component_engines_stl.push_back(thisengine);
          component_power.push_back(thisengine);
          unsigned int numturbopumps = 1 + ((double)civ->redundancy / 255.0 * 4) + 0.5;
          for(unsigned int i = 0; i < numturbopumps; ++i) {
            component *thispump = new component(componenttypes->getcomponent("turbopump"), this);
            parts.push_back(thispump);
            component_engines_stl.push_back(thispump);
          }
          component *thisnozzle = new component(componenttypes->getcomponent("engine_rocket_nozzle"), this);
          parts.push_back(thisnozzle);
          component_engines_stl.push_back(thisnozzle);
        }
        // radiators
      }
      // radiation shielding
      break;
    case PROPULSION_FISSIONTHERMAL:
      {
        numengines = 1 + ((double)civ->redundancy / 255.0 * 3) + 0.5;
        has_atmospheric = true;
        std::cout << "This ship has " << numengines << " thermal nuclear rocket engines." << std::endl;
        std::cout << "Info: " << componenttypes->getcomponent("engine_thermalnuclear")->description << std::endl;
        for(unsigned int i = 0; i < numengines; ++i) {
          component *thisengine = new component(componenttypes->getcomponent("engine_thermalnuclear"), this);
          parts.push_back(thisengine);
          component_engines_stl.push_back(thisengine);
          component_power.push_back(thisengine);
        }
        component *thistank = new component(componenttypes->getcomponent("fueltank_hydrogen"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        // radiators
      }
      // radiation shielding
      break;
    case PROPULSION_FISSIONFRAGMENT:
      {
        numengines = randomgen->pick_one(1, 2, 3, 4);
        has_atmospheric = true;
        std::cout << "This ship has " << numengines << " fission fragment nuclear rocket engines." << std::endl;
        for(unsigned int i = 0; i < numengines; ++i) {
          component *thisengine = new component(componenttypes->getcomponent("engine_fissionfragment"), this);
          parts.push_back(thisengine);
          component_engines_stl.push_back(thisengine);
          // fissionable fuel disks
          // reactor core
          // fragment exhaust
          // moderator
          // containment field generator
          // induction coils
          // decelerator
          component *thisgenerator = new component(componenttypes->getcomponent("generator_thermonuclear"), this);
          parts.push_back(thisgenerator);
          component_engines_stl.push_back(thisgenerator);
          component_power.push_back(thisgenerator);
        }
      }
      break;
    case PROPULSION_CHEMICAL:
      {
        numengines = randomgen->pick_one(5, 6, 8, 9, 30);
        has_atmospheric = true;
        std::cout << "This ship has " << numengines << " old-fashioned chemical rocket engines." << std::endl;
        component *thistank = new component(componenttypes->getcomponent("fueltank_hydrogen"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        thistank = new component(componenttypes->getcomponent("fueltank_oxygen"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        for(unsigned int i = 0; i < numengines; ++i) {
          unsigned int numturbopumps = 1 + ((double)civ->redundancy / 255.0 * 4) + 0.5;
          for(unsigned int i = 0; i < numturbopumps; ++i) {
            component *thispump = new component(componenttypes->getcomponent("turbopump"), this);
            parts.push_back(thispump);
            component_engines_stl.push_back(thispump);
          }
          component *thismotor = new component(componenttypes->getcomponent("engine_rocket_motor"), this);
          parts.push_back(thismotor);
          component_engines_stl.push_back(thismotor);
          component *thisnozzle = new component(componenttypes->getcomponent("engine_rocket_nozzle"), this);
          parts.push_back(thisnozzle);
          component_engines_stl.push_back(thisnozzle);
        }
      }
      break;
    case PROPULSION_ANTIMATTER:
      {
        numengines = 1;
        has_atmospheric = true;
        std::cout << "This ship has one matter/antimatter annihilation rocket engine." << std::endl;
        component *thistank = new component(componenttypes->getcomponent("fueltank_hydrogen"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        thistank = new component(componenttypes->getcomponent("fueltank_antimatter"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        component *thisreactor = new component(componenttypes->getcomponent("engine_antimatter_reactor"), this);
        parts.push_back(thisreactor);
        component_engines_stl.push_back(thisreactor);
        component_power.push_back(thisreactor);
        component *thisnozzle = new component(componenttypes->getcomponent("engine_magnetic_nozzle"), this);
        parts.push_back(thisnozzle);
        component_engines_stl.push_back(thisnozzle);
        // radiation shielding
        // radiators
      }
      break;
    case PROPULSION_ANTIMATTERFUSION:
      {
        numengines = 1;
        has_atmospheric = true;
        std::cout << "This ship is equipped with an antimatter catalyzed nuclear pulse engine." << std::endl;
        component *thistank = new component(componenttypes->getcomponent("fueltank_hydrogen"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        thistank = new component(componenttypes->getcomponent("fueltank_antimatter"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        component *thisengine = new component(componenttypes->getcomponent("engine_antimatterfusion"), this);
        parts.push_back(thisengine);
        component_engines_stl.push_back(thisengine);
        component_power.push_back(thisengine);
        // radiators
        // radiation shielding
        // nuclear pulse microfusion unit magazines
        // ejector gas tank
        // pulse unit launcher
        // coolant storage tanks
        // plasma deflector cone
        // shock absorbers
        // pusher plate
      }
      break;
    case PROPULSION_ION:
      {
        numengines = randomgen->pick_one(1, 2, 3, 4);
        has_atmospheric = false;
        std::cout << "This ship is equipped with " << numengines << " electric ion thrusters." << std::endl;
        component *thistank = new component(componenttypes->getcomponent("fueltank_xenon"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        for(unsigned int i = 0; i < numengines; ++i) {
          component *thisengine = new component(componenttypes->getcomponent("engine_ion"), this);
          parts.push_back(thisengine);
          component_engines_stl.push_back(thisengine);
          // electric engine nozzle
        }
      }
      break;
    case PROPULSION_RAMSCOOP:
      {
        numengines = 1;
        has_atmospheric = false;
        std::cout << "This ship is equipped with a Bussard ramscoop engine." << std::endl;
        component *thisengine = new component(componenttypes->getcomponent("engine_ramscoop"), this);
        parts.push_back(thisengine);
        component_engines_stl.push_back(thisengine);
        unsigned int numlasers = 1 + ((double)civ->redundancy / 255.0 * 3);
        for(unsigned int i = 0; i < numlasers; ++i) {
          component *thislaser = new component(componenttypes->getcomponent("weapon_laser_ionising"), this);
          parts.push_back(thislaser);
          component_engines_stl.push_back(thislaser);
          component_weapons.push_back(thislaser);
        }
        // collector
        // fusion chamber
        // fusion nozzle
      }
      break;
    case PROPULSION_SAIL:
      {
        numengines = 1;
        has_atmospheric = false;
        std::cout << "This ship is equipped with a solar sail." << std::endl;
        component *thisengine = new component(componenttypes->getcomponent("engine_sail"), this);
        parts.push_back(thisengine);
        component_engines_stl.push_back(thisengine);
      }
      break;
    case PROPULSION_VASIMR:
      {
        numengines = randomgen->pick_one(2, 4);
        has_atmospheric = false;
        std::cout << "This ship has " << numengines << " Variable Specific Impulse Magnetoplasma Rocket (VASIMR) engines." << std::endl;
        component *thistank = new component(componenttypes->getcomponent("fueltank_argon"), this);
        parts.push_back(thistank);
        component_engines_stl.push_back(thistank);
        for(unsigned int i = 0; i < numengines; ++i) {
          component *thisengine = new component(componenttypes->getcomponent("engine_vasimr"), this);
          parts.push_back(thisengine);
          component_engines_stl.push_back(thisengine);
          // RF generators
          // injector
          // helicon coupler
          // ICH coupler
          // electric engine nozzle
        }
      }
      break;
    default:
      std::cout << "ERROR: STL propulsion determination error, unhandled enum " << propulsion << std::endl;;
    }
  }

  unsigned int power_propulsion_max = 0;
  unsigned int power_propulsion_min = 0;
  unsigned int power_lifesupportmin = 0;

  std::cout << "This ship consumes from " << power_propulsion_min << "W up to " << power_propulsion_max << "W of power at full propulsion." << std::endl;
  std::cout << "This ship requires at least " << power_lifesupportmin << "W of power to maintain life support." << std::endl;
  // Decide on power system
  // Determine type of power transmission used
  // Decide number of slower than light engines
  // Populate all necessary propulsion auxiliaries (fuel etc)
  // Decide on amount of shielding around components based on cultural factors
  // Determine minimum crew complement
  // Decide whether this civilisation uses coldsleep
  // Determine maximum coldsleep capacity
  // Determine maximum total crew capacity
  // Determine mission type
  // Decide weaponry based on cultural inclination and mission
  // Determine auxiliary mission-specific systems required
  // Decide redundancy factor based on cultural inclination
  // Duplicate core systems according to redundancy factor
  // Decide axes of symmetry in the ship
  // Decide symmetric and non-symmetric sprawl factors
  // Lay out core components with respect to symmetry and sprawl factor
  // Place even numbers of engines off axes of symmetry
  // Place main power system on all axes of symmetry
  // Decide number of crew rooms required wrt cultural factors
  // Decide number of auxiliary crew rooms required wrt cultural factors
  // Determine required volume of crew module
  // Decide core location and shape of crew module with respect to cultural factors
  // Place bridge in a reasonable position on vertical axis of symmetry with a forward view
  // Place communications systems on furthest extremity on one axis of symmetry
  // Place even numbers of weapons systems off axes of symmetry
  // Determine whether culture has artificial gravity
  // Determine whether to allow horizontal turbolifts, vertical lifts only, or ladders only
  // Place engineering headquarters adjacent to main power system on axis of symmetry
  // Populate main horizontal corridors between key engineering components
  // Place secondary horizontal corridors between main and secondary rooms
  // Decide on a quota of vertical connections based on ship size, crew number and tech
  // Add vertical connections between most major overlapping corridors up to quota
  // Decide on proportion of crew ranks and depth of hierarchy
  // Decide on a cultural inequality factor for room size and opulence
  // Split remaining space into crew cabin rooms with a distribution of sizes
  // Add tertiary corridors where rooms are isolated from existing corridors
  // Add tertiary corridors where the primary corridors have too few junctions
  // Add power transmission systems under relevant floors
  // Add control system grid under relevant floors
  // Add jeffries tubes along densest parts of under-floor grids


}

starship::~starship() {
}
