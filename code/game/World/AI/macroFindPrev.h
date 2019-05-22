// find food
    bool blockL = false;
    bool blockR = false;
    for(int i : {idPosition-1, idPosition+1,idPosition-2, idPosition+2,idPosition-3, idPosition+3})
    {
        int dir = 1;
        if(i < idPosition ) 
        {   
            dir = -1;
        }
        
        if(i > idPosition && blockR == true) continue;
        if(i < idPosition && blockL == true) continue;

        Tile* tile = w->tiles.getTile(i);
        if( tile != nullptr )
        {