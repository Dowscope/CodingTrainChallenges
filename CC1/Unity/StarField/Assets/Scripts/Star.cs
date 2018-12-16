using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Star {

	public int X { get; protected set; }
	public int Y { get; protected set; }

	public Star() {
		X = Random.Range(0, Screen.width);
		Y = Random.Range(0, Screen.height);
	}
}
