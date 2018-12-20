//
//  Star.swift
//  Starfield
//
//  Created by Timothy Dowling on 2018-12-16.
//  Copyright © 2018 Timothy Dowling. All rights reserved.
//

import GameplayKit

class Star: GKEntity {
    
    let screenSize: CGSize
    public var zPos: CGFloat = 0
    
    init(_ point: CGPoint, screenSize: CGSize) {
        // Set the reference to the width o
        self.screenSize = screenSize
        super.init()
        
        addComponent(SpriteComponent(point))
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
}
