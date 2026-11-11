from sklearn.datasets import make_moons, make_circles
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

# 1. Выведи данные, правильный ответ для цифры.
print_paragraph('1. Выведи данные, правильный ответ для цифры в строку.')

X, y = make_circles(n_samples = 800,
                    noise = 0.08,
                    factor = 0.35,
                    random_state = 42)

print('Данные для первых 10 объектов:')
print(f'{X[:10]}')
print('Правильные категории для 10 объектов:')
print(f'{y[:10]}')

X_one = [[X[i][0] for i in range(len(X)) if y[i] == 1], [X[i][1] for i in range(len(X)) if y[i] == 1]]

X_zero = [[X[i][0] for i in range(len(X)) if y[i] == 0], [X[i][1] for i in range(len(X)) if y[i] == 0]]

plt.plot(X_one[0], X_one[1], ".g")
plt.plot(X_zero[0], X_zero[1], ".b")
plt.tight_layout()
plt.show(block = True)

print_paragraph('3. Определи и выведи в консоль:')

print('- количество объектов: ', f'{len(X)}')
print('- количество признаков: ', f'{X.shape[1]}')
print('- количество классов: ', '2')
print('- диапазон значений признаков: ', f'от {X.min()} до {X.max()}')
print('- количество объектов каждого класса: ', f'~ {len(X) // 2}')

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
print('Исходные признаки лежат примерно от -1.2 до 1.2. После применения StandardScaler '
      'данные центрируются (среднее значение каждого признака становится близким к 0, а стандартное отклонение к 1), '
      'и диапазон становится примерно от -2.3 до +2.2. Масштаб подбирается только по обучающей выборке.')


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

model_perc = MLPClassifier( hidden_layer_sizes=(32,), activation="relu", max_iter=1000, random_state=42 )

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


print_paragraph('3. Выведите изображения точек, в которых где MLP ошибся (imshow смотри выше):')
print('Номера объектов, где MLP ошибся:')
print(f"В тренировочной выборке: {list(map(int, index_error_perc_train))}\n"
      f"В тестовой выборке: {list(map(int, index_error_perc_test))}\n"
      f"Верные цифры:\n"
      f"- в тренировочной выборке: {y_train[index_error_perc_train]}\n"
      f"- в тестовой выборке: {y_test[index_error_perc_test]}")

X_error = [[X_train[i][0] for i in index_error_perc_train] + [X_test[i][0] for i in index_error_perc_test], 
           [X_train[i][1] for i in index_error_perc_train] + [X_test[i][1] for i in index_error_perc_test]] 

plt.plot(X_one[0], X_one[1], ".g")
plt.plot(X_zero[0], X_zero[1], ".b")
plt.plot(X_error[0], X_error[1], ".r")
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

fig, ax = plt.subplots(figsize=(8, 6))
disp = ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=model_perc.classes_)
disp.plot(cmap="Blues", ax=ax)
plt.title("Матрица ошибок (MLP 32 нейрона)")
plt.tight_layout()
plt.show(block = True)


#########################
# Задание №5 Вскрытие
#########################
print_header('Вскрытие')
print_paragraph("1. Получите веса моделей (model.coefs_)")

coefs_perc = model_perc.coefs_
weights = coefs_perc[0]

print_paragraph("2. Измените и выведите матрицу весов для одного нейрона")
print(f"{weights[:, 10]}")
print_paragraph("3. Постройте изображение весов через imshow")  

plt.imshow(
    	weights[:, 10].reshape(1, 2),
    	cmap="gray"
	)
plt.colorbar()
plt.tight_layout()
plt.show(block = True)


print("1. Объясните, что означают выведенные весы.")
print("Вклад в результат выхода нейрона в итоговый ответ")
print("2. Можно ли по визуализации весов понять, на какие области изображения реагирует нейрон?")
print("Нейрон реагирует сильнее на светлые области данного изображения (веса в них больше) и слабее на тёмные области данного изображения (веса в них меньше)")


#################################
# Задание №6 -- Исследование архитектуры MLP
#################################
print_header("Задание №6 Исследование архитектуры MLP")

print_paragraph('1. Обучите модели со следующими архитектурами:')

