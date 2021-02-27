import tensorflow as tf
import unreal_engine as ue
import json as json
import numpy as np
import random;

from pathlib import Path
from TFPluginAPI import TFPluginAPI

class CarAi(TFPluginAPI):

    def qwerty(self):
        f1 = open(self.pathToFile + '/DataRecorded1.json', "r")
        data1 = json.loads(f1.read()) 
        f1.close()

        f2 = open(self.pathToFile + '/DataRecorded2.json', "r")
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



        with open(self.pathToFile + '/DataScrambled.json', 'w') as outfile:
            json.dump(JsonFile, outfile, indent=4)
        return

        ue.log("Sucsessful Scramble")

#//------------------------------------ Python API Functions -----------------------------------//
    def onSetup(self):
        # Declaring Required Variable
        self.RunsTillSave = 5
        self.RunsCompleated = 0
        self.ShutDownActive = False
        self.ToRecordAt = 5000

        self.LearnDataLength = 100
        self.TestDataLength = 10

        self.epochs = 1
        self.batches = 1

        self.ToTrain = True

        # Recording To Json
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.pathToFile = str( temp )

        self.qwerty()

        #Training initlization
        trainingData = np.zeros((self.LearnDataLength , 8))
        trainingLables = np.zeros((self.LearnDataLength, 2))

        ValidationData = np.zeros((self.TestDataLength , 8))
        ValidationLables = np.zeros((self.TestDataLength, 2))

        #open and read json data
        f = open (self.pathToFile + '/DataScrambled.json', "r")
        data = json.loads(f.read()) 
        f.close()

        # Iterating through the json and formatting json to just feelers 
        for i in range(self.LearnDataLength): 
            trainingData[i][0] = float(data[str(i)]['North'])
            trainingData[i][1] = float(data[str(i)]['NorthEast'])
            trainingData[i][2] = float(data[str(i)]['East'])
            trainingData[i][3] = float(data[str(i)]['SouthEast'])
            trainingData[i][4] = float(data[str(i)]['South'])
            trainingData[i][5] = float(data[str(i)]['SouthWest'])
            trainingData[i][6] = float(data[str(i)]['West'])
            trainingData[i][7] = float(data[str(i)]['NorthWest'])
            trainingLables[i][0] = float(data[str(i)]['Acceleration'])
            trainingLables[i][1] = float(data[str(i)]['Steering'])

        for i in range(self.TestDataLength) :
            ValidationData[i][0] = float(data[str(i + self.LearnDataLength)]['North'])
            ValidationData[i][1] = float(data[str(i + self.LearnDataLength)]['NorthEast'])
            ValidationData[i][2] = float(data[str(i + self.LearnDataLength)]['East'])
            ValidationData[i][3] = float(data[str(i + self.LearnDataLength)]['SouthEast'])
            ValidationData[i][4] = float(data[str(i + self.LearnDataLength)]['South'])
            ValidationData[i][5] = float(data[str(i + self.LearnDataLength)]['SouthWest'])
            ValidationData[i][6] = float(data[str(i + self.LearnDataLength)]['West'])
            ValidationData[i][7] = float(data[str(i + self.LearnDataLength)]['NorthWest'])
            ValidationLables[i][0] = float(data[str(i + self.LearnDataLength)]['Acceleration'])
            ValidationLables[i][1] = float(data[str(i + self.LearnDataLength)]['Steering'])

        #Building The Neural Network's Structure
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(8, activation='relu', input_shape=(8,)))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        self.model.summary()

        self.model.compile(optimizer='Adam', loss='binary_crossentropy', metrics=['accuracy'])

        #True = train    false = Load
        if (self.ToTrain) :
                self.model.fit(trainingData, trainingLables, epochs=self.epochs, batch_size=self.batches , validation_data=(ValidationData, ValidationLables))
                self.model.save_weights(self.pathToFile + '/CurrentWeights1.h5')
        else :
                self.model.load_weights(self.pathToFile + '/CurrentWeights1.h5')

        
    #Parse Json to useable Data
    def onJsonInput(self, jsonInput):
        #save This Frames Data To
        self.recordedData[self.RunsCompleated] = jsonInput
        
        #Increase Counter Count
        self.RunsCompleated = self.RunsCompleated + 1
            

        #Split into two elements to Data Recording and Ai Driving
        
        #if (self.RunsCompleated > self.ToRecordAt) :
        if (False):
            ue.log("Saved Data")
            self.ToRecordAt += 1000;

            #Open file and add this frames data
            with open(self.pathToFile + '/DataRecorded2.json', 'w') as outfile:
                json.dump(self.recordedData, outfile, indent=4)
            return



        else:
            result = {}
            result['LR'] = 0.5
            result['FB'] = 1

            Data = np.zeros((1, 8))
            Data[0][0] = float(jsonInput['North'])
            Data[0][1] = float(jsonInput['NorthEast'])
            Data[0][2] = float(jsonInput['East'])
            Data[0][3] = float(jsonInput['SouthEast'])
            Data[0][4] = float(jsonInput['South'])
            Data[0][5] = float(jsonInput['SouthWest'])
            Data[0][6] = float(jsonInput['West'])
            Data[0][7] = float(jsonInput['NorthWest'])

            temp = self.model.predict(Data)

            result['FB'] = float(temp[0][0])
            result['LR'] = float(temp[0][1])

            return result


    def onBeginTraining(self):
        pass


def getApi():
    return CarAi.getInstance()