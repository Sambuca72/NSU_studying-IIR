import numpy as np
import matplotlib.pyplot as plt 
import torchvision

# Initializing the transform for the dataset
transform = torchvision.transforms.Compose([
                    torchvision.transforms.ToTensor(),
                    torchvision.transforms.Normalize((0.5), (0.5))
                                            ])

# Downloading the MNIST dataset
train_dataset = torchvision.datasets.MNIST(
    root="MNIST/train", train=True,
    transform=torchvision.transforms.ToTensor(),
    download=False)

test_dataset = torchvision.datasets.MNIST(
    root="MNIST/test", train=False,
    transform=torchvision.transforms.ToTensor(),
    download=False)

test1 = train_dataset[0]
# (Img, label)

def encode_label(j):
    # 5 -> [[0], [0], [0], [0], [0], [1], [0], [0], [0], [0]]
    e = np.zeros((10,1))
    e[j] = 1.0
    return e

def shape_data(data):
    features = [np.reshape(x[0][0].numpy(), (784,1)) for x in data]
    labels = [encode_label(y[1]) for y in data]
    return zip(features, labels)

train = shape_data(train_dataset)
test = shape_data(test_dataset)

train = list(train)
test = list(test)

def average_digit(data, digit):
    filtered_data = [x[0] for x in data if np.argmax(x[1]) == digit]
    filtered_array = np.asarray(filtered_data)
    return np.average(filtered_array, axis=0)

class MyClassifier:
    def __init__(self, W, b = -45):
        self.W = W
        self.b = b
    
    def predict(self, x):
        return 1.0 if ((np.dot(self.W, x)[0][0] + self.b)/ np.linalg.norm(self.W)) >= 0 else 0
    

W0 = np.transpose(average_digit(train, 0))
W1 = np.transpose(average_digit(train, 1))
W2 = np.transpose(average_digit(train, 2))
W3 = np.transpose(average_digit(train, 3))
W4 = np.transpose(average_digit(train, 4))
W5 = np.transpose(average_digit(train, 5))
W6 = np.transpose(average_digit(train, 6))
W7 = np.transpose(average_digit(train, 7))
W8 = np.transpose(average_digit(train, 8))
W9 = np.transpose(average_digit(train, 9))

weights = {
    0 : W0,
    1 : W1,
    2 : W2,
    3 : W3,
    4 : W4, 
    5 : W5,
    6 : W6,
    7 : W7,
    8 : W8,
    9 : W9
}

accuracy = []

train = list(train)
test = list(test)

# print(len(train))

for i in range(10):
    model = MyClassifier(weights[i])
    TP, TN, FP, FN = 0, 0, 0, 0
    for j in range(len(test)):
        digit = test[j][0]
        label = np.argmax(test[j][1])
        
        prediction = model.predict(digit)
        if label == i and prediction == 1:
            TP += 1
        elif label == i and prediction == 0:
            FP += 1
        elif label != i and prediction == 0:
            TN += 1
        elif label != i and prediction == 1:
            FP += 1
        
    accuracy.append((TP+TN)/(TP + TN + FP + FN))


class DigitsClassifier:
    def __init__(self, weights, accuracy, b = -45):
        self.weights = weights
        self.accuracy = accuracy
        self.b = b
        self.classifiers = [MyClassifier(w) for w in weights]

    def predict(self, x):
        predictions = []
        for i,c in enumerate(self.classifiers):
            predictions.append(accuracy[i] * c.predict(x))
        answer = np.zeros((10,1))
        answer[np.argmax(predictions)] = 1
        return answer
        

classifier = DigitsClassifier(weights, accuracy)

TP, TN, FP, FN = 0, 0, 0, 0
precision, recall = 0, 0
for i in range(len(test)):
    digit = test[i][0]
    label = np.argmax(test[i][1])

    answer = np.argmax(classifier.predict(digit))
    if answer == label:
        TP += 1
    elif answer != label:
        FP += 1
precision = TP/(TP+FP)
recall = TP/(TP + FP)