MLP_all = [MLPClassifier(hidden_layer_sizes=(4,), activation="relu", max_iter=2000, random_state=42 ), 
           MLPClassifier(hidden_layer_sizes=(16,), activation="relu", max_iter=1000, random_state=42 ), 
           MLPClassifier(hidden_layer_sizes=(64,), activation="relu", max_iter=1000, random_state=42 ), 
           MLPClassifier(hidden_layer_sizes=(16, 16), activation="relu", max_iter=500, random_state=42 ), 
           MLPClassifier(hidden_layer_sizes=(64, 32), activation="relu", max_iter=500, random_state=42 )]

print_paragraph("2. Для каждой модели определите accuracy на train, test и количество итераций обучения.")

accuracy_train_MLP = []
accuracy_test_MLP = []
n_iter_MPL = []

for model in MLP_all:
    model.fit(X_train_s, y_train)
    n_iter_MPL.append(model.n_iter_)

    X_train_MLP_pred = model.predict(X_train_s)
    X_test_MLP_pred = model.predict(X_test_s)

    accuracy_train_MLP.append(accuracy_score(y_train, X_train_MLP_pred))
    accuracy_test_MLP.append(accuracy_score(y_test, X_test_MLP_pred))

print("Модели обучены, данные сохранены")

print_paragraph("3. Выведи общий результат в таблицу")

for i, model in enumerate(MLP_all):
    print(f"Модель - {model.hidden_layer_sizes}, n_iter = {n_iter_MPL[i]}, "
          f"accuracy_train = {accuracy_train_MLP[i]*100: .2f}, accuracy_test = {accuracy_test_MLP[i]*100: .2f}\n")

print()
print('1. Какая архитектура лучше справляется с нелинейной границей классов?')
print('- Справились все архитектуры, на тесте везде 100%. Даже сеть из 4 нейронов дала около 100% (на train 99.84%). '
      'Логистическая регрессия на этих данных дала только около 50%.')
print('2. Всегда ли увеличение числа нейронов улучшает тестовую точность?')
print('- Нет, точность уже 100% и дальше расти некуда. Больше нейронов влияет только на количество итераций (у (4,) 1000, у (64, 32) 127).')
print('3. Что меняется при переходе от одного скрытого слоя к двум?')
print('- Количество итераций уменьшается ((16,) - 571, (16, 16) - 227), а точность остаётся 100%.')
print('4. Есть ли разрыв между точностью на обучающей и тестовой выборках?')
print('- Нет, и на train, и на test точность 100%.')

#################################
# Задание №7 -- Функция активации
#################################
print_header('Задание №5 Функция активации')

print_paragraph("1. Возьми архитектуру (16, 16).")
print_paragraph('2. Обучи модели с активациями ["relu", "logistic", "tanh", "identity"]')

func_activations = [MLPClassifier(hidden_layer_sizes=(16, 16), activation="relu", max_iter=500, random_state=42 ), 
                    MLPClassifier(hidden_layer_sizes=(16, 16), activation="logistic", max_iter=500, random_state=42 ),
                    MLPClassifier(hidden_layer_sizes=(16, 16), activation="tanh", max_iter=500, random_state=42 ),
                    MLPClassifier(hidden_layer_sizes=(16, 16), activation="identity", max_iter=500, random_state=42 )]

accuracy_train_func = []
accuracy_test_func = []
n_iter_func = []

for model in func_activations:
    model.fit(X_train_s, y_train)
    n_iter_func.append(model.n_iter_)

    X_train_func_pred = model.predict(X_train_s)
    X_test_func_pred = model.predict(X_test_s)

    accuracy_train_func.append(accuracy_score(y_train, X_train_func_pred))
    accuracy_test_func.append(accuracy_score(y_test, X_test_func_pred))

print_paragraph("3. Выведи общий результат в таблицу")

for i, model in enumerate(func_activations):
    print(f"Модель - {model.activation}, n_iter = {n_iter_func[i]}, "
          f"accuracy_train = {accuracy_train_func[i]*100: .2f}, accuracy_test = {accuracy_test_func[i]*100: .2f}\n")


print()
print('Почему сеть с identity не может эффективно построить сложную нелинейную границу, даже если в ней несколько скрытых слоёв?')
print('- Функция identity ничего не меняет, поэтому несколько слоёв это просто несколько линейных преобразований подряд, '
      'которые можно заменить одним. Сеть строит только прямую границу, а здесь классы лежат одно кольцо внутри другого, '
      'поэтому прямой их не разделить и accuracy около 50%.')