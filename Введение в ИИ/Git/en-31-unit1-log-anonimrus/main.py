import numpy as np
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, mean_squared_error, log_loss, confusion_matrix, ConfusionMatrixDisplay, classification_report
from sklearn.linear_model import LinearRegression, LogisticRegression

# Задание 1
print("\nЗадание 1. Формирование данных")

my_hours = 10.0

rng = np.random.default_rng(42)
results = rng.random(100)
results[results < 0.5] = 0
results[results >= 0.5] = 1
hours = np.zeros(100)
hours[results == 0] = rng.integers(0, 40, len(hours[results == 0]))*0.25
hours[results == 1] = rng.integers(30, 80, len(hours[results == 1]))*0.25

results = results.reshape(-1, 1)
hours = hours.reshape(-1, 1)

# Задание 2
print("\nЗадание 2. Первичный анализ")

print(f"Результаты студентов: {results[:10].reshape(1, -1)}"
      f"\nЧасов подготовки: {hours[:10].reshape(1, -1)}")

fig1 = plt.figure()

plt.plot(hours[results == 0], results[results == 0], "r.", label = "Не сдал")
plt.plot(hours[results == 1], results[results == 1], "g.", label = "Сдал")
plt.title("Зависимость сдачи от часов")
plt.xlabel("Количество часов подготовки")
plt.ylabel("Результат зачета")
plt.yticks([0, 1], ["Не сдал", "Сдал"])

plt.legend()
plt.show()

print("Визуально видно, что с ростом часов шансы сдать зачет возрастают.")


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

print("Масштабирование нужно, чтобы признаки были в одном масштабе.")


# Задание 4
print("\nЗадание 4. Линейная регрессия")

model_linear = LinearRegression()
model_linear.fit(hours_train_scaled, results_train.ravel())

results_pred_linear = model_linear.predict(hours_test_scaled)
print(f"Реальные результаты: {results_test.reshape(1, -1)}" 
      f"\nПредсказанные результаты: {np.round(results_pred_linear, 2).reshape(1, -1)}")

hours_line = np.linspace(0, 20, 100).reshape(-1, 1)
hours_line_scaled = scaler.transform(hours_line)

fig2 = plt.figure()
plt.plot(hours[results == 0], results[results == 0], "r.", label = "Не сдал")
plt.plot(hours[results == 1], results[results == 1], "g.", label = "Сдал")
plt.plot(hours_line, model_linear.predict(hours_line_scaled), "b", label = "Линейная регрессия")
plt.title("Линейная регрессия")
plt.xlabel("Количество часов подготовки")
plt.ylabel("Результат зачета")
plt.yticks([0, 1], ["Не сдал", "Сдал"])

plt.legend()
plt.show()

print("Ответы на вопросы:"
      "\n1) Линейная регрессия задается прямой y = kx + b, поэтому при крайних значениях уходит за пределы [0, 1]."
      "\n2) Нельзя, потому что вероятность не может быть меньше 0 или больше 1."
      "\n3) Потому что для классов нужна функция, ограниченная диапазоном от 0 до 1.")


# Задание 5
print("\nЗадание 5. Логистическая регрессия")

model_logistic = LogisticRegression(random_state = 42)
model_logistic.fit(hours_train_scaled, results_train.ravel())

results_pred_logistic = model_logistic.predict(hours_test_scaled)
result_prob = model_logistic.predict_proba(hours_test_scaled)[:, 1]

print(f"Реальные результаты: {results_test.reshape(1, -1)}" 
      f"\nПредсказанные результаты: {results_pred_logistic.reshape(1, -1)}")

fig3 = plt.figure()
plt.plot(hours[results == 0], results[results == 0], "r.", label = "Не сдал")
plt.plot(hours[results == 1], results[results == 1], "g.", label = "Сдал")
plt.plot(hours_line, model_logistic.predict_proba(hours_line_scaled)[:, 1], "m", label = "Вероятность сдачи")
plt.title("Логистическая регрессия")
plt.xlabel("Количество часов подготовки")
plt.ylabel("Вероятность сдачи")
plt.yticks([0, 1], ["Не сдал", "Сдал"])

plt.legend()
plt.show()

print("Ответы на вопросы:"
      "\n1) Линейная модель дает бесконечную прямую, а логистическая — сигмоиду, зажатую от 0 до 1."
      "\n2) Вероятность того, что студент с данным временем подготовки сдаст зачет."
      "\n3) С ростом часов подготовки вероятность монотонно растет к 1.")


# Задание 6
print("\nЗадание 6. Предсказание классов")

print(f"Фактический результат: {results_test[:10].reshape(1, -1)}"
      f"\nКоличество часов подготовки: {hours_test[:10].reshape(1, -1)}"
      f"\nПредсказанные результаты: {results_pred_logistic[:10].reshape(1, -1)}")
print(f"Общее число студентов в тестовой выборке: {len(hours_test)}")
print(f"Количество реально сдавших студентов (в тестовой выборке): {len(results_test[results_test == 1])}")
print(f"Количество студентов, сдавших согласно модели (в тестовой выборке): {len(results_pred_logistic[results_pred_logistic == 1])}")


# Задание 7
print("\nЗадание 7. Оценка качества модели")

loss = log_loss(results_test, result_prob)
print(f"Лог-потери: {loss:.4f}")

cm = confusion_matrix(results_test, results_pred_logistic)
print(f"Матрица ошибок:\n{cm}")

ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=['Не сдал', 'Сдал']).plot()
plt.title("Матрица ошибок")
plt.grid(False)
plt.show()

acc = accuracy_score(results_test, results_pred_logistic)
print(f"Доля верных ответов: {acc:.4f}")

print("\nПодробный отчет:")
print(classification_report(results_test, results_pred_logistic, target_names=["Не сдал", "Сдал"]))

print("Ответы на вопросы:"
      "\n1) Метрика оценивает качество именно вероятностей, сильнее штрафуя за уверенность в ложном классе."
      f"\n2) Правильно не сдал: {cm[0, 0]}, правильно сдал: {cm[1, 1]}, ложно сдал: {cm[0, 1]}, ложно не сдал: {cm[1, 0]}."
      "\n3) precision — точность, recall — полнота нахождения класса, f1-score — среднее гармоническое между ними, support — число объектов.")


# Итог
print("\nИТОГ")

my_hours_scaled = scaler.transform(np.array([[my_hours]]))
my_pred = model_logistic.predict(my_hours_scaled)[0]
my_prob = model_logistic.predict_proba(my_hours_scaled)[0, 1]

print(f"Мои часы подготовки: {my_hours}")
print(f"Вероятность сдачи: {my_prob * 100:.2f}%")
print(f"Предсказание: {'Сдал' if my_pred == 1 else 'Не сдал'}")

print("\nОтветы на вопросы:"
      "\n1) Напрямую: больше часов — выше вероятность сдачи."
      "\n2) Она ограничена отрезком [0, 1] и интерпретируется как вероятность."
      "\n3) Степень уверенности классификатора."
      "\n4) Число правильных и ошибочных классификаций по каждому классу."
      "\n5) Штраф за неточность предсказанных вероятностей."
      "\n6) Общий процент правильных предсказаний."
      "\n7) Ошибка I рода: студент не сдал, а предсказали 'сдал'. Ошибка II рода: студент сдал, а предсказали 'не сдал'."
      "\n8) Нет, 100% гарантии нет, так как между 7.5 и 9.75 часами есть область пересечения результатов.")