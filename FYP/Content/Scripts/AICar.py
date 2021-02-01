import tensorflow as tf
import unreal_engine as ue
import json as json

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

        # Recording To Json
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.pathToFile = str( temp )

        #Training 
        f = open ('data.json', "r") 
        # Reading from file 
        data = json.loads(f.read()) 
        # Iterating through the json 
        for i in 1070: 
            a
  
        # Closing file 
        f.close() 

        #Building The Neural Network's Structure
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(16, activation='relu', input_shape=(8,)))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        self.model.summary()

        #Loading the Last Weights Back in
        self.model.load_weights(self.pathToFile + '/CurrentWeights.h5')
        #self.model.save_weights(path)

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
            ue.log('MY CODE IS RUNNING')
            result = {}
            result['LR'] = 0.5
            result['FB'] = 1
            return result


    def onBeginTraining(self):
        pass

def getApi():
    return CarAi.getInstance()