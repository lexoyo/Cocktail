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
	{trace("new");
		super();
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
			width:Std.int(stage.stageWidth / 2),
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
			
			var document = cv.document;
			
			//access to DOM
			var button = document.getElementById("button");
			button.onclick = function(e) {
				//toggle flash interface visibility
				//mc.visible = !mc.visible;
				game.ball.gravity.x = -game.ball.gravity.x;
				game.ball.gravity.y = -game.ball.gravity.y;
			}
			
			//attach cocktail root to native flash root
			flash.Lib.current.addChild(cv.root);
		};
	}
}
