#include "Enemy.h"
#include <cassert>

using namespace KamataEngine;

Enemy::~Enemy() {
	for (EnemyBullet* bullet : bullets_) {
		delete bullet;
	}
}

void Enemy::Initialize(Model* model, const Vector3& position) { 
	assert(model);
	model_ = model;

	textureHandle_ = TextureManager::Load("uvChecker.png");
	
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	Fire();
}

void Enemy::Update() { 
	// デスフラグの立った弾を削除
	bullets_.remove_if([](EnemyBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});
	for (EnemyBullet* bullet : bullets_) {
		bullet->Update();
	}
	movePhase();
	//worldTransform_.translation_ -= velocity_;
	worldTransform_.UpdateMatirx();
}

void Enemy::Fire() {
	// 弾の速度
	const float kBulletSpeed = -1.0f;
	Vector3 velocity(0, 0, kBulletSpeed);

	// 速度ベクトルを自機の向きに合わせて回転させる
	velocity = TransformNormal(velocity, worldTransform_.matWorld_);

	// 弾を生成し、初期化
	EnemyBullet* newBullet = new EnemyBullet();
	newBullet->Initialize(model_, worldTransform_.translation_, velocity);

	// 弾を登録する
	bullets_.push_back(newBullet);
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

void Enemy::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera, textureHandle_); 
	for (EnemyBullet* bullet : bullets_) {
		bullet->Draw(camera);
	}
}