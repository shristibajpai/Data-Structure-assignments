#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
    char name[50];
    char phone[15];
    struct contact *next;
};
struct contact *head = NULL;

// Insert at the beginning

void insertBeginning()
{
    struct contact *newNode;
    newNode = (struct contact *)malloc(sizeof(struct contact));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }
    printf("Enter name");
    scanf("%49s", newNode->name);
    printf("Enter phone number");
    scanf("%14s", newNode->phone);

    newNode->next = head;
    head = newNode;
    printf("Contact added sucessfully ");
}
// Insert at the end
void insertEnd()
{
    struct contact *newNode, *temp;
    newNode = (struct contact *)malloc(sizeof(struct contact));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }
    printf("Enter the name");
    scanf("%49s", newNode->name);
    printf("Enter phone number");
    scanf("%14s", newNode->phone);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Contact added succesfully ");
}
// delete contact by name

void deletecontact()
{
    char name[50];
    struct contact *temp, *prev;
    printf("Enter the name to delete");
    scanf("%49s", name);
    temp = head;
    prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Deleted successfully");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Contact not found!\n");
}
// search by contact name

void searchContact()
{
    char name[50];
    struct contact *temp;

    printf("Enter name to search: ");
    scanf("%s", name);
    temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Contact Found!\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            return;
        }

        temp = temp->next;
    }

    printf("Contact not found!\n");
}

// display all contact
void displayContact()
{
    struct contact *temp;
    if (head == NULL)
    {
        printf("Contact list is empty");
        return;
    }
    temp = head;
    printf("\n Contact list \n");
    while (temp != NULL)
    {
        printf("Name : %s \n ", temp->name);
        printf("Phone :%s \n", temp->phone);
        printf("----------\n");
        temp = temp->next;
    }
}
// Free all allocated memory
void freeMemory()
{
    struct contact *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            deletecontact();
            break;
        case 4:
            searchContact();
            break;
        case 5:
            displayContact();
            break;
        case 6:
            freeMemory();
            printf("Memory released. Program ended.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
