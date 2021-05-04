import tensorflow as tf
import unreal_engine as ue
import json as json
import numpy as np
import random
import os

from pathlib import Path
from TFPluginAPI import TFPluginAPI
from enum import IntEnum

class CarAi(TFPluginAPI):

    def SaveWeights(self):
        self.model.set_weights(self.CurrentModelWeights)
        self.model.save_weights(self.GoodAiPath + '/GAWeightFolder/GAWeights' + str(self.GenarationCount) +'.h5')
        return

    def ReviewPerformance(self, fitness):
        #if best current AI then save

        floatFitness = float(fitness)

        if floatFitness > self.bestFitness:
            self.bestFitness = floatFitness
            self.bestWeightings = self.CurrentModelWeights
        elif floatFitness > self.secondBestFitness:
            self.secondBestFitness = floatFitness
            self.secondBestWeightings = self.CurrentModelWeights
        
        ue.log('---------------------------------')
        ue.log('---Generation ' + str(self.GenarationCount) + '---')
        ue.log(str(self.CurrentChildBeingTested) + ' / ' + str(self.ChildPerGenration))
        ue.log(str(floatFitness))
        ue.log('---------------------------------')

        #Test Next Child
        self.CurrentChildBeingTested += 1

        #If Finished Testing then Generate New Genaration
        if self.CurrentChildBeingTested == self.ChildPerGenration + 1:
            self.CurrentChildBeingTested = 0
            self.GenerateNextGenoration()
            self.GenarationCount += 1
            self.SaveWeights()
            ue.log('Generation Compleated')

        self.MutateSelf()

        self.model.set_weights(self.CurrentModelWeights)

        return

    def GenerateNextGenoration(self):
        ChildWeightings = self.CurrentModelWeights

        #Cross Random Weightings
        for i in range(len(self.bestWeightings)):
            if random.randint(0,1) == 0:
                self.ChildWeightings[i] = self.bestWeightings[i]
            else:
                self.ChildWeightings[i] = self.secondBestWeightings[i]
        
        return 
    
    def MutateSelf(self):
        #For Every Weight
        for x in range(len(self.CurrentModelWeights)):
            #Random Mutation
            if random.randint(0,1) == 0:
                self.CurrentModelWeights[x] += 0.1
            else:
                self.CurrentModelWeights[x] -= 0.1
            #Weighting Caps
            #if (self.CurrentModelWeights[x]) > 2.0:
            #    self.CurrentModelWeights[x] = 2.0
            #elif (self.CurrentModelWeights[x]) < -2.0:
            #    self.CurrentModelWeights[x] = -2.0

        return

    def RandomiseWeightings(self):
        for x in self.CurrentModelWeights:
            #Get Random number between -2 to 2 in 0.01 increments 
            x = (random.randint(0,3)) - 1

        self.model.set_weights(self.CurrentModelWeights)

        return



#//------------------------------------ Python API Functions -----------------------------------//
    def onSetup(self):
        #Calculating local file dectory to read and write files
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.GoodAiPath = str( temp )
        
        #Creating the AI
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(16, input_shape=(8,)))
        self.model.add(tf.keras.layers.LeakyReLU(alpha = 0.3))
        self.model.add(tf.keras.layers.Dense(8, input_shape=(4,)))
        self.model.add(tf.keras.layers.LeakyReLU(alpha = 0.3))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        
        #Getting Corrent style of numpy array
        self.CurrentModelWeights = self.model.get_weights()
        self.ChildWeightings = self.CurrentModelWeights
        #Get Total Amount of weights
        self.AmmountOfWeights = len(self.CurrentModelWeights)

        self.ChildPerGenration = 10
        self.bestFitness = -1
        self.secondBestFitness = -1
        self.CurrentChildBeingTested = 0
        self.GenarationCount = 0

        self.RandomiseWeightings()


    #Parse Json to useable Data
    def onJsonInput(self, jsonInput):
            result = {}
            result['LR'] = 0.5
            result['FB'] = 0.5

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
            result['ResetCar'] = 0.0

            if jsonInput['Alive'] == 'false':
                result['ResetCar'] = 1.0

                stringScore = jsonInput['Score']

                self.ReviewPerformance(str(stringScore))

            return result

    def onBeginTraining(self):
        pass


def getApi():
    return CarAi.getInstance()