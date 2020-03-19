# Part 3-Using Convolutional Neural Networks with TensorFlow

This same blog is availaible on Medium [here](https://medium.com/@rishit.dagli/using-convolutional-neural-networks-with-tensorflow-part-3-35de28a5621)

![](https://miro.medium.com/max/1860/1*zRbqakEO9WX43jKCGWCJHg.jpeg)
<p align="center">Source: cognitiveclass.ai</p>

This is the third part of the series where I post about TensorFlow for Deep Learning and Machine Learning. 
In the earlier blog post you saw a basic Neural Network for Computer Vision. 
It did the job nicely, but it was a little naive in its approach. This time you’re going to improve on that using 
Convolutional Neural Networks(CNN). I believe in hands-on coding so we will have many exercises and demos which you 
can try yourself too. I would recommend you to play around with these exercises and change the hyper-parameters and 
experiment with the code. We will also be working with some real life data sets and apply the discussed algorithms on them 
too. If you have not read the previous article consider reading it once before you read this one here.

## Introduction

I think it’s really cool that you’re already able to implement a neural network to do this fashion classification task. 
It’s just amazing that large data sets like this are readily available to you which makes it really easy to learn. 
And in this case we saw with just a few lines of code, we were able to build a DNN, deep neural net that allowed you 
to do this classification of clothing and we got reasonable accuracy with it but it was a little bit of a naive algorithm 
that we used, right? We’re looking at each and every pixel in every image, but maybe there are ways that we can 
make it better but maybe looking at features of what makes a shoe a shoe and what makes a handbag a handbag. 
What do you think? You might think something like if I have a shoelace in the picture it could be a shoe and 
if there is a handle it may be a handbag.

So, one of the ideas that make these neural networks work much better is to use convolutional neural networks, 
where instead of looking at every single pixel and say, getting the pixel values and then figuring out, 
“is this a shoe or is this a hand bag? I don’t know.” But instead you can look at a picture and say, 
“Ok, I see shoelaces and a sole.” Then, it’s probably shoe or say, “I see a handle and rectangular bag 
beneath that.” Probably a handbag. What’s really interesting about convolutions is that they sound very 
complicated but they’re actually quite straightforward. It is essentially just a filter that you pass over an 
image in the same way as if you’re doing some sharpening. If you have ever done image processing, 
it can spot features within the image just like we talked about. With the same paradigm of just data labels, 
we can let a neural network figure out for itself that it should look for shoe laces and soles or handles in 
bags and then just learn how to detect these things by itself. So we will also see how good or bad it 
works in comparison to our earlier approach for Fashion MNIST?

So, now we will know about convolutional neural networks and get to use it to build a much better fashion classifier.

## What are Convolutions and Poolings

In the DNN approach, in just a couple of minutes, you’re able to train it to 
classify with pretty high accuracy on the training set, but a little less on the test set. 
Now, one of the things that you would have seen when you looked at the images is that there’s 
a lot of wasted space in each image. While there are only 784 pixels, it will be interesting to 
see if there was a way that we could condense the image down to the important features that distinguish 
what makes it a shoe, or a handbag, or a shirt. That’s where convolutions come in. So, what’s convolution at all?

## How filters work?

If you have ever done any kind of image processing, 
it usually involves having a filter and passing that filter over the image in 
order to change the underlying image. The process works a little bit like this. 
For every pixel, take its value, and take a look at the value of its neighbors. 
If our filter is three by three, then we can take a look at the immediate neighbor, 
so that you have a corresponding 3 by 3 grid. Then to get the new value for the pixel, 
we simply multiply each neighbor by the corresponding value in the filter. So, for example, 
in this case, our pixel has the value 192, and its upper left neighbor has the value 0. The 
upper left value and the filter is -1, so we multiply 0 by -1. Then we would do the same for 
the upper neighbor. Its value is 64 and the corresponding filter value was 0, so we’d multiply those out.

Repeat this for each neighbor and each corresponding filter value, 
and would then have the new pixel with the sum of each of the neighbor values multiplied by the corresponding filter value, 
and that’s a convolution. It’s really as simple as that. The idea here is that some convolutions will 
change the image in such a way that certain features in the image get emphasized.

So, for example, if you look at this filter, then the vertical lines in the image really pop out. 
Don’t worry we will do a hands-on for this later.

![](https://miro.medium.com/max/1365/1*o684lNHDAumheeE_opXOMw.jpeg)
<p align="center>A filter which pops out vertical lines</p>

With this filter, the horizontal lines pop out.

![](https://miro.medium.com/max/1365/1*36DCauavhFgzqmvo3mf57Q.jpeg)
<p align="center">A filter which pops out horizontal lines</p>

Now, that’s a very basic introduction to what convolutions do, 
and when combined with something called pooling, they can become really powerful.

Now what’s pooling then? pooling is a way of compressing an image. 
A quick and easy way to do this, is to go over the image of 4 pixels at a time, 
that is, the current pixel and its neighbors underneath and to the right of it.

![](https://miro.medium.com/max/1365/1*drRGSm4SeE63kRkeE3FsYQ.jpeg)
<p align="center">a 4 x 4 pooling</p>

Of these 4, pick the biggest value and keep just that. 
So, for example, you can see it here. My 16 pixels on the left are 
turned into the four pixels on the right, by looking at them in 2 by 2 
grids and picking the biggest value. This will preserve the features that were highlighted by the convolution, 
while simultaneously quartering the size of the image. We have the horizontal and vertical axes too.

### Coding for convolutions and max pooling

These layers are available as

*    [Conv2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/Conv2D) and
*    [MaxPooling2D](https://www.tensorflow.org/api_docs/python/tf/keras/layers/MaxPool2D?version=stable)

in TensorFlow.

We don’t have to do all the math for filtering and compressing, 
we simply define convolutional and pooling layers to do the job for us.

So here’s our code from the earlier example, 
where we defined out a neural network to have an input layer in the shape of our data, 
and output layer in the shape of the number of categories we’re trying to define, and a hidden layer in the middle. 
The Flatten takes our square 28 by 28 images and turns them into a one dimensional array.

```python
  model = tf.keras.models.Sequential([  tf.keras.layers.Flatten(input_shape=(28, 28)),
  tf.keras.layers.Dense(128, activation = tf.nn.relu,
  tf.keras.layers.Dense(10, activation = tf.nn.softmax])
```

To add convolutions to this, you use code like this.

```python
model = tf.keras.models.Sequential([
  tf.keras.layers.Conv2D(64, (3,3), 
    activation='relu',
    input_shape=(28, 28, 1)),
  tf.keras.layers.MaxPooling2D(2, 2),  
  tf.keras.layers.Conv2D(64, (3,3), 
    activation='relu'),  
  tf.keras.layers.MaxPooling2D(2,2),  
  tf.keras.layers.Flatten(),  
  tf.keras.layers.Dense(128, activation='relu'),  
  tf.keras.layers.Dense(10, activation='softmax')])
```

You’ll see that the last three lines are the same, the `Flatten`, the `Dense` hidden layer with 128 neurons, 
and the `Dense` output layer with 10 neurons. 
What’s different is what has been added on top of this. Let’s take a look at this, line by line.

```python
tf.keras.layers.Conv2D(64, (3,3), activation='relu', input_shape=(28, 28, 1))
```

Here we’re specifying the first convolution. 
We’re asking keras to generate 64 filters for us. 
These filters are 3 by 3, their activation is relu, 
which means the negative values will be thrown way, and finally the input shape is as before, the 28 by 28. 
That extra 1 just means that we are tallying using a single byte for color depth. As we saw before our image is our 
gray scale, so we just use one byte. Now, of course, you might wonder what the 64 filters are. 
It’s a little beyond the scope of this blog to define them, but they for now you can understand that they are not random. 
They start with a set of known good filters in a similar way to the pattern fitting that you saw earlier, 
and the ones that work from that set are learned over time.

```python
tf.keras.layers.MaxPooling2D(2, 2)
```

This next line of code will then create a pooling layer. 
It’s max-pooling because we’re going to take the maximum value. 
We’re saying it’s a two-by-two pool, so for every four pixels, 
the biggest one will survive as shown earlier. We then add another convolutional layer, 
and another max-pooling layer so that the network can learn another set of convolutions on top of the existing one, 
and then again, pool to reduce the size. So, by the time the image gets to the flatten to go into the dense layers, 
it’s already much smaller. It’s being quartered, and then quartered again. So, its content has been greatly simplified, 
the goal being that the convolutions will filter it to the features that determine the output.

A really useful method on the model is the model.summary method. 
This allows you to inspect the layers of the model, and see the journey of the image through the convolutions, 
and here is the output.

![](https://miro.medium.com/max/1365/1*nwRwIymE6lGWeYRVCxMXnQ.jpeg)
<p align="center">Output of model.summary</p>

It’s a nice table showing us the layers, and some details about them including the output shape. 
It’s important to keep an eye on the output shape column. When you first look at this, 
it can be a little bit confusing and feel like a bug. After all, isn’t the data 28 by 28, so why is the output, 26 by 26? 
The key to this is remembering that the filter is a 3 by 3 filter. Consider what happens when you start scanning through an 
image starting on the top left. So, you can’t calculate the filter for the pixel in the top left, 
because it doesn’t have any neighbors above it or to its left. In a similar fashion, the next pixel to the right won’t 
work either because it doesn’t have any neighbors above it. So, logically, the first pixel that you can do calculations 
on is this one, because this one of course has all 8 neighbors that a three by 3 filter needs. This when you think about it, 
means that you can’t use a 1 pixel margin all around the image, so the output of the convolution will be 2 pixels smaller on x, 
and 2 pixels smaller on y. If your filter is five-by-five for similar reasons, your output will be four smaller on x, 
and four smaller on y. So, that’s y with a three by three filter, our output from the 28 by 28 image, is now 26 by 26, 
we’ve removed that one pixel on x and y, and each of the borders.

So, now our output gets reduced from 26 by 26, to 13 by 13. 
The convolutions will then operate on that, and of course, we lose the 1 pixel margin as before, 
so we’re down to 11 by 11, add another 2 by 2 max-pooling to have this rounding down, and went down, 
down to 5 by 5 images. So, now our dense neural network is the same as before, but it’s being fed with 
five-by-five images instead of 28 by 28 ones.

But remember, it’s not just one compressed 5 by 5 image instead of the original 28 by 28, 
there are a number of convolutions per image that we specified, in this case 64. So, there are 64 new images of 5 by 5 
that had been fed in. Flatten that out and you have 25 pixels times 64, which is 1600. So, you can see that the new flattened 
layer has 1,600 elements in it, as opposed to the 784 that you had previously. This number is impacted by the parameters 
that you set when defining the convolutional 2D layers. Later when you experiment, you’ll see what the impact of setting 
what other values for the number of convolutions will be, and in particular, you can see what happens when you’re feeding 
less than 784 over all pixels in. Training should be faster, but is there a sweet spot where it’s more accurate?

## Hands on with CNN

You can find the notebook used by me [here](https://github.com/Rishit-dagli/Deep-Learning-With-TensorFlow-Blog-series/blob/master/Part%203-Using%20Convolutional%20Neural%20Networks%20with%20TensorFlow/CNN_with_Fashion_MNIST_Notebook.ipynb).
Again, you can download the notebook if you are using a local environment and if 
you are using Colab, you can cllick on `open in colab` button.

This is a really nice way to improve our image recognition performance. Let’s now look at it in action using a notebook. 
Here’s the same neural network that you used before for loading the set of images of clothing and then classifying them. 
By the end of epoch five, you can see the loss is around 0.34, meaning, your accuracy is pretty good on the training data.

![](https://miro.medium.com/max/810/1*O2-HTqNB-Qv3wUZIl-nwHQ.jpeg)
<p align="center">Output with DNN</p>

It took just a few seconds to train, so that’s not bad. 
With the test data as before and as expected, the losses a little higher and thus, the accuracy is a little lower.

So now, you can see the code that adds convolutions and pooling. 
We’re going to do 2 convolutional layers each with 64 convolutions, and each followed by a max pooling layer.

You can see that we defined our convolutions to be three-by-three and our pools to be two-by-two. 
Let’s train. The first thing you’ll notice is that the training is much slower. For every image, 
64 convolutions are being tried, and then the image is compressed and then another 64 convolutions, 
and then it’s compressed again, and then it’s passed through the DNN, and that’s for 60,000 images that 
this is happening on each epoch. So it might take a few minutes instead of a few seconds. 
To remedy this what you can do is use a GPU. How to do that in Colab?

All you need to do is `Runtime > Change Runtime Type > GPU`. A single layer would now take approximately 5–6 seconds.

![](https://miro.medium.com/max/835/1*vwaKOlFtlcT0yxzqMvVcpA.jpeg)
<p align="center">Output with the Convolutions and max poolings</p>

Now that it’s done, you can see that the loss has improved a little it’s 0.25 now. 
In this case, it’s brought our accuracy up a bit for both our test data and with our training data. That’s pretty cool, right?

Now, this is a really fun visualization of the journey of an image through the convolutions. 
First, I’ll print out the first 100 test labels. 
The number 9 as we saw earlier is a shoe or boots. 
I picked out a few instances of this whether the zero, the 23rd and the 28th labels are all nine. 
So let’s take a look at their journey.

![](https://miro.medium.com/max/384/1*w7IPWRDopOL0f8WqdKzxjQ.jpeg)
<p align="center>The visualization</p>

The Keras API gives us each convolution and each pooling and each dense, etc. as a layer. 
So with the layers API, I can take a look at each layer’s outputs, so I’ll create a list of each layer’s output. 
I can then treat each item in the layer as an individual activation model if I want to see the results of just that layer. 
Now, by looping through the layers, I can display the journey of the image through the first convolution and 
then the first pooling and then the second convolution and then the second pooling. Note how the size of the image 
is changing by looking at the axes. If I set the convolution number to one, we can see that it almost immediately 
detects the laces area as a common feature between the shoes.

So, for example, if I change the third image to be one, which looks like a handbag, 
you’ll see that it also has a bright line near the bottom that could look like the soul of the shoes, 
but by the time it gets through the convolutions, that’s lost, and that area for the laces doesn’t even show up at all. 
So this convolution definitely helps me separate issue from a handbag. Again, if I said it’s a two, it appears to be trousers, 
but the feature that detected something that the shoes had in common fails again. Also, if I changed my third image 
back to that for shoe, but I tried a different convolution number, you’ll see that for convolution two, 
it didn’t really find any common features. To see commonality in a different image, try images two, three, and five. 
These all appear to be trousers. Convolutions two and four seem to detect this vertical feature as something they all have 
in common. If I again go to the list and find three labels that are the same, in this case six, I can see what they signify. 
When I run it, I can see that they appear to be shirts. 
Convolution four doesn’t do a whole lot, so let’s try five. 
We can kind of see that the color appears to light up in this case.

There are some exercises at the bottom of the notebook check them out.

## How convolutions work, hands-on ?(OPTIONAL)

We will create a little pooling algorithm, so you can visualize its impact. 
There’s a notebook that you can play with too, and I’ll step through that here. 
Here’s the notebook for playing with convolutions [here](). It does use a few Python 
libraries that you may not be familiar with such as `cv2`. It also has `Matplotlib` that we used before. 
If you haven’t used them, they’re really quite intuitive for this task and they’re very very easy to learn. 
So first, we’ll set up our inputs and in particular, import the misc library from `SciPy`. 
Now, this is a nice shortcut for us because `misc.ascent` returns a nice image that we can play with, 
and we don’t have to worry about managing our own.

`Matplotlib` contains the code for drawing an image and it will render it right in the browser with Colab. 
Here, we can see the ascent image from `SciPy`. 
Next up, we’ll take a copy of the image, and we’ll add it with our homemade convolutions, 
and we’ll create variables to keep track of the `x` and `y` dimensions of the image. 
So we can see here that it’s a 512 by 512 image. 
So now, let’s create a convolution as a three by three array. 
We’ll load it with values that are pretty good for detecting sharp edges first. 
Here’s where we’ll create the convolution.

We then iterate over the image, leaving a one pixel margin. 
You’ll see that the loop starts at one and not zero, and it ends at size x minus one and size y minus one. 
In the loop, it will then calculate the convolution value by looking at the pixel and its neighbors, and then by multiplying them out by the values determined by the filter, 
before finally summing it all up.

![](https://miro.medium.com/max/310/1*J7rEGoDz_20EIZiKFtwAtw.jpeg)
<p align="center">Vertical line filter</p>

Let’s run it. 
It takes just a few seconds, so when it’s done, let’s draw the results. We can see that only certain features made it 
through the filter. I’ve provided a couple more filters, so let’s try them. This first one is really great at spotting vertical lines. So when I run it, and plot the results, we can see that the vertical lines in the image made it through. 
It’s really cool because they’re not just straight up and down, they are vertical in perspective within the perspective 
of the image itself. Similarly, this filter works well for horizontal lines. So when I run it, and then plot the results, 
we can see that a lot of the horizontal lines made it through. Now, let’s take a look at pooling, and in this case, 
Max pooling, which takes pixels in chunks of four and only passes through the biggest value. I run the code and then 
render the output. We can see that the features of the image are maintained, but look closely at the axes, 
and we can see that the size has been halved from the 500’s to the 250's.

![](https://miro.medium.com/max/302/1*loH--AXE8LPMjBnoS8cIYQ.jpeg)
<p align="center">With pooling</p>

## Excercise 3

Now you need to apply this to MNIST Handwrting recognition we will revisit that from last blog post. 
You need to improve MNIST to 99.8% accuracy or more using only a single convolutional layer and a single MaxPooling 2D. 
You should stop training once the accuracy goes above this amount. 
It should happen in less than 20 epochs, so it’s ok to hard code the number of epochs for training, 
but your training must end once it hits the above metric. 
If it doesn’t, then you’ll need to redesign your layers.

When 99.8% accuracy has been hit, you should print out the string “Reached 99.8% accuracy so cancelling training!”. 
Yes, this is just optional (You can also print out something like “I’m getting bored and won’t train any more” 🤣)

The question notebook is available — [here](https://github.com/Rishit-dagli/Deep-Learning-With-TensorFlow-Blog-series/blob/master/Part%203-Using%20Convolutional%20Neural%20Networks%20with%20TensorFlow/Excercise2_question.ipynb)

## My Solution

Wonderful! 😃 , you just coded for a handwriting recognizer with a 99.8% accuracy (that’s good) in less than 20 epochs. Let explore my solution for this.

```python
def train_mnist_conv():
    # Please write your code only where you are indicated.
    # please do not remove model fitting inline comments.

    # YOUR CODE STARTS HERE
    class myCallback(tf.keras.callbacks.Callback):
        def on_epoch_end(self, epoch, logs={}):
            if(logs.get('acc')>0.998):
                print("/n Reached 99.8% accuracy so cancelling training!")
                self.model.stop_training = True
    # YOUR CODE ENDS HERE

    mnist = tf.keras.datasets.mnist
    (training_images, training_labels), (test_images, test_labels) = mnist.load_data()
    # YOUR CODE STARTS HERE
    callbacks = myCallback()
    
    training_images=training_images.reshape(60000, 28, 28, 1)
    test_images=test_images.reshape(10000, 28, 28, 1)
    training_images = training_images / 255.0
    test_images = test_images / 255.0
    # YOUR CODE ENDS HERE

    model = tf.keras.models.Sequential([
            # YOUR CODE STARTS HERE
            tf.keras.layers.Conv2D(64, (3,3), activation='relu', input_shape=(28, 28, 1)),
            tf.keras.layers.MaxPooling2D(2, 2),
            tf.keras.layers.Flatten(),
            tf.keras.layers.Dense(256, activation='relu'),
            tf.keras.layers.Dense(10, activation='softmax')
            # YOUR CODE ENDS HERE
    ])

    model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])
    # model fitting
    history = model.fit(
        # YOUR CODE STARTS HERE
        training_images,
        training_labels,
        epochs = 20,
        callbacks=[callbacks]
        # YOUR CODE ENDS HERE
    )
    # model fitting
    return history.epoch, history.history['acc'][-1]
```

### The callback class (This is the simplest)

```python
class myCallback(tf.keras.callbacks.Callback):  
  def on_epoch_end(self, epoch, logs={}):    
    if(logs.get('acc')>0.998):      
      print("/n Reached 99.8% accuracy so cancelling training!")      
    self.model.stop_training = True
```

### The main CNN code

```python
training_images=training_images.reshape(60000, 28, 28, 1)
    test_images=test_images.reshape(10000, 28, 28, 1)
    training_images = training_images / 255.0
    test_images = test_images / 255.0
    # YOUR CODE ENDS HEREmodel = tf.keras.models.Sequential([
            # YOUR CODE STARTS HERE
            tf.keras.layers.Conv2D(64, (3,3), activation='relu', input_shape=(28, 28, 1)),
            tf.keras.layers.MaxPooling2D(2, 2),
            tf.keras.layers.Flatten(),
            tf.keras.layers.Dense(256, activation='relu'),
            tf.keras.layers.Dense(10, activation='softmax')
            # YOUR CODE ENDS HERE
    ])
```

So, all you had to do was play around the code and get this done in just 7 epochs.

![](https://miro.medium.com/max/1284/1*ufQX2FjBxlC4CdUhnbwGPg.jpeg)
<p align="center">My output</p>

The solution notebook is available [here](https://github.com/Rishit-dagli/Deep-Learning-With-TensorFlow-Blog-series/blob/master/Part%203-Using%20Convolutional%20Neural%20Networks%20with%20TensorFlow/Excercise2_solution.ipynb)

## About Me

Hi everyone I am Rishit Dagli

LinkedIn — linkedin.com/in/rishit-dagli-440113165/

Website — rishitdagli.ml

If you want to ask me some questions, report any mistake, suggest improvements, give feedback you are free to do so via the chat box on the website or by mailing me at —

*    hello@rishitdagli.ml
*    rishit.dagli@gmail.com

