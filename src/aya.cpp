import window;
import engine;

int main()
{
	init_window();
	int width, height;
	get_window_size(width, height);
	init_engine(get_native_window(), width, height);
	init_pipeline();
	
	while (!window_should_close())
	{
		poll_events();
		render();
		render_gui();
		present();
	}

	cleanup_engine();
	cleanup_window();

	
	
	return 0;
}
