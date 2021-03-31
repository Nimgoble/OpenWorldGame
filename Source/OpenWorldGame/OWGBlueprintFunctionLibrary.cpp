// Fill out your copyright notice in the Description page of Project Settings.


#include "OWGBlueprintFunctionLibrary.h"


bool UOWGBlueprintFunctionLibrary::IsActorInsideActor(AActor* actorThatMayBeInside, AActor* actorWeMayBeInside, bool onlyCollidingComponents)
{
	FVector origin1, extent1;
	FVector origin2, extent2;
	if (actorThatMayBeInside == NULL || actorWeMayBeInside == NULL)
		return false;

	actorThatMayBeInside->GetActorBounds(onlyCollidingComponents, origin1, extent1);
	actorWeMayBeInside->GetActorBounds(onlyCollidingComponents, origin2, extent2);
	FBox bounds1(origin1, extent1);
	FBox bounds2(origin2, extent2);

	bool rtn = bounds2.IsInside(bounds1);
	FVector min1 = bounds1.Min;
	FVector max1 = bounds1.Max;
	FVector min2 = bounds2.Min;
	FVector max2 = bounds2.Max;

	return rtn;
}

bool UOWGBlueprintFunctionLibrary::IsComponentInsideComponent(UPrimitiveComponent* componentThatMayBeInside, UPrimitiveComponent* componentWeMayBeInside)
{
	if (componentThatMayBeInside == NULL || componentWeMayBeInside == NULL)
		return false;

	FBox innerBox = componentThatMayBeInside->Bounds.GetBox();
	FBox outerBox = componentWeMayBeInside->Bounds.GetBox();
	return outerBox.IsInside(innerBox);
}
