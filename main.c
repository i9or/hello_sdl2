#include <stdbool.h>
#include <SDL.h>

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *window = SDL_CreateWindow(
			"Hello SDL2",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			320,
			240,
			0
			);

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	SDL_SetWindowMouseGrab(window, SDL_TRUE);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, 320, 240);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Event e;
	bool quit = false;

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_KEYDOWN) {
				quit = true;
			}
		}

		// Clear screen with black background
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Set draw color to red
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		// Create a rectangle
		SDL_Rect fillRect = {
			.x = 0,   // X position
			.y = 0,   // Y position
			.w = 320,   // Width
			.h = 240    // Height
		};

		// Render filled red rectangle
		SDL_RenderFillRect(renderer, &fillRect);

		// Update screen
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
