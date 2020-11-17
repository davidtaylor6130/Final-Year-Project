# TO GET ACSESS TO tf.keras YOU NEED TO IMPORT TENSORFLOW AS TF AND THEN DO TF.tf.keras
# Tensorflow is installed to work with python version 3.6 AND NO FUTRUE DAVID IM NOT CHANGING IT
import tensorflow as tf
#Setting numpy for maths as np
import numpy as np
#import for the graphs
import matplotlib.pyplot as plt

# function to vectorise input data
def vectorize_sequences(sequences, dimension=10000):
    results = np.zeros((len(sequences), dimension))
    for i, sequence in enumerate(sequences):
        results[i, sequence] = 1.
    return results

# Saving the dataset to the needed arrays
(train_data, train_labels), (test_data, test_labels) = tf.keras.datasets.imdb.load_data(num_words=10000)
    
#vectorising the input data into 1's & 0's to allow neural networks to process it 
x_train = vectorize_sequences(train_data)
x_test = vectorize_sequences(test_data)

#vectorising the label data as all data needs to be a tensor when doing neural networks
y_train = np.asarray(train_labels).astype('float32')
y_test = np.asarray(test_labels).astype('float32')


#construction of the NN (NN = Neural Networks)
model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Dense(16, activation='relu', input_shape=(10000,)))
model.add(tf.keras.layers.Dense(16, activation='relu'))
model.add(tf.keras.layers.Dense(1, activation='sigmoid'))

    #Diffrent says to compile model 3 diffrent ways are possible thats why there is an if statement
UseCompileType = 0
if (UseCompileType == 0):
    #compiling the model with built in optimizors, lossfunctions and metrics
    model.compile(optimizer='rmsprop',
                  loss='binary_crossentropy',
                  metrics=['accuracy'])

elif (UseCompileType == 1):
    #compiling can use your own and built in optimizors, lossfunctions and metrics PG:73 deeplearning with python book 
    model.compile(optimizer = tf.keras.optimizers.RMSprop(lr=0.001),
                  loss = 'Binary_crossentropy',
                  metrics = ['accuracy'])

elif (UseCompileType == 2):
    #compiling can be done through all custom optomizors, loss functions and metrics
    model.compile(optimizer = tf.keras.optimizers.RMSprop(lr=0.001),
                  loss = tf.keras.losses.binary_crossentropy,
                  metrics = [tf.keras.metrics.binary_accuracy])
    
    
#Creation of Validation Data
x_val = x_train[:10000]
partial_x_train = x_train[10000:]
y_val = y_train[:10000]
partial_y_train = y_train[10000:]

    #training the model with training data and to epochs and batch_size specs
    #this passes back data on history of training 
history = model.fit(partial_x_train, 
                    partial_y_train,
                    epochs=20,
                    batch_size=512,
                    validation_data=(x_val, y_val))


#
## <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<END OF AI JUST PLOTTING CODE FROM NOW ON>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
# list all data in history
print(history.history.keys())

# summarize history for accuracy
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.show()

# summarize history for loss
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('model loss')
plt.ylabel('loss')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.show()