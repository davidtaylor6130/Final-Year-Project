import tensorflow as tf
import unreal_engine as ue
from TFPluginAPI import TFPluginAPI

class CarAi(TFPluginAPI):

    #Simmilar To Constructor 
    def CarAiConstructor(self):
        # Declaring Required Variable
        self.RunsTillSave = 5
        self.RunsCompleated = 0
        self.ShutDownActive = False

        #Building The Neural Network's Structure
        self.model = tf.keras.models.Sequential()
        self.model.add(tf.keras.layers.Dense(16, activation='relu', input_shape=(8,)))
        self.model.add(tf.keras.layers.Dense(16, activation='relu'))
        self.model.add(tf.keras.layers.Dense(2, activation='sigmoid'))

        #Loading the Last Weights Back in
        self.LoadModel()

    #Contains Neural Network Input and Outputs
    def AiUpdate():
        outputs = {0,0}
        return outputs

    #Contains The Optimisation of the weights and calculation of loss score
    def AiDeath():
        self.RunsCompleated += 1

    #Saves Current Weights Everytime incase of pc crashes then saves after every 5 deaths as a backup
    def SaveModel():
        self.model.save_weights("CurrentWeights.h5")
        if (self.RunsTillSave == 0):
            fileName = "Trained " + self.RunsCompleated + ".h5"
            self.model.save_weight(fileName)
        else:
            self.RunsTillSave -= 1

    #loads the last save to the network
    def LoadModel():
        self.model.load_weights("CurrentWeights.h5")




#//------------------------------------ Python API Functions -----------------------------------//
    def onSetup(self):
        self.CarAiConstructor(self)

    #Parse Json to useable Data
    def onJsonInput(self, jsonInput):
        ue.log('MY CODE IS RUNNING')
        result = {}
        result['Left Right'] = 0
        result['Forward Back'] = 0
        return result

    def onBeginTraining(self):
        pass

def getApi():
    return CarAi.getInstance()