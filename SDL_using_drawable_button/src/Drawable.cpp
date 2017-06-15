
#include "Drawable.h"


Drawable::Drawable(int x, int y) {
	setPosition(x, y);
	rect.w = 0;
	rect.h = 0;
	mTexture = NULL;
}

Drawable::~Drawable() {
	free();
}

int Drawable::getHeight() const {
	return rect.h;
}

void Drawable::setHeight(int height) {
	this->rect.h = height;
}

int Drawable::getWidth() const {
	return rect.w;
}

void Drawable::setWidth(int width) {
	this->rect.w = width;
}

int Drawable::getX() const {
	return rect.x;
}

int Drawable::getY() const {
	return rect.y;
}

void Drawable::draw(SDL_Renderer* gRenderer, double angle, SDL_RendererFlip flip) {
	if (mTexture) {
		SDL_RenderCopyEx(gRenderer, mTexture, NULL, &rect,angle,NULL, flip);
	}
}

void Drawable::free() {
	if (mTexture) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}


bool Drawable::loadFromFile(SDL_Renderer* gRenderer, std::string path) {
	if (path != "") {
		SDL_Surface * loadedSurface = IMG_Load(path.data());
		mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		this->setWidth(loadedSurface->w);
		this->setHeight(loadedSurface->h);
		SDL_FreeSurface(loadedSurface);
		loadedSurface = NULL;
	}
	return mTexture != NULL;
}

void Drawable::setPosition(int x, int y) {
	this->rect.x = x;
	this->rect.y = y;
}





