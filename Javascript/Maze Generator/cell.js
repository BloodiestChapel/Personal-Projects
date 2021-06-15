// Cells
function Cell(i, j) {
    this.i = i;
    this.j = j;
    //           [Top , Right, Bottom, Left]
    this.walls = [true, true , true  , true];
    this.visited = false;

    this.highlight = function() {
        var x = this.i * res;
        var y = this.j * res;
        ctx.fillStyle = 'rgb(255, 0, 100)';
        ctx.fillRect(x, y, res, res);
        
    }

    this.checkNeighbors = function() {
        var neighbors = [];

        var top    = grid[index(i    , j - 1)];
        var right  = grid[index(i + 1, j    )];
        var bottom = grid[index(i    , j + 1)];
        var left   = grid[index(i - 1, j    )];

        if(top && !top.visited) {
            neighbors.push(top);
        }
        if(right && !right.visited) {
            neighbors.push(right);
        }
        if(bottom && !bottom.visited) {
            neighbors.push(bottom);
        }        
        if(left && !left.visited) {
            neighbors.push(left);
        }
        
        if (neighbors.length > 0) {
            var r = Math.floor(Math.random() * (neighbors.length));
            return neighbors[r];
        }
        else {
            return undefined;
        }
    }

    this.show = function() {
        var x = this.i * res;
        var y = this.j * res;

        // If wall exists, draw the line
        if (this.walls[0]) {
            // top-left to top-right
            line(ctx, [x, y]            , [x + res, y]      ); 
        }
        if (this.walls[1]) {
            // top-right to bottom-right
            line(ctx, [x + res, y]      , [x + res, y + res]); 
        }
        if (this.walls[2]) {
            // bottom-right to bottom-left
            line(ctx, [x + res, y + res], [x, y + res]      ); 
        }
        if (this.walls[3]) {
            // bottom-left to top-left
            line(ctx, [x, y + res]      , [x, y]            ); 
        }

        if(this.visited) {
            // ctx.beginPath();
            ctx.fillStyle = "purple";
            ctx.lineWidth = 5;
            ctx.fillRect(x, y, res, res);
        }

    }
}