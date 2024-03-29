#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


@interface MTMaterialView : UIView {

	BOOL _useBuiltInAlphaTransformerAndBackdropScaleAdjustment;
	BOOL _recipeDynamic;
	BOOL _shadowed;
	NSMutableDictionary* _cmVisualStyleCategoriesToProviders;
	NSDictionary* _recipeNamesByTraitCollection;
	NSBundle* _recipeBundle;
	NSHashTable* _observers;
	UIView* _highlightView;
	BOOL _needsLayoutOnMoveToWindow;
	BOOL _highlighted;
	NSString* _groupNameBase;
	long long _recipe;
	long long _configuration;
}
@property (nonatomic,copy) NSString * recipeName; 
@property (assign,getter=isBlurEnabled,nonatomic) BOOL blurEnabled; 
@property (assign,getter=isZoomEnabled,nonatomic) BOOL zoomEnabled; 
@property (assign,getter=isCaptureOnly,nonatomic) BOOL captureOnly; 
@property (assign,getter=isShadowed,nonatomic) BOOL shadowed; 
@property (assign,getter=isInPlaceFilteringEnabled,nonatomic) BOOL inPlaceFilteringEnabled; 
@property (nonatomic,copy) id backdropScaleAdjustment; 
@property (assign,nonatomic) BOOL shouldCrossfade; 
@property (assign,nonatomic) BOOL useBuiltInAlphaTransformerAndBackdropScaleAdjustment; 
@property (assign,nonatomic) BOOL useBuiltInAlphaTransformerAndBackdropScaleAdjustmentIfNecessary; 
@property (assign,getter=isRecipeDynamic,nonatomic) BOOL recipeDynamic; 
@property (assign,nonatomic) BOOL ignoresScreenClip; 
@property (assign,getter=isContentReplacedWithSnapshot,nonatomic) BOOL contentReplacedWithSnapshot; 
@property (assign,nonatomic) BOOL shouldCrossfadeIfNecessary; 
@property (assign,nonatomic) BOOL forceCrossfadeIfNecessary;             //@synthesize backdropFloatAnimatableProperty=_backdropFloatAnimatableProperty - In the implementation block
@property (nonatomic,copy) NSString * groupName; 
@property (nonatomic,copy) NSString * groupNameBase;                                                                                               //@synthesize groupNameBase=_groupNameBase - In the implementation block
@property (assign,nonatomic) double weighting; 
@property (assign,nonatomic) long long recipe;                                                                                                     //@synthesize recipe=_recipe - In the implementation block
@property (assign,nonatomic) long long configuration;                                                                                              //@synthesize configuration=_configuration - In the implementation block
@property (assign,getter=isHighlighted,nonatomic) BOOL highlighted;                                                                                //@synthesize highlighted=_highlighted - In the implementation block
@property (nonatomic,copy) NSString * debugIdentifier; 
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
+(void)initialize;
+(id)_recipeNameForTraitCollection:(id)arg1 withRecipeNamesByTraitCollection:(id)arg2 ;
+(id)newDefaultHighlightAnimator;
+(id)materialViewWithRecipe:(long long)arg1 configuration:(long long)arg2 initialWeighting:(double)arg3 ;
+(id)materialViewWithRecipeNamesByTraitCollection:(id)arg1 inBundle:(id)arg2 configuration:(long long)arg3 initialWeighting:(double)arg4 scaleAdjustment:(/*^block*/id)arg5 ;
+(Class)layerClass;
+(id)materialViewWithRecipe:(long long)arg1 configuration:(long long)arg2 initialWeighting:(double)arg3 compatibleWithTraitCollection:(id)arg4 ;
+(id)materialViewWithRecipeNamed:(id)arg1 inBundle:(id)arg2 configuration:(long long)arg3 initialWeighting:(double)arg4 scaleAdjustment:(/*^block*/id)arg5 ;
+(id)staticMaterialViewWithRecipe:(long long)arg1 configuration:(long long)arg2 ;
+(id)materialViewWithRecipe:(long long)arg1 configuration:(long long)arg2 initialWeighting:(double)arg3 scaleAdjustment:(/*^block*/id)arg4 ;
+(id)materialViewWithRecipeNamed:(id)arg1 ;
+(id)materialViewWithRecipeNamesByTraitCollection:(id)arg1 compatibleWithTraitCollection:(id)arg2 bundle:(id)arg3 configuration:(long long)arg4 initialWeighting:(double)arg5 scaleAdjustment:(/*^block*/id)arg6 ;
+(id)materialViewWithRecipe:(long long)arg1 configuration:(long long)arg2 ;
-(BOOL)isHighlighted;
-(BOOL)isZoomEnabled;
-(double)weighting;
-(void)setZoomEnabled:(BOOL)arg1 ;
-(BOOL)isBlurEnabled;
-(void)setShouldCrossfadeIfNecessary:(BOOL)arg1 ;
-(void)setWeighting:(double)arg1 ;
-(void)setBackdropScaleAdjustment:(id)arg1 ;
-(id)init;
-(void)setContentReplacedWithSnapshot:(BOOL)arg1 ;
-(void)setRecipeDynamic:(BOOL)arg1 ;
-(void)setInPlaceFilteringEnabled:(BOOL)arg1 ;
-(void)setConfiguration:(long long)arg1 ;
-(NSString *)groupName;
-(id)_backdropFloatAnimatableProperty;
-(void)_removeObserver:(id)arg1 ;
-(void)layoutSubviews;
-(void)setGroupName:(NSString *)arg1 ;
-(BOOL)shouldCrossfade;
-(id)newShadowView;
-(void)setBlurEnabled:(BOOL)arg1 ;
-(void)didMoveToWindow;
-(void)setDebugIdentifier:(NSString *)arg1 ;
-(void)_reduceTransparencyStatusDidChange;
-(BOOL)_shouldAnimatePropertyWithKey:(id)arg1 ;
-(id)_initWithCoreMaterialRecipe:(id)arg1 fromBundle:(id)arg2 coreMaterialConfiguration:(id)arg3 initialWeighting:(double)arg4 scaleAdjustment:(/*^block*/id)arg5 ;
-(BOOL)ignoresScreenClip;
-(BOOL)isManagingInterpolationForMaterialLayer:(id)arg1 ;
-(BOOL)isShadowed;
-(void)setGroupNameBase:(NSString *)arg1 ;
-(id)visualStylingProviderForCategory:(long long)arg1 ;
-(void)_setupOrInvalidateAlphaTransformer;
-(BOOL)useBuiltInAlphaTransformerAndBackdropScaleAdjustmentIfNecessary;
-(void)_updateGroupNameIfNecessary;
-(void)setRecipe:(long long)arg1 ;
-(void)_reduceMotionStatusDidChange;
-(id)_materialLayer;
-(BOOL)useBuiltInAlphaTransformerAndBackdropScaleAdjustment;
-(void)setRecipeName:(NSString *)arg1 ;
-(NSString *)debugIdentifier;
-(long long)recipe;
-(BOOL)addCompletionForCurrentAnimation:(/*^block*/id)arg1 forMaterialLayer:(id)arg2 reason:(out id*)arg3 ;
-(id)_initWithRecipeNamesByTraitCollection:(id)arg1 compatibleWithTraitCollection:(id)arg2 bundle:(id)arg3 configuration:(long long)arg4 initialWeighting:(double)arg5 scaleAdjustment:(/*^block*/id)arg6 ;
-(BOOL)isManagingOpacityForMaterialLayer:(id)arg1 ;
-(void)_addObserver:(id)arg1 ;
-(id)backdropScaleAdjustment;
-(void)_notifyObserversWithBlock:(/*^block*/id)arg1 ;
-(void)setUseBuiltInAlphaTransformerAndBackdropScaleAdjustment:(BOOL)arg1 ;
-(void)setShouldCrossfade:(BOOL)arg1 ;
-(long long)configuration;
-(void)_setRecipeName:(id)arg1 withWeighting:(double)arg2 ;
-(id)_initWithRecipe:(long long)arg1 configuration:(long long)arg2 userInterfaceStyle:(long long)arg3 initialWeighting:(double)arg4 scaleAdjustment:(/*^block*/id)arg5 ;
-(void)setCaptureOnly:(BOOL)arg1 ;
-(void)setHighlighted:(BOOL)arg1 ;
-(void)setUseBuiltInAlphaTransformerAndBackdropScaleAdjustmentIfNecessary:(BOOL)arg1 ;
-(void)setShadowed:(BOOL)arg1 ;
-(BOOL)managesWeightingForMaterialLayer:(id)arg1 ;
-(NSString *)description;
-(id)_coreMaterialVisualStylingProviderForCategory:(id)arg1 ;
-(BOOL)isInPlaceFilteringEnabled;
-(id)newShadowViewWithCaptureOnlyMaterialView:(BOOL)arg1 ;
-(void)dealloc;
-(id)_recipeNameForCurrentTraitCollection;
-(BOOL)isContentReplacedWithSnapshot;
-(void)prune;
-(void)setForceCrossfadeIfNecessary:(BOOL)arg1 ;
-(NSString *)groupNameBase;
-(BOOL)forceCrossfadeIfNecessary;
-(BOOL)shouldCrossfadeIfNecessary;
-(BOOL)isRecipeDynamic;
-(BOOL)isCaptureOnly;
-(void)setIgnoresScreenClip:(BOOL)arg1 ;
-(void)_invalidateAlphaTransformer;
-(id)_groupNameWithBase:(id)arg1 ;
-(void)_updateRecipeNameIfNeeded;
-(void)_setupAlphaTransformer;
-(NSString *)recipeName;
-(id)copyWithZone:(NSZone*)arg1 ;
@end

