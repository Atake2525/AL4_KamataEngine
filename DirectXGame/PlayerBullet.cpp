#include "PlayerBullet.h"
#include <cassert>

using namespace KamataEngine;

void PlayerBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity) { 
	// NULLポインタチェック
	assert(model);

	model_ = model;
	// テクスチャ読み込み
	textureHandle_ = TextureManager::Load("uvChecker.png");

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	velocity_ = velocity;
}

void PlayerBullet::Update() { 
	worldTransform_.translation_ += velocity_;
	// 時間経過で消滅(デス)
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
	worldTransform_.UpdateMatirx();
	worldTransform_.TransferMatrix();
}

void PlayerBullet::Draw(const Camera& camera) { model_->Draw(worldTransform_, camera, textureHandle_); }


