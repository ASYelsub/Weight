// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Weight/WeightGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeightGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Weight();
WEIGHT_API UClass* Z_Construct_UClass_AWeightGameMode();
WEIGHT_API UClass* Z_Construct_UClass_AWeightGameMode_NoRegister();
// End Cross Module References

// Begin Class AWeightGameMode
void AWeightGameMode::StaticRegisterNativesAWeightGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWeightGameMode);
UClass* Z_Construct_UClass_AWeightGameMode_NoRegister()
{
	return AWeightGameMode::StaticClass();
}
struct Z_Construct_UClass_AWeightGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "WeightGameMode.h" },
		{ "ModuleRelativePath", "WeightGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWeightGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AWeightGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Weight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWeightGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWeightGameMode_Statics::ClassParams = {
	&AWeightGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWeightGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AWeightGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWeightGameMode()
{
	if (!Z_Registration_Info_UClass_AWeightGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWeightGameMode.OuterSingleton, Z_Construct_UClass_AWeightGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWeightGameMode.OuterSingleton;
}
template<> WEIGHT_API UClass* StaticClass<AWeightGameMode>()
{
	return AWeightGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWeightGameMode);
AWeightGameMode::~AWeightGameMode() {}
// End Class AWeightGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Abby_Game_Development_Weight_Weight_Source_Weight_WeightGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWeightGameMode, AWeightGameMode::StaticClass, TEXT("AWeightGameMode"), &Z_Registration_Info_UClass_AWeightGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWeightGameMode), 4267371245U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Abby_Game_Development_Weight_Weight_Source_Weight_WeightGameMode_h_1406108555(TEXT("/Script/Weight"),
	Z_CompiledInDeferFile_FID_Abby_Game_Development_Weight_Weight_Source_Weight_WeightGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Abby_Game_Development_Weight_Weight_Source_Weight_WeightGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
