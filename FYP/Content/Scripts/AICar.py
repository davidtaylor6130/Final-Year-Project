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
            trainingData[i][0] = data[str(i)]['North']
            trainingData[i][1] = data[str(i)]['NorthEast']
            trainingData[i][2] = data[str(i)]['East']
            trainingData[i][3] = data[str(i)]['SouthEast']
            trainingData[i][4] = data[str(i)]['South']
            trainingData[i][5] = data[str(i)]['SouthWest']
            trainingData[i][6] = data[str(i)]['West']
            trainingData[i][7] = data[str(i)]['NorthWest']

            trainingLables[i][0] = data[str(i)]['Acceleration']
            trainingLables[i][1] = data[str(i)]['Steering']
            
        ue.log("Is trainingData Constructed")

        #Building The Neural Network's Structure
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(16, activation='relu', input_shape=(8,)))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        self.model.summary()

        ue.log("Is Constructed")

        self.model.compile(optimizer='rmsprop',
                  loss='binary_crossentropy',
                  metrics=['accuracy'])

        ue.log("Is Complie")

        self.model.fit(trainingData, trainingLables, epochs=20, batch_size=512, validation_data=(trainingData, trainingLables))

        ue.log("Is Fit")

        #Loading the Last Weights Back in
        #self.model.load_weights(self.pathToFile + '/CurrentWeights.h5')
        self.model.save_weights(self.pathToFile + '/CurrentWeights.h5')

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
            #ue.log('MY CODE IS RUNNING')
            result = {}
            result['LR'] = 0.5
            result['FB'] = 1

            inData = [] * 8
            inData[0] = float(jsonInput['North'])
            inData[1] = float(jsonInput['NorthEast'])
            inData[2] = float(jsonInput['East'])
            inData[3] = float(jsonInput['SouthEast'])
            inData[4] = float(jsonInput['South'])
            inData[5] = float(jsonInput['SouthWest'])
            inData[6] = float(jsonInput['West'])
            inData[7] = float(jsonInput['NorthWest'])

            #temp = self.model.predict(inData);
            temp = self.model.predict({0,0,0,0,0,0,0,0});

            result['FB'] = temp[0]
            result['LR'] = temp[1]

            ue.log("Is Predicted")

            return result


    def onBeginTraining(self):
        pass

def getApi():
    return CarAi.getInstance()