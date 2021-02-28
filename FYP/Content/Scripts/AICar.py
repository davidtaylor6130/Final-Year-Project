import tensorflow as tf
import unreal_engine as ue
import json as json
import numpy as np
import random
import os

from pathlib import Path
from TFPluginAPI import TFPluginAPI
from enum import IntEnum

class OptimiserType(IntEnum):
    Adam = 1
    Sigmoid = 2
    
class SensorTypes(IntEnum):
     FrontThreeDiagonal = 1
     FrontThreePerpendicular = 2
     FrontFive = 3
     AllEight = 4

class ModelLayouts(IntEnum):
    ThirtytwoSixteenEight = 1
    EightSixteen = 2
    Eight = 3


class AiToTrainValues(IntEnum):
    ModelLayoutSelection = 1
    OptimiserSelection = 2
    SensorTypeSelection = 3
    DataLengthSelection = 4
    Epochs = 5

#ModelLayoutSelection -> OptimiserSelection -> SensorTypeSelection -> DataLengthSelection -> Epochs
#3 -> 2 -> 3 -> 2139 -> 30     
#1,155,060 combinations

# 3 -> 2 -> 3 -> 500 -> 30
#270,000 combonations 


class CarAi(TFPluginAPI):

    def DataScrambleFunction(self):
        f1 = open(self.GoodAiPath + '/DataRecorded1.json', "r")
        data1 = json.loads(f1.read()) 
        f1.close()

        f2 = open(self.GoodAiPath + '/DataRecorded2.json', "r")
        data2 = json.loads(f2.read()) 
        f2.close()

        data1Length = 1070
        data2Length = 9000
        countOfDataSet = 0

        JsonFile = {}

        for i in range(data1Length) :
            JsonFile[str(countOfDataSet)] = data1[str(i)]
            countOfDataSet = countOfDataSet + 1

            JsonFile[str(countOfDataSet)] = data2[str(i)]
            countOfDataSet = countOfDataSet + 1



        with open(self.GoodAiPath + '/DataScrambled.json', 'w') as outfile:
            json.dump(JsonFile, outfile, indent=4)
        return

        ue.log("Sucsessful Scramble")

#//----------------------------------------------------------------------------------------------------------------------------------//

    def ModelLayout(self):
        #Building The Neural Network's Structure
        #Following the rule of keep it simple

        #First sucsess was with this layout
        if (self.ModelStruct == ModelLayouts.EightSixteen):
            self.model = tf.keras.models.Sequential()
            self.model.add(tf.keras.layers.Dense(8, activation='relu', input_shape=(self.AiInputLength,)))
            self.model.add(tf.keras.layers.Dense(16, activation='relu'))
            self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))

        #Keeping Simple Ai as not a very complex problem
        elif (self.ModelStruct == ModelLayouts.Eight):
            self.model = tf.keras.models.Sequential()
            self.model.add(tf.keras.layers.Dense(8, activation='relu', input_shape=(self.AiInputLength,)))
            self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))

        #Using this idea from nvidea Ai paper where it worked with picture input
        elif (self.ModelStruct == ModelLayouts.ThirtytwoSixteenEight):
            self.model = tf.keras.models.Sequential()
            self.model.add(tf.keras.layers.Dense(32, activation='relu', input_shape=(self.AiInputLength,)))
            self.model.add(tf.keras.layers.Dense(16, activation='relu'))
            self.model.add(tf.keras.layers.Dense(8, activation='relu'))
            self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))


        self.model.summary()

