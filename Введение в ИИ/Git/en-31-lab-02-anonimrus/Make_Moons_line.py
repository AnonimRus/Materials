from sklearn.datasets import make_moons, make_circles
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, ConfusionMatrixDisplay
from sklearn.preprocessing import StandardScaler

import matplotlib.colors as mcolors
import numpy as np
import matplotlib.pyplot as plt
import os

X, y = make_moons(n_samples = 800,
                  noise = 0.2,
                  random_state = 42)

X_one = [[X[i][0] for i in range(len(X)) if y[i] == 1], [X[i][1] for i in range(len(X)) if y[i] == 1]]
X_zero = [[X[i][0] for i in range(len(X)) if y[i] == 0], [X[i][1] for i in range(len(X)) if y[i] == 0]]

plt.plot(X_one[0], X_one[1], ".g")
plt.plot(X_zero[0], X_zero[1], ".b")
plt.tight_layout()
# plt.show(block = True)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, 
    test_size = 0.2,
    random_state = 42,
    stratify = y)

scaler = StandardScaler()
X_train_s = scaler.fit_transform(X_train)
X_test_s = scaler.transform(X_test)

model = MLPClassifier( hidden_layer_sizes=(32,), activation="relu", max_iter=1000, random_state=42 )

model.fit(X_train_s, y_train)

X_train_perc_pred = model.predict(X_train_s)
X_test_perc_pred = model.predict(X_test_s)

acc_perc_train = accuracy_score(y_train, X_train_perc_pred)
acc_perc_test = accuracy_score(y_test, X_test_perc_pred)

vern_perc_train = int(acc_perc_train * len(X_train))
error_perc_train = len(X_train) - vern_perc_train
index_error_perc_train = np.where(X_train_perc_pred != y_train)[0]

vern_perc_test = int(acc_perc_test * len(X_test))
error_perc_test = len(X_test) - vern_perc_test
index_error_perc_test = np.where(X_test_perc_pred != y_test)[0]

X_error_tr = [[X_train[i][0], X_train[i][1]] for i in index_error_perc_train]
X_error_ts = [[X_test[i][0],  X_test[i][1]] for i in index_error_perc_test]

y_error_tr = y_train[index_error_perc_train]
y_error_ts = y_test[index_error_perc_test]


X_errors_0 = []
X_errors_1 = []

for i in range(len(X_error_tr)):
    if y_error_tr[i] == 0:
        X_errors_0.append([X_error_tr[i][0], X_error_tr[i][1]])
    elif y_error_tr[i] == 1:
        X_errors_1.append([X_error_tr[i][0], X_error_tr[i][1]])

for i in range(len(X_error_ts)):
    if y_error_ts[i] == 0:
        X_errors_0.append([X_error_ts[i][0], X_error_ts[i][1]])
    elif y_error_ts[i] == 1:
        X_errors_1.append([X_error_ts[i][0], X_error_ts[i][1]])

# plt.plot(X_one[0], X_one[1], ".g")
# plt.plot(X_zero[0], X_zero[1], ".b")
# plt.plot(X_errors_0[0], X_errors_0[1], ".r")
# plt.plot(X_errors_1[0], X_errors_1[1], ".y")
# plt.tight_layout()
# plt.show(block = True)


x1_min, x1_max = X[:, 0].min() - 0.5, X[:, 0].max() + 0.5
x2_min, x2_max = X[:, 1].min() - 0.5, X[:, 1].max() + 0.5


xx1, xx2 = np.linspace(x1_min, x1_max, 800), np.linspace(x2_min, x2_max, 800)

XX1, XX2 = np.meshgrid(xx1, xx2)

grid = np.c_[XX1.ravel(), XX2.ravel()]
grid_s = scaler.transform(grid)

y = model.predict(grid_s).reshape(XX1.shape)

my_colors = ["#0482FF", "#21DC00"]
my_cmap = mcolors.LinearSegmentedColormap.from_list('my_custom_cmap', my_colors)

plt.pcolormesh(XX1, XX2, y, cmap = my_cmap)
plt.show()