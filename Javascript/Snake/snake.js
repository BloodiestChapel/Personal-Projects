// Snake Object
function Snake() {
    this.x = floor(random(floor(width / pixel))) * pixel;
    this.y = floor(random(floor(width / pixel))) * pixel;

    this.xSpeed = 0;
    this.ySpeed = 0;

    this.tailLength = 0;
    this.tail = [];

    this.direction = function(x, y) {
        this.xSpeed = x;
        this.ySpeed = y;
    }

    this.update = function() {
        if(this.tailLength === this.tail.length) {
            for (var i = 0; i < this.tail.length - 1; i++) {
                this.tail[i] = this.tail[i + 1];
            }
        }
        this.tail[this.tailLength - 1] = createVector(this.x, this.y);
        
        this.x = this.x + this.xSpeed * pixel;
        this.y = this.y + this.ySpeed * pixel;

        this.wrap();
        this.death();

    }

    this.wrap = function() {
        // If snake hits a boundary, 
        // put it on the other side
        if (this.x > width - pixel) {
            this.x = 0;
        }
        else if (this.x < 0) {
            this.x = width - pixel;
        }
        else if (this.y > height - pixel) {
            this.y = 0;
        }
        else if (this.y < 0) {
            this.y = height - pixel;
        }
    }

    this.death = function() {
        for (var i = 0; i < this.tail.length; i++) {
            var pos = this.tail[i];
            var d = dist(this.x, this.y, pos.x, pos.y);
            if (d < 1) {
                this.tailLength = 0;
                this.tail = [];
            }
        }
    }

    this.eat = function(pos) {
        var distance = dist(this.x, this.y, pos.x, pos.y);
        if(distance < 1) {
            this.tailLength++;
            return true;
        }
        else {
            return false;
        }

    }

    this.show = function() {
        for(var i = 0; i < this.tail.length; i++) {
            fill(255);
            rect(this.tail[i].x, this.tail[i].y, pixel, pixel);
        }

        fill(255);
        rect(this.x, this.y, pixel, pixel);
    }
}