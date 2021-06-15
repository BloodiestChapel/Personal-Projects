// Score
var score = '0';

// Pixel height and width
var pixel = 32;

// Snake Parameters
var snake;

// Food parameters
var food;

function pickLocation() {
    var cols = floor(width / pixel);
    var rows = floor(height / pixel);
    food = createVector(floor(random(cols)), floor(random(rows)));
    food.mult(pixel);
}

function setup() {
    // Get canvas ready
    createCanvas(640, 640);

    frameRate(8);

    snake = new Snake();
    pickLocation();

}

function draw() {
    background(51);

    // Display Score
    fill(255);
    textAlign(TOP, LEFT);
    textSize(16);
    text(`Score: ${snake.tailLength}`, 16, 32);
    // text('James wins no matter what', 16, 64);
    // text('Unless stiff knees is around', 16, 64);


    snake.update();
    snake.show();

    if (snake.eat(food)) {
        pickLocation();
    }

    fill(255, 0, 100);
    rect(food.x, food.y, pixel, pixel);
}

function keyPressed() {
    if (keyCode === UP_ARROW) {
        snake.direction(0, -1);
    }
    else if (keyCode === DOWN_ARROW) {
        snake.direction(0, 1);
    }
    else if (keyCode === LEFT_ARROW) {
        snake.direction(-1, 0);
    }
    else if (keyCode === RIGHT_ARROW) {
        snake.direction(1, 0);
    }
}