import numpy as np
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split       		# разделение данных на train/test
from sklearn.preprocessing import StandardScaler          		# стандартизация признаков (нормализация, масштабирование)
from sklearn.metrics import accuracy_score, mean_squared_error  	# метрики качества (среднеквадратичная ошибка, абсолютная ошибка и т.д.)
from sklearn.linear_model import LinearRegression, LogisticRegression  	# линейная регрессия и классификация

# Задание 1
print("\nЗадание 1. Формирование данных")

# my_hours = int(input("Введите ваше количество часов: "))

rng = np.random.default_rng(42)
results = rng.random(100)
results[results < 0.5] = 0
results[results >= 0.5] = 1
hours = np.zeros(100)
hours[results == 0] = rng.integers(0, 40, len(hours[results == 0]))*0.25
hours[results == 1] = rng.integers(40, 80, len(hours[results == 1]))*0.25

results = results.reshape(-1, 1)
hours = hours.reshape(-1, 1)

# Задание 2
print("\nЗадание 2. Первичный анализ")

print(f"Результаты студентов: {results[:10].reshape(1, -1)}"
      f"\nЧасов подготовки: {hours[:10].reshape(1, -1)}")

fig1 = plt.figure()

plt.plot(hours[results == 0], results[results == 0], "r.", label = "Не сдал")
plt.plot(hours[results == 1], results[results == 1], "g.", label = "Сдал")
plt.title("Результаты")
plt.xlabel("Количество часов подготовки")
plt.ylabel("Результат")

plt.legend()
plt.show(block=False)
plt.close(fig1)

print("Визуально можно заметить, что при достижении определённого количества часов, после полосы несдач начинается полоса сдач")


# Задание 3
print("\nЗадание 3. Разделение данных и масштабирование")

hours_train, hours_test, results_train, results_test = train_test_split(
    hours,
    results,
    test_size = 0.2,
    random_state = 42
)

scaler = StandardScaler()

hours_train_scaled = scaler.fit_transform(hours_train)
hours_test_scaled = scaler.transform(hours_test)


# Задание 4
print("\nЗадание 4. LinearRegression")

model_linear = LinearRegression()
model_linear.fit(hours_train_scaled, results_train)

results_pred_linear = model_linear.predict(results_test)
print(f"Реальные результаты: {results_test.reshape(1, -1)}" 
    f"\nПредсказанные результаты: {results_pred_linear.reshape(1, -1)}")

# fig2 = plt.figure()
# plt.plot(hours[results == 0], results[results == 0], "r.", label = "Не сдал")
# plt.plot(hours[results == 1], results[results == 1], "g.", label = "Сдал")
# plt.plot(hours_test, model_linear.coef_[0]*hours_test + model_linear.intercept_, "b", label = "Линейная регрессия")
# # plt.xlim(-1, 21)
# # plt.ylim(-0.1, 1.1)
# plt.title("Результаты")
# plt.xlabel("Количество часов подготовки")
# plt.ylabel("Результат")

# plt.legend()
# plt.show()
# plt.close(fig2)


print("Ответы на вопросы: \n1) - \n2) - \n3) -")


# Задание 5
print("\nЗадание 5. LogisticRegression")

model_logistic = LogisticRegression()
model_logistic.fit(hours_train_scaled, results_train)

results_pred_logistic = model_logistic.predict(results_test)
result_prob = model_logistic.predict_proba(hours_test)

# print(accuracy_score(results_test, results_pred_logistic))
# print(result_prob)
print(f"Реальные результаты: {results_test.reshape(1, -1)}" 
    f"\nПредсказанные результаты: {results_pred_logistic.reshape(1, -1)}")



# Задание 6
print("\nЗадание 6. Предсказание классов")

print(f"Фактический результат: {results_test[:10].reshape(1, -1)}"
      f"\nКоличество часов подготовки: {hours_test[:10].reshape(1, -1)}"
      f"\nПредсказанный результаты: {results_pred_logistic[:10].reshape(1, -1)}")
print(f"Общее число студентов в тестовой выборке: {len(hours_test)}")
print(f"Количество реально сдавших студентов (в тестовой выборке): {len(results_test[results_test == 1])}")
print(f"Количество студентов, сдавших согласно модели (в тестовой выборке): {len(results_pred_logistic[results_pred_logistic == 1])}")


# Задание 7
print("\nЗадание 7. Оценка качества модели")

