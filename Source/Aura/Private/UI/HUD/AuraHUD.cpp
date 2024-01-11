// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if(OverlayWidgetController==nullptr)
	{
		OverlayWidgetController= NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}
void AAuraHUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	
	checkf(OverlayWidgetClass,TEXT("Overlay widget class Uninitialize , please filled out"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialize , please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams Params(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	UOverlayWidgetController* OverLayWidgetController = GetOverlayWidgetController(Params);

	OverlayWidget->SetWidgetController(OverLayWidgetController);
	OverlayWidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
		
		
	
}

