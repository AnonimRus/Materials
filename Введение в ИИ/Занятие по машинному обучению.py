import numpy as np
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, Ridge, Lasso
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

plt.rcParams['figure.figsize'] = (10, 6)
plt.style.use('seaborn-v0_8-whitegrid')

'''
1) Цена

2) Площадь (S)

3) Этаж
[0, 1]
seconds_floor {1, 2, 3}
midle_floor {4, 5, 6, 7, 8}
high_floor {9, 10, 11, 12, 13, 14, 15, 16, 17}

4) Число комнат

5) Состояние
1 - Плохое
2 - Нормальное
3 - Отличное

6) Район (расстояние до центра)

7) Интерьер
1 - Нет ничего
2 - Мебель
3 - Плазм. хол.
'''

np.random.seed(42)

# Число квартир
n = 150

area = np.random.uniform(30, 120, n)
rooms = np.random.randint(1, 5, n)
floor = np.random.randint(1, 15, n)
total_floor = np.random.randint(5, 20, n)
ceiling_height = np.random.uniform(2.5, 3.2, n)
distance_center = np.random.uniform(1, 20, n)
condition = np.random.randint(0, 3, n)

price = (
    50
    + 3 * area
    + 35 * rooms
    + 2 * floor
    + 4 * total_floor
    + 5 * ceiling_height
    - 8 * distance_center
    + 25 * condition
    + np.random.normal(0, 35, n)
)

# print(f"Первые 10 значений цены: {price[:10]}")

X = np.column_stack((
    area,
    rooms,
    floor,
    total_floor,
    ceiling_height,
    distance_center,
    condition
))

Y = price

# print(f"Размер матрицы X: {X.shape}")
# print(f"Размер матрицы Y: {Y.shape}")

# plt.scatter(area, price)
# plt.xlabel("Площадь")
# plt.ylabel("Цена")
# plt.show()

X_train, X_test, Y_train, Y_test = train_test_split(
    X,
    Y,
    test_size = 0.2,
    random_state = 42
)

model = LinearRegression()
model.fit(X_train, Y_train)
# print(f"Коэффициенты модели: {model.coef_}")

Y_pred = model.predict(X_test)
print(f"Настоящие цены: {Y_test[:10]} \nПредсказанные цены: {Y_pred[:10]}")

mae = mean_absolute_error(Y_test, Y_pred)
mse = mean_squared_error(Y_test, Y_pred)
r2 = r2_score(Y_test, Y_pred)

print(f"Средняя абсолютная ошибка: {mae} \nСредняя квадратическая ошибка: {mse} \nКоэффициент детерминации: {r2}")


random_features = np.random.normal(
    0,
    1,
    (n, 40)
)

X_with_noise = np.column_stack(
    X,
    random_features
)

X_train_noise, X_test_noise, Y_train_noise, Y_test_noise = train_test_split(
    X_with_noise,
    Y,
    test_size = 0.2,
    random_state = 42
)

scaler = StandardScaler()
X_train_noise_scaled = scaler.fit_transform(
    X_train_noise
)
X_test_noise_scales = scaler.transform(
    X_test_noise
)

model_noise = LinearRegression()
model_noise.fit(X_train_noise_scaled, Y_train)
# print(f"Коэффициенты модели: {model.coef_}")

Y_pred_noise = model_noise.predict(X_test_noise_scales)
print(f"Настоящие цены: {Y_test[:10]} \nПредсказанные цены: {Y_pred_noise[:10]}")

mae = mean_absolute_error(Y_test, Y_pred_noise)
mse = mean_squared_error(Y_test, Y_pred_noise)
r2 = r2_score(Y_test, Y_pred_noise)

print(f"Средняя абсолютная ошибка: {mae} \nСредняя квадратическая ошибка: {mse} \nКоэффициент детерминации: {r2}")