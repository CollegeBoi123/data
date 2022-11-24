#include<iostream>
using namespace std;


struct node 
{
    struct node * prev;
    int data;
    struct node * next;
};

struct node* add(struct node* head,int data);
void create_list(struct node * head,int n);
void display_for(struct node * head);
struct node * mid(struct node * head,int data,int pos);
void display_back(struct node * head);
struct node * inst_beg(struct node * head,int data);
int count(struct node * head);
void del_pos(struct node **head,int pos);



int main()
{  
    
    int n;
    cout<<"Enter the number of nodes "<<endl;
    cin>>n;
    if(n<=0)
    {
        cout<<"Zero node list"<<endl;
        return 0;
    }
    else
    {
        struct node * head = (struct node *)malloc(sizeof(struct node*));
        head->prev = NULL;
        head->next = NULL;
        create_list(head,n);
        cout<<endl;
        int ch;
        while(ch!= 7)
        {
            cout<<"1. Display list values"<<endl;
            cout<<"2. Add element at end"<<endl;
            cout<<"3. Add element at first"<<endl;
            cout<<"4. Add element at desired position other than (1)"<<endl;
            cout<<"5. Deletion of node"<<endl;
            cout<<"6. Counting number of nodes"<<endl;
            cout<<"7. Exit"<<endl;
            cout<<"Enter your Choice "<<endl,cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    display_for(head);
                    break;
                }
                case 2:
                {
                    int t;
                    cout<<"Enter the data value-- ",cin>>t;
                    add(head,t);
                    display_for(head);
                    break;
                }
                case 3:
                {
                    int t;
                    cout<<"Enter the data value-- ",cin>>t;
                    head = inst_beg(head,t);
                    display_for(head);
                    break;
                }
                case 4:
                {
                    int f,pos;
                    cout<<"Enter the data -- ",cin>>f;
                    cout<<"Enter the position -- ",cin>>pos;
                    mid(head,f,pos);
                    
                    break;
                }
                case 5:
                {
                    int p;
                    cout<<"Enter the position to be deleted -- ",cin>>p;
                    del_pos(&head,p);
                    break;
                }
                case 6:
                {
                    int y = count(head);
                    cout<<"Number of nodes "<<y<<endl;
                    break;
                }
                case 7:
                    cout<<"END....... !!!!";
                    break;
                default:
                    cout<<"Invalid Choice";
                    break;
            }
            cout<<"\n"<<endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
};




struct node* add(struct node* head,int data)
{
    struct node *ptr;
    struct node* temp = (struct node *)malloc(sizeof(struct node *));
    temp->next = NULL;
    temp->data = data;
    temp->prev = NULL;
    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

void create_list(struct node * head,int n)
{
    int y;
    cout<<"Enter data for node 1"<<endl;
    cin>>head->data;
    for(int i = 1;i<n;i++)
    {
        cout<<"Enter data for node "<<i+1<<endl;
        cin>>y;
        add(head,y);
    }
}

void display_for(struct node * head)
{
    struct node* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout<<"Value is "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

void display_back(struct node * head)
{
    cout<<"In Reverse order"<<endl;
    struct node* ptr = head ,*last = NULL;
    while(ptr!= NULL)
    {
        last = ptr;
        ptr = ptr->next;
    }
    while(last!= NULL)
    {
        cout<<"Value is "<<last->data<<endl;
        last = last->prev;
    }
    
}


struct node * inst_beg(struct node * head,int data)
{
    struct node* temp = (struct node *)malloc(sizeof(struct node *));
    temp->next = head;
    temp->data = data;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
    return head;
}


int count(struct node * head)
{
    int c = 0;
    struct node * ptr;
    ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        c++;
    }
    return c;
}

struct node * mid(struct node * head,int data,int pos)
{
    struct node * ptr = head;
    struct node* temp = (struct node *)malloc(sizeof(struct node *));
    temp->next = NULL;
    temp->data = data;
    temp->prev = NULL;
    pos--;
    int n = count(head);
    if((pos > 0) and (pos <=n))
    {
        while(pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        display_for(head);
    }
    else
    {
        cout<<"Cannot be added in list"<<endl;
    }
    return head;
}




void del_pos(struct node **head,int pos)
{
    struct node *current = *head;
    struct node *previous = *head;
    if(*head ==  NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(pos == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
        //ead->prev = NULL;
    }
    else if(pos >0)
    {
        int n = count(*head);
        if((pos != 1) and (pos <(n+1)))
        {
             while(pos != 1)
            {
                previous = current;
                current = current->next;
                pos--;
            }
            previous->next = current->next;
            free(current);
            current = NULL;
            display_for(*head);
        }
        else
        {
            cout<<"Out of Range"<<endl;
        }
    }
    else
    {
        cout<<"Out of range"<<endl;
    }
}










