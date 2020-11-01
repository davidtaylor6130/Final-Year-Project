from math import *
import os


def HelloWorld():
    print("Hello" + "world")

def VarAndDataTypesTutorials():
    varString = "String"
    varInt = 1
    varFloat = 1.5
    varComplex = 1j
    varList = [1,2,3]
    varTuple = (1,2,3)
    varRange = range(6)
    varDict = {"name" : "David", "age" : "20"}
    varSet = {"Apple","Bannana","Cherry"}
    varFrozenSet = ({"Apple","Bannana","Cherry"})
    varBool = True
    xBytes = b"Hello"
    xByteArray = bytearray(5)
   


def WorkingWithStringsTutorial():
    varString = "VarString"
    print("Var Strings are simmilar to c++ but use a \\ to allows odd char through like \" \\ ")
    print("you can combine strings with plus")
    temp1 = input("String One: ")
    temp2 = input("String Two: ")
    print(temp1 + temp2)
    


def WorkingWithNumbersTutorial():
    temp = float(input("Enter Number One: "))
    temp2 = float(input("Enter Number Two: "))

    print("Add " + str(temp + temp2))
    print("Minus " + str((temp) - (temp2)))
    print("Times " + str((temp) * (temp2)))
    print("Divide " + str((temp) / (temp2)))

    print("To Cast To data type = float(var)")



def MathsImport() :
    tempInt = int(input("Give an Int (Whole Number): "))
    tempFloat = float(input("Give an Float (decimalPoint Number): "))

    print("math.ceil rounds up: Int " + str(ceil(tempInt)) + " Float " + str(ceil(tempFloat)))



def GettingInputFromUsers():
    print("Need to import Maths functions with \"from Math import *\"")
    num = 5
    print(sqrt(num))



def IfAndSwitchStatements():
    print("If Statements are Almost the same") 
    print(" if (statement) :")
    print("      Code")

    print("Switch select statements are alot diffrent look at this bit of the code by ctrl+F SWITCHSELECTSTATEMENTS")
    switcher = {
        0 : False,
        1 : True
        }
   
    print(switcher.get(0, "INPUT NOT FOUND")) 
    print(switcher.get(1, "INPUT NOT FOUND"))
    print(switcher.get(2, "INPUT NOT FOUND")) 



def NotImplimentedYet():
    print("NotWorking")



def Main():
    temp = 1
    switcher = {
            0 : 0,
            1 : HelloWorld,
            2 : VarAndDataTypesTutorials,
            3 : WorkingWithStringsTutorial,
            4 : WorkingWithNumbersTutorial,
            5 : MathsImport,
            6 : GettingInputFromUsers,
            7 : NotImplimentedYet,
            8 : NotImplimentedYet,
            9 : NotImplimentedYet,
            10 : NotImplimentedYet
            }
    
    while(temp > 0) :
        input();
        print("Hello World - 1")
        print("Var Types - 2")
        print("Working With Strings - 3")
        print("Working With Numbers - 4")
        print("MAths Import - 5")
        print("Getting Input - 6")
        print("IfAndSwitchStatements - 7")
        print(" - 8")
        print(" - 9")
        print(" - 10")
        temp = int(input("Select Information: "))

        if (temp > 0) :
            func = switcher.get(temp, lambda: "Invalid Input");
            func()


Main()