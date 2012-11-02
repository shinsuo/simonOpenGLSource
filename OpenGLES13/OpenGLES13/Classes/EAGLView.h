//
//  EAGLView.h
//  OpenGLES13
//
//  Created by Simon Maurice on 24/05/09.
//  Copyright Simon Maurice 2009. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

#define WALK_SPEED 0.005
#define TURN_SPEED 0.01

typedef enum __MOVMENT_TYPE {
	MTNone = 0,
	MTWalkForward,
	MTWAlkBackward,
	MTTurnLeft,
	MTTurnRight
} MovementType;

/*
This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView subclass.
The view content is basically an EAGL surface you render your OpenGL scene into.
Note that setting the view non-opaque will only work if the EAGL surface has an alpha channel.
*/
@interface EAGLView : UIView {
    
@private
    /* The pixel dimensions of the backbuffer */
    GLint backingWidth;
    GLint backingHeight;
    
    EAGLContext *context;
    
    /* OpenGL names for the renderbuffer and framebuffers used to render to this view */
    GLuint viewRenderbuffer, viewFramebuffer;
    
    /* OpenGL name for the depth buffer that is attached to viewFramebuffer, if it exists (0 if it does not exist) */
    GLuint depthRenderbuffer;
    
    NSTimer *animationTimer;
    NSTimeInterval animationInterval;
	
	GLuint textures[10];
	MovementType currentMovement;
	
	GLfloat eye[3];					// Where we are viewing from
	GLfloat center[3];				// Where we are looking towards
}

@property NSTimeInterval animationInterval;

- (void)startAnimation;
- (void)stopAnimation;
- (void)drawView;

- (void)setupView;
- (void)loadTexture:(NSString *)name intoLocation:(GLuint)location;
- (void)handleTouches;

@end
