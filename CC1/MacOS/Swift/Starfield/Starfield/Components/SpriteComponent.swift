//
//  SpriteComponent.swift
//  Starfield
//
//  Created by Timothy Dowling on 2018-12-16.
//  Copyright © 2018 Timothy Dowling. All rights reserved.
//

import GameplayKit

class SpriteComponent: GKComponent {
    
    // For this example we are going to use a shape and not a sprite.
    // Everything should continue to work, if we were to change to a
    // sprite though.  Maybe in the future we can add sprites instead of
    // just pixels.
    let sprite = SKShapeNode(circleOfRadius: 2)
    
    init(_ point: CGPoint) {
        super.init()
        
        sprite.position = point
        sprite.fillColor = .white
        sprite.lineWidth = 0
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
