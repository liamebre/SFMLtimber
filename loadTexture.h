#pragma once
#include "inclusions.h"
using namespace sf;
using namespace std;

Texture checktex(sf::Texture tex_,filesystem::path file_) {
    if (!tex_.loadFromFile(file_)) {
        cerr << "Error: Failed to load texture!" << endl;
    }
    else { 
        return tex_; 
    }
}

SoundBuffer checksound(sf::SoundBuffer sound_, filesystem::path file_) {
    if (!sound_.loadFromFile(file_)) {
        cerr << "Error: Failed to load sound!" << endl;
    }
    else {
        return sound_;
    }
}

void renderAll(RenderWindow& window_,Sprite bg_, vector<Sprite> sprites_,vector<Sprite> clouds) {
    window_.clear();
	window_.draw(bg_);
    for (auto& cloud : clouds) {
        window_.draw(cloud);
    }
    for (auto& sprite : sprites_) {
        window_.draw(sprite);
    }
}

Sprite makeCloud(Texture& texturecloud_) {
    Sprite cloud(texturecloud_);
    cloud.setPosition({ float((rand() % 400) - 200), float((rand() % 350)) });
	return cloud;
}
