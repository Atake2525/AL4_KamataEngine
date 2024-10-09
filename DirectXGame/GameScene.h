#pragma once

#include "3d/WorldTransform.h"
#include "audio/Audio.h"
#include <base\DirectXCommon.h>
#include <input\Input.h>
#include "3d/Model.h"
#include "2d/Sprite.h"
#include "3d/Camera.h"
#include "3d/WorldTransform.h"
#include <math\MathUtility.h>
#include <math\Matrix4x4.h>
#include <math\Vector3.h>
#include <math\Vector4.h>
#include <cmath>
#include "3d/DebugCamera.h"
#include "Player.h"
#include "Enemy.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	// デバッグカメラ
	bool isDebugCameraActive_ = false;
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera camera_;

	Player* player_ = nullptr;
	KamataEngine::Model* ModelPlayer_ = nullptr;

	Enemy* enemy_ = nullptr;
	KamataEngine::Model* ModelEnemy_ = nullptr;


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
