// Camera.cpp
// Created by Haony 2023/4/1

#include "Camera.h"
#include "Engine.h"
#include "Setting.h"
#include "Timer.h"
#include "KeyBoard.h"
#include "Mouse.h"
#include <DirectXMath.h>
#include "XMath.h"

namespace XRender
{

Camera::Camera(XRenderEngine* engine)
	: mEngine(engine),mPosition(),mDirection(),mUp(),mRight(),
	mFOV(DirectX::XM_PIDIV2), mAspectRatio(1.7f),mNearPlaneDist(0.01f),mFarPlaneDist(1000.f),
	mViewMatrix(), mProjMatrix(),mRotateMatrix(),
	mKeyBoard(engine->GetKeyBoard()),mMouse(engine->GetMouse())
{
	mPosition = Setting::CameraPosition;
	mDirection = Setting::CameraDirection;
	mUp = Setting::CameraUp;
	mRight = Setting::CameraRight;

	mFOV = Setting::CameraFOV;
	mAspectRatio = Setting::CameraAspectRatio;
	mNearPlaneDist = Setting::CameraNearPlaneDist;
	mFarPlaneDist = Setting::CameraFarPlaneDist;

	mMouseSensitivity = Setting::CameraMouseSensitivity;
	mMovementRate = Setting::CameraMovementRate;
	mRotationRate = Setting::CameraRotationRate;
}

Camera::~Camera()
{

}

bool Camera::Init()
{
	UpdateViewMatrix();
	UpdateProjMatrix();

	return true;
}

void Camera::Update()
{
	UpdateViewMatrix();
	UpdateProjMatrix();
}

void Camera::UpdateViewMatrix()
{
	DirectX::XMVECTOR position = ToDXVector3(mPosition);
	DirectX::XMVECTOR direction = ToDXVector3(mDirection);
	DirectX::XMVECTOR up = ToDXVector3(mUp);

	mViewMatrix = DirectX::XMMatrixLookToRH(position, direction, up);
}

void Camera::UpdateProjMatrix()
{
	// process keyboard movement
	Vector3f movement(0.0f);
	if (mKeyBoard)
	{
		if (mKeyBoard->CurrentKeyDown(DIK_A))
		{
			movement.x = -1.0f;
		}
		if (mKeyBoard->CurrentKeyDown(DIK_D))
		{
			movement.x = 1.0f;
		}
		if (mKeyBoard->CurrentKeyDown(DIK_W))
		{
			movement.y = 1.0f;
		}
		if (mKeyBoard->CurrentKeyDown(DIK_S))
		{
			movement.y = -1.0f;
		}
		if (mKeyBoard->CurrentKeyDown(DIK_Q))
		{
			movement.z = -1.0f;
		}
		if (mKeyBoard->CurrentKeyDown(DIK_E))
		{
			movement.z = 1.0f;
		}
	}

	// process mouse rotation
	Vector2f rotation(0);
	if (mMouse)
	{
		if (mMouse->IsButtonHold(MouseButtonsRight))
		{
			auto state = mMouse->GetCurrentState();
			rotation.x = -state->lX * mMouseSensitivity;
			rotation.y = -state->lY * mMouseSensitivity;
		}
	}

	auto* timer = mEngine->GetTimer();
	float elapsedTime = static_cast<float>(timer->ElapsedTime());

	// movement
	Vector3f moveVec = movement * mMovementRate * elapsedTime;
	mPosition += (mRight * moveVec.x + mDirection * moveVec.y + mUp * moveVec.z);

	// rotation
	Vector2f rotateVec = rotation * mRotationRate * elapsedTime;

	DirectX::XMMATRIX pitch = DirectX::XMMatrixRotationAxis(ToDXVector3(mRight), rotateVec.x);
	DirectX::XMMATRIX yaw = DirectX::XMMatrixRotationY(rotateVec.y);
	DirectX::XMMATRIX transRotate = DirectX::XMMatrixMultiply(pitch, yaw);

	SetRotationMatrix(transRotate);

	mProjMatrix = DirectX::XMMatrixPerspectiveFovRH(mFOV, mAspectRatio, mNearPlaneDist, mFarPlaneDist);
}

void Camera::SetRotationMatrix(const DirectX::XMMATRIX& matrix)
{
	DirectX::XMVECTOR direction = ToDXVector3(mDirection);
	DirectX::XMVECTOR up = ToDXVector3(mUp);

	direction = DirectX::XMVector3TransformNormal(direction, matrix);
	direction = DirectX::XMVector3Normalize(direction);

	up = DirectX::XMVector3TransformNormal(up, matrix);
	up = DirectX::XMVector3Normalize(up);

	DirectX::XMVECTOR right = DirectX::XMVector3Cross(direction, up);
	up = DirectX::XMVector3Cross(right, direction);

	mDirection = ToVector3(direction);
	mUp = ToVector3(up);
	mRight = ToVector3(right);

	mRotateMatrix = matrix;
}

}