#include "PlayerBullet.h"
#include <cassert>

using namespace KamataEngine;

void PlayerBullet::Initialize(Model* model, const Vector3& position) { 
	// NULLポインタチェック
	assert(model);

	model_ = model;
	// テクスチャ読み込み
	textureHandle_ = TextureManager::Load("uvChecker.png");

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
}

void PlayerBullet::Update() { 
	worldTransform_.UpdateMatirx();
	worldTransform_.TransferMatrix();
}

void PlayerBullet::Draw(const Camera& camera) { model_->Draw(worldTransform_, camera, textureHandle_); }


