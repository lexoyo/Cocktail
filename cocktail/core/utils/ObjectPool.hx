/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.utils;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ObjectPool<T:IPoolable>
{
	private var _pool:Array<T>;
	
	private var _freeObjectIndex:Int;

	private var _pooledClass:Class<T>;
	
	private var _args:Array<Dynamic>;
	
	public function new(pooledClass:Class<T>) 
	{
		_pooledClass = pooledClass;
		_pool = new Array<T>();
		_freeObjectIndex = -1;
		_args = [];
	}
	
	public function get():T
	{
		if (_freeObjectIndex == -1)
		{
			return Type.createInstance(_pooledClass, _args);
		}
		else
		{
			var object:T = _pool[_freeObjectIndex];
			_freeObjectIndex--;
			return object;
		}
	}
	
	public function release(object:T):Void
	{
		object.reset();
		_freeObjectIndex++;
		_pool[_freeObjectIndex] = object;
	}
}