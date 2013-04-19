package;

import flash.Lib;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.display.Stage;
import flash.net.URLRequest;
import flash.events.Event;
import haxe.Timer;


/** 
 * example of a bouncing ball game
 */
class Game 
{
	/**
	 * the bouncing ball 
	 */
	private var ball:Ball;
	/**
	 * the game container
	 */
	private var gameContainer:Sprite;
	/** 
	 * main function to start the game on the stage with default params
	 * for testing purpose, test the game standalone
	 */
	static function main() 
	{
		trace("New game !");
		new Game(Lib.current, "https://si0.twimg.com/profile_images/1864751891/Gym-Ball.jpg");
		//new Game(Lib.current, 400, 400, "http://michaelreid.typepad.com/.a/6a00e54edabd838833011168a00f09970c-800wi");
		//new Game(Lib.current, 400, 400, "ball1.jpg");
	}
	/** 
	 * constructor
	 * load the assets and setup the game
	 */
	public function new(gameContainer:Sprite, imageUrl:String) 
	{
		trace("new game "+gameContainer.width+", "+gameContainer.height);

		// scene boundaries
		var sceneWidth = gameContainer.width;
		var sceneHeight = gameContainer.height;
		if (gameContainer == Lib.current)
		{trace("stage "+Lib.current.stage.stageHeight);
			sceneWidth = Lib.current.stage.stageWidth;
			sceneHeight = Lib.current.stage.stageHeight;
		}

		// create the ball
		ball = new Ball(imageUrl, 
			{x:Math.round(sceneWidth/2), y:0}, 
			{x:0, y:0}, 
			{x:10, y:0}, 
			{x:0, y:1}
		);

		// keep a reference to the game container
		this.gameContainer = gameContainer;
		
		// attach the ball to the scene
		gameContainer.addChild (ball);

		// start the loop
		gameContainer.addEventListener(Event.ENTER_FRAME, loop);
		// var timer = new Timer(20);
		// timer.run = loop;
	}
	/**
	 * game loop
	 */
	function loop(event:Event) 
	{
		// scene boundaries
		var sceneWidth = gameContainer.width;
		var sceneHeight = gameContainer.height;
		if (gameContainer == Lib.current)
		{
			sceneWidth = Lib.current.stage.stageWidth;
			sceneHeight = Lib.current.stage.stageHeight;
		}

		// detect collisions left
		if (ball.x < 0)
		{
			ball.x = 0;
			ball.speed.x = -ball.speed.x;
		}
		// detect collisions right
		if (ball.x + ball.width > sceneWidth)
		{
			ball.x = sceneWidth - ball.width;
			ball.speed.x = -ball.speed.x;
		}
		// detect collisions top
		if (ball.y < 0)
		{
			ball.y = 0;
			ball.speed.y = -ball.speed.y;
		}
		// detect collisions bottom
		if (ball.y + ball.height > sceneHeight)
		{
			ball.y = sceneHeight - ball.height;
			ball.speed.y = -ball.speed.y;
		}
		// move the ball
		ball.loop();

	}
}