# Get started with TensorFlow and Deep Learning Part-1

This same blog is availaible on Medium [here](https://medium.com/@rishit.dagli/get-started-with-tensorflow-and-deep-learning-part-1-72c7d67f99fc)

![](https://miro.medium.com/max/1860/1*zRbqakEO9WX43jKCGWCJHg.jpeg)
<p align="center">Source: cognitiveclass.ai</p>

This is the first part of a series where I will be posting many blog posts about coding Machine Learning and Deep Learning algorithms. I believe in hands-on coding so we will have many exercises and demos which you can try yourself too. I would recommend you to play around with these exercises and change the hyper-parameters and experiment with the code. That is the best way to learn and code efficiently. If you don’t know what hyper-parameters are don’t worry. We will walk through Tensor Flow’s core capabilities and then also explore high level API’s in TensorFlow and so on.

## Is this series for me?

If you are a person who is looking to get started with Tensor Flow, Machine Learning and Deep Learning but don’t have any knowledge about Machine Learning you can do this.
If you already know about Machine Learning and Deep Learning and don’t know about Tensor Flow you can follow these. As you might be using some other frameworks or libraries like Caffe, Theano, CNTK, Apple ML or PyTorch and might also be knowing about the maths behind it you can skip the sections marked OPTIONAL.
If you know about the basics of Tensor Flow then you can skip some of the blog posts.

## Is any software setup needed?

No!!

Not at all, you don’t need to install any software at all to complete the exercises and follow the code at all. We will be using [Google Colaboratory](http://colab.research.google.com/). Colaboratory is a research tool for machine learning education and research. It’s a Jupyter notebook environment that requires no setup to use. Colaboratory works with most major browsers and is most thoroughly tested with the latest versions of [Chrome](https://www.google.com/chrome/browser/desktop/index.html), [Firefox](https://www.mozilla.org/en-US/firefox/), and [Safari](https://www.apple.com/safari/). And what more, it is completely free to use. All Colaboratory notebooks are stored in Google Drive. Colaboratory notebooks can be shared just as you would with Google Docs or Sheets. Simply click the Share button at the top right of any Colaboratory notebook, or follow these Google Drive [file sharing instructions](https://support.google.com/drive/answer/2494822?co=GENIE.Platform%3DDesktop&hl=en). Before, you ask me Colaboratory is really reliable and fast too.

However, you can also use a local development environment preferably Jupyter Notebooks but we will not be covering how to set up the local environment in these blogs.

## Which Version of Tensor Flow?

The answer to this question is that in this blog we will cover both. If you are using Colab notebooks add this code.

```python
try:
  # %tensorflow_version only exists in Colab.
  %tensorflow_version 2.x
except Exception:
  pass
  
import tensorflow as tf
```

## Introduction

Coding has been the bread and butter for developers since the dawn of computing. We’re used to creating applications by breaking down requirements into composable problems that can then be coded against. So for example, if we have to write an application that figures out a stock analytic, maybe the price divided by the ratio, we can usually write code to get the values from a data source, do the calculation and then return the result. Or if we’re writing a game we can usually figure out the rules. For example, if the ball hits the brick then the brick should vanish and the ball should rebound. But if the ball falls off the bottom of the screen then maybe the player loses their life.

We can represent that with this diagram. Rules and data go in answers come out. Rules are expressed in a programming language and data can come from a variety of sources from local variables up to databases. Machine learning rearranges this diagram where we put answers in data in and then we get rules out. So instead of us as developers figuring out the rules when should the brick be removed, when should the player’s life end, or what’s the desired analytic for any other concept, what we will do is we can get a bunch of examples for what we want to see and then have the computer figure out the rules.

![](https://miro.medium.com/max/514/1*-yqcaIQ-6-BkmzKOSLr-MQ.jpeg)
<p align="center">Traditional Programming vs Machine Learning</p>

So consider this example, activity recognition. If I’m building a device that detects if somebody is say walking and I have data about their speed, I might write code like this and if they’re running well that’s a faster speed so I could adapt my code to this and if they’re biking, well that’s not too bad either. I can adapt my code like this. But then I have to do golf recognition too, now my concept becomes broken. But not only that, doing it by speed alone of course is quite naive. We walk and run at different speeds uphill and downhill and other people walk and run at different speeds to us.

![](https://miro.medium.com/max/609/1*rEc6QCVlvMuH2lSuxvJRUQ.jpeg)
<p align="center">A traditional programming logic</p>

The new paradigm is that I get lots and lots of examples and then I have labels on those examples and I use the data to say this is what walking looks like, this is what running looks like, this is what biking looks like and yes, even this is what golfing looks like. So, then it becomes answers and data in with rules being inferred by the machine. A machine learning algorithm then figures out the specific patterns in each set of data that determines the distinctiveness of each. That’s what’s so powerful and exciting about this programming paradigm. It’s more than just a new way of doing the same old thing. It opens up new possibilities that were infeasible to do before.

So, now I am going to show you the basics of creating a neural network for doing this type of pattern recognition. A neural network is just a slightly more advanced implementation of machine learning and we call that deep learning. But fortunately it's actually very easy to code. So, we're just going to jump straight into deep learning. We'll start with a simple one and then we'll move on to one that does computer vision in about 10 lines of code.
Hello Neural Networks

To show how that works, let’s take a look at a set of numbers and see if you can determine the pattern between them. Okay, here are the numbers.

x = -1, 0, 1, 2, 3, 4

y = -3, -1, 1, 3, 5, 7

You easily figure this out `y = 2x — 1`

You probably tried that out with a couple of other values and see that it fits. Congratulations, you’ve just done the basics of machine learning in your head.

Okay, here’s our first line of code. This is written using Python and TensorFlow and an API in TensorFlow called keras. Keras makes it really easy to define neural networks. A neural network is basically a set of functions which can learn patterns.

```python
model = keras.Sequential([keras.layers.Dense(units = 1, input_shape = [1])])
```

The simplest possible neural network is one that has only one neuron in it, and that’s what this line of code does. In keras we use the word Dense to define a layer of connected neurons. There is only one Dense here means that there is only one layer and there is only single unit in it so there is only one neuron. Successive layers in keras are defined in a sequence so the word Sequential . You define the shape of what's input to the neural network in the first and in this case the only layer, and you can see that our input shape is super simple. It's just one value. You've probably seen that for machine learning, you need to know and use a lot of math, calculus probability and the like. It's really good to understand that as you want to optimize your models but the nice thing for now about TensorFlow and keras is that a lot of that math is implemented for you in functions. There are two function roles that you should be aware of though and these are loss functions and optimizers.

```python
model.compile(optimizer = 'sgd', loss = 'mean_squared_error')
```

This lines defines that for us. So, lets understand what it is.

Understand it like this the neural network has no idea of the relation between `X` and `Y` so it makes a random guess say `y=x+3` . It will then use the data that it knows about, that’s the set of Xs and Ys that we’ve already seen to measure how good or how bad its guess was. The loss function measures this and then gives the data to the optimizer which figures out the next guess. So the optimizer thinks about how good or how badly the guess was done using the data from the loss function. Then the logic is that each guess should be better than the one before. As the guesses get better and better, an accuracy approaches 100 percent, the term convergence is used.

Here we have used the loss function as mean squared error and optimizer as SGD or stochactic gradient descent.

Our next step is to represent the known data. These are the Xs and the Ys that you saw earlier. The np.array is using a Python library called numpy that makes data representation particularly enlists much easier. So here you can see we have one list for the Xs and another one for the Ys. The training takes place in the fit command. Here we’re asking the model to figure out how to fit the X values to the Y values. The epochs equals 500 value means that it will go through the training loop 500 times. This training loop is what we described earlier. Make a guess, measure how good or how bad the guesses with the loss function, then use the optimizer and the data to make another guess and repeat this. When the model has finished training, it will then give you back values using the predict method.

Here’s the code of what we talked about.

```python
xs = np.array([-1.0,  0.0, 1.0, 2.0, 3.0, 4.0], dtype=float)
ys = np.array([-3.0, -1.0, 1.0, 3.0, 5.0, 7.0], dtype=float)model.fit(xs, ys, epochs=500)
print(model.predict([10.0]))
```

So, what output do you except — 19, right?

But when you try this in the workbook yourself you will see it gives me a value close to 19 not 19. Like you might receive-

```python
[[18.987219]]
```

Why do you think this happens because the equation is `y = 2x-1` .

There are two main reasons:

The first is that you trained it using very little data. There’s only six points. Those six points are linear but there’s no guarantee that for every X, the relationship will be Y equals 2X minus 1. There’s a very high probability that Y equals 19 for X equals 10, but the neural network isn’t positive. So it will figure out a realistic value for Y. The the second main reason. When using neural networks, as they try to figure out the answers for everything, they deal in probability. You’ll see that a lot and you’ll have to adjust how you handle answers to fit. Keep that in mind as you work through the code. Okay, enough talking. Now let’s get hands-on and write the code that we just saw and then we can run it.

## Hands-on Hello with Neural Nets

If you have used Jupyter before you will find Colab easy to use. If you have not used Colab before consider watching this intro to it.

Introduction to Google Colab

[![](https://img.youtube.com/vi/inN8seMm7UI/0.jpg)](https://www.youtube.com/watch?v=inN8seMm7UI)
<p align="center">Introduction to Google Colab</p>

Now you know how to use Colab so let’s get started.

If you are using Jupyter Notebooks in your local environment download the code file [here](https://github.com/Rishit-dagli/Deep-Learning-With-TensorFlow-Blog-series/blob/master/Part%201-Getting%20started%20with%20TensorFlow%20and%20Deep%20Learning/Hello_Neural_Nets.ipynb).

If you are using Colab follow the link [here](https://colab.research.google.com/github/Rishit-dagli/Artificial-Intelligence_resources-and-notebooks/blob/master/Hello_Neural_Nets.ipynb). You need to sign in with your Google account to run the code and receive a hosted run time.

I recommend you to spend some time with the notebook and try changing the epochs and see the effect on loss and accuracy and experiment with the code.

## Exercise — 1

In this exercise you’ll try to build a neural network that predicts the price of a house according to a simple formula. So, imagine if house pricing was as easy as a house costs 50k + 50k per bedroom, so that a 1 bedroom house costs 100k, a 2 bedroom house costs 150k etc. How would you create a neural network that learns this relationship so that it would predict a 7 bedroom house as costing close to 400k etc.

Hint: Your network might work better if you scale the house price down. You don’t have to give the answer 400…it might be better to create something that predicts the number 4, and then your answer is in the ‘hundreds of thousands’ etc.

Note: The maximum error allowed is 400 dollars

Make a new Colab Notebook and write your solution for this exercise and try it with some numbers the model has not seen.

## My Solution

Wonderful, you just created a neural net all by yourself and some of you must be feeling like this (it’s perfectly ok)-

![](https://miro.medium.com/max/205/1*quYL8J2gCxGucV1yeNQnVw.jpeg)
<p align="center">Source: me.me</p>

Let’s see my solution to this.

```python
def house_model(y_new):
    xs=[]
    ys=[]
    for i in range(1,10):
        xs.append(i)
        ys.append((1+float(i))*50)
    
    xs=np.array(xs,dtype=float)
    ys=np.array(ys, dtype=float)model = keras.Sequential([keras.layers.Dense(units = 1, input_shape = [1])])
    model.compile(optimizer='sgd', loss='mean_squared_error')    
    
    model.fit(xs, ys, epochs = 4500)
    return (model.predict(y_new)[0]/100)
```

And this gives me the answer to the required tolerate limit.

Here’s the Solution to this exercise — [here](https://github.com/Rishit-dagli/Deep-Learning-With-TensorFlow-Blog-series/blob/master/Part%201-Getting%20started%20with%20TensorFlow%20and%20Deep%20Learning/Excercise_1_Solution.ipynb)

If you want to try this out in Colab you can go to the link and click open on colab button.

That was it, the basics. You even created a neural net all by yourself and made pretty accurate predictions too. Next, we will see about using some image classifiers with Tensor Flow so, stay tuned and explore till then.

Some useful resources for further reading

*    Learn more about Colab [here](https://colab.research.google.com/notebooks/welcome.ipynb)
*    TensorFlow website [here](https://www.tensorflow.org/)
*    TensorFlow docs [here](https://github.com/tensorflow/docs)
*    GitHub repository [here](https://github.com/tensorflow/tensorflow)
*    A wonderful Neural Nets research paper [here](https://www.sciencedirect.com/science/article/abs/pii/S0893608014002135)
*    A wonderful visualization tool by TensorFlow [here](http://projector.tensorflow.org/)
*    TensorFlow models and data sets [here](https://www.tensorflow.org/resources/models-datasets)

Some TensorFlow research papers

*    Large scale Machine Learning with TensorFlow [here](http://download.tensorflow.org/paper/whitepaper2015.pdf)
*    A Deep Level Understanding of Recurrent Neural Network & LSTM with Practical Implementation in Keras & Tensorflow [here](https://www.academia.edu/41209114/A_Deep_Level_Understanding_of_Recurrent_Neural_Network_and_LSTM_with_Practical_Implementation_in_Keras_and_Tensorflow)

## About Me

Hi everyone I am Rishit Dagli

LinkedIn — linkedin.com/in/rishit-dagli-440113165/

Website — rishitdagli.ml

If you want to ask me some questions, report any mistake, suggest improvements, give feedback you are free to do so via the chat box on the website or by mailing me at —

* hello@rishitdagli.ml
* rishit.dagli@gmail.com
