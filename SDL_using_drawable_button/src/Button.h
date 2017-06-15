
#ifndef BUTTON_H_
#define BUTTON_H_

#include "Drawable.h"


class Button: public Drawable {
public:
	Button(int x = 0, int y = 0);
	virtual bool isClicked(int x, int y);
	virtual ~Button();
private:
};

#endif /* BUTTON_H_ */
