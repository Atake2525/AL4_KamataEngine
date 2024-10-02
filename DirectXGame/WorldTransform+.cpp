#include "kMath.h"
#include <math\MathUtility.h>
#include "3d/WorldTransform.h"


void KamataEngine::WorldTransform::UpdateMatirx() {
	// スケール、回転、平行移動を合成して行列を計算する
	KamataEngine::WorldTransform::matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);
	// 変数バッファに転送する
	TransferMatrix();
}