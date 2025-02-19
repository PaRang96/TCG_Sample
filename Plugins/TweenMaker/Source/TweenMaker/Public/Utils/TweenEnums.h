// Copyright 2018 Francesco Desogus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TweenEnums.generated.h"

/// @brief Available easing functions.
UENUM()
enum class ETweenEaseType : uint8
{
    Linear,
    EaseInQuad,
    EaseOutQuad,
    EaseInOutQuad,
    EaseOutInQuad,
    EaseInCubic,
    EaseOutCubic,
    EaseInOutCubic,
    EaseOutInCubic,
    EaseInQuart,
    EaseOutQuart,
    EaseInOutQuart,
    EaseOutInQuart,
    EaseInQuint,
    EaseOutQuint,
    EaseInOutQuint,
    EaseOutInQuint,
    EaseInSine,
    EaseOutSine,
    EaseInOutSine,
    EaseOutInSine,
    EaseInExpo,
    EaseOutExpo,
    EaseInOutExpo,
    EaseOutInExpo,
    EaseInCirc,
    EaseOutCirc,
    EaseInOutCirc,
    EaseOutInCirc,
    EaseInElastic,
    EaseOutElastic,
    EaseInOutElastic,
    EaseOutInElastic,
    EaseInBack,
    EaseOutBack,
    EaseInOutBack,
    EaseOutInBack,
    EaseInBounce,
    EaseOutBounce,
    EaseInOutBounce,
    EaseOutInBounce
};

/// @brief Available loop types.
UENUM()
enum class ETweenLoopType : uint8
{
    Yoyo UMETA(ToolTip = "When a Tween reaches the end, it will restart from the end and go backward"),
    Restart UMETA(ToolTip = "When a Tween reaches the end, it will restart from the beginning")
};

/// @brief Available Tween targets.
UENUM()
enum class ETweenTargetType : uint8
{
    Actor,
    SceneComponent,
    UMG,
    Material,
    Custom
};

/// @brief Available Tweens for a "FVector" type.
UENUM()
enum class ETweenVectorType : uint8
{
    MoveTo,
    MoveBy,
    ScaleTo,
    ScaleBy,
    Custom
};

/// @brief Available Tweens for a "FVector2D" type.
UENUM()
enum class ETweenVector2DType : uint8
{
    MoveTo,
    MoveBy,
    ScaleTo,
    ScaleBy,
    ShearTo,
    Custom
};

/// @brief Available Tweens for a "FRotator" type.
UENUM()
enum class ETweenRotatorType : uint8
{
    RotateTo,
    RotateBy
};

/// @brief Available Tweens for a "FLinearColor" type.
UENUM()
enum class ETweenLinearColorType : uint8
{
    MaterialVectorFromTo,
    MaterialVectorTo,
};

/// @brief Available Tweens for a "float" type.
UENUM()
enum class ETweenFloatType : uint8
{
    MaterialScalarFromTo,
    MaterialScalarTo,
    RotateAroundPoint,
    FollowSpline,
    WidgetAngleTo,
    WidgetOpacityTo,
    Custom
};

/// @brief Axis reference, used for the "rotate around poit" type of Tween.
UENUM()
enum class ETweenReferenceAxis : uint8
{
    XAxis,
    YAxis,
    ZAxis
};

/// @brief Defines in which space the Tween makes its update (i.e. 'world' or 'relative').
UENUM()
enum class ETweenSpace : uint8
{
    World UMETA(ToolTip = "The Tween makes its update in world space"),
    Relative UMETA(ToolTip = "The Tween makes its update in relative (local) space")
};

/// @brief Available rotation modes.
UENUM()
enum class ETweenRotationMode : uint8
{
    ShortestPath UMETA(ToolTip = "The rotation occurs by taking the shortest path between the start and the end"),
    FullPath UMETA(ToolTip = "The rotation occurs by taking the full path between the start and the end")
};

/// @brief Available snap modes, used when a Tween is manually deleted to choose if it should go to the beginning/end or simply leave it be
UENUM()
enum class ESnapMode : uint8
{
	None UMETA(ToolTip = "No snapping occurs. The Tween target stays where it is"),
	SnapToBeginning UMETA(ToolTip = "Snaps the Tween target to the beginning of the animation"),
	SnapToEnd UMETA(ToolTip = "Snaps the Tween target to the end of the animation")
};

/// @brief Generic type of Tween.
UENUM()
enum class ETweenGenericType : uint8
{
    Any UMETA(ToolTip = "Any type of Tween."),
    Move UMETA(ToolTip = "Tweens that move either an Actor, SceneComponent or a Widget."),
    Scale UMETA(ToolTip = "Tweens that scale either an Actor, SceneComponent or a Widget."),
    Rotate UMETA(ToolTip = "Tweens that rotate either an Actor or a SceneComponent."),
    RotateAroundPoint UMETA(ToolTip = "Tweens that rotate around a pivot point either an Actor or a SceneComponent."),
    FollowSpline UMETA(ToolTip = "Tweens that make either an Actor or a SceneComponent follow a spline."),
    MaterialVector UMETA(ToolTip = "Tweens that modify a Vector property of a material."),
    MaterialScalar UMETA(ToolTip = "Tweens that modify a Scalar property of a material."),
    WidgetAngle UMETA(ToolTip = "Tweens that rotate a Widget."),
    WidgetOpacity UMETA(ToolTip = "Tweens that modify the opacity value of a Widget."),
    WidgetShear UMETA(ToolTip = "Tweens that modify the shear value of a Widget."),
    CustomVector UMETA(ToolTip = "Custom Vector Tweens."),
    CustomFloat UMETA(ToolTip = "Custom Float Tweens."),
    CustomVector2D UMETA(ToolTip = "Custom Vector2D Tweens."),
};


