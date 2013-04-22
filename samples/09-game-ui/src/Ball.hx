package;

import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.display.Loader;
import flash.net.URLRequest;
import flash.events.Event;
import haxe.Timer;

typedef XYPoint = {
	x:Float,
	y:Float,
}

/**
 * the bouncing ball 
 */
class Ball extends Sprite
{
	/**
	 * ball physical property
	 */
	public var speed:XYPoint;
	/**
	 * ball physical property
	 */
	public var accel:XYPoint;
	/**
	 * ball physical property
	 */
	public var angularSpeed:Float;
	/**
	 * ball physical property
	 * also stands for the weight
	 */
	public var gravity:XYPoint;
	/**
	 * dimension of the loaded image
	 * considered to be the dimensions of the ball
	 */
	public var size:XYPoint;
	/** 
	 * constructor
	 * load the image and setup the ball
	 */
	public function new(imageUrl:String, position:XYPoint, speed:XYPoint, accel:XYPoint, gravity:XYPoint, angularSpeed:Float) 
	{
		super();

		// load the picture for the ball
		var loader:Loader = new Loader();
		var image:URLRequest = new URLRequest(imageUrl);
		loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onLoad);
		loader.load(image);
		addChild (loader);

		// store the data
		this.x = position.x;
		this.y = position.y;
		this.speed = speed;
		this.angularSpeed = angularSpeed;
		this.accel = accel;
		this.gravity = gravity;

		// size
		size = {x:0,y:0};
	}
	/**
	 * callback for the loader
	 */
	function onLoad(event:Event) 
	{
		trace("onLoad "+event);
		size = {
			x : event.target.width,
			y : event.target.height,
		};
		event.target.content.x = -event.target.width/2;
		event.target.content.y = -event.target.height/2;
	}
	/**
	 * game loop
	 * compute new position
	 */
	public function loop() 
	{
		// compute speed
		speed.x += accel.x + gravity.x;
		speed.y += accel.y + gravity.y;
		// compute position
		x += speed.x;
		y += speed.y;
		// reset accel
		accel.x = 0;
		accel.y = 0;
		// angular speed
		rotation += angularSpeed;
	}
}