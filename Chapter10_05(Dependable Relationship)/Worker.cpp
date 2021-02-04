#pragma once
#include "Worker.h"
#include "Timer.h"

void Worker::doSomething()
{
	Timer timer;		// start timer

	// Do some work here

	timer.elapsed();	// end timer and report elapsed time
}