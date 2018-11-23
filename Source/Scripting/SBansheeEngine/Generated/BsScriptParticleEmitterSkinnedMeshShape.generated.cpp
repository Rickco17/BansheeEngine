#include "BsScriptParticleEmitterSkinnedMeshShape.generated.h"
#include "BsMonoMethod.h"
#include "BsMonoClass.h"
#include "BsMonoUtil.h"
#include "../../../bsf/Source/Foundation/bsfCore/Particles/BsParticleEmitter.h"
#include "BsScriptPARTICLE_SKINNED_MESH_SHAPE_DESC.generated.h"
#include "BsScriptParticleEmitterShape.generated.h"

namespace bs
{
	ScriptParticleEmitterSkinnedMeshShape::ScriptParticleEmitterSkinnedMeshShape(MonoObject* managedInstance, const SPtr<ParticleEmitterSkinnedMeshShape>& value)
		:ScriptObject(managedInstance)
	{
		mInternal = value;
	}

	SPtr<ParticleEmitterSkinnedMeshShape> ScriptParticleEmitterSkinnedMeshShape::getInternal() const 
	{
		return std::static_pointer_cast<ParticleEmitterSkinnedMeshShape>(mInternal);
	}

	void ScriptParticleEmitterSkinnedMeshShape::initRuntimeData()
	{
		metaData.scriptClass->addInternalCall("Internal_setOptions", (void*)&ScriptParticleEmitterSkinnedMeshShape::Internal_setOptions);
		metaData.scriptClass->addInternalCall("Internal_getOptions", (void*)&ScriptParticleEmitterSkinnedMeshShape::Internal_getOptions);
		metaData.scriptClass->addInternalCall("Internal_create", (void*)&ScriptParticleEmitterSkinnedMeshShape::Internal_create);

	}

	MonoObject* ScriptParticleEmitterSkinnedMeshShape::create(const SPtr<ParticleEmitterSkinnedMeshShape>& value)
	{
		if(value == nullptr) return nullptr; 

		bool dummy = false;
		void* ctorParams[1] = { &dummy };

		MonoObject* managedInstance = metaData.scriptClass->createInstance("bool", ctorParams);
		new (bs_alloc<ScriptParticleEmitterSkinnedMeshShape>()) ScriptParticleEmitterSkinnedMeshShape(managedInstance, value);
		return managedInstance;
	}
	void ScriptParticleEmitterSkinnedMeshShape::Internal_setOptions(ScriptParticleEmitterSkinnedMeshShape* thisPtr, __PARTICLE_SKINNED_MESH_SHAPE_DESCInterop* options)
	{
		PARTICLE_SKINNED_MESH_SHAPE_DESC tmpoptions;
		tmpoptions = ScriptPARTICLE_SKINNED_MESH_SHAPE_DESC::fromInterop(*options);
		thisPtr->getInternal()->setOptions(tmpoptions);
	}

	void ScriptParticleEmitterSkinnedMeshShape::Internal_getOptions(ScriptParticleEmitterSkinnedMeshShape* thisPtr, __PARTICLE_SKINNED_MESH_SHAPE_DESCInterop* __output)
	{
		PARTICLE_SKINNED_MESH_SHAPE_DESC tmp__output;
		tmp__output = thisPtr->getInternal()->getOptions();

		__PARTICLE_SKINNED_MESH_SHAPE_DESCInterop interop__output;
		interop__output = ScriptPARTICLE_SKINNED_MESH_SHAPE_DESC::toInterop(tmp__output);
		MonoUtil::valueCopy(__output, &interop__output, ScriptPARTICLE_SKINNED_MESH_SHAPE_DESC::getMetaData()->scriptClass->_getInternalClass());
	}

	MonoObject* ScriptParticleEmitterSkinnedMeshShape::Internal_create(__PARTICLE_SKINNED_MESH_SHAPE_DESCInterop* desc)
	{
		SPtr<ParticleEmitterShape> tmp__output;
		PARTICLE_SKINNED_MESH_SHAPE_DESC tmpdesc;
		tmpdesc = ScriptPARTICLE_SKINNED_MESH_SHAPE_DESC::fromInterop(*desc);
		tmp__output = ParticleEmitterSkinnedMeshShape::create(tmpdesc);

		MonoObject* __output;
		__output = ScriptParticleEmitterShape::create(tmp__output);

		return __output;
	}
}