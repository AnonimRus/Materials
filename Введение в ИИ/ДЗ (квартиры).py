import numpy as np
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, Ridge, Lasso
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

area = np.array([39.3, 77.7, 75.9, 57.8, 54.4, 93.2, 82.7, 80.2, 40.7, 47.6]) # Площадь
rooms = np.array([1, 2, 3, 2, 2, 3, 3, 3, 2, 2]) # Кол-во комнат
floor = np.array([2, 4, 7, 4, 2, 2, 4, 3, 5, 2]) # Этаж
total_floor = np.array([5, 4, 8, 20, 7, 2, 8, 9, 5, 5]) # Всего этажей
distance_center = np.array([3, 3, 3, 3, 10, 4, 8, 6, 1, 7]) # Расстояние до центра (км)
infrastructure = np.array([2, 2, 2, 2, 2, 1, 2, 2, 1, 2]) # Инфраструктура (0, 1, 2, 3)
condition = np.array([1, 2, 1, 2, 2, 1, 2, 2, 2, 2]) # Состояние (0, 1, 2, 3)
furniture = np.array([0, 2, 0, 0, 0, 0, 2, 3, 2, 2]) # Интерьер (0, 1, 2, 3)
new_building = np.array([1, 1, 1, 1, 1, 0, 0, 0, 0, 0]) # Новостройка (0, 1)
price = np.array([5698500, 10320000, 8652600, 7051600, 7505820, 8388000, 8450000, 9200000, 12800000, 4500000]) # Цена

X = np.column_stack((
    area,
    rooms,
    floor,
    total_floor,
    distance_center,
    infrastructure,
    condition,
    furniture,
    new_building
))

Y = price


model = LinearRegression()
model.fit(X, Y)

X_test = np.column_stack((
    42.2,
    1,
    4,
    6,
    8,
    2,
    2,
    2,
    0
))

Y_test = [6100000]

Y_pred = model.predict(X_test)
print(f"Настоящие цены: {Y_test[:10]} \nПредсказанные цены: {Y_pred[:10]}")

mae = mean_absolute_error(Y_test, Y_pred)
mse = mean_squared_error(Y_test, Y_pred)
r2 = r2_score(Y_test, Y_pred)

print(f"Средняя абсолютная ошибка: {mae} \nСредняя квадратическая ошибка: {mse} \nКоэффициент детерминации: {r2}")