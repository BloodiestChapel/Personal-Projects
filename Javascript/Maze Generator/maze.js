var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");
ctx.fillStyle = "black";
ctx.fillRect(0, 0, canvas.width, canvas.height);

var cols, rows;
var res = 35;
var grid = [];
var stack = [];
var currCell;


function setup() {
    cols = Math.floor(canvas.width / res);
    rows = Math.floor(canvas.height / res);

    // Make cells
    for(var j = 0; j < rows; j++) {
        for(var i = 0; i < cols; i++) {
            var cell = new Cell(i, j);
            grid.push(cell);
        }
    }
    currCell = grid[0];
}

function draw() {
    
    // Show cells
    for(var i = 0; i < grid.length; i++) {
        grid[i].show();
    }

    currCell.visited = true;
    currCell.highlight();

    // Step 1
    var nextCell = currCell.checkNeighbors();       
    
    if (nextCell) {
        nextCell.visited = true;
        // Step 2
        stack.push(currCell);
        // Step 3
        removeWalls(currCell, nextCell);
        // Step 4
        currCell = nextCell;
    }
    else if (stack.length > 0) {
        currCell = stack.pop();
        
    }
}

// Easy line function
function line(ctx, begin, end, stroke = 'white', width = 1) {
    if (stroke) {
        ctx.strokeStyle = stroke;
    }

    if (width) {
        ctx.lineWidth = width;
    }

    ctx.beginPath();
    ctx.moveTo(...begin);
    ctx.lineTo(...end);
    ctx.stroke();
}

// return index
function index(i, j) {
    if (i < 0 || j < 0 || i > cols - 1 || j > rows - 1) {
        return -1;
    }
    return i + j * cols;
}

function removeWalls(a, b) {
    // Left & right
    var x = a.i - b.i;
    if (x === 1) {
        a.walls[3] = false;
        b.walls[1] = false;
    }
    else if (x === -1) {
        a.walls[1] = false;
        b.walls[3] = false;
    }
    
    // Top and bottom
    var y = a.j - b.j;
    if (y === 1) {
        a.walls[0] = false;
        b.walls[2] = false;
    }
    else if (y === -1) {
        a.walls[2] = false;
        b.walls[0] = false;
    }
}

setup();
var frameRate = setInterval(draw, 1);