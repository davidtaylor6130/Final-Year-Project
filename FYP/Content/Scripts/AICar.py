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

        ue.log("Var Setup")

        # Recording To Json
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.pathToFile = str( temp )

        ue.log("Got Path")

        #Training initlization
        trainingData = np.zeros((1070 , 8))
        trainingLables = np.zeros((1070, 2))

        ue.log("Is Initilized")

        #open and read json data
        f = open (self.pathToFile + '/DataRecorded1.json', "r")
        data = json.loads(f.read()) 
        f.close()

        ue.log("File Loaded")

        # Iterating through the json and formatting json to just feelers 
        for i in range(1070): 
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
            
        ue.log("Is trainingData Constructed")

        #Building The Neural Network's Structure
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(8, activation='relu', input_shape=(8,)))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        self.model.summary()

        ue.log("Is Constructed")

        self.model.compile(optimizer='rmsprop',
                  loss='binary_crossentropy',
                  metrics=['accuracy'])

        ue.log("Is Complie")

        #self.model.fit(trainingData, trainingLables, epochs=1024, batch_size=128, validation_data=(trainingData, trainingLables))

        ue.log("Is Fit")

        #Loading the Last Weights Back in
        self.model.load_weights(self.pathToFile + '/CurrentWeights.h5')
        #self.model.save_weights(self.pathToFile + '/CurrentWeights.h5')

    #Parse Json to useable Data
    def onJsonInput(self, jsonInput):
        #save This Frames Data To
        self.recordedData[self.RunsCompleated] = jsonInput
        
        #Increase Counter Count
        self.RunsCompleated = self.RunsCompleated + 1
            

        #Split into two elements to Data Recording and Ai Driving
        if (jsonInput['RecordingData'] == 'True') :
            #Open file and add this frames data
            with open(self.pathToFile + '/DataRecorded1.json', 'w') as outfile:
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