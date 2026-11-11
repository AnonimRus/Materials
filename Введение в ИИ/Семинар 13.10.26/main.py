from sklearn.neural_network import MLPClassifier
import numpy as np
import matplotlib.pyplot as plt

X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
Y = np.array([0, 1, 1, 0])

model = MLPClassifier(hidden_layer_sizes = (4,), 
                      activation = "tanh", 
                      max_iter = 2000,
                      random_state = 42)

model.fit(X, Y)

Ypred = model.predict(X)
print(Ypred)

w11 = model.coefs_[0][0][0]
w12 = model.coefs_[0][1][0]
w21 = model.coefs_[0][0][1]
w22 = model.coefs_[0][1][1]

b1 = model.coefs_[1][0][0]
b2 = model.coefs_[1][1][0]

X_ = [-1, 2]

plt.scatter([0, 1], [0, 1])
plt.scatter([1, 0], [0, 1])
plt.plot(X, (w11*X + b1)/w21)
plt.plot(X, (w12*X + b2)/w22)

plt.show()


x1 = np.linspace(-1, 2, 200)
x2 = np.linspace(-1, 2, 200)

xx, yy = np.meshgrid(x1, x2)

grid = np.column_stack(xx.ravel(), yy.ravel())

# Z = model.predict()

# Модель вероятности сделать (начертить контур plt.conture)