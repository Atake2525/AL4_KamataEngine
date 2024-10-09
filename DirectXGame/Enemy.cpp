#include "Enemy.h"
#include <cassert>

using namespace KamataEngine;

void Enemy::Initialize(Model* model, const Vector3& position) { 
	assert(model);
	model_ = model;

	textureHandle_ = TextureManager::Load("uvChecker.png");
	
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
}

void Enemy::Update() { 
	worldTransform_.translation_ -= velocity_;
	worldTransform_.UpdateMatirx();
}

void Enemy::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, textureHandle_); }