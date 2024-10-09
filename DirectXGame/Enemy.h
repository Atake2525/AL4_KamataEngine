#pragma once
#include "3d/WorldTransform.h"
#include "3d/Camera.h"
#include "3d/Model.h"
#include "math/MathUtility.h"
#include "kMath.h"
#include "base/TextureManager.h"

// 行動フェーズ
enum class Phase {
	Approach, // 接近する
	Leave,    // 離脱する
};

class Enemy {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& position);
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw(KamataEngine::Camera& camera);

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;

	uint32_t textureHandle_;

	// 移動速度
	KamataEngine::Vector3 velocity_ = {0.0f, 0.0f, 0.02f};


	// 行動
	void movePhase();
	Phase phase_ = Phase::Approach;
	KamataEngine::Vector3 ApproachVelocity = {0.0f, 0.0f, -0.02f};
	KamataEngine::Vector3 LeaveVelocity = {-0.1f, 0.05f, 0.02f};
};
