cmake_minimum_required(VERSION 2.6)
project(FCollada)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, defaulting to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

option(BUILD_SHARED_LIBS "Build FCollada as a shared library." OFF)
option(BUILD_UNICODE "Build FCollada in wide-character mode." OFF)
option(BUILD_TESTS "Build the test suite." OFF)

set(LIBRARY_NAME FCollada)

if(BUILD_SHARED_LIBS)
    add_definitions(-DFCOLLADA_DLL)
elseif(NOT MSVC)
    set(LIBRARY_NAME "${LIBRARY_NAME}S")
endif()

if(BUILD_UNICODE)
    add_definitions(-DUNICODE -D_UNICODE)
    set(LIBRARY_NAME "${LIBRARY_NAME}U")
endif()

if(NOT BUILD_TESTS)
    add_definitions(-DRETAIL)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(-DWIN32)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_definitions(-DLINUX)
endif()

# For LibXML
include(CheckIncludeFiles)
check_include_files(unistd.h HAVE_UNISTD_H)
if(HAVE_UNISTD_H)
  add_definitions(-DHAVE_UNISTD_H=1)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/LibXML/include)

file(GLOB SOURCE_FILES
    "LibXML/*.c"
    "FCDocument/*.cpp"
    "FMath/*.cpp"
    "FUtils/*.cpp"
    "*.cpp"
    "../FColladaPlugins/FArchiveXML/*.cpp"
)

add_library(${LIBRARY_NAME} ${SOURCE_FILES})
target_link_libraries(${LIBRARY_NAME} ${CMAKE_DL_LIBS})

if(NOT MSVC)
    set_target_properties(${LIBRARY_NAME} PROPERTIES
        OUTPUT_NAME_DEBUG ${LIBRARY_NAME}D
    )
endif()

install(TARGETS ${LIBRARY_NAME} DESTINATION lib)

install(FILES
    FCollada.h
    FColladaPlugin.h
    DESTINATION include/FCollada
)
install(FILES
    FCDocument/FCDAnimated.h
    FCDocument/FCDAnimation.h
    FCDocument/FCDAnimationChannel.h
    FCDocument/FCDAnimationClip.h
    FCDocument/FCDAnimationClipTools.h
    FCDocument/FCDAnimationCurve.h
    FCDocument/FCDAnimationCurveTools.h
    FCDocument/FCDAnimationKey.h
    FCDocument/FCDAnimationMultiCurve.h
    FCDocument/FCDAsset.h
    FCDocument/FCDCamera.h
    FCDocument/FCDController.h
    FCDocument/FCDControllerInstance.h
    FCDocument/FCDControllerTools.h
    FCDocument/FCDEffect.h
    FCDocument/FCDEffectCode.h
    FCDocument/FCDEffectParameter.h
    FCDocument/FCDEffectParameter.hpp
    FCDocument/FCDEffectParameterFactory.h
    FCDocument/FCDEffectParameterSampler.h
    FCDocument/FCDEffectParameterSurface.h
    FCDocument/FCDEffectPass.h
    FCDocument/FCDEffectPassShader.h
    FCDocument/FCDEffectPassState.h
    FCDocument/FCDEffectProfile.h
    FCDocument/FCDEffectProfileFX.h
    FCDocument/FCDEffectStandard.h
    FCDocument/FCDEffectTechnique.h
    FCDocument/FCDEffectTools.h
    FCDocument/FCDEmitter.h
    FCDocument/FCDEmitterInstance.h
    FCDocument/FCDEmitterObject.h
    FCDocument/FCDEmitterParticle.h
    FCDocument/FCDEntity.h
    FCDocument/FCDEntityInstance.h
    FCDocument/FCDEntityReference.h
    FCDocument/FCDExternalReferenceManager.h
    FCDocument/FCDExtra.h
    FCDocument/FCDForceDeflector.h
    FCDocument/FCDForceDrag.h
    FCDocument/FCDForceField.h
    FCDocument/FCDForceGravity.h
    FCDocument/FCDForcePBomb.h
    FCDocument/FCDForceTyped.h
    FCDocument/FCDForceWind.h
    FCDocument/FCDGeometry.h
    FCDocument/FCDGeometryInstance.h
    FCDocument/FCDGeometryMesh.h
    FCDocument/FCDGeometryNURBSSurface.h
    FCDocument/FCDGeometryPolygons.h
    FCDocument/FCDGeometryPolygonsInput.h
    FCDocument/FCDGeometryPolygonsTools.h
    FCDocument/FCDGeometrySource.h
    FCDocument/FCDGeometrySpline.h
    FCDocument/FCDImage.h
    FCDocument/FCDLibrary.h
    FCDocument/FCDLibrary.hpp
    FCDocument/FCDLight.h
    FCDocument/FCDLightTools.h
    FCDocument/FCDMaterial.h
    FCDocument/FCDMaterialInstance.h
    FCDocument/FCDMorphController.h
    FCDocument/FCDObject.h
    FCDocument/FCDObjectWithId.h
    FCDocument/FCDocument.h
    FCDocument/FCDocumentTools.h
    FCDocument/FCDParameterAnimatable.h
    FCDocument/FCDParameterAnimatable.hpp
    FCDocument/FCDParticleEmitter.h
    FCDocument/FCDParticleModifier.h
    FCDocument/FCDPhysicsAnalyticalGeometry.h
    FCDocument/FCDPhysicsForceFieldInstance.h
    FCDocument/FCDPhysicsMaterial.h
    FCDocument/FCDPhysicsModel.h
    FCDocument/FCDPhysicsModelInstance.h
    FCDocument/FCDPhysicsRigidBody.h
    FCDocument/FCDPhysicsRigidBodyInstance.h
    FCDocument/FCDPhysicsRigidBodyParameters.h
    FCDocument/FCDPhysicsRigidConstraint.h
    FCDocument/FCDPhysicsRigidConstraintInstance.h
    FCDocument/FCDPhysicsScene.h
    FCDocument/FCDPhysicsShape.h
    FCDocument/FCDPlaceHolder.h
    FCDocument/FCDSceneNode.h
    FCDocument/FCDSceneNodeIterator.h
    FCDocument/FCDSceneNodeIterator.hpp
    FCDocument/FCDSceneNodeTools.h
    FCDocument/FCDSkinController.h
    FCDocument/FCDTargetedEntity.h
    FCDocument/FCDTexture.h
    FCDocument/FCDTransform.h
    FCDocument/FCDVersion.h
    DESTINATION include/FCollada/FCDocument
)

