# veeeery-simple-ploter


## How does it work?
You simply put values into this function, where a-d are params of x powers in descending order.

a is for x^1, b x^2 etc...
```cpp
void plot(int offsetX, int offsetY ,int a, int b = 0, int c = 0, int d = 0)
```

## Usage
```cpp
screen.plot(32,32,0,0,1);
screen.print();
```
