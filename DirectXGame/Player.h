#pragma once
#include "3d/WorldTransform.h"
//#include <base\WinApp.h>
#include "3d/Camera.h"
#include "3d/Model.h"
#include <3d\ObjectColor.h>
#include <input\Input.h>
#include <math\Vector3.h>
#include "kMath.h"
#include "PlayerBullet.h"
#include <list>

class PlayerBullet;

class Player {
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();
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
	void Draw(KamataEngine::Camera& camera);

private:
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera* camera_ = nullptr;
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::ObjectColor objectColor_;

	void Move();
	void wolk();
	void Rotate();


	// キャラクターの速さ
	const float kCharacterSpeed = 0.2f;
	// 移動限界座標
	const float kMoveLimitX = 35.0f;
	const float kMoveLimitY = 19.0f;

	/// キャラクターの回転
	// 回転の速さ[ラジアン/frame]
	const float kRotSpeed = 0.2f;

	// 弾
	std::list<PlayerBullet*> bullets_;
	void Attack();

};
