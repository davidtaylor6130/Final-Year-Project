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
#//------------------------------------ Python API Functions -----------------------------------//
    def onSetup(self):
        #Calculating local file dectory to read and write files
        self.recordedData = {}
        temp = Path(__file__).parent.absolute()
        self.GoodAiPath = str( temp )
        
        #Creating the AI
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(16, input_shape=(4,)))
        self.model.add(tf.keras.layers.LeakyReLU(alpha = 0.3))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))
        
        #Reading in data must be smaller than 2139
        self.TrainingDataAmount = 100
        self.TestDataLength = 100

        #Training Data initlization
        self.trainingData = np.zeros((self.TrainingDataAmount , 4))
        self.trainingLables = np.zeros((self.TrainingDataAmount, 2))

        #Validation Data initlization
        self.ValidationData = np.zeros((self.TestDataLength , 4))
        self.ValidationLables = np.zeros((self.TestDataLength, 2))

        #open and read json data
        f = open (self.GoodAiPath + '/DataScrambled.json', "r")
        data = json.loads(f.read()) 
        f.close()

        #Reading in data then setting it to the provided data format
        for i in range(self.TrainingDataAmount): 
            self.trainingData[i][0] = float(data[str(i)]['North'])
            #self.trainingData[i][1] = float(data[str(i)]['NorthEast'])
            self.trainingData[i][1] = float(data[str(i)]['East'])
            #self.trainingData[i][3] = float(data[str(i)]['SouthEast'])
            self.trainingData[i][2] = float(data[str(i)]['South'])
            #self.trainingData[i][5] = float(data[str(i)]['SouthWest'])
            self.trainingData[i][3] = float(data[str(i)]['West'])
            #self.trainingData[i][7] = float(data[str(i)]['NorthWest'])
            self.trainingLables[i][0] = float(data[str(i)]['Acceleration'])
            self.trainingLables[i][1] = float(data[str(i)]['Steering'])
        
        #Review Data Format
        for i in range(self.TestDataLength):
            self.ValidationData[i][0] = float(data[str(i + self.TrainingDataAmount)]['North'])
            #self.ValidationData[i][1] = float(data[str(i + self.TrainingDataAmount)]['NorthEast'])
            self.ValidationData[i][1] = float(data[str(i + self.TrainingDataAmount)]['East'])
            #self.ValidationData[i][3] = float(data[str(i + self.TrainingDataAmount)]['SouthEast'])
            self.ValidationData[i][2] = float(data[str(i + self.TrainingDataAmount)]['South'])
            #self.ValidationData[i][5] = float(data[str(i + self.TrainingDataAmount)]['SouthWest'])
            self.ValidationData[i][3] = float(data[str(i + self.TrainingDataAmount)]['West'])
            #self.ValidationData[i][7] = float(data[str(i + self.TrainingDataAmount)]['NorthWest'])
            self.ValidationLables[i][0] = float(data[str(i + self.TrainingDataAmount)]['Acceleration'])
            self.ValidationLables[i][1] = float(data[str(i + self.TrainingDataAmount)]['Steering'])

        self.model.compile(optimizer='sgd', loss='mean_squared_error')

        self.model.fit(self.trainingData, self.trainingLables, epochs=120, batch_size=8 , validation_data=(self.ValidationData, self.ValidationLables))
        self.model.save_weights(self.GoodAiPath + '/CurrentWeightsCarAI2_1.h5')

    #Parse Json to useable Data
    def onJsonInput(self, jsonInput):
            result = {}
            result['LR'] = 0.5
            result['FB'] = 0.5

            Data = np.zeros((1, 4))

            Data[0][0] = float(jsonInput['North'])
            #Data[0][1] = float(jsonInput['NorthEast'])
            Data[0][1] = float(jsonInput['East'])
            #Data[0][3] = float(jsonInput['SouthEast'])
            Data[0][2] = float(jsonInput['South'])
            #Data[0][5] = float(jsonInput['SouthWest'])
            Data[0][3] = float(jsonInput['West'])
            #Data[0][7] = float(jsonInput['NorthWest'])

            temp = self.model.predict(Data)

            result['FB'] = float(temp[0][0])
            result['LR'] = float(temp[0][1])
            result['ResetCar'] = 0.0

            return result

    def onBeginTraining(self):
        pass


def getApi():
    return CarAi.getInstance()