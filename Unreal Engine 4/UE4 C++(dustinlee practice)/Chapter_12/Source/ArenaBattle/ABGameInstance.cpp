// Fill out your copyright notice in the Description page of Project Settings.
//#include "ArenaBattle.h"
#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	//UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("Game Instance Construcor Call! Start"));
	//매크로
	AB_LOG(Warning, TEXT("Coustructor Call Start"));
	WebConnection = CreateDefaultSubobject<UWebConnection>(TEXT("MyWebConnection"));
	//UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("Game Instance Construcor Call! End"));
	//매크로
	AB_LOG(Warning, TEXT("Constructor Call End"));
}

void UABGameInstance::Init()
{
	Super::Init();
	//UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("Game Instance Init!"));
	AB_LOG_CALLONLY(Warning);
	//chapter 5
	{
		UClass* ClassInfo1 = WebConnection->GetClass();
		UClass* ClassInfo2 = UWebConnection::StaticClass();
		if (ClassInfo1 == ClassInfo2)
		{
			AB_LOG(Warning, TEXT("ClassInfo1 is name with ClassInfo2"));
		}

		for (TFieldIterator<UProperty>It(ClassInfo1); It; ++It)
		{
			AB_LOG(Warning, TEXT("Field:%s, Type:%s"), *It->GetName(), *It->GetClass()->GetName());
			UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());
			if (StrProp)
			{
				AB_LOG(Warning, TEXT("Value=%s"), *StrProp->GetPropertyValue_InContainer(WebConnection));
			}
		}

		for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)
		{
			AB_LOG(Warning, TEXT("Function=%s"), *Entry.Name.ToString());
			UFunction* Func1 = ClassInfo1->FindFunctionByName(Entry.Name);
			if (Func1->ParmsSize == 0)
			{
				WebConnection->ProcessEvent(Func1, NULL);
			}
		}
	}

	//chapter 6
	{
		TArray<UObject*> DefaultSubobjects;
		GetDefaultSubobjects(DefaultSubobjects);
		for (const auto& Entry : DefaultSubobjects)
		{
			AB_LOG(Warning, TEXT("DefaultSubobject:%s"), *Entry->GetClass()->GetName());
			AB_LOG(Warning, TEXT("Outer of DefaultSubobject:%s"), *Entry->GetOuter()->GetClass()->GetName());
		}

		WebConnectionNew = NewObject<UWebConnection>(this);
		AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnectionNew->GetOuter()->GetClass()->GetName());

		UWorld* CurrentWorld = GetWorld();
		for (const auto& Entry : FActorRange(CurrentWorld))
		{
			AB_LOG(Warning, TEXT("Actor:%s"), *Entry->GetName());
			TArray<UObject*>Components;
			Entry->GetDefaultSubobjects(Components);
			for (const auto&CEntry : Components)
			{
				AB_LOG(Warning, TEXT(" -- Conmpoenet:%s"), *CEntry->GetName());
			}
		}

		for (TActorIterator<AStaticMeshActor>It(CurrentWorld); It; ++It)
		{
			AB_LOG(Warning, TEXT("StaticMesh Actor: %s"), *It->GetName());
		}

		WebConnection->Host = TEXT("localhost");
		WebConnectionNew->Host = TEXT("127.0.0.1");

		for (TObjectIterator<UWebConnection>It; It; ++It)
		{
			UWebConnection* Conn = *It;
			AB_LOG(Warning, TEXT("WebConnection Object Host:%s"), *Conn->Host);
		}
	}

	//WebConnection->TokenCompleteDelegate.BindUObject(this, &UABGameInstance::RequestTokenComplete);
	WebConnection->TokenCompleteDelegate.AddDynamic(this, &UABGameInstance::RequestTokenComplete);
	WebConnection->RequestToken(TEXT("destiny)"));

	/*{
		WebConnectionNew = NewObject<UWebConnection>(this);
		WebConnectionNew->Host = TEXT("127.0.0.7");
		WebConnectionNew->URI = TEXT("/");

		FString FullPath = FString::Printf(TEXT("%s%s"), *FPaths::GameSavedDir(), TEXT("WebConnection.txt"));
		FArchive* ArWriter = IFileManager::Get().CreateFileWriter(*FullPath);
		if (ArWriter)
		{
			//*ArWriter << WebConnectionNew->Host;
			//*ArWriter << WebConnectionNew->URI;
			*ArWriter << *WebConnectionNew;
			ArWriter->Close();
			delete ArWriter;
			ArWriter = NULL;
		}

		TSharedPtr<FArchive>FileReader = MakeShareable(IFileManager::Get().CreateFileReader(*FullPath));
		if (FileReader.IsValid())
		{
			//FString Host;
			//FString URI;
			//*FileReader.Get() << Host;
			//*FileReader.Get() << URI;
			UWebConnection* WebConnectionFromFile = NewObject<UWebConnection>(this);
			*FileReader.Get() << *WebConnectionFromFile;
			FileReader->Close();
			AB_LOG(Warning, TEXT("WebConnection From File: Host %s, URI %s"), *WebConnectionFromFile->Host, *WebConnectionFromFile->URI);
			//AB_LOG(Warning, TEXT("WebConnection:Host %s,URI%s"), *Host, *URI);
		}
	}*/

	FString PackageName = TEXT("/Temp/SavedWebConnection");
	UPackage* NewPackage = CreatePackage(nullptr, *PackageName);
	WebConnectionNew = NewObject<UWebConnection>(NewPackage);
	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	WebConnectionNew->Host = TEXT("127.0.0.7");
	WebConnectionNew->URI = TEXT("/");
	if (UPackage::SavePackage(NewPackage, WebConnectionNew, RF_Standalone, *PackageFileName))
	{
		UPackage* SavedPackage = ::LoadPackage(NULL, *PackageFileName, LOAD_None);
		TArray<UObject*>ObjectsInPackage;
		GetObjectsWithOuter(SavedPackage, ObjectsInPackage, false);
		for (const auto& EachObject : ObjectsInPackage)
		{
			UWebConnection* WebConnectionFromFile = Cast<UWebConnection>(EachObject);
			if (WebConnectionFromFile)
			{
				AB_LOG(Warning, TEXT("WebConnection From Filr: Host %s, URI %s"), *WebConnectionFromFile->Host, *WebConnectionFromFile->URI);
			}
		}
	}

}

void UABGameInstance::RequestTokenComplete(const FString & Token)
{
	AB_LOG(Warning, TEXT("Token : %s"), *Token);
}


