//
// Created by Marine on 09/05/2022.
//

#pragma once
#include "../Abstract/Component.h"

class ASCIIRenderer : public Component {
public:

	ASCIIRenderer(char, int);
	char getAsciiValue() const;
	void setAsciiValue(char);

	int getPriority() const;
	void setPriority(int);

	void Start() override;

	void Update() override;

	void FixedUpdate() override;

	void LateUpdate() override;

	static const int typeHash = 2;

private:
	char asciiValue = 'O';
	int priority = 0;
};
