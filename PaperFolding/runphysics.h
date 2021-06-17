
#ifndef RUNPHYSICS_HPP
#define RUNPHYSICS_HPP

#include "simulation.h"
#include <string>
#include <vector>

void save(const Simulation& sim, int frame);
void init_physics(const std::string& json_file, std::string outprefix, bool is_reloading);
void init_resume(const std::vector<std::string>& args);
void sim_step();
void run_physics(const std::vector<std::string>& args);
void resume_physics(const std::vector<std::string>& args);

#endif