#//----------------------------------------------------------------------------------------------------------------------------------//

    def InputDataProcessing(self):

        # If statement length
        if (self.SensorTypes == SensorTypes.AllEight):
            self.AiInputLength = 8

        elif (self.SensorTypes == SensorTypes.FrontFive):
            self.AiInputLength = 5

        elif (self.SensorTypes == SensorTypes.FrontThreeDiagonal or self.SensorTypes == SensorTypes.FrontThreePerpendicular):
            self.AiInputLength = 3


        #Training initlization
        self.trainingData = np.zeros((self.LearnDataLength , self.AiInputLength))
        self.trainingLables = np.zeros((self.LearnDataLength, 2))

        self.ValidationData = np.zeros((self.TestDataLength , self.AiInputLength))
        self.ValidationLables = np.zeros((self.TestDataLength, 2))

        #open and read json data
        f = open (self.GoodAiPath + '/DataScrambled.json', "r")
        data = json.loads(f.read()) 
        f.close()

        if (self.LearnDataLength + self.TestDataLength > self.TotalDataLength):
            raise NameError('Data Lengths are too long and will cause an error set learnData/testData to equal lower than MaxInputSize')
        else:
            #Formatting From Json Data Storage to Float In arrays
            #Diffrent Input configs require diffrent processing
            #Not the best way to do this but im keeping this simple for future ease

            if (self.SensorTypes == SensorTypes.AllEight):
                #Training Data Format
                for i in range(self.LearnDataLength): 
                    self.trainingData[i][0] = float(data[str(i)]['North'])
                    self.trainingData[i][1] = float(data[str(i)]['NorthEast'])
                    self.trainingData[i][2] = float(data[str(i)]['East'])
                    self.trainingData[i][3] = float(data[str(i)]['SouthEast'])
                    self.trainingData[i][4] = float(data[str(i)]['South'])
                    self.trainingData[i][5] = float(data[str(i)]['SouthWest'])
                    self.trainingData[i][6] = float(data[str(i)]['West'])
                    self.trainingData[i][7] = float(data[str(i)]['NorthWest'])
                    self.trainingLables[i][0] = float(data[str(i)]['Acceleration'])
                    self.trainingLables[i][1] = float(data[str(i)]['Steering'])
                #Review Data Format
                for i in range(self.TestDataLength):
                    self.ValidationData[i][0] = float(data[str(i + self.LearnDataLength)]['North'])
                    self.ValidationData[i][1] = float(data[str(i + self.LearnDataLength)]['NorthEast'])
                    self.ValidationData[i][2] = float(data[str(i + self.LearnDataLength)]['East'])
                    self.ValidationData[i][3] = float(data[str(i + self.LearnDataLength)]['SouthEast'])
                    self.ValidationData[i][4] = float(data[str(i + self.LearnDataLength)]['South'])
                    self.ValidationData[i][5] = float(data[str(i + self.LearnDataLength)]['SouthWest'])
                    self.ValidationData[i][6] = float(data[str(i + self.LearnDataLength)]['West'])
                    self.ValidationData[i][7] = float(data[str(i + self.LearnDataLength)]['NorthWest'])
                    self.ValidationLables[i][0] = float(data[str(i + self.LearnDataLength)]['Acceleration'])
                    self.ValidationLables[i][1] = float(data[str(i + self.LearnDataLength)]['Steering'])

            elif (self.SensorTypes == SensorTypes.FrontFive):
                #Learning Data Format
                for i in range(self.LearnDataLength): 
                    self.trainingData[i][0] = float(data[str(i)]['North'])
                    self.trainingData[i][1] = float(data[str(i)]['NorthEast'])
                    self.trainingData[i][2] = float(data[str(i)]['East'])
                    self.trainingData[i][3] = float(data[str(i)]['West'])
                    self.trainingData[i][4] = float(data[str(i)]['NorthWest'])
                    self.trainingLables[i][0] = float(data[str(i)]['Acceleration'])
                    self.trainingLables[i][1] = float(data[str(i)]['Steering'])
                #Validation data formating
                for i in range(self.TestDataLength):
                    self.ValidationData[i][0] = float(data[str(i + self.LearnDataLength)]['North'])
                    self.ValidationData[i][1] = float(data[str(i + self.LearnDataLength)]['NorthEast'])
                    self.ValidationData[i][2] = float(data[str(i + self.LearnDataLength)]['East'])
                    self.ValidationData[i][3] = float(data[str(i + self.LearnDataLength)]['West'])
                    self.ValidationData[i][4] = float(data[str(i + self.LearnDataLength)]['NorthWest'])
                    self.ValidationLables[i][0] = float(data[str(i + self.LearnDataLength)]['Acceleration'])
                    self.ValidationLables[i][1] = float(data[str(i + self.LearnDataLength)]['Steering'])

            elif (self.SensorTypes == SensorTypes.FrontThreePerpendicular):
                #Learning Data Formating
                for i in range(self.LearnDataLength): 
                    self.trainingData[i][0] = float(data[str(i)]['North'])
                    self.trainingData[i][1] = float(data[str(i)]['East'])
                    self.trainingData[i][2] = float(data[str(i)]['West'])
                    self.trainingLables[i][0] = float(data[str(i)]['Acceleration'])
                    self.trainingLables[i][1] = float(data[str(i)]['Steering'])
                #Validation Data Forming
                for i in range(self.TestDataLength):
                    self.ValidationData[i][0] = float(data[str(i + self.LearnDataLength)]['North'])
                    self.ValidationData[i][1] = float(data[str(i + self.LearnDataLength)]['East'])
                    self.ValidationData[i][2] = float(data[str(i + self.LearnDataLength)]['West'])
                    self.ValidationLables[i][0] = float(data[str(i + self.LearnDataLength)]['Acceleration'])
                    self.ValidationLables[i][1] = float(data[str(i + self.LearnDataLength)]['Steering'])

            elif (self.SensorTypes == SensorTypes.FrontThreeDiagonal):
                #Learning Data Formatting
                for i in range(self.LearnDataLength): 
                    self.trainingData[i][0] = float(data[str(i)]['North'])
                    self.trainingData[i][1] = float(data[str(i)]['NorthEast'])
                    self.trainingData[i][2] = float(data[str(i)]['NorthWest'])
                    self.trainingLables[i][0] = float(data[str(i)]['Acceleration'])
                    self.trainingLables[i][1] = float(data[str(i)]['Steering'])
                #Validation Data Formatting
                for i in range(self.TestDataLength) :
                    self.ValidationData[i][0] = float(data[str(i + self.LearnDataLength)]['North'])
                    self.ValidationData[i][1] = float(data[str(i + self.LearnDataLength)]['NorthEast'])
                    self.ValidationData[i][2] = float(data[str(i + self.LearnDataLength)]['NorthWest'])
                    self.ValidationLables[i][0] = float(data[str(i + self.LearnDataLength)]['Acceleration'])
                    self.ValidationLables[i][1] = float(data[str(i + self.LearnDataLength)]['Steering'])
        

        return

