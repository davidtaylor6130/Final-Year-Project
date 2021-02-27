import tensorflow as tf
import unreal_engine as ue
import json as json
import numpy as np

import random;

from pathlib import Path
from TFPluginAPI import TFPluginAPI

class CarAi(TFPluginAPI):

    #Contains The Optimisation of the weights and calculation of loss score
    def AiDeath():
        self.RunsCompleated += 1

    #Saves Current Weights Everytime incase of pc crashes then saves after every 5 deaths as a backup
    def SaveModel():
        #Save weights each run
        self.model.save_weights(self.pathToFile + 'CurrentWeights.h5')
        
        #Backup Saves Weights Every Five Runs
        if (self.RunsTillSave == 0):
            self.model.save_weight(self.pathToFile + 'Trained ' + self.RunsCompleated + '.h5')
            self.RunsTillSave = 5
        else:
            self.RunsTillSave -= 1

    #loads the last save to the network
    def LoadModel():
        self.model.load_weights("CurrentWeights.h5")

#//------------------------------------ Python API Functions -----------------------------------//
    def onSetup(self):
        # Declaring Required Variable
        self.RunsTillSave = 5
        self.RunsCompleated = 0
        self.ShutDownActive = False
        self.ToRecordAt = 5000


        self.LearnDataLength = 250
        self.TestDataLength = 100

        self.epochs = 32
        self.batches = 1

        self.ToTrain = False

        # Recording To Json
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.pathToFile = str( temp )

        #Training initlization
        trainingData = np.zeros((self.LearnDataLength , 3))
        trainingLables = np.zeros((self.LearnDataLength, 2))

        ValidationData = np.zeros((self.TestDataLength , 3))
        ValidationLables = np.zeros((self.TestDataLength, 2))

        #open and read json data
        f = open (self.pathToFile + '/DataRecorded1.json', "r")
        data = json.loads(f.read()) 
        f.close()

        DataToUse = random.sample(range(900), self.LearnDataLength)
        # Iterating through the json and formatting json to just feelers 
        for i in range(self.LearnDataLength): 
            trainingData[i][0] = float(data[str(DataToUse[i])]['North'])
            #trainingData[i][1] = float(data[str(DataToUse[i])]['NorthEast'])
            trainingData[i][1] = float(data[str(DataToUse[i])]['East'])
            #trainingData[i][3] = float(data[str(i)]['SouthEast'])
            #trainingData[i][4] = float(data[str(i)]['South'])
            #trainingData[i][5] = float(data[str(i)]['SouthWest'])
            trainingData[i][2] = float(data[str(DataToUse[i])]['West'])
            #trainingData[i][2] = float(data[str(DataToUse[i])]['NorthWest'])

            trainingLables[i][0] = float(data[str(DataToUse[i])]['Acceleration'])
            trainingLables[i][1] = float(data[str(DataToUse[i])]['Steering'])


        DataToLearn = random.sample(range(100), self.TestDataLength)
        for i in range(self.TestDataLength) :
            ValidationData[i][0] = float(data[str(DataToLearn[i]+self.LearnDataLength)]['North'])
            #ValidationData[i][1] = float(data[str(DataToLearn[i]+self.LearnDataLength)]['NorthEast'])
            ValidationData[i][1] = float(data[str(DataToLearn[i]+self.LearnDataLength)]['East'])
            #ValidationData[i][3] = float(data[str(i+self.LearnDataLength)]['SouthEast'])
            #ValidationData[i][4] = float(data[str(i+self.LearnDataLength)]['South'])
            #ValidationData[i][5] = float(data[str(i+self.LearnDataLength)]['SouthWest'])
            ValidationData[i][2] = float(data[str(DataToLearn[i]+self.LearnDataLength)]['West'])
            #ValidationData[i][2] = float(data[str(DataToLearn[i]+self.LearnDataLength)]['NorthWest'])

            ValidationLables[i][0] = float(data[str(DataToLearn[i]+self.LearnDataLength)]['Acceleration'])
            ValidationLables[i][1] = float(data[str(DataToLearn[i]+self.LearnDataLength)]['Steering'])

        ue.log("Is training Data Constructed")

        #Building The Neural Network's Structure
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(8, activation='relu', input_shape=(3,)))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        #self.model.add(tf.keras.layers.Dense(8, activation='relu'))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        self.model.summary()

        self.model.compile(optimizer='Adam',
                  loss='binary_crossentropy',
                  metrics=['accuracy'])

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

            Data = np.zeros((1, 3))
            Data[0][0] = float(jsonInput['North'])
            Data[0][1] = float(jsonInput['NorthEast'])
            #Data[0][2] = float(jsonInput['East'])
            #Data[0][3] = float(jsonInput['SouthEast'])
            #Data[0][4] = float(jsonInput['South'])
            #Data[0][5] = float(jsonInput['SouthWest'])
            #Data[0][6] = float(jsonInput['West'])
            Data[0][2] = float(jsonInput['NorthWest'])

            temp = self.model.predict(Data)

            result['FB'] = float(temp[0][0])
            result['LR'] = float(temp[0][1])

            return result


    def onBeginTraining(self):
        pass

    def ScrambleDataSet():
        pass

def getApi():
    return CarAi.getInstance()