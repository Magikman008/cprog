from funcs import *
from tkinter import *
from tkinter import messagebox as mb

class NemojuError(Exception):
    pass

def wrap(items, chunk_size):
    for i in range(0, len(items), chunk_size):
        yield items[i:i+chunk_size]

def show_fib_arr():
    try:
        n = int(entry_field.get())
        if n <= 0:
            raise ValueError
        if n > 47:
            raise NemojuError
        s = '\n'.join(wrap(', '.join(str(v)
                      for v in fillarray(n)), int(window.winfo_width() / 31)))
        lb_res.configure(text=f"Результат: {s}")
    except ValueError:
        mb.showerror(title='Ошибка ввода!',
                     message=f"Как я тебе выведу {entry_field.get()} чисел?")
    except NemojuError:
        mb.showerror(title='Ошибка ввода!',
                     message=f"Компуктер не хранит такие большие числа...")
    except:
        mb.showerror(title='Ошибка ввода!',
                     message=f"Что ты тут хочешь увидеть? Слона?")

def kill_imposters():
    arr = list(entry_field.get().split())
    try:
        for i in range(len(arr)):
            arr[i] = int(arr[i])

        s = '\n'.join(wrap(', '.join(str(v)
                      for v in copy_elems(arr)), int(window.winfo_width() / 31)))
        lb_res.configure(text=f"Результат: {s}")
    except ValueError:
        mb.showerror(title='Ошибка ввода!',
                     message=f"Ты нажал на кнопку, где есть слово \"чисел\", так сложно ввести числа?")
    except:
        mb.showerror(title='Ошибка ввода!',
                     message=f"Что ты тут хочешь увидеть? Слона?")


window = Tk()
window.title("Нереальная лаба по Си")
window.geometry("1337x1337")

entry_field = Entry(width=25, justify=LEFT, font=("Roboto", 14))
b1 = Button(text='Массив Фибоначчи',  font=(
    "Roboto", 14), command=lambda: show_fib_arr())
b2 = Button(text='Первые вхождения чисел', font=(
    "Roboto", 14), command=lambda: kill_imposters())
lb_res = Label(window, text="Результат:", bg='gray',
               fg='white', font=("Liberation mono", 14))

entry_field.pack(fill=X, padx=5, pady=5)
b1.pack(fill=X, padx=5, pady=5)
b2.pack(fill=X, padx=5, pady=5)
lb_res.pack(anchor=N)

window.mainloop()
