#include "Array.h"
#include "Queue.h"
#include "Stack.h"
#include "IIterator.h"
#include <iostream>
using namespace std;

#define SIZE 10

void test_stack() {
	int amount_elements_in_container = 10;
	std::cout << "НАЧАЛО ТЕСТА STACK!!!\n\n";

	std::cout << "Создание стека...\n";
	Stack stack;
	Stack stack_2;
	std::cout << "Успешное создание стека\n";

	std::cout << "Заполнение стека с помощью push()...\n";
	for (int i = 0; i < amount_elements_in_container; i++) {
		stack.push(i * 1.5 + 1.12 * i - 2 * i + 1);
	}

	for (int i = 0; i < amount_elements_in_container; i++) {
		stack_2.push(i * 1.1 + 1.12 * i - 1 * i + 1);
	}
	std::cout << "size stack == " << stack.getSize() << std::endl;

	std::cout << "Получение значения элемента стека по индексу...\n";
	std::cout << "stack[7] == " << stack[7] << std::endl;
	std::cout << "stack[0] == " << stack[0] << std::endl;
	std::cout << "stack[9] == " << stack[9] << std::endl;

	std::cout << "Удаление элемента по индексу 9...\n ";
	stack.remove(stack.at(9));

	std::cout << "Удаление элемента по индексу 0...\n";
	stack.remove(stack.at(0));

	std::cout << "Удаление элемента по индексу 7...\n";
	stack.remove(stack.at(7));

	std::cout << "Вывод стека через оператор []...\n";
	for (int i = 0; i < stack.getSize(); i++) {
		std::cout << "stack[" << i << "] == " << stack[i] << std::endl;
	}
	std::cout << "Конец вывода стека через []...\n";

	std::cout << "Изменение стека с помощью []...\n";
	for (int i = 0; i < stack.getSize(); i++) {
		stack[i] = i * 1.09 + 5.1 * i - 12.3;
	}
	std::cout << "Финальный вывод после изменения с помощью []...\n";
	for (int i = 0; i < stack.getSize(); i++) {
		std::cout << "stack[" << i << "] == " << stack[i] << std::endl;
	}

	std::cout << "Вывод второго стека...\n";
	for (int i = 0; i < stack_2.getSize(); i++) {
		std::cout << "stack_2[" << i << "] == " << stack_2[i] << std::endl;
	}
	std::cout << "Конец вывода второго стека...\n";

	std::cout << "Метод join с вторым стеком...\n" << std::endl;
	stack.join(&stack_2);

	std::cout << "Финальный вывод после join...\n";
	for (int i = 0; i < stack.getSize(); i++) {
		std::cout << "stack[" << i << "] == " << stack[i] << std::endl;
	}

	std::cout << "Метод clear1...\n";
	stack.clear();
	std::cout << "Метод clear2...\n";
	stack_2.clear();
	std::cout << "КОНЕЦ ТЕСТА STACK!!!\n\n";

}

void test_queue() {
	std::cout << "НАЧАЛО ТЕСТА QUEUE!!!\n\n";

	Queue queue;

	std::cout << "Добавление элементов в очередь с помощью push()...\n";
	for (int i = 0; i < 5; ++i) {
		queue.push(i * 2.5 + 3.7);
	}

	std::cout << "Размер очереди: " << queue.getSize() << std::endl;

	std::cout << "Очередь пуста? " << (queue.isEmpty() ? "Да" : "Нет") << std::endl;

	std::cout << "Элементы очереди через []:\n";
	for (int i = 0; i < queue.getSize(); ++i) {
		std::cout << "queue[" << i << "] = " << queue[i] << std::endl;
	}

	std::cout << "Элемент по индексу 2 через at(): " << *(queue.get_data(2)) << std::endl;

	queue.remove(queue.at(2));
	std::cout << "Элемент по индексу 2 удален\n";

	std::cout << "Элементы после удаления:\n";
	for (int i = 0; i < queue.getSize(); ++i) {
		std::cout << "queue[" << i << "] = " << queue[i] << std::endl;
	}

	Queue queue_2;

	for (int i = 0; i < 3; ++i) {
		queue_2.push(i * 1.7 + 4.2);
	}

	std::cout << "Присоединение второй очереди к первой...\n";
	queue.join(&queue_2);

	std::cout << "Элементы после присоединения второй очереди:\n";
	for (int i = 0; i < queue.getSize(); ++i) {
		std::cout << "queue[" << i << "] = " << queue[i] << std::endl;
	}

	queue.clear();
	std::cout << "Очередь очищена\n";
	std::cout << "КОНЕЦ ТЕСТА QUEUE!!!\n\n";
}

int main()
{
	system("chcp 1251");
	// Array a; 
	 Stack b;
	//Queue c;
	// a.push(1.2); a.push(2.3); a.push(13.7); a.push(0.5);
	// b.push(1.2 ); b.push(2.3); b.push(13.7); b.push(0.5);
   /*  for (IIterator* i = a.begin(); !i->isEqual(a.end()); i->next())
		 cout << *(double*)i->get() << " ";
	 cout << endl;*/
	/*c.push(1.2); c.push(2.3); c.push(13.7); c.push(0.5);
	for (IIterator* i = c.begin(); !i->isEqual(c.end()); i->next())
		cout << "el = " << *(double*)i->get() << " ";
	cout << endl;*/
	b.push(1.2); b.push(2.3); b.push(13.7); b.push(0.5);
   for (IIterator* i = b.begin(); !i->isEqual(b.end()); i->next())
	   cout << "el = " << *(double*)i->get() << " ";
   cout << endl;

	test_stack();
	//test_queue();
	return 0;
}