#include "Player.h"

void Player::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera) {
	model_ = model;
	worldTransform_.Initialize();
	objectColor_.Initialize();
	camera_ = camera;
}

void Player::Update() {

}

void Player::Draw() { model_->Draw(worldTransform_, *camera_, &objectColor_); }