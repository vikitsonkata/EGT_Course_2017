
#ifndef DRAWABLE_H_
#define DRAWABLE_H_
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <string>
using namespace std;

class Drawable {
public:
	Drawable(int x = 0, int y = 0);
	virtual bool loadFromFile(SDL_Renderer* gRenderer, std::string path);
	virtual ~Drawable();
	virtual void draw(SDL_Renderer*, double = 0, SDL_RendererFlip = SDL_FLIP_NONE);
	virtual void free();
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	int getX() const;
	int getY() const;
	virtual void setPosition(int x, int y);

protected:
	SDL_Texture * mTexture;
	SDL_Rect rect;

};

#endif /* DRAWABLE_H_ */
