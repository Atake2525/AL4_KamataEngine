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
	movePhase();
	//worldTransform_.translation_ -= velocity_;
	worldTransform_.UpdateMatirx();
}

void Enemy::movePhase() {
	switch (phase_) {
	case Phase::Approach:
	default:
		// 移動(ベクトルを加算)
		worldTransform_.translation_ += ApproachVelocity;
		if (worldTransform_.translation_.z < 0.0f) {
			phase_ = Phase::Leave;
		}
		break;
	case Phase::Leave:
		// 移動(ベクトルを加算)
		worldTransform_.translation_ += LeaveVelocity;
		break;
	}
}

void Enemy::Draw(Camera& camera) { model_->Draw(worldTransform_, camera, textureHandle_); }