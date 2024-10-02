#pragma once
#include "3d/WorldTransform.h"
#include "3d/Camera.h"
#include "3d/Model.h"
#include <3d\ObjectColor.h>

class Player {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera);
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera* camera_ = nullptr;
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::ObjectColor objectColor_;
};
