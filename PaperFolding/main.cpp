
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "display.h"
#include "displayphysics.h"
//#include "displayreplay.hpp"
//#include "displaytesting.hpp"
//#include "misc.hpp"s
//#include "io.hpp"
#include "runphysics.h"


using namespace std;

// implement this anywhere in any .cpp file
//extern void debug(const vector<string>& args);

int main(int argc, char** argv) {

    struct Action {
        string name;
        void (*run) (const vector<string>& args);
    } actions[] = {
        {"simulate", display_physics},
        //{"simulateoffline", run_physics},
        {"resume", display_resume}
        //{"resumeoffline", resume_physics},
        //{"replay", display_replay},
        //{"merge", merge_meshes},
        //{"split", split_meshes},
        //{"test", display_testing},
        //{"tri2obj", tri2obj},
        //{"debug", debug}
    };

    int nactions = sizeof(actions) / sizeof(Action);

    string name = (argc <= 1) ? "" : argv[1];
    vector<string> args;
    for (int a = 2; a < argc; a++)
        args.push_back(argv[a]);
    for (int i = 0; i < nactions; i++) {
        if (name == actions[i].name) {
            actions[i].run(args);
            exit(EXIT_SUCCESS);
        }
    }

    cout << "Usage: " << endl;
    cout << "    " << argv[0] << " <command> [<args>]" << endl;
    cout << "where <command> is one of" << endl;
    for (int i = 0; i < nactions; i++)
        cout << "    " << actions[i].name << endl;
    cout << endl;
    cout << "Run '" << argv[0] << " <command>' without extra arguments ";
    cout << "to get more information about a particular command." << endl;
    exit(EXIT_FAILURE);
}
