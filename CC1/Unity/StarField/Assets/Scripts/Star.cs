using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Star {

	public int X { get; protected set; }
	public int Y { get; protected set; }

	public Star() {
		Debug.Log("The Screen Width is " + Screen.Width);
	}
}
