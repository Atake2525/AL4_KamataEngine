#include "EnemyBullet.h"
#include <cassert>

using namespace KamataEngine;

void EnemyBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity) { 
	// NULLポインタチェック
	assert(model);

	model_ = model;
	// 色の変更
	objectColor_.Initialize();
	objectColor_.SetColor(Vector4{1.0f, 0.0f, 0.0f, 1.0f});

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	velocity_ = velocity;
}

void EnemyBullet::Update() {
	worldTransform_.translation_ += velocity_;
	// 時間経過で消滅(デス)
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
	worldTransform_.UpdateMatirx();
	worldTransform_.TransferMatrix();
}

void EnemyBullet::Draw(const Camera& camera) { model_->Draw(worldTransform_, camera, &objectColor_); }