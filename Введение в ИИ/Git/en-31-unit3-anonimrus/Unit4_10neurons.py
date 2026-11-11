from sklearn.datasets import load_digits
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, ConfusionMatrixDisplay
from sklearn.preprocessing import StandardScaler

import numpy as np
import matplotlib.pyplot as plt
import os

def print_header(text):
    try:
        width = os.get_terminal_size().columns
    except OSError:
        width = 80
    text =' ' + text + ' '
    print('\n' + "="*width)
    print(text.center(width,"="))
    print("="*width + '\n')

def print_paragraph(text):
    try:
        width = os.get_terminal_size().columns
    except OSError:
        width = 80
    text = ' ' + text + ' '
    print('\n' + text.center(width,"#") + '\n')

#################################
# Задание №1 -- подготовка данных
#################################
print_header('Задание №1 - подготовка данных')

digits = load_digits()

# 1. Выведи данные, правильный ответ для цифры.
print_paragraph('1. Выведи данные, правильный ответ для цифры в строку.')

X = digits.data
y = digits.target

print('Данные для первых 10 объектов:')
print(f'{X[:10]}')
print('Правильные числа для 10 объектов:')
print(f'{y[:10]}')

print_paragraph('2. Построй первые 10 изображений:')
fig, axes = plt.subplots(nrows = 2, ncols = 5, figsize = (10, 5))

for i, ax in enumerate(axes.flat):
    ax.imshow(digits.images[i], cmap = "gray")

plt.tight_layout()
plt.show(block = True)

# Ответь на вопрос: Как изображение преобразуется в данные?
print('Как изображение преобразуется в данные?')
print('Изображение переводится в матрицу, где значение элементов - градация серого (от чёрного (0) до белого (16))')

print_paragraph('3. Определи и выведи в консоль:')

print('- количество объектов: ', f'{len(X)}')
print('- количество признаков: ', f'{X.shape[1]}')
print('- количество классов: ', '10')
print('- диапазон значений признаков: ', f'от {X.min()} до {X.max()}')
print('- количество объектов каждого класса: ', f'~ {len(X) // 10}')

print_paragraph('4. Раздели данные на тестовую и тренировочную выборки (Используй параметр stratify=y).')
X_train, X_test, y_train, y_test = train_test_split(
    X, y, 
    test_size = 0.2, 
    random_state = 42,
    stratify = y)

print("Данные разделены на тестовую и тренировочную выборки")

print_paragraph('5. Масштабирование')
scaler = StandardScaler()
X_train_s = scaler.fit_transform(X_train)
X_test_s = scaler.transform(X_test)

print("Признаки отмасштабированы")

print_paragraph('6. Выведи максимальное и минимальное значение \
 для немасштабированных и \
 масштабированных признаков')
print('Максимальное значение без масштаба:', X_train.max())
print('Минимальное значение без масштаба:', X_train.min())
print('Максимальное значение с масштабом:', X_train_s.max())
print('Минимальное значение с масштабом:', X_train_s.min())

print('Объяснение полученных чисел:')
print('Исходные признаки имеют значения интенсивности пикселей от 0 до 16. После применения StandardScaler '
      'данные центрируются (среднее значение каждого признака становится близким к 0, а стандартное отклонение к 1), '
      'из-за чего диапазон значений смещается в область отрицательных и положительных чисел примерно от -3 до +3.')

#################################
# Задание №2 -- Логистическая регрессия
#################################
print_header('Задание №2 Логистическая регрессия')

print_paragraph('1. Обучи модель LogRegression')

model_log = LogisticRegression()
model_log.fit(X_train_s, y_train)

print("Модель LogisticRegression обучена")

print_paragraph('2. Сохрани и выведи accuracy и число верных/неверных значений для тестовой и тренировочной выборок.')

X_train_log_pred = model_log.predict(X_train_s)
X_test_log_pred = model_log.predict(X_test_s)

acc_log_train = accuracy_score(y_train, X_train_log_pred)
acc_log_test = accuracy_score(y_test, X_test_log_pred)

vern_log_train = int(acc_log_train * len(X_train))
error_log_train = len(X_train) - vern_log_train

vern_log_test = int(acc_log_test * len(X_test))
error_log_test = len(X_test) - vern_log_test

print('Тренировочная выборка')
print('accuracy = ', f"{100 * acc_log_train: .2f}%")
print('Число верных значений', f"{vern_log_train}")
print('Число неверно определенных значений', f"{error_log_train}")

print('Тестовая выборка')
print('accuracy = ', f"{100 * acc_log_test: .2f}%")
print('Число верных значений', f"{vern_log_test}")
print('Число неверно определенных значений', f"{error_log_test}")


#################################
# Задание №3 -- Первый многослойный персептрон
#################################
print_header('Задание №3. Первый многослойный персептрон')

print_paragraph('1. Используйте MLPClassifier')

model_perc = MLPClassifier( hidden_layer_sizes=(10,), activation="relu", max_iter=500, random_state=42 )

print_paragraph('2. Обучите модель и определите accuracy на train и test выборке')

