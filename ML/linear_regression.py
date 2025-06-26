import numpy as np
import matplotlib.pyplot as plt

class LinearRegression:
    w: np.matrix = None
    lr: float = 0.1
    bias: float = 1
    def __init__(self, lr: float = 0.1):
        self.lr = lr
        pass

    def predict(self, x: np.ndarray):
        x_with_x0 = np.insert(x, 0, 1, axis = 0)
        if self.w is None:
            self.w = np.array(np.ones(x_with_x0.shape))
        return self.w.T @ x_with_x0

    def compute_cost_single(self, x: np.ndarray, y: np.ndarray):
        # Implementing Mean Squared Error
        val = (self.predict(x) - y) ** 2
        return val
    
    def compute_cost_all(self, x: np.ndarray, y: np.ndarray):
        sum = 0
        for x_i, y_i in zip(x, y):
            sum += self.compute_cost_single(x_i, y_i)
        return sum

    def fit(self, x : np.ndarray, y : np.ndarray):
        x_with_x0 = np.insert(x, 0, 1, axis = 0)
        print("X: ", x_with_x0)
        self.w = self.w + self.lr * (y - self.predict(x)) * x_with_x0
        return self.w

if __name__ == "__main__":
    model = LinearRegression(lr = 0.1)
    # Dataset, comprised of 5 points
    x = np.array([[1], [2], [3], [4], [5]])
    # Labels for the 5 points
    y = np.array([[2], [8], [3], [10], [12]])
    for i in range(1):
        for x_i, y_i in zip(x,y):
            pred = model.predict(x_i)
            # print(model.compute_cost_single(x_i, y_i))
            print("=========")
            print(model.fit(x_i, y_i))
            print("Cost: ", model.compute_cost_all(x, y)[0])

    w = model.w
    print(w)
    w_x = np.linspace(-2, 10, 100)
    w_y = w[1] * w_x + w[0]
    plt.plot(w_x, w_y)
    plt.plot(x, y, 'ro')

    plt.show()
    # print(model.predict(x))
    #print(type(x))