# READ ME
READ ME FINDROOTS

In order to run the code you will need to open the CMD and get to the directory where your executable file named findroots(.exe) is at. 
Once you are in the directory, you will need to execute it in the CMD and click enter. In the following line enter the values of the constants a,b,c and d of the third order polynomial. 

Now I will explain the logic I used to develop the code.  

First, in the main menu I added 4 variables named a,b,c and d. 
These variables will get the values entered when you execute the findroots(.exe) file.
After I recieved my parameters I created a conditional element (if) that analyzes the values of a,b,c and d. 
The first condition analyzes the case when all of the values are equal to zero (this would mean that there is no existing polynomial), and therefore it prints an empty array in the console({}). 
In case that the first condition doesn't apply, in other words in case that a,b,c or d have a nonzero value, there is three functions called "RaicesRacionales", "DivSint", and "Ceros" that will be executed and will give us the real roots of the polynomial.

NOTE: I decided to do functions instead of adding all of the code in the main section just for order reason and so the code would look cleaner.
NOTE: In order to evaluate and find the zeros, i used the rational root theorem. 

RaicesRacionales Function description:
The first function called "RaicesRacionales" has four int type arguments/parameters, these arguments will be the initial a,b,c and d values that you enter in the console. 
NOTE: I evaluated these conditions because the rational root theorem states that in order to find the possible roots of a third order polynomial you must evaluate the factors of the variable d, remembering that these factor might be negative or positive values.
Inside the function there is another conditional elemente (if) that evaluates if the value of the d variable is greater than zero, equal to zero or less than zero. 
The first condition that evaluates if d is smaller than zero, contains a "for" that has a variable named i that will be equal to the value of d, and it will run until i is less than or equal to the negative value of d, also the i value goes on 1 by 1 increments. 
If our d value is less than zero it means that we have a negative number and therefore in order to obtain all of its factors, we have to evaluate the "for" from the negative value of d all the way to the positive number of d which is represented in the "for" as the second argument (-d, since negative 1 times a negative value will give you a positive number).
Inside this for, there is another conditional element "if" that evaluates if the residue  of the division of d/i is equal to zero. If it is equal to zero we ensure that our i value is a factor of d. Then inside this "if", I saved these i values inside an array named "mult", each value is saved in the position determined by a j variiable that will be incrementing as the cycle progresses. 
Then inside this "if" I added another "if" that evaluates if my next increment value is equal to zero. We have to evaluate this condition because we do not desire to have divisions by zero since they are undefined. Therefore inside this condition we increment the value of i+2.
The second condition that evaluates if my value of d is equal to zero was created because if d is equal to zero it doesn't have any factors and therefore in the array that we defined as "mult", I set a value of 0 in the position "mult[0]".
The third part of the condition that evualuates if d is greater than zero functions similarly to the first condition that evaluates id d is smaller than 0. The only thing that changes here are the parameter for the initial "for". This is due to the fact that since our d value is positive and we wish to obtain negative and positive factor of the d value, our range will change from the value of -d all the way to the value of d and our i will be incrementing 1 by 1 just as in the first comdition. The other part of the code inside these "for", is the same and works the same way as the one found in the "for" of the first condition.
Last but not least in the same function "RaicesRacionales", I added a "for" that will evaluate the values of the factors that we previously saved in the array "mult[]" in an equation that has the form of a third order polynomial. 
If the evaluation of the polynomial with that factor is equal to zero, it will save the evalue of the factor into a new array called "raiz[]". It is important to save these values becasue as we know if the evaluation of the polynomial is equal to zero when evaluated in "x", then x is a root or zero of the polynomial.

DivSint Function Description:
In the function called "RaicesRacionales", we calculated a value of "x" that was a zero of our polynomial. 
Following the Rational Root Theorem logic, once we have at least one zero we can use that value of "x" and do a sintetic division. 
The residue constants of this division will give us the constants(a,b, and c) of a second order polynomial.
This function called "DivSint" gets five type int arguments/parameters, that represent the value of "x" that makes our third order polynomial equal to zero, the value of a, the value of b, the value of c, and the value of d. 
Then we set the value of a0, (the a constant for the second order polynomial) as the value of our a constant since that value stays the same.
Then we set the value of b0 (constant b of a second order polynomial), as the addition of the multiplicacion of "x" by "a" plus "b".
Then we set the value of c0 (constant b of a second order polynomial), as the addition of the multiplicacion of "x" by "b0" plus "c".
Then we set the value of d0 (constant b of a second order polynomial), as the addition of the multiplicacion of "x" by "c0" plus "d".
Keep in mind that d0 has to equal zero.

Ceros Function Description:
Now that we have the constant values for a0,b0 and c0 and we have a quadratic equation, we can use the quadratic formula in order to find the roots of the second order polynomial.
However, the code only asks us for the real roots and therefore we have to ignore the imaginary roots. 
We know that if the argument within the square root is a negative number then we will be dealing with imaginary numbers and therefore roots. 
Therefore, I first calcualted that argument and assigned it to a type int varbale named "det". Then I evaualted if this value was greater than zero or smaller than zero. 
If the "det" is greater than zero i continued evaluating and calculating the two roots, named "r1" and "r2". Then I proceed to save the first root we found on "RaicesRacionales", "r1" and "r2" into an array named "ra" and then I printed these values into the console.
If "det" is smaller than zero then we do not calculate the rest of the cuadratic formula. Instead we just set our array value in the position 0 as "ra[0]", equal to 0.


NOTE: Since we couldn't use any library i had to create a new function for calcualting square roots. I used the Newton-Rpahson method and I called this function "RaizCu".
