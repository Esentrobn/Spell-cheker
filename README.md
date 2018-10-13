# Spell-cheker

while ‘DLinkedBag’ class uses 10 functions including 2 constructors with different parameters. ‘BagInterface’ is the interface used to 
primarily define a protocol. 

Among this class functions one is a constructor function where it calls itself when the class is initialized in the main function.
constructor used to initialize structure data variables head, curr and temp to null. 

The second class function is a void type function called ‘add()’ which doesn’t return anything but takes the two data types the user wants to store in the Linked List. 

The third class function is a bool class function called ‘empty’ which checks if the there is a node before deleting. 

The fourth class function is a void class function called ‘remove()’ which removes the last node upon request.

The fifth class function is a void class function called ‘append ()’ which joins the last list to the list after deletion of the former
linked lists. 
The sixth one is a void class function called ‘clear()’ which deletes a node upon request on any chain except the last node. 

The seventh class function is a void class function called ‘displayBag()’ which outputs data’s saved in the linked list. 
‘setItem()’ and ‘setNext()’ save a data and a pointer in a linked list.

 function returnSimilar() used to spell check a text file a user entered. This function takes in 2 parameters; the first parameter takes an object from the main function while the second parameter is a word we check for spelling error. This function returns a string value that is most similar to the function. It uses for loop to go through each words in the ‘dictionary.txt’ to check for any similar or even same words. 
If similar word found, the function returns it and the main function displays it. 

              Test Run


> a.out

Testing the Link-Based Bag:
The initial bag is empty.
isEmpty: returns 1; should be 1 (true)
The bag contains 0 items:


Add 6 items to the bag: 
The bag contains 6 items:
one five four three two one 

isEmpty: returns 0; should be 0 (false)
getCurrentSize: returns 6; should be 6
Try to add another entry: add("extra") returns 1
contains("three"): returns 1; should be 1 (true)
contains("ten"): returns 0; should be 0 (false)
getFrequencyOf("one"): returns 2 should be 2
remove("one"): returns 1; should be 1 (true)
getFrequencyOf("one"): returns 1 should be 1
remove("one"): returns 1; should be 1 (true)
remove("one"): returns 0; should be 0 (false)

The bag contains 5 items:
five four three two extra 

After clearing the bag, isEmpty: returns 1; should be 1 (true)
All done!
> cd ..

> cd b

> a.out

         This program checks for spelling error
Enter the name of the file that contains words to check: text.txt

The following words in the filetext.txt are not spelled correctly: 
stude:     possible match:study
Reseach:     possible match:research
Resul:     possible match:result
Outpr:     possible match:output

> a.out

         This program checks for spelling error
Enter the name of the file that contains words to check: text
Unable to open text

> exit

exit

