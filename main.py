class Node:
    def __init__(self, data):
        self.info = data
        self.link = None

class LinkedList:
    def __init__(self):
        self.start = None

    def create_list(self):
        if self.start is None:
            n = int(input("\nEnter the number of nodes: "))
            if n != 0:
                data = int(input("\nEnter number to be inserted: "))
                self.start = Node(data)
                temp = self.start
                for _ in range(n - 1):
                    data = int(input("\nEnter number to be inserted: "))
                    new_node = Node(data)
                    temp.link = new_node
                    temp = new_node
                print("\nThe list is created")
        else:
            print("\nThe list is already created")

    def traverse(self):
        if self.start is None:
            print("\nList is empty")
        else:
            temp = self.start
            while temp is not None:
                print(temp.info, end="\t")
                temp = temp.link

    def insert_at_front(self):
        data = int(input("\nEnter number to be inserted: "))
        temp = Node(data)
        temp.link = self.start
        self.start = temp

    def insert_at_end(self):
        data = int(input("\nEnter number to be inserted: "))
        temp = Node(data)
        if self.start is None:
            self.start = temp
        else:
            head = self.start
            while head.link is not None:
                head = head.link
            head.link = temp

    def insert_at_position(self):
        pos = int(input("\nEnter position: "))
        data = int(input("Enter data: "))
        new_node = Node(data)
        if pos == 1:
            new_node.link = self.start
            self.start = new_node
            return
        temp = self.start
        for _ in range(pos - 2):
            if temp is None:
                print("\nPosition not found")
                return
            temp = temp.link
        new_node.link = temp.link
        temp.link = new_node

    def delete_first(self):
        if self.start is None:
            print("\nList is empty")
        else:
            temp = self.start
            self.start = self.start.link
            del temp

    def delete_end(self):
        if self.start is None:
            print("\nList is empty")
        elif self.start.link is None:
            del self.start
            self.start = None
        else:
            temp = self.start
            while temp.link is not None:
                prev = temp
                temp = temp.link
            del temp
            prev.link = None

    def delete_position(self):
        if self.start is None:
            print("\nList is empty")
        else:
            pos = int(input("\nEnter position: "))
            if pos == 1:
                temp = self.start
                self.start = temp.link
                del temp
                return
            temp = self.start
            for _ in range(pos - 2):
                if temp is None:
                    print("\nPosition not found")
                    return
                temp = temp.link
            if temp.link is None:
                print("\nPosition not found")
                return
            position = temp.link
            temp.link = position.link
            del position

if __name__ == "__main__":
    linked_list = LinkedList()

    while True:
        print("\n1. See list")
        print("2. For insertion at starting")
        print("3. For insertion at end")
        print("4. For insertion at any point")
        print("5. For deletion of first element")
        print("6. For deletion of last element")
        print("7. For deletion of element at any position")
        print("8. To exit")

        choice = int(input("\nEnter Choice: "))

        if choice == 1:
            linked_list.traverse()
        elif choice == 2:
            linked_list.insert_at_front()
        elif choice == 3:
            linked_list.insert_at_end()
        elif choice == 4:
            linked_list.insert_at_position()
        elif choice == 5:
            linked_list.delete_first()
        elif choice == 6:
            linked_list.delete_end()
        elif choice == 7:
            linked_list.delete_position()
        elif choice == 8:
            break
        else:
            print("Incorrect Choice")
