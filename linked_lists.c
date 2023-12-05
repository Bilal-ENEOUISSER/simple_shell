<<<<<<< HEAD
#include "shell.h"
=======
#include "lists.h"
>>>>>>> f07b586d481862df583cd45793823758d4fdc0f9

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: head
 * Return: integer
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *ptr = h;
	int count = 0;

	while (ptr != NULL)
	{
		count++;
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	return (count);
}
/**
 * listint_len -  returns the number of elements in a linked listint_t list.
 * @h: head
 * Return: integer
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *ptr = h;
	int count = 0;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: address of head
 * @str: string.
 * Return: adddress of new element.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *ptr;
	int i = 0;
	unsigned int len = 0;

	if (head == NULL || str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	ptr = malloc(sizeof(list_t));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr->str = strdup(str);
	ptr->len = len;
	ptr->next = *head;
	*head = ptr;
	return (*head);
}
/**
 * add_node_end -  adds a new node at the end of a list_t list.
 * @head: address of head
 * @str: string
 * Return: address
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *ptr;
	list_t *temp;
	int i = 0;
	unsigned int len = 0;

	if (head == NULL || str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	temp = malloc(sizeof(list_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp->str = strdup(str);
	temp->len = len;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	return (*head);
}
/**
 * free_list - function that frees a list_t list.
 * @head: head
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *temp;

	if (head)
	{
		while (head != NULL)
		{
			temp = head->next;
			free(head->str);
			free(head);
			head = temp;
		}
	}
}
