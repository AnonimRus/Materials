import numpy as np
import time

# Задача 1
print("Задача 1")

task1_1 = np.array([1, 2, 3, 4])

task1_2 = np.array([
    [
        [1, 2],
        [3, 4]
    ],
    [
        [5, 6],
        [7, 8]
    ]
])

print(f"- Форма одномерного массива: {task1_1.shape}\n- Форма трёхмерного массива: {task1_2.shape}")

task1_1_float = task1_1.astype(np.float32)
task1_2_float = task1_2.astype(np.float32)

print(f"- Одномерный массив: \n{task1_1_float}\n- Трёхмерный массив: \n{task1_2_float}")


# Задача 2
print("\nЗадача 2")

task2_1 = np.zeros((100, 20))
print(f"- Матрица 100x20, заполненная нулями: \n{task2_1} \n-Форма матрицы: {task2_1.shape}")

task2_2 = np.arange(100)
print(f"- Последовательность от 0 до 100: \n{task2_2}")

task2_3 = np.arange(4, 40, 4)
print(f"- Последовательность от 4 до 40 с шагом 4: \n{task2_3}")

task2_4 = np.arange(0.1, 1, 0.2)
print(f"- Массив от 0.1 до 1 с шагом 0.2: \n{task2_4}")

rng = np.random.default_rng(42)
task2_5 = rng.random(50)
print(f"- 50 равномерно распределённых точек от 0 до 1: \n{task2_5}")

task2_6 = rng.random(50)
task2_6 = task2_6 * 16 + 4
print(f"- 50 равномерно распределённых точек от 4 до 20: \n{task2_6}")


# Задача 3
print("\nЗадача 3")

task3_1 = np.arange(1, 26)

task3_2 = task3_1.reshape(5, 5)

