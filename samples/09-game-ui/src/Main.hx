/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import cocktail.api.CocktailView;
import flash.display.Sprite;
import flash.text.TextField;
import js.Lib;

/**
 * This sample show how to use cocktail as a
 * webview, and how to mix the flash and DOM api
 */
class Main extends Sprite
{
	/** 
	 * main function to start the game on the stage with default params
	 */
	static function main() 
	{
		flash.Lib.current.addChild( new Main() );
	}
	
	/**
	 * cocktail's "web view"
	 */
	var cv:CocktailView;
	
	/**
	 * flash interface's root sprite
	 */
	var mc:Sprite;
	
	/**
	 * flash game object
	 */
	var game:Game;
	
	var resizeCallbacks : List<Void->Void>;
	public function new()
	{
		super();
		haxe.Firebug.redirectTraces();
		addEventListener( flash.events.Event.ADDED_TO_STAGE, onAdded );
	}

	function onAdded(_)
	{trace("onAdded");

		stage.align = flash.display.StageAlign.TOP_LEFT;
		stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;

		removeEventListener(flash.events.Event.ADDED_TO_STAGE, onAdded);
		stage.addEventListener(flash.events.Event.RESIZE, resize);

		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		init();
		#end
	}

	var inited : Bool;
	function resize(e) 
	{
		//reset();
		if (!inited) init();

		updateViewportPosition();
		game.setSize(stage.stageWidth, stage.stageHeight);
	}

	function init()
	{trace("init");
		inited = true;
		initFlash();
		initCocktailView();
	}

	/**
	 * build flash interface
	 */
	function initFlash()
	{trace("initFlash");
		mc = new Sprite();
		game = new Game(mc, "ball1.jpg", stage.stageWidth, stage.stageHeight);
		flash.Lib.current.addChild(mc);
	}
	/**
	 * place the webview in the flash/NME app
	 */	
	function updateViewportPosition()
	{trace("updateViewportPosition "+stage.stageWidth);
		cv.viewport = { 
			x:0,
			y:0,
			width:stage.stageWidth,
			height:stage.stageHeight
		};
	}
	/**
	 * build cocktail interface
	 */
	function initCocktailView()
	{
		trace("initCocktailView");

		//build a cocktail webview
		cv = new CocktailView();
		
		updateViewportPosition();
		
		//use an external html for the document
		cv.loadURL("game-ui.html");
		
		//wait for document ready
		cv.window.onload = function(e) { 
			
			//attach cocktail root to native flash root
			flash.Lib.current.addChild(cv.root);

			// add the logic to the UIs
			initUIs();
		};
	}
	/**
	 * init the UI after the html is loaded
	 */
	function refresh() 
	{
		cast(cv.document.getElementById("gravityValueX")).value = game.ball.gravity.x;
		cast(cv.document.getElementById("gravityValueY")).value = game.ball.gravity.y;
	}
	/**
	 * init the UI after the html is loaded
	 */
	function initUIs() 
	{
		refresh();

		//access to DOM
		var button = cv.document.getElementById("inverseGravity");
		button.onclick = inverseGravity;

		var button = cv.document.getElementById("stopBall");
		button.onclick = stopBall;

		var text = cv.document.getElementById("gravityValueX");
		text.oninput = gravityValueXChanged;

		var text = cv.document.getElementById("gravityValueY");
		text.oninput = gravityValueYChanged;
	}
	/**
	 * callback for the html element
	 */
	function gravityValueXChanged(event:js.Dom.Event) 
	{
		var value:String = cast(event.target).value;
		trace(event.target+" - "+value);
		game.ball.gravity.x = Std.parseFloat(value);
	}
	/**
	 * callback for the html element
	 */
	function gravityValueYChanged(event:js.Dom.Event) 
	{
		var value:String = cast(event.target).value;
		trace(event.target+" - "+value);
		game.ball.gravity.y = Std.parseFloat(value);
	}
	/**
	 * callback for the html element
	 */
	function inverseGravity(event:js.Dom.Event) 
	{
		event.preventDefault();
		game.ball.gravity.x = -game.ball.gravity.x;
		game.ball.gravity.y = -game.ball.gravity.y;
		refresh();
	}
	/**
	 * callback for the html element
	 */
	function stopBall(event:js.Dom.Event) 
	{
		event.preventDefault();
		game.ball.speed.x = 0;
		game.ball.speed.y = 0;
		refresh();
	}
}
