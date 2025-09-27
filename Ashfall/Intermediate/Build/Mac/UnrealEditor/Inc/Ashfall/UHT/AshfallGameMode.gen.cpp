// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Ashfall/AshfallGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAshfallGameMode() {}

// Begin Cross Module References
ASHFALL_API UClass* Z_Construct_UClass_AAshfallGameMode();
ASHFALL_API UClass* Z_Construct_UClass_AAshfallGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Ashfall();
// End Cross Module References

// Begin Class AAshfallGameMode
void AAshfallGameMode::StaticRegisterNativesAAshfallGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAshfallGameMode);
UClass* Z_Construct_UClass_AAshfallGameMode_NoRegister()
{
	return AAshfallGameMode::StaticClass();
}
struct Z_Construct_UClass_AAshfallGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "AshfallGameMode.h" },
		{ "ModuleRelativePath", "AshfallGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAshfallGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAshfallGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Ashfall,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAshfallGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAshfallGameMode_Statics::ClassParams = {
	&AAshfallGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAshfallGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AAshfallGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAshfallGameMode()
{
	if (!Z_Registration_Info_UClass_AAshfallGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAshfallGameMode.OuterSingleton, Z_Construct_UClass_AAshfallGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAshfallGameMode.OuterSingleton;
}
template<> ASHFALL_API UClass* StaticClass<AAshfallGameMode>()
{
	return AAshfallGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAshfallGameMode);
AAshfallGameMode::~AAshfallGameMode() {}
// End Class AAshfallGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_kim_Documents_GitHub_kht9544_Project_Ashfall_Ashfall_Source_Ashfall_AshfallGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAshfallGameMode, AAshfallGameMode::StaticClass, TEXT("AAshfallGameMode"), &Z_Registration_Info_UClass_AAshfallGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAshfallGameMode), 1744189607U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kim_Documents_GitHub_kht9544_Project_Ashfall_Ashfall_Source_Ashfall_AshfallGameMode_h_2268269620(TEXT("/Script/Ashfall"),
	Z_CompiledInDeferFile_FID_kim_Documents_GitHub_kht9544_Project_Ashfall_Ashfall_Source_Ashfall_AshfallGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kim_Documents_GitHub_kht9544_Project_Ashfall_Ashfall_Source_Ashfall_AshfallGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