print(f"- Первый ряд: {task3_2[0]}")
print(f"- Последний ряд: {task3_2[-1]}")
print(f"- Первый столбец: {task3_2[:, 0]}")
print(f"- Последний столбец: {task3_2[:, -1]}")
print(f"- Центральный элемент: {task3_2[2][2]}")
print(f"- Квадрат 3x3 в центре: \n{task3_2[1:4, 1:4]}")
for i in range(2, len(task3_2), len(task3_2)//2):
    print(f"- {i}-й столбец: {task3_2[:, i - 1]}")


# Задача 4
print("\nЗадача 4")

task4_1 = np.array([18, 21, 19, 25, 27, 30, 28])
print(f"- Температура в Цельсиях: {task4_1}")

task4_2 = task4_1 * 1.8 + 32
print(f"- Температура в Фарингейтах: {task4_2}")
print(f"- Минимальная температура: {task4_1.min()} / {task4_2.min()}")
print(f"- Максимальная температура: {task4_1.max()} / {task4_2.max()}")

task4_5_1 = task4_1 - task4_1.mean()
task4_5_2 = task4_2 - task4_2.mean()
print(f"- Отклонение каждого значения от среднего: {task4_5_1} / {task4_5_2}")


# Задача 5
print("\nЗадача 5")

start1 = time.time()

task5_1 = []
for i in range(1, 10**6):
    task5_1.append(i**2 + 2 * i + 1)
sum1 = sum(task5_1)

end1 = time.time()

print(f"- Сумма элементов массива (Python): {sum1} \n- Время: {end1 - start1}")

start2 = time.time()

task5_2 = np.arange(1, 10**6)
task5_2 = task5_2**2 + 2 * task5_2 + 1

sum2 = task5_2.sum()

end2 = time.time()

print(f"- Сумма элементов массива (NumPy): {sum2} \n- Время: {end2 - start2}")


# Задача 6
print("\nЗадача 6")

task6_1 = np.arange(0, 24)
task6_1 = task6_1.reshape(4, 6)
print(f"Матрица 4x6: \n- shape: {task6_1.shape} \n- ndim: {task6_1.ndim} \n- size: {task6_1.size}")


task6_2 = np.arange(0, 24)
task6_2 = task6_2.reshape(6, 4)
print(f"Матрица 6x4: \n- shape: {task6_2.shape} \n- ndim: {task6_2.ndim} \n- size: {task6_2.size}")


task6_3 = np.arange(0, 24)
task6_3 = task6_3.reshape(2, 3, 4)
print(f"Матрица 2x3x4: \n- shape: {task6_3.shape} \n- ndim: {task6_3.ndim} \n- size: {task6_3.size}")


task6_4 = np.arange(0, 24)
task6_4 = task6_4.reshape(3, 2, 4)
print(f"Матрица 3x2x4: \n- shape: {task6_4.shape} \n- ndim: {task6_4.ndim} \n- size: {task6_4.size}")


# Задача 7
print("\nЗадача 7")

X = np.arange(10, 91, 10)
X = X.reshape(3, 3)
print(f"- Матрица X: \n{X}\n")

print(f"- Суммы по столбцам: {X.sum(axis = 0)}")
print(f"- Суммы по строкам: {X.sum(axis = 1)}")
print(f"- Среднее по столбцам: {X.mean(axis = 0)}")
print(f"- Среднее по строкам: {X.mean(axis = 1)}")
print(f"- Максимальные по столбцам: {X.max(axis = 0)}")
print(f"- Максимальные по строкам: {X.max(axis = 1)}")


# Задача 8
print("\nЗадача 8")

scores = np.array([45, 67, 89, 32, 91, 76, 54])

print(f"- Массив чисел выше 70: {scores[np.where(scores > 70)]}")
print(f"- Массив чисел ниже 50: {scores[np.where(scores < 50)]}")
print(f"- Массив чисел между 50 и 80: {scores[np.where((scores > 50) & (scores < 80))]}")
print(f"- Количество чисел выше 70: {len(scores[np.where(scores > 70)])}")


# Задача 9
print("\nЗадача 9")

rng = np.random.default_rng(42)
task9_1 = rng.normal(loc = 100, scale = 15, size = 1000)

task9_mean = np.mean(task9_1)
task9_std = np.std(task9_1)

print(f"- Среднее: {np.mean(task9_1)}")
print(f"- Медиана: {np.median(task9_1)}")
print(f"- Среднеквадратичное отклонение: {np.std(task9_1)}")
print(f"- Максимальное значение: {np.max(task9_1)}")
print(f"- Минимальное значение: {np.min(task9_1)}")
print(f"- Элементы для которых x > mean + std (x > {task9_mean + task9_std}): \n{task9_1[np.where(task9_1 > (task9_mean + task9_std))]}")
print(f"- Элементы для которых x < mean - std (x < {task9_mean - task9_std}): \n{task9_1[np.where(task9_1 < (task9_mean - task9_std))]}")


# Задача 10
print("\nЗадача 10")

X = np.arange(10, 91, 10)
X = X.reshape(3, 3)

bias = np.array([1, 2, 3])

print(f"- X + bias: \n{X + bias}")


# Задача 11
print("\nЗадача 11")

print(f"- Система уравнений: \n2x + y = 5\nx + 3y = 6")

task11_A = np.array([[2, 1],
                   [1, 3]])

task11_b = np.array([5, 6])

task11_solve = np.linalg.solve(task11_A, task11_b)

print(f"- Решение: x = {task11_solve[0]}, y = {task11_solve[1]}")


# Задача 12
print("\nЗадача 12")

task12_1 = np.array([1, 2, 3])

task12_2 = np.array([1, 2, 3])
task12_2 = task12_2.reshape(3, 1)

task12_3 = np.array([1, 2, 3])
task12_3 = task12_3.reshape(1, 3)

print(f"- shape: {task12_1.shape} / {task12_2.shape} / {task12_3.shape}")
print(f"- ndim: {task12_1.ndim} / {task12_2.ndim} / {task12_3.ndim}")


# Задача 13
print("\nЗадача 13")

price = np.array([100, 150, 280, 130])
area = np.array([20, 40, 60, 30])
condition = np.array([1, 2, 3, 2])

task13 = np.column_stack((price, area, condition))

print(f"- Итоговая матрица: \n{task13}")
print(f"- Форма матрицы: {task13.shape}")