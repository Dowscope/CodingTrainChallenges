//
//  GameScene.swift
//  Starfield
//
//  Created by Timothy Dowling on 2018-12-16.
//  Copyright © 2018 Timothy Dowling. All rights reserved.
//

import SpriteKit
import GameplayKit

class GameScene: SKScene {
    
    let numOfStars = 100
    
    override func didMove(to view: SKView) {
        // Set the coordinates to the middle of the screen.
        anchorPoint = CGPoint(x: 0.5, y: 0.5)
        
        let random = GKARC4RandomSource()
        
        for _ in 0..<numOfStars {
            let x = random.nextInt() % (Int(view.bounds.width) / 2)
            let y = random.nextInt() % (Int(view.bounds.height) / 2)
            let s = Star(CGPoint(x: CGFloat(x), y: CGFloat(y)))
            addChild(s.component(ofType: SpriteComponent.self)!.sprite)
        }
        
    }
}