model_perc.fit(X_train_s, y_train)

X_train_perc_pred = model_perc.predict(X_train_s)
X_test_perc_pred = model_perc.predict(X_test_s)

acc_perc_train = accuracy_score(y_train, X_train_perc_pred)
acc_perc_test = accuracy_score(y_test, X_test_perc_pred)

vern_perc_train = int(acc_perc_train * len(X_train))
error_perc_train = len(X_train) - vern_perc_train
index_error_perc_train = np.where(X_train_perc_pred != y_train)[0]

vern_perc_test = int(acc_perc_test * len(X_test))
error_perc_test = len(X_test) - vern_perc_test
index_error_perc_test = np.where(X_test_perc_pred != y_test)[0]

print('Тренировочная выборка')
print('accuracy = ', f"{100 * acc_perc_train: .2f}%")
print('Число верных значений', f"{vern_perc_train}")
print('Число неверно определенных значений', f"{error_perc_train}")

print('Тестовая выборка')
print('accuracy = ', f"{100 * acc_perc_test: .2f}%")
print('Число верных значений', f"{vern_perc_test}")
print('Число неверно определенных значений', f"{error_perc_test}")


print_paragraph('3. Выведите изображения чисел, в которых где MLP ошибся (imshow смотри выше):')
print('Номера объектов, где MLP ошибся:')
print(f"В тренировочной выборке: {list(map(int, index_error_perc_train))}\n"
      f"В тестовой выборке: {list(map(int, index_error_perc_test))}\n"
      f"Верные цифры:\n"
      f"- в тренировочной выборке: {y_train[index_error_perc_train]}\n"
      f"- в тестовой выборке: {y_test[index_error_perc_test]}")


images_error_perc = [X_train[i].reshape(8, 8) for i in index_error_perc_train] + [X_test[i].reshape(8, 8) for i in index_error_perc_test]
if len(images_error_perc) > 0:
    fig, axes = plt.subplots(nrows = 1, ncols = len(images_error_perc), figsize = (15, 3))
    if len(images_error_perc) == 1:
        axes = [axes]
    for i, ax in enumerate(axes):
        ax.imshow(images_error_perc[i], cmap = "gray")
    plt.tight_layout()
    plt.show(block = True)


#################################
# Задание №4 -- Ошибки
#################################
print_header('Задание №4. Ошибки')
print_paragraph("1. Построй матрицу ошибок")

cm = confusion_matrix(y_test, X_test_perc_pred)
print("Матрица ошибок:")
print(f"{cm}")

# изображение матрицы ошибок
fig, ax = plt.subplots(figsize=(8, 6))
disp = ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=model_perc.classes_)
disp.plot(cmap="Blues", ax=ax)
plt.title("Матрица ошибок (MLP 10 нейронов)")
plt.tight_layout()
plt.show(block=True)

print()
print('1. Какие цифры модель чаще всего путает?')
print('Модель чаще всего путает цифры 1 и 9, 1 и 8.')

print('2. Какие цифры распознаются наиболее уверенно?')
print('Наиболее уверенно распознаются цифры 2, 3, 5, 6')

print('3. Найдите несколько неправильно классифицированных изображений.')
print(f'Индексы ошибочных объектов в тестовой выборке: {list(map(int, index_error_perc_test))}')

print('Покажите их и подпишите')
if len(index_error_perc_test) > 0:
    num_errors = min(5, len(index_error_perc_test))
    fig, axes = plt.subplots(nrows=1, ncols=num_errors, figsize=(3 * num_errors, 3))
    if num_errors == 1:
        axes = [axes]
    for idx, ax in enumerate(axes):
        err_idx = index_error_perc_test[idx]
        ax.imshow(X_test[err_idx].reshape(8, 8), cmap="gray")
        ax.set_title(f"Истинное: {y_test[err_idx]}\nПредсказание: {X_test_perc_pred[err_idx]}")
        ax.axis('off')
    plt.tight_layout()
    plt.show(block=True)

#########################
# Задание №5 Вскрытие
#########################
print_header('Вскрытие')
print_paragraph("1. Получите веса моделей (model.coefs_)")

coefs_perc = model_perc.coefs_
weights = coefs_perc[0]

print_paragraph("2. Измените и выведите матрицу весов 8x8 для одного нейрона")
print(f"{weights[:, 0]}")
print_paragraph("3. Постройте изображение весов через imshow")  

plt.imshow(
    	weights[:, 0].reshape(8, 8),
    	cmap="gray"
	)
plt.colorbar()
plt.show(block = True)


print("1. Объясните, что означают выведенные весы.")
print("Вклад в результат выхода нейрона в итоговый ответ")
print("2. Можно ли по визуализации весов понять, на какие области изображения реагирует нейрон?")
print("Нейрон реагирует сильнее на светлые области данного изображения (веса в них больше) и слабее на тёмные области данного изображения (веса в них меньше)")


#################################
# Поменяйте число нейронов на 10 и проведите то же исследование в другом файле.
#################################