@interface CCUIModularControlCenterOverlayViewController : UIViewController
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (copy, readonly) NSString* description;
@property (copy, readonly) NSString* debugDescription;
@property (assign, nonatomic) unsigned long long presentationState; //@synthesize presentationState=_presentationState - In the implementation block
@property (assign, nonatomic) unsigned long long transitionState; //@synthesize transitionState=_transitionState - In the implementation block
@property (nonatomic, copy) NSUUID* currentTransitionUUID; //@synthesize currentTransitionUUID=_currentTransitionUUID - In the implementation block
@property (assign, getter=isReachabilityActive, nonatomic) BOOL reachabilityActive; //@synthesize reachabilityActive=_reachabilityActive - In the implementation block
@property (nonatomic, readonly) MTMaterialView* overlayBackgroundView;
@property (nonatomic, readonly) UIScrollView* overlayScrollView;
@property (nonatomic, readonly) UIView* overlayContainerView;
@property (nonatomic, readonly) CGRect overlayBackgroundFrame;
@property (nonatomic, readonly) CGRect overlayContainerFrame;
@property (nonatomic, readonly) long long overlayInterfaceOrientation;
@property (nonatomic, readonly) double overlayReachabilityHeight;
+ (id)_controlCenterBringupEventStream;
+ (id)_blocksBySignpost;
+ (void)_addBlockForSignpost:(unsigned long long)arg1 block:(/*^block*/ id)arg2;
+ (id)_controlCenterDismissEventStream;
+ (id)_presentationProviderForDevice;
+ (void)_executeAndCleanupBlocksForAllSignposts;
+ (void)_executeBlocksForSignpost:(unsigned long long)arg1;
+ (id)_controlCenterDismissOrbActionsEventStream;
+ (void)_playEventStream:(id)arg1 withCompletion:(/*^block*/ id)arg2;
- (unsigned long long)preferredScreenEdgesDeferringSystemGestures;
- (id)_moduleCollectionViewContainerView;
- (void)_reparentAndBecomeActive;
- (void)moduleCollectionViewController:(id)arg1 willPresentViewController:(id)arg2;
- (id)_statusLabelViewContainerView;
- (void)setTransitionState:(unsigned long long)arg1;
- (void)moduleInstancesLayoutChangedForModuleInstanceManager:(id)arg1;
- (void)dismissControlCenterForContentModuleContext:(id)arg1;
- (void)moduleCollectionViewController:(id)arg1 willDismissViewController:(id)arg2;
- (void)moduleCollectionViewController:(id)arg1 didAddModuleContainerViewController:(id)arg2;
- (void)moduleInstancesChangedForModuleInstanceManager:(id)arg1;
- (void)moduleCollectionViewController:(id)arg1 willCloseExpandedModule:(id)arg2;
- (void)moduleCollectionViewControllerDidUpdateModules:(id)arg1;
- (void)moduleCollectionViewController:(id)arg1 willOpenExpandedModule:(id)arg2;
- (void)_dismissalPanGestureRecognizerFailed:(id)arg1;
- (BOOL)gestureRecognizer:(id)arg1 shouldBeRequiredToFailByGestureRecognizer:(id)arg2;
- (id)_beginPresentationAnimated:(BOOL)arg1 interactive:(BOOL)arg2;
- (void)_updatePresentationForTransitionState:(id)arg1 withCompletionHander:(/*^block*/ id)arg2;
- (BOOL)_scrollViewIsScrollable;
- (void)beginPresentationWithLocation:(CGPoint)arg1 translation:(CGPoint)arg2 velocity:(CGPoint)arg3;
- (void)reachabilityAnimationDidEnd;
- (BOOL)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (BOOL)_dismissalFlickGestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (UIScrollView*)overlayScrollView;
- (unsigned long long)transitionState;
- (BOOL)runTest:(id)arg1 options:(id)arg2 delegate:(id)arg3;
- (void)_dismissalPanGestureRecognizerBegan:(id)arg1;
- (void)_willDismissView;
- (BOOL)_dismissalFlickGestureRecognizerShouldBegin:(id)arg1;
- (void)statusLabelViewControllerWillBeginStatusUpdates:(id)arg1;
- (BOOL)_gestureRecognizerIsActive:(id)arg1;
- (void)_handleDismissalPanGestureRecognizer:(id)arg1;
- (void)_endPresentationWithUUID:(id)arg1;
- (NSUUID*)currentTransitionUUID;
- (void)presentAnimated:(BOOL)arg1 withCompletionHandler:(/*^block*/ id)arg2;
- (unsigned long long)__supportedInterfaceOrientations;
- (void)viewDidLoad;
- (MTMaterialView*)overlayBackgroundView;
- (void)_dismissalPanGestureRecognizerChanged:(id)arg1;
- (void)_handleDismissalFlickGestureRecognizer:(id)arg1;
- (void)setReachabilityActive:(BOOL)arg1;
- (void)updatePresentationWithLocation:(CGPoint)arg1 translation:(CGPoint)arg2 velocity:(CGPoint)arg3;
- (BOOL)gestureRecognizerShouldBegin:(id)arg1;
- (CGRect)overlayContainerFrame;
- (void)cancelPresentationWithLocation:(CGPoint)arg1 translation:(CGPoint)arg2 velocity:(CGPoint)arg3;
- (void)_setupPanGestureFailureRequirements;
- (void)_updateHotPocket:(BOOL)arg1 animated:(BOOL)arg2;
- (void)viewWillLayoutSubviews;
- (void)_cancelDismissalPanGestures;
- (void)_willPresentView;
- (BOOL)_scrollPanGestureRecognizerCanBeginForGestureVelocity:(CGPoint)arg1;
- (id)_initWithSystemAgent:(id)arg1 presentationProvider:(id)arg2;
- (void)statusLabelViewControllerDidFinishStatusUpdates:(id)arg1;
- (id)initWithSystemAgent:(id)arg1;
- (BOOL)_dismissalFlickGestureRecognizer:(id)arg1 shouldBeRequiredToFailByGestureRecognizer:(id)arg2;
- (UIView*)overlayContainerView;
- (CGRect)compactAvoidanceFrameForStatusBar:(id)arg1;
- (BOOL)_dismissalTapGestureRecognizerShouldBegin:(id)arg1;
- (BOOL)_scrollPanGestureRecognizerShouldBegin:(id)arg1;
- (void)didReceiveSignpost:(unsigned long long)arg1;
- (void)_endDismissalWithUUID:(id)arg1 animated:(BOOL)arg2;
- (void)_updateHotPocketAnimated:(BOOL)arg1;
- (id)compactTrailingStyleRequestForStatusBar:(id)arg1;
- (unsigned long long)presentationState;
- (void)setCurrentTransitionUUID:(NSUUID*)arg1;
- (void)_dismissalPanGestureRecognizerCancelled:(id)arg1;
- (id)_beginDismissalAnimated:(BOOL)arg1 interactive:(BOOL)arg2;
- (void)_replaceBackgroundViewContentsWithSnapshotIfNecessary:(BOOL)arg1;
- (BOOL)_scrollViewCanAcceptDownwardsPan;
- (BOOL)scrollView:(id)arg1 gestureRecognizerShouldBegin:(id)arg2;
- (BOOL)_canShowWhileLocked;
- (void)_dismissalPanGestureRecognizerEnded:(id)arg1;
- (long long)overlayInterfaceOrientation;
- (UIEdgeInsets)overlayAdditionalEdgeInsets;
- (void)viewWillTransitionToSize:(CGSize)arg1 withTransitionCoordinator:(id)arg2;
- (void)scrollViewDidScroll:(id)arg1;
- (void)dismissAnimated:(BOOL)arg1 withCompletionHandler:(/*^block*/ id)arg2;
- (BOOL)_dismissalPanGestureRecognizerShouldBegin:(id)arg1;
- (void)_updateChevronStateForTransitionState:(id)arg1;
- (CGRect)overlayBackgroundFrame;
- (double)overlayReachabilityHeight;
- (unsigned long long)supportedInterfaceOrientations;
- (CGPoint)_centerPointOfTopmostModule;
- (BOOL)isReachabilityActive;
- (void)setOverlayStatusBarHidden:(BOOL)arg1;
- (void)endPresentationWithLocation:(CGPoint)arg1 translation:(CGPoint)arg2 velocity:(CGPoint)arg3;
- (void)runTest:(id)arg1 subtests:(id)arg2 eventStream:(id)arg3 completionHandler:(/*^block*/ id)arg4;
- (void)_updateSensorActivityStatusForHeaderPocketView;
- (void)_handleDismissalTapGestureRecognizer:(id)arg1;
- (id)_controlCenterShowOrbActionsEventStream;
- (void)_updatePresentationForTransitionType:(unsigned long long)arg1 translation:(CGPoint)arg2 interactive:(BOOL)arg3;
- (void)setPresentationState:(unsigned long long)arg1;
@end