#//----------------------------------------------------------------------------------------------------------------------------------//

    def ModelTrainingFunction(self):
        # Swap Over The optimiser type
        # Not the best solution but super simple for easy future use
        if (self.ModelTraining == OptimiserType.Adam):
            self.model.compile(optimizer='Adam', loss='binary_crossentropy', metrics=['accuracy'])

        elif (self.ModelTraining == OptimiserType.Sigmoid):
            self.model.compile(optimizer='rmsprop', loss='binary_crossentropy', metrics=['accuracy'])

        #Swap from training new models to loading the last model
        #Again folowing the rule of keep it simple
        if (self.ToTrain) :
                self.model.fit(self.trainingData, self.trainingLables, epochs=self.epochs, batch_size=self.batches , validation_data=(self.ValidationData, self.ValidationLables))
                self.model.save_weights(self.GoodAiPath + '/CurrentWeights1.h5')
                
        else :
                self.model.load_weights(self.GoodAiPath + '/CurrentWeights1.h5')

    def UpdateModelNumbers(self):
        
        if (self.FinishedCalculatingBestResults == False):
            #Remove An Epoc Every time fail state kicks in
            self.AIStatsToCheck[AiToTrainValues.Epochs] -= 1
            self.AmmountChecked += 1

            #if all 30 epochs have been calculated then remove one from data selection and reset epochs
            if (self.AIStatsToCheck[AiToTrainValues.Epochs] == 0):
                self.AIStatsToCheck[AiToTrainValues.Epochs] = 30
                self.AIStatsToCheck[AiToTrainValues.DataLengthSelection] -= 1
            
                #if data length is compleated then reset and chnage sensor type
                if (self.AIStatsToCheck[AiToTrainValues.DataLengthSelection] == 0):
                    self.AIStatsToCheck[AiToTrainValues.DataLengthSelection] = 500
                    self.AIStatsToCheck[AiToTrainValues.SensorTypeSelection] -= 1
                
                    #if  sensor types have compleated
                    if (self.AIStatsToCheck[AiToTrainValues.SensorTypeSelection] == 0):
                        self.AIStatsToCheck[AiToTrainValues.SensorTypeSelection] = 3
                        self.AIStatsToCheck[AiToTrainValues.OptimiserSelection] -= 1

                        # if optimers compleated
                        if (self.AIStatsToCheck[AiToTrainValues.OptimiserSelection] == 0):
                            self.AIStatsToCheck[AiToTrainValues.OptimiserSelection] = 2
                            self.AIStatsToCheck[AiToTrainValues.ModelLayoutSelection] -= 1

                            # if All Model Layouts are compleated
                            if (self.AIStatsToCheck[AiToTrainValues.ModelLayoutSelection] == 0):
                                ue.log('COMPLEATED ALL AI VERSIONS')
                                self.FinishedCalculatingBestResults = True
                                return
                        return
                    return
                return
            return
        else:
            return 

    def ModelReset(self):

        #Ai Var about input Data
        self.LearnDataLength = round(self.AIStatsToCheck[(AiToTrainValues.DataLengthSelection)] * 0.9)
        self.TestDataLength = round(self.AIStatsToCheck[(AiToTrainValues.DataLengthSelection)] * 0.1)
        self.TotalDataLength = 500

        #Ai Var About Training Amounts
        #Epocs are amount that the full data set is trainined on
        self.epochs = self.AIStatsToCheck[(AiToTrainValues.Epochs)]
        #batches are how much gradient decent is tested for errors one is highest resoution
        self.batches = 1

        #Train new ai or load old ai weights
        self.ToTrain = True

        #Decisions for Model Layout and training and sensor layouts
        self.ModelStruct = self.AIStatsToCheck[(AiToTrainValues.ModelLayoutSelection)]
        self.ModelTraining = self.AIStatsToCheck[(AiToTrainValues.OptimiserSelection)]
        self.SensorTypes = self.AIStatsToCheck[(AiToTrainValues.SensorTypeSelection)]

        self.InputDataProcessing()
        self.ModelLayout()
        self.ModelTrainingFunction()

    def CompareModelPerformance(self, performance):
        
        if (float(performance) > self.BestCurrentScore):
            #Update Best Score To Only allow best ai to be saved
            self.BestCurrentScore = float(performance)

            #Add all values for the AI to be saved for human readable Json to see all info
            JsonFile = {}
            JsonFile['Performance Score'] = str(performance)
            JsonFile['Itteration Of AI Length'] = str(self.AmmountChecked)
            JsonFile['Epochs Trained For'] = str(self.AIStatsToCheck[AiToTrainValues.Epochs])
            JsonFile['Amount Of Training Data Used'] = str(self.AIStatsToCheck[AiToTrainValues.DataLengthSelection])
            JsonFile['Sensor Style Used'] = str(self.AIStatsToCheck[AiToTrainValues.SensorTypeSelection])
            JsonFile['Optimiser Used'] = str(self.AIStatsToCheck[AiToTrainValues.OptimiserSelection])
            JsonFile['Model Layout Used'] = str(self.AIStatsToCheck[AiToTrainValues.ModelLayoutSelection])

            #Create Folder Name
            FolderName = '/'
            FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.ModelLayoutSelection])) + '_'
            FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.OptimiserSelection])) + '_'
            FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.SensorTypeSelection])) + '_'
            FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.DataLengthSelection])) + '_'
            FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.Epochs]))
            
            #Make The File For Ai Files
            os.mkdir(self.GoodAiPath + '/Auto Ai Saves' + FolderName)

            #Saves Weights to the New File
            self.model.save_weights(self.GoodAiPath + '/Auto Ai Saves' + FolderName + '/AiWeights.h5')
            self.model.save(self.GoodAiPath + '/Auto Ai Saves' + FolderName + '/AiStuctureSave.h5')
            
            with open(self.GoodAiPath + '/Auto Ai Saves' + FolderName + '/AiInfo.Json', 'w') as outfile:
                    json.dump(JsonFile, outfile, indent=4)
        
        # Saving Model Weights to vault
        FolderName = '/'
        FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.ModelLayoutSelection])) + '_'
        FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.OptimiserSelection])) + '_'
        FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.SensorTypeSelection])) + '_'
        FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.DataLengthSelection])) + '_'
        FolderName += str(int(self.AIStatsToCheck[AiToTrainValues.Epochs]))
        
        os.mkdir(self.AiVault + FolderName)

        self.model.save_weights(self.AiVault + FolderName + '/CurrentWeights1.h5')
        self.model.save(self.AiVault + FolderName + '/AiStructireSave.h5')

        return

