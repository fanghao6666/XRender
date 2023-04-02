// Camera.cpp
// Created by Haony 2023/4/1

#include "Component.h"
#include <DirectXMath.h>
#include "XMath.h"

namespace XRender
{
	class XRenderEngine;
	class KeyBoard;
	class Mouse;

	class Camera : public Component
	{
	public:
		Camera(XRenderEngine* engine);
		virtual ~Camera();

		
		virtual bool			Init() override;
		virtual void			Update() override;

		void					UpdateViewMatrix();
		void					UpdateProjMatrix();
	public:
		void					SetPosition(const Vector3f& position) { mPosition = position; }
		void					SetDirection(const Vector3f& direction) { mDirection = direction; }
		void					SetUp(const Vector3f& up) { mUp = up; }
		void					SetRight(const Vector3f& right) { mRight = right; }
		void					SetFov(float fov) { mFOV = fov; }
		void					SetAspectRation(float ratio) { mAspectRatio = ratio; }
		void					SetNearPlaneDist(float distance) { mNearPlaneDist = distance; }
		void					SetFarPlaneDist(float distance) { mFarPlaneDist = distance; }
		void					SetRotationMatrix(const DirectX::XMMATRIX& matrix);

		void					SetMouseSensitivity(float sensitivity) { mMouseSensitivity = sensitivity; }
		void					SetMovementRate(float rate) { mMovementRate = rate; }
		void					SetRotationRate(float rate) { mRotationRate = rate; }

		Vector3f				GetPosition() const { return mPosition; }
		Vector3f				GetDirection() const { return mDirection; }
		Vector3f				GetUp() const { return mUp; }
		Vector3f				GetRight() const { return mRight; }
		float					GetFov() const { return mFOV; }
		float					GetAspectRation() const { return mAspectRatio; }
		float					GetNearPlaneDist() const { return mNearPlaneDist; }
		float					GetFarPlaneDist() const { return mFarPlaneDist; }
		DirectX::XMMATRIX		GetViewMatrix() const { return mViewMatrix; }
		DirectX::XMMATRIX		GetProjMatrix() const { return mProjMatrix; }
		DirectX::XMMATRIX		GetRotateMatrix() const { return mRotateMatrix; }

	private:
		XRenderEngine*			mEngine;

		Vector3f				mPosition;
		Vector3f				mDirection;
		Vector3f				mUp;
		Vector3f				mRight;

		DirectX::XMMATRIX		mViewMatrix;
		DirectX::XMMATRIX		mProjMatrix;
		DirectX::XMMATRIX		mRotateMatrix;

		float					mFOV;
		float					mAspectRatio;
		float					mNearPlaneDist;
		float					mFarPlaneDist;

	private:
		KeyBoard*				mKeyBoard;
		Mouse*					mMouse;
		float					mMouseSensitivity;
		float					mMovementRate;
		float					mRotationRate;
	};

}