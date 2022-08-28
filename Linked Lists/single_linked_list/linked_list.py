class Node:
    def __init__(self,data = None,next_address = None):
        self.data = data
        self.next = next_address
        print('Node Created for {}'.format(data))
class Linked_List:
    def __init__(self):
        self.head = None
        print('Linked List is Created ')
    
    def add_data_in_beginning(self,data):
        self.head = Node(data,self.head)
        return '{} Added in the Begining'.format(data)
    
    def add_data_in_end(self,data):
        if self.head == None:
            return self.add_data_in_beginning(data)
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = Node(data,None)
            return '{} Added at the end'.format(data)
        
    def add_data_in_middle(self,before_element, insert_element):
        if self.head == None:
            return self.add_data_in_beginning(data)
        else:
            temp = self.head
            while temp:
                if temp.data == before_element:
                    temp.next = Node(insert_element,temp.next)
                    return 'Element Inserted Succesfully'
                temp = temp.next
            return 'There is no element in the linked list'        
        
    def remove_data(self,data):
        remove_index = self.get_data_index(data)
        if remove_index == 0:
            return 'There is no data present in the given link'
        
        if remove_index == 1 :
            self.head = self.head.next
            self.print_list()
            return 'please check the data: {} entered is deleted or not'.format(data)
        
        temp = self.head
        while temp:
            if temp.next.data == data:
                temp.next = temp.next.next
                break
            temp = temp.next
        self.print_list()
        return 'please check the data: {} entered is deleted or not'.format(data)
    
    def inser_data(self,after_data,insert_data):
        after_index = self.get_data_index(after_data)
        
        if after_index == 0:
            output = self.add_data_in_beginning(insert_data)
            return output
        
        if after_index == 1:
            output = self.add_data_in_middle(after_data,insert_data)
            return output
        
        temp = self.head
        while temp:
            if temp.next.data == after_data:
                node = Node(after_data,temp.next.next)
                temp.next = node
                break
            temp = temp.next
        return 'Data Added Successfully'
    
    def modify_data(self,find_data,replace_data):
        temp = self.head
        while temp:
            if temp.data == find_data:
                temp.data = replace_data
                return 'Data Modified Successfully'
            temp = temp.next
        return 'Could not find data {} in the linked list'.format(find_data)
        
    def get_data_index(self,data):
        index = 0
        temp = self.head
        while temp:
            index = index +1
            if temp.data == data:
                return index
            temp = temp.next
        return 0
        
    def get_length(self):
        index = 0
        temp = self.head
        while temp:
            index = index + 1
            temp = temp.next
        return index        

    def search_element(self,data):
        temp = self.head
        index = 1
        while temp:
            if temp.data == data:
                return 'Match Found data {} in the index {}'.format(temp.data,index)
            temp = temp.next
            index = index + 1
    
    def print_list(self):
        if self.head == None:
            print('Linked List is Empty')
        itr= self.head
        while itr:
            print(itr.data,end='-->')
            itr = itr.next
        print('Null')
ll=Linked_List()
print(ll.add_data_in_beginning(10))
print(ll.add_data_in_end(30))
print(ll.add_data_in_middle(10,20))
print(ll.search_element(20))
ll.print_list()
print('\nNow Deleting data 10')
print(ll.remove_data(10))
ll.print_list()
print('\nModifying_data 20 with 100')
print(ll.modify_data(20,100))
print(ll.print_list())