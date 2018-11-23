#include "BsScriptParticleEmitter.generated.h"
#include "BsMonoMethod.h"
#include "BsMonoClass.h"
#include "BsMonoUtil.h"
#include "../../../bsf/Source/Foundation/bsfCore/Particles/BsParticleEmitter.h"
#include "BsScriptParticleEmitterShape.generated.h"
#include "BsScriptParticleBurst.generated.h"
#include "BsScriptTDistribution.generated.h"
#include "BsScriptTDistribution.generated.h"
#include "BsScriptColorDistribution.generated.h"

namespace bs
{
	ScriptParticleEmitter::ScriptParticleEmitter(MonoObject* managedInstance, const SPtr<ParticleEmitter>& value)
		:ScriptObject(managedInstance), mInternal(value)
	{
	}

	void ScriptParticleEmitter::initRuntimeData()
	{
		metaData.scriptClass->addInternalCall("Internal_setShape", (void*)&ScriptParticleEmitter::Internal_setShape);
		metaData.scriptClass->addInternalCall("Internal_getShape", (void*)&ScriptParticleEmitter::Internal_getShape);
		metaData.scriptClass->addInternalCall("Internal_setEmissionRate", (void*)&ScriptParticleEmitter::Internal_setEmissionRate);
		metaData.scriptClass->addInternalCall("Internal_getEmissionRate", (void*)&ScriptParticleEmitter::Internal_getEmissionRate);
		metaData.scriptClass->addInternalCall("Internal_setEmissionBursts", (void*)&ScriptParticleEmitter::Internal_setEmissionBursts);
		metaData.scriptClass->addInternalCall("Internal_getEmissionBursts", (void*)&ScriptParticleEmitter::Internal_getEmissionBursts);
		metaData.scriptClass->addInternalCall("Internal_setInitialLifetime", (void*)&ScriptParticleEmitter::Internal_setInitialLifetime);
		metaData.scriptClass->addInternalCall("Internal_getInitialLifetime", (void*)&ScriptParticleEmitter::Internal_getInitialLifetime);
		metaData.scriptClass->addInternalCall("Internal_setInitialSpeed", (void*)&ScriptParticleEmitter::Internal_setInitialSpeed);
		metaData.scriptClass->addInternalCall("Internal_getInitialSpeed", (void*)&ScriptParticleEmitter::Internal_getInitialSpeed);
		metaData.scriptClass->addInternalCall("Internal_setInitialSize", (void*)&ScriptParticleEmitter::Internal_setInitialSize);
		metaData.scriptClass->addInternalCall("Internal_getInitialSize", (void*)&ScriptParticleEmitter::Internal_getInitialSize);
		metaData.scriptClass->addInternalCall("Internal_setInitialSize3D", (void*)&ScriptParticleEmitter::Internal_setInitialSize3D);
		metaData.scriptClass->addInternalCall("Internal_getInitialSize3D", (void*)&ScriptParticleEmitter::Internal_getInitialSize3D);
		metaData.scriptClass->addInternalCall("Internal_setUse3DSize", (void*)&ScriptParticleEmitter::Internal_setUse3DSize);
		metaData.scriptClass->addInternalCall("Internal_getUse3DSize", (void*)&ScriptParticleEmitter::Internal_getUse3DSize);
		metaData.scriptClass->addInternalCall("Internal_setInitialRotation", (void*)&ScriptParticleEmitter::Internal_setInitialRotation);
		metaData.scriptClass->addInternalCall("Internal_getInitialRotation", (void*)&ScriptParticleEmitter::Internal_getInitialRotation);
		metaData.scriptClass->addInternalCall("Internal_setInitialRotation3D", (void*)&ScriptParticleEmitter::Internal_setInitialRotation3D);
		metaData.scriptClass->addInternalCall("Internal_getInitialRotation3D", (void*)&ScriptParticleEmitter::Internal_getInitialRotation3D);
		metaData.scriptClass->addInternalCall("Internal_setUse3DRotation", (void*)&ScriptParticleEmitter::Internal_setUse3DRotation);
		metaData.scriptClass->addInternalCall("Internal_getUse3DRotation", (void*)&ScriptParticleEmitter::Internal_getUse3DRotation);
		metaData.scriptClass->addInternalCall("Internal_setInitialColor", (void*)&ScriptParticleEmitter::Internal_setInitialColor);
		metaData.scriptClass->addInternalCall("Internal_getInitialColor", (void*)&ScriptParticleEmitter::Internal_getInitialColor);
		metaData.scriptClass->addInternalCall("Internal_setRandomOffset", (void*)&ScriptParticleEmitter::Internal_setRandomOffset);
		metaData.scriptClass->addInternalCall("Internal_getRandomOffset", (void*)&ScriptParticleEmitter::Internal_getRandomOffset);
		metaData.scriptClass->addInternalCall("Internal_setFlipU", (void*)&ScriptParticleEmitter::Internal_setFlipU);
		metaData.scriptClass->addInternalCall("Internal_getFlipU", (void*)&ScriptParticleEmitter::Internal_getFlipU);
		metaData.scriptClass->addInternalCall("Internal_setFlipV", (void*)&ScriptParticleEmitter::Internal_setFlipV);
		metaData.scriptClass->addInternalCall("Internal_getFlipV", (void*)&ScriptParticleEmitter::Internal_getFlipV);

	}

