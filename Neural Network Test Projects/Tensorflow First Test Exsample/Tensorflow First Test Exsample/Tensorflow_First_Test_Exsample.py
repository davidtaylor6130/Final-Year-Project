# TO GET ACSESS TO KERAS YOU NEED TO IMPORT TENSORFLOW AS TF AND THEN DO TF.KERAS
# Tensorflow is installed to work with python version 3.6 AND NO FUTRUE DAVID IM NOT CHANGING IT
import tensorflow as tf

#Loading the data
mnist = tf.keras.datasets.mnist
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0

#building the model
model = tf.keras.models.Sequential([
    tf.keras.layers.Flatten(input_shape=(28,28)),
    tf.keras.layers.Dense(128, activation='relu'),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.Dense(10)
    ])

#SOME THING??
predictions = model(x_train[:1]).numpy()
predictions

#Turning Predictions into probalilites for each class
tf.nn.softmax(predictions).numpy()

#Creating loss function
loss_fn = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True)

#Setting function
loss_fn(y_train[:1], predictions).numpy()

#Conpiling the model from input data above
model.compile(optimizer='adam',
              loss=loss_fn,
              metrics=['accuracy'])

#Training the model from the data
model.fit(x_train, y_train, epochs=5)

#Evaluate the model that has been trained
model.evaluate(x_test, y_test, verbose=2)