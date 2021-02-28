import tensorflow as tf
import unreal_engine as ue
import json as json
import numpy as np

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
        self.ToRecordAt = 5000;
        self.DataLength = 3000;

        #Bad Input Data is using currentWeights.h5
        #Struct of ai is
        #self.model = tf.keras.models.Sequential()
        #self.model.add(tf.keras.layers.Dense(8, activation='relu', input_shape=(8,)))
        #self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        #
        #self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        #self.model.summary()

        # Recording To Json
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.pathToFile = str( temp )

        #Training initlization
        trainingData = np.zeros((6000 , 8))
        trainingLables = np.zeros((6000, 2))

        ValidationData = np.zeros((1000 , 8))
        ValidationLables = np.zeros((1000, 2))

        #open and read json data
        f = open (self.pathToFile + '/DataRecorded2.json', "r")
        data = json.loads(f.read()) 
        f.close()

        # Iterating through the json and formatting json to just feelers 
        for i in range(6000): 
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


        for i in range(1000) :
            ValidationData[i][0] = float(data[str(i+6000)]['North'])
            ValidationData[i][1] = float(data[str(i+6000)]['NorthEast'])
            ValidationData[i][2] = float(data[str(i+6000)]['East'])
            ValidationData[i][3] = float(data[str(i+6000)]['SouthEast'])
            ValidationData[i][4] = float(data[str(i+6000)]['South'])
            ValidationData[i][5] = float(data[str(i+6000)]['SouthWest'])
            ValidationData[i][6] = float(data[str(i+6000)]['West'])
            ValidationData[i][7] = float(data[str(i+6000)]['NorthWest'])

            ValidationLables[i][0] = float(data[str(i+6000)]['Acceleration'])
            ValidationLables[i][1] = float(data[str(i+6000)]['Steering'])

        ue.log("Is training Data Constructed")

        #Building The Neural Network's Structure
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(8, activation='relu', input_shape=(8,)))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        self.model.add(tf.keras.layers.Dropout(0.2))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        self.model.summary()

        self.model.compile(optimizer='rmsprop',
                  loss='binary_crossentropy',
                  metrics=['accuracy'])

        #True = train    false = Load
        if (True) :
                self.model.fit(trainingData, trainingLables, epochs=4096, batch_size=2048, validation_data=(ValidationData, ValidationLables))
                self.model.save_weights(self.pathToFile + '/CurrentWeights2.h5')
        else :
                self.model.load_weights(self.pathToFile + '/CurrentWeights2.h5')

        
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