#include "civilisation.h"
//#include <cstdlib>
//#include <string>
#include <sstream>

std::string civilisation::describe() {
  char notethres = 64;                                                          // attribute notability threshold

  std::stringstream desc;
  desc << "This is a ";
  if(techlevel >= 192) {
    desc << "highly advanced";
  } else if(techlevel >= 128) {
    desc << "moderately advanced";
  } else if(techlevel >= 64) {
    desc << "relatively new";
  } else {
    desc << "low-tech";
  }
  //desc << " (techlevel " << (unsigned int)techlevel << ")";
  if(wealth >= 192) {
    desc << ", extremely wealthy";
  } else if(wealth >= 128) {
    desc << ", wealthy";
  } else if(wealth >= 64) {
  } else {
    desc << ", impoverished";
  }
  //desc << " (wealth " << (unsigned int)wealth << ")";

  if(liberalism > notethres) {
    desc << " liberal";
  } else if(liberalism < -notethres) {
    desc << " conservative";
  }
  desc << " civilisation";


  if(hierarchicality > notethres) {
    desc << ", with a tendency towards hierarchy";
  } else if(hierarchicality < -notethres) {
    desc << ", with a love for social equality";
  }
  if(discipline > notethres) {
    desc << " known for a strong culture of discipline";
  } else if(discipline < -notethres) {
    desc << " noted for its lack of discipline";
  }
  desc << "." << std::endl;

  desc << "This race possesses a long history";
  if(homogeneity > notethres) {
    desc << ", a remarkable level of similarity between individuals";
  } else if(homogeneity < -notethres) {
    desc << ", a remarkable range of individual variety";
  }
  if(intelligence > notethres) {
    desc << ", is notable for its intelligence";
  } else if(intelligence < -notethres) {
    desc << ", a visible dim-wittedness";
  }
  if(strength > notethres) {
    desc << ", has exceptional strength";
  } else if(strength < -notethres) {
    desc << ", is physically frail";
  }
  if(stressability > notethres) {
    desc << ", is very susceptible to stress";
  } else if(stressability < -notethres) {
    desc << ", barely notices stress";
  }
  if(invented_ftl) {
    desc << " and is recognised throughout this sector of the galaxy";
  } else {
    desc << " and has never been seen outside its origin solar system";
  }
  desc << ". ";
  desc << "Observers frequently describe this race as spacefaring";
  if(selfishness > notethres) {
    desc << ", selfish";
  } else if(selfishness < -notethres) {
    desc << ", selfless";
  }
  if(generosity > notethres) {
    desc << ", generous";
  } else if(generosity < -notethres) {
    desc << ", stingy";
  }
  if(honesty > notethres) {
    desc << ", honest";
  } else if(honesty < -notethres) {
    desc << ", dishonest";
  }
  if(treachery > notethres) {
    desc << ", treacherous";
  } else if(treachery < -notethres) {
    desc << ", trustworthy";
  }
  if(belligirence > notethres) {
    desc << ", belligirent";
  } else if(belligirence < -notethres) {
    desc << ", peaceful";
  }
  if(ruthlessness > notethres) {
    desc << ", ruthless";
  } else if(ruthlessness < -notethres) {
    desc << ", compassionate";
  }
  if(vangefulness > notethres) {
    desc << ", vangeful";
  } else if(vangefulness < -notethres) {
    desc << ", forgiving";
  }
  if(cowardice > notethres) {
    desc << ", cowardly";
  } else if(cowardice < -notethres) {
    desc << ", brave";
  }
  if(laziness > notethres) {
    desc << ", lazy";
  } else if(laziness < -notethres) {
    desc << ", energetic";
  }
  desc << " and generally unpredictable. ";
  desc << "Members of this civilisation";
  if(physicality > notethres) {
    desc << " place a major emphasis on physical training, in between which they pass the time by";
  } else if(physicality < -notethres) {
    desc << " have a strong aversion to physical effort, preferring to occupy themselves by";
  }
  else {
    desc << " enjoy";
  }
  if(geekiness > notethres) {
    desc << " reading and learning";
  } else if(geekiness < -notethres) {
    desc << " tuning out";
  } else {
    desc << " spending time";
  }
  if(sociability > notethres) {
    desc << " in large social groups";
  } else if(sociability < -notethres) {
    desc << " exclusively on their own";
  } else if(sociability > 0) {
    desc << " socially and sometimes alone";
  } else {
    desc << " on their own and sometimes socially";
  }
  desc << ".";
  if(mercantility > notethres) {
    desc << " They are known for being very enterprising and driven by commerce.";
  } else if(mercantility < -notethres) {
    desc << " They are known to be inefficient in business dealings.";
  }
  if(artisticness > notethres) {
    desc << " Their artistic works are very highly prized.";
  } else if(artisticness < -notethres) {
    desc << " Their efforts at art are notoriously bad.";
  }
  if(religiousness > notethres) {
    desc << " Their religious devotion is exemplary.";
  } else if(religiousness < -notethres) {
    desc << " They have a strong aversion to religion.";
  }
  if(fashion > notethres) {
    desc << " They are well-known leaders in fashion.";
  } else if(fashion < -notethres) {
    desc << " They are frequently seen to be sloppily dressed.";
  }
  if(precision > notethres) {
    desc << " They are famous for their precise engineering.";
  } else if(precision < -notethres) {
    desc << " They are infamous for sloppy quality control standards.";
  }
  if(alcohol_use > notethres) {
    desc << " Drink plays a major role in their culture.";
  } else if(alcohol_use < -notethres) {
    desc << " They have a strong dislike of alcohol.";
  }
  if(tobacco_use > notethres) {
    desc << " They have a long history of smoking.";
  } else if(tobacco_use < -notethres) {
    desc << " They have an extreme aversion to smoking.";
  }
  if(stimulant_use > notethres) {
    desc << " They rely heavily on stimulants to get through the working day.";
  } else if(stimulant_use < -notethres) {
    desc << " They distrust all stimulants.";
  }
  if(drug_use > notethres) {
    desc << " Drug use is prevalent in this culture.";
  } else if(drug_use < -notethres) {
    desc << " Drug use is highly frowned upon in this culture.";
  }
  desc << std::endl;
  desc << "Notable inventions include: " << std::endl;

  if(invented_ftl) {
    desc << "* faster than light travel" << std::endl;
  }
  if(invented_coldsleep) {
    desc << "* human cryogenics" << std::endl;
  }
  if(invented_cloaking) {
    desc << "* cloaking devices" << std::endl;
  }
  if(invented_forcefields) {
    desc << "* forcefields" << std::endl;
  }
  if(invented_antimatter) {
    desc << "* harnessing of antimatter" << std::endl;
  }
  if(invented_singularities) {
    desc << "* harnessing of singularities" << std::endl;
  }
  if(invented_tractorbeams) {
    desc << "* tractor beams" << std::endl;
  }
  if(invented_holograms) {
    desc << "* tangible holograms" << std::endl;
  }
  if(invented_androids) {
    desc << "* artificially intelligent androids" << std::endl;
  }
  if(invented_cloning) {
    desc << "* rapid-gestation human cloning" << std::endl;
  }
  if(invented_teleportation) {
    desc << "* teleportation" << std::endl;
  }
  if(invented_replicator) {
    desc << "* molecular nano-reassembly" << std::endl;
  }

  if(!alcohol_legal) {
    desc << "Alcohol has been outlawed. ";
  }
  if(tobacco_legal) {
    desc << "Unusually, smoking is permitted aboard ship. ";
  }
  if(!stimulants_legal) {
    desc << "The use of all stimulants has been outlawed. ";
  }
  if(drugs_legal) {
    desc << "Controversially, all narcotic drugs are permitted aboard ship. ";
  }
  if(!uniform_mandatory) {
    desc << "Uniform is optional for crew aboard ship. ";
  }

  if(deathpenalty) {
    desc << "Severe crimes merit the death penalty. ";
  }

  /*std::cout << "DEBUG:" <<
    std::endl << "intelligence    " << (int)intelligence <<
    std::endl << "strength        " << (int)strength <<
    std::endl << "homogeneity     " << (int)homogeneity <<
    std::endl << "stressability   " << (int)stressability <<
    std::endl << "liberalism      " << (int)liberalism <<
    std::endl << "hierarchicality " << (int)hierarchicality <<
    std::endl << "discipline      " << (int)discipline <<
    std::endl << "selfishness     " << (int)selfishness <<
    std::endl << "generosity      " << (int)generosity <<
    std::endl << "honesty         " << (int)honesty <<
    std::endl << "sociability     " << (int)sociability <<
    std::endl << "geekiness       " << (int)geekiness <<
    std::endl << "physicality     " << (int)physicality <<
    std::endl << "mercantility    " << (int)mercantility <<
    std::endl << "artisticness    " << (int)artisticness <<
    std::endl << "religiousness   " << (int)religiousness <<
    std::endl << "fashion         " << (int)fashion <<
    std::endl << "treachery       " << (int)treachery <<
    std::endl << "belligirence    " << (int)belligirence <<
    std::endl << "ruthlessness    " << (int)ruthlessness <<
    std::endl << "vangefulness    " << (int)vangefulness <<
    std::endl << "cowardice       " << (int)cowardice <<
    std::endl << "laziness        " << (int)laziness <<
    std::endl << "alcohol_use     " << (int)alcohol_use <<
    std::endl << "tobacco_use     " << (int)tobacco_use <<
    std::endl << "stimulant_use   " << (int)stimulant_use <<
    std::endl << "drug_use        " << (int)drug_use << std::endl;*/

  return desc.str();
}
