#include "stdafx.h"

#include <iostream>

#include "ootzAStar/ootzAStar.hpp"
using namespace ootz;

int main()
{
    GridGraph graph(10, 10, 1.0f, Vector3::Zero());
    //graph.GetNearestNode(Vector3(0.0f, 0.3f, 0.5f));
    cout << graph.GetNearestNode(Vector3(-0.4f, -0.5f, -0.6f));

    system("pause");
    return 0;
}