install(FILES
    FMath/FMAllocator.h
    FMath/FMAngleAxis.h
    FMath/FMArray.h
    FMath/FMArrayPointer.h
    FMath/FMath.h
    FMath/FMColor.h
    FMath/FMFloat.h
    FMath/FMInteger.h
    FMath/FMInterpolation.h
    FMath/FMLookAt.h
    FMath/FMMatrix33.h
    FMath/FMMatrix44.h
    FMath/FMQuaternion.h
    FMath/FMRandom.h
    FMath/FMSkew.h
    FMath/FMSort.h
    FMath/FMTree.h
    FMath/FMVector2.h
    FMath/FMVector3.h
    FMath/FMVector4.h
    FMath/FMVolume.h
    DESTINATION include/FCollada/FMath
)

install(FILES
    FUtils/FUAssert.h
    FUtils/FUBase64.h
    FUtils/FUBoundingBox.h
    FUtils/FUBoundingSphere.h
    FUtils/FUCrc32.h
    FUtils/FUCriticalSection.h
    FUtils/FUDaeEnum.h
    FUtils/FUDaeEnumSyntax.h
    FUtils/FUDaeSyntax.h
    FUtils/FUDateTime.h
    FUtils/FUDebug.h
    FUtils/FUError.h
    FUtils/FUErrorLog.h
    FUtils/FUEvent.h
    FUtils/FUFile.h
    FUtils/FUFileManager.h
    FUtils/FUFunctor.h
    FUtils/FULogFile.h
    FUtils/FUObject.h
    FUtils/FUObjectType.h
    FUtils/FUParameter.h
    FUtils/FUParameter.hpp
    FUtils/FUParameterizable.h
    FUtils/FUPlugin.h
    FUtils/FUPluginManager.h
    FUtils/FUSemaphore.h
    FUtils/FUSingleton.h
    FUtils/FUString.h
    FUtils/FUStringBuilder.h
    FUtils/FUStringBuilder.hpp
    FUtils/FUStringConversion.h
    FUtils/FUStringConversion.hpp
    FUtils/FUSynchronizableObject.h
    FUtils/FUTestBed.h
    FUtils/FUThread.h
    FUtils/FUtils.h
    FUtils/FUTracker.h
    FUtils/FUUniqueStringMap.h
    FUtils/FUUri.h
    FUtils/FUXmlDocument.h
    FUtils/FUXmlParser.h
    FUtils/FUXmlWriter.h
    FUtils/Platforms.h
    DESTINATION include/FCollada/FUtils
)

if(BUILD_TESTS)
    add_subdirectory(FColladaTest)
endif()