#//------------------------------------ Python API Functions -----------------------------------//
    def onSetup(self):
        #Hidden Data Collection Var        
        self.RunsCompleated = 0
        self.ToRecordAt = 5000
        self.Recording = False
        self.FinishedCalculatingBestResults = False
        self.BestCurrentScore = -1.0
        self.AmmountChecked = 0

        #Calculating local file dectory to read and write files
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.GoodAiPath = str( temp )

        self.AiVault = 'D:\AI Valut'

        self.AIStatsToCheck = [0,0,0,0,0,0]
        self.AIStatsToCheck[(AiToTrainValues.ModelLayoutSelection)] = 3
        self.AIStatsToCheck[(AiToTrainValues.OptimiserSelection)] = 2
        self.AIStatsToCheck[(AiToTrainValues.SensorTypeSelection)] = 3
        self.AIStatsToCheck[(AiToTrainValues.DataLengthSelection)] = 500
        self.AIStatsToCheck[(AiToTrainValues.Epochs)] = 30

        #Update Params and Re-Train AI
        self.ModelReset()

        
    #Parse Json to useable Data
    def onJsonInput(self, jsonInput):
        #save This Frames Data To

        # if Recording then store the data else dont waste memory space
        if (self.Recording):
            self.recordedData[self.RunsCompleated] = jsonInput
            #Increase Counter Count
            self.RunsCompleated = self.RunsCompleated + 1
            #Split into two elements to Data Recording and Ai Driving
            if (self.RunsCompleated > self.ToRecordAt) :
                ue.log("Saved Data")
                self.ToRecordAt += 1000;

                #Open file and add this frames data
                with open(self.GoodAiPath + '/DataRecorded2.json', 'w') as outfile:
                    json.dump(self.recordedData, outfile, indent=4)

        # if not recording format and output ai results
        else:

            if (jsonInput['Alive'] == 'false'):
                self.CompareModelPerformance(jsonInput['Score'])
                self.UpdateModelNumbers()
                self.ModelReset()

                result = {}
                result['FB'] = 0.5
                result['LR'] = 0.5
                result['ResetCar'] = 1.0

            else:
                result = {}
                result['LR'] = 0.5
                result['FB'] = 0.5

                Data = np.zeros((1, self.AiInputLength))

                if (self.SensorTypes == SensorTypes.AllEight):
                    Data[0][0] = float(jsonInput['North'])
                    Data[0][1] = float(jsonInput['NorthEast'])
                    Data[0][2] = float(jsonInput['East'])
                    Data[0][3] = float(jsonInput['SouthEast'])
                    Data[0][4] = float(jsonInput['South'])
                    Data[0][5] = float(jsonInput['SouthWest'])
                    Data[0][6] = float(jsonInput['West'])
                    Data[0][7] = float(jsonInput['NorthWest'])

                elif (self.SensorTypes == SensorTypes.FrontThreeDiagonal):
                    Data[0][0] = float(jsonInput['North'])
                    Data[0][1] = float(jsonInput['NorthEast'])
                    Data[0][2] = float(jsonInput['NorthWest'])

                elif (self.SensorTypes == SensorTypes.FrontThreePerpendicular):
                    Data[0][0] = float(jsonInput['North'])
                    Data[0][1] = float(jsonInput['East'])
                    Data[0][2] = float(jsonInput['West'])


                temp = self.model.predict(Data)

                result['FB'] = float(temp[0][0])
                result['LR'] = float(temp[0][1])
                result['ResetCar'] = 0.0

            return result

    def onBeginTraining(self):
        pass


def getApi():
    return CarAi.getInstance()