#include <iostream>

using namespace std;

import window;
import engine;

int main()
{
	init_window();
	init_engine(get_native_window());
	init_pipeline();
	
	while (!window_should_close())
	{
		poll_events();
		render();
		present();
	}

	cleanup_window();
	
	
	return EXIT_SUCCESS;
}