	MonoObject* ScriptParticleEmitter::create(const SPtr<ParticleEmitter>& value)
	{
		if(value == nullptr) return nullptr; 

		bool dummy = false;
		void* ctorParams[1] = { &dummy };

		MonoObject* managedInstance = metaData.scriptClass->createInstance("bool", ctorParams);
		new (bs_alloc<ScriptParticleEmitter>()) ScriptParticleEmitter(managedInstance, value);
		return managedInstance;
	}
	void ScriptParticleEmitter::Internal_setShape(ScriptParticleEmitter* thisPtr, MonoObject* shape)
	{
		SPtr<ParticleEmitterShape> tmpshape;
		ScriptParticleEmitterShapeBase* scriptshape;
		scriptshape = (ScriptParticleEmitterShapeBase*)ScriptParticleEmitterShape::toNative(shape);
		tmpshape = scriptshape->getInternal();
		thisPtr->getInternal()->setShape(tmpshape);
	}

	MonoObject* ScriptParticleEmitter::Internal_getShape(ScriptParticleEmitter* thisPtr)
	{
		SPtr<ParticleEmitterShape> tmp__output;
		*tmp__output = *thisPtr->getInternal()->getShape();

		MonoObject* __output;
		__output = ScriptParticleEmitterShape::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setEmissionRate(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<TDistribution<float>> tmpvalue;
		ScriptTDistributionfloat* scriptvalue;
		scriptvalue = ScriptTDistributionfloat::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setEmissionRate(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getEmissionRate(ScriptParticleEmitter* thisPtr)
	{
		SPtr<TDistribution<float>> tmp__output = bs_shared_ptr_new<TDistribution<float>>();
		*tmp__output = thisPtr->getInternal()->getEmissionRate();

		MonoObject* __output;
		__output = ScriptTDistributionfloat::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setEmissionBursts(ScriptParticleEmitter* thisPtr, MonoArray* bursts)
	{
		Vector<ParticleBurst> vecbursts;
		if(bursts != nullptr)
		{
			ScriptArray arraybursts(bursts);
			vecbursts.resize(arraybursts.size());
			for(int i = 0; i < (int)arraybursts.size(); i++)
			{
				vecbursts[i] = ScriptParticleBurst::fromInterop(arraybursts.get<__ParticleBurstInterop>(i));
			}
		}
		thisPtr->getInternal()->setEmissionBursts(vecbursts);
	}

	MonoArray* ScriptParticleEmitter::Internal_getEmissionBursts(ScriptParticleEmitter* thisPtr)
	{
		Vector<ParticleBurst> vec__output;
		vec__output = thisPtr->getInternal()->getEmissionBursts();

		MonoArray* __output;
		int arraySize__output = (int)vec__output.size();
		ScriptArray array__output = ScriptArray::create<ScriptParticleBurst>(arraySize__output);
		for(int i = 0; i < arraySize__output; i++)
		{
			array__output.set(i, ScriptParticleBurst::toInterop(vec__output[i]));
		}
		__output = array__output.getInternal();

		return __output;
	}

	void ScriptParticleEmitter::Internal_setInitialLifetime(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<TDistribution<float>> tmpvalue;
		ScriptTDistributionfloat* scriptvalue;
		scriptvalue = ScriptTDistributionfloat::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setInitialLifetime(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getInitialLifetime(ScriptParticleEmitter* thisPtr)
	{
		SPtr<TDistribution<float>> tmp__output = bs_shared_ptr_new<TDistribution<float>>();
		*tmp__output = thisPtr->getInternal()->getInitialLifetime();

		MonoObject* __output;
		__output = ScriptTDistributionfloat::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setInitialSpeed(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<TDistribution<float>> tmpvalue;
		ScriptTDistributionfloat* scriptvalue;
		scriptvalue = ScriptTDistributionfloat::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setInitialSpeed(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getInitialSpeed(ScriptParticleEmitter* thisPtr)
	{
		SPtr<TDistribution<float>> tmp__output = bs_shared_ptr_new<TDistribution<float>>();
		*tmp__output = thisPtr->getInternal()->getInitialSpeed();

		MonoObject* __output;
		__output = ScriptTDistributionfloat::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setInitialSize(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<TDistribution<float>> tmpvalue;
		ScriptTDistributionfloat* scriptvalue;
		scriptvalue = ScriptTDistributionfloat::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setInitialSize(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getInitialSize(ScriptParticleEmitter* thisPtr)
	{
		SPtr<TDistribution<float>> tmp__output = bs_shared_ptr_new<TDistribution<float>>();
		*tmp__output = thisPtr->getInternal()->getInitialSize();

		MonoObject* __output;
		__output = ScriptTDistributionfloat::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setInitialSize3D(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<TDistribution<Vector3>> tmpvalue;
		ScriptTDistributionVector3* scriptvalue;
		scriptvalue = ScriptTDistributionVector3::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setInitialSize3D(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getInitialSize3D(ScriptParticleEmitter* thisPtr)
	{
		SPtr<TDistribution<Vector3>> tmp__output = bs_shared_ptr_new<TDistribution<Vector3>>();
		*tmp__output = thisPtr->getInternal()->getInitialSize3D();

		MonoObject* __output;
		__output = ScriptTDistributionVector3::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setUse3DSize(ScriptParticleEmitter* thisPtr, bool value)
	{
		thisPtr->getInternal()->setUse3DSize(value);
	}

	bool ScriptParticleEmitter::Internal_getUse3DSize(ScriptParticleEmitter* thisPtr)
	{
		bool tmp__output;
		tmp__output = thisPtr->getInternal()->getUse3DSize();

		bool __output;
		__output = tmp__output;

		return __output;
	}

	void ScriptParticleEmitter::Internal_setInitialRotation(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<TDistribution<float>> tmpvalue;
		ScriptTDistributionfloat* scriptvalue;
		scriptvalue = ScriptTDistributionfloat::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setInitialRotation(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getInitialRotation(ScriptParticleEmitter* thisPtr)
	{
		SPtr<TDistribution<float>> tmp__output = bs_shared_ptr_new<TDistribution<float>>();
		*tmp__output = thisPtr->getInternal()->getInitialRotation();

		MonoObject* __output;
		__output = ScriptTDistributionfloat::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setInitialRotation3D(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<TDistribution<Vector3>> tmpvalue;
		ScriptTDistributionVector3* scriptvalue;
		scriptvalue = ScriptTDistributionVector3::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setInitialRotation3D(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getInitialRotation3D(ScriptParticleEmitter* thisPtr)
	{
		SPtr<TDistribution<Vector3>> tmp__output = bs_shared_ptr_new<TDistribution<Vector3>>();
		*tmp__output = thisPtr->getInternal()->getInitialRotation3D();

		MonoObject* __output;
		__output = ScriptTDistributionVector3::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setUse3DRotation(ScriptParticleEmitter* thisPtr, bool value)
	{
		thisPtr->getInternal()->setUse3DRotation(value);
	}

	bool ScriptParticleEmitter::Internal_getUse3DRotation(ScriptParticleEmitter* thisPtr)
	{
		bool tmp__output;
		tmp__output = thisPtr->getInternal()->getUse3DRotation();

		bool __output;
		__output = tmp__output;

		return __output;
	}

	void ScriptParticleEmitter::Internal_setInitialColor(ScriptParticleEmitter* thisPtr, MonoObject* value)
	{
		SPtr<ColorDistribution> tmpvalue;
		ScriptColorDistribution* scriptvalue;
		scriptvalue = ScriptColorDistribution::toNative(value);
		tmpvalue = scriptvalue->getInternal();
		thisPtr->getInternal()->setInitialColor(*tmpvalue);
	}

	MonoObject* ScriptParticleEmitter::Internal_getInitialColor(ScriptParticleEmitter* thisPtr)
	{
		SPtr<ColorDistribution> tmp__output = bs_shared_ptr_new<ColorDistribution>();
		*tmp__output = thisPtr->getInternal()->getInitialColor();

		MonoObject* __output;
		__output = ScriptColorDistribution::create(tmp__output);

		return __output;
	}

	void ScriptParticleEmitter::Internal_setRandomOffset(ScriptParticleEmitter* thisPtr, float value)
	{
		thisPtr->getInternal()->setRandomOffset(value);
	}

	float ScriptParticleEmitter::Internal_getRandomOffset(ScriptParticleEmitter* thisPtr)
	{
		float tmp__output;
		tmp__output = thisPtr->getInternal()->getRandomOffset();

		float __output;
		__output = tmp__output;

		return __output;
	}

	void ScriptParticleEmitter::Internal_setFlipU(ScriptParticleEmitter* thisPtr, float value)
	{
		thisPtr->getInternal()->setFlipU(value);
	}

	float ScriptParticleEmitter::Internal_getFlipU(ScriptParticleEmitter* thisPtr)
	{
		float tmp__output;
		tmp__output = thisPtr->getInternal()->getFlipU();

		float __output;
		__output = tmp__output;

		return __output;
	}

	void ScriptParticleEmitter::Internal_setFlipV(ScriptParticleEmitter* thisPtr, float value)
	{
		thisPtr->getInternal()->setFlipV(value);
	}

	float ScriptParticleEmitter::Internal_getFlipV(ScriptParticleEmitter* thisPtr)
	{
		float tmp__output;
		tmp__output = thisPtr->getInternal()->getFlipV();

		float __output;
		__output = tmp__output;

		return __output;
	}